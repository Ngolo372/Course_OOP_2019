#include "dialog_main_task_tab_endtask.h"

//容器

extern User OnlineUser;
extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;
extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;
extern QHash <QString, QQueue<message>>Message_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_Hash_iter;
extern QHash <QString, QQueue<message>>Message_New_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_New_Hash_iter;
extern QQueue<message> Message_Queue[1000];
extern QQueue<message> Message_New_Queue[1000];

dialog_main_task_tab_endtask::dialog_main_task_tab_endtask(QWidget *parent) : QWidget(parent)
{

}

dialog_main_task_tab_endtask::~dialog_main_task_tab_endtask()
{

}

dialog_main_task_tab_endtask::dialog_main_task_tab_endtask(int id, int role)
{
    Maintask = id;
    mainlabel = new QLabel("Results");
    maintext = new QTextEdit;
    upBtn = new QPushButton("upload");
    moneyBtn = new QPushButton;
    passBtn = new QPushButton("Pass the task");
    upBtn ->setEnabled(0);
    moneyBtn ->setEnabled(0);
    passBtn ->setEnabled(0);

    Btnlayout = new QHBoxLayout;
    Btnlayout ->addWidget(passBtn);
    Btnlayout ->addWidget(upBtn);
    Btnlayout ->addWidget(moneyBtn);
    Layout = new QVBoxLayout(this);
    Layout ->addWidget(mainlabel);
    Layout ->addWidget(maintext);
    Layout ->addLayout(Btnlayout);

    //发布人权限： 超过ddl未提交（4）/未审核（5）可提出举报；对完成的任务（6）付款

    if(role == 1){
        if((Taskinfo_Hash.find(Maintask).value().GetState() == 4 ||
                Taskinfo_Hash.find(Maintask).value().GetState() == 5)
                && QDateTime::currentDateTime() > Taskinfo_Hash.find(Maintask).value().GetDDL_Final()){
            moneyBtn ->setText("accord");
            moneyBtn ->setEnabled(1);
            connect(moneyBtn, SIGNAL(clicked()), this, SLOT(accord()));
        }
        if(Taskinfo_Hash.find(Maintask).value().GetState() == 6){
            moneyBtn ->setText("pay");
            moneyBtn ->setEnabled(1);
            connect(moneyBtn, SIGNAL(clicked()), this, SLOT(givemoney()));
        }
        if(Taskinfo_Hash.find(Maintask).value().GetState() == 7){
            maintext ->setText(Taskinfo_Hash.find(Maintask).value().Get_Result_Total_S());
        }

    }


    //负责人、审核人、译者权限： 发布人付款后（7）领取酬金

    if(role >= 2 && role <= 4){
        moneyBtn ->setText("get reward");
        maintext ->setText(Taskinfo_Hash.find(Maintask).value().Get_Result_Total_S());
        if(Taskinfo_Hash.find(Maintask).value().GetState() == 4 ||
                Taskinfo_Hash.find(Maintask).value().GetState() == 5)upBtn ->setEnabled(1);
        if(Taskinfo_Hash.find(Maintask).value().GetState() == 7
                /*|| (Taskinfo_Hash.find(Maintask).value().GetState() == 5
                    && QDateTime::currentDateTime().addDays(-1) > Taskinfo_Hash.find(Maintask).value().GetDDL_Final())*/)
            moneyBtn ->setEnabled(1);
        connect(upBtn, SIGNAL(clicked()), this, SLOT(up()));
        connect(moneyBtn, SIGNAL(clicked()), this, SLOT(getmoney()));
        connect(passBtn, SIGNAL(clicked()), this, SLOT(pass()));
    }


    //审核人权限： 决定是否结项

    if(role == 3 && Taskinfo_Hash.find(Maintask).value().GetState() == 5)passBtn ->setEnabled(1);
}


//负责人上传结果， 审核人给予意见

