#include "dialog_main_peoplelist.h"


//构造

dialog_main_Peoplelist::dialog_main_Peoplelist(QWidget *parent) : QWidget(parent)
{
    UserList = new QListWidget;
    UserStack = new QStackedWidget;
    UserBtn = new QPushButton(tr("Confilm"));
    Layout = new QHBoxLayout(this);
    RLayout = new QVBoxLayout;
    RLayout ->addWidget(UserStack);
    RLayout ->addWidget(UserBtn);
    Layout ->addWidget(UserList);
    Layout ->addLayout(RLayout);
    Layout ->setStretch(0, 1);
    Layout ->setStretch(1, 5);
    connect(UserList, SIGNAL(currentRowChanged(int)),
            UserStack, SLOT(setCurrentIndex(int)));
}


//析构

dialog_main_Peoplelist::~dialog_main_Peoplelist()
{

}


//参数构造

dialog_main_Peoplelist::dialog_main_Peoplelist(int task0):MainTask(task0)
{
    UserList = new QListWidget;
    UserStack = new QStackedWidget;
    UserBtn = new QPushButton(tr("Confilm"));
    Layout = new QHBoxLayout(this);
    RLayout = new QVBoxLayout;
    RLayout ->addWidget(UserStack);
    RLayout ->addWidget(UserBtn);
    Layout ->addWidget(UserList);
    Layout ->addLayout(RLayout);
    Layout ->setStretch(0, 1);
    Layout ->setStretch(1, 5);


    // 连接list与stack

    connect(UserList, SIGNAL(currentRowChanged(int)),
            UserStack, SLOT(setCurrentIndex(int)));
}
