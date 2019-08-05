#include "dialog_main_peoplelist_task.h"

//容器

extern User OnlineUser;
extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;

//构造

dialog_main_peoplelist_task::dialog_main_peoplelist_task(QWidget *parent) : dialog_main_Peoplelist(parent)
{

}


//析构

dialog_main_peoplelist_task::~dialog_main_peoplelist_task()
{

}


//带参构造

dialog_main_peoplelist_task::dialog_main_peoplelist_task(int task0)
{
    //添加成员：发布人、非责任、审核人、译者、报名未通过/未审核者

    MainTask = task0;
    UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetPublisher() + "[Publisher]");
    UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetPublisher()));

    int size = Taskinfo_Hash.find(MainTask)->GetPreHeaderNum();
    UserBtn->setEnabled(0);
    if(Taskinfo_Hash.find(MainTask)->GetHeader() != ""){
        UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetHeader() + "[Header]");
        UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetHeader()));
    }

    for (int i = 0; i < size; i ++) {
        if(Taskinfo_Hash.find(MainTask)->GetPreHeader(i) != Taskinfo_Hash.find(MainTask)->GetHeader()){
            UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetPreHeader(i) + "[PreHeader]");
            UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetPreHeader(i)));
        }
    }

    size = Taskinfo_Hash.find(MainTask)->GetPreReviewerNum();

    if(Taskinfo_Hash.find(MainTask)->GetReviewer() != ""){
        UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetReviewer() + "[Reviewer]");
        UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetReviewer()));
    }
    qDebug() << MainTask <<  "reviewer" << size;
    for (int i = 0; i < size; i ++) {
        if(Taskinfo_Hash.find(MainTask)->GetPreReviewer(i) != Taskinfo_Hash.find(MainTask)->GetReviewer()){
            UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetPreReviewer(i) + "[PreReviewer]");
            UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetPreReviewer(i)));
        }
    }

    for(int i = 0; i < 5; i ++){
        if(Taskinfo_Hash.find(MainTask)->GetTranslator(i) != ""){
            UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetTranslator(i) + "[Translator]");
            UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetTranslator(i)));
         }
    }

    size = Taskinfo_Hash.find(MainTask)->GetPreTranslatorNum();
    for (int i = 0; i < size; i ++) {
        if(!Taskinfo_Hash.find(MainTask)->isTranslator(Taskinfo_Hash.find(MainTask)->GetPreTranslator(i))){
            UserList ->addItem(Taskinfo_Hash.find(MainTask)->GetPreTranslator(i) + "[PreTranslator]");
            UserStack ->addWidget(new dialog_main_userinfo_onlyread(Taskinfo_Hash.find(MainTask)->GetPreTranslator(i)));
        }
    }

}
