/* 文件名 dialog_main_task_tab_link_role_0.h
 * 用途  定义 dialog_main_task_tab_link_role_0 类： 无关用户查看任务
*/

#ifndef DIALOG_MAIN_TASK_TAB_LINK_ROLE_0_H
#define DIALOG_MAIN_TASK_TAB_LINK_ROLE_0_H

#include <QWidget>
#include "project.h"
#include "dialog_main_task_tab_link_role_1_state_1_tab_0.h"
#include "message.h"

/* 类名 dialog_main_task_tab_link_role_0
 * 用途  ： 无关用户查看任务
*/

class dialog_main_task_tab_link_role_0 : public QWidget
{
    Q_OBJECT
public:
    explicit dialog_main_task_tab_link_role_0(QWidget *parent = nullptr);
    dialog_main_task_tab_link_role_0(int id, int state);
    ~dialog_main_task_tab_link_role_0();

    //任务基本信息

    dialog_main_task_tab_link_role_1_state_1_tab_0 *R0;


    QVBoxLayout *R0_Layout;

    QPushButton *R0HBtn;
    QPushButton *R0TBtn;
    QPushButton *R0RBtn;

    QHBoxLayout *R0_Btn_Layout;

    int R0Id;
    int R0State;
signals:

public slots:

    /* 函数名 BeHeader / BeReviewer / BeTranslator
     * 用途  ： 报名负责人 / 审核人 / 译者
    */

    void BeHeader();
    void BeReviewer();
    void BeTranslator();
};

#endif // DIALOG_MAIN_TASK_TAB_LINK_ROLE_0_H
