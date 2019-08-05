/* 文件名 dialog_main_peoplelist_task.h
 * 用途  定义 dialog_main_peoplelist_task 类： 任务相关人员列表， 用于人员查看
 * 继承自人员列表dialog_main_peoplelist
*/

#ifndef DIALOG_MAIN_PEOPLELIST_TASK_H
#define DIALOG_MAIN_PEOPLELIST_TASK_H

#include <QWidget>
#include "project.h"
#include "dialog_main_peoplelist.h"
#include "dialog_main_userinfo_onlyread.h"


/* 类名 dialog_main_peoplelist_task
 * 用途  ： 任务相关人员列表
*/
class dialog_main_peoplelist_task : public dialog_main_Peoplelist
{
    Q_OBJECT
public:

    //构造

    explicit dialog_main_peoplelist_task(QWidget *parent = nullptr);

    //析构

    ~dialog_main_peoplelist_task();

    //传入任务编号的构造函数

    dialog_main_peoplelist_task(int id);

signals:

public slots:
};

#endif // DIALOG_MAIN_PEOPLELIST_TASK_H
