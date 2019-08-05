#include "dialog_main_task.h"


//容器

extern User OnlineUser;
extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;



//构造

Dialog_Main_Task::Dialog_Main_Task(QWidget *parent) : QWidget(parent)
{

    Dialog_Main_Task_Label = new QLabel(tr("Tasks"));
    Dialog_Main_Task_Tab = new QTabWidget;
    Dialog_Main_Task_All_Table = new QTableWidget(100, 15);
    Dialog_Main_Task_All_Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    Dialog_Main_Task_Self_Table = new QTableWidget(100, 13);
    Dialog_Main_Task_Self_Table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    Dialog_Main_Task_All_Table_Titles << QStringLiteral("ID") << QStringLiteral("Language") << QStringLiteral("StateCode") << QStringLiteral("State")
                                      << QStringLiteral("My Role Code") << QStringLiteral("My Role")<< QString("Introduction")<< QStringLiteral("Publisher") << QStringLiteral("Publish Time")
                                      << QStringLiteral("Header DDL") << QStringLiteral("Reviewer DDL")  << QStringLiteral("DDL")
                                          << QStringLiteral("Header Integral") << QStringLiteral("Reviewer Integral") << QStringLiteral("Reward") ;

    Dialog_Main_Task_Self_Table_Titles << QStringLiteral("TaskID") << QStringLiteral("My Role") << QStringLiteral("My Role Code") << QStringLiteral("Task State") << QStringLiteral("Task State Code");

    Dialog_Main_Task_Self_Table ->setHorizontalHeaderLabels(Dialog_Main_Task_Self_Table_Titles);
    Dialog_Main_Task_All_Table ->setHorizontalHeaderLabels(Dialog_Main_Task_All_Table_Titles);

    Dialog_Main_Task_All_Table ->setSelectionMode(QAbstractItemView::SingleSelection);
    Dialog_Main_Task_All_Table ->setSelectionBehavior(QAbstractItemView::SelectRows);
    Dialog_Main_Task_Self_Table ->setSelectionMode(QAbstractItemView::SingleSelection);
    Dialog_Main_Task_Self_Table ->setSelectionBehavior(QAbstractItemView::SelectRows);

    Dialog_Main_Task_Tab ->addTab(Dialog_Main_Task_All_Table, "All Tasks");
    Dialog_Main_Task_Tab ->addTab(Dialog_Main_Task_Self_Table, "My Tasks");
    Dialog_Main_Task_Tab ->addTab(Dialog_Main_Task_Label, "NULL");
    Dialog_Main_Task_Tab ->setTabsClosable(true);
    ((QTabBar*)(Dialog_Main_Task_Tab->tabBar()))->setTabButton(Dialog_Main_Task_Tab->indexOf(Dialog_Main_Task_All_Table),QTabBar::RightSide,nullptr);
    ((QTabBar*)(Dialog_Main_Task_Tab->tabBar()))->setTabButton(Dialog_Main_Task_Tab->indexOf(Dialog_Main_Task_Self_Table),QTabBar::RightSide,nullptr);
    Dialog_Main_Task_Publish_Btn = new QPushButton(tr("Publish a new task"));
    Dialog_Main_Task_Layout = new QVBoxLayout(this);
    Dialog_Main_Task_Layout ->addWidget(Dialog_Main_Task_Tab);
    Dialog_Main_Task_Layout ->addWidget(Dialog_Main_Task_Publish_Btn);
    Dialog_Main_Task_All_Show();
    Dialog_Main_Task_Self_Show();
    connect(Dialog_Main_Task_Tab, SIGNAL(tabCloseRequested(int)), this, SLOT(Dialog_Main_Task_Remove_Tab(int)));
    connect(Dialog_Main_Task_Tab, SIGNAL(tabBarClicked(int)), this, SLOT(Dialog_Main_Task_Fresh(int)));
    connect(Dialog_Main_Task_Publish_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Main_Task_New_Tab()));
    connect(Dialog_Main_Task_All_Table, SIGNAL(cellDoubleClicked(int,int)),this,SLOT(Dialog_Main_Task_All_Check(int,int)));
    connect(Dialog_Main_Task_Self_Table, SIGNAL(cellDoubleClicked(int,int)),this,SLOT(Dialog_Main_Task_Self_Check(int,int)));
}


//析构

Dialog_Main_Task::~Dialog_Main_Task()
{

}


//新建任务

void Dialog_Main_Task::Dialog_Main_Task_New_Tab()
{
    dialog_main_task_tab_new *newTab = new dialog_main_task_tab_new;
    Dialog_Main_Task_Tab ->addTab(newTab, "New Task");
    Dialog_Main_Task_Tab ->setCurrentWidget(newTab);
    connect(newTab ->Dialog_Main_Task_Tab_Cancel_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Main_Task_Remove_Tab()));
    connect(newTab ->Dialog_Main_Task_Tab_Quit_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Main_Task_Remove_Tab_No_info()));
}


