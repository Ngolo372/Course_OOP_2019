#include "dialog_signup.h"
#include "ui_dialog_signup.h"

extern User OnlineUser;
extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;
extern QHash <int, int> Link_Task_Hash[1000];
extern QHash <int, int>::const_iterator Link_Task_Hash_iter;
extern QHash <QString, QHash<int, int>>Link_usertask_Hash;
extern QHash <QString, QHash<int, int>>::const_iterator Link_usertask_Hash_iter;
extern QHash <QString, QQueue<message>>Message_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_Hash_iter;
extern QHash <QString, QQueue<message>>Message_New_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_New_Hash_iter;
extern QQueue<message> Message_Queue[1000];
extern QQueue<message> Message_New_Queue[1000];
extern QHash <QString, QQueue<message>>Message_NewState_Hash;
extern QHash <QString, QQueue<message>>::const_iterator Message_NewState_Hash_iter;
//extern QQueue<message> Message_Queue[1000];
//extern QQueue<message> Message_New_Queue[1000];
extern QQueue<message> Message_NewState_Queue[1000];


Dialog_Signup::Dialog_Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Signup)
{
    ui->setupUi(this);

    Dialog_Signup_Username_Label = new QLabel(tr("Username*:"));
    Dialog_Signup_Password_1_Label = new QLabel(tr("Password*:"));
    Dialog_Signup_Password_2_Label = new QLabel(tr("Confirm Password*"));
    Dialog_Signup_ErrorTip_Label = new QLabel("*Error: username must more than 5 letter or numbers");
    Dialog_Signup_Nickname_Label = new QLabel(tr("Nickname:"));
    Dialog_Signup_Realname_Label = new QLabel(tr("Realname:"));
    Dialog_Signup_FreeSign_Label = new QLabel(tr("FreeSign:"));
    Dialog_Signup_Sex_Label = new QLabel(tr("Sex:"));
    Dialog_Signup_Age_Label = new QLabel(tr("Age:"));
    Dialog_Signup_Address_Label = new QLabel(tr("Address"));
    Dialog_Signup_Address_Country_Label = new QLabel(tr("Country:"));
    Dialog_Signup_Address_Province_Label = new QLabel(tr("Province:"));
    Dialog_Signup_Address_City_Label = new QLabel(tr("City:"));
    Dialog_Signup_PhoneNumber_Label = new QLabel(tr("Phone Number:"));
    Dialog_Signup_Email_Label = new QLabel(tr("Email:"));
    Dialog_Signup_ID_Number_Label = new QLabel(tr("ID Number:"));
    Dialog_Signup_Language_Label = new QLabel(tr("Language Qualifies:"));
    Dialog_Signup_Language_Cet4_Label = new QLabel(tr("CET4 Score:"));
    Dialog_Signup_Language_Cet6_Label = new QLabel(tr("CET6 Score:"));
    Dialog_Signup_Language_Tem4_Label = new QLabel(tr("TEM4 Score:"));
    Dialog_Signup_Language_Tem8_Label = new QLabel(tr("TEM8 Score:"));
    Dialog_Signup_Language_Toefl_Label = new QLabel(tr("TOEFL Score:"));
    Dialog_Signup_Language_Ielts_Label = new QLabel(tr("IELTS Score:"));
    Dialog_Signup_Language_Gre_Label = new QLabel(tr("GRE Score:"));
    Dialog_Signup_Language_ErrorTip_Label = new QLabel(tr("OK"));

    Dialog_Signup_Username_LineEdit = new QLineEdit;
    Dialog_Signup_Password_1_LineEdit = new QLineEdit;
    Dialog_Signup_Password_2_LineEdit = new QLineEdit;
    Dialog_Signup_Password_1_LineEdit ->setEchoMode(QLineEdit::Password);
    Dialog_Signup_Password_2_LineEdit ->setEchoMode(QLineEdit::Password);
    Dialog_Signup_Nickname_LineEdit = new QLineEdit;
    Dialog_Signup_Realname_LineEdit = new QLineEdit;
    Dialog_Signup_FreeSign_LineEdit = new QLineEdit;

    Dialog_Signup_Sex_Combox = new QComboBox;
    Dialog_Signup_Sex_Combox ->insertItem(0, tr("Male"));
    Dialog_Signup_Sex_Combox ->insertItem(1, tr("Female"));

    Dialog_Signup_Age_LineEdit = new QLineEdit;
    Dialog_Signup_Address_Country_Combox = new QComboBox;
    Dialog_Signup_Address_Province_Combox = new QComboBox;
    Dialog_Signup_Address_City_Combox = new QComboBox;
    Dialog_Signup_PhoneNumber_LineEdit = new QLineEdit;
    Dialog_Signup_Email_LineEdit = new QLineEdit;
    Dialog_Signup_ID_Number_LineEdit = new QLineEdit;
    Dialog_Signup_Language_Cet4_LineEdit = new QLineEdit;
    Dialog_Signup_Language_Cet6_LineEdit = new QLineEdit;
    Dialog_Signup_Language_Tem4_LineEdit = new QLineEdit;
    Dialog_Signup_Language_Tem8_LineEdit = new QLineEdit;
    Dialog_Signup_Language_Toefl_LineEdit = new QLineEdit;
    Dialog_Signup_Language_Ielts_LineEdit = new QLineEdit;
    Dialog_Signup_Language_Gre_LineEdit = new QLineEdit;
    Dialog_Signup_Confirm_Btn = new QPushButton(tr("Confirm"));
    Dialog_Signup_Cancel_Btn = new QPushButton(tr("Cancel"));
    Dialog_Signup_Confirm_Btn ->setEnabled(0);

    Dialog_Signup_UserInfo_Layout = new QGridLayout;
    Dialog_Signup_UserSelf_Layout = new QGridLayout;
    Dialog_Signup_Address_Layout = new QGridLayout;
    Dialog_Signup_Language_Layout = new QGridLayout;
    Dialog_Signup_Btn_Layout = new QHBoxLayout;
    Dialog_Signup_Layout = new QVBoxLayout(this);

    Dialog_Signup_UserInfo_Layout ->addWidget(Dialog_Signup_Username_Label, 0, 0);
    Dialog_Signup_UserInfo_Layout ->addWidget(Dialog_Signup_Password_1_Label, 1, 0);
    Dialog_Signup_UserInfo_Layout ->addWidget(Dialog_Signup_Password_2_Label, 2, 0);
    Dialog_Signup_UserInfo_Layout ->addWidget(Dialog_Signup_Username_LineEdit, 0, 1);
    Dialog_Signup_UserInfo_Layout ->addWidget(Dialog_Signup_Password_1_LineEdit, 1, 1);
    Dialog_Signup_UserInfo_Layout ->addWidget(Dialog_Signup_Password_2_LineEdit, 2, 1);
    Dialog_Signup_UserInfo_Layout ->addWidget(Dialog_Signup_ErrorTip_Label, 3, 0, 1, 2);

    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_Nickname_Label, 0, 0);
    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_Realname_Label, 1, 0);
    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_FreeSign_Label, 2, 0);
    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_Sex_Label, 3, 0);
    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_Age_Label, 4, 0);
    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_Nickname_LineEdit, 0, 1);
    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_Realname_LineEdit, 1, 1);
    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_FreeSign_LineEdit, 2, 1);
    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_Sex_Combox, 3, 1);
    Dialog_Signup_UserSelf_Layout ->addWidget(Dialog_Signup_Age_LineEdit, 4, 1);

