#include "dialog_admin.h"


//容器

extern User OnlineUser;
extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;


//构造

dialog_admin::dialog_admin(QWidget *parent) : QWidget(parent)
{

    adminLabel = new QLabel(tr("Please input admin password"));
    adminEdit = new QLineEdit;
    adminButton = new QPushButton(tr("confirm"));
    adminTable_user = new QTableWidget(1000, 7);
    adminToplayout = new QHBoxLayout;
    applyButton = new QPushButton(tr("apply"));
    adminToplayout ->addWidget(adminLabel);
    adminToplayout ->addWidget(adminEdit);
    adminToplayout ->addWidget(adminButton);
    adminLayout = new QVBoxLayout(this);
    adminLayout ->addLayout(adminToplayout);
    adminLayout ->addWidget(applyButton);
    applyButton ->setEnabled(0);
    adminLayout ->addWidget(adminTable_user);

    //密码正确时， 平台管理员可以登录

    connect(adminButton, SIGNAL(clicked()), this, SLOT(admin_login()));
}



//平台管理员登录

void dialog_admin::admin_login()
{
    if(adminEdit ->text() == "20181111")
    {

        //平台密码20181111

        applyButton ->setEnabled(1);
        adminEdit ->clear();
        adminEdit ->setEnabled(0);


        //提取用户分数信息、任务积分、余额

        int ucount = 0;
        Userinfo_Hash_Iter = Userinfo_Hash.constBegin();
        while (Userinfo_Hash_Iter != Userinfo_Hash.constEnd()) {
            adminTable_user ->setItem(ucount, 0, new QTableWidgetItem(Userinfo_Hash_Iter.value().GetUsername()));
            adminTable_user ->setItem(ucount, 1, new QTableWidgetItem(QString ("%1").arg(Userinfo_Hash_Iter.value().get_cet4_score())));
            adminTable_user ->setItem(ucount, 2, new QTableWidgetItem(QString ("%1").arg(Userinfo_Hash_Iter.value().get_cet6_score())));
            adminTable_user ->setItem(ucount, 3, new QTableWidgetItem(QString ("%1").arg(Userinfo_Hash_Iter.value().get_tem4_score())));
            adminTable_user ->setItem(ucount, 4, new QTableWidgetItem(QString ("%1").arg(Userinfo_Hash_Iter.value().get_tem8_score())));
            adminTable_user ->setItem(ucount, 5, new QTableWidgetItem(QString ("%1").arg(Userinfo_Hash_Iter.value().Get_User_Tasks_Intergral())));
            adminTable_user ->setItem(ucount, 6, new QTableWidgetItem(QString ("%1").arg(Userinfo_Hash_Iter.value().Get_User_Money_int())));
            Userinfo_Hash_Iter ++;
            ucount ++;
        }

        //点击"apply" 保存更改

        connect(applyButton, SIGNAL(clicked()), this, SLOT(change_integral()));
    }

    //密码错误提示

    else {
        QMessageBox::warning(this, "password wrong", "password wrong");
    }
}


//保存

void dialog_admin::change_integral()
{
    QMessageBox::information(this, "OK", "change success");
    int ucount = 0;
    while (ucount < Userinfo_Hash.size()) {
        Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().set_cet4_score(adminTable_user ->item(ucount, 1) ->text().toInt());
        Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().set_cet6_score(adminTable_user ->item(ucount, 2) ->text().toInt());
        Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().set_tem4_score(adminTable_user ->item(ucount, 3) ->text().toInt());
        Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().set_tem8_score(adminTable_user ->item(ucount, 4) ->text().toInt());
        Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().Set_User_Task_Integral(adminTable_user ->item(ucount, 5) ->text().toInt());
        Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().SetMoney(adminTable_user ->item(ucount, 6) ->text().toInt());
        Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().Set_User_Language_Intergral();
        Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().Set_User_Intergral();

        //set the information modify flags
        for (int i = 13; i < 27; i ++) {
            Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().Changeinfoflag[i] = 1;
        }
        qDebug() << Userinfo_Hash.find(adminTable_user ->item(ucount, 0) ->text()).value().Get_User_Intergral();
        ucount ++;
    }
}
