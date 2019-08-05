/* 文件名 dialog_main_userinfo.h
 * 用途  dialog_main_userinfo类 个人信息查看与编辑
*/

#ifndef Dialog_Main_Userinfo_H
#define Dialog_Main_Userinfo_H

#include <QWidget>
#include "project.h"
#include "user.h"

/* 类名  dialog_main_userinfo 个人信息查看与编辑
*/

class Dialog_Main_Userinfo : public QWidget
{
    Q_OBJECT
public:
    explicit Dialog_Main_Userinfo(QWidget *parent = nullptr);

    /* 函数名 Userinfo_State_0();  Userinfo_State_1();
     * 用途  个人信息查看与编辑 / 退出编辑
    */
    void Userinfo_State_0();
    void Userinfo_State_1();


    /* 函数名 Dialog_Changeinfo_Success_Info();  Dialog_Changeinfo_ExitEdit_Info();
     * 用途  提示框
    */
    void Dialog_Changeinfo_Success_Info();
    void Dialog_Changeinfo_ExitEdit_Info();

    /* 函数名 changemoney();
     * 用途  充值
    */
    void changemoney();

    /* 函数名 Userinfo_GetState();
    * 获取状态
    */

    bool Userinfo_GetState();

    QPushButton *Dialog_Main_Userinfo_Edit_Btn;

signals:

public slots:
    /* 函数名 Userinfo_ChangeState();
     * 用途  查看/编辑状态改变
    */
    void Userinfo_ChangeState();

    /* 函数名 Dialog_Changeinfo_Success();
     * 用途  修改成功
    */
    void Dialog_Changeinfo_Success();

    /* 函数名 Dialog_Changeinfo_ErrorTips();
     * 用途  用户名、密码错误信息
    */
    void Dialog_Changeinfo_ErrorTips();

    /* 函数名 Dialog_Changeinfo_Language_ErrorTips();
     * 用途  语言资质错误信息
    */
    void Dialog_Changeinfo_Language_ErrorTips();

    /* 函数名 charge;
     * 用途  充值
    */
    void charge();

private:
    bool Dialog_Main_Userinfo_State;
    //Tips
    QLabel *Dialog_Main_Userinfo_Username_Label;
    QLabel *Dialog_Main_Userinfo_Password_1_Label;
    QLabel *Dialog_Main_Userinfo_Nickname_Label;
    QLabel *Dialog_Main_Userinfo_Realname_Label;
    QLabel *Dialog_Main_Userinfo_FreeSign_Label;
    QLabel *Dialog_Main_Userinfo_Sex_Label;
    QLabel *Dialog_Main_Userinfo_Age_Label;
    QLabel *Dialog_Main_Userinfo_Address_Label;
    QLabel *Dialog_Main_Userinfo_Address_Country_Label;
    QLabel *Dialog_Main_Userinfo_Address_Province_Label;
    QLabel *Dialog_Main_Userinfo_Address_City_Label;
    QLabel *Dialog_Main_Userinfo_PhoneNumber_Label;
    QLabel *Dialog_Main_Userinfo_Email_Label;
    QLabel *Dialog_Main_Userinfo_ID_Number_Label;
    QLabel *Dialog_Main_Userinfo_Language_Label;
    QLabel *Dialog_Main_Userinfo_Language_Cet4_Label;
    QLabel *Dialog_Main_Userinfo_Language_Cet6_Label;
    QLabel *Dialog_Main_Userinfo_Language_Tem4_Label;
    QLabel *Dialog_Main_Userinfo_Language_Tem8_Label;
    QLabel *Dialog_Main_Userinfo_Language_Toefl_Label;
    QLabel *Dialog_Main_Userinfo_Language_Ielts_Label;
    QLabel *Dialog_Main_Userinfo_Language_Gre_Label;
    QLabel *Dialog_Main_Userinfo_Lan_Intergral_Label;
    QLabel *Dialog_Main_Userinfo_Tas_Intergral_Label;
    QLabel *Dialog_Main_Userinfo_Intergral_Label;
    QLabel *Dialog_Main_Userinfo_Money;
    QPushButton *Dialog_Main_Userinfo_Apply_Btn;

    //check state(0)
    QLabel *Dialog_Main_Userinfo_0_Username_Label;
    QLabel *Dialog_Main_Userinfo_0_Password_1_Label;
    QLabel *Dialog_Main_Userinfo_0_Nickname_Label;
    QLabel *Dialog_Main_Userinfo_0_Realname_Label;
    QLabel *Dialog_Main_Userinfo_0_FreeSign_Label;
    QLabel *Dialog_Main_Userinfo_0_Sex_Label;
    QLabel *Dialog_Main_Userinfo_0_Age_Label;
    QLabel *Dialog_Main_Userinfo_0_Address_Label;
    QLabel *Dialog_Main_Userinfo_0_Address_Country_Label;
    QLabel *Dialog_Main_Userinfo_0_Address_Province_Label;
    QLabel *Dialog_Main_Userinfo_0_Address_City_Label;
    QLabel *Dialog_Main_Userinfo_0_PhoneNumber_Label;
    QLabel *Dialog_Main_Userinfo_0_Email_Label;
    QLabel *Dialog_Main_Userinfo_0_ID_Number_Label;
    QLabel *Dialog_Main_Userinfo_0_Language_Label;
    QLabel *Dialog_Main_Userinfo_0_Language_Cet4_Label;
    QLabel *Dialog_Main_Userinfo_0_Language_Cet6_Label;
    QLabel *Dialog_Main_Userinfo_0_Language_Tem4_Label;
    QLabel *Dialog_Main_Userinfo_0_Language_Tem8_Label;
    QLabel *Dialog_Main_Userinfo_0_Language_Toefl_Label;
    QLabel *Dialog_Main_Userinfo_0_Language_Ielts_Label;
    QLabel *Dialog_Main_Userinfo_0_Language_Gre_Label;

