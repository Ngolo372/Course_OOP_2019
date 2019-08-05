#include "task.h"
#include "message.h"

//captain of User information, to get task-related users' information
extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;
extern QHash <QString, QQueue<message>>Message_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_Hash_iter;
extern QHash <QString, QQueue<message>>Message_New_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_New_Hash_iter;
extern QQueue<message> Message_Queue[1000];
extern QQueue<message> Message_New_Queue[1000];


//Constructor
task::task()
{
    //A new task's initial state: unpublished
    State = 0;

    //defualt settings: Don' t modify the database(data22.db)
    //NewTaskFlag = (create a new task)
    NewTaskFlag = 0;    
    for(int i = 0; i < 21; i++){
        UpdateTaskFlag[i] = 0;
    }
    for (int i = 0; i < 10; i ++) {
        Header1[i].SetUsername("");
    }
    for (int i = 0 ; i < 5 ; i++){
        UpdateMainpart[i] = 0;
    }
    for (int i = 0 ; i < 5 ; i++){
        UpdateResultSavepart[i] = 0;
    }
    for (int i = 0 ; i < 5 ; i++){
        UpdateResultpart[i] = 0;
    }
    for (int i = 0 ; i < 5 ; i++){
        UpdateHFpart[i] = 0;
    }
    for (int i = 0 ; i < 5 ; i++){
        UpdateRFpart[i] = 0;
    }
    updatefinal = 0;
    EndTaskflag = 0;
}

task::~task()
{

}

int task::GetID() const
{
    return Task_ID;
}

int task::GetState() const
{
    return State;
}

QString task::GetState_String() const
{
    switch (State) {
    case 0:
        return "Unpublished";
    case 1:
        return "Published, recruiting header and reviewer";
    case 2:
        return "Header confirmed, recruiting translators";
    case 3:
        return "Header and Reviewer confirmed, recruting translators";
    case 4:
        return "Processing: translating and sorting";
    case 5:
        return "Sorting completed, ready for reviewing";
    case 6:
        return "Review completed";
    case 7:
        return "Publisher paid, task ended";
    default:
        return "";
    }
}

void task::SetTaskFail()
{
    if(QDateTime::currentDateTime() > GetDDL_Final() && GetState() == 4){
        qDebug() << "hsb";
        qDebug() << Userinfo_Hash.find(GetHeader())->GetUsername() << Userinfo_Hash.find(GetHeader())->Get_User_Tasks_Intergral();
        Userinfo_Hash.find(GetHeader())->Add_User_Task_Integral( - 20);
        Userinfo_Hash.find(GetHeader())->Set_User_Intergral();
        qDebug() << Userinfo_Hash.find(GetHeader())->GetUsername() << Userinfo_Hash.find(GetHeader())->Get_User_Tasks_Intergral();
        Userinfo_Hash.find(GetHeader())->Changeinfoflag[14] = 1;
        Userinfo_Hash.find(GetHeader())->Changeinfoflag[15] = 1;
        message newmess1(Task_ID, GetHeader(), 56);
        newmess1.floatid = Message_Hash.find(GetHeader()).value().size() + Task_ID * 1000;
        Message_Hash.find(GetHeader()).value().enqueue(newmess1);
        Message_New_Hash.find(GetHeader()).value().enqueue(newmess1);
    }
    if(QDateTime::currentDateTime() > GetDDL_Final() && GetState() == 5){
         qDebug() << "rsb";
        Userinfo_Hash.find(GetReviewer())->Add_User_Task_Integral( - 20);
        Userinfo_Hash.find(GetHeader())->Set_User_Intergral();
        Userinfo_Hash.find(GetReviewer())->Changeinfoflag[14] = 1;
        Userinfo_Hash.find(GetReviewer())->Changeinfoflag[15] = 1;
        message newmess1(Task_ID, GetReviewer(), 56);
        newmess1.floatid = Message_Hash.find(GetReviewer()).value().size() + Task_ID * 1000;
        Message_Hash.find(GetReviewer()).value().enqueue(newmess1);
        Message_New_Hash.find(GetReviewer()).value().enqueue(newmess1);
    }
}

