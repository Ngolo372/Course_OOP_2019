#include "connection_taskinfo.h"

//容器

extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;


//数据库中的数据读入内存

void Connection_Taskinfo_Into_Memory()
{

    //connection and inspection
    QSqlDatabase db_userinfo_into_memory = QSqlDatabase::database("data_22.db");
    db_userinfo_into_memory.open();


    //write into memory(taskinfo)
    QSqlQuery query_userinfo_into_memory(db_userinfo_into_memory);
    query_userinfo_into_memory.exec("select * from taskinfo");

    while(query_userinfo_into_memory.next()){
        int ID_Present = query_userinfo_into_memory.value(0).toInt();
        int LanF_Present = query_userinfo_into_memory.value(1).toInt();
        int LanT_Present = query_userinfo_into_memory.value(2).toInt();
        QString Intro_Present = query_userinfo_into_memory.value(3).toString();
        QString Main_Present = query_userinfo_into_memory.value(4).toString();
        QString x = query_userinfo_into_memory.value(5).toString().mid(0,10) + " " + query_userinfo_into_memory.value(5).toString().mid(11,8);
        QDateTime StartTime_Present = QDateTime::fromString(x, "yyyy-MM-dd hh:mm:ss");
        x = query_userinfo_into_memory.value(6).toString().mid(0,10) + " " + query_userinfo_into_memory.value(6).toString().mid(11,8);
        QDateTime DDL_Present = QDateTime::fromString(x, "yyyy-MM-dd hh:mm:ss");
        x = query_userinfo_into_memory.value(7).toString().mid(0,10) + " " + query_userinfo_into_memory.value(7).toString().mid(11,8);
        QDateTime DDLH_Present = QDateTime::fromString(x, "yyyy-MM-dd hh:mm:ss");
        x = query_userinfo_into_memory.value(8).toString().mid(0,10) + " " + query_userinfo_into_memory.value(8).toString().mid(11,8);
        QDateTime DDLR_Present = QDateTime::fromString(x, "yyyy-MM-dd hh:mm:ss");
        int IntH_Present = query_userinfo_into_memory.value(9).toInt();
        int IntR_Present = query_userinfo_into_memory.value(10).toInt();
        int Reward_Present = query_userinfo_into_memory.value(11).toInt();
        int State_Present = query_userinfo_into_memory.value(12).toInt();
        QString Publisher_Present = query_userinfo_into_memory.value(13).toString();
        QString Header_Present = query_userinfo_into_memory.value(14).toString();
        QString Reviewer_Present = query_userinfo_into_memory.value(15).toString();
        QString Translator_Present[5];
        for (int i = 0; i < 5; i ++) {
            Translator_Present[i] = query_userinfo_into_memory.value(i + 16).toString();
        }


        //create an object of class "task" and push it into captain
        task Task_Present;
        Task_Present.SetID(ID_Present);
        Task_Present.SetLan(LanF_Present, LanT_Present);
        Task_Present.SetIntro(Intro_Present);
        Task_Present.SetMainTotal(Main_Present);
        Task_Present.SetDDL_0(StartTime_Present);
        Task_Present.SetDDL_Final(DDL_Present);
        Task_Present.SetDDL_Header(DDLH_Present);
        Task_Present.SetDDL_Reviewer(DDLR_Present);
        Task_Present.SetIntH(IntH_Present);
        Task_Present.SetIntR(IntR_Present);
        Task_Present.SetReward_Publish(Reward_Present);
        Task_Present.SetState(State_Present);
        Task_Present.SetPublisher(Publisher_Present);

        //prevent search from reporting errors
        if(Header_Present != "" && Header_Present != "0") Task_Present.SetHeader(Header_Present);
        if(Reviewer_Present != "" && Reviewer_Present != "0") Task_Present.SetReviewer(Reviewer_Present);
        for (int i = 0; i < 5; i ++) {
            if(Translator_Present[i] != "0" && Translator_Present[i] != "")
                Task_Present.add_Translator(Translator_Present[i]);
        }

        //push into captain
        Taskinfo_Hash.insert(ID_Present, Task_Present);
    }


    //write into memory(taskinfo_new)
    QSqlQuery query_userinfo2_into_memory(db_userinfo_into_memory);
    query_userinfo2_into_memory.exec("select * from taskinfo_new");

    while(query_userinfo2_into_memory.next()){
        int Task_Present = query_userinfo2_into_memory.value(0).toInt();

        QString Main_Part_Present[5];
        for (int i = 0; i < 5; i ++) {
            Main_Part_Present[i] = query_userinfo2_into_memory.value(i + 1).toString();
        }

        QString Tran_Part_Present[5];
        for (int i = 0; i < 5; i ++) {
            Tran_Part_Present[i] = query_userinfo2_into_memory.value(i + 11).toString();           
        }

        QString Transave_Part_Present[5];
        for (int i = 0; i < 5; i ++) {
            Transave_Part_Present[i] = query_userinfo2_into_memory.value(i + 6).toString();          
        }

        QString Feedback_Part_Present[5];
        for (int i = 0; i < 5; i ++) {
            Feedback_Part_Present[i] = query_userinfo2_into_memory.value(i + 16).toString();
        }

        QString Feedback2_Part_Present[5];
        for (int i = 0; i < 5; i ++) {
            Feedback2_Part_Present[i] = query_userinfo2_into_memory.value(i + 21).toString();
        }


        //prevent search from reporting errors
        for (int i = 0; i < 5; i ++) {
            if(Main_Part_Present[i] != "0" && Main_Part_Present[i] != "")
                Taskinfo_Hash.find(Task_Present).value().set_Main(i, Main_Part_Present[i]);               
        }

        for (int i = 0; i < 5; i ++) {
            if(Tran_Part_Present[i] != "0" && Tran_Part_Present[i] != "")
                Taskinfo_Hash.find(Task_Present).value().set_Result(i, Tran_Part_Present[i]);              
        }

        for (int i = 0; i < 5; i ++) {
            if(Transave_Part_Present[i] != "0" && Transave_Part_Present[i] != "")
                Taskinfo_Hash.find(Task_Present).value().set_Resultsave(i, Transave_Part_Present[i]);              
        }

        for (int i = 0; i < 5; i ++) {
            if(Feedback_Part_Present[i] != "0" && Feedback_Part_Present[i] != "")
                Taskinfo_Hash.find(Task_Present).value().set_Feedback1(i, Feedback_Part_Present[i]);
        }

        for (int i = 0; i < 5; i ++) {
            if(Feedback2_Part_Present[i] != "0" && Feedback2_Part_Present[i] != "")
                Taskinfo_Hash.find(Task_Present).value().set_Feedback2(i, Feedback2_Part_Present[i]);
        }
    }


    //write into memory(taskinfo_final)
    QSqlQuery query_userinfo3_into_memory(db_userinfo_into_memory);
    query_userinfo3_into_memory.exec("select * from taskinfo_final");

    while(query_userinfo3_into_memory.next()){
        int i = query_userinfo3_into_memory.value(0).toInt();
        QString q = query_userinfo3_into_memory.value(1).toString();
        //prevent search from reporting errors
        if(q != "" && q != "0")
        {
            Taskinfo_Hash.find(i).value().set_ResultTotal(q);
            Taskinfo_Hash.find(i).value().EndTaskflag = 1;      //end task request
        }
    }
};


