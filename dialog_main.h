/* 文件名 dialog_main.h
 * 用途  定义 dialog_main 类： 操作主入口
*/

#ifndef DIALOG_MAIN_H
#define DIALOG_MAIN_H

#include "project.h"
#include "dialog_main_userinfo.h"
#include "dialog_main_task.h"
#include "dialog_main_message.h"
#include "dialog_signup.h"
#include "dialog_admin.h"
#include "connection_userinfo.h"
#include "connection_taskinfo.h"
#include "user.h"
#include "project.h"

namespace Ui {
class Dialog_Main;
}

/* 类名 dialog_admin
 * 用途  ： 操作主入口
*/

class Dialog_Main : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Main(QWidget *parent = nullptr);
    ~Dialog_Main();


    //成员main0_admin：平台管理员登录入口（新界面）

    dialog_admin main0_admin;

    //成员Dialog_Sign_up：登录入口（新界面）

    Dialog_Signup Dialog_Sign_up;



    /* 函数名 GetState（）
     * 用途  获取状态： 0：未登录 ；  1：有用户登陆
    */
    bool GetState();


    /* 函数名 Userinfo_Save（）
     * 用途  把所有新建和更新信息保存到数据库
    */
    void Userinfo_Save();


    /* 函数名 Dialog_Main_0_Username_exist（）
     * 用途  判断注册的用户名是否已经存在
    */
    bool Dialog_Main_0_Username_exist();


    /* 函数名 Dialog_Main_0_Match_It（）
     * 用途  判断注册的两次密码输入是否匹配
    */
    bool Dialog_Main_0_Match_It();


    /* 函数名 Login_Fail_Info_0（）  ；  Login_Fail_Info_1（）
     * 用途  判断登录信息是否正确， 给出错误提示   0：用户名不存在   1：密码错误
    */
    void Login_Fail_Info_0();
    void Login_Fail_Info_1();


protected:
    /* 函数名 closeEvent  （重写）
     * 用途  主界面关闭时完成信息到数据库的存储， 并关闭所有其他界面
    */
    void closeEvent(QCloseEvent *event);


private slots:
    /* 函数名 ChangeState_0 （）
     * 用途  用户登出
    */
    void ChangeState_0(); //in State 1, push Logout, change to State 0


    /* 函数名 ChangeState_1 （）
     * 用途  用户登入
    */
    void ChangeState_1(); //in State 0, push Login, change to State 1


    /* 函数名 Dialog_Signup_Show （）
     * 用途  打开用户注册界面
    */
    void Dialog_Signup_Show(); //in State 0, push Sign up, change to sign up


    /* 函数名 Dialog_Main_Close （）
     * 用途  关闭所有窗口并保存信息
    */
    void Dialog_Main_Close(); //close all


    /* 函数名 List_0_Tip （）
     * 用途  用户个人信息查看模式与编辑模式下左侧列表栏提醒
    */
    void List_0_Tip();


    /* 函数名 message_fresh_main （）
     * 用途  刷新消息盒子
    */
    void message_fresh_main(int index);


    /* 函数名 admin_start （）
     * 用途  打开平台管理员登陆界面
    */
    void admin_start();

private:
    Ui::Dialog_Main *ui;

    //主界面状态 0：无用户在线     1：有用户在线
    bool State;

    //State = 0 控件

    QLabel *Dialog_Main_0_Welcome_Label;
    QLabel *Dialog_Main_0_Username_Label;
    QLineEdit *Dialog_Main_0_Username_LineEdit;
    QLabel *Dialog_Main_0_Password_Label;
    QLineEdit *Dialog_Main_0_Password_LineEdit;
    QPushButton *Dialog_Main_0_Signup_Btn;
    QPushButton *Dialog_Main_0_Admin_Btn;
    QPushButton *Dialog_Main_0_Login_Btn;
    QPushButton *Dialog_Main_0_Quit_Btn;
    QHBoxLayout *Dialog_Main_0_Username_Layout;
    QHBoxLayout *Dialog_Main_0_Password_Layout;
    QHBoxLayout *Dialog_Main_0_Btn_Layout;
    QVBoxLayout *Dialog_Main_0_Layout;


     //State = 1 控件

    QLabel *Dialog_Main_1_Label;
    QDateTime *Dialog_Main_1_Datetime;
    QListWidgetItem *Dialog_Main_1_List_Label;
    QListWidget *Dialog_Main_1_List;
    QStackedWidget *Dialog_Main_1_Stack;
    Dialog_Main_Userinfo *Dialog_Main_1_Userinfo;
    Dialog_Main_Task *Dialog_Main_1_Task;
    Dialog_Main_Message *Dialog_Main_1_Message;
    QPushButton *Dialog_Main_1_Logout_Btn;
    QPushButton *Dialog_Main_1_Quit_Btn;
    QHBoxLayout *Dialog_Main_1_Btn_Layout;
    QVBoxLayout *Dialog_Main_1_Left_Layout;
    QVBoxLayout *Dialog_Main_1_Right_Layout;
    QHBoxLayout *Dialog_Main_1_Layout;

     //State = 0 输入信息及其合法性

    QString Dialog_Main_0_Username;
    QString Dialog_Main_0_Password;
    bool Dialog_Main_0_User_Legal;
    bool Dialog_Main_0_Match;



    /* 函数名 SetState_0_New（）  SetState_1_New（）
     * SetState_0_Delete（）  SetState_1_Delete（）
     * 用途  用户登入登出的控件切换
    */
    void SetState_0_New();
    void SetState_1_New();
    void SetState_0_Delete();
    void SetState_1_Delete();

};

#endif // DIALOG_MAIN_H
