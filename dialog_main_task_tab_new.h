/* 文件名 dialog_main_task_tab_new.h
 * 用途  定义dialog_main_task_tab_new类： 新建任务基本信息页
 * 继承自 dialog_main_task_tab 类
*/

#ifndef DIALOG_MAIN_TASK_TAB_NEW_H
#define DIALOG_MAIN_TASK_TAB_NEW_H

#include <QWidget>
#include "dialog_main_task_tab.h"
#include "project.h"
#include "task.h"
#include "task.h"
#include "project.h"
#include "message.h"

/* 类名 dialog_main_task_tab_new类： 新建任务基本信息页
 * 继承自 dialog_main_task_tab 类
*/

class dialog_main_task_tab_new : public dialog_main_task_tab
{
    Q_OBJECT
public:
    explicit dialog_main_task_tab_new(QWidget *parent = nullptr);
    ~dialog_main_task_tab_new();

    //成员：任务编号

    task NewTask;


    /* 函数名 Dialog_Main_Task_Full
     * 用途  完成布局
    */

     void Dialog_Main_Task_Full();




     /* 函数名 task_update
      * 用途  刷新
     */

     void task_update(int id);
signals:

public slots:

     /* 函数名 Task_Publish_Enable
      * 用途  保存新任务（state = 0）
     */

     void Task_Publish_Enable();


     /* 函数名 Task_Publish_Complete
      * 用途  发布新任务（state = 1）
     */
     void Task_Publish_Complete();


     /* 函数名 Task_Publish_Btns
      * 用途  按钮权限
     */

     void Task_Publish_Btns();


     /* 函数名 Legal_Int / Legal_Time
      * 用途  保证积分和时间输入合法
     */
     bool Legal_Lan();
     void Legal_Int();
     void Legal_Time();

protected:
     QComboBox *Dialog_Main_Task_Lan0_Combox;
     QComboBox *Dialog_Main_Task_Lan1_Combox;
     QLabel *Lan_Error;

     QGridLayout *Dialog_Main_Task_Lan_Layout;
     QSpinBox *Dialog_Main_Task_HI_Num;
     QSpinBox *Dialog_Main_Task_RI_Num;
     QDoubleSpinBox *Dialog_Main_Task_Reward_Num;
     QGridLayout *Dialog_Main_Task_TR_Layout;

     QDateTimeEdit *Dialog_Main_DDL_Header_Edit;
     QDateTimeEdit *Dialog_Main_DDL_Reviewer_Edit;
     QDateTimeEdit *Dialog_Main_DDL_Edit;

     QVBoxLayout *Dialog_Main_Task_Tab_New_Layout;

     QString Taskinfo;
     QString TaskMain;
     QString DDL[3];
     QString Language[2];

     bool issaved;
     int taskID;
};

#endif // DIALOG_MAIN_TASK_TAB_NEW_H