//    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_Address_Label, 0, 1);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_Address_Country_Label, 1, 0);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_Address_Province_Label, 2, 0);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_Address_City_Label, 3, 0);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_Address_Country_Combox, 1, 1);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_Address_Province_Combox, 2, 1);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_Address_City_Combox, 3, 1);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_PhoneNumber_Label, 1, 2);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_Email_Label, 2, 2);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_ID_Number_Label, 3, 2);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_PhoneNumber_LineEdit, 1, 3);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_Email_LineEdit, 2, 3);
    Dialog_Signup_Address_Layout ->addWidget(Dialog_Signup_ID_Number_LineEdit, 3, 3);

    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Cet4_Label, 1, 0);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Cet6_Label, 2, 0);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Tem4_Label, 3, 0);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Tem8_Label, 4, 0);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Toefl_Label, 1, 2);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Ielts_Label, 2, 2);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Gre_Label, 3, 2);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Cet4_LineEdit, 1, 1);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Cet6_LineEdit, 2, 1);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Tem4_LineEdit, 3, 1);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Tem8_LineEdit, 4, 1);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Toefl_LineEdit, 1, 3);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Ielts_LineEdit, 2, 3);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_Gre_LineEdit, 3, 3);
    Dialog_Signup_Language_Layout ->addWidget(Dialog_Signup_Language_ErrorTip_Label, 4, 2, 1, 2);

    Dialog_Signup_Btn_Layout ->addWidget(Dialog_Signup_Confirm_Btn);
    Dialog_Signup_Btn_Layout ->addWidget(Dialog_Signup_Cancel_Btn);

    Dialog_Signup_Layout ->addLayout(Dialog_Signup_UserInfo_Layout);
    Dialog_Signup_Layout ->addLayout(Dialog_Signup_UserSelf_Layout);
    Dialog_Signup_Layout ->addLayout(Dialog_Signup_Address_Layout);
    Dialog_Signup_Layout ->addLayout(Dialog_Signup_Language_Layout);
    Dialog_Signup_Layout ->addLayout(Dialog_Signup_Btn_Layout);
    Dialog_Signup_Layout ->setSpacing(25);

    Dialog_Signup_Enable = 0;
    language_enable = 1;

    connect(Dialog_Signup_Confirm_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Signup_Success()));
    connect(Dialog_Signup_Confirm_Btn, SIGNAL(clicked()), this, SLOT(Dialog_signup_Success_Info()));
    connect(Dialog_Signup_Cancel_Btn, SIGNAL(clicked()), this, SLOT(Dialog_signup_Cancel_Info()));
    connect(Dialog_Signup_Confirm_Btn, SIGNAL(clicked()), this, SLOT(close()));

    connect(Dialog_Signup_Username_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Signup_ErrorTips()));
    connect(Dialog_Signup_Password_1_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Signup_ErrorTips()));
    connect(Dialog_Signup_Password_2_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Signup_ErrorTips()));
    connect(Dialog_Signup_Language_Cet4_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Signup_Language_ErrorTips()));
    connect(Dialog_Signup_Language_Cet6_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Signup_Language_ErrorTips()));
    connect(Dialog_Signup_Language_Tem4_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Signup_Language_ErrorTips()));
    connect(Dialog_Signup_Language_Tem8_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Signup_Language_ErrorTips()));
}

