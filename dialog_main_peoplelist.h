/* 文件名 dialog_main_peoplelist.h
 * 用途  定义 dialog_main_peoplelist 类： 人员列表
 * 作为任务相关人员列表、 报名人员列表、 译者列表灯的基类
*/

#ifndef DIALOG_MAIN_PEOPLELIST_H
#define DIALOG_MAIN_PEOPLELIST_H

#include <QWidget>
#include "project.h"
#include "task.h"

/* 类名 dialog_main_peoplelist
 * 用途  ： 人员列表
*/
class dialog_main_Peoplelist : public QWidget
{
    Q_OBJECT
public:

    //构造

    explicit dialog_main_Peoplelist(QWidget *parent = nullptr);

    //传入任务编号的构造函数

    dialog_main_Peoplelist(int Task0);

    //析构
    ~dialog_main_Peoplelist();


    //控件list + stack

    QListWidget *UserList;
    QStackedWidget *UserStack;
    QPushButton *UserBtn;
    QVBoxLayout *RLayout;
    QHBoxLayout *Layout;


    //任务编号

    int MainTask;

signals:

public slots:

};

#endif // DIALOG_MAIN_PEOPLELIST_H
