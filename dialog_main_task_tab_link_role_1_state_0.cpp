#include "dialog_main_task_tab_link_role_1_state_0.h"

//容器

extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern User OnlineUser;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;

dialog_main_task_tab_link_role_1_state_0::dialog_main_task_tab_link_role_1_state_0(QWidget *parent) : dialog_main_task_tab_new(parent)
{

}

dialog_main_task_tab_link_role_1_state_0::~dialog_main_task_tab_link_role_1_state_0()
{

}

//返回任务编号
int dialog_main_task_tab_link_role_1_state_0::GetID()const
{
    return taskID;
}


//带参构造

dialog_main_task_tab_link_role_1_state_0::dialog_main_task_tab_link_role_1_state_0(int id)
{
    taskID = id;
    issaved = 1;
    Lan_Error ->setText(tr("OK"));
    Dialog_Main_TaskID_Label ->setText(tr("ID %1").arg(taskID));
    Dialog_Main_Task_Lan0_Combox ->setCurrentIndex(Taskinfo_Hash.find(taskID).value().GetLanF());
    Dialog_Main_Task_Lan1_Combox ->setCurrentIndex(Taskinfo_Hash.find(taskID).value().GetLanT());
    Dialog_Main_Taskinfo_TextEdit ->setText(Taskinfo_Hash.find(taskID).value().Get_Intro_S());
    Dialog_Main_Taskmain_TextEdit ->setText(Taskinfo_Hash.find(taskID).value().Get_MainTotal_S());
    Dialog_Main_Task_HI_Num ->setValue(Taskinfo_Hash.find(taskID).value().GetIntH());
    Dialog_Main_Task_RI_Num ->setValue(Taskinfo_Hash.find(taskID).value().GetIntR());
    Dialog_Main_Task_Reward_Num ->setValue(Taskinfo_Hash.find(taskID).value().GetReward_Publish());
    Dialog_Main_DDL_Header_Edit ->setDateTime(Taskinfo_Hash.find(taskID).value().GetDDL_Header());
    Dialog_Main_DDL_Reviewer_Edit ->setDateTime(Taskinfo_Hash.find(taskID).value().GetDDL_Reviewer());
    Dialog_Main_DDL_Edit ->setDateTime(Taskinfo_Hash.find(taskID).value().GetDDL_Final());
}


