#include "dialog_main_task_tab_link_role_2_state_2.h"
#include "dialog_main_peoplelist_task.h"

dialog_main_task_tab_link_role_2_state_2::dialog_main_task_tab_link_role_2_state_2(QWidget *parent) : QWidget(parent)
{

}

dialog_main_task_tab_link_role_2_state_2::~dialog_main_task_tab_link_role_2_state_2()
{

}

dialog_main_task_tab_link_role_2_state_2::dialog_main_task_tab_link_role_2_state_2(int id)
{
    qDebug() << id;
    R2S2_Whole_Layout = new QVBoxLayout(this);
    R2S2_Whole_Tab = new QTabWidget;

    //任务基本信息

    R2S2_T0 = new dialog_main_task_tab_link_role_1_state_1_tab_0(id);

    //译者报名列表

    R2S2_T1 = new dialog_main_task_tab_link_role_2_state_2_tab_1(id);

    //任务相关人员列表

    R2S2_T2 = new dialog_main_peoplelist_task(id);

    R2S2_Whole_Tab ->addTab(R2S2_T0, "Task Info");
    R2S2_Whole_Tab ->addTab(R2S2_T2, "users info");
    R2S2_Whole_Tab ->addTab(R2S2_T1, "Pre_Translators Info");
    R2S2_Whole_Layout ->addWidget(R2S2_Whole_Tab);

    connect(R2S2_Whole_Tab, SIGNAL(tabBarClicked(int)), R2S2_T1, SLOT(Fresh(int)));
}
