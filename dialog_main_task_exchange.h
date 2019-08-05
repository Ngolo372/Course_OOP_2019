/* 文件名 dialog_main_task_exchange.h
 * 用途  定义 dialog_main_task_exchange 类： 任务信息交换， 用于任务分配、翻译信息、反馈信息的上传与查询
*/

#ifndef DIALOG_MAIN_TASK_EXCHANGE_H
#define DIALOG_MAIN_TASK_EXCHANGE_H

#include <QWidget>
#include "project.h"
#include "user.h"
#include "task.h"
#include "message.h"


/* 类名 dialog_main_task_exchange
 * 用途  ： 任务信息交换， 用于任务分配、翻译信息、反馈信息的上传与查询
*/

class dialog_main_task_exchange : public QWidget
{
    Q_OBJECT
public:

    //构造、析构、带参构造

    explicit dialog_main_task_exchange(QWidget *parent = nullptr);
    ~dialog_main_task_exchange();
    dialog_main_task_exchange(int task0, int translator0, int role);


    //参数：角色、状态、任务编号、本部分译者

    int Myrole;
    int MainTask;
    int serial;
    QString MainTranslator;

    QLabel *task_exchange_main_label;
    QLabel *task_exchange_translated_label;
    QLabel *task_exchange_translated_pre_label;
    QLabel *task_exchange_feedback_label;
    QLabel *task_exchange_feedback2_label;

    QTextEdit *task_exchange_main_textedit;
    QTextEdit *task_exchange_translated_textedit;
    QTextEdit *task_exchange_translated_pre_textedit;
    QTextEdit *task_exchange_feedback_textedit;
    QTextEdit *task_exchange_feedback2_textedit;

    QGridLayout *mainLayout;

    QPushButton *PartBtn;
    QPushButton *SaveBtn;
    QPushButton *UpBtn;
    QHBoxLayout *Btn1Layout;
    QPushButton *PassBtn;
    QPushButton *FailBtn;
    QHBoxLayout *Btn2Layout;
    QPushButton *Pass2Btn;
    QPushButton *Fail2Btn;
    QHBoxLayout *Btn3Layout;

    QVBoxLayout *task_exchange_layout;

signals:


public slots:

    /* 函数名 GiveTask
     * 用途  任务分配
    */

    void GiveTask();


    /* 函数名 SaveResult
     * 用途  任务翻译结果保存
    */

    void SaveResult();


    /* 函数名 UpResult
     * 用途  任务翻译结果提交
    */

    void UpResult();


    /* 函数名 FeedH（R）_Fail（Pass）
     * 用途  负责人（审核人）反馈信息——不通过（通过）
    */

    void FeedH_Fail();
    void FeedR_Fail();
    void FeedH_Pass();
    void FeedR_Pass();
};

#endif // DIALOG_MAIN_TASK_EXCHANGE_H
