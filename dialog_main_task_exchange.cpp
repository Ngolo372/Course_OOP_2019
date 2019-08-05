#include "dialog_main_task_exchange.h"

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

dialog_main_task_exchange::dialog_main_task_exchange(QWidget *parent) : QWidget(parent)
{

}


//析构

dialog_main_task_exchange::~dialog_main_task_exchange()
{

}


//带参构造

dialog_main_task_exchange::dialog_main_task_exchange(int task0, int translator0, int role)
{
    serial = translator0;
    MainTask = task0;
    MainTranslator = Taskinfo_Hash.find(MainTask).value().GetTranslator(serial);
    Myrole = role;

    task_exchange_main_label = new QLabel("My Part");
    task_exchange_translated_label = new QLabel("Handin Trans");
    task_exchange_translated_pre_label = new QLabel("My Saved Trans");
    task_exchange_feedback_label = new QLabel("Head Feedback");
    task_exchange_feedback2_label = new QLabel("Review back");
    mainLayout = new QGridLayout;
    task_exchange_main_textedit = new QTextEdit;
    task_exchange_main_textedit ->setText(Taskinfo_Hash.find(MainTask).value().Get_Main_S(serial));
    task_exchange_translated_textedit = new QTextEdit;
    task_exchange_translated_textedit ->setText(Taskinfo_Hash.find(MainTask).value().Get_Result_S(serial));
    task_exchange_translated_pre_textedit = new QTextEdit;
    task_exchange_translated_pre_textedit ->setText(Taskinfo_Hash.find(MainTask).value().GetResult_Tem(serial));
    task_exchange_feedback_textedit = new QTextEdit;
    task_exchange_feedback_textedit ->setText(Taskinfo_Hash.find(MainTask).value().GetFeedback(serial));

    task_exchange_feedback2_textedit = new QTextEdit;
    task_exchange_feedback2_textedit ->setText(Taskinfo_Hash.find(MainTask).value().GetFeedBack2(serial));

    mainLayout ->addWidget(task_exchange_translated_label, 0, 0);
    mainLayout ->addWidget(task_exchange_translated_textedit, 1, 0);
    UpBtn  = new QPushButton("Hand in");
    SaveBtn = new QPushButton("Save");
    PartBtn = new QPushButton("Give Part");

    Btn1Layout = new QHBoxLayout;
    PassBtn = new QPushButton("Pass");
    FailBtn = new QPushButton("No Pass");
    Btn2Layout = new QHBoxLayout;
    Pass2Btn = new QPushButton("Pass");
    Fail2Btn = new QPushButton("No Pass");
    Btn3Layout = new QHBoxLayout;

    SaveBtn ->setEnabled(0);
    UpBtn ->setEnabled(0);
    PassBtn ->setEnabled(0);
    FailBtn ->setEnabled(0);
    Pass2Btn ->setEnabled(0);
    Fail2Btn ->setEnabled(0);
    PartBtn ->setEnabled(0);
    Btn1Layout ->addWidget(UpBtn);
    Btn1Layout ->addWidget(SaveBtn);

    Btn2Layout ->addWidget(PassBtn);
    Btn2Layout ->addWidget(FailBtn);
    Btn3Layout ->addWidget(Pass2Btn);
    Btn3Layout ->addWidget(Fail2Btn);

    task_exchange_layout =  new QVBoxLayout(this);
    task_exchange_layout ->addWidget(task_exchange_main_label);
    task_exchange_layout ->addWidget(task_exchange_main_textedit);
    task_exchange_layout ->addWidget(PartBtn);
    task_exchange_layout ->addLayout(mainLayout);
    task_exchange_layout ->addLayout(Btn1Layout);
    task_exchange_layout ->addWidget(task_exchange_feedback_label);
    task_exchange_layout ->addWidget(task_exchange_feedback_textedit);
    task_exchange_layout ->addLayout(Btn2Layout);
    task_exchange_layout ->addWidget(task_exchange_feedback2_label);
    task_exchange_layout ->addWidget(task_exchange_feedback2_textedit);
    task_exchange_layout ->addLayout(Btn3Layout);


    //译者：上传与保存翻译结果

    if(Myrole == 4){

        if(OnlineUser.GetUsername() == Taskinfo_Hash.find(MainTask).value().GetTranslator(serial)){
            SaveBtn ->setEnabled(1);
            UpBtn ->setEnabled(1);
            mainLayout ->addWidget(task_exchange_translated_pre_label, 0, 1);
            mainLayout ->addWidget(task_exchange_translated_pre_textedit, 1, 1);
            connect(SaveBtn, SIGNAL(clicked()), this, SLOT(SaveResult()));
            connect(UpBtn, SIGNAL(clicked()), this, SLOT(UpResult()));
        }
    }


    //负责人：分配任务、给予反馈

    if(Myrole == 2){
        PassBtn ->setEnabled(1);
        FailBtn ->setEnabled(1);
        if(Taskinfo_Hash.find(MainTask).value().Get_Main_S(serial) == "")
        PartBtn ->setEnabled(1);
        connect(PartBtn, SIGNAL(clicked()), this, SLOT(GiveTask()));
        connect(PassBtn, SIGNAL(clicked()), this, SLOT(FeedH_Pass()));
        connect(FailBtn, SIGNAL(clicked()), this, SLOT(FeedH_Fail()));
    }


    //审核人：给予反馈

    if(Myrole == 3){
        Pass2Btn ->setEnabled(1);
        Fail2Btn ->setEnabled(1);
        connect(Pass2Btn, SIGNAL(clicked()), this, SLOT(FeedR_Pass()));
        connect(Fail2Btn, SIGNAL(clicked()), this, SLOT(FeedR_Fail()));
    }

}