    //edit state(1)
    QLabel *Dialog_Main_Userinfo_1_Password_2_Label;
    QLabel *Dialog_Main_Userinfo_1_ErrorTip_Label;
    QLabel *Dialog_Main_Userinfo_1_Language_ErrorTip_Label;
    QLineEdit *Dialog_Main_Userinfo_1_Username_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Password_1_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Password_2_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Nickname_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Realname_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_FreeSign_LineEdit;
    QComboBox *Dialog_Main_Userinfo_1_Sex_Combox;
    QLineEdit *Dialog_Main_Userinfo_1_Age_LineEdit;
    QComboBox *Dialog_Main_Userinfo_1_Address_Country_Combox;
    QComboBox *Dialog_Main_Userinfo_1_Address_Province_Combox;
    QComboBox *Dialog_Main_Userinfo_1_Address_City_Combox;
    QLineEdit *Dialog_Main_Userinfo_1_PhoneNumber_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Email_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_ID_Number_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Language_Cet4_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Language_Cet6_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Language_Tem4_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Language_Tem8_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Language_Toefl_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Language_Ielts_LineEdit;
    QLineEdit *Dialog_Main_Userinfo_1_Language_Gre_LineEdit;
    QPushButton *Dialog_Main_Userinfo_1_Money_Btn;

    QGridLayout *Dialog_Main_Userinfo_UserInfo_Layout;
    QGridLayout *Dialog_Main_Userinfo_UserSelf_Layout;
    QGridLayout *Dialog_Main_Userinfo_Address_Layout;
    QGridLayout *Dialog_Main_Userinfo_Language_Layout;
    QHBoxLayout *Dialog_Main_Userinfo_Btn_Layout;
    QVBoxLayout *Dialog_Main_Userinfo_Layout;

    //input informations
    QString Dialog_Main_Userinfo_1_Username_Input;
    QString Dialog_Main_Userinfo_1_Password_1_Input;
    QString Dialog_Main_Userinfo_1_Password_2_Input;
    QString Dialog_Main_Userinfo_1_Username_Enable;
    QString Dialog_Main_Userinfo_1_Password_Enable;
    QString Dialog_Main_Userinfo_1_CET4_Input;
    uint16_t Dialog_Main_Userinfo_1_CET4_Enable;
    uint16_t Dialog_Main_Userinfo_1_CET4_Enabled;
    QString Dialog_Main_Userinfo_1_CET6_Input;
    uint16_t Dialog_Main_Userinfo_1_CET6_Enable;
    uint16_t Dialog_Main_Userinfo_1_CET6_Enabled;
    QString Dialog_Main_Userinfo_1_TEM4_Input;
    uint16_t Dialog_Main_Userinfo_1_TEM4_Enable;
    uint16_t Dialog_Main_Userinfo_1_TEM4_Enabled;
    QString Dialog_Main_Userinfo_1_TEM8_Input;
    uint16_t Dialog_Main_Userinfo_1_TEM8_Enable;
    uint16_t Dialog_Main_Userinfo_1_TEM8_Enabled;
    QString Dialog_Main_Userinfo_1_TOEFL_Input;
    uint16_t Dialog_Main_Userinfo_1_TOEFL_Enable;
    uint16_t Dialog_Main_Userinfo_1_TOEFL_Enabled;
    QString Dialog_Main_Userinfo_1_IELTS_Input;
    uint16_t Dialog_Main_Userinfo_1_IELTS_Enable;
    uint16_t Dialog_Main_Userinfo_1_IELTS_Enabled;
    QString Dialog_Main_Userinfo_1_GRE_Input;
    uint16_t Dialog_Main_Userinfo_1_GRE_Enable;
    uint16_t Dialog_Main_Userinfo_1_GRE_Enabled;
    bool Dialog_Main_Userinfo_1_Sex_Enable;
    QString Dialog_Main_Userinfo_1_Sexs_Enable;

    bool Dialog_Main_Userinfo_1_Enable;
    bool Dialog_Main_Userinfo_1_language_enable;

    /* 函数名 SetState_Userinfo_0（/ 1）_New（/ Delete）;
     * 用途  状态切换的空间变化
    */
    void SetState_Userinfo_0_New();
    void SetState_Userinfo_1_New();
    void SetState_Userinfo_0_Delete();
    void SetState_Userinfo_1_Delete();
};

#endif // Dialog_Main_Userinfo_H
