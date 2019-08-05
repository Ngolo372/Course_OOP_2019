#include "dialog_main_task_tab_link_state_4.h"
#include "dialog_main_task_tab_link_role_1_state_1_tab_0.h"
#include "dialog_main_peoplelist_task.h"

dialog_main_task_tab_link_state_4::dialog_main_task_tab_link_state_4(QWidget *parent) : QWidget(parent)
{

}

dialog_main_task_tab_link_state_4::~dialog_main_task_tab_link_state_4()
{

}

dialog_main_task_tab_link_state_4::dialog_main_task_tab_link_state_4(int id, int role)
{
    qDebug() << id;
    S4_Whole_Layout = new QVBoxLayout(this);
    S4_Whole_Tab = new QTabWidget;

    //任务基本信息

    S4T0 = new dialog_main_task_tab_link_role_1_state_1_tab_0(id);

    //译者列表

    S4T1 = new dialog_main_peoplelist_trans(id, role);

    //结项界面

    S4T2 = new dialog_main_task_tab_endtask(id, role);

    //人员列表

    S4T3 = new dialog_main_peoplelist_task(id);



    S4_Whole_Tab ->addTab(S4T0, "Task Info");
    S4_Whole_Tab ->addTab(S4T3, "users info");
    S4_Whole_Tab ->addTab(S4T1, "Pre_Translators Info");
    S4_Whole_Tab ->addTab(S4T2, "End");
    S4_Whole_Layout ->addWidget(S4_Whole_Tab);
}