//分配任务

void dialog_main_task_exchange::GiveTask()
{
    if(QMessageBox::question(this, "Give Task" , "Sure?") == QMessageBox::Yes)
    {
        Taskinfo_Hash.find(MainTask)->set_Main(serial, task_exchange_main_textedit ->toPlainText());
        Taskinfo_Hash.find(MainTask)->UpdateMainpart[serial] = 1;
        PartBtn ->setEnabled(0);

        //发送消息

        QString usernamet = Taskinfo_Hash.find(MainTask).value().GetTranslator(serial);
        message newmess1(MainTask, OnlineUser.GetUsername(), "",usernamet, task_exchange_main_textedit ->toPlainText(),50);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

        QString usernamer = Taskinfo_Hash.find(MainTask).value().GetReviewer();
        message newmess2(MainTask, usernamer,  OnlineUser.GetUsername(), usernamet, task_exchange_main_textedit ->toPlainText(),51);
        newmess2.floatid = Message_Hash.find(usernamer).value().size() + MainTask * 1000;
        Message_Hash.find(usernamer).value().enqueue(newmess2);
        Message_New_Hash.find(usernamer).value().enqueue(newmess2);

        message newmess3(MainTask, usernamet, OnlineUser.GetUsername(), "",  task_exchange_main_textedit ->toPlainText(),52);
        newmess3.floatid = Message_Hash.find(usernamet).value().size() + MainTask * 1000;
        Message_Hash.find(usernamet).value().enqueue(newmess3);
        Message_New_Hash.find(usernamet).value().enqueue(newmess3);
    }
}


//保存翻译结果

void dialog_main_task_exchange::SaveResult()
{
    if(QMessageBox::question(this, "Save", "Sure?") == QMessageBox::Yes){
        Taskinfo_Hash.find(MainTask)->set_Resultsave(serial, task_exchange_translated_pre_textedit ->toPlainText());
        Taskinfo_Hash.find(MainTask)->UpdateResultSavepart[serial] = 1;

        message newmess1(MainTask, OnlineUser.GetUsername(), "", "", task_exchange_translated_pre_textedit ->toPlainText(),47);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
    }
}


//上传翻译结果

void dialog_main_task_exchange::UpResult()
{
    if(QMessageBox::question(this, "Upload", "Sure?") == QMessageBox::Yes){
        Taskinfo_Hash.find(MainTask)->set_Result(serial, task_exchange_translated_textedit ->toPlainText());
        Taskinfo_Hash.find(MainTask)->UpdateResultpart[serial] = 1;
        message newmess1(MainTask, OnlineUser.GetUsername(), "", "", task_exchange_translated_textedit ->toPlainText(),41);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

        QString usernameh = Taskinfo_Hash.find(MainTask).value().GetHeader();
        message newmess2(MainTask, usernameh, OnlineUser.GetUsername(), "", task_exchange_translated_textedit ->toPlainText(),23);
        newmess2.floatid = Message_Hash.find(usernameh).value().size() + MainTask * 1000;
        Message_Hash.find(usernameh).value().enqueue(newmess2);
        Message_New_Hash.find(usernameh).value().enqueue(newmess2);

        QString usernamer = Taskinfo_Hash.find(MainTask).value().GetReviewer();
        message newmess3(MainTask, usernamer, OnlineUser.GetUsername(), "", task_exchange_translated_textedit ->toPlainText(),31);
        newmess3.floatid = Message_Hash.find(usernamer).value().size() + MainTask * 1000;
        Message_Hash.find(usernamer).value().enqueue(newmess3);
        Message_New_Hash.find(usernamer).value().enqueue(newmess3);
    }
}


//反馈信息

