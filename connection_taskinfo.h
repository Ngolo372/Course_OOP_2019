/* 文件名 connection_taskinfo.h
 * 用途  程序启动时将数据库中存储的任务相关信息写入内存
 *      程序关闭时将内存中有新增或修改标记的任务相关信息写入数据库
*/

#ifndef CONNECTION_TASKINFO_H
#define CONNECTION_TASKINFO_H

#include "project.h"
#include "task.h"

/*函数名：Connection_Taskinfo_Into_Memory()
 * 用途：程序启动时将数据库中存储的任务相关信息写入内存
*/

void Connection_Taskinfo_Into_Memory();



/*函数名：Connection_Taskinfo_Pres()
 * 用途：程序启动时将数据库中存储的任务待定人员信息（已报名负责人、审核人、译者但未通过）写入内存
*/
void Connection_Taskinfo_Pres();



/*函数名：Connection_Taskinfo_Into_Sql()
 * 用途：程序关闭时将内存中有新增或修改标记的任务相关信息写入数据库
*/

void Connection_Taskinfo_Into_Sql();




#endif // CONNECTION_TASKINFO_H
