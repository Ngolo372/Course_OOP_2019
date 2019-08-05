#include "dialog_main_task_tab_new.h"

extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern User OnlineUser;
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

dialog_main_task_tab_new::dialog_main_task_tab_new(QWidget *parent) : dialog_main_task_tab(parent)
{
    issaved = 0;
    Dialog_Main_Task_Full();
}

dialog_main_task_tab_new::~dialog_main_task_tab_new()
{

}


//完成布局

void dialog_main_task_tab_new::Dialog_Main_Task_Full()
{
    Dialog_Main_Taskmain_TextEdit ->setEnabled(true);

    Lan_Error = new QLabel(tr("*ERROR: CAN'T be the same language"));
    Dialog_Main_Task_Lan0_Combox = new QComboBox;
    Dialog_Main_Task_Lan1_Combox = new QComboBox;
    Dialog_Main_Task_Lan0_Combox ->insertItem(0, "Simplified Chinese");
    Dialog_Main_Task_Lan0_Combox ->insertItem(1, "Traditional Chinese");
    Dialog_Main_Task_Lan0_Combox ->insertItem(2, "English");
    Dialog_Main_Task_Lan0_Combox ->insertItem(3, "Russian");
    Dialog_Main_Task_Lan1_Combox ->insertItem(0, "Simplified Chinese");
    Dialog_Main_Task_Lan1_Combox ->insertItem(1, "Traditional Chinese");
    Dialog_Main_Task_Lan1_Combox ->insertItem(2, "English");
    Dialog_Main_Task_Lan1_Combox ->insertItem(3, "Russian");

    Dialog_Main_Task_HI_Num = new QSpinBox;
    Dialog_Main_Task_RI_Num = new QSpinBox;
    Dialog_Main_Task_Reward_Num = new QDoubleSpinBox;
    Dialog_Main_Task_HI_Num ->setMinimum(1000);
    Dialog_Main_Task_RI_Num ->setMinimum(1000);
    Dialog_Main_Task_Reward_Num ->setMinimum(2000);
    Dialog_Main_Task_HI_Num ->setMaximum(20000);
    Dialog_Main_Task_RI_Num ->setMaximum(20000);
    Dialog_Main_Task_Reward_Num ->setMaximum(40000);
    Dialog_Main_Task_Reward_Num ->setDecimals(2);

    Dialog_Main_Task_Lan_Layout = new QGridLayout;
    Dialog_Main_Task_Lan_Layout ->addWidget(Dialog_Main_Task_Lan0_label, 0, 0);
    Dialog_Main_Task_Lan_Layout ->addWidget(Dialog_Main_Task_Lan1_label, 1, 0);
    Dialog_Main_Task_Lan_Layout ->addWidget(Dialog_Main_Task_Lan0_Combox, 0, 1);
    Dialog_Main_Task_Lan_Layout ->addWidget(Dialog_Main_Task_Lan1_Combox, 1, 1);
    Dialog_Main_Task_Lan_Layout ->addWidget(Lan_Error);

    Dialog_Main_Task_TR_Layout = new QGridLayout;
    Dialog_Main_Task_TR_Layout ->addWidget(Dialog_Main_Task_IntH_label, 0, 0);
    Dialog_Main_Task_TR_Layout ->addWidget(Dialog_Main_Task_HI_Num, 0, 1);
    Dialog_Main_Task_TR_Layout ->addWidget(Dialog_Main_Task_IntR_label, 1, 0);
    Dialog_Main_Task_TR_Layout ->addWidget(Dialog_Main_Task_RI_Num, 1, 1);
    Dialog_Main_Task_TR_Layout ->addWidget(Dialog_Main_Task_Reward_label, 2, 0);
    Dialog_Main_Task_TR_Layout ->addWidget(Dialog_Main_Task_Reward_Num, 2, 1);

    Dialog_Main_DDL_Header_Edit = new QDateTimeEdit;
    Dialog_Main_DDL_Reviewer_Edit = new QDateTimeEdit;
    Dialog_Main_DDL_Edit = new QDateTimeEdit;
    Dialog_Main_DDL_Header_Edit ->setCalendarPopup(1);
    Dialog_Main_DDL_Reviewer_Edit ->setCalendarPopup(1);
    Dialog_Main_DDL_Edit ->setCalendarPopup(1);
    QDateTime curDateTime=QDateTime::currentDateTime();
    Dialog_Main_DDL_Edit ->setMinimumDateTime(curDateTime.addSecs(300));
    Dialog_Main_DDL_Header_Edit ->setMinimumDateTime(curDateTime.addSecs(60));
    Dialog_Main_DDL_Reviewer_Edit ->setMinimumDateTime(curDateTime.addSecs(150));

    Dialog_Main_DDL_Layout ->addWidget(Dialog_Main_DDL_Edit, 0, 1);
    Dialog_Main_DDL_Layout ->addWidget(Dialog_Main_DDL_Header_Edit, 1, 1);
    Dialog_Main_DDL_Layout ->addWidget(Dialog_Main_DDL_Reviewer_Edit, 2, 1);

    Dialog_Main_Task_Tab_New_Layout = new QVBoxLayout(this);
    Dialog_Main_Task_Tab_New_Layout ->addLayout(Dialog_Main_Task_Lan_Layout);
    Dialog_Main_Task_Tab_New_Layout ->addLayout(Dialog_Main_Task_Tab_Info_Layout);
    Dialog_Main_Task_Tab_New_Layout ->addLayout(Dialog_Main_Task_TR_Layout);
    Dialog_Main_Task_Tab_New_Layout ->addLayout(Dialog_Main_DDL_Layout);
    Dialog_Main_Task_Tab_New_Layout ->addLayout(Dialog_Main_Task_Tab_Btn_Layout);

    connect(Dialog_Main_Task_Lan0_Combox, SIGNAL(currentIndexChanged(int)), this, SLOT(Legal_Lan()));
    connect(Dialog_Main_Task_Lan1_Combox, SIGNAL(currentIndexChanged(int)), this, SLOT(Legal_Lan()));
    connect(Dialog_Main_Task_HI_Num, SIGNAL(valueChanged(int)), this, SLOT(Legal_Int()));
    connect(Dialog_Main_Task_RI_Num, SIGNAL(valueChanged(int)), this, SLOT(Legal_Int()));
    connect(Dialog_Main_Task_Reward_Num, SIGNAL(valueChanged(double)), this, SLOT(Legal_Int()));
    connect(Dialog_Main_DDL_Edit, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(Legal_Time()));
    connect(Dialog_Main_DDL_Header_Edit, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(Legal_Time()));
    connect(Dialog_Main_DDL_Reviewer_Edit, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(Legal_Time()));
    Task_Publish_Btns();
}


