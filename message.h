/* 文件名 message.h
 * 用途  message 消息
*/

#ifndef MESSAGE_H
#define MESSAGE_H

#include "project.h"
#include "task.h"
#include "user.h"

class message
{
public:
    message();
    ~message();
    message(int taskid, QString receiver, int type);
    message(int taskid, QString receiver, QString sender, int type);
    message(int taskid, QString receiver, QString sender, QString aboutter, int type);
    message(int taskid, QString receiver, QString sender, QString aboutter, QString add, int type);
    message(int taskid, bool flag, QString main);
    QString getmessage();

    int taskID;
    QString ReceiveUser;
    QString SendUser;
    QString AboutUser;
    int floatid;
    QString messageadd;

    // 是否未读

    bool isnotread;
    void message_add(QString add);
private:

    QString messagemain;


    enum Messagetype{

        Create_New = 0,
        PreHeader_Report = 1,
        PreReviewer_Report = 2,
        PreTranslator_Report = 3,
        PreHeader_Fail = 4,
        PreReviewer_Fail = 5,
        PreTranslator_Fail = 6,


        Be_Publisher = 10,
        New_PreHeader = 11,
        New_PreReviewer = 12,
        PreHeader_Confirm = 13,
        Previewer_Confirm = 14,
        FinalTask_Pay = 15,

        Be_Header = 20,
        New_PreTranslator = 21,
        PreTranslator_Confirm = 22,
        Translator_Result_Header = 23,
        FeedBack_Header_Self = 24,
        FeedBack_Reviewer = 25,
        FinalTask_Up_Header = 26,
        FinalTask_GetPay = 27,
        FeedBack_Header_Pass_Self = 28,
        FeedBack_Reviewer_Pass = 29,


        Be_Reviewer = 30,
        Translator_Result_Reviewer = 31,
        FeedBack_Reviewer_Self = 32,
        FeedBack_Header = 33,
        FinalTask_Up_Others = 34,
        FeedBack_Reviewer_Pass_Self = 36,
        FeedBack_Header_Pass = 37,
        FinalTask_Up_Reviewer = 38,
        FianlTask_Up_Final = 39,

        Be_Translator = 40,
        Translator_Result_Self = 41,
        FeedBack_Header_Translator = 42,
        FeedBack_Reviewer_Translator = 43,
        FeedBack_Header_Translator_Pass = 45,
        FeedBack_Reviewer_Translator_Pass = 46,
        Translator_Result_Save = 47,

        Part_Task_Header = 50,
        Part_Task_Reviewer = 51,
        Part_Task_Translator = 52,
        FinalTask_Up_Reviewer_Pass = 53,
        FianlTask_Up_Final_Pass = 54,
        FinalTask_ReceivePay = 55,

        miss_DDL = 56,
        Translator_Deleted = 57,
        Translator_Deleted_Header = 58,
        Translator_Deleted_Reviewer = 59,
        Translator_New_Reviewer = 60


    }messagetype;
};

#endif // MESSAGE_H