Dialog_Signup::~Dialog_Signup()
{
    delete ui;
    qDebug() << "Dialog_Signup destructed";
}

//get Username
QString Dialog_Signup::Dialog_Signup_GetUsername()
{
    return Dialog_Signup_Username_Enable;
}

//get Password
QString Dialog_Signup::Dialog_Signup_GetPassword()
{
    return Dialog_Signup_Password_Enable;
}

//Sign up successfully, save the Userinfo
void Dialog_Signup::Dialog_Signup_Success()
{
    if(Dialog_Signup_Enable){
        Dialog_Signup_Username_Enable = Dialog_Signup_Username_Input;
        Dialog_Signup_Password_Enable = Dialog_Signup_Password_1_Input;
        Dialog_Signup_Sex_Enable = Dialog_Signup_Sex_Combox ->currentIndex();
        Dialog_Signup_Sexs_Enable = Dialog_Signup_Sex_Enable == 0 ? "Male" : "Female";

        Dialog_Signup_CET4_Input = Dialog_Signup_Language_Cet4_LineEdit ->text();
        Dialog_Signup_CET6_Input = Dialog_Signup_Language_Cet6_LineEdit ->text();
        Dialog_Signup_TEM4_Input = Dialog_Signup_Language_Tem4_LineEdit ->text();
        Dialog_Signup_TEM8_Input = Dialog_Signup_Language_Tem8_LineEdit ->text();

        User User_Enable;
        User_Enable.SetUsername(Dialog_Signup_Username_Enable);
        User_Enable.SetPassword(Dialog_Signup_Password_Enable);
        User_Enable.SetSex(Dialog_Signup_Sex_Enable);
        User_Enable.set_cet4_score(Dialog_Signup_CET4_Enable);
        User_Enable.set_cet6_score(Dialog_Signup_CET6_Enable);
        User_Enable.set_tem4_score(Dialog_Signup_TEM4_Enable);
        User_Enable.set_tem8_score(Dialog_Signup_TEM8_Enable);
        User_Enable.Set_User_Language_Intergral();
        User_Enable.Set_User_Intergral();
        User_Enable.SetMoney(0);
        User_Enable.Signupflag = 1;

        Userinfo_Hash.insert(User_Enable.GetUsername(), User_Enable);
        Link_usertask_Hash.insert(User_Enable.GetUsername(), Link_Task_Hash[Link_usertask_Hash.size() + 1]);
        Message_Hash.insert(User_Enable.GetUsername(), Message_Queue[Message_Hash.size() + 1]);
        Message_New_Hash.insert(User_Enable.GetUsername(), Message_New_Queue[Message_New_Hash.size() + 1]);
        Message_NewState_Hash .insert(User_Enable.GetUsername(), Message_NewState_Queue[Message_NewState_Hash.size() + 1]);


        qDebug() << "new user" << Dialog_Signup_Username_Enable
                 << "password" << Dialog_Signup_Password_Enable
                 << "sex" << Dialog_Signup_Sexs_Enable
                 << "cet4" << Dialog_Signup_CET4_Enable << User_Enable.get_cet4_level()
                 << "integral" << User_Enable.Get_User_Language_Intergral() << User_Enable.Get_User_Tasks_Intergral() << User_Enable.Get_User_Intergral();
    }
}

