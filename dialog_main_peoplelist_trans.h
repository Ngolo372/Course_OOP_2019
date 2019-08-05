/* 文件名 dialog_main_peoplelist_trans.h
 * 用途  定义 dialog_main_peoplelist_trans 类： 任务译者列表， 用于译者与审核人、负责人的信息交换
 * 继承自人员列表dialog_main_peoplelist
*/

#ifndef DIALOG_MAIN_PEOPLELIST_TRANS_H
#define DIALOG_MAIN_PEOPLELIST_TRANS_H

#include <QWidget>
#include "project.h"
#include "dialog_main_task_exchange.h"
#include "user.h"
#include "task.h"
#include "dialog_main_peoplelist.h"
#include "message.h"


/* 类名 dialog_main_peoplelist_trans
 * 用途  ： 任务译者列表，
*/

class dialog_main_peoplelist_trans : public dialog_main_Peoplelist
{
    Q_OBJECT
public:

    //构造（带参）、析构

    explicit dialog_main_peoplelist_trans(QWidget *parent = nullptr);
    ~dialog_main_peoplelist_trans();
    dialog_main_peoplelist_trans(int task0, int role);

signals:

public slots:

    /* 函数名 deleteTranslator
     * 用途  删除译者
    */

    void deleteTranslator();

private:
    QPushButton *deleteBtn;
};

#endif // DIALOG_MAIN_PEOPLELIST_TRANS_H