void dialog_main_task_tab_endtask::up()
{
    Taskinfo_Hash.find(Maintask).value().EndTaskflag = 1;
    switch (Taskinfo_Hash.find(Maintask)->LinkRelation(OnlineUser)) {
    case 2:
        if(QMessageBox::question(this, "UP your whole result", "Sure?") == QMessageBox::Yes){
            if(QDateTime::currentDateTime() < Taskinfo_Hash.find(Maintask).value().GetDDL_Final()){
                Taskinfo_Hash.find(Maintask).value().UpdateTaskFlag[12] = 1;
                Taskinfo_Hash.find(Maintask).value().SetState(5);
                Taskinfo_Hash.find(Maintask).value().set_ResultTotal(maintext ->toPlainText());
                message newmess1(Maintask, OnlineUser.GetUsername(), 26);
                newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + Maintask * 1000;
                Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
                Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

                QString usernamer = Taskinfo_Hash.find(Maintask).value().GetReviewer();
                message newmess2(Maintask, usernamer,  OnlineUser.GetUsername(), 34);
                newmess2.floatid = Message_Hash.find(usernamer).value().size() + Maintask * 1000;
                Message_Hash.find(usernamer).value().enqueue(newmess2);
                Message_New_Hash.find(usernamer).value().enqueue(newmess2);

                QString usernamep = Taskinfo_Hash.find(Maintask).value().GetPublisher();
                message newmess3(Maintask, usernamep, OnlineUser.GetUsername(), 34);
                newmess3.floatid = Message_Hash.find(usernamep).value().size() + Maintask * 1000;
                qDebug() << newmess3.floatid;
                Message_Hash.find(usernamep).value().enqueue(newmess3);
                Message_New_Hash.find(usernamep).value().enqueue(newmess3);
            }


        }
        break;
    case 3:
        if(QMessageBox::question(this, "UP your advice and let the header modify", "Sure?") == QMessageBox::Yes){
            if(QDateTime::currentDateTime() < Taskinfo_Hash.find(Maintask).value().GetDDL_Final()){
                passBtn ->setEnabled(0);
                Taskinfo_Hash.find(Maintask).value().UpdateTaskFlag[12] = 1;
                Taskinfo_Hash.find(Maintask).value().SetState(4);
                Taskinfo_Hash.find(Maintask).value().set_ResultTotal(maintext ->toPlainText());
                message newmess1(Maintask, OnlineUser.GetUsername(), 38);
                newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + Maintask * 1000;
                Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
                Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

                QString usernamer = Taskinfo_Hash.find(Maintask).value().GetHeader();
                message newmess2(Maintask, usernamer,  OnlineUser.GetUsername(), 39);
                newmess2.floatid = Message_Hash.find(usernamer).value().size() + Maintask * 1000;
                Message_Hash.find(usernamer).value().enqueue(newmess2);
                Message_New_Hash.find(usernamer).value().enqueue(newmess2);

                QString usernamep = Taskinfo_Hash.find(Maintask).value().GetPublisher();
                message newmess3(Maintask, usernamep, OnlineUser.GetUsername(), 39);
                newmess3.floatid = Message_Hash.find(usernamep).value().size() + Maintask * 1000;
                qDebug() << newmess3.floatid;
                Message_Hash.find(usernamep).value().enqueue(newmess3);
                Message_New_Hash.find(usernamep).value().enqueue(newmess3);
            }
        }
        break;
    default:
        break;
    }
    qDebug() << Taskinfo_Hash.find(Maintask)->Get_Result_Total_S();
}


//审核人结项

void dialog_main_task_tab_endtask::pass()
{
    if(QMessageBox::question(this, "UP to publisher finally", "Sure?") == QMessageBox::Yes)
    {
        QMessageBox::information(this, "OK", "Confirm success");
        passBtn ->setEnabled(0);
        upBtn ->setEnabled(0);
        Taskinfo_Hash.find(Maintask).value().EndTaskflag = 1;
        Taskinfo_Hash.find(Maintask).value().UpdateTaskFlag[12] = 1;
        Taskinfo_Hash.find(Maintask).value().SetState(6);

        message newmess1(Maintask, OnlineUser.GetUsername(), 53);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + Maintask * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

        QString usernamer = Taskinfo_Hash.find(Maintask).value().GetHeader();
        message newmess2(Maintask, usernamer,  OnlineUser.GetUsername(), 54);
        newmess2.floatid = Message_Hash.find(usernamer).value().size() + Maintask * 1000;
        Message_Hash.find(usernamer).value().enqueue(newmess2);
        Message_New_Hash.find(usernamer).value().enqueue(newmess2);

        QString usernamep = Taskinfo_Hash.find(Maintask).value().GetPublisher();
        message newmess3(Maintask, usernamep, OnlineUser.GetUsername(), 54);
        newmess3.floatid = Message_Hash.find(usernamep).value().size() + Maintask * 1000;
        qDebug() << newmess3.floatid;
        Message_Hash.find(usernamep).value().enqueue(newmess3);
        Message_New_Hash.find(usernamep).value().enqueue(newmess3);
    }
}


//领取酬金

