/* 文件名 dialog_main_task_tab_link_role_2_state_2_tab_1.h
 * 用途  定义 dialog_main_task_tab_link_role_2_state_2_tab_1 类： 负责人查看已发布的任务译者报名信息并确认
 * 继承自 dialog_main_Peoplelist
*/

#ifndef DIALOG_MAIN_TASK_TAB_LINK_ROLE_2_STATE_2_TAB_1_H
#define DIALOG_MAIN_TASK_TAB_LINK_ROLE_2_STATE_2_TAB_1_H

#include <QWidget>
#include "project.h"
#include "dialog_main_peoplelist.h"
#include "dialog_main_userinfo_onlyread.h"
#include "message.h"

class dialog_main_task_tab_link_role_2_state_2_tab_1 : public dialog_main_Peoplelist
{
    Q_OBJECT
public:
    explicit dialog_main_task_tab_link_role_2_state_2_tab_1(QWidget *parent = nullptr);
    ~dialog_main_task_tab_link_role_2_state_2_tab_1();
    dialog_main_task_tab_link_role_2_state_2_tab_1(int task0);
signals:

public slots:

    /* 函数名 ConfirmTranslator.h
     * 用途  确认译者
    */
    void ConfirmTranslator();

    /* 函数名 ConfirmEnd.h
     * 用途  确认所有译者
    */
    void ConfirmEnd();

    /* 函数名 Fresh.h
     * 用途  切换到译者页面， 按钮权限更新
    */
    void Fresh(int index);

    /* 函数名 Btn_Fresh.h
     * 用途  切换选中译者，按钮权限更新， 防止野指针/空指针
    */
    void Btn_Fresh(int index);


    /* 函数名 Info_Fresh.h
     * 用途  刷新
    */
    void Info_Fresh();

private:
    QPushButton *Userall;
};

#endif // DIALOG_MAIN_TASK_TAB_LINK_ROLE_2_STATE_2_TAB_1_H
