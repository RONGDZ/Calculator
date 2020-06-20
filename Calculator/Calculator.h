#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Calculator.h"
#include <memory>

class Calculator : public QMainWindow
{
	Q_OBJECT

public:
	Calculator(QWidget *parent = Q_NULLPTR);

private:
	float count = NULL;
	int flag = 0;
	QString num;

	void (Calculator::* ptr)();

private:
	void init();
	void initEvent();

private slots:
	void slotgetspot();
	void slotget0();
	void slotget1();
	void slotget2();
	void slotget3();
	void slotget4();
	void slotget5();
	void slotget6();
	void slotget7();
	void slotget8();
	void slotget9();

	void add();
	void sub();
	void mul();
	void div();

	void slotadd();
	void slotsub();
	void slotmul();
	void slotdiv();

	void slotdel();
	void slotequal();
private:
	Ui::CalculatorClass ui;
};