void dialog_main_task_exchange::FeedH_Fail()
{
    if(QMessageBox::question(this, "No pass it", "Sure?") == QMessageBox::Yes){
        Taskinfo_Hash.find(MainTask)->set_Feedback1(serial, task_exchange_feedback_textedit ->toPlainText());
        Taskinfo_Hash.find(MainTask)->UpdateHFpart [serial] = 1;
        QString usernameh = Taskinfo_Hash.find(MainTask).value().GetReviewer();
        QString usernamer = Taskinfo_Hash.find(MainTask).value().GetTranslator(serial);

        message newmess1(MainTask, OnlineUser.GetUsername(), usernamer, "", task_exchange_feedback_textedit ->toPlainText(),24);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);


        message newmess2(MainTask, usernameh, OnlineUser.GetUsername(), usernamer, task_exchange_feedback_textedit ->toPlainText(),33);
        newmess2.floatid = Message_Hash.find(usernameh).value().size() + MainTask * 1000;
        Message_Hash.find(usernameh).value().enqueue(newmess2);
        Message_New_Hash.find(usernameh).value().enqueue(newmess2);

        message newmess3(MainTask, usernamer, OnlineUser.GetUsername(), "", task_exchange_feedback_textedit ->toPlainText(),42);
        newmess3.floatid = Message_Hash.find(usernamer).value().size() + MainTask * 1000;
        Message_Hash.find(usernamer).value().enqueue(newmess3);
        Message_New_Hash.find(usernamer).value().enqueue(newmess3);
    }
}

void dialog_main_task_exchange::FeedR_Fail()
{
    if(QMessageBox::question(this, "Give advice", "Sure?") == QMessageBox::Yes){
        Taskinfo_Hash.find(MainTask)->set_Feedback2(serial, task_exchange_feedback2_textedit ->toPlainText());
        Taskinfo_Hash.find(MainTask)->UpdateRFpart [serial] = 1;

        QString usernamer = Taskinfo_Hash.find(MainTask).value().GetTranslator(serial);
        message newmess1(MainTask, OnlineUser.GetUsername(), usernamer, "", task_exchange_feedback2_textedit ->toPlainText(),32);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

        QString usernameh = Taskinfo_Hash.find(MainTask).value().GetHeader();
        message newmess2(MainTask, usernameh, OnlineUser.GetUsername(), "", task_exchange_feedback2_textedit ->toPlainText(),25);
        newmess2.floatid = Message_Hash.find(usernameh).value().size() + MainTask * 1000;
        Message_Hash.find(usernameh).value().enqueue(newmess2);
        Message_New_Hash.find(usernameh).value().enqueue(newmess2);


        message newmess3(MainTask, usernamer, OnlineUser.GetUsername(), usernamer, task_exchange_feedback2_textedit ->toPlainText(),43);
        newmess3.floatid = Message_Hash.find(usernamer).value().size() + MainTask * 1000;
        Message_Hash.find(usernamer).value().enqueue(newmess3);
        Message_New_Hash.find(usernamer).value().enqueue(newmess3);
    }
}


void dialog_main_task_exchange::FeedH_Pass()
{
    if(QMessageBox::question(this, "Give it pass", "Sure?") == QMessageBox::Yes){
        Taskinfo_Hash.find(MainTask)->set_Feedback1(serial, "OK");
        Taskinfo_Hash.find(MainTask)->UpdateHFpart [serial] = 1;

        QString usernamer = Taskinfo_Hash.find(MainTask).value().GetTranslator(serial);
        message newmess1(MainTask, OnlineUser.GetUsername(), usernamer, "" ,28);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

        QString usernameh = Taskinfo_Hash.find(MainTask).value().GetReviewer();
        message newmess2(MainTask, usernameh, OnlineUser.GetUsername(), usernamer, 37);
        newmess2.floatid = Message_Hash.find(usernameh).value().size() + MainTask * 1000;
        Message_Hash.find(usernameh).value().enqueue(newmess2);
        Message_New_Hash.find(usernameh).value().enqueue(newmess2);


        message newmess3(MainTask, usernamer, OnlineUser.GetUsername(), "", 45);
        newmess3.floatid = Message_Hash.find(usernamer).value().size() + MainTask * 1000;
        Message_Hash.find(usernamer).value().enqueue(newmess3);
        Message_New_Hash.find(usernamer).value().enqueue(newmess3);
    }
}

void dialog_main_task_exchange::FeedR_Pass()
{
    if(QMessageBox::question(this, "Give it pass", "Sure?") == QMessageBox::Yes){
        Taskinfo_Hash.find(MainTask)->set_Feedback2(serial, "OK");
        Taskinfo_Hash.find(MainTask)->UpdateRFpart [serial] = 1;

        QString usernamer = Taskinfo_Hash.find(MainTask).value().GetTranslator(serial);
        QString usernameh = Taskinfo_Hash.find(MainTask).value().GetHeader();

        message newmess1(MainTask, OnlineUser.GetUsername(), usernamer, "", 36);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + MainTask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

        message newmess2(MainTask, usernameh, OnlineUser.GetUsername(), usernamer,29);
        newmess2.floatid = Message_Hash.find(usernameh).value().size() + MainTask * 1000;
        Message_Hash.find(usernameh).value().enqueue(newmess2);
        Message_New_Hash.find(usernameh).value().enqueue(newmess2);


        message newmess3(MainTask, usernamer, OnlineUser.GetUsername(), "", 46);
        newmess3.floatid = Message_Hash.find(usernamer).value().size() + MainTask * 1000;
        Message_Hash.find(usernamer).value().enqueue(newmess3);
        Message_New_Hash.find(usernamer).value().enqueue(newmess3);
    }
}
