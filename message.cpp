#include "message.h"

message::message()
{

}

message::~message()
{

}


message::message(int taskid, QString receiver, int type):taskID(taskid), ReceiveUser(receiver), messagetype(Messagetype(type))
{
    isnotread = 1;
    switch (messagetype) {
    case Create_New:
        messagemain = QString("Dear %1, You create task(ID: %2), but not publish it").arg(ReceiveUser).arg(taskID);
        break;
    case Be_Publisher:
        messagemain = QString("Dear %1, You publish task(ID: %2)").arg(ReceiveUser).arg(taskID);
        break;
    case Be_Header:
        messagemain = QString("Dear %1, You enter as header in task(ID: %2)").arg(ReceiveUser).arg(taskID);
        break;
    case Be_Reviewer:
        messagemain = QString("Dear %1, You  enter as reviewer in task(ID: %2)").arg(ReceiveUser).arg(taskID);
        break;
    case Be_Translator:
        messagemain = QString("Dear %1, You  enter as translator in task(ID: %2)").arg(ReceiveUser).arg(taskID);
        break;
    case Translator_Deleted:
        messagemain = QString("Dear %1, You are deleted as translator in task(ID: %2)").arg(ReceiveUser).arg(taskID);
        break;
    case PreHeader_Report:
        messagemain = QString("Dear %1, in task %2, you report to be header").arg(ReceiveUser).arg(taskID);
        break;
    case PreReviewer_Report:
        messagemain = QString("Dear %1, in task %2, you report to be reviewer").arg(ReceiveUser).arg(taskID);
        break;
    case PreTranslator_Report:
        messagemain = QString("Dear %1, in task %2, you report to be translator").arg(ReceiveUser).arg(taskID);
        break;
    case PreHeader_Fail:
        messagemain = QString("Dear %1, in task %2, your report to be header is refused").arg(ReceiveUser).arg(taskID);
        break;
    case PreReviewer_Fail:
        messagemain = QString("Dear %1, in task %2, your report to be reviewer is refused").arg(ReceiveUser).arg(taskID);
        break;
    case PreTranslator_Fail:
        messagemain = QString("Dear %1, in task %2, your report to be translator is refused").arg(ReceiveUser).arg(taskID);
        break;
    case FinalTask_Pay:
        messagemain = QString("Dear %1, in task %2, your have paid and get results").arg(ReceiveUser).arg(taskID);
        break;
    case FinalTask_GetPay:
        messagemain = QString("Dear %1, in task %2, your have get 100 task-integrals and rewards").arg(ReceiveUser).arg(taskID);
        break;
    case FinalTask_ReceivePay:
        messagemain = QString("Dear %1, in task %2,publisher paid").arg(ReceiveUser).arg(taskID);
        break;
    case Translator_Result_Self:
        messagemain = QString("Dear %1, in task %2, you uploaded your result").arg(ReceiveUser).arg(taskID);
        break;
    case FinalTask_Up_Header:
        messagemain = QString("Dear %1, in task %2, you uploaded your whole result").arg(ReceiveUser).arg(taskID);
        break;
    case FinalTask_Up_Reviewer:
        messagemain = QString("Dear %1, in task %2, you uploaded your advice of whole result").arg(ReceiveUser).arg(taskID);
        break;
    case FinalTask_Up_Reviewer_Pass:
        messagemain = QString("Dear %1, in task %2, you confirm the task end").arg(ReceiveUser).arg(taskID);
        break;
    case miss_DDL:
        messagemain = QString("Dear %1, in task %2, you missed the ddl, integral - 20").arg(ReceiveUser).arg(taskID);
        break;
    default:
        break;
    }

}

message::message(int taskid, QString receiver, QString sender, int type)
    :taskID(taskid), ReceiveUser(receiver), SendUser(sender), messagetype(Messagetype(type))
{
    isnotread = 1;
    switch (type) {

    case New_PreHeader:
        messagemain = QString("Dear %1, in task %2, %3 reported to be your header").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case New_PreReviewer:
        messagemain = QString("Dear %1, in task %2, %3 reported to be your reviewer").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case New_PreTranslator:
        messagemain = QString("Dear %1, in task %2, %3 reported to be your translator").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case PreHeader_Confirm:
        messagemain = QString("Dear %1, in task %2, you have confirmed header %3").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case Previewer_Confirm:
        messagemain = QString("Dear %1, in task %2, you have confirmed reviewer %3").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case PreTranslator_Confirm:
        messagemain = QString("Dear %1, in task %2, you have confirmed translator %3").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case Translator_Deleted_Header:
        messagemain = QString("Dear %1, in task %2, you have deleted translator %3").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case FeedBack_Header_Self:
        messagemain = QString("Dear %1, in task %2, your have give feedback as header to translator %3 to let him/her change").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case FeedBack_Reviewer_Self:
        messagemain = QString("Dear %1, in task %2, your have give feedback as reviewer to translator %3 to let him/her change").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case FeedBack_Header_Pass_Self:
        messagemain = QString("Dear %1, in task %2, your have passed translator %3 ").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case FeedBack_Reviewer_Pass_Self:
        messagemain = QString("Dear %1, in task %2, your have passed translator%3 ").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;


    case Translator_Result_Header:
        messagemain = QString("Dear %1, in task %2, translator %3 uploaded his/her result").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case Translator_Result_Reviewer:
        messagemain = QString("Dear %1, in task %2, translator %3 uploaded his/her result").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case FinalTask_Up_Others:
        messagemain = QString("Dear %1, in task %2, header %3 uploaded his/her result").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case FianlTask_Up_Final:
        messagemain = QString("Dear %1, in task %2, reviewer %3 uploaded his/her advice").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case FianlTask_Up_Final_Pass:
        messagemain = QString("Dear %1, in task %2, reviewer %3 end the task").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    default:
        break;
    }
}

