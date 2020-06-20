#pragma once
#include <vector>
#include <QThread>
#include <functional>
#include <QReadWriteLock>
#define EV_SLOT_MAX 100

class LoopMgr : public QThread
{
	Q_OBJECT

public:
	LoopMgr();
	~LoopMgr();
private:
	QReadWriteLock m_lock;
	std::vector<std::function<void(void)>> m_loop;
	std::function<void(void)> m_event[EV_SLOT_MAX];
	size_t m_ev_start;
	size_t m_ev_end;
	bool m_exit;
	int m_flag;
public:
	void run() override;
	void wait_exit();
public:
	void addLoop(std::function<void(void)>  lpFunc);
	void addEvent(std::function<void(void)> cbFunc);

};
