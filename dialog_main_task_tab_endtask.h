/* 文件名 dialog_main_task_endtask.h
 * 用途  定义 dialog_main_task_endtask 类： 任务结项信息交换， 用于任务最终整理翻译结果上传查看、审核信息、收付款与举报
*/

#ifndef DIALOG_MAIN_TASK_TAB_ENDTASK_H
#define DIALOG_MAIN_TASK_TAB_ENDTASK_H

#include <QWidget>
#include "user.h"
#include "task.h"
#include "project.h"
#include "message.h"

/* 类名 dialog_main_task_endtask
 * 用途  ： 任务结项信息交换， 用于任务最终整理翻译结果上传查看、审核信息、收付款与举报
*/

class dialog_main_task_tab_endtask : public QWidget
{
    Q_OBJECT
public:
    explicit dialog_main_task_tab_endtask(QWidget *parent = nullptr);
    ~dialog_main_task_tab_endtask();
    dialog_main_task_tab_endtask(int id, int role);

private:
    QLabel *mainlabel;
    QTextEdit *maintext;
    QPushButton *upBtn;
    QPushButton *moneyBtn;
    QPushButton *passBtn;

    QHBoxLayout *Btnlayout;
    QVBoxLayout *Layout;

    int Maintask;
signals:

public slots:

    /* 函数名 up
     * 用途  任务最终结果上传
    */

    void up();


    /* 函数名 pass
     * 用途  任务审核通过
    */
    void pass();


    /* 函数名 accord
     * 用途  超期无结果， 发布人举报
    */
    void accord();


    /* 函数名 givemoney
     * 用途  付款
    */
    void givemoney();


    /* 函数名 getmoney
     * 用途  收款，领取积分
    */
    void getmoney();
};

#endif // DIALOG_MAIN_TASK_TAB_ENDTASK_H
