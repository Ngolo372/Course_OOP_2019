//transmit the user_info date between sql and memory

#include "connection_userinfo.h"

#define uint16_t     unsigned short int
#define uint32_t     unsigned int


//容器

extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;
extern QHash<int, task> Taskinfo_Hash;
extern QHash<int, task>::const_iterator Taskinfo_Hash_iter;
extern QHash <QString, QQueue<message>>Message_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_Hash_iter;
extern QHash <QString, QQueue<message>>Message_New_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_New_Hash_iter;
extern QHash <QString, QQueue<message>>Message_NewState_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_NewState_Hash_iter;
extern QQueue<message> Message_Queue[1000];
extern QQueue<message> Message_New_Queue[1000];
extern QQueue<message> Message_NewState_Queue[1000];


//用户信息读入内存

void Connection_Userinfo_Into_Memory(){

    //连接检查

    QSqlDatabase db_userinfo_into_memory = QSqlDatabase::database("data_22.db");
    db_userinfo_into_memory.open();


    //读取数据
    QSqlQuery query_userinfo_into_memory(db_userinfo_into_memory);
    query_userinfo_into_memory.exec("select * from userinfo_new_1");

    int ucount = 0;
    while(query_userinfo_into_memory.next()){
        QString Username_Present = query_userinfo_into_memory.value(0).toString();
        QString Password_Present = query_userinfo_into_memory.value(1).toString();
        bool Sex_Present = (query_userinfo_into_memory.value(6) == "Female");
        uint32_t CET4Score_Present = query_userinfo_into_memory.value(16).toUInt();
        QString CET4Level_Present = query_userinfo_into_memory.value(23).toString();
        uint32_t CET6Score_Present = query_userinfo_into_memory.value(17).toUInt();
        QString CET6Level_Present = query_userinfo_into_memory.value(24).toString();
        uint32_t TEM4Score_Present = query_userinfo_into_memory.value(18).toUInt();
        QString TEM4Level_Present = query_userinfo_into_memory.value(25).toString();
        uint32_t TEM8Score_Present = query_userinfo_into_memory.value(19).toUInt();
        QString TEM8Level_Present = query_userinfo_into_memory.value(26).toString();
        int Money_Present = query_userinfo_into_memory.value(27).toInt();
        int Taskint_Present = query_userinfo_into_memory.value(14).toInt();

        User User_Present;
        User_Present.SetUsername(Username_Present);
        User_Present.SetPassword(Password_Present);
        User_Present.SetSex(Sex_Present);
        User_Present.set_cet4_score((uint16_t)CET4Score_Present);
        User_Present.set_cet6_score((uint16_t)CET6Score_Present);
        User_Present.set_tem4_score((uint16_t)TEM4Score_Present);
        User_Present.set_tem8_score((uint16_t)TEM8Score_Present);
        User_Present.Set_User_Language_Intergral();
        User_Present.Set_User_Task_Integral(Taskint_Present);
        User_Present.Set_User_Intergral();
        User_Present.SetMoney(Money_Present);
        Userinfo_Hash.insert(Username_Present, User_Present);


        //for each user, get his/her information linked to tasks and messages
        //get user-task correspondence
        QSqlQuery query_link_into_memory(db_userinfo_into_memory);
        const QString linktablename = QString("select * from %1").arg(Username_Present);
        query_link_into_memory.exec(linktablename);
        while(query_link_into_memory.next()){
            int Link_Task_Present = query_link_into_memory.value(0).toInt();
            int Link_State = query_link_into_memory.value(1).toInt();
            int Link_relation = query_link_into_memory.value(2).toInt();
            Link_Task_Hash[ucount].insert(Link_Task_Present, Link_relation * 10 + Link_State);

        }


        //get user-task correspondence
        QSqlQuery query_mess_into_memory(db_userinfo_into_memory);
        const QString messtablename = QString("select * from %1").arg(Username_Present + "messages");
        query_mess_into_memory.exec(messtablename);
        while(query_mess_into_memory.next()){
            int floatid_Present = query_mess_into_memory.value(0).toInt();
            int Mess_Task_Present = floatid_Present / 1000;
            int Mess_Flag = query_mess_into_memory.value(1).toInt();
            QString Mess_Main = query_mess_into_memory.value(2).toString();
            message Mess_Present(Mess_Task_Present, bool(Mess_Flag), Mess_Main);
            Mess_Present.floatid =  floatid_Present;
            Message_Queue[ucount].enqueue(Mess_Present);
        }

        Link_usertask_Hash.insert(Username_Present, Link_Task_Hash[ucount]);
        Message_Hash.insert(Username_Present, Message_Queue[ucount]);
        Message_New_Hash.insert(Username_Present, Message_New_Queue[ucount]);
        Message_NewState_Hash.insert(Username_Present, Message_NewState_Queue[ucount]);
        ucount ++;
    }
}