//程序运行中新建和修改的数据写入数据库

void Connection_Taskinfo_Into_Sql()
{


    //连接检查

    QSqlDatabase db_userinfo_into_sql = QSqlDatabase::database("data22_db.db");
    db_userinfo_into_sql.open();
    QSqlQuery query_userinfo_into_sql(db_userinfo_into_sql);


    //对于新任务，插入新记录(表 1)

    query_userinfo_into_sql.prepare("insert into taskinfo values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");


    //遍历任务Hash

    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    int icount = 0;
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().NewTaskFlag){
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.value().GetLanF());
            query_userinfo_into_sql.bindValue(2, Taskinfo_Hash_iter.value().GetLanT());
            query_userinfo_into_sql.bindValue(3, Taskinfo_Hash_iter.value().Get_Intro_S());
            query_userinfo_into_sql.bindValue(4, Taskinfo_Hash_iter.value().Get_MainTotal_S());
            query_userinfo_into_sql.bindValue(5, Taskinfo_Hash_iter.value().GetDDL_0());
            query_userinfo_into_sql.bindValue(6, Taskinfo_Hash_iter.value().GetDDL_Final());
            query_userinfo_into_sql.bindValue(7, Taskinfo_Hash_iter.value().GetDDL_Header());
            query_userinfo_into_sql.bindValue(8, Taskinfo_Hash_iter.value().GetDDL_Reviewer());
            query_userinfo_into_sql.bindValue(9, Taskinfo_Hash_iter.value().GetIntH());
            query_userinfo_into_sql.bindValue(10, Taskinfo_Hash_iter.value().GetIntR());
            query_userinfo_into_sql.bindValue(11, Taskinfo_Hash_iter.value().GetReward_Publish());
            query_userinfo_into_sql.bindValue(12, Taskinfo_Hash_iter.value().GetState());
            query_userinfo_into_sql.bindValue(13, Taskinfo_Hash_iter.value().GetPublisher());
            query_userinfo_into_sql.bindValue(14, Taskinfo_Hash_iter.value().GetHeader());
            query_userinfo_into_sql.bindValue(15, Taskinfo_Hash_iter.value().GetReviewer());
            query_userinfo_into_sql.bindValue(16, Taskinfo_Hash_iter.value().GetTranslator(0));
            query_userinfo_into_sql.bindValue(17, Taskinfo_Hash_iter.value().GetTranslator(1));
            query_userinfo_into_sql.bindValue(18, Taskinfo_Hash_iter.value().GetTranslator(2));
            query_userinfo_into_sql.bindValue(19, Taskinfo_Hash_iter.value().GetTranslator(3));
            query_userinfo_into_sql.bindValue(20, Taskinfo_Hash_iter.value().GetTranslator(4));

            query_userinfo_into_sql.exec();
        }

        Taskinfo_Hash_iter ++;
        icount ++ ;
    }


    //对于新任务，插入新记录(表 2)

    QSqlQuery query_userinfo2_into_sql(db_userinfo_into_sql);
    query_userinfo2_into_sql.prepare("insert into taskinfo_new values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");


    //遍历任务Hash

    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    int icount2 = 0;
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().NewTaskFlag){
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.value().Get_Main_S(0));
            query_userinfo2_into_sql.bindValue(2, Taskinfo_Hash_iter.value().Get_Main_S(1));
            query_userinfo2_into_sql.bindValue(3, Taskinfo_Hash_iter.value().Get_Main_S(2));
            query_userinfo2_into_sql.bindValue(4, Taskinfo_Hash_iter.value().Get_Main_S(3));
            query_userinfo2_into_sql.bindValue(5, Taskinfo_Hash_iter.value().Get_Main_S(4));
            query_userinfo2_into_sql.bindValue(6, Taskinfo_Hash_iter.value().GetResult_Tem(0));
            query_userinfo2_into_sql.bindValue(7, Taskinfo_Hash_iter.value().GetResult_Tem(1));
            query_userinfo2_into_sql.bindValue(8, Taskinfo_Hash_iter.value().GetResult_Tem(2));
            query_userinfo2_into_sql.bindValue(9, Taskinfo_Hash_iter.value().GetResult_Tem(3));
            query_userinfo2_into_sql.bindValue(10, Taskinfo_Hash_iter.value().GetResult_Tem(4));
            query_userinfo2_into_sql.bindValue(11, Taskinfo_Hash_iter.value().Get_Result_S(0));
            query_userinfo2_into_sql.bindValue(12, Taskinfo_Hash_iter.value().Get_Result_S(1));
            query_userinfo2_into_sql.bindValue(13, Taskinfo_Hash_iter.value().Get_Result_S(2));
            query_userinfo2_into_sql.bindValue(14, Taskinfo_Hash_iter.value().Get_Result_S(3));
            query_userinfo2_into_sql.bindValue(15, Taskinfo_Hash_iter.value().Get_Result_S(4));
            query_userinfo2_into_sql.bindValue(16, Taskinfo_Hash_iter.value().GetFeedback(0));
            query_userinfo2_into_sql.bindValue(17, Taskinfo_Hash_iter.value().GetFeedback(1));
            query_userinfo2_into_sql.bindValue(18, Taskinfo_Hash_iter.value().GetFeedback(2));
            query_userinfo2_into_sql.bindValue(19, Taskinfo_Hash_iter.value().GetFeedback(3));
            query_userinfo2_into_sql.bindValue(20, Taskinfo_Hash_iter.value().GetFeedback(4));
            query_userinfo2_into_sql.bindValue(21, Taskinfo_Hash_iter.value().GetFeedBack2(0));
            query_userinfo2_into_sql.bindValue(22, Taskinfo_Hash_iter.value().GetFeedBack2(1));
            query_userinfo2_into_sql.bindValue(23, Taskinfo_Hash_iter.value().GetFeedBack2(2));
            query_userinfo2_into_sql.bindValue(24, Taskinfo_Hash_iter.value().GetFeedBack2(3));
            query_userinfo2_into_sql.bindValue(25, Taskinfo_Hash_iter.value().GetFeedBack2(4));

            query_userinfo2_into_sql.exec();
        }

        Taskinfo_Hash_iter ++;
        icount2 ++ ;
    }


    //对于新任务，插入新记录(表 3)

    QSqlQuery query_userinfo3_into_sql(db_userinfo_into_sql);
    query_userinfo3_into_sql.prepare("insert into taskinfo_final values(?,?,?)");

    //遍历任务Hash
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    int icount3 = 0;
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().EndTaskflag){
            query_userinfo3_into_sql.bindValue(0, Taskinfo_Hash_iter.key());
            query_userinfo3_into_sql.bindValue(1, Taskinfo_Hash_iter.value().Get_Result_Total_S());
            query_userinfo3_into_sql.bindValue(2, Taskinfo_Hash_iter.value().GetState());
            query_userinfo3_into_sql.exec();
        }

        Taskinfo_Hash_iter ++;
        icount3 ++ ;
    }


    //updateflag 出现时更新对应记录

    //更新语言

    query_userinfo_into_sql.prepare("update taskinfo set language_from =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[1]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetLanF());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;       
    }


    query_userinfo_into_sql.prepare("update taskinfo set language_to =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[2]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetLanT());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }



    //更新任务简介

    query_userinfo_into_sql.prepare("update taskinfo set introduction =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[3]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Intro_S());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }



    //更新原文

    query_userinfo_into_sql.prepare("update taskinfo set main =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[4]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_MainTotal_S());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新发布时间

    query_userinfo_into_sql.prepare("update taskinfo set time_publish =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[5]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetDDL_0());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新 ddl

    query_userinfo_into_sql.prepare("update taskinfo set ddl_final =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[6]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetDDL_Final());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新负责人和审核人报名ddl

    query_userinfo_into_sql.prepare("update taskinfo set ddl_header =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[7]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetDDL_Header());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新译者报名ddl

    query_userinfo_into_sql.prepare("update taskinfo set ddl_reviewer =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[8]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetDDL_Reviewer());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新负责人积分最低标准

    query_userinfo_into_sql.prepare("update taskinfo set integral_header =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[9]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetIntH());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新审核人积分最低标准

    query_userinfo_into_sql.prepare("update taskinfo set integral_reviewer =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[10]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetIntR());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新酬金

    query_userinfo_into_sql.prepare("update taskinfo set reward =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[11]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetReward_Publish());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新任务状态

    query_userinfo_into_sql.prepare("update taskinfo set state =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[12]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetState());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新负责人

    query_userinfo_into_sql.prepare("update taskinfo set header =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[14]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetHeader());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新审核人

    query_userinfo_into_sql.prepare("update taskinfo set reviewer =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[15]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetReviewer());
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新译者（编号0-4）

    query_userinfo_into_sql.prepare("update taskinfo set translator_0 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[16]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetTranslator(0));
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo_into_sql.prepare("update taskinfo set translator_1 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[17]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetTranslator(1));
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo_into_sql.prepare("update taskinfo set translator_2 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[18]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetTranslator(2));
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo_into_sql.prepare("update taskinfo set translator_3 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[19]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetTranslator(3));
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo_into_sql.prepare("update taskinfo set translator_4 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateTaskFlag[20]){
            query_userinfo_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetTranslator(4));
            query_userinfo_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }



    //更新任务分配

    query_userinfo2_into_sql.prepare("update taskinfo_new set main0 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateMainpart[0]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Main_S(0));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set main1 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateMainpart[1]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Main_S(1));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set main2 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateMainpart[2]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Main_S(2));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set main3 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateMainpart[3]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Main_S(3));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set main4 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateMainpart[4]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Main_S(4));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新译者本次保存翻译结果

    query_userinfo2_into_sql.prepare("update taskinfo_new set resulttem0 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultSavepart[0]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetResult_Tem(0));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set resulttem1 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultSavepart[1]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetResult_Tem(1));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set resulttem2 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultSavepart[2]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetResult_Tem(2));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set resulttem3 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultSavepart[3]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetResult_Tem(3));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set resulttem4 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultSavepart[4]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetResult_Tem(4));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新译者提交结果

    query_userinfo2_into_sql.prepare("update taskinfo_new set result0 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultpart[0]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Result_S(0));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set result1 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultpart[1]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Result_S(1));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set result2 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultpart[2]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Result_S(2));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set result3 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultpart[3]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Result_S(3));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set result4 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateResultpart[4]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Result_S(4));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新负责人反馈

    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback0 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateHFpart[0]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedback(0));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback1 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateHFpart[1]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedback(1));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback2 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateHFpart[2]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedback(2));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback3 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateHFpart[3]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedback(3));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback4 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateHFpart[4]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedback(4));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新审核人反馈

    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback20 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateRFpart[0]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedBack2(0));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback21 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateRFpart[1]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedBack2(1));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback22 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateRFpart[2]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedBack2(2));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback23 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateRFpart[3]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedBack2(3));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }

    query_userinfo2_into_sql.prepare("update taskinfo_new set feedback24 =? where id =?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().UpdateRFpart[4]){
            query_userinfo2_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo2_into_sql.bindValue(0, Taskinfo_Hash_iter.value().GetFeedBack2(4));
            query_userinfo2_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }


    //更新负责人提交的最终译文

    query_userinfo3_into_sql.prepare("insert into taskinfo_final values(?,?,?)");
    query_userinfo3_into_sql.prepare("update taskinfo_final set main=? where id=?");
    Taskinfo_Hash_iter = Taskinfo_Hash.constBegin();
    while (Taskinfo_Hash_iter != Taskinfo_Hash.constEnd()) {
        if(Taskinfo_Hash_iter.value().EndTaskflag){
            query_userinfo3_into_sql.bindValue(1, Taskinfo_Hash_iter.key());
            query_userinfo3_into_sql.bindValue(0, Taskinfo_Hash_iter.value().Get_Result_Total_S());
            query_userinfo3_into_sql.exec();
        }
        Taskinfo_Hash_iter ++;
    }
};



//加入报名人员

void Connection_Taskinfo_Pres()
{
    //traverse the Link_usertask_Hash
    Link_usertask_Hash_iter = Link_usertask_Hash.constBegin();
    while (Link_usertask_Hash_iter != Link_usertask_Hash.constEnd()) {        
        Link_Task_Hash_iter = Link_usertask_Hash_iter.value().constBegin();
        while(Link_Task_Hash_iter != Link_usertask_Hash_iter.value().constEnd()){
            if(Link_Task_Hash_iter.value() / 10 == 5)
                Taskinfo_Hash.find(Link_Task_Hash_iter.key())->add_pre_Header(Link_usertask_Hash_iter.key());
            if(Link_Task_Hash_iter.value() / 10 == 6)
                Taskinfo_Hash.find(Link_Task_Hash_iter.key())->add_pre_Translator(Link_usertask_Hash_iter.key());
            if(Link_Task_Hash_iter.value() / 10 == 7)
                Taskinfo_Hash.find(Link_Task_Hash_iter.key())->add_pre_Reviewer(Link_usertask_Hash_iter.key());

            Link_Task_Hash_iter ++;
        }
        Link_usertask_Hash_iter ++;
    }

}
