#include "task_infomation.h"

Task_Infomation::Task_Infomation()
{

}

Task_Infomation::~Task_Infomation()
{

}

void Task_Infomation::SetInformation(QString Information_New)
{
    Information = Information_New;
}

QString Task_Infomation::GetInformation()const
{
    return Information;
}