//按钮信号连接

void dialog_main_task_tab_new::Task_Publish_Btns()
{
    connect(Dialog_Main_Task_Tab_Apply_Btn, SIGNAL(clicked()), this, SLOT(Task_Publish_Enable()));
    connect(Dialog_Main_Task_Tab_OK_Btn, SIGNAL(clicked()), this, SLOT(Task_Publish_Complete()));
}

//确保语言、积分、时间输入合法

bool dialog_main_task_tab_new::Legal_Lan()
{
    if(Dialog_Main_Task_Lan0_Combox ->currentIndex() == Dialog_Main_Task_Lan1_Combox ->currentIndex())
    {
        Lan_Error ->setText(tr("*ERROR: CAN'T be the same language"));
        Dialog_Main_Task_Tab_Apply_Btn ->setEnabled(0);
        Dialog_Main_Task_Tab_OK_Btn ->setEnabled(0);
        return 0;
    }
    else {
        Lan_Error ->setText(tr("OK"));
        Dialog_Main_Task_Tab_Apply_Btn ->setEnabled(1);
        Dialog_Main_Task_Tab_OK_Btn ->setEnabled(1);
        return 1;
    }
}


void dialog_main_task_tab_new::Legal_Int()
{
    if(Dialog_Main_Task_RI_Num ->value() < 0)
        Dialog_Main_Task_RI_Num ->setValue(0);
    if(Dialog_Main_Task_RI_Num ->value() < Dialog_Main_Task_HI_Num ->value())
        Dialog_Main_Task_RI_Num ->setValue(Dialog_Main_Task_HI_Num ->value());
    if(Dialog_Main_Task_Reward_Num ->value() < Dialog_Main_Task_HI_Num ->value() + Dialog_Main_Task_RI_Num ->value())
        Dialog_Main_Task_Reward_Num ->setValue(Dialog_Main_Task_HI_Num ->value() + Dialog_Main_Task_RI_Num ->value());
}


