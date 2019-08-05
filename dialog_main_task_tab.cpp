#include "dialog_main_task_tab.h"

dialog_main_task_tab::dialog_main_task_tab(QWidget *parent) : QWidget(parent)
{
    Dialog_Main_Task_Lan0_label = new QLabel(tr("FROM"));
    Dialog_Main_Task_Lan1_label = new QLabel(tr("TO"));
    Dialog_Main_Task_IntH_label = new QLabel(tr("Header Integrals not less than"));
    Dialog_Main_Task_IntR_label = new QLabel(tr("Reviewer Integrals not less than"));
    Dialog_Main_Task_Reward_label = new QLabel(tr("Rewards"));

    Dialog_Main_Task_Tab_Apply_Btn = new QPushButton(tr("Apply"));
    Dialog_Main_Task_Tab_OK_Btn = new QPushButton(tr("Publish"));
    Dialog_Main_Task_Tab_Cancel_Btn = new QPushButton(tr("Cancel"));
    Dialog_Main_Task_Tab_Quit_Btn = new QPushButton;
    Dialog_Main_Task_Tab_Apply_Btn ->setEnabled(0);
    Dialog_Main_Task_Tab_OK_Btn ->setEnabled(0);
    Dialog_Main_Task_Tab_Btn_Layout = new QHBoxLayout;
    Dialog_Main_Task_Tab_Btn_Layout ->addWidget(Dialog_Main_Task_Tab_Apply_Btn);
    Dialog_Main_Task_Tab_Btn_Layout ->addWidget(Dialog_Main_Task_Tab_OK_Btn);
    Dialog_Main_Task_Tab_Btn_Layout ->addWidget(Dialog_Main_Task_Tab_Cancel_Btn);

    Dialog_Main_TaskID_Label = new QLabel(tr("ID"));
    Dialog_Main_Taskinfo_Label = new QLabel(tr("Task introductions"));
    Dialog_Main_Taskinfo_TextEdit = new QTextEdit;
    Dialog_Main_Taskmain_Label = new QLabel(tr("Task Main"));
    Dialog_Main_Taskmain_TextEdit = new QTextEdit;
    Dialog_Main_Taskmain_TextEdit ->setEnabled(false);
    Dialog_Main_Task_Tab_Info_Layout = new QVBoxLayout;
    Dialog_Main_Task_Tab_Info_Layout ->addWidget(Dialog_Main_TaskID_Label);
    Dialog_Main_Task_Tab_Info_Layout ->addWidget(Dialog_Main_Taskinfo_Label);
    Dialog_Main_Task_Tab_Info_Layout ->addWidget(Dialog_Main_Taskinfo_TextEdit);
    Dialog_Main_Task_Tab_Info_Layout ->addWidget(Dialog_Main_Taskmain_Label);
    Dialog_Main_Task_Tab_Info_Layout ->addWidget(Dialog_Main_Taskmain_TextEdit);

    Dialog_Main_DDL_Label  = new QLabel(tr("Final DDL"));
    Dialog_Main_DDL_Header_Label = new QLabel(tr("Header/Reviewer recruit DDL"));
    Dialog_Main_DDL_Reviewer_Label = new QLabel(tr("Translator recruit DDL"));

    Dialog_Main_DDL_Layout = new QGridLayout;
    Dialog_Main_DDL_Layout ->addWidget(Dialog_Main_DDL_Label, 0, 0);
    Dialog_Main_DDL_Layout ->addWidget(Dialog_Main_DDL_Header_Label, 1, 0);
    Dialog_Main_DDL_Layout ->addWidget(Dialog_Main_DDL_Reviewer_Label, 2, 0);   
}

dialog_main_task_tab::~dialog_main_task_tab()
{

}
