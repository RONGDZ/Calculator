#include "LoopMgr.h"
#include <QTime>

LoopMgr::LoopMgr()
{
	m_ev_start = 0;
	m_ev_end = 0;
	for (size_t i = 0; i < EV_SLOT_MAX; i++)
	{
		m_event[i] = nullptr;
	}

	m_exit = false;
	m_flag = 0;
}

LoopMgr::~LoopMgr()
{
	wait_exit();
}

void LoopMgr::run()
{
	m_flag = 1;
	while (!m_exit)
	{
		//处理事件
		if (m_ev_start != m_ev_end)
		{
			if (nullptr != m_event[m_ev_start])
			{
				m_event[m_ev_start]();
				m_event[m_ev_start] = nullptr;
				if (EV_SLOT_MAX <= ++m_ev_start)
				{
					m_ev_start = 0;
				}
			}
		}

		//执行回环消息
		size_t sz = m_loop.size();
		for (size_t i = 0; i < sz; i++)
		{
			m_loop[i]();
		}
	}
	m_flag = 2;

}

void LoopMgr::wait_exit()
{
	m_exit = true;
	if (1 == m_flag)
	{
		QTime tm;
		m_ev_start = m_ev_end;
		for (tm.start(); tm.elapsed() < 3000;)
		{
			if (2 == m_flag)
			{
				break;
			}
		}
	}
	wait();
}

void LoopMgr::addLoop(std::function<void(void)>  lpFunc)
{
	QWriteLocker locker(&m_lock);
	m_loop.push_back(lpFunc);
}

void LoopMgr::addEvent(std::function<void(void)>  cbFunc)
{
	//QWriteLocker locker(&m_lock);
	m_event[m_ev_end] = cbFunc;
	//检查是否需要回环
	if (EV_SLOT_MAX <= ++m_ev_end)
	{
		m_ev_end = 0;
	}
}
