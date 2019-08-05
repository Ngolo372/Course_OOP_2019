//容器

#ifndef USER_CAPS_H
#define USER_CAPS_H

#include "project.h"
#include "user.h"
#include "task.h"
#include "message.h"

//all signed-up users infomation
QHash<QString, User> Userinfo_Hash;
QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;

//online users information
//QHash<QString, user> Online_User_Info_Hash;
//QHash<QString, user> ::const_iterator Online_User_Info_Hash_Iter;

User OnlineUser;
//QString OnlineUsername;

QHash<int, task> Taskinfo_Hash;
QHash<int, task>::const_iterator Taskinfo_Hash_iter;

QHash <int, int> Link_Task_Hash[1000];
QHash <int, int>::const_iterator Link_Task_Hash_iter;
QHash <QString, QHash<int, int>>Link_usertask_Hash;
QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;

QHash <QString, QQueue<message>>Message_Hash;
QHash <QString, QQueue<message>>::const_iterator Message_Hash_iter;
QHash <QString, QQueue<message>>Message_New_Hash;
QHash <QString, QQueue<message>>::const_iterator Message_New_Hash_iter;
QHash <QString, QQueue<message>>Message_NewState_Hash;
QHash <QString, QQueue<message>>::const_iterator Message_NewState_Hash_iter;
QQueue<message> Message_Queue[1000];
QQueue<message> Message_New_Queue[1000];
QQueue<message> Message_NewState_Queue[1000];
#endif // USER_CAPS_H
