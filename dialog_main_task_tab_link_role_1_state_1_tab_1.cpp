#include "dialog_main_task_tab_link_role_1_state_1_tab_1.h"

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


dialog_main_task_tab_link_role_1_state_1_tab_1::dialog_main_task_tab_link_role_1_state_1_tab_1(QWidget *parent) : dialog_main_Peoplelist(parent)
{

}


dialog_main_task_tab_link_role_1_state_1_tab_1::~dialog_main_task_tab_link_role_1_state_1_tab_1()
{

}


dialog_main_task_tab_link_role_1_state_1_tab_1::dialog_main_task_tab_link_role_1_state_1_tab_1(int task0)
{
    MainTask = task0;
    int size = Taskinfo_Hash.find(MainTask)->GetPreHeaderNum();



    if( Taskinfo_Hash.find(MainTask) ->GetState() != 1)UserBtn->setEnabled(0);

    //防止空指针

    if(Taskinfo_Hash.find(MainTask)->GetHeader() != ""){
        UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetHeader() + "[Confirmed]");
        UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetHeader()));
    }

    for (int i = 0; i < size; i ++) {
        if(Taskinfo_Hash.find(MainTask)->GetPreHeader(i) != Taskinfo_Hash.find(MainTask)->GetHeader()){
            UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetPreHeader(i));
            UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetPreHeader(i)));
        }
    }

    connect(UserBtn, SIGNAL(clicked()), this, SLOT(ConfirmHeader()));

}


//确认负责人

void dialog_main_task_tab_link_role_1_state_1_tab_1::ConfirmHeader()
{
    //已过报名ddl

    if(QDateTime::currentDateTime() < Taskinfo_Hash.find(MainTask).value().GetDDL_Header())
    {
        QMessageBox::warning(this, "Error", "Header recruiting, DDL not reach");
        return;
    }
    int num = UserList ->currentRow();


    //防止随机数

    if(num < 0)num = 0;
    if(QMessageBox::question(this, "Select Header", "Sure?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes)
    {
        QString usernamec = Taskinfo_Hash.find(MainTask)->GetPreHeader(num);
        message newmess1(MainTask, OnlineUser.GetUsername(), usernamec, 13);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

        message newmess2(MainTask, usernamec, 20);
        newmess2.floatid = Message_Hash.find(usernamec).value().size() + MainTask * 1000;
        Message_Hash.find(usernamec).value().enqueue(newmess2);
        Message_New_Hash.find(usernamec).value().enqueue(newmess2);
        for (int i = 0; i < Taskinfo_Hash.find(MainTask)->GetPreHeaderNum(); i++) {
            QString usernamef = Taskinfo_Hash.find(MainTask)->GetPreHeader(i);
             if(usernamef != usernamec)  {
                 message newmess(MainTask, usernamef, 4);
                 newmess.floatid = Message_Hash.find(usernamef).value().size() + MainTask * 1000;
                 Message_Hash.find(usernamef).value().enqueue(newmess);
                 Message_New_Hash.find(usernamef).value().enqueue(newmess);
             }
        }

        Taskinfo_Hash.find(MainTask).value().SetState(2);
        Taskinfo_Hash.find(MainTask).value().SetHeader(usernamec);
        Link_usertask_Hash.find(OnlineUser.GetUsername()).value().find(MainTask).value() ++;
        Link_usertask_Hash.find(usernamec).value().insert(MainTask, 22);
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[12] = 1;
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[14] = 1;
        UserBtn ->setEnabled(0);
    }
}
