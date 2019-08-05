/* 文件名 connection.h
 * 用途  打开连接数据库.db文件的通道，创建数据表
*/

#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QDebug>
#include "qdom.h"

/*函数名：Create_Connection_Sql()
 * 用途：创建四张主要数据表
 * userinfo_new_1 用户信息
 * taskinfo 任务发布属性、相关用户
 * taskinfo_new 任务分配信息、翻译结果、反馈
 * taskinfo_final 任务结束信息
*/

bool Create_Connection_Sql();


#endif // CONNECTION_H
