/* 文件名 connection_userinfo.h
 * 用途  程序启动时将数据库中存储的用户相关信息、用户-任务连接信息、用户-消息连接信息写入内存
 *      程序关闭时将内存中有新增或修改标记的用户相关信息、用户-任务连接信息、用户-消息连接信息写入数据库
*/

#ifndef CONNECTION_USERINFO_H
#define CONNECTION_USERINFO_H

#include "project.h"
#include "user.h"
#include "task.h"
#include "message.h"

/* 函数名 Connection_Userinfo_Into_Memory()
 * 程序启动时将数据库中存储的用户相关信息、用户-任务连接信息、用户-消息连接信息写入内存
*/
void Connection_Userinfo_Into_Memory();


/* 函数名 Connection_Userinfo_Into_Sql()
 * 程序关闭时将内存中有新增或修改标记的用户相关信息、用户-任务连接信息、用户-消息连接信息写入数据库
*/
void Connection_Userinfo_Into_Sql();

#endif // CONNECTION_USERINFO_H