//show Error Tips about Username and Password
void Dialog_Signup::Dialog_Signup_ErrorTips()
{
    Dialog_Signup_Enable = 1;

    Dialog_Signup_Username_Input = Dialog_Signup_Username_LineEdit ->text();
    Dialog_Signup_Password_1_Input = Dialog_Signup_Password_1_LineEdit ->text();
    Dialog_Signup_Password_2_Input = Dialog_Signup_Password_2_LineEdit ->text();

    bool username_existed = 0;
    if(Userinfo_Hash.count(Dialog_Signup_Username_Input))username_existed = 1;

    bool password_match = (Dialog_Signup_Password_1_Input == Dialog_Signup_Password_2_Input);
    bool username_illegal_tooshort = (Dialog_Signup_Username_Input.length() < 5);
    bool username_illegal_toolong = (16 < Dialog_Signup_Username_Input.length());
    bool username_illegal_chars = 0;
    bool password_illegal_tooshort = (Dialog_Signup_Password_1_Input.length() < 5);
    bool password_illegal_toolong = (16 < Dialog_Signup_Password_1_Input.length());
    bool password_illegal_chars = 0;
    bool username_same_password = (Dialog_Signup_Username_Input == Dialog_Signup_Password_1_Input);
    for(int i = 0; i < Dialog_Signup_Username_Input.length(); i++){
        if(Dialog_Signup_Username_Input.mid(i, 1) < 48)username_illegal_chars = 1;
        else if(57 < Dialog_Signup_Username_Input.mid(i, 1) && Dialog_Signup_Username_Input.mid(i, 1) < 65)username_illegal_chars = 1;
        else if(90 < Dialog_Signup_Username_Input.mid(i, 1) && Dialog_Signup_Username_Input.mid(i, 1) < 97)username_illegal_chars = 1;
        else if(122 < Dialog_Signup_Username_Input.mid(i, 1))username_illegal_chars = 1;
    }
    for(int i = 0; i < Dialog_Signup_Password_1_Input.length(); i++){
        if(Dialog_Signup_Password_1_Input.mid(i, 1) < 48)password_illegal_chars = 1;
        else if(57 < Dialog_Signup_Password_1_Input.mid(i, 1) && Dialog_Signup_Password_1_Input.mid(i, 1) < 65)password_illegal_chars = 1;
        else if(90 < Dialog_Signup_Password_1_Input.mid(i, 1) && Dialog_Signup_Password_1_Input.mid(i, 1) < 97)password_illegal_chars = 1;
        else if(122 < Dialog_Signup_Password_1_Input.mid(i, 1))password_illegal_chars = 1;
    }

    Dialog_Signup_Enable = (!username_illegal_tooshort) && (!username_illegal_toolong) && (!username_illegal_chars)
            && (!password_illegal_tooshort) && (!password_illegal_toolong) && (!password_illegal_chars)
            && (password_match) && (!username_same_password) && (!username_existed);
    if(username_existed)Dialog_Signup_ErrorTip_Label ->setText("Error: username existed, please change");
    else if(username_illegal_tooshort)Dialog_Signup_ErrorTip_Label ->setText("Error: username must more than 5 letter or numbers");
    else if(username_illegal_chars)Dialog_Signup_ErrorTip_Label ->setText("Error: illegal username: only letters or numbers");
    else if(username_illegal_toolong)Dialog_Signup_ErrorTip_Label ->setText("Error: username must less than 16 letter or numbers");
    else if(password_illegal_tooshort)Dialog_Signup_ErrorTip_Label ->setText("Error: password must more than 5 letter or numbers");
    else if(password_illegal_chars)Dialog_Signup_ErrorTip_Label ->setText("Error: illegal password: only letters or numbers");
    else if(password_illegal_toolong)Dialog_Signup_ErrorTip_Label ->setText("Error: password must less than 16 letter or numbers");
    else if(!password_match)Dialog_Signup_ErrorTip_Label ->setText("Error: password unmatch");
    else if(username_same_password)Dialog_Signup_ErrorTip_Label ->setText("Error: username == password, please modify at least one");
    else Dialog_Signup_ErrorTip_Label ->setText("no errors");

    if(Dialog_Signup_Enable && language_enable)Dialog_Signup_Confirm_Btn ->setEnabled(1);
    else Dialog_Signup_Confirm_Btn ->setEnabled(0);
}