//关闭任务界面

void Dialog_Main_Task::Dialog_Main_Task_Remove_Tab()
{
    if(QMessageBox::Yes == QMessageBox::question(this, "Close", "Sure to leave?", QMessageBox::Yes | QMessageBox::No)){
        delete Dialog_Main_Task_Tab ->currentWidget();
    }
}

//关闭任务界面并跳转上一界面

void Dialog_Main_Task::Dialog_Main_Task_Remove_Tab(int index)
{
    QWidget *F = Dialog_Main_Task_Tab ->currentWidget();
    Dialog_Main_Task_Tab ->setCurrentIndex(index);
    delete Dialog_Main_Task_Tab ->currentWidget();
    Dialog_Main_Task_Tab ->setCurrentWidget(F);
}


//关闭当前任务界面
void Dialog_Main_Task::Dialog_Main_Task_Remove_Tab_No_info()
{
    delete Dialog_Main_Task_Tab ->currentWidget();
}


//列出所有任务

void Dialog_Main_Task::Dialog_Main_Task_All_Show()
{
    int icount = 0;
    int tcount = 0;
    while (tcount <  Taskinfo_Hash.size()) {
        Taskinfo_Hash_iter = Taskinfo_Hash.find(tcount + 1);
        if(Taskinfo_Hash_iter.value().GetState() != 0){
            Dialog_Main_Task_All_Table ->setItem(icount, 0, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash_iter.value().GetID())));
            Dialog_Main_Task_All_Table ->setItem(icount, 1, new QTableWidgetItem(QString("%1 -> %2").arg(Taskinfo_Hash_iter.value().GetLanF()).arg(Taskinfo_Hash_iter.value().GetLanT())));
            Dialog_Main_Task_All_Table ->setItem(icount, 6, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash_iter.value().Get_Intro_S())));
            Dialog_Main_Task_All_Table ->setItem(icount, 8, new QTableWidgetItem((Taskinfo_Hash_iter.value().GetDDL_0()).toString()));
            Dialog_Main_Task_All_Table ->setItem(icount, 11, new QTableWidgetItem((Taskinfo_Hash_iter.value().GetDDL_Final()).toString()));
            Dialog_Main_Task_All_Table ->setItem(icount, 9, new QTableWidgetItem((Taskinfo_Hash_iter.value().GetDDL_Header()).toString()));
            Dialog_Main_Task_All_Table ->setItem(icount, 10, new QTableWidgetItem((Taskinfo_Hash_iter.value().GetDDL_Reviewer()).toString()));
            Dialog_Main_Task_All_Table ->setItem(icount, 12, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash_iter.value().GetIntH())));
            Dialog_Main_Task_All_Table ->setItem(icount, 13, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash_iter.value().GetIntR())));
            Dialog_Main_Task_All_Table ->setItem(icount, 14, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash_iter.value().GetReward_Publish())));
            Dialog_Main_Task_All_Table ->setItem(icount, 2, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash_iter.value().GetState())));
            Dialog_Main_Task_All_Table ->setItem(icount, 3, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash_iter.value().GetState_String())));
            Dialog_Main_Task_All_Table ->setItem(icount, 4, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash_iter.value().LinkRelation_c(OnlineUser))));
            Dialog_Main_Task_All_Table ->setItem(icount, 5, new QTableWidgetItem(role_change(Taskinfo_Hash_iter.value().LinkRelation_c(OnlineUser))));
            Dialog_Main_Task_All_Table ->setItem(icount, 7, new QTableWidgetItem(Taskinfo_Hash_iter.value().GetPublisher()));
            icount ++;
        }

        tcount ++;
    }
}


//列出与自己相关任务

void Dialog_Main_Task::Dialog_Main_Task_Self_Show()
{
    int icount = 0;
    Link_Task_Hash_iter = Link_usertask_Hash.find(OnlineUser.GetUsername()).value().constBegin();
    while (Link_Task_Hash_iter != Link_usertask_Hash.find(OnlineUser.GetUsername()).value().constEnd()) {
        Dialog_Main_Task_Self_Table ->setItem(icount, 0, new QTableWidgetItem(QString("%1").arg(Link_Task_Hash_iter.key())));
        Dialog_Main_Task_Self_Table ->setItem(icount, 1, new QTableWidgetItem(role_change(Link_Task_Hash_iter.value() / 10)));
        Dialog_Main_Task_Self_Table ->setItem(icount, 2, new QTableWidgetItem(QString("%1").arg(Link_Task_Hash_iter.value() / 10)));
        Dialog_Main_Task_Self_Table ->setItem(icount, 3, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash.find(Link_Task_Hash_iter.key()).value().GetState_String())));
        Dialog_Main_Task_Self_Table ->setItem(icount, 4, new QTableWidgetItem(QString("%1").arg(Taskinfo_Hash.find(Link_Task_Hash_iter.key()).value().GetState())));
        Link_Task_Hash_iter ++;
        icount ++;
    }
}


