/* 文件名 dialog_main_message.h
 * 用途  定义 Dialog_Main_Message 类： 消息盒子入口
*/

#ifndef DIALOG_MAIN_MESSAGE_H
#define DIALOG_MAIN_MESSAGE_H

#include <QWidget>
#include "project.h"
#include "message.h"

/* 类名 Dialog_Main_Message
 * 用途  ： 消息盒子入口
*/

class Dialog_Main_Message : public QWidget
{
    Q_OBJECT
public:
    explicit Dialog_Main_Message(QWidget *parent = nullptr);
    ~Dialog_Main_Message();

signals:

public slots:

    /* 函数名 message_fresh
     * 用途  刷新消息盒子
    */

    void message_fresh();


    /* 函数名 read_message
     * 用途  读取消息
    */

    void read_message(int row, int column);


private:

    //消息列表

    QTableWidget *MessageTable;
    QVBoxLayout *Layout;

};

#endif // DIALOG_MAIN_MESSAGE_H