int task::GetLanF() const
{
    return Lan_F;
}

int task::GetLanT() const
{
    return Lan_T;
}

int task::GetIntH() const
{
    return Integral_Header;
}

int task::GetIntR() const
{
    return Integral_Reviewer;
}

QString task::Get_Intro_S() const
{
    return  Task_Intro.GetInformation();
}

QString task::Get_MainTotal_S() const
{
    return Task_Main_Total.GetInformation();
}


double task::GetReward_Publish() const
{
    return Task_Reward_Publisher;
}

QString task::GetPublisher() const
{
    return Task_Publisher0.GetUsername();
}

QString task::GetHeader() const
{
    return Task_Header0.GetUsername();
}

QString task::GetTranslator(int index) const
{
    if(index < 5)return Task_Translator0[index].GetUsername();
    else return "";
}

QString task::GetReviewer() const
{
    return Task_Reviewer0.GetUsername();
}

int task::GetTranslatorNum() const
{
//    qDebug() << "phn";
    int i = 0;
    for (; i < 5; i++) {
        if(Task_Translator0[i].GetUsername() == "")break;
        qDebug() << "i = " << i << Task_Translator0[i].GetUsername();
    }
    return  i;
}

int task::GetPreHeaderNum() const
{
    int i = 0;
    for (; i < 10; i++) {
//        qDebug() << i << Header1->GetUsername();
        if(Header1[i].GetUsername() == "")break;
    }
    return  i;
}

int task::GetPreReviewerNum() const
{
    int i = 0;
    for (; i < 10; i++) {
//        qDebug() << i << Header1->GetUsername();
        if(Reviewer1[i].GetUsername() == "")break;
    }
    return  i;
}

int task::GetPreTranslatorNum() const
{
    int i;
    for (i = 0; i < 10; i++) {
//        qDebug() << "i = " << i << Translator1[i].GetUsername();
        if(Translator1[i].GetUsername() == "")break;
    }
    return  i;
}

QString task::GetPreHeader(int index) const
{
    if(index < GetPreHeaderNum())
        return Header1[index].GetUsername();
    else return "";
}

QString task::GetPreTranslator(int index) const
{
    if(index < GetPreTranslatorNum())
        return Translator1[index].GetUsername();
    else return "";
}

void task::delete_Translator(int index)
{
    if(index < GetTranslatorNum()){
        for (int i = index; i < GetTranslatorNum() - 1; i ++) {
            Task_Translator0[i] = Task_Translator0[i + 1];
        }
        User user;
        user.SetUsername("");
        Task_Translator0[GetTranslatorNum() - 1] = user;

        for (int i = 16; i < 21; i ++) {
           UpdateTaskFlag[i] = 1;
        }
    }
}

QString task::GetPreReviewer(int index) const
{
    if(index < GetPreReviewerNum())
        return Reviewer1[index].GetUsername();
    else return "";
}

QString task::Get_Main_S(int index) const
{
    return Task_Main[index].GetInformation();
}

QString task::GetFeedback(int index) const
{
    return Task_FeedBack[index].GetInformation();
}
QString task::GetFeedBack2(int index) const
{
    return Task_FeedBack2[index].GetInformation();
}
QString task::Get_Result_S(int index) const
{
    return Task_Result[index].GetInformation();
}
QString task::GetResult_Tem(int index) const
{
    return Task_Resule_Tem[index].GetInformation();
}

QString task::Get_Result_Total_S() const
{
    return Task_Result_Total.GetInformation();
}

QDateTime task::GetDDL_0()const
{
    return Task_Published;
}

QDateTime task::GetDDL_Final() const
{
    return Task_DDL_Final;
}

QDateTime task::GetDDL_Header() const
{
    return Task_DDL_Header;
}

QDateTime task::GetDDL_Reviewer() const
{
    return Task_DDL_Reviewer;
}

void task::SetID(int id)
{
    Task_ID = id;
}

void task::SetState(int s)
{
    State = s;
}

void task::SetLan(int f, int t)
{
    Lan_F = f;
    Lan_T = t;
}

void task::SetIntH(int intH)
{
    Integral_Header = intH;
}

