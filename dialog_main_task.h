/* 文件名 dialog_main_task.h
 * 用途  定义 dialog_main_task 类： 任务表， 用于任务查看
*/

#ifndef DIALOG_MAIN_TASK_H
#define DIALOG_MAIN_TASK_H

#include <QWidget>
#include"project.h"
#include "project.h"
#include "dialog_main_task_tab_new.h"
#include "dialog_main_task_tab_link_role_1_state_0.h"
#include "dialog_main_task_tab_link_role_1_state_1.h"
#include "dialog_main_task_tab_link_role_0.h"
#include "dialog_main_task_tab_link_role_2_state_2.h"
#include "dialog_main_task_tab_link_state_4.h"
#include "dialog_main_peoplelist_task.h"
#include "role_change.h"


/* 类名 dialog_main_task
 * 用途  ： 任务列表
*/

class Dialog_Main_Task : public QWidget
{
    Q_OBJECT
public:

    //构造、析构

    explicit Dialog_Main_Task(QWidget *parent = nullptr);
    ~Dialog_Main_Task();


    /* 函数名 Dialog_Main_Task_All_Show
     * 用途  读取全部任务
    */
    void Dialog_Main_Task_All_Show();


    /* 函数名 Dialog_Main_Task_Self_Show
     * 用途  读取自己相关任务
    */
    void Dialog_Main_Task_Self_Show();


    /* 函数名 Dialog_Main_Task_Tabs_Show
     * 用途  读取指定编号任务（取决于角色和状态）
    */
    void Dialog_Main_Task_Tabs_Show(int task, int role, int state);
signals:

public slots:

    /* 函数名 Dialog_Main_Task_New_Tab
     * 用途  新建任务
    */

    void Dialog_Main_Task_New_Tab();


    /* 函数名 Dialog_Main_Task_Remove_Tab
     * 用途  关闭任务
    */

    void Dialog_Main_Task_Remove_Tab();


    /* 函数名 Dialog_Main_Task_Remove_Tab_No_info
     * 用途  关闭当前任务
    */

    void Dialog_Main_Task_Remove_Tab_No_info();


    /* 函数名 Dialog_Main_Task_Remove_Tab
     * 用途  关闭任务并跳转上一界面
    */

    void Dialog_Main_Task_Remove_Tab(int index);


    /* 函数名 Dialog_Main_Task_Fresh
     * 用途  刷新任务
    */
    void Dialog_Main_Task_Fresh(int index);


    /* 函数名 Dialog_Main_Task_Fresh
     * 用途  查看所有任务
    */
    void Dialog_Main_Task_All_Check(int index, int index_0);


    /* 函数名 Dialog_Main_Task_Fresh
     * 用途  查看与自己相关任务
    */
    void Dialog_Main_Task_Self_Check(int index, int index_0);

private:
    QLabel *Dialog_Main_Task_Label;   
    QTabWidget *Dialog_Main_Task_Tab;
    QTableWidget *Dialog_Main_Task_All_Table;
    QTableWidget *Dialog_Main_Task_Self_Table;
    QStringList Dialog_Main_Task_All_Table_Titles;
    QStringList Dialog_Main_Task_Self_Table_Titles;
    QPushButton *Dialog_Main_Task_Publish_Btn;
    QVBoxLayout *Dialog_Main_Task_Layout;
};

#endif // DIALOG_MAIN_TASK_H
