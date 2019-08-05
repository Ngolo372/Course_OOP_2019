#include "dialog_main_message.h"

//容器

extern QHash <QString, QQueue<message>>Message_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_Hash_iter;
extern QHash <QString, QQueue<message>>Message_New_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_New_Hash_iter;
extern QQueue<message> Message_Queue[1000];
extern QQueue<message> Message_New_Queue[1000];
extern QHash <QString, QQueue<message>>Message_NewState_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_NewState_Hash_iter;
//extern QQueue<message> Message_Queue[1000];
//extern QQueue<message> Message_New_Queue[1000];
extern QQueue<message> Message_NewState_Queue[1000];
extern User OnlineUser;


//构造

Dialog_Main_Message::Dialog_Main_Message(QWidget *parent) : QWidget(parent)
{
    MessageTable = new QTableWidget(100, 4);
    QStringList ql;
    ql << "unreadstate"<< "Task ID"  << "floatid"<< "Information" ;
    MessageTable ->setHorizontalHeaderLabels(ql);

    //消息盒子刷新

    message_fresh();

    MessageTable ->horizontalHeader()->setStretchLastSection(1);
    MessageTable ->setEditTriggers(QAbstractItemView::NoEditTriggers);
    MessageTable ->setSelectionMode(QAbstractItemView::SingleSelection);
    MessageTable ->setSelectionBehavior(QAbstractItemView::SelectRows);
    Layout = new QVBoxLayout(this);
    Layout ->addWidget(MessageTable);

    //读取消息

    connect(MessageTable, SIGNAL(cellDoubleClicked(int,int)),this,SLOT(read_message(int,int)));
}


//析构

Dialog_Main_Message::~Dialog_Main_Message()
{

}


//消息盒子刷新

void Dialog_Main_Message::message_fresh()
{
    QQueue<message> Queue_Online = Message_Hash.find(OnlineUser.GetUsername()).value();

    int i = 0;
    while (!Queue_Online.isEmpty()) {

        //显示最近100条

        message mess_present = Queue_Online.dequeue();
        MessageTable ->setItem(i%100, 1, new QTableWidgetItem(QString("%1").arg(mess_present.taskID)));
        MessageTable ->setItem(i%100, 3, new QTableWidgetItem(mess_present.getmessage()));
        MessageTable ->setItem(i%100, 2, new QTableWidgetItem(QString("%1").arg(mess_present.floatid )));
        MessageTable ->setItem(i%100, 0, new QTableWidgetItem(mess_present.isnotread ? "unread" : ""));
        qDebug() << QString("%1").arg(mess_present.floatid );
        i++;
    }
}


//读取消息

void Dialog_Main_Message::read_message(int row ,int column)
{
    bool change_flag = 0;
    int change_taskid = MessageTable->item(row, 1)->text().toInt();
    int change_floatid = MessageTable->item(row, 2)->text().toInt();
    QString change_main = MessageTable->item(row, 3)->text();
    QMessageBox::information(this, "check success", change_main);


    //设为已读

    message change_message;
    change_message.taskID = change_taskid;
    change_message.floatid = change_floatid;
    change_message.isnotread = change_flag;
    Message_NewState_Hash.find(OnlineUser.GetUsername()).value().enqueue(change_message);

    QQueue <message>::iterator mess_iter = Message_Hash.find(OnlineUser.GetUsername()).value().begin();
    while(mess_iter != Message_Hash.find(OnlineUser.GetUsername()).value().end()) {
        if(mess_iter->floatid ==  change_floatid)mess_iter ->isnotread = 0;
        mess_iter ++;
    }

    //刷新

    message_fresh();
}
