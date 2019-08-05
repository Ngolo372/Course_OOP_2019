/* 文件名 dialog_main_userinfo_onlyread.h
 * 用途  dialog_main_userinfo_onlyread 个人信息只读
*/

#ifndef DIALOG_MAIN_USERINFO_ONLYREAD_H
#define DIALOG_MAIN_USERINFO_ONLYREAD_H

#include <QWidget>
#include "project.h"
#include "dialog_main_userinfo.h"
#include "user.h"

/* 类名 dialog_main_userinfo_onlyread 个人信息只读
*/

class dialog_main_userinfo_onlyread : public QWidget
{
    Q_OBJECT
public:
    explicit dialog_main_userinfo_onlyread(QWidget *parent = nullptr);
    dialog_main_userinfo_onlyread(QString checkuser);
    ~dialog_main_userinfo_onlyread();

    //用户名

    QString MainUser;
signals:

public slots:

private:
    //Tips
    QLabel *Dialog_Main_Userinfo_onlyread_Username_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Nickname_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Realname_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_FreeSign_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Sex_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Age_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Address_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Address_Country_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Address_Province_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Address_City_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_PhoneNumber_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Email_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_ID_Number_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Language_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Language_Cet4_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Language_Cet6_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Language_Tem4_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Language_Tem8_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Language_Toefl_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Language_Ielts_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Language_Gre_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Lan_Intergral_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Tas_Intergral_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_Intergral_Label;

    QLabel *Dialog_Main_Userinfo_onlyread_0_Username_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Nickname_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Realname_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_FreeSign_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Sex_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Age_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Address_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Address_Country_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Address_Province_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Address_City_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_PhoneNumber_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Email_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_ID_Number_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Language_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Language_Cet4_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Language_Cet6_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Language_Tem4_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Language_Tem8_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Language_Toefl_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Language_Ielts_Label;
    QLabel *Dialog_Main_Userinfo_onlyread_0_Language_Gre_Label;

    QGridLayout *Dialog_Main_Userinfo_onlyread_Userinfo_onlyread_Layout;
    QGridLayout *Dialog_Main_Userinfo_onlyread_UserSelf_Layout;
    QGridLayout *Dialog_Main_Userinfo_onlyread_Address_Layout;
    QGridLayout *Dialog_Main_Userinfo_onlyread_Language_Layout;
    QHBoxLayout *Dialog_Main_Userinfo_onlyread_Btn_Layout;
    QVBoxLayout *Dialog_Main_Userinfo_onlyread_Layout;

};

#endif // DIALOG_MAIN_USERINFO_ONLYREAD_H
