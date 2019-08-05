#include "dialog_main.h"
#include "ui_dialog_main.h"

//容器

extern User OnlineUser;
extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;


//构造

Dialog_Main::Dialog_Main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Main)
{
    ui->setupUi(this);


    //默认 state = 0, 用户名错误

    State = 0;
    SetState_0_New();
    Dialog_Main_0_User_Legal = 0;
    Dialog_Main_0_Match = 0;
    Dialog_Main_1_Datetime = new QDateTime(QDateTime::currentDateTime());
}


//析构

Dialog_Main::~Dialog_Main()
{
    delete ui;   
}



//获取状态 (0 == start) (1 == online)

bool Dialog_Main::GetState()
{
    return State;
}




//更改状态 (0 == start) (1 == online)

void Dialog_Main::ChangeState_0()
{
    State = 0;
    SetState_1_Delete();
    SetState_0_New();
}

void Dialog_Main::ChangeState_1()
{
    Dialog_Main_0_User_Legal = Dialog_Main_0_Username_exist();


    //存在的用户名和密码匹配

    if(! Dialog_Main_0_User_Legal){
        Login_Fail_Info_0();
    }
    else {
        Dialog_Main_0_Match = Dialog_Main_0_Match_It();
        if(! Dialog_Main_0_Match)Login_Fail_Info_1();
        else {
            State = 1;
            OnlineUser = Userinfo_Hash.find(Dialog_Main_0_Username).value();          
            SetState_0_Delete();
            SetState_1_New();
        }
    }
}



//注册

void Dialog_Main::Dialog_Signup_Show()
{
    Dialog_Sign_up.setWindowTitle(tr("Sign up for iTranslate"));
    Dialog_Sign_up.setMinimumWidth(1024);
    Dialog_Sign_up.Dialog_Signup_Clear_Edits();
    Dialog_Sign_up.show();
}


//登入登出的控件修改

void Dialog_Main::SetState_0_New()
{

    Dialog_Main_0_Welcome_Label = new QLabel(tr("welcome to the Center of Translate"));
    Dialog_Main_0_Username_Label = new QLabel(tr("Username:"));
    Dialog_Main_0_Username_LineEdit = new QLineEdit;
    Dialog_Main_0_Password_Label = new QLabel(tr("Password:"));
    Dialog_Main_0_Password_LineEdit = new QLineEdit;
    Dialog_Main_0_Password_LineEdit ->setEchoMode(QLineEdit::Password);
    Dialog_Main_0_Signup_Btn = new QPushButton(tr("Sign up"));
    Dialog_Main_0_Login_Btn = new QPushButton(tr("Log in"));
    Dialog_Main_0_Quit_Btn = new QPushButton(tr("Quit"));
    Dialog_Main_0_Admin_Btn = new QPushButton(tr("I 'm Admin"));
    Dialog_Main_0_Username_Layout = new QHBoxLayout;
    Dialog_Main_0_Password_Layout = new QHBoxLayout;
    Dialog_Main_0_Btn_Layout = new QHBoxLayout;
    Dialog_Main_0_Layout = new QVBoxLayout(this);
    Dialog_Main_0_Username_Layout ->addWidget(Dialog_Main_0_Username_Label);
    Dialog_Main_0_Username_Layout ->addWidget(Dialog_Main_0_Username_LineEdit);
    Dialog_Main_0_Password_Layout ->addWidget(Dialog_Main_0_Password_Label);
    Dialog_Main_0_Password_Layout ->addWidget(Dialog_Main_0_Password_LineEdit);
    Dialog_Main_0_Btn_Layout ->addWidget(Dialog_Main_0_Login_Btn);
    Dialog_Main_0_Btn_Layout ->addWidget(Dialog_Main_0_Quit_Btn);
    Dialog_Main_0_Layout->addWidget(Dialog_Main_0_Welcome_Label);
    Dialog_Main_0_Layout->addLayout(Dialog_Main_0_Username_Layout);
    Dialog_Main_0_Layout->addLayout(Dialog_Main_0_Password_Layout);
    Dialog_Main_0_Layout->addLayout(Dialog_Main_0_Btn_Layout);
    Dialog_Main_0_Layout ->addWidget(Dialog_Main_0_Signup_Btn);
    Dialog_Main_0_Layout ->addWidget(Dialog_Main_0_Admin_Btn);
    Dialog_Main_0_Username = Dialog_Main_0_Username_LineEdit ->text();
    Dialog_Main_0_Password = Dialog_Main_0_Password_LineEdit ->text();

    //登录

    connect(Dialog_Main_0_Login_Btn, SIGNAL(clicked()), this, SLOT(ChangeState_1()));

    //注册

    connect(Dialog_Main_0_Signup_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Signup_Show()));

    //全部关闭

    connect(Dialog_Main_0_Quit_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Main_Close()));

    //管理员登陆

    connect(Dialog_Main_0_Admin_Btn, SIGNAL(clicked()), this, SLOT(admin_start()));
}


