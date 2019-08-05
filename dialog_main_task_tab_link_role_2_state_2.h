/* 文件名 dialog_main_task_tab_link_role_2_state_2.h
 * 用途  定义 dialog_main_task_tab_link_role_2_state_2 类： 负责人查看正在招募译者任务
*/

#ifndef DIALOG_MAIN_TASK_TAB_LINK_ROLE_2_STATE_2_H
#define DIALOG_MAIN_TASK_TAB_LINK_ROLE_2_STATE_2_H

#include <QWidget>
#include "project.h"
#include "task.h"
#include "user.h"
#include "dialog_main_task_tab_link_role_1_state_1_tab_0.h"
#include "dialog_main_task_tab_link_role_2_state_2_tab_1.h"

class dialog_main_task_tab_link_role_2_state_2 : public QWidget
{
    Q_OBJECT
public:
    explicit dialog_main_task_tab_link_role_2_state_2(QWidget *parent = nullptr);
    ~dialog_main_task_tab_link_role_2_state_2();
    dialog_main_task_tab_link_role_2_state_2(int id);

    QVBoxLayout *R2S2_Whole_Layout;
    QTabWidget *R2S2_Whole_Tab;
    QWidget *R2S2_T0;
    QWidget *R2S2_T1;
    QWidget *R2S2_T2;
signals:

public slots:
};

#endif // DIALOG_MAIN_TASK_TAB_LINK_ROLE_2_STATE_2_H