void dialog_main_task_tab_new::Legal_Time()
{
    QDateTime curDateTime=QDateTime::currentDateTime();
    Dialog_Main_DDL_Header_Edit ->setMinimumDateTime(curDateTime.addSecs(60));
    Dialog_Main_DDL_Reviewer_Edit ->setMinimumDateTime(Dialog_Main_DDL_Header_Edit ->dateTime().addSecs(90));
    Dialog_Main_DDL_Edit ->setMinimumDateTime(Dialog_Main_DDL_Reviewer_Edit ->dateTime().addSecs(300));
}



// 保存或更新

void dialog_main_task_tab_new::Task_Publish_Enable()
{
    if(!issaved){
        Dialog_Main_TaskID_Label ->setText(tr("ID %1").arg(Taskinfo_Hash.size() + 1));
        NewTask.SetID(Taskinfo_Hash.size() + 1);
        taskID = NewTask.GetID();
        issaved = 1;

        Taskinfo = Dialog_Main_Taskinfo_TextEdit ->toPlainText();
        TaskMain = Dialog_Main_Taskmain_TextEdit ->toPlainText();
        NewTask.SetPublisher(OnlineUser.GetUsername());
        NewTask.SetIntro(Taskinfo);
        NewTask.SetMainTotal(TaskMain);
        NewTask.SetDDL_0();
        NewTask.SetDDL_Final(Dialog_Main_DDL_Edit ->dateTime());
        NewTask.SetDDL_Header(Dialog_Main_DDL_Header_Edit ->dateTime());
        NewTask.SetDDL_Reviewer(Dialog_Main_DDL_Reviewer_Edit ->dateTime());
        NewTask.SetIntH(Dialog_Main_Task_HI_Num ->value());
        NewTask.SetIntR(Dialog_Main_Task_RI_Num ->value());
        NewTask.SetReward_Publish(Dialog_Main_Task_Reward_Num ->value());
        NewTask.SetLan(Dialog_Main_Task_Lan0_Combox ->currentIndex(), Dialog_Main_Task_Lan1_Combox ->currentIndex());
        NewTask.NewTaskFlag = 1;

        Taskinfo_Hash.insert(NewTask.GetID(), NewTask);
        qDebug() << Taskinfo_Hash.size();
        qDebug() << "Add Task" << "ID" << NewTask.GetID() << "State" << NewTask.GetState()
                 << "Publisher" << Taskinfo_Hash.find(NewTask.GetID()).value().GetPublisher()
                 << "From" << Taskinfo_Hash.find(NewTask.GetID()).value().GetLanF() << "To" << Taskinfo_Hash.find(NewTask.GetID()).value().GetLanT()
                 << "INFO" << Taskinfo_Hash.find(NewTask.GetID()).value().Get_Intro_S()
                 << "Main" << Taskinfo_Hash.find(NewTask.GetID()).value().Get_MainTotal_S()
                 << "DDL" << Taskinfo_Hash.find(NewTask.GetID()).value().GetDDL_Final().toString()
                 << "integral" << Taskinfo_Hash.find(NewTask.GetID()).value().GetIntH()
                 << Taskinfo_Hash.find(NewTask.GetID()).value().GetIntR()
                 << "Rewards" << Taskinfo_Hash.find(NewTask.GetID()).value().GetReward_Publish();

        Link_usertask_Hash.find(OnlineUser.GetUsername()).value() .insert(NewTask.GetID(), NewTask.GetState() + 1 * 10);
        qDebug() << Link_usertask_Hash.find(OnlineUser.GetUsername()).value().find(NewTask.GetID()).key();


    }

    else {
        task_update(taskID);
    }
    message newmess(taskID, OnlineUser.GetUsername(), 0);
    newmess.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + taskID * 1000;
    Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);
    Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);

}


//发布