message::message(int taskid, QString receiver, QString sender, QString aboutter, int type)
    :taskID(taskid), ReceiveUser(receiver), SendUser(sender), AboutUser(aboutter),  messagetype(Messagetype(type))
{
    isnotread = 1;
    switch (messagetype) {
    case Translator_Deleted_Reviewer:
        messagemain = QString("Dear %1, in task %2, %3 have deleted translator %4").arg(ReceiveUser).arg(taskID).arg(SendUser).arg(AboutUser);
        break;
    case Translator_New_Reviewer:
        messagemain = QString("Dear %1, in task %2, %3 have added translator %4").arg(ReceiveUser).arg(taskID).arg(SendUser).arg(AboutUser);
        break;
    case FeedBack_Header:
        messagemain = QString("Dear %1, in task %2, %3 have give feedback as header to translator %4 to let him/her change")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(AboutUser);
        break;
    case FeedBack_Reviewer:
        messagemain = QString("Dear %1, in task %2, %3 have give feedback as reviewer to translator %4 to let him/her change")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(AboutUser);
        break;

    case FeedBack_Header_Pass:
        messagemain = QString("Dear %1, in task %2, %3 have passed translator %4 as header").arg(ReceiveUser).arg(taskID).arg(SendUser).arg(AboutUser);
        break;
    case FeedBack_Reviewer_Pass:
        messagemain = QString("Dear %1, in task %2, %3 have passed translator%4 as reviewer").arg(ReceiveUser).arg(taskID).arg(SendUser).arg(AboutUser);
        break;
    case FeedBack_Header_Pass_Self:
        messagemain = QString("Dear %1, in task %2, you have passed translator %3 as header").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case FeedBack_Reviewer_Pass_Self:
        messagemain = QString("Dear %1, in task %2, you have passed translator %3 as reviewer").arg(ReceiveUser).arg(taskID).arg(SendUser);
        break;
    case FeedBack_Header_Translator_Pass:
        messagemain = QString("Dear %1, in task %2, %3 as header have passed your result")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd);
        break;
    case FeedBack_Reviewer_Translator_Pass:
        messagemain = QString("Dear %1, in task %2, %3 as reviewer have passed your result")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd);
        break;
    default:
        break;
    }
}

message::message(int taskid, QString receiver, QString sender, QString aboutter, QString add, int type)
  :taskID(taskid), ReceiveUser(receiver), SendUser(sender), AboutUser(aboutter), messageadd(add), messagetype(Messagetype(type))
{
    isnotread = 1;
    switch (type) {

    case Translator_Result_Self:
        messagemain = QString("Dear %1, in task %2, you uploaded your result %3").arg(ReceiveUser).arg(taskID).arg(messageadd);
        break;
    case Translator_Result_Save:
        messagemain = QString("Dear %1, in task %2, you saved your result %3").arg(ReceiveUser).arg(taskID).arg(messageadd);
        break;

    case FeedBack_Header_Self:
        messagemain = QString("Dear %1, in task %2, your have give feedback  %3 as header to translator %4 to let him/her change").arg(ReceiveUser).arg(taskID).arg(messageadd).arg(SendUser);
        break;
    case FeedBack_Reviewer_Self:
        messagemain = QString("Dear %1, in task %2, your have give feedback %3 as reviewer to translator %4 to let him/her change").arg(ReceiveUser).arg(taskID).arg(messageadd).arg(SendUser);
        break;


    case Translator_Result_Header:
        messagemain = QString("Dear %1, in task %2, translator %3 uploaded his/her result %4").arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd);
        break;
    case Translator_Result_Reviewer:
        messagemain = QString("Dear %1, in task %2, translator %3 uploaded his/her result %4").arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd);
        break;
    case FinalTask_Up_Others:
        messagemain = QString("Dear %1, in task %2, header %3 uploaded his/her result %4").arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd);
        break;

    case FeedBack_Header:
        messagemain = QString("Dear %1, in task %2, %3 have give feedback %4 as header to translator %5 to let him/her change")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd).arg(AboutUser);
        break;
    case FeedBack_Reviewer:
        messagemain = QString("Dear %1, in task %2, %3 have give feedback %4 as reviewer to translator %5 to let him/her change")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd).arg(AboutUser);
        break;

    case Part_Task_Header:
        messagemain = QString("Dear %1, in task %2, you have give task %3 as header to translator %4")
                .arg(ReceiveUser).arg(taskID).arg(messageadd).arg(AboutUser);
        break;
    case Part_Task_Reviewer:
        messagemain = QString("Dear %1, in task %2, %3 have give task %4 as header to translator %5")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd).arg(AboutUser);
        break;
    case Part_Task_Translator:
        messagemain = QString("Dear %1, in task %2, %3 have give task %4 as header to you")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd);
        break;

    case FeedBack_Header_Translator:
        messagemain = QString("Dear %1, in task %2, %3 have give feedback %4 as header to you, please modify")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd);
        break;
    case FeedBack_Reviewer_Translator:
        messagemain = QString("Dear %1, in task %2, %3 have give feedback %4 as reviewer to you, please modify")
                .arg(ReceiveUser).arg(taskID).arg(SendUser).arg(messageadd);
        break;

    default:
        break;
    }
}

message::message(int taskid, bool flag, QString main):taskID(taskid), isnotread(flag) , messagemain(main)
{

}

QString message::getmessage()
{
    return messagemain;
}

void message::message_add(QString add)
{
    messagemain += add;
}