//刷新任务列表

void Dialog_Main_Task::Dialog_Main_Task_Fresh(int index)
{
    if(index == 0)Dialog_Main_Task_All_Show();
    if(index == 1)Dialog_Main_Task_Self_Show();
}


//查看任务

void Dialog_Main_Task::Dialog_Main_Task_All_Check(int index, int index_0)
{
    if(Dialog_Main_Task_All_Table ->item(index, 0)){
        int Pre_Task =Dialog_Main_Task_All_Table ->item(index, 0) ->text().toInt();
        int Pre_state = Dialog_Main_Task_All_Table ->item(index, 2) ->text().toInt();
        int Pre_relation = Taskinfo_Hash.find(Pre_Task)->LinkRelation(OnlineUser);
        Dialog_Main_Task_Tabs_Show(Pre_Task, Pre_relation, Pre_state);
    }
}


void Dialog_Main_Task::Dialog_Main_Task_Self_Check(int index, int index_0){
    if(Dialog_Main_Task_All_Table ->item(index, 0)){
        int Pre_Task =Dialog_Main_Task_Self_Table ->item(index, 0) ->text().toInt();
        int Pre_state = Dialog_Main_Task_Self_Table ->item(index, 4) ->text().toInt();
        int Pre_relation = Dialog_Main_Task_Self_Table ->item(index, 2) ->text().toInt();
        Dialog_Main_Task_Tabs_Show(Pre_Task, Pre_relation, Pre_state);
    }
}


//弹出任务查看界面

void Dialog_Main_Task::Dialog_Main_Task_Tabs_Show(int task, int role, int state)
{
    if(role == 0 || role >= 5){
        dialog_main_task_tab_link_role_0 *newTab = new dialog_main_task_tab_link_role_0(task, state);
        QTabWidget *q = new QTabWidget;
        dialog_main_peoplelist_task *newtabuser = new dialog_main_peoplelist_task(task);
        q ->addTab(newTab, "task info");
        q ->addTab(newtabuser, "users info");
        Dialog_Main_Task_Tab ->addTab(q, QString("%1").arg(task));
        Dialog_Main_Task_Tab ->setCurrentWidget(q);
    }

    if(role == 1 && state == 0){
        dialog_main_task_tab_link_role_1_state_0 *newTab = new dialog_main_task_tab_link_role_1_state_0(task);
        QTabWidget *q = new QTabWidget;
        dialog_main_peoplelist_task *newtabuser = new dialog_main_peoplelist_task(task);
        q ->addTab(newTab, "task info");
        q ->addTab(newtabuser, "users info");
        Dialog_Main_Task_Tab ->addTab(q, QString("%1").arg(task));
        Dialog_Main_Task_Tab ->setCurrentWidget(q);
        connect(newTab ->Dialog_Main_Task_Tab_Cancel_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Main_Task_Remove_Tab()));
        connect(newTab ->Dialog_Main_Task_Tab_Quit_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Main_Task_Remove_Tab_No_info()));
    }

    if(role == 1 && state >= 1){
        dialog_main_task_tab_link_role_1_state_1 *newTab = new dialog_main_task_tab_link_role_1_state_1(task);
        Dialog_Main_Task_Tab ->addTab(newTab, QString("%1").arg(task));
        Dialog_Main_Task_Tab ->setCurrentWidget(newTab);
    }

    if(role >= 2 && role <= 3 && state >= 2 && state <= 3){
        dialog_main_task_tab_link_role_2_state_2 *newTab = new dialog_main_task_tab_link_role_2_state_2(task);
        Dialog_Main_Task_Tab ->addTab(newTab, QString("%1").arg(task));
        Dialog_Main_Task_Tab ->setCurrentWidget(newTab);
    }

    if(role >= 2 && role <= 4 && state >= 4){
        dialog_main_task_tab_link_state_4 *newTab = new dialog_main_task_tab_link_state_4(task, role);
        Dialog_Main_Task_Tab ->addTab(newTab, QString("%1").arg(task));
        Dialog_Main_Task_Tab ->setCurrentWidget(newTab);
    }
}
