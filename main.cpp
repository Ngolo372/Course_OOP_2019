#include "dialog_main.h"
#include "project.h"
#include "connection.h"
#include "connection_userinfo.h"
#include "connection_taskinfo.h"
#include "user_caps.h"
#include <QApplication>

extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //建表， 读入内存

    Create_Connection_Sql();
    Connection_Userinfo_Into_Memory();
    Connection_Taskinfo_Into_Memory();
    Connection_Taskinfo_Pres();

    //主框外显

    Dialog_Main w;
    w.setWindowTitle("iTranslate");
    w.setMinimumWidth(1152);
    w.setMinimumHeight(992);
    w.setMaximumHeight(992);
    w.setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint|Qt::WindowCloseButtonHint);
    w.show();
    return a.exec();
}