void dialog_main_task_tab_endtask::getmoney()
{
    if(QMessageBox::question(this, "  get money", "Sure?") == QMessageBox::Yes){

        Userinfo_Hash.find(OnlineUser.GetUsername()).value().Changeinfoflag[27] = 1;
        Userinfo_Hash.find(OnlineUser.GetUsername()).value().Changeinfoflag[14] = 1;
        Userinfo_Hash.find(OnlineUser.GetUsername()).value().Changeinfoflag[15] = 1;
        Taskinfo_Hash.find(Maintask).value().UpdateTaskFlag[12] = 1;


        int role = Taskinfo_Hash.find(Maintask).value().LinkRelation(OnlineUser);
        double getmoneynum = Taskinfo_Hash.find(Maintask).value().GetReward_Publish();

        switch (role) {
        case 2:
            getmoneynum *= 0.2;
            break;
        case 3:
            getmoneynum *= 0.2;
            break;
        case 4:
            getmoneynum *= 0.6;
            getmoneynum /= Taskinfo_Hash.find(Maintask).value().GetTranslatorNum();
            break;
        }
        Userinfo_Hash.find(OnlineUser.GetUsername()).value().AddMoney(getmoneynum);
        Userinfo_Hash.find(OnlineUser.GetUsername()).value().Add_User_Task_Integral(100);
        message newmess1(Maintask, OnlineUser.GetUsername(), 27);
        newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + Maintask * 1000;
        newmess1.message_add(QString(" get money %1").arg(getmoneynum));
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
        moneyBtn ->setEnabled(0);
        QMessageBox::information(this, "Success", QString("get money %1").arg(getmoneynum));
    }
}


//付款

void dialog_main_task_tab_endtask::givemoney()
{
    //余额判断

    if(OnlineUser.Get_User_Money() < Taskinfo_Hash.find(Maintask).value().Task_Reward_Publisher){
        QMessageBox::warning(this, "not enough", "");
    }

    else {
        if(QMessageBox::question(this, "pay and get back", "Sure?") == QMessageBox::Yes){
            message newmess1(Maintask, OnlineUser.GetUsername(), 15);
            newmess1.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + Maintask * 1000;
            double givemoneysum = Taskinfo_Hash.find(Maintask).value().GetReward_Publish();
            newmess1.message_add(QString(" pay money %1").arg(givemoneysum));
            Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);
            Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess1);

            message newmess2(Maintask, Taskinfo_Hash.find(Maintask)->GetHeader(), 55);
            newmess2.floatid = Message_Hash.find(Taskinfo_Hash.find(Maintask)->GetHeader()).value().size() + Maintask * 1000;
            Message_Hash.find(Taskinfo_Hash.find(Maintask)->GetHeader()).value().enqueue(newmess2);
            Message_New_Hash.find(Taskinfo_Hash.find(Maintask)->GetHeader()).value().enqueue(newmess2);

            message newmess3(Maintask, Taskinfo_Hash.find(Maintask)->GetReviewer(), 55);
            newmess3.floatid = Message_Hash.find(Taskinfo_Hash.find(Maintask)->GetReviewer()).value().size() + Maintask * 1000;
            Message_Hash.find(Taskinfo_Hash.find(Maintask)->GetReviewer()).value().enqueue(newmess3);
            Message_New_Hash.find(Taskinfo_Hash.find(Maintask)->GetReviewer()).value().enqueue(newmess3);

            for (int i = 0; i < Taskinfo_Hash.find(Maintask).value().GetTranslatorNum(); i ++) {
                message newmess4(Maintask, Taskinfo_Hash.find(Maintask)->GetTranslator(i), 55);
                newmess4.floatid = Message_Hash.find(Taskinfo_Hash.find(Maintask)->GetTranslator(i)).value().size() + Maintask * 1000;
                Message_Hash.find(Taskinfo_Hash.find(Maintask)->GetTranslator(i)).value().enqueue(newmess4);
                Message_New_Hash.find(Taskinfo_Hash.find(Maintask)->GetTranslator(i)).value().enqueue(newmess4);
            }

            Taskinfo_Hash.find(Maintask).value().SetState(7);
            Taskinfo_Hash.find(Maintask).value().UpdateTaskFlag[12] = 1;

            Userinfo_Hash.find(OnlineUser.GetUsername()).value().Changeinfoflag[27] = 1;
            Userinfo_Hash.find(OnlineUser.GetUsername()).value().SubMoney(givemoneysum);
            qDebug() << Userinfo_Hash.find(OnlineUser.GetUsername()).value().Get_User_Money();
            moneyBtn ->setEnabled(0);
            maintext ->setText(Taskinfo_Hash.find(Maintask).value().Get_Result_Total_S());
            QMessageBox::information(this, "Success", QString("pay money %1").arg(givemoneysum));
        }
    }
}


//举报

void dialog_main_task_tab_endtask::accord()
{
    if(QMessageBox::Yes == QMessageBox::question(this, "Accord", "You will accord the header or reviewer"))
    {
        moneyBtn ->setEnabled(0);
     Taskinfo_Hash.find(Maintask).value().SetTaskFail();
    }
}