void task::SetIntR(int intR)
{
    Integral_Reviewer =intR;
}

void task::SetIntro(QString Intro)
{
    Task_Intro.SetInformation(Intro);
}

void task::SetMainTotal(QString MainTotal)
{
    Task_Main_Total.SetInformation(MainTotal);
}

void task::SetDDL_0()
{
    Task_Published = QDateTime::currentDateTime();
}

void task::SetDDL_0(QDateTime ddl0)
{
    Task_Published = ddl0;
}

void task::SetReward_Publish(double money)
{
    Task_Reward_Publisher = money;
}

void task::SetPublisher(QString P_User)
{
    Task_Publisher0 =  Userinfo_Hash.find(P_User).value();
}

void task::SetHeader(QString H_User)
{
    Task_Header0 = Userinfo_Hash.find(H_User).value();
}

void task::SetTranslator(QString T_User1, QString T_User2, QString T_User3, QString T_User4, QString T_User5)
{
    Task_Translator0[0] = Userinfo_Hash.find(T_User1).value();
    Task_Translator0[1] = Userinfo_Hash.find(T_User2).value();
    Task_Translator0[2] = Userinfo_Hash.find(T_User3).value();
    Task_Translator0[3] = Userinfo_Hash.find(T_User4).value();
    Task_Translator0[4] = Userinfo_Hash.find(T_User5).value();
}

void task::SetReviewer(QString R_User)
{
    Task_Reviewer0 = Userinfo_Hash.find(R_User).value();
}

void task::set_Main(int index, QString q){
    Task_Main[index].SetInformation(q);
}
void task::set_Resultsave(int index, QString q){
    Task_Resule_Tem[index].SetInformation(q);
}
void task::set_Result(int index, QString q){
    Task_Result[index].SetInformation(q);
}
void task::set_Feedback1(int index, QString q){
    Task_FeedBack[index].SetInformation(q);
}
void task::set_Feedback2(int index, QString q){
    Task_FeedBack2[index].SetInformation(q);
}

void task::set_ResultTotal(QString q)
{
    Task_Result_Total.SetInformation(q);
}

void task::add_Translator(QString T_User)
{
    qDebug ()<< T_User;
    int num = GetTranslatorNum();
    qDebug() << num;
    if(num < 5){
        qDebug() << "CCC00";
        qDebug() << Task_Translator0[num].GetUsername();
        qDebug() << Userinfo_Hash.find(T_User).value().GetUsername();
        Task_Translator0[num] = Userinfo_Hash.find(T_User).value();
        qDebug() << "CCC01";
        qDebug() << Task_Translator0[num].GetUsername() << GetTranslatorNum();
    }
}

void task::add_Main(QString q)
{
    int num = GetTranslatorNum();
    qDebug() << num;
    if(num < 5){
        Task_Main[num].SetInformation(q);
//        qDebug() << Task_Translator0[num].GetUsername() << GetTranslatorNum();
    }
}

void task::add_Result(QString q)
{
    int num = GetTranslatorNum();
    qDebug() << num;
    if(num < 5){
        Task_Result[num].SetInformation(q);
//        qDebug() << Task_Translator0[num].GetUsername() << GetTranslatorNum();
    }
}

void task::add_Resultsave(QString q)
{
    int num = GetTranslatorNum();
    qDebug() << num;
    if(num < 5){
        Task_Resule_Tem[num].SetInformation(q);
//        qDebug() << Task_Translator0[num].GetUsername() << GetTranslatorNum();
    }
}

void task::add_Feedback1(QString q)
{
    int num = GetTranslatorNum();
    qDebug() << num;
    if(num < 5){
        Task_FeedBack[num].SetInformation(q);
//        qDebug() << Task_Translator0[num].GetUsername() << GetTranslatorNum();
    }
}

void task::add_Feedback2(QString q)
{
    int num = GetTranslatorNum();
    qDebug() << num;
    if(num < 5){
        Task_FeedBack2[num].SetInformation(q);
//        qDebug() << Task_Translator0[num].GetUsername() << GetTranslatorNum();
    }
}

