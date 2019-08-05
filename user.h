//用户

#ifndef USER_H
#define USER_H
#include "project.h"
#include "user_language_qualification.h"

class User :public User_Language_Qualification
{
public:
    User();
    ~User();

    QString GetUsername() const;
    QString GetPassword() const;
    QString GetNickname() const;
    QString GetRealname() const;
    QString GetFreeSign() const;
    int GetAge() const;
    bool GetSex() const;
    void SetUsername(const QString NewUsername);
    void SetPassword(const QString NewPassword);
    void SetNickname(const QString NewNickname);
    void SetRealname(const QString NewRealname);
    void SetFreeSign(const QString NewFreeSign);
    void SetAge(const int NewAge);
    void SetSex(const bool NewSex);
    void SetMoney(int NewMoney);
    void AddMoney(double AMoney);
    void SubMoney(double SMoney);

    void Set_User_Language_Intergral();
    void Set_User_Task_Integral(int i);
    void Add_User_Task_Integral(int i);

    void Set_User_Intergral();
    void Set_User_Intergral(int i);
    int Get_User_Language_Intergral() const;
    int Get_User_Tasks_Intergral() const;
    int Get_User_Intergral() const;
    double Get_User_Money()const;
    int Get_User_Money_int()const;
    void UserBuild();

    //更新& 新建 标志位

    bool Changeinfoflag[28];
    bool Signupflag;

    //余额存储： 内存中为double， 数据库中 * 100 存 int

    int User_Money;
    double User_Money_Fact;
private:
    QString User_Username;
    QString User_Password;
    QString User_Nickname;
    QString User_Realname;
    QString User_FreeSign;
    int User_Age;
    bool User_Sex;
    QString User_ID_Number;
    QString User_Email;
    long int User_Phonenumber;
    int User_Language_Intergral;
    int User_Tasks_Intergral;
    int User_Intergral;

};

#endif // USER_H
