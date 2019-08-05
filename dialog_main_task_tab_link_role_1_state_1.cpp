#include "dialog_main_task_tab_link_role_1_state_1.h"

dialog_main_task_tab_link_role_1_state_1::dialog_main_task_tab_link_role_1_state_1(QWidget *parent) : QWidget(parent)
{
    R1S1_Whole_Layout = new QVBoxLayout(this);
    R1S1_Whole_Tab = new QTabWidget;
    R1S1_T0 = new dialog_main_task_tab_link_role_1_state_1_tab_0;

    R1S1_Whole_Layout ->addWidget(R1S1_Whole_Tab);
    R1S1_Whole_Tab ->addTab(R1S1_T0, "Task Info");
}

dialog_main_task_tab_link_role_1_state_1::~dialog_main_task_tab_link_role_1_state_1()
{

}

dialog_main_task_tab_link_role_1_state_1::dialog_main_task_tab_link_role_1_state_1(int id)
{
    qDebug() << id;
    R1S1_Whole_Layout = new QVBoxLayout(this);
    R1S1_Whole_Tab = new QTabWidget;

    //任务基本信息

    R1S1_T0 = new dialog_main_task_tab_link_role_1_state_1_tab_0(id);

    //负责人报名页面

    R1S1_T1 = new dialog_main_task_tab_link_role_1_state_1_tab_1(id);

    //审核人报名页面

    R1S1_T2 = new dialog_main_task_tab_link_role_1_state_1_tab_2(id);

    //结项页面

    R1S1_T3 = new dialog_main_task_tab_endtask(id, 1);

    //任务相关人员列表

    R1S1_T4 = new dialog_main_peoplelist_task(id);
    R1S1_Whole_Tab ->addTab(R1S1_T0, "Task Info");
    R1S1_Whole_Tab ->addTab(R1S1_T4, "users Info");
    R1S1_Whole_Tab ->addTab(R1S1_T1, "Pre_Headers Info");
    R1S1_Whole_Tab ->addTab(R1S1_T2, "Pre_Reviewers Info");
    R1S1_Whole_Tab ->addTab(R1S1_T3, "End");
    R1S1_Whole_Layout ->addWidget(R1S1_Whole_Tab);

    connect(R1S1_Whole_Tab, SIGNAL(tabBarClicked(int)), R1S1_T2, SLOT(Fresh(int)));
}
