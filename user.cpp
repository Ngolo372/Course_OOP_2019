#include "user.h"

User::User()
{
    for (int i = 0; i < 28; i++) {
        Changeinfoflag[i] = 0;
    }
    Signupflag = 0;
    User_Language_Intergral = 0;
    User_Tasks_Intergral = 0;
    User_Intergral = 0;
    User_Nickname = QString("");
    User_Realname = QString("");
    User_FreeSign = QString("");
    User_Age = 0;
    User_Sex = 0;
    User_ID_Number = QString("");
    User_Email = QString("");
    User_Phonenumber = 0;
    User_Money = 0;
}

User::~User()
{

}

//get the infomations
QString User::GetUsername() const {
    return User_Username;
}

QString User::GetPassword() const {
    return User_Password;
}

QString User::GetNickname() const {
    return User_Nickname;
}

QString User::GetRealname() const {
    return User_Realname;
}

QString User::GetFreeSign() const {
    return User_FreeSign;
}

int User::GetAge() const {
    return User_Age;
}

bool User::GetSex() const {
    return User_Sex;
}

//set the information
void User::SetUsername(const QString NewUsername){
    User_Username = NewUsername;
}

void User::SetPassword(const QString NewPassword){
    User_Password = NewPassword;
}

void User::SetNickname(const QString NewNickname){
    User_Nickname = NewNickname;
}

void User::SetRealname(const QString NewRealname){
    User_Realname = NewRealname;
}

void User::SetFreeSign(const QString NewFreeSign){
    User_FreeSign = NewFreeSign;
}

void User::SetAge(const int NewAge){
    User_Age = NewAge;
}

void User::SetSex(const bool NewSex){
    User_Sex = NewSex;
}

//actions about the intergrals
int User::Get_User_Intergral()const {
    return User_Intergral;
}

void User::Set_User_Language_Intergral(){
    User_Language_Intergral = get_cet4_score() * 4 +
            get_cet6_score() * 4 +
            get_tem4_score() * 30 +
            get_tem8_score() * 30 +
            get_toefl_score() * 30 +
            get_ielts_score() * 400 +
            get_gre_score() * 10;
}


int User::Get_User_Tasks_Intergral()const {
    return User_Tasks_Intergral;
}

int User::Get_User_Language_Intergral()const{
    return User_Language_Intergral;
}

void User::Set_User_Task_Integral(int i)
{
    User_Tasks_Intergral = i;
}

void User::Add_User_Task_Integral(int i)
{
    User_Tasks_Intergral += i;
}


void User::Set_User_Intergral(){
    User_Intergral = User_Language_Intergral + User_Tasks_Intergral;
}

void User::Set_User_Intergral(int i){
    User_Intergral = i;
}

//deal with money
void User::SetMoney(int NewMoney)
{
    User_Money = NewMoney;
    User_Money_Fact = 0.01 * User_Money;
}

void User::AddMoney(double AMoney)
{
    User_Money_Fact += AMoney;
    User_Money = 100 * int(User_Money_Fact);
}

void User::SubMoney(double SMoney)
{
    User_Money_Fact -= SMoney;
    User_Money = 100 * int(User_Money_Fact);
}

double User::Get_User_Money() const
{
    return User_Money_Fact;
}

int User::Get_User_Money_int() const
{
    return User_Money;
}
