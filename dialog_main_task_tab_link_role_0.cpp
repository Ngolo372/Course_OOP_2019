#include "dialog_main_task_tab_link_role_0.h"

//容器

extern User OnlineUser;
extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;
extern QHash <QString, QQueue<message>>Message_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_Hash_iter;
extern QHash <QString, QQueue<message>>Message_New_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_New_Hash_iter;
extern QQueue<message> Message_Queue[1000];
extern QQueue<message> Message_New_Queue[1000];



dialog_main_task_tab_link_role_0::dialog_main_task_tab_link_role_0(QWidget *parent) : QWidget(parent)
{
    R0 = new dialog_main_task_tab_link_role_1_state_1_tab_0;
    R0HBtn = new QPushButton;
    R0TBtn = new QPushButton;
    R0RBtn = new QPushButton;
    R0_Btn_Layout = new QHBoxLayout;
    R0_Btn_Layout ->addWidget(R0HBtn);
    R0_Btn_Layout ->addWidget(R0TBtn);
    R0_Btn_Layout ->addWidget(R0RBtn);

    R0_Layout = new QVBoxLayout(this);
    R0_Layout ->addWidget(R0);
    R0_Layout ->addLayout(R0_Btn_Layout);
}

dialog_main_task_tab_link_role_0::~dialog_main_task_tab_link_role_0()
{

}

dialog_main_task_tab_link_role_0 ::dialog_main_task_tab_link_role_0(int id, int state) :R0Id(id), R0State(state)
{
    R0 = new dialog_main_task_tab_link_role_1_state_1_tab_0(id);
    R0HBtn = new QPushButton(tr("Be Header"));
    R0TBtn = new QPushButton(tr("Be Translator"));
    R0RBtn = new QPushButton(tr("Be Reviewer"));
    R0HBtn ->setEnabled(0);
    R0TBtn ->setEnabled(0);
    R0RBtn ->setEnabled(0);
    R0_Btn_Layout = new QHBoxLayout;
    R0_Btn_Layout ->addWidget(R0HBtn);
    R0_Btn_Layout ->addWidget(R0TBtn);
    R0_Btn_Layout ->addWidget(R0RBtn);

    R0_Layout = new QVBoxLayout(this);
    R0_Layout ->addWidget(R0);
    R0_Layout ->addLayout(R0_Btn_Layout);

    if(Taskinfo_Hash.find(R0Id).value().LinkRelation(OnlineUser) == 0){
        if(state == 1){
                R0HBtn ->setEnabled(1);
                R0RBtn ->setEnabled(1);
        }

        if(state == 2 || state == 3){
                R0TBtn ->setEnabled(1);
        }
    }


    connect(R0HBtn, SIGNAL(clicked()), this, SLOT(BeHeader()));
    connect(R0RBtn, SIGNAL(clicked()), this, SLOT(BeReviewer()));
    connect(R0TBtn, SIGNAL(clicked()), this, SLOT(BeTranslator()));
}

//报名负责人

void dialog_main_task_tab_link_role_0::BeHeader()
{
    if(QDateTime::currentDateTime() > Taskinfo_Hash.find(R0Id).value().GetDDL_Header())
        QMessageBox::warning(this, "Error", "Miss the report ddl");
    else if(Taskinfo_Hash.find(R0Id).value().GetIntH() > OnlineUser.Get_User_Intergral())
        QMessageBox::warning(this, "Error", "Integral not enough");
    else{
        if(QMessageBox::question(this, "Be Header", "Sure?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes){
            Taskinfo_Hash.find(R0Id).value().add_pre_Header(OnlineUser.GetUsername());
            Taskinfo_Hash.find(R0Id).value().NewTaskFlag = 1;
            Link_usertask_Hash.find(OnlineUser.GetUsername()).value().insert(R0Id,51);
            qDebug() << Link_usertask_Hash.find(OnlineUser.GetUsername()).value().find(R0Id).value();
            R0RBtn ->setEnabled(0);
            R0HBtn ->setEnabled(0);
            R0TBtn ->setEnabled(0);

            message newmess(R0Id, OnlineUser.GetUsername(), 1);
            newmess.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + R0Id * 1000;
            Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);
            Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);

            message newmess2(R0Id, Taskinfo_Hash.find(R0Id)->GetPublisher(), OnlineUser.GetUsername(), 11);
            newmess2.floatid = Message_Hash.find(Taskinfo_Hash.find(R0Id)->GetPublisher()).value().size() + R0Id * 1000;
            Message_Hash.find(Taskinfo_Hash.find(R0Id)->GetPublisher()).value().enqueue(newmess2);
            Message_New_Hash.find(Taskinfo_Hash.find(R0Id)->GetPublisher()).value().enqueue(newmess2);
        }
    }
}

