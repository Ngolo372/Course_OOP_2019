/* 文件名 dialog_main_task_tab_link_role_1_state_1_tab_1.h
 * 用途  定义 dialog_main_task_tab_link_role_1_state_1_tab_1 类： 发布人查看已发布的任务负责人报名信息并确认
 * 继承自 dialog_main_Peoplelist
*/

#ifndef DIALOG_MAIN_TASK_TAB_LINK_ROLE_1_STATE_1_TAB_1_H
#define DIALOG_MAIN_TASK_TAB_LINK_ROLE_1_STATE_1_TAB_1_H

#include <QWidget>
#include "project.h"
#include "dialog_main_peoplelist.h"
#include "dialog_main_userinfo_onlyread.h"
#include "message.h"


class dialog_main_task_tab_link_role_1_state_1_tab_1 : public dialog_main_Peoplelist
{
    Q_OBJECT
public:
    explicit dialog_main_task_tab_link_role_1_state_1_tab_1(QWidget *parent = nullptr);
    dialog_main_task_tab_link_role_1_state_1_tab_1(int task0);
    ~dialog_main_task_tab_link_role_1_state_1_tab_1();

signals:

public slots:

    /* 函数名 ConfirmHeader.h
     * 用途  确认负责人
    */
    void ConfirmHeader();
};

#endif // DIALOG_MAIN_TASK_TAB_LINK_ROLE_STATE_1_TAB_1_H
