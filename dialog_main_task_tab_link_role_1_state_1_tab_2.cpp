#include "dialog_main_task_tab_link_role_1_state_1_tab_2.h"


extern QHash <QString, QQueue<message>>Message_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_Hash_iter;
extern QHash <QString, QQueue<message>>Message_New_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_New_Hash_iter;
extern QQueue<message> Message_Queue[1000];
extern QQueue<message> Message_New_Queue[1000];
extern User OnlineUser;
extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;

dialog_main_task_tab_link_role_1_state_1_tab_2::dialog_main_task_tab_link_role_1_state_1_tab_2(QWidget *parent) : dialog_main_Peoplelist(parent)
{

}

dialog_main_task_tab_link_role_1_state_1_tab_2::~dialog_main_task_tab_link_role_1_state_1_tab_2()
{

}

dialog_main_task_tab_link_role_1_state_1_tab_2::dialog_main_task_tab_link_role_1_state_1_tab_2(int task0)
{
    MainTask = task0;
    int size = Taskinfo_Hash.find(MainTask)->GetPreReviewerNum();
    if( Taskinfo_Hash.find(MainTask) ->GetState() != 2)UserBtn->setEnabled(0);
    if(Taskinfo_Hash.find(MainTask)->GetReviewer() != ""){
        UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetReviewer() + "[Confirmed]");
        UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetReviewer()));
    }
    qDebug() << MainTask <<  "reviewer" << size;
    for (int i = 0; i < size; i ++) {
        if(Taskinfo_Hash.find(MainTask)->GetPreReviewer(i) != Taskinfo_Hash.find(MainTask)->GetReviewer()){
            UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetPreReviewer(i));
            UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetPreReviewer(i)));
        }
    }
    connect(UserBtn, SIGNAL(clicked()), this, SLOT(ConfirmReviewer()));
}


//确认审核人

void dialog_main_task_tab_link_role_1_state_1_tab_2::ConfirmReviewer()
{
    if(QDateTime::currentDateTime() < Taskinfo_Hash.find(MainTask).value().GetDDL_Header())
    {
        QMessageBox::warning(this, "Error", "Reviewer recruiting, DDL not reach");
        return;
    }

    int num = UserList ->currentRow();
    if(num < 0)num = 0;
    qDebug() << num;
    if(QMessageBox::question(this, "Select Reviewer", "Sure?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes)
    {
        QString usernamec = Taskinfo_Hash.find(MainTask)->GetPreReviewer(num);

        message newmess1(MainTask, OnlineUser.GetUsername(), usernamec, 14);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        message newmess2(MainTask, usernamec, 30);
        newmess2.floatid = Message_Hash.find(usernamec).value().size() + MainTask * 1000;
        Message_Hash.find(usernamec).value().enqueue(newmess2);
        Message_New_Hash.find(usernamec).value().enqueue(newmess2);
        for (int i = 0; i < Taskinfo_Hash.find(MainTask)->GetPreReviewerNum(); i++) {
            QString usernamef = Taskinfo_Hash.find(MainTask)->GetPreReviewer(i);
             if(usernamef != usernamec)  {
                 message newmess(MainTask, usernamef, 5);
                 newmess.floatid = Message_Hash.find(usernamef).value().size() + MainTask * 1000;
                 Message_Hash.find(usernamef).value().enqueue(newmess);
                 Message_New_Hash.find(usernamef).value().enqueue(newmess);
             }
        }
        Taskinfo_Hash.find(MainTask).value().SetReviewer(usernamec);
        Taskinfo_Hash.find(MainTask).value().SetState(3);
        Link_usertask_Hash.find(OnlineUser.GetUsername()).value().find(MainTask).value() ++;
        Link_usertask_Hash.find(usernamec).value().insert(MainTask, 33);
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[12] = 1;
        Link_usertask_Hash.find(Taskinfo_Hash.find(MainTask)->GetHeader()).value().find(MainTask).value() ++;
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[15] = 1;
        UserBtn ->setEnabled(0);
    }
}


//刷新任务状态与确认权限

void dialog_main_task_tab_link_role_1_state_1_tab_2::Fresh(int index)
{
    if(index == 2){
        if( Taskinfo_Hash.find(MainTask) ->GetState() == 2)UserBtn->setEnabled(1);
        else UserBtn->setEnabled(0);
    }
}
