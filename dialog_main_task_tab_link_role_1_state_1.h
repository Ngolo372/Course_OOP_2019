/* 文件名 dialog_main_task_tab_link_role_1_state_1.h
 * 用途  定义 dialog_main_task_tab_link_role_1_state_1 类： 发布人查看已发布的任务
*/

#ifndef DIALOG_MAIN_TASK_TAB_LINK_ROLE_1_STATE_1_H
#define DIALOG_MAIN_TASK_TAB_LINK_ROLE_1_STATE_1_H

#include <QWidget>
#include "project.h"
#include "dialog_main_task_tab_link_role_1_state_1_tab_0.h"
#include "dialog_main_task_tab_link_role_1_state_1_tab_1.h"
#include "dialog_main_task_tab_link_role_1_state_1_tab_2.h"
#include "dialog_main_task_tab_endtask.h"
#include "dialog_main_peoplelist_task.h"


/* 类名 dialog_main_task_tab_link_role_1_state_1 类：
 * 用途： 发布人查看已发布的任务
*/

class dialog_main_task_tab_link_role_1_state_1 : public QWidget
{
    Q_OBJECT
public:
    explicit dialog_main_task_tab_link_role_1_state_1(QWidget *parent = nullptr);
    ~dialog_main_task_tab_link_role_1_state_1();
    dialog_main_task_tab_link_role_1_state_1(int id);

    QVBoxLayout *R1S1_Whole_Layout;
    QTabWidget *R1S1_Whole_Tab;
    QWidget *R1S1_T0;
    QWidget *R1S1_T1;
    QWidget *R1S1_T2;
    QWidget *R1S1_T3;
    QWidget *R1S1_T4;

signals:

public slots:
};

#endif // DIALOG_MAIN_TASK_TAB_LINK_ROLE_1_STATE_1_H
