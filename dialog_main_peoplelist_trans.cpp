#include "dialog_main_peoplelist_trans.h"

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


//构造

dialog_main_peoplelist_trans::dialog_main_peoplelist_trans(QWidget *parent) : dialog_main_Peoplelist(parent)
{

}


//析构

dialog_main_peoplelist_trans::~dialog_main_peoplelist_trans()
{

}


//带参构造

dialog_main_peoplelist_trans::dialog_main_peoplelist_trans(int task0, int role)
{
    deleteBtn = new QPushButton("delete this person");
    RLayout ->addWidget(deleteBtn);


    //仅负责人有操作权限

    if(role != 2)deleteBtn ->setEnabled(0);


    //防止初始状态野指针、空指针

    UserBtn ->setEnabled(0);

    MainTask = task0;
    for(int i = 0; i < 5; i ++){
        if(Taskinfo_Hash.find(MainTask)->GetTranslator(i) != ""){
            UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetTranslator(i) + "[Translator]");
            UserStack ->addWidget(new dialog_main_task_exchange(MainTask, i, role));
         }
    }

    //删除译者

    connect(deleteBtn, SIGNAL(clicked()), this, SLOT(deleteTranslator()));
}

void dialog_main_peoplelist_trans::deleteTranslator()
{
    if(QMessageBox::Yes == QMessageBox::question(this, "delete translator", "sure to delete him/her"))
    {
        deleteBtn ->setEnabled(0);
        int i = UserList ->currentRow();
        QString usernamec = Taskinfo_Hash.find(MainTask)->GetTranslator(i);
        QString usernamer = Taskinfo_Hash.find(MainTask)->GetReviewer();
        message newmess1(MainTask, OnlineUser.GetUsername(), usernamec, 58);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

        message newmess2(MainTask, usernamec, 57);
        newmess2.floatid = Message_Hash.find(usernamec).value().size() + MainTask * 1000;
        Message_Hash.find(usernamec).value().enqueue(newmess2);
        Message_New_Hash.find(usernamec).value().enqueue(newmess2);

        message newmess3(MainTask, usernamer, OnlineUser.GetUsername(), usernamec, 59);
        newmess3.floatid = Message_Hash.find(usernamer).value().size() + MainTask * 1000;
        Message_Hash.find(usernamer).value().enqueue(newmess3);
        Message_New_Hash.find(usernamer).value().enqueue(newmess3);
        Taskinfo_Hash.find(MainTask).value().delete_Translator(i);

        int inbefore = Link_usertask_Hash.find(usernamec).value().find(MainTask).value();
        Link_usertask_Hash.find(usernamec).value().find(MainTask).value() = inbefore % 10;
    }
}
