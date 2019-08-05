/* 文件名 dialog_main_signup.h
 * 用途  dialog_main_signup 注册界面对话框
*/


#ifndef DIALOG_SIGNUP_H
#define DIALOG_SIGNUP_H

#include "project.h"
#include <QDialog>
#include "user.h"
#include "message.h"

#define uint16_t     unsigned short int

namespace Ui {
class Dialog_Signup;
}


/* 类名 dialog_main_signup 注册界面对话框
*/

class Dialog_Signup : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Signup(QWidget *parent = nullptr);
    ~Dialog_Signup();


    /* 函数名 Dialog_Signup_GetUsername / Dialog_Signup_GetPassword
     * 用途：获取新用户 用户名、密码
    */
    QString Dialog_Signup_GetUsername();
    QString Dialog_Signup_GetPassword();

    /* 函数名 Dialog_Signup_Clear_Edits / Dialog_Signup_GetPassword
     * 用途：清空历史
    */
    void Dialog_Signup_Clear_Edits();

private slots:

    /* 函数名 Dialog_Signup_Success
     * 用途：注册成功
    */

    void Dialog_Signup_Success();

    /* 函数名 Dialog_Signup_ErrorTips
     * 用户名密码错误提示
    */

    void Dialog_Signup_ErrorTips();

    /* 函数名 Dialog_Signup_Language_ErrorTips
     * 语言资质错误提示
    */
    void Dialog_Signup_Language_ErrorTips();

    /* 函数名 Dialog_signup_Success_Info(); / Dialog_signup_Cancel_Info
     * 用途：注册成功 / 退出 提示信息
    */

    void Dialog_signup_Success_Info();
    void Dialog_signup_Cancel_Info();

private:
    Ui::Dialog_Signup *ui;
    QLabel *Dialog_Signup_Username_Label;
    QLabel *Dialog_Signup_Password_1_Label;
    QLabel *Dialog_Signup_Password_2_Label;
    QLabel *Dialog_Signup_ErrorTip_Label;
    QLabel *Dialog_Signup_Nickname_Label;
    QLabel *Dialog_Signup_Realname_Label;
    QLabel *Dialog_Signup_FreeSign_Label;
    QLabel *Dialog_Signup_Sex_Label;
    QLabel *Dialog_Signup_Age_Label;
    QLabel *Dialog_Signup_Address_Label;
    QLabel *Dialog_Signup_Address_Country_Label;
    QLabel *Dialog_Signup_Address_Province_Label;
    QLabel *Dialog_Signup_Address_City_Label;
    QLabel *Dialog_Signup_PhoneNumber_Label;
    QLabel *Dialog_Signup_Email_Label;
    QLabel *Dialog_Signup_ID_Number_Label;
    QLabel *Dialog_Signup_Language_Label;
    QLabel *Dialog_Signup_Language_Cet4_Label;
    QLabel *Dialog_Signup_Language_Cet6_Label;
    QLabel *Dialog_Signup_Language_Tem4_Label;
    QLabel *Dialog_Signup_Language_Tem8_Label;
    QLabel *Dialog_Signup_Language_Toefl_Label;
    QLabel *Dialog_Signup_Language_Ielts_Label;
    QLabel *Dialog_Signup_Language_Gre_Label;
    QLabel *Dialog_Signup_Language_ErrorTip_Label;
    QLineEdit *Dialog_Signup_Username_LineEdit;
    QLineEdit *Dialog_Signup_Password_1_LineEdit;
    QLineEdit *Dialog_Signup_Password_2_LineEdit;
    QLineEdit *Dialog_Signup_Nickname_LineEdit;
    QLineEdit *Dialog_Signup_Realname_LineEdit;
    QLineEdit *Dialog_Signup_FreeSign_LineEdit;
    QComboBox *Dialog_Signup_Sex_Combox;
    QLineEdit *Dialog_Signup_Age_LineEdit;
    QComboBox *Dialog_Signup_Address_Country_Combox;
    QComboBox *Dialog_Signup_Address_Province_Combox;
    QComboBox *Dialog_Signup_Address_City_Combox;
    QLineEdit *Dialog_Signup_PhoneNumber_LineEdit;
    QLineEdit *Dialog_Signup_Email_LineEdit;
    QLineEdit *Dialog_Signup_ID_Number_LineEdit;
    QLineEdit *Dialog_Signup_Language_Cet4_LineEdit;
    QLineEdit *Dialog_Signup_Language_Cet6_LineEdit;
    QLineEdit *Dialog_Signup_Language_Tem4_LineEdit;
    QLineEdit *Dialog_Signup_Language_Tem8_LineEdit;
    QLineEdit *Dialog_Signup_Language_Toefl_LineEdit;
    QLineEdit *Dialog_Signup_Language_Ielts_LineEdit;
    QLineEdit *Dialog_Signup_Language_Gre_LineEdit;
    QPushButton *Dialog_Signup_Confirm_Btn;
    QPushButton *Dialog_Signup_Cancel_Btn;

    QGridLayout *Dialog_Signup_UserInfo_Layout;
    QGridLayout *Dialog_Signup_UserSelf_Layout;
    QGridLayout *Dialog_Signup_Address_Layout;
    QGridLayout *Dialog_Signup_Language_Layout;
    QHBoxLayout *Dialog_Signup_Btn_Layout;
    QVBoxLayout *Dialog_Signup_Layout;

    QString Dialog_Signup_Username_Input;
    QString Dialog_Signup_Password_1_Input;
    QString Dialog_Signup_Password_2_Input;
    QString Dialog_Signup_Username_Enable;
    QString Dialog_Signup_Password_Enable;

    QString Dialog_Signup_CET4_Input;
    uint16_t Dialog_Signup_CET4_Enable;
    QString Dialog_Signup_CET6_Input;
    uint16_t Dialog_Signup_CET6_Enable;
    QString Dialog_Signup_TEM4_Input;
    uint16_t Dialog_Signup_TEM4_Enable;
    QString Dialog_Signup_TEM8_Input;
    uint16_t Dialog_Signup_TEM8_Enable;
    QString Dialog_Signup_TOEFL_Input;
    uint16_t Dialog_Signup_TOEFL_Enable;
    QString Dialog_Signup_IELTS_Input;
    uint16_t Dialog_Signup_IELTS_Enable;
    QString Dialog_Signup_GRE_Input;
    uint16_t Dialog_Signup_GRE_Enable;
    bool Dialog_Signup_Sex_Enable;
    QString Dialog_Signup_Sexs_Enable;

    bool Dialog_Signup_Enable;
    bool language_enable;
};

#endif // DIALOG_SIGNUP_H
