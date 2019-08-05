//任务内容类， 本次只实现QString文字， 可扩展为文件传输

#ifndef TASK_INFOMATION_H
#define TASK_INFOMATION_H
#include "project.h"

class Task_Infomation
{
public:
    Task_Infomation();
    ~Task_Infomation();

    //设置与获取

    void SetInformation(QString Information_New);
    QString GetInformation()const;

private:
    QString Information;
};

#endif // TASK_INFOMATION_H
