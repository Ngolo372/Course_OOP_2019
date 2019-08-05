#include "dialog_main_task_tab_link_role_2_state_2_tab_1.h"


extern User OnlineUser;
extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;
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

dialog_main_task_tab_link_role_2_state_2_tab_1::dialog_main_task_tab_link_role_2_state_2_tab_1(QWidget *parent) : dialog_main_Peoplelist(parent)
{

}

dialog_main_task_tab_link_role_2_state_2_tab_1::~dialog_main_task_tab_link_role_2_state_2_tab_1()
{

}

dialog_main_task_tab_link_role_2_state_2_tab_1::dialog_main_task_tab_link_role_2_state_2_tab_1(int task0)
{
    MainTask = task0;
    if( Taskinfo_Hash.find(MainTask) ->GetState() != 3)UserBtn->setEnabled(0);
    Info_Fresh();
    UserBtn ->setText("Confirm this");
    UserBtn ->setEnabled(0);
    connect(UserBtn, SIGNAL(clicked()), this, SLOT(ConfirmTranslator()));
    Userall = new QPushButton("Confirm all");
    RLayout ->addWidget(Userall);
    connect(Userall, SIGNAL(clicked()), this, SLOT(ConfirmEnd()));
    connect(UserList, SIGNAL(currentRowChanged(int)), this, SLOT(Btn_Fresh(int)));
}

//确认译者

void dialog_main_task_tab_link_role_2_state_2_tab_1::ConfirmTranslator()
{   
    int num = UserList ->currentRow();
    if(num < 0)num = 0;
    qDebug() << num << "num";
    if(QMessageBox::question(this, "Select Translator", "Sure?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes)
    {
        QString usernamec = UserList ->currentItem()->text();
        if(usernamec.back() == ']' || UserList ->item(0) ->text().back() == ']')UserBtn ->setEnabled(0);
        QString usernamer = Taskinfo_Hash.find(MainTask)->GetReviewer();
        qDebug() << "CCC0" << usernamec;
        Taskinfo_Hash.find(MainTask).value().add_Translator(usernamec);
        qDebug() << "CCC1";
        Link_usertask_Hash.find(usernamec).value().insert(MainTask, 44);
        qDebug() << "CCC2";
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[12] = 1;
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[16] = 1;
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[17] = 1;
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[18] = 1;
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[19] = 1;
        Taskinfo_Hash.find(MainTask).value().UpdateTaskFlag[20] = 1;
        if(Taskinfo_Hash.find(MainTask)->GetTranslatorNum() >= 5) UserBtn ->setEnabled(0);
        qDebug() << "CCC3";
        message newmess1(MainTask, OnlineUser.GetUsername(), usernamec, 22);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

        message newmess2(MainTask, usernamec, 40);
        newmess2.floatid = Message_Hash.find(usernamec).value().size() + MainTask * 1000;
        Message_Hash.find(usernamec).value().enqueue(newmess2);
        Message_New_Hash.find(usernamec).value().enqueue(newmess2);

        message newmess3(MainTask, usernamer, OnlineUser.GetUsername(), usernamec, 60);
        newmess3.floatid = Message_Hash.find(usernamer).value().size() + MainTask * 1000;
        Message_Hash.find(usernamer).value().enqueue(newmess3);
        Message_New_Hash.find(usernamer).value().enqueue(newmess3);


        UserList ->currentItem()->setText(usernamec + "[Confirmed]");
        UserBtn ->setEnabled(0);
    }
}


//确认已经加入所有译者

void dialog_main_task_tab_link_role_2_state_2_tab_1::ConfirmEnd()
{
    if(QDateTime::currentDateTime() < Taskinfo_Hash.find(MainTask).value().GetDDL_Reviewer())
    {
        QMessageBox::warning(this, "Error", "Translator recruiting, DDL not reach");
        return;
    }
    if(QMessageBox::question(this, "Finish Translator", "Sure?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes)
    {
        Taskinfo_Hash.find(MainTask).value().SetState(4);
        Userall ->setEnabled(0);
        UserBtn ->setEnabled(0);
        for (int i = 0; i < Taskinfo_Hash.find(MainTask)->GetPreTranslatorNum(); i++) {
            QString usernamef = Taskinfo_Hash.find(MainTask)->GetPreTranslator(i);
             if(Taskinfo_Hash.find(MainTask).value().LinkRelation(Userinfo_Hash.find(usernamef).value()) != 4)  {
                 message newmess(MainTask, usernamef, 6);
                 newmess.floatid = Message_Hash.find(usernamef).value().size() + MainTask * 1000;

                 Message_Hash.find(usernamef).value().enqueue(newmess);
                 Message_New_Hash.find(usernamef).value().enqueue(newmess);
             }
        }
    }
}

//刷新

void dialog_main_task_tab_link_role_2_state_2_tab_1::Info_Fresh()
{
    int size = Taskinfo_Hash.find(MainTask)->GetPreTranslatorNum();
    for(int i = 0; i < 5; i ++){
        if(Taskinfo_Hash.find(MainTask)->GetTranslator(i) != ""){
            UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetTranslator(i) + "[Confirmed]");
            UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetTranslator(i)));
        }
    }

    for (int i = 0; i < size; i ++) {
        if(!Taskinfo_Hash.find(MainTask).value().isTranslator(Taskinfo_Hash.find(MainTask).value().GetPreTranslator(i))){

            UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetPreTranslator(i));
            UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetPreTranslator(i)));
        }
    }
}

//进入译者列表， 按钮权限刷新

void dialog_main_task_tab_link_role_2_state_2_tab_1::Fresh(int index)
{
    if(index == 1){
        if(Taskinfo_Hash.find(MainTask).value().LinkRelation(OnlineUser) == 2 && Taskinfo_Hash.find(MainTask) ->GetState() == 3)UserBtn->setEnabled(1);
        else UserBtn->setEnabled(0);
    }
}


//切换选中译者， 按钮权限刷新

void dialog_main_task_tab_link_role_2_state_2_tab_1::Btn_Fresh(int index)
{
    if(UserList ->currentItem()->text().back() == ']')UserBtn->setEnabled(0);
    else UserBtn ->setEnabled(1);
}