//存入数据库

void Connection_Userinfo_Into_Sql(){

    //连接检查

    QSqlDatabase db_userinfo_into_sql = QSqlDatabase::database("data22_db.db");
    db_userinfo_into_sql.open();


    //插入新注册用户

    QSqlQuery query_userinfo_into_sql(db_userinfo_into_sql);
    query_userinfo_into_sql.prepare(
                "insert into userinfo_new_1 values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");


    //遍历

    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    int icount = 0;    
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Signupflag){
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.value().GetPassword());
            query_userinfo_into_sql.bindValue(2, 0);
            query_userinfo_into_sql.bindValue(3, 0);
            query_userinfo_into_sql.bindValue(4, 0);
            query_userinfo_into_sql.bindValue(5, 0);
            QString sexchar = Userinfo_Hash_Iter.value().GetSex() ? "Female" : "Male";
            query_userinfo_into_sql.bindValue(6, sexchar);
            query_userinfo_into_sql.bindValue(7, 0);
            query_userinfo_into_sql.bindValue(8, 0);
            query_userinfo_into_sql.bindValue(9, 0);
            query_userinfo_into_sql.bindValue(10, 0);
            query_userinfo_into_sql.bindValue(11, 0);
            query_userinfo_into_sql.bindValue(12, 0);
            query_userinfo_into_sql.bindValue(13, Userinfo_Hash_Iter.value().Get_User_Language_Intergral());
            query_userinfo_into_sql.bindValue(14, Userinfo_Hash_Iter.value().Get_User_Tasks_Intergral());
            query_userinfo_into_sql.bindValue(15, Userinfo_Hash_Iter.value().Get_User_Intergral());
            query_userinfo_into_sql.bindValue(16, Userinfo_Hash_Iter.value().get_cet4_score());
            query_userinfo_into_sql.bindValue(17, Userinfo_Hash_Iter.value().get_cet6_score());
            query_userinfo_into_sql.bindValue(18, Userinfo_Hash_Iter.value().get_tem4_score());
            query_userinfo_into_sql.bindValue(19, Userinfo_Hash_Iter.value().get_tem8_score());
            query_userinfo_into_sql.bindValue(20, 0);
            query_userinfo_into_sql.bindValue(21, 0);
            query_userinfo_into_sql.bindValue(22, 0);
            query_userinfo_into_sql.bindValue(23, QString(Userinfo_Hash_Iter.value().get_cet4_level()));
            query_userinfo_into_sql.bindValue(24, QString(Userinfo_Hash_Iter.value().get_cet6_level()));
            query_userinfo_into_sql.bindValue(25, QString(Userinfo_Hash_Iter.value().get_tem4_level()));
            query_userinfo_into_sql.bindValue(26, QString(Userinfo_Hash_Iter.value().get_tem8_level()));
            query_userinfo_into_sql.bindValue(27, Userinfo_Hash_Iter.value().Get_User_Money_int());

            query_userinfo_into_sql.exec();


            //对每一个用户， 新建用户-任务角色连接表

            QSqlQuery query_new_link_new_memory(db_userinfo_into_sql);
            const QString tablename =QString("create table %1("
                                      "taskid int primary key, "
                                      "state int, "
                                      "role int"
                                      ")").arg(Userinfo_Hash_Iter.key());
            query_new_link_new_memory.prepare(tablename);
            query_new_link_new_memory.exec();


            //对每一个用户， 查看用户-任务角色连接表

            const QString Seltablename = QString("select * from %1").arg(Userinfo_Hash_Iter.key());
            bool sql_createlink_success = query_new_link_new_memory.exec(Seltablename);
            while(!sql_createlink_success)query_new_link_new_memory.exec(Seltablename);



            //对每一个用户， 新建用户-消息连接表

            QSqlQuery query_message_into_memory(db_userinfo_into_sql);
            const QString _m_tablename =QString("create table %1("
                                      "taskid int primary key, "
                                      "flag int, "
                                      "main varchar"
                                      ")").arg(Userinfo_Hash_Iter.key() + "messages");
            query_new_link_new_memory.prepare(_m_tablename);
            query_new_link_new_memory.exec();


            //对每一个用户， 查看用户-消息连接表

            const QString _m_Seltablename = QString("select * from %1").arg(Userinfo_Hash_Iter.key() + "messages");
            bool sql_createmess_success = query_new_link_new_memory.exec(_m_Seltablename);
            while(!sql_createmess_success)query_new_link_new_memory.exec(_m_Seltablename);
        }       


        //每一个用户， 查看用户-任务角色连接表

        QSqlDatabase db_link_into_sql = QSqlDatabase::database("data22_db.db");
        if(!db_link_into_sql.isOpen())db_link_into_sql.open();
        QSqlQuery query_link_into_sql(db_link_into_sql);
        const QString Seltablename = QString("select * from %1").arg(Userinfo_Hash_Iter.key());
        bool sql_createlink_success = query_link_into_sql.exec(Seltablename);
        while(!sql_createlink_success)query_link_into_sql.exec(Seltablename);



        //每一个用户， 用户-任务角色连接表插入新记录

        const QString Instablename = QString("insert into %1 values(?,?,?)").arg(Userinfo_Hash_Iter.key());
        query_link_into_sql.prepare(Instablename);
        Link_Task_Hash_iter = Link_usertask_Hash.find(Userinfo_Hash_Iter.key()).value().constBegin();
        while(Link_Task_Hash_iter != Link_usertask_Hash.find(Userinfo_Hash_Iter.key()).value().constEnd())
        {
            if(Taskinfo_Hash.find(Link_Task_Hash_iter.key())->NewTaskFlag){
                query_link_into_sql.bindValue(0, Link_Task_Hash_iter.key());
                query_link_into_sql.bindValue(1, Link_Task_Hash_iter.value()%10);
                query_link_into_sql.bindValue(2, Link_Task_Hash_iter.value()/10);                
                query_link_into_sql.exec();
            }
            Link_Task_Hash_iter ++;
        }


        //一个用户， 用户-消息连接表插入新记录

        const QString Instablename_mess =
                QString("insert into %1 values(?,?,?)").arg(Userinfo_Hash_Iter.key() + "messages");
        query_link_into_sql.prepare(Instablename_mess);
        int start = Message_Hash.find(Userinfo_Hash_Iter.key()).value().size()
                -  Message_New_Hash.find(Userinfo_Hash_Iter.key()).value().size();
        while(!Message_New_Hash.find(Userinfo_Hash_Iter.key()).value().isEmpty())
        {
            if(1){
                message NewMess = Message_New_Hash.find(Userinfo_Hash_Iter.key()).value().dequeue();
                query_link_into_sql.bindValue(0, NewMess.floatid);
                query_link_into_sql.bindValue(1, NewMess.isnotread);
                query_link_into_sql.bindValue(2, NewMess.getmessage());
                query_link_into_sql.exec();
                start ++;
            }
        }


        //更新连接表中的任务状态

        const QString UpdateTablename =
                QString("update %1 set state =? where taskid =?").arg(Userinfo_Hash_Iter.key());
        query_link_into_sql.prepare(UpdateTablename);
        Link_Task_Hash_iter = Link_usertask_Hash.find(Userinfo_Hash_Iter.key()).value().constBegin();
        while(Link_Task_Hash_iter != Link_usertask_Hash.find(Userinfo_Hash_Iter.key()).value().constEnd())
        {
            if(Taskinfo_Hash.find(Link_Task_Hash_iter.key())->UpdateTaskFlag[12]){
                query_link_into_sql.bindValue(1, Link_Task_Hash_iter.key());
                query_link_into_sql.bindValue(0, Link_Task_Hash_iter.value()%10);
                query_link_into_sql.exec();
            }
            Link_Task_Hash_iter ++;
        }


        //更新连接表中的对应角色

        const QString UpdateTablename2 = QString("update %1 set role =? where taskid =?").arg(Userinfo_Hash_Iter.key());
        query_link_into_sql.prepare(UpdateTablename2);
        Link_Task_Hash_iter = Link_usertask_Hash.find(Userinfo_Hash_Iter.key()).value().constBegin();
        while(Link_Task_Hash_iter != Link_usertask_Hash.find(Userinfo_Hash_Iter.key()).value().constEnd())
        {
            if(Taskinfo_Hash.find(Link_Task_Hash_iter.key())->UpdateTaskFlag[14] || Taskinfo_Hash.find(Link_Task_Hash_iter.key())->UpdateTaskFlag[15]
                   || Taskinfo_Hash.find(Link_Task_Hash_iter.key())->UpdateTaskFlag[16]){
                query_link_into_sql.bindValue(1, Link_Task_Hash_iter.key());
                query_link_into_sql.bindValue(0, Link_Task_Hash_iter.value()/10);
                query_link_into_sql.exec();
            }
            Link_Task_Hash_iter ++;
        }


        //更新消息未读状态

        const QString UpdateTablename2_mess = QString("update %1 set flag =? where taskid =?").arg(Userinfo_Hash_Iter.key() + "messages");
        query_link_into_sql.prepare(UpdateTablename2_mess);

        while(!Message_NewState_Hash.find(Userinfo_Hash_Iter.key()).value().isEmpty())
        {          
            message NewMess = Message_NewState_Hash.find(Userinfo_Hash_Iter.key()).value().dequeue();
            if(!NewMess.isnotread){
                query_link_into_sql.bindValue(1, NewMess.floatid);
                query_link_into_sql.bindValue(0, NewMess.isnotread);
                query_link_into_sql.exec();
            }
        }
        Userinfo_Hash_Iter ++;
        icount ++ ;
    }



    //改密码

    query_userinfo_into_sql.prepare("update userinfo_new_1 set password =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[1]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.value().GetPassword());
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }


    //改性别

    query_userinfo_into_sql.prepare("update userinfo_new_1 set sex =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[6]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            QString sexchar = Userinfo_Hash_Iter.value().GetSex() ? "Female" : "Male";
            query_userinfo_into_sql.bindValue(0, sexchar);
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }



    //改分数、积分

    //update cet4
    query_userinfo_into_sql.prepare("update userinfo_new_1 set cet4score =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[16]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.value().get_cet4_score());
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }
    query_userinfo_into_sql.prepare("update userinfo_new_1 set cet4level =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[23]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, QString(Userinfo_Hash_Iter.value().get_cet4_level()));
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }



    //update cet6
    query_userinfo_into_sql.prepare("update userinfo_new_1 set cet6score =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[17]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.value().get_cet6_score());
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }

    query_userinfo_into_sql.prepare("update userinfo_new_1 set cet6level =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[24]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, QString(Userinfo_Hash_Iter.value().get_cet6_level()));
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }


    //update tem4
    query_userinfo_into_sql.prepare("update userinfo_new_1 set tem4score =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[18]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.value().get_tem4_score());
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }

    query_userinfo_into_sql.prepare("update userinfo_new_1 set tem4level =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[25]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, QString(Userinfo_Hash_Iter.value().get_tem4_level()));
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }



    //update tem8
    query_userinfo_into_sql.prepare("update userinfo_new_1 set tem8score =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[19]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.value().get_tem8_score());
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }

    query_userinfo_into_sql.prepare("update userinfo_new_1 set tem4level =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[26]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, QString(Userinfo_Hash_Iter.value().get_tem8_level()));
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }


    //update integrals
    query_userinfo_into_sql.prepare("update userinfo_new_1 set lan_intergral =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[13]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.value().Get_User_Language_Intergral());
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }

    query_userinfo_into_sql.prepare("update userinfo_new_1 set tas_intergral =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[14]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.value().Get_User_Tasks_Intergral());
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }

    query_userinfo_into_sql.prepare("update userinfo_new_1 set intergral =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[15]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.value().Get_User_Intergral());
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }


    //改钱

    query_userinfo_into_sql.prepare("update userinfo_new_1 set money =? where username =?");
    Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
    while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
        if(Userinfo_Hash_Iter.value().Changeinfoflag[27]){
            query_userinfo_into_sql.bindValue(1, Userinfo_Hash_Iter.key());
            query_userinfo_into_sql.bindValue(0, Userinfo_Hash_Iter.value().Get_User_Money_int());
            query_userinfo_into_sql.exec();
        }
        Userinfo_Hash_Iter ++;
    }
}