void dialog_main_task_tab_new::Task_Publish_Complete(){
    Task_Publish_Enable();
    if(QMessageBox::Yes == QMessageBox::question(this, "Publish", "Saved, sure to publish?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No)){
        Taskinfo_Hash.find(taskID).value().SetState(1);
        if(Link_usertask_Hash.find(OnlineUser.GetUsername()).value().find(taskID).value()%10 == 0)
            Link_usertask_Hash.find(OnlineUser.GetUsername()).value().find(taskID).value() ++;
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[12] = 1;
        qDebug() << "IMM" << Link_usertask_Hash.find(OnlineUser.GetUsername()).value().find(taskID).value();       

        message newmess(taskID, OnlineUser.GetUsername(), 10);
        newmess.floatid = Message_Hash.find(OnlineUser.GetUsername()).value().size() + taskID * 1000;
        Message_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);
        Message_New_Hash.find(OnlineUser.GetUsername()).value().enqueue(newmess);
        Dialog_Main_Task_Tab_Quit_Btn->click();
    }
}


//刷新

void dialog_main_task_tab_new::task_update(int taskID)
{
    Taskinfo = Dialog_Main_Taskinfo_TextEdit ->toPlainText();
    TaskMain = Dialog_Main_Taskmain_TextEdit ->toPlainText();
    if(Taskinfo != Taskinfo_Hash.find(taskID).value().Get_Intro_S()){
        Taskinfo_Hash.find(taskID).value().SetIntro(Taskinfo);
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[3] = 1;
    }
    if(TaskMain != Taskinfo_Hash.find(taskID).value().Get_MainTotal_S()){
        Taskinfo_Hash.find(taskID).value().SetMainTotal(TaskMain);
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[4] = 1;
    }

    if(Dialog_Main_Task_Lan0_Combox ->currentIndex() != Taskinfo_Hash.find(taskID).value().GetLanF() ||
            Dialog_Main_Task_Lan1_Combox ->currentIndex() != Taskinfo_Hash.find(taskID).value().GetLanT()){
        Taskinfo_Hash.find(taskID).value().SetLan(Dialog_Main_Task_Lan0_Combox ->currentIndex(), Dialog_Main_Task_Lan1_Combox ->currentIndex());
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[1] = 1;
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[2] = 1;
    }

    Taskinfo_Hash.find(taskID).value().SetDDL_0();
    Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[5] = 1;

    if(Dialog_Main_DDL_Edit ->dateTime() != Taskinfo_Hash.find(taskID).value().GetDDL_Final()){
        Taskinfo_Hash.find(taskID).value().SetDDL_Final(Dialog_Main_DDL_Edit ->dateTime());
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[6] = 1;
    }
    if(Dialog_Main_DDL_Header_Edit ->dateTime() != Taskinfo_Hash.find(taskID).value().GetDDL_Header()){
        Taskinfo_Hash.find(taskID).value().SetDDL_Header(Dialog_Main_DDL_Header_Edit ->dateTime());
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[7] = 1;
    }
    if(Dialog_Main_DDL_Reviewer_Edit ->dateTime() != Taskinfo_Hash.find(taskID).value().GetDDL_Reviewer()){
        Taskinfo_Hash.find(taskID).value().SetDDL_Reviewer(Dialog_Main_DDL_Reviewer_Edit ->dateTime());
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[8] = 1;
    }

    if(Dialog_Main_Task_HI_Num ->value() != Taskinfo_Hash.find(taskID).value().GetIntH()){
        Taskinfo_Hash.find(taskID).value().SetIntH(Dialog_Main_Task_HI_Num ->value());
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[9] = 1;
    }
    if(Dialog_Main_Task_RI_Num ->value() != Taskinfo_Hash.find(taskID).value().GetIntR()){
        Taskinfo_Hash.find(taskID).value().SetIntR(Dialog_Main_Task_RI_Num ->value());
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[10] = 1;
    }

        Taskinfo_Hash.find(taskID).value().SetReward_Publish(Dialog_Main_Task_Reward_Num ->value());
        Taskinfo_Hash.find(taskID).value().UpdateTaskFlag[11] = 1;
    Link_usertask_Hash.find(OnlineUser.GetUsername()).value() .find(taskID).value() = Taskinfo_Hash.find(taskID).value().GetState() + 1 * 10;
}
