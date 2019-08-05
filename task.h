//任务类

#ifndef TASK_H
#define TASK_H

#include "project.h"
#include "user.h"
#include "task_infomation.h"


class task
{
public:
    task();
    ~task();

    //新建&更新标志

    bool NewTaskFlag;
    bool UpdateTaskFlag[21];
    bool UpdateMainpart[5];
    bool UpdateResultSavepart[5];
    bool UpdateResultpart[5];
    bool UpdateHFpart[5];
    bool UpdateRFpart[5];
    bool updatefinal;
    bool EndTaskflag;

    //获取任务与用户之间的关系

    int LinkRelation(User u);
    QString LinkRelation_String(User u);
    int LinkRelation_c(User u)const;

    //属性设置与获取 Lan:language  IntH/R integral for header / reviewer

    void SetID(int id);
    void SetState(int s);
    void SetTaskFail();
    void SetLan(int f, int t);       
    void SetIntH(int intH);
    void SetIntR(int intR);
    void SetIntro(QString Intro);
    void SetMainTotal(QString MainTotal);
    void set_Main(int index, QString q);
    void set_Resultsave(int index, QString q);
    void set_Result(int index, QString q);
    void set_Feedback1(int index, QString q);
    void set_Feedback2(int index, QString q);
    void SetReward_Publish(double money);
    void SetDDL_0();
    void SetDDL_0(QDateTime ddl0);
    void SetDDL_Header(QDateTime DDLH);
    void SetDDL_Reviewer(QDateTime DDLR);
    void SetDDL_Final(QDateTime DDLF);
    void SetPublisher(QString P_User);
    void SetHeader(QString H_User);
    void SetTranslator(QString T_User1, QString T_User2 = "", QString T_User3 = "", QString T_User4 = "", QString T_User5 = "");
    void SetReviewer(QString R_User);
    void set_ResultTotal(QString q);
    void add_pre_Header(QString Pre_H_User);
    void add_pre_Translator(QString Pre_T_User);
    void add_pre_Reviewer(QString Pre_R_User);
    void add_Translator(QString T_User);
    void delete_Translator(int i);
    void add_Main(QString q);
    void add_Resultsave(QString q);
    void add_Result(QString q);
    void add_Feedback1(QString q);
    void add_Feedback2(QString q);

    int GetID()const;
    int GetState()const;
    QString GetState_String()const;
    int GetLanF()const;
    int GetLanT()const;
    int GetIntH()const;
    int GetIntR()const;
    QString Get_Intro_S()const;
    QString Get_Main_S(int index)const;
    QString Get_MainTotal_S()const;
    QString Get_Result_S(int index)const;
    QString GetResult_Tem(int index)const;
    QString GetFeedback(int index)const;
    QString GetFeedBack2(int index)const;
    QString Get_Result_Total_S()const;
    QString Get_Feedback_S()const;
    QString Get_Feedback2_S()const;

    double GetReward_Publish()const;
    QDateTime GetDDL_0()const;
    QDateTime GetDDL_Header()const;
    QDateTime GetDDL_Reviewer()const;
    QDateTime GetDDL_Final()const;
    QString GetPublisher()const;
    QString GetHeader()const;
    QString GetReviewer()const;
    int GetTranslatorNum()const;
    int GetPreHeaderNum()const;
    int GetPreReviewerNum()const;
    int GetPreTranslatorNum()const;
    QString GetTranslator(int index)const;
    QString GetPreHeader(int index)const;
    QString GetPreReviewer(int index)const;
    QString GetPreTranslator(int index)const;
    double Task_Reward_Publisher;
    double Task_Reward_Header;
    double Task_Reward_Translator;
    double Task_Reward_Reviewer;
    bool isTranslator(QString username);

private:
    int State;
    int Task_ID;
    int Lan_F, Lan_T;
    int Integral_Header;
    int Integral_Reviewer;
    Task_Infomation Task_Intro;
    Task_Infomation Task_Main_Total;
    Task_Infomation Task_Main[5];
    Task_Infomation Task_FeedBack_Total;
    Task_Infomation Task_FeedBack[5];
    Task_Infomation Task_FeedBack2_Total;
    Task_Infomation Task_FeedBack2[5];
    Task_Infomation Task_Result_Total;
    Task_Infomation Task_Result[5];
    Task_Infomation Task_Resule_Tem[5];

    User Task_Publisher0;
    User Task_Header0;
    User Task_Reviewer0;
    User Task_Translator0[5];


    //未确定用户（报名者）

    User Header1[10];
    User Reviewer1[10];
    User Translator1[10];

//    User_Publisher *Task_Publisher;
//    User_Header *Task_Header;
//    User_Translator *Task_Translator[10];
//    User_Reviewer *Task_Reviewer;

    //发布时间

    QDateTime Task_Published;

    //负责人、审核人报名ddl

    QDateTime Task_DDL_Header;

    //最终ddl

    QDateTime Task_DDL_Final;

    //译者d'd'l

    QDateTime Task_DDL_Reviewer;
};

#endif // TASK_H