void Dialog_Main::SetState_0_Delete()
{
    delete Dialog_Main_0_Welcome_Label;
    delete Dialog_Main_0_Username_Label;
    delete Dialog_Main_0_Username_LineEdit;
    delete Dialog_Main_0_Password_Label;
    delete Dialog_Main_0_Password_LineEdit;
    delete Dialog_Main_0_Signup_Btn;
    delete Dialog_Main_0_Login_Btn;
    delete Dialog_Main_0_Quit_Btn;
    delete Dialog_Main_0_Admin_Btn;
    delete Dialog_Main_0_Username_Layout;
    delete Dialog_Main_0_Password_Layout;
    delete Dialog_Main_0_Btn_Layout;
    delete Dialog_Main_0_Layout;
}


void Dialog_Main::SetState_1_New()
{   
    Dialog_Main_1_Label = new QLabel(tr("Online.") +
                                     Dialog_Main_1_Datetime ->date().toString() +
                                     Dialog_Main_1_Datetime ->time().toString());
    Dialog_Main_1_List_Label = new QListWidgetItem(tr("Check Info"));
    Dialog_Main_1_List = new QListWidget;
    Dialog_Main_1_List ->insertItem(0, Dialog_Main_1_List_Label);
    Dialog_Main_1_List ->insertItem(1, QObject::tr("Check Task"));
    Dialog_Main_1_List ->insertItem(2, QObject::tr("Messages"));
    Dialog_Main_1_Stack = new QStackedWidget;
    Dialog_Main_1_Userinfo = new Dialog_Main_Userinfo;
    Dialog_Main_1_Task = new Dialog_Main_Task;
    Dialog_Main_1_Message = new Dialog_Main_Message;
    Dialog_Main_1_Stack ->addWidget(Dialog_Main_1_Userinfo);
    Dialog_Main_1_Stack ->addWidget(Dialog_Main_1_Task);
    Dialog_Main_1_Stack ->addWidget(Dialog_Main_1_Message);
    Dialog_Main_1_Logout_Btn = new QPushButton(tr("Log out"));
    Dialog_Main_1_Quit_Btn = new QPushButton(tr("Quit"));
    Dialog_Main_1_Btn_Layout = new QHBoxLayout;
    Dialog_Main_1_Left_Layout = new QVBoxLayout;
    Dialog_Main_1_Right_Layout = new QVBoxLayout;
    Dialog_Main_1_Btn_Layout ->addWidget(Dialog_Main_1_Logout_Btn);
    Dialog_Main_1_Btn_Layout ->addWidget(Dialog_Main_1_Quit_Btn);
    Dialog_Main_1_Left_Layout ->addWidget(Dialog_Main_1_List);
    Dialog_Main_1_Right_Layout ->addWidget(Dialog_Main_1_Stack);
    Dialog_Main_1_Right_Layout ->addWidget(Dialog_Main_1_Label);
    Dialog_Main_1_Right_Layout ->addLayout(Dialog_Main_1_Btn_Layout);
    Dialog_Main_1_Layout = new QHBoxLayout(this);
    Dialog_Main_1_Layout ->addLayout(Dialog_Main_1_Left_Layout);
    Dialog_Main_1_Layout ->addLayout(Dialog_Main_1_Right_Layout);
    Dialog_Main_1_Layout ->setStretch(0, 1);
    Dialog_Main_1_Layout ->setStretch(1, 5);

    //3 lists: userinfo, tasks, messages
    connect(Dialog_Main_1_List, SIGNAL(currentRowChanged(int)),
            Dialog_Main_1_Stack, SLOT(setCurrentIndex(int)));

    //选中message 更新消息盒子

    connect(Dialog_Main_1_List, SIGNAL(currentRowChanged(int)),
            this, SLOT(message_fresh_main(int)));

    //登出

    connect(Dialog_Main_1_Logout_Btn, SIGNAL(clicked()), this, SLOT(ChangeState_0()));

    //关闭

    connect(Dialog_Main_1_Quit_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Main_Close()));

    //编辑个人信息和充值

    connect(Dialog_Main_1_Userinfo->Dialog_Main_Userinfo_Edit_Btn, SIGNAL(clicked()), this, SLOT(List_0_Tip()));
}


