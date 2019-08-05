#include "connection.h"

bool Create_Connection_Sql()
{


    //建立数据库连接

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("easybook-3313b0");
    db.setDatabaseName("data_22.db");
    db.setUserName("diamond");
    db.setPassword("123456");


    //打开数据库连接通道

    if(!db.open()){
        return false;
    }


    //QsqlQuery类， 执行数据库语句

    QSqlQuery query(db);


    //建立表 userinfo_new_1: 个人基本信息

    query.exec("create table userinfo_new_1("
               "username varchar primary key, "
               "password varchar, "
               "nickname varchar, "
               "realname varchar, "
               "freesign varchar, "
               "age int, "
               "sex varchar, "
               "country varchar, "
               "province varchar, "
               "city varchar, "
               "phonenumber long, "
               "email varchar, "
               "idnumber varchar, "
               "lan_intergral int, "
               "tas_intergral int, "
               "intergral int, "
               "cet4score short, "
               "cet6score short, "
               "tem4score short, "
               "tem8score short, "
               "toeflscore short, "
               "ieltsscore short, "
               "grescore short, "
               "cet4level varchar, "
               "cet6level varchar, "
               "tem4level varchar, "
               "tem8level varchar, "
               "money int"
               ")");
    bool sql_select_success = query.exec("select * from userinfo_new_1");
    while(!sql_select_success)query.exec("select * from userinfo_new_1");


    //建立表 taskinfo & taskinfo_new & taskinfo_final: 任务信息

    query.exec("create table taskinfo("
               "id int primary key, "
               "language_from int, "
               "language_to int, "
               "introduction varchar, "
               "main varchar, "
               "time_publish varchar, "
               "ddl_final varchar, "
               "ddl_header varchar, "
               "ddl_reviewer varchar, "
               "integral_header int, "
               "integral_reviewer int, "
               "reward double, "
               "state int, "
               "publisher varchar, "
               "header varchar, "
               "reviewer varchar, "
               "translator_0 varchar, "
               "translator_1 varchar, "
               "translator_2 varchar, "
               "translator_3 varchar, "
               "translator_4 varchar"
               ")");
    bool sql_select_success_1 = query.exec("select * from taskinfo");
    while(!sql_select_success_1)query.exec("select * from taskinfo");

    query.exec("create table taskinfo_new("
               "id int primary key, "
               "main0 varchar, "
               "main1 varchar, "
               "main2 varchar, "
               "main3 varchar, "
               "main4 varchar, "
               "resulttem0 varchar, "
               "resulttem1 varchar, "
               "resulttem2 varchar, "
               "resulttem3 varchar, "
               "resulttem4 varchar, "
               "result0 varchar, "
               "result1 varchar, "
               "result2 varchar, "
               "result3 varchar, "
               "result4 varchar, "
               "feedback0 varchar, "
               "feedback1 varchar, "
               "feedback2 varchar, "
               "feedback3 varchar, "
               "feedback4 varchar, "
               "feedback20 varchar, "
               "feedback21 varchar, "
               "feedback22 varchar, "
               "feedback23 varchar, "
               "feedback24 varchar"
               ")");
    bool sql_select_success_2 = query.exec("select * from taskinfo_new");
    while(!sql_select_success_2)query.exec("select * from taskinfo_new");

    query.exec("create table taskinfo_final(id int primary key, main varchar, state int)");
    bool sql_select_success_3 = query.exec("select * from taskinfo_final");
    while(!sql_select_success_3)query.exec("select * from taskinfo_final");


    return  true;
}