//报名审核人

void dialog_main_task_tab_link_role_0::BeReviewer()
{
    if(QDateTime::currentDateTime() > Taskinfo_Hash.find(R0Id).value().GetDDL_Header())
        QMessageBox::warning(this, "Error", "Miss the report ddl");
    else if (Taskinfo_Hash.find(R0Id).value().GetIntR() > OnlineUser.Get_User_Intergral()) {
        QMessageBox::warning(this, "Error", "Integral not enough");
    }
    else {
        if(QMessageBox::question(this, "Be Reviewer", "Sure?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes){
            Taskinfo_Hash.find(R0Id).value().add_pre_Reviewer(OnlineUser.GetUsername());
             Taskinfo_Hash.find(R0Id).value().NewTaskFlag = 1;
            Link_usertask_Hash.find(OnlineUser.GetUsername()).value().insert(R0Id,71);
            R0RBtn ->setEnabled(0);
            R0HBtn ->setEnabled(0);
            R0TBtn ->setEnabled(0);
            qDebug() << Link_usertask_Hash.find(OnlineUser.GetUsername()).value().find(R0Id).value();

            message newmess(R0Id, OnlineUser.GetUsername(), 2);
            newmess.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + R0Id * 1000;

            Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);
            Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);

            message newmess2(R0Id, Taskinfo_Hash.find(R0Id)->GetPublisher(), OnlineUser.GetUsername(), 12);
            newmess2.floatid = Message_Hash.find(Taskinfo_Hash.find(R0Id)->GetPublisher()).value().size() + R0Id * 1000;
            Message_Hash.find(Taskinfo_Hash.find(R0Id)->GetPublisher()).value().enqueue(newmess2);
            Message_New_Hash.find(Taskinfo_Hash.find(R0Id)->GetPublisher()).value().enqueue(newmess2);
        }
    }
}

//报名译者

void dialog_main_task_tab_link_role_0::BeTranslator()
{
    if(QDateTime::currentDateTime() < Taskinfo_Hash.find(R0Id).value().GetDDL_Reviewer()){
        if(QMessageBox::question(this, "Be Translator", "Sure?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes){
            Taskinfo_Hash.find(R0Id).value().add_pre_Translator(OnlineUser.GetUsername());
             Taskinfo_Hash.find(R0Id).value().NewTaskFlag = 1;
            Link_usertask_Hash.find(OnlineUser.GetUsername()).value().insert(R0Id,61);
            R0RBtn ->setEnabled(0);
            R0HBtn ->setEnabled(0);
            R0TBtn ->setEnabled(0);
            qDebug() << Link_usertask_Hash.find(OnlineUser.GetUsername()).value().find(R0Id).value();

            message newmess(R0Id, OnlineUser.GetUsername(), 3);
            newmess.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + R0Id * 1000;
            Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);
            Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);

            message newmess2(R0Id, Taskinfo_Hash.find(R0Id)->GetPublisher(), OnlineUser.GetUsername(), 21);
            newmess2.floatid = Message_Hash.find(Taskinfo_Hash.find(R0Id)->GetPublisher()).value().size() + R0Id * 1000;
            Message_Hash.find(Taskinfo_Hash.find(R0Id)->GetPublisher()).value().enqueue(newmess2);
            Message_New_Hash.find(Taskinfo_Hash.find(R0Id)->GetPublisher()).value().enqueue(newmess2);

            message newmess3(R0Id, Taskinfo_Hash.find(R0Id)->GetHeader(), OnlineUser.GetUsername(), 21);
            newmess3.floatid = Message_Hash.find(Taskinfo_Hash.find(R0Id)->GetHeader()).value().size() + R0Id * 1000;
            Message_Hash.find(Taskinfo_Hash.find(R0Id)->GetHeader()).value().enqueue(newmess3);
            Message_New_Hash.find(Taskinfo_Hash.find(R0Id)->GetHeader()).value().enqueue(newmess3);
        }
    }
    else {
        QMessageBox::warning(this, "Error", "Miss the report ddl");
    }
}
