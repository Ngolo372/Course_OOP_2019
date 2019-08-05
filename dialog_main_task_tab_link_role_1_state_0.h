/* 文件名 dialog_main_task_tab_link_role_1_state_0.h
 * 用途  定义 dialog_main_task_tab_link_role_1_state_0 类： 发布人查看已经保存未发布的任务
 * 继承自 dialog_main_task_tab_new
*/

#ifndef DIALOG_MAIN_TASK_TAB_LINK_ROLE_1_STATE_0_H
#define DIALOG_MAIN_TASK_TAB_LINK_ROLE_1_STATE_0_H

#include <QWidget>
#include "dialog_main_task_tab_new.h"
#include "project.h"
#include "task.h"


/* 类名 dialog_main_task_tab_link_role_1_state_0 类：
 * 用途： 发布人查看已经保存未发布的任务
 * 继承自 dialog_main_task_tab_new
*/

class dialog_main_task_tab_link_role_1_state_0 : public dialog_main_task_tab_new
{
    Q_OBJECT
public:
    explicit dialog_main_task_tab_link_role_1_state_0(QWidget *parent = nullptr);
    dialog_main_task_tab_link_role_1_state_0(int id);
    ~dialog_main_task_tab_link_role_1_state_0();

    /* 函数名 GetID
     * 用途  获取任务编号
    */

    int GetID()const;

signals:

public slots:

private:

};

#endif // DIALOG_MAIN_TASK_TAB_LINK_ROLE_1_STATE_0_H