void task::add_pre_Header(QString Pre_H_User)
{
//    qDebug() << "add before" << GetPreHeaderNum();
    if(GetPreHeaderNum() < 10){
        Header1[GetPreHeaderNum()] = Userinfo_Hash.find(Pre_H_User).value();
    }
//    qDebug() << "add after" << GetPreHeaderNum();
}

void task::add_pre_Translator(QString Pre_T_User)
{
    if(GetPreTranslatorNum() < 10){
        Translator1[GetPreTranslatorNum()] = Userinfo_Hash.find(Pre_T_User).value();
    }
}

void task::add_pre_Reviewer(QString Pre_R_User)
{
    if(GetPreReviewerNum() < 10){
        Reviewer1[GetPreReviewerNum()] = Userinfo_Hash.find(Pre_R_User).value();
    }
}

void task::SetDDL_Final(QDateTime DDLF)
{
    Task_DDL_Final = DDLF;
}

void task::SetDDL_Header(QDateTime DDLH)
{
    Task_DDL_Header = DDLH;
}

void task::SetDDL_Reviewer(QDateTime DDLR)
{
    Task_DDL_Reviewer = DDLR;
}

int task::LinkRelation(User u)
{
    bool ish = 0, isr = 0, ist = 0;
    for(int i = 0; i < 10; i++){
        if(Header1[i].GetUsername() == u.GetUsername())ish = 1;
    }
    for(int i = 0; i < 10; i++){
        if(Reviewer1[i].GetUsername() == u.GetUsername())isr = 1;
    }
    for(int i = 0; i < 10; i++){
        if(Translator1[i].GetUsername() == u.GetUsername())ist = 1;
    }
    if(u.GetUsername() == Task_Publisher0.GetUsername())return 1;
    else if(u.GetUsername() == Task_Header0.GetUsername())return 2;
    else if(u.GetUsername() == Task_Reviewer0.GetUsername())return 3;
    else if(u.GetUsername() == Task_Translator0[0].GetUsername() || u.GetUsername() == Task_Translator0[1].GetUsername() ||
            u.GetUsername() == Task_Translator0[2].GetUsername() || u.GetUsername() == Task_Translator0[3].GetUsername() ||
            u.GetUsername() == Task_Translator0[4].GetUsername())return 4;
    else if(ish)return 5;
    else if(isr)return 6;
    else if(ist)return 7;
    else  return 0;
}

QString task::LinkRelation_String(User u)
{
    int role = LinkRelation(u);
    switch (role) {
    case 0:
        return "no relation";
    case 1:
        return "publisher";
    case 2:
        return "header";
    case 3:
        return "reviewer";
    case 4:
        return "translator";
    case 5:
        return "pre_header";
    case 6:
        return "pre_reviewer";
    case 7:
        return "pre_translator";
    }
}

bool task::isTranslator(QString username)
{
    bool flag = 0;
    for (int i = 0; i < 5; i ++) {
        if(username == Task_Translator0[i].GetUsername())flag = 1;
    }
    return flag;
}

int task::LinkRelation_c(User u)const
{
    bool ish = 0, isr = 0, ist = 0;
    for(int i = 0; i < 10; i++){
        if(Header1[i].GetUsername() == u.GetUsername())ish = 1;
    }
    for(int i = 0; i < 10; i++){
        if(Reviewer1[i].GetUsername() == u.GetUsername())isr = 1;
    }
    for(int i = 0; i < 10; i++){
        if(Translator1[i].GetUsername() == u.GetUsername())ist = 1;
    }
    if(u.GetUsername() == Task_Publisher0.GetUsername())return 1;
    else if(u.GetUsername() == Task_Header0.GetUsername())return 2;
    else if(u.GetUsername() == Task_Reviewer0.GetUsername())return 3;
    else if(u.GetUsername() == Task_Translator0[0].GetUsername() || u.GetUsername() == Task_Translator0[1].GetUsername() ||
            u.GetUsername() == Task_Translator0[2].GetUsername() || u.GetUsername() == Task_Translator0[3].GetUsername() ||
            u.GetUsername() == Task_Translator0[4].GetUsername())return 4;
    else if(ish)return 5;
    else if(isr)return 6;
    else if(ist)return 7;
    else  return 0;
}