void Dialog_Main::SetState_1_Delete()
{
    delete Dialog_Main_1_List_Label;
    delete Dialog_Main_1_Label;
    delete Dialog_Main_1_Logout_Btn;
    delete Dialog_Main_1_Quit_Btn;
    delete Dialog_Main_1_List;
    delete Dialog_Main_1_Userinfo;
    delete Dialog_Main_1_Task;
    delete Dialog_Main_1_Stack;
    delete Dialog_Main_1_Btn_Layout;
    delete Dialog_Main_1_Left_Layout;
    delete Dialog_Main_1_Right_Layout;
    delete Dialog_Main_1_Layout;
}


//close all: QuitBtn || closeevent :: clicked()
void Dialog_Main::closeEvent(QCloseEvent *event)
{
    main0_admin.close();
    Dialog_Sign_up.close();
    Userinfo_Save();
}

void Dialog_Main::Dialog_Main_Close()
{
    Dialog_Sign_up.close();
    this ->close(); //= closeevent
}


//存入数据库

void Dialog_Main::Userinfo_Save()
{
    Connection_Userinfo_Into_Sql();
    Connection_Taskinfo_Into_Sql();
}


//登陆失败的提示

void Dialog_Main::Login_Fail_Info_0()
{
    QMessageBox::critical(this, "Error", "User not exist");
}

void Dialog_Main::Login_Fail_Info_1()
{
    QMessageBox::critical(this, "Error", "Password Wrong");
}



//检查用户名是否重叠及两次密码匹配

bool Dialog_Main::Dialog_Main_0_Username_exist()
{
    Dialog_Main_0_Username = Dialog_Main_0_Username_LineEdit ->text();
    return Userinfo_Hash.count(Dialog_Main_0_Username);
}

bool Dialog_Main::Dialog_Main_0_Match_It()
{
    Dialog_Main_0_Password = Dialog_Main_0_Password_LineEdit ->text();
    return (Dialog_Main_0_Password == Userinfo_Hash.find(Dialog_Main_0_Username).value().GetPassword());
}


//用户信息界面查看/编辑状态在列表项的提示

void Dialog_Main::List_0_Tip()
{
    if(Dialog_Main_1_Userinfo->Userinfo_GetState())Dialog_Main_1_List_Label ->setText(tr("[Edit] info"));
    else Dialog_Main_1_List_Label ->setText(tr("Check info"));
}


//刷新消息盒子

void Dialog_Main::message_fresh_main(int index)
{
    if(index == 0)    Dialog_Main_1_Userinfo ->changemoney();
    if(index == 2)Dialog_Main_1_Message ->message_fresh();
}


//管理员登陆

void Dialog_Main::admin_start()
{
    main0_admin.show();
    main0_admin.setWindowFlags(main0_admin.windowFlags() | Qt::WindowStaysOnTopHint);
}

