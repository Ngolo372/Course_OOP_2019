/* 文件名 dialog_main_task_tab_link_state_4.h
 * 用途  定义 dialog_main_task_tab_link_state_4 类： 进行中的任务查看
*/

#ifndef DIALOG_MAIN_TASK_TAB_LINK_STATE_4_H
#define DIALOG_MAIN_TASK_TAB_LINK_STATE_4_H

#include <QWidget>
#include "project.h"
#include "task.h"
#include "user.h"
#include "dialog_main_peoplelist_trans.h"
#include "dialog_main_task_tab_endtask.h"
#include "dialog_main_task_tab_link_role_1_state_1_tab_0.h"
#include "dialog_main_peoplelist_task.h"

/* 类名 dialog_main_task_tab_link_state_4 类： 进行中的任务查看
*/

class dialog_main_task_tab_link_state_4 : public QWidget
{
    Q_OBJECT
public:
    explicit dialog_main_task_tab_link_state_4(QWidget *parent = nullptr);
    ~dialog_main_task_tab_link_state_4();
    dialog_main_task_tab_link_state_4(int id, int role);

    QVBoxLayout *S4_Whole_Layout;
    QTabWidget *S4_Whole_Tab;
    QWidget *S4T0;
    dialog_main_peoplelist_trans *S4T1;
    dialog_main_task_tab_endtask *S4T2;
    QWidget *S4T3;

signals:

public slots:
};

#endif // DIALOG_MAIN_TASK_TAB_LINK_STATE_4_H
