/* 文件名 dialog_main_task_tab.h
 * 用途  定义 dialog_main_task_tab 类： 任务页
*/

#ifndef DIALOG_MAIN_TASK_TAB_H
#define DIALOG_MAIN_TASK_TAB_H

#include <QWidget>
#include "project.h"


/* 类名 dialog_main_task_tab
 * 用途  ： 任务页
*/

class dialog_main_task_tab : public QWidget
{
    Q_OBJECT
public:

    explicit dialog_main_task_tab(QWidget *parent = nullptr);
    ~dialog_main_task_tab();

    QLabel *Dialog_Main_Task_Lan0_label;
    QLabel *Dialog_Main_Task_Lan1_label;
    QLabel *Dialog_Main_Task_IntH_label;
    QLabel *Dialog_Main_Task_IntR_label;
    QLabel *Dialog_Main_Task_Reward_label;
    QPushButton *Dialog_Main_Task_Tab_Apply_Btn;
    QPushButton *Dialog_Main_Task_Tab_OK_Btn;
    QPushButton *Dialog_Main_Task_Tab_Cancel_Btn;
    QPushButton *Dialog_Main_Task_Tab_Quit_Btn;
    QHBoxLayout *Dialog_Main_Task_Tab_Btn_Layout;

    QLabel *Dialog_Main_TaskID_Label;
    QLabel *Dialog_Main_Taskinfo_Label;
    QTextEdit *Dialog_Main_Taskinfo_TextEdit;
    QLabel *Dialog_Main_Taskmain_Label;
    QTextEdit *Dialog_Main_Taskmain_TextEdit;
    QVBoxLayout *Dialog_Main_Task_Tab_Info_Layout;

    QLabel *Dialog_Main_DDL_Header_Label;
    QLabel *Dialog_Main_DDL_Reviewer_Label;
    QLabel *Dialog_Main_DDL_Label;
    QGridLayout *Dialog_Main_DDL_Layout;

    virtual void Dialog_Main_Task_Full() = 0;

signals:

public slots:

private:

};

#endif // DIALOG_MAIN_TASK_TAB_H