//tip: signup success || cancel
void Dialog_Signup::Dialog_signup_Success_Info()
{
    QMessageBox::information(this, "Success", "New user Created",
                             QMessageBox::Ok, QMessageBox::NoButton);
}

void Dialog_Signup::Dialog_signup_Cancel_Info()
{
    if(QMessageBox::Yes == QMessageBox::question(this, "Quit" ,"Sure to cancel, not saved",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::No))
        this ->close();
}

//tip:language informations error
void Dialog_Signup::Dialog_Signup_Language_ErrorTips()
{
    Dialog_Signup_CET4_Input = Dialog_Signup_Language_Cet4_LineEdit ->text();
    Dialog_Signup_CET6_Input = Dialog_Signup_Language_Cet6_LineEdit ->text();
    Dialog_Signup_TEM4_Input = Dialog_Signup_Language_Tem4_LineEdit ->text();
    Dialog_Signup_TEM8_Input = Dialog_Signup_Language_Tem8_LineEdit ->text();
    Dialog_Signup_TOEFL_Input = Dialog_Signup_Language_Toefl_LineEdit ->text();
    Dialog_Signup_IELTS_Input = Dialog_Signup_Language_Ielts_LineEdit ->text();
    Dialog_Signup_GRE_Input = Dialog_Signup_Language_Gre_LineEdit ->text();

    language_enable = 0;
    bool cet4_enable = 1;
    bool cet6_enable = 1;
    bool tem4_enable = 1;
    bool tem8_enable = 1;
    bool toefl_enable = 1;
    bool ielts_enable = 1;
    bool gre_enable = 1;

    if(3 < Dialog_Signup_CET4_Input.length())cet4_enable = 0;
    if(cet4_enable == 1){
        for (int i = 0; i < Dialog_Signup_CET4_Input.length(); i++) {
            if(Dialog_Signup_CET4_Input.mid(i, 1) < 48 || 57 < Dialog_Signup_CET4_Input.mid(i, 1))
                cet4_enable = 0;
        }
    }
    if(cet4_enable == 1){
        Dialog_Signup_CET4_Enable = 0;
        int powerbase = 1;
        for(int i = 0; i < Dialog_Signup_CET4_Input.length(); i++){
            Dialog_Signup_CET4_Enable += (Dialog_Signup_CET4_Input.mid(Dialog_Signup_CET4_Input.length() - i - 1, 1).toShort()) * powerbase;
        powerbase *= 10;
        }
    }
    cet4_enable = cet4_enable && (Dialog_Signup_CET4_Enable <= 710);

    if(3 < Dialog_Signup_CET6_Input.length())cet6_enable = 0;
    if(cet6_enable == 1){
        for (int i = 0; i < Dialog_Signup_CET6_Input.length(); i++) {
            if(Dialog_Signup_CET6_Input.mid(i, 1) < 48 || 57 < Dialog_Signup_CET6_Input.mid(i, 1))
                cet6_enable = 0;
        }
    }
    if(cet6_enable == 1){
        Dialog_Signup_CET6_Enable = 0;
        int powerbase = 1;
        for(int i = 0; i < Dialog_Signup_CET6_Input.length(); i++){
            Dialog_Signup_CET6_Enable += (Dialog_Signup_CET6_Input.mid(Dialog_Signup_CET6_Input.length() - i - 1, 1).toShort()) * powerbase;
        powerbase *= 10;
        }
    }
    cet6_enable = cet6_enable && (Dialog_Signup_CET6_Enable <= 710);

    if(3 < Dialog_Signup_TEM4_Input.length())tem4_enable = 0;
    if(tem4_enable == 1){
        for (int i = 0; i < Dialog_Signup_TEM4_Input.length(); i++) {
            if(Dialog_Signup_TEM4_Input.mid(i, 1) < 48 || 57 < Dialog_Signup_TEM4_Input.mid(i, 1))
                tem4_enable = 0;
        }
    }
    if(tem4_enable == 1){
        Dialog_Signup_TEM4_Enable = 0;
        int powerbase = 1;
        for(int i = 0; i < Dialog_Signup_TEM4_Input.length(); i++){
            Dialog_Signup_TEM4_Enable += (Dialog_Signup_TEM4_Input.mid(Dialog_Signup_TEM4_Input.length() - i - 1, 1).toShort()) * powerbase;
        powerbase *= 10;
        }
    }
    tem4_enable = tem4_enable && (Dialog_Signup_TEM4_Enable <= 100);

    if(3 < Dialog_Signup_TEM8_Input.length())tem8_enable = 0;
    if(tem8_enable == 1){
        for (int i = 0; i < Dialog_Signup_TEM8_Input.length(); i++) {
            if(Dialog_Signup_TEM8_Input.mid(i, 1) < 48 || 57 < Dialog_Signup_TEM8_Input.mid(i, 1))
                tem8_enable = 0;
        }
    }
    if(tem8_enable == 1){
        Dialog_Signup_TEM8_Enable = 0;
        int powerbase = 1;
        for(int i = 0; i < Dialog_Signup_TEM8_Input.length(); i++){
            Dialog_Signup_TEM8_Enable += (Dialog_Signup_TEM8_Input.mid(Dialog_Signup_TEM8_Input.length() - i - 1, 1).toShort()) * powerbase;
        powerbase *= 10;
        }
    }
    tem8_enable = tem8_enable && (Dialog_Signup_TEM8_Enable <= 100);

    language_enable = cet4_enable && cet6_enable &&
            tem4_enable && tem8_enable && toefl_enable &&
            ielts_enable &&gre_enable;

//    qDebug() << Dialog_Signup_Enable << language_enable;
    if(cet4_enable == 0)Dialog_Signup_Language_ErrorTip_Label ->setText("Error: CET4");
    else if(cet6_enable == 0)Dialog_Signup_Language_ErrorTip_Label ->setText("Error: CET6");
    else if(tem4_enable == 0)Dialog_Signup_Language_ErrorTip_Label ->setText("Error: TEM4");
    else if(tem8_enable == 0)Dialog_Signup_Language_ErrorTip_Label ->setText("Error: TEM8");
    else Dialog_Signup_Language_ErrorTip_Label ->setText("OK..");
    if(language_enable && Dialog_Signup_Enable)Dialog_Signup_Confirm_Btn ->setEnabled(1);
    else Dialog_Signup_Confirm_Btn ->setEnabled(0);

//    qDebug() << Dialog_Signup_CET4_Enable;
}

//when open signup, clear the texts
void Dialog_Signup::Dialog_Signup_Clear_Edits()
{
    Dialog_Signup_Username_LineEdit ->clear();
    Dialog_Signup_Password_1_LineEdit ->clear();
    Dialog_Signup_Password_2_LineEdit ->clear();
    Dialog_Signup_Nickname_LineEdit ->clear();
    Dialog_Signup_Realname_LineEdit ->clear();
    Dialog_Signup_FreeSign_LineEdit ->clear();
    Dialog_Signup_Age_LineEdit ->clear();
    Dialog_Signup_PhoneNumber_LineEdit ->clear();
    Dialog_Signup_Email_LineEdit ->clear();
    Dialog_Signup_ID_Number_LineEdit ->clear();
    Dialog_Signup_Language_Cet4_LineEdit ->clear();
    Dialog_Signup_Language_Cet6_LineEdit ->clear();
    Dialog_Signup_Language_Tem4_LineEdit ->clear();
    Dialog_Signup_Language_Tem8_LineEdit ->clear();
    Dialog_Signup_Language_Toefl_LineEdit ->clear();
    Dialog_Signup_Language_Ielts_LineEdit ->clear();
    Dialog_Signup_Language_Gre_LineEdit ->clear();
}
