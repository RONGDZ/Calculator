#include "Calculator.h"



Calculator::Calculator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	init();
}

void Calculator::init()
{
	initEvent();
	ui.lab_view->setAlignment(Qt::AlignRight);
	ui.lab_view->setFont(QFont("OldEnglish", 28, QFont::Bold));
}

void Calculator::initEvent()
{
	connect(ui.btn_spot, SIGNAL(clicked(bool)), this, SLOT(slotgetspot()));
	connect(ui.btn_0, SIGNAL(clicked(bool)), this, SLOT(slotget0()));
	connect(ui.btn_1, SIGNAL(clicked(bool)), this, SLOT(slotget1()));
	connect(ui.btn_2, SIGNAL(clicked(bool)), this, SLOT(slotget2()));
	connect(ui.btn_3, SIGNAL(clicked(bool)), this, SLOT(slotget3()));
	connect(ui.btn_4, SIGNAL(clicked(bool)), this, SLOT(slotget4()));
	connect(ui.btn_5, SIGNAL(clicked(bool)), this, SLOT(slotget5()));
	connect(ui.btn_6, SIGNAL(clicked(bool)), this, SLOT(slotget6()));
	connect(ui.btn_7, SIGNAL(clicked(bool)), this, SLOT(slotget7()));
	connect(ui.btn_8, SIGNAL(clicked(bool)), this, SLOT(slotget8()));
	connect(ui.btn_9, SIGNAL(clicked(bool)), this, SLOT(slotget9()));

	connect(ui.btn_add, SIGNAL(clicked(bool)), this, SLOT(slotadd()));
	connect(ui.btn_sub, SIGNAL(clicked(bool)), this, SLOT(slotsub()));
	connect(ui.btn_mul, SIGNAL(clicked(bool)), this, SLOT(slotmul()));
	connect(ui.btn_div, SIGNAL(clicked(bool)), this, SLOT(slotdiv()));
	connect(ui.btn_del, SIGNAL(clicked(bool)), this, SLOT(slotdel()));
	connect(ui.btn_equal, SIGNAL(clicked(bool)), this, SLOT(slotequal()));
	
}


void Calculator::slotgetspot()
{
	if (flag == 0)
		count = NULL;
	num.append(".");
	ui.lab_view->setText(num);
	flag = -1;
}

void Calculator::slotget0()
{
	if (flag == 0)
		count = NULL;
	num.append("0");
	ui.lab_view->setText(num);
	flag = -1;
}
void Calculator::slotget1()
{
	if (flag == 0)
		count = NULL;
	num.append("1");
	ui.lab_view->setText(num);
	flag = -1;
}
void Calculator::slotget2()
{
	if (flag == 0)
		count = NULL;
	num.append("2");
	ui.lab_view->setText(num);
	flag = -1;
}
void Calculator::slotget3()
{
	if (flag == 0)
		count = NULL;
	num.append("3");
	ui.lab_view->setText(num);
	flag = -1;
}
void Calculator::slotget4()
{
	if (flag == 0)
		count = NULL;
	num.append("4");
	ui.lab_view->setText(num);
	flag = -1;
}
void Calculator::slotget5()
{
	if (flag == 0)
		count = NULL;
	num.append("5");
	ui.lab_view->setText(num);
	flag = -1;
}
void Calculator::slotget6()
{
	if (flag == 0)
		count = NULL;
	num.append("6");
	ui.lab_view->setText(num);
	flag = -1;
}
void Calculator::slotget7()
{
	if (flag == 0)
		count = NULL;
	num.append("7");
	ui.lab_view->setText(num);
	flag = -1;
}
void Calculator::slotget8()
{
	if (flag == 0)
		count = NULL;
	num.append("8");
	ui.lab_view->setText(num);
	flag = -1;
}
void Calculator::slotget9()
{
	if (flag == 0)
		count = NULL;
	num.append("9");
	ui.lab_view->setText(num);
	flag = -1;
}

void Calculator::add()
{
	float d = num.toFloat();
	count += d;
	QString data = QString("%1").arg(count);
	ui.lab_view->setText(data);
	num.clear();
}
void Calculator::sub()
{
	float d = num.toFloat();
	count -= d;
	QString data = QString("%1").arg(count);
	ui.lab_view->setText(data);
	num.clear();
}
void Calculator::mul()
{
	float d = num.toFloat();
	count *= d;
	QString data = QString("%1").arg(count);
	ui.lab_view->setText(data);
	num.clear();
}
void Calculator::div()
{
	float d = num.toFloat();
	count /= d;
	QString data = QString("%1").arg(count);
	ui.lab_view->setText(data);
	num.clear();
}

void Calculator::slotadd()
{	
	if (count == NULL)
	{
		float d = num.toFloat();
		count = d;
		num.clear();
		ptr = &Calculator::add;
			
	}
	else
	{
		if (num != NULL)
			if (ptr != NULL)
				(this->*ptr)();
		ptr = &Calculator::add;
	}
	flag = 1;
}

void Calculator::slotsub()
{
	flag += 1;
	if (flag == 2)
	{
		num.append("-");
		ui.lab_view->setText(num);
		flag = -1;
	}
	else
	{
		if (count == NULL)
		{
			if(num == NULL)
			{
				num.append("-");
				ui.lab_view->setText(num);
				flag = -1;
			}
			else
			{
				float d = num.toFloat();
				count = d;
				num.clear();
				ptr = &Calculator::sub;
			}
			
		}
		else
		{
			if (num != NULL)
				if (ptr != NULL)
					(this->*ptr)();
			ptr = &Calculator::sub;

		}
		flag = 1;
	}
	
	
}

void Calculator::slotmul()
{
	if (count == NULL)
	{
		float d = num.toFloat();
		count = d;
		num.clear();
		ptr = &Calculator::mul;
	}
	else
	{
		if (num != NULL)
		{
			if (ptr != NULL)
				(this->*ptr)();
		}
		ptr = &Calculator::mul;
	}
	flag = 1;
}

void Calculator::slotdiv()
{
	if (count == NULL)
	{
		float d = num.toFloat();
		count = d;
		num.clear();
		ptr = &Calculator::div;
	}
	else
	{
		if (num != NULL)
			if (ptr != NULL)
				(this->*ptr)();
		ptr = &Calculator::div;

	}
	flag = 1;
}

void Calculator::slotequal()
{	
	flag = 0;
	if(ptr != NULL)
		(this->*ptr)();
	ptr = NULL;
	
}

void Calculator::slotdel()
{
	flag = 0;
	count = NULL;
	num.clear();
	ptr = NULL;
	ui.lab_view->setText(num);
}