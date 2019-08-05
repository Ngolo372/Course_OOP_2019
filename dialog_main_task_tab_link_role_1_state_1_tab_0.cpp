#include "dialog_main_task_tab_link_role_1_state_1_tab_0.h"

extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern User OnlineUser;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;

dialog_main_task_tab_link_role_1_state_1_tab_0::dialog_main_task_tab_link_role_1_state_1_tab_0(QWidget *parent) : dialog_main_task_tab_link_role_1_state_0(parent)
{

}

dialog_main_task_tab_link_role_1_state_1_tab_0::dialog_main_task_tab_link_role_1_state_1_tab_0(int id, QWidget *parent): dialog_main_task_tab_link_role_1_state_0(parent)
{
    taskID = id;
    issaved = 1;

    Dialog_Main_DDL_Header_Edit ->setEnabled(0);
    Dialog_Main_DDL_Reviewer_Edit ->setEnabled(0);
    Dialog_Main_DDL_Edit ->setEnabled(0);
    Lan_Error ->setText(tr("OK"));
    Dialog_Main_TaskID_Label ->setText(tr("ID %1").arg(taskID));
    Dialog_Main_Task_Lan0_Combox ->setCurrentIndex(Taskinfo_Hash.find(taskID).value().GetLanF());
    Dialog_Main_Task_Lan1_Combox ->setCurrentIndex(Taskinfo_Hash.find(taskID).value().GetLanT());
    Dialog_Main_Taskinfo_TextEdit ->setText(Taskinfo_Hash.find(taskID).value().Get_Intro_S());
    Dialog_Main_Taskmain_TextEdit ->setText(Taskinfo_Hash.find(taskID).value().Get_MainTotal_S());
    Dialog_Main_Task_HI_Num ->setValue(Taskinfo_Hash.find(taskID).value().GetIntH());
    Dialog_Main_Task_RI_Num ->setValue(Taskinfo_Hash.find(taskID).value().GetIntR());
    Dialog_Main_Task_Reward_Num ->setValue(Taskinfo_Hash.find(taskID).value().GetReward_Publish());

    Dialog_Main_DDL_Layout ->replaceWidget(Dialog_Main_DDL_Edit, new QLabel(Taskinfo_Hash.find(taskID).value().GetDDL_Final().toString()));
    Dialog_Main_DDL_Layout ->removeWidget(Dialog_Main_DDL_Edit);
    delete Dialog_Main_DDL_Edit;
    Dialog_Main_DDL_Layout ->replaceWidget(Dialog_Main_DDL_Header_Edit, new QLabel(Taskinfo_Hash.find(taskID).value().GetDDL_Header().toString()));
    Dialog_Main_DDL_Layout ->removeWidget(Dialog_Main_DDL_Header_Edit);
    delete Dialog_Main_DDL_Header_Edit;
    Dialog_Main_DDL_Layout ->replaceWidget(Dialog_Main_DDL_Reviewer_Edit, new QLabel(Taskinfo_Hash.find(taskID).value().GetDDL_Reviewer().toString()));
    Dialog_Main_DDL_Layout ->removeWidget(Dialog_Main_DDL_Reviewer_Edit);
    delete Dialog_Main_DDL_Reviewer_Edit;

    //只读， 不可修改

    Dialog_Main_Task_Lan0_Combox ->setEnabled(0);
    Dialog_Main_Task_Lan1_Combox ->setEnabled(0);
    Dialog_Main_Taskinfo_TextEdit ->setReadOnly(1);
    Dialog_Main_Taskmain_TextEdit ->setReadOnly(1);
    Dialog_Main_Task_HI_Num ->setEnabled(0);
    Dialog_Main_Task_RI_Num ->setEnabled(0);
    Dialog_Main_Task_Reward_Num ->setEnabled(0);


    Dialog_Main_Task_Tab_OK_Btn ->setEnabled(0);
    Dialog_Main_Task_Tab_Apply_Btn ->setEnabled(0);
    Dialog_Main_Task_Tab_Cancel_Btn ->setEnabled(0);
}

dialog_main_task_tab_link_role_1_state_1_tab_0::~dialog_main_task_tab_link_role_1_state_1_tab_0()
{

}
