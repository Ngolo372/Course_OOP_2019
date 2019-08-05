#include "dialog_main_userinfo.h"


extern User OnlineUser;
extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;

Dialog_Main_Userinfo::Dialog_Main_Userinfo(QWidget *parent) : QWidget(parent)
{
    Dialog_Main_Userinfo_State = 0;
    Dialog_Main_Userinfo_Username_Label = new QLabel(tr("Username*:"));
    Dialog_Main_Userinfo_Password_1_Label = new QLabel(tr("Password*:"));
    Dialog_Main_Userinfo_Nickname_Label = new QLabel(tr("Nickname:"));
    Dialog_Main_Userinfo_Realname_Label = new QLabel(tr("Realname:"));
    Dialog_Main_Userinfo_FreeSign_Label = new QLabel(tr("FreeSign:"));
    Dialog_Main_Userinfo_Sex_Label = new QLabel(tr("Sex:"));
    Dialog_Main_Userinfo_Age_Label = new QLabel(tr("Age:"));
    Dialog_Main_Userinfo_Address_Label = new QLabel(tr("Address"));
    Dialog_Main_Userinfo_Address_Country_Label = new QLabel(tr("Country:"));
    Dialog_Main_Userinfo_Address_Province_Label = new QLabel(tr("Province:"));
    Dialog_Main_Userinfo_Address_City_Label = new QLabel(tr("City:"));
    Dialog_Main_Userinfo_PhoneNumber_Label = new QLabel(tr("Phone Number:"));
    Dialog_Main_Userinfo_Email_Label = new QLabel(tr("Email:"));
    Dialog_Main_Userinfo_ID_Number_Label = new QLabel(tr("ID Number:"));
    Dialog_Main_Userinfo_Language_Label = new QLabel(tr("Language Qualifies:"));
    Dialog_Main_Userinfo_Language_Cet4_Label = new QLabel(tr("CET4 Score:"));
    Dialog_Main_Userinfo_Language_Cet6_Label = new QLabel(tr("CET6 Score:"));
    Dialog_Main_Userinfo_Language_Tem4_Label = new QLabel(tr("TEM4 Score:"));
    Dialog_Main_Userinfo_Language_Tem8_Label = new QLabel(tr("TEM8 Score:"));
    Dialog_Main_Userinfo_Language_Toefl_Label = new QLabel(tr("TOEFL Score:"));
    Dialog_Main_Userinfo_Language_Ielts_Label = new QLabel(tr("IELTS Score:"));
    Dialog_Main_Userinfo_Language_Gre_Label = new QLabel(tr("GRE Score:"));
    Dialog_Main_Userinfo_Lan_Intergral_Label = new QLabel(tr("Language Intergral:"));
    Dialog_Main_Userinfo_Tas_Intergral_Label = new QLabel(tr("Task Intergral:"));
    Dialog_Main_Userinfo_Intergral_Label = new QLabel(tr("Intergral:"));
    Dialog_Main_Userinfo_Money = new QLabel("Money: " + QString::number(Userinfo_Hash.find(OnlineUser.GetUsername()).value().Get_User_Money(), 'f', 2));
    Dialog_Main_Userinfo_Apply_Btn = new QPushButton(tr("Apply"));
    Dialog_Main_Userinfo_Edit_Btn = new QPushButton(tr("Edit"));
    Dialog_Main_Userinfo_Apply_Btn ->setEnabled(0);
    Dialog_Main_Userinfo_UserInfo_Layout = new QGridLayout;
    Dialog_Main_Userinfo_UserSelf_Layout = new QGridLayout;
    Dialog_Main_Userinfo_Address_Layout = new QGridLayout;
    Dialog_Main_Userinfo_Language_Layout = new QGridLayout;
    Dialog_Main_Userinfo_Btn_Layout = new QHBoxLayout;
    Dialog_Main_Userinfo_Layout = new QVBoxLayout(this);
    Dialog_Main_Userinfo_UserInfo_Layout ->addWidget(Dialog_Main_Userinfo_Username_Label, 0, 0);
    Dialog_Main_Userinfo_UserInfo_Layout ->addWidget(Dialog_Main_Userinfo_Password_1_Label, 1, 0);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_Nickname_Label, 0, 0);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_Realname_Label, 1, 0);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_FreeSign_Label, 2, 0);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_Sex_Label, 3, 0);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_Age_Label, 4, 0);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_Address_Country_Label, 1, 0);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_Address_Province_Label, 2, 0);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_Address_City_Label, 3, 0);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_PhoneNumber_Label, 1, 2);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_Email_Label, 2, 2);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_ID_Number_Label, 3, 2);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Language_Cet4_Label, 1, 0);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Language_Cet6_Label, 2, 0);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Language_Tem4_Label, 3, 0);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Language_Tem8_Label, 4, 0);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Intergral_Label, 5, 0);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Language_Toefl_Label, 1, 2);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Language_Ielts_Label, 2, 2);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Language_Gre_Label, 3, 2);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Lan_Intergral_Label, 5, 2);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Tas_Intergral_Label, 5, 3);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_Money, 6, 0);
    Dialog_Main_Userinfo_Btn_Layout ->addWidget(Dialog_Main_Userinfo_Apply_Btn);
    Dialog_Main_Userinfo_Btn_Layout ->addWidget(Dialog_Main_Userinfo_Edit_Btn);

    SetState_Userinfo_0_New();

    Dialog_Main_Userinfo_Layout ->addLayout(Dialog_Main_Userinfo_Btn_Layout);
    Dialog_Main_Userinfo_Layout ->addLayout(Dialog_Main_Userinfo_UserInfo_Layout);
    Dialog_Main_Userinfo_Layout ->addLayout(Dialog_Main_Userinfo_UserSelf_Layout);
    Dialog_Main_Userinfo_Layout ->addLayout(Dialog_Main_Userinfo_Address_Layout);
    Dialog_Main_Userinfo_Layout ->addLayout(Dialog_Main_Userinfo_Language_Layout);

    Dialog_Main_Userinfo_Layout ->setSpacing(25);

    Dialog_Main_Userinfo_1_CET4_Enable = 0;

    Dialog_Main_Userinfo_1_language_enable = 1;
    Dialog_Main_Userinfo_1_Enable = 0;

    connect(Dialog_Main_Userinfo_Apply_Btn, SIGNAL(clicked()), this, SLOT(Dialog_Changeinfo_Success()));
    connect(Dialog_Main_Userinfo_Edit_Btn, SIGNAL(clicked()), this, SLOT(Userinfo_ChangeState()));

}



//编辑、退出编辑

void Dialog_Main_Userinfo::Userinfo_ChangeState()
{
    if(Dialog_Main_Userinfo_State == 1)Dialog_Changeinfo_ExitEdit_Info();
    else Userinfo_State_1();
}

void Dialog_Main_Userinfo::Userinfo_State_1()
{
    Dialog_Main_Userinfo_State = 1;
    SetState_Userinfo_0_Delete();
    SetState_Userinfo_1_New();
}

void Dialog_Main_Userinfo::Userinfo_State_0()
{
    Dialog_Main_Userinfo_State = 0;
    SetState_Userinfo_1_Delete();
    SetState_Userinfo_0_New();
    Dialog_Main_Userinfo_Apply_Btn ->setEnabled(0);
}


//控件变化

void Dialog_Main_Userinfo::SetState_Userinfo_0_New(){
    Dialog_Main_Userinfo_Edit_Btn ->setText("Edit");

    Dialog_Main_Userinfo_0_Username_Label = new QLabel(OnlineUser.GetUsername());
    Dialog_Main_Userinfo_0_Password_1_Label = new QLabel(OnlineUser.GetPassword());
    Dialog_Main_Userinfo_0_Nickname_Label = new QLabel;
    Dialog_Main_Userinfo_0_Realname_Label = new QLabel;
    Dialog_Main_Userinfo_0_FreeSign_Label = new QLabel;
    Dialog_Main_Userinfo_0_Sex_Label = new QLabel(OnlineUser.GetSex() ? "Female" : "Male");
    Dialog_Main_Userinfo_0_Age_Label = new QLabel;
    Dialog_Main_Userinfo_0_Address_Label = new QLabel;
    Dialog_Main_Userinfo_0_Address_Country_Label = new QLabel;
    Dialog_Main_Userinfo_0_Address_Province_Label = new QLabel;
    Dialog_Main_Userinfo_0_Address_City_Label = new QLabel;
    Dialog_Main_Userinfo_0_PhoneNumber_Label = new QLabel;
    Dialog_Main_Userinfo_0_Email_Label = new QLabel;
    Dialog_Main_Userinfo_0_ID_Number_Label = new QLabel;
    Dialog_Main_Userinfo_0_Language_Label = new QLabel;
    Dialog_Main_Userinfo_0_Language_Cet4_Label = new QLabel(QString("%1").arg(OnlineUser.get_cet4_score()));
    Dialog_Main_Userinfo_0_Language_Cet6_Label = new QLabel(QString("%1").arg(OnlineUser.get_cet6_score()));
    Dialog_Main_Userinfo_0_Language_Tem4_Label = new QLabel(QString("%1").arg(OnlineUser.get_tem4_score()));
    Dialog_Main_Userinfo_0_Language_Tem8_Label = new QLabel(QString("%1").arg(OnlineUser.get_tem8_score()));
    Dialog_Main_Userinfo_0_Language_Toefl_Label = new QLabel;
    Dialog_Main_Userinfo_0_Language_Ielts_Label = new QLabel;
    Dialog_Main_Userinfo_0_Language_Gre_Label = new QLabel;
    Dialog_Main_Userinfo_Intergral_Label ->setText("Intergral:" + QString("%1").arg(OnlineUser.Get_User_Intergral()));
    Dialog_Main_Userinfo_Lan_Intergral_Label ->setText("Lan_Intergral:" + QString("%1").arg(OnlineUser.Get_User_Language_Intergral()));
    Dialog_Main_Userinfo_Tas_Intergral_Label ->setText("Tas_Intergral:" + QString("%1").arg(OnlineUser.Get_User_Tasks_Intergral()));

    Dialog_Main_Userinfo_UserInfo_Layout ->addWidget(Dialog_Main_Userinfo_0_Username_Label, 0, 1);
    Dialog_Main_Userinfo_UserInfo_Layout ->addWidget(Dialog_Main_Userinfo_0_Password_1_Label, 1, 1);

    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_0_Nickname_Label, 0, 1);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_0_Realname_Label, 1, 1);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_0_FreeSign_Label, 2, 1);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_0_Sex_Label, 3, 1);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_0_Age_Label, 4, 1);

    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_0_Address_Country_Label, 1, 1);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_0_Address_Province_Label, 2, 1);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_0_Address_City_Label, 3, 1);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_0_PhoneNumber_Label, 1, 3);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_0_Email_Label, 2, 3);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_0_ID_Number_Label, 3, 3);

    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_0_Language_Cet4_Label, 1, 1);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_0_Language_Cet6_Label, 2, 1);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_0_Language_Tem4_Label, 3, 1);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_0_Language_Tem8_Label, 4, 1);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_0_Language_Toefl_Label, 1, 3);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_0_Language_Ielts_Label, 2, 3);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_0_Language_Gre_Label, 3, 3);
}


void Dialog_Main_Userinfo::SetState_Userinfo_1_New(){
    //in state 1 (edit)
    Dialog_Main_Userinfo_Edit_Btn ->setText("Exit Edit");

    Dialog_Main_Userinfo_1_Password_2_Label = new QLabel(tr("Confirm Password*"));
    Dialog_Main_Userinfo_1_ErrorTip_Label = new QLabel("*Error: password unmatch");
    Dialog_Main_Userinfo_1_Language_ErrorTip_Label = new QLabel(tr("OK"));

    Dialog_Main_Userinfo_1_Username_LineEdit = new QLineEdit(OnlineUser.GetUsername());
    Dialog_Main_Userinfo_1_Username_LineEdit ->setEnabled(0);
    Dialog_Main_Userinfo_1_Password_1_LineEdit = new QLineEdit(OnlineUser.GetPassword());
    Dialog_Main_Userinfo_1_Password_2_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_Password_1_LineEdit ->setEchoMode(QLineEdit::Password);
    Dialog_Main_Userinfo_1_Password_2_LineEdit ->setEchoMode(QLineEdit::Password);
    Dialog_Main_Userinfo_1_Nickname_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_Realname_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_FreeSign_LineEdit = new QLineEdit;

    Dialog_Main_Userinfo_1_Sex_Combox = new QComboBox;
    Dialog_Main_Userinfo_1_Sex_Combox ->insertItem(0, tr("Male"));
    Dialog_Main_Userinfo_1_Sex_Combox ->insertItem(1, tr("Female"));
    Dialog_Main_Userinfo_1_Sex_Combox ->setCurrentIndex(OnlineUser.GetSex());

    Dialog_Main_Userinfo_1_Age_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_Address_Country_Combox = new QComboBox;
    Dialog_Main_Userinfo_1_Address_Province_Combox = new QComboBox;
    Dialog_Main_Userinfo_1_Address_City_Combox = new QComboBox;
    Dialog_Main_Userinfo_1_PhoneNumber_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_Email_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_ID_Number_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_Language_Cet4_LineEdit = new QLineEdit(QString("%1").arg(OnlineUser.get_cet4_score()));
    Dialog_Main_Userinfo_1_Language_Cet6_LineEdit = new QLineEdit(QString("%1").arg(OnlineUser.get_cet6_score()));
    Dialog_Main_Userinfo_1_Language_Tem4_LineEdit = new QLineEdit(QString("%1").arg(OnlineUser.get_tem4_score()));
    Dialog_Main_Userinfo_1_Language_Tem8_LineEdit = new QLineEdit(QString("%1").arg(OnlineUser.get_tem8_score()));
    Dialog_Main_Userinfo_1_Language_Toefl_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_Language_Ielts_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_Language_Gre_LineEdit = new QLineEdit;
    Dialog_Main_Userinfo_1_Money_Btn = new QPushButton(tr("Charge"));

    Dialog_Main_Userinfo_UserInfo_Layout ->addWidget(Dialog_Main_Userinfo_1_Password_2_Label, 2, 0);
    Dialog_Main_Userinfo_UserInfo_Layout ->addWidget(Dialog_Main_Userinfo_1_Username_LineEdit, 0, 1);
    Dialog_Main_Userinfo_UserInfo_Layout ->addWidget(Dialog_Main_Userinfo_1_Password_1_LineEdit, 1, 1);
    Dialog_Main_Userinfo_UserInfo_Layout ->addWidget(Dialog_Main_Userinfo_1_Password_2_LineEdit, 2, 1);
    Dialog_Main_Userinfo_UserInfo_Layout ->addWidget(Dialog_Main_Userinfo_1_ErrorTip_Label, 3, 0, 1, 2);

    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_1_Nickname_LineEdit, 0, 1);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_1_Realname_LineEdit, 1, 1);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_1_FreeSign_LineEdit, 2, 1);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_1_Sex_Combox, 3, 1);
    Dialog_Main_Userinfo_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_1_Age_LineEdit, 4, 1);

    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_1_Address_Country_Combox, 1, 1);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_1_Address_Province_Combox, 2, 1);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_1_Address_City_Combox, 3, 1);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_1_PhoneNumber_LineEdit, 1, 3);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_1_Email_LineEdit, 2, 3);
    Dialog_Main_Userinfo_Address_Layout ->addWidget(Dialog_Main_Userinfo_1_ID_Number_LineEdit, 3, 3);

    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_1_Language_Cet4_LineEdit, 1, 1);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_1_Language_Cet6_LineEdit, 2, 1);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_1_Language_Tem4_LineEdit, 3, 1);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_1_Language_Tem8_LineEdit, 4, 1);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_1_Language_Toefl_LineEdit, 1, 3);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_1_Language_Ielts_LineEdit, 2, 3);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_1_Language_Gre_LineEdit, 3, 3);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_1_Language_ErrorTip_Label, 4, 2, 1, 2);
    Dialog_Main_Userinfo_Language_Layout ->addWidget(Dialog_Main_Userinfo_1_Money_Btn, 6, 1);

    connect(Dialog_Main_Userinfo_1_Username_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Changeinfo_ErrorTips()));
    connect(Dialog_Main_Userinfo_1_Password_1_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Changeinfo_ErrorTips()));
    connect(Dialog_Main_Userinfo_1_Password_2_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Changeinfo_ErrorTips()));
    connect(Dialog_Main_Userinfo_1_Language_Cet4_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Changeinfo_Language_ErrorTips()));
    connect(Dialog_Main_Userinfo_1_Language_Cet6_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Changeinfo_Language_ErrorTips()));
    connect(Dialog_Main_Userinfo_1_Language_Tem4_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Changeinfo_Language_ErrorTips()));
    connect(Dialog_Main_Userinfo_1_Language_Tem8_LineEdit, SIGNAL(textChanged(QString)), this, SLOT(Dialog_Changeinfo_Language_ErrorTips()));
      connect(Dialog_Main_Userinfo_1_Money_Btn, SIGNAL(clicked()), this, SLOT(charge()));

}

void Dialog_Main_Userinfo::SetState_Userinfo_0_Delete(){
    delete Dialog_Main_Userinfo_0_Username_Label;
    delete Dialog_Main_Userinfo_0_Password_1_Label;
    delete Dialog_Main_Userinfo_0_Nickname_Label;
    delete Dialog_Main_Userinfo_0_Realname_Label;
    delete Dialog_Main_Userinfo_0_FreeSign_Label;
    delete Dialog_Main_Userinfo_0_Sex_Label;
    delete Dialog_Main_Userinfo_0_Age_Label;
    delete Dialog_Main_Userinfo_0_Address_Label;
    delete Dialog_Main_Userinfo_0_Address_Country_Label;
    delete Dialog_Main_Userinfo_0_Address_Province_Label;
    delete Dialog_Main_Userinfo_0_Address_City_Label;
    delete Dialog_Main_Userinfo_0_PhoneNumber_Label;
    delete Dialog_Main_Userinfo_0_Email_Label;
    delete Dialog_Main_Userinfo_0_ID_Number_Label;
    delete Dialog_Main_Userinfo_0_Language_Label;
    delete Dialog_Main_Userinfo_0_Language_Cet4_Label;
    delete Dialog_Main_Userinfo_0_Language_Cet6_Label;
    delete Dialog_Main_Userinfo_0_Language_Tem4_Label;
    delete Dialog_Main_Userinfo_0_Language_Tem8_Label;
    delete Dialog_Main_Userinfo_0_Language_Toefl_Label;
    delete Dialog_Main_Userinfo_0_Language_Ielts_Label;
    delete Dialog_Main_Userinfo_0_Language_Gre_Label;
}

void Dialog_Main_Userinfo::SetState_Userinfo_1_Delete(){
    Dialog_Main_Userinfo_UserInfo_Layout ->removeWidget(Dialog_Main_Userinfo_1_Password_2_Label);
    Dialog_Main_Userinfo_UserInfo_Layout ->removeWidget(Dialog_Main_Userinfo_1_Username_LineEdit);
    Dialog_Main_Userinfo_UserInfo_Layout ->removeWidget(Dialog_Main_Userinfo_1_Password_1_LineEdit);
    Dialog_Main_Userinfo_UserInfo_Layout ->removeWidget(Dialog_Main_Userinfo_1_Password_2_LineEdit);
    Dialog_Main_Userinfo_UserInfo_Layout ->removeWidget(Dialog_Main_Userinfo_1_ErrorTip_Label);

    Dialog_Main_Userinfo_UserSelf_Layout ->removeWidget(Dialog_Main_Userinfo_1_Nickname_LineEdit);
    Dialog_Main_Userinfo_UserSelf_Layout ->removeWidget(Dialog_Main_Userinfo_1_Realname_LineEdit);
    Dialog_Main_Userinfo_UserSelf_Layout ->removeWidget(Dialog_Main_Userinfo_1_FreeSign_LineEdit);
    Dialog_Main_Userinfo_UserSelf_Layout ->removeWidget(Dialog_Main_Userinfo_1_Sex_Combox);
    Dialog_Main_Userinfo_UserSelf_Layout ->removeWidget(Dialog_Main_Userinfo_1_Age_LineEdit);

    Dialog_Main_Userinfo_Address_Layout ->removeWidget(Dialog_Main_Userinfo_1_Address_Country_Combox);
    Dialog_Main_Userinfo_Address_Layout ->removeWidget(Dialog_Main_Userinfo_1_Address_Province_Combox);
    Dialog_Main_Userinfo_Address_Layout ->removeWidget(Dialog_Main_Userinfo_1_Address_City_Combox);
    Dialog_Main_Userinfo_Address_Layout ->removeWidget(Dialog_Main_Userinfo_1_PhoneNumber_LineEdit);
    Dialog_Main_Userinfo_Address_Layout ->removeWidget(Dialog_Main_Userinfo_1_Email_LineEdit);
    Dialog_Main_Userinfo_Address_Layout ->removeWidget(Dialog_Main_Userinfo_1_ID_Number_LineEdit);

    Dialog_Main_Userinfo_Language_Layout ->removeWidget(Dialog_Main_Userinfo_1_Language_Cet4_LineEdit);
    Dialog_Main_Userinfo_Language_Layout ->removeWidget(Dialog_Main_Userinfo_1_Language_Cet6_LineEdit);
    Dialog_Main_Userinfo_Language_Layout ->removeWidget(Dialog_Main_Userinfo_1_Language_Tem4_LineEdit);
    Dialog_Main_Userinfo_Language_Layout ->removeWidget(Dialog_Main_Userinfo_1_Language_Tem8_LineEdit);
    Dialog_Main_Userinfo_Language_Layout ->removeWidget(Dialog_Main_Userinfo_1_Language_Toefl_LineEdit);
    Dialog_Main_Userinfo_Language_Layout ->removeWidget(Dialog_Main_Userinfo_1_Language_Ielts_LineEdit);
    Dialog_Main_Userinfo_Language_Layout ->removeWidget(Dialog_Main_Userinfo_1_Language_Gre_LineEdit);
    Dialog_Main_Userinfo_Language_Layout ->removeWidget(Dialog_Main_Userinfo_1_Language_ErrorTip_Label);
    Dialog_Main_Userinfo_Language_Layout ->removeWidget(Dialog_Main_Userinfo_1_Money_Btn);

    delete Dialog_Main_Userinfo_1_Password_2_Label;
    delete Dialog_Main_Userinfo_1_Username_LineEdit;
    delete Dialog_Main_Userinfo_1_Password_1_LineEdit;
    delete Dialog_Main_Userinfo_1_Password_2_LineEdit;
    delete Dialog_Main_Userinfo_1_ErrorTip_Label;
    delete Dialog_Main_Userinfo_1_Nickname_LineEdit;
    delete Dialog_Main_Userinfo_1_Realname_LineEdit;
    delete Dialog_Main_Userinfo_1_FreeSign_LineEdit;
    delete Dialog_Main_Userinfo_1_Sex_Combox;
    delete Dialog_Main_Userinfo_1_Age_LineEdit;
    delete Dialog_Main_Userinfo_1_Address_Country_Combox;
    delete Dialog_Main_Userinfo_1_Address_Province_Combox;
    delete Dialog_Main_Userinfo_1_Address_City_Combox;
    delete Dialog_Main_Userinfo_1_PhoneNumber_LineEdit;
    delete Dialog_Main_Userinfo_1_Email_LineEdit;
    delete Dialog_Main_Userinfo_1_ID_Number_LineEdit;
    delete Dialog_Main_Userinfo_1_Language_Cet4_LineEdit;
    delete Dialog_Main_Userinfo_1_Language_Cet6_LineEdit;
    delete Dialog_Main_Userinfo_1_Language_Tem4_LineEdit;
    delete Dialog_Main_Userinfo_1_Language_Tem8_LineEdit;
    delete Dialog_Main_Userinfo_1_Language_Toefl_LineEdit;
    delete Dialog_Main_Userinfo_1_Language_Ielts_LineEdit;
    delete Dialog_Main_Userinfo_1_Language_Gre_LineEdit;
    delete Dialog_Main_Userinfo_1_Language_ErrorTip_Label;
    delete Dialog_Main_Userinfo_1_Money_Btn;
}


//tip: Changeinfo success || exit edit
void Dialog_Main_Userinfo::Dialog_Changeinfo_Success_Info()
{
    QMessageBox::information(this, "Change success", "Your changes saved", QMessageBox::Ok, QMessageBox::NoButton);
}

void Dialog_Main_Userinfo::Dialog_Changeinfo_ExitEdit_Info()
{
    if(QMessageBox::Yes == QMessageBox::question(this, "Exit Edit", "Your unapplyed changes will not be saved",
                                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::No))
        Userinfo_State_0();
}


//用户名、密码： 5- 16位，不重复

void Dialog_Main_Userinfo::Dialog_Changeinfo_ErrorTips()
{
    Dialog_Main_Userinfo_1_Enable = 1;

    Dialog_Main_Userinfo_1_Username_Input = Dialog_Main_Userinfo_1_Username_LineEdit ->text();
    Dialog_Main_Userinfo_1_Password_1_Input = Dialog_Main_Userinfo_1_Password_1_LineEdit ->text();
    Dialog_Main_Userinfo_1_Password_2_Input = Dialog_Main_Userinfo_1_Password_2_LineEdit ->text();

    bool username_existed = 0;
    if(Dialog_Main_Userinfo_1_Username_Input != OnlineUser.GetUsername() && Userinfo_Hash.count(Dialog_Main_Userinfo_1_Username_Input))username_existed = 1;

    bool password_match = (Dialog_Main_Userinfo_1_Password_1_Input == Dialog_Main_Userinfo_1_Password_2_Input);
    bool username_illegal_tooshort = (Dialog_Main_Userinfo_1_Username_Input.length() < 5);
    bool username_illegal_toolong = (16 < Dialog_Main_Userinfo_1_Username_Input.length());
    bool username_illegal_chars = 0;
    bool password_illegal_tooshort = (Dialog_Main_Userinfo_1_Password_1_Input.length() < 5);
    bool password_illegal_toolong = (16 < Dialog_Main_Userinfo_1_Password_1_Input.length());
    bool password_illegal_chars = 0;
    bool username_same_password = (Dialog_Main_Userinfo_1_Username_Input == Dialog_Main_Userinfo_1_Password_1_Input);
    for(int i = 0; i < Dialog_Main_Userinfo_1_Username_Input.length(); i++){
        if(Dialog_Main_Userinfo_1_Username_Input.mid(i, 1) < 48)username_illegal_chars = 1;
        else if(57 < Dialog_Main_Userinfo_1_Username_Input.mid(i, 1) && Dialog_Main_Userinfo_1_Username_Input.mid(i, 1) < 65)username_illegal_chars = 1;
        else if(90 < Dialog_Main_Userinfo_1_Username_Input.mid(i, 1) && Dialog_Main_Userinfo_1_Username_Input.mid(i, 1) < 97)username_illegal_chars = 1;
        else if(122 < Dialog_Main_Userinfo_1_Username_Input.mid(i, 1))username_illegal_chars = 1;
    }
    for(int i = 0; i < Dialog_Main_Userinfo_1_Password_1_Input.length(); i++){
        if(Dialog_Main_Userinfo_1_Password_1_Input.mid(i, 1) < 48)password_illegal_chars = 1;
        else if(57 < Dialog_Main_Userinfo_1_Password_1_Input.mid(i, 1) && Dialog_Main_Userinfo_1_Password_1_Input.mid(i, 1) < 65)password_illegal_chars = 1;
        else if(90 < Dialog_Main_Userinfo_1_Password_1_Input.mid(i, 1) && Dialog_Main_Userinfo_1_Password_1_Input.mid(i, 1) < 97)password_illegal_chars = 1;
        else if(122 < Dialog_Main_Userinfo_1_Password_1_Input.mid(i, 1))password_illegal_chars = 1;
    }

    Dialog_Main_Userinfo_1_Enable = (!username_illegal_tooshort) && (!username_illegal_toolong) && (!username_illegal_chars)
            && (!password_illegal_tooshort) && (!password_illegal_toolong) && (!password_illegal_chars)
            && (password_match) && (!username_same_password) && (!username_existed);

    if(username_existed)Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("*Error: username existed, please change");
    else if(username_illegal_tooshort)Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("*Error: username must more than 5 letter or numbers");
    else if(username_illegal_chars)Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("*Error: illegal username: only letters or numbers");
    else if(username_illegal_toolong)Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("*Error: username must less than 16 letter or numbers");
    else if(password_illegal_tooshort)Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("*Error: password must more than 5 letter or numbers");
    else if(password_illegal_chars)Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("*Error: illegal password: only letters or numbers");
    else if(password_illegal_toolong)Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("*Error: password must less than 16 letter or numbers");
    else if(!password_match)Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("*Error: password unmatch");
    else if(username_same_password)Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("*Error: username == password, please modify at least one");
    else Dialog_Main_Userinfo_1_ErrorTip_Label ->setText("no errors");

    if(Dialog_Main_Userinfo_1_Enable && Dialog_Main_Userinfo_1_language_enable)Dialog_Main_Userinfo_Apply_Btn ->setEnabled(1);
    else Dialog_Main_Userinfo_Apply_Btn ->setEnabled(0);
}


//语言资质：分数为整数（cet<710  tem < 100）

void Dialog_Main_Userinfo::Dialog_Changeinfo_Language_ErrorTips()
{
    Dialog_Main_Userinfo_1_CET4_Input = Dialog_Main_Userinfo_1_Language_Cet4_LineEdit ->text();
    Dialog_Main_Userinfo_1_CET6_Input = Dialog_Main_Userinfo_1_Language_Cet6_LineEdit ->text();
    Dialog_Main_Userinfo_1_TEM4_Input = Dialog_Main_Userinfo_1_Language_Tem4_LineEdit ->text();
    Dialog_Main_Userinfo_1_TEM8_Input = Dialog_Main_Userinfo_1_Language_Tem8_LineEdit ->text();
    Dialog_Main_Userinfo_1_TOEFL_Input = Dialog_Main_Userinfo_1_Language_Toefl_LineEdit ->text();
    Dialog_Main_Userinfo_1_IELTS_Input = Dialog_Main_Userinfo_1_Language_Ielts_LineEdit ->text();
    Dialog_Main_Userinfo_1_GRE_Input = Dialog_Main_Userinfo_1_Language_Gre_LineEdit ->text();

    Dialog_Main_Userinfo_1_language_enable = 0;
    bool cet4_enable = 1;
    bool cet6_enable = 1;
    bool tem4_enable = 1;
    bool tem8_enable = 1;
    bool toefl_enable = 1;
    bool ielts_enable = 1;
    bool gre_enable = 1;

    if(3 < Dialog_Main_Userinfo_1_CET4_Input.length())cet4_enable = 0;
    if(cet4_enable == 1){
        for (int i = 0; i < Dialog_Main_Userinfo_1_CET4_Input.length(); i++) {
            if(Dialog_Main_Userinfo_1_CET4_Input.mid(i, 1) < 48 || 57 < Dialog_Main_Userinfo_1_CET4_Input.mid(i, 1))
                cet4_enable = 0;
        }
    }
    if(cet4_enable == 1){
        Dialog_Main_Userinfo_1_CET4_Enable = 0;
        int powerbase = 1;
        for(int i = 0; i < Dialog_Main_Userinfo_1_CET4_Input.length(); i++){
            Dialog_Main_Userinfo_1_CET4_Enable += (Dialog_Main_Userinfo_1_CET4_Input.mid(Dialog_Main_Userinfo_1_CET4_Input.length() - i - 1, 1).toShort()) * powerbase;
        powerbase *= 10;
        }
    }
    cet4_enable = cet4_enable && (Dialog_Main_Userinfo_1_CET4_Enable <= 710);

    if(3 < Dialog_Main_Userinfo_1_CET6_Input.length())cet6_enable = 0;
    if(cet6_enable == 1){
        for (int i = 0; i < Dialog_Main_Userinfo_1_CET6_Input.length(); i++) {
            if(Dialog_Main_Userinfo_1_CET6_Input.mid(i, 1) < 48 || 57 < Dialog_Main_Userinfo_1_CET6_Input.mid(i, 1))
                cet6_enable = 0;
        }
    }
    if(cet6_enable == 1){
        Dialog_Main_Userinfo_1_CET6_Enable = 0;
        int powerbase = 1;
        for(int i = 0; i < Dialog_Main_Userinfo_1_CET6_Input.length(); i++){
            Dialog_Main_Userinfo_1_CET6_Enable += (Dialog_Main_Userinfo_1_CET6_Input.mid(Dialog_Main_Userinfo_1_CET6_Input.length() - i - 1, 1).toShort()) * powerbase;
        powerbase *= 10;
        }
    }
    cet6_enable = cet6_enable && (Dialog_Main_Userinfo_1_CET6_Enable <= 710);

    if(3 < Dialog_Main_Userinfo_1_TEM4_Input.length())tem4_enable = 0;
    if(tem4_enable == 1){
        for (int i = 0; i < Dialog_Main_Userinfo_1_TEM4_Input.length(); i++) {
            if(Dialog_Main_Userinfo_1_TEM4_Input.mid(i, 1) < 48 || 57 < Dialog_Main_Userinfo_1_TEM4_Input.mid(i, 1))
                tem4_enable = 0;
        }
    }
    if(tem4_enable == 1){
        Dialog_Main_Userinfo_1_TEM4_Enable = 0;
        int powerbase = 1;
        for(int i = 0; i < Dialog_Main_Userinfo_1_TEM4_Input.length(); i++){
            Dialog_Main_Userinfo_1_TEM4_Enable += (Dialog_Main_Userinfo_1_TEM4_Input.mid(Dialog_Main_Userinfo_1_TEM4_Input.length() - i - 1, 1).toShort()) * powerbase;
        powerbase *= 10;
        }
    }
    tem4_enable = tem4_enable && (Dialog_Main_Userinfo_1_TEM4_Enable <= 100);

    if(3 < Dialog_Main_Userinfo_1_TEM8_Input.length())tem8_enable = 0;
    if(tem8_enable == 1){
        for (int i = 0; i < Dialog_Main_Userinfo_1_TEM8_Input.length(); i++) {
            if(Dialog_Main_Userinfo_1_TEM8_Input.mid(i, 1) < 48 || 57 < Dialog_Main_Userinfo_1_TEM8_Input.mid(i, 1))
                tem8_enable = 0;
        }
    }
    if(tem8_enable == 1){
        Dialog_Main_Userinfo_1_TEM8_Enable = 0;
        int powerbase = 1;
        for(int i = 0; i < Dialog_Main_Userinfo_1_TEM8_Input.length(); i++){
            Dialog_Main_Userinfo_1_TEM8_Enable += (Dialog_Main_Userinfo_1_TEM8_Input.mid(Dialog_Main_Userinfo_1_TEM8_Input.length() - i - 1, 1).toShort()) * powerbase;
        powerbase *= 10;
        }
    }
    tem8_enable = tem8_enable && (Dialog_Main_Userinfo_1_TEM8_Enable <= 100);

    Dialog_Main_Userinfo_1_language_enable = cet4_enable && cet6_enable &&
            tem4_enable && tem8_enable && toefl_enable &&
            ielts_enable &&gre_enable;

//    qDebug() << Dialog_Main_Userinfo_1_Enable << language_enable;
    if(cet4_enable == 0)Dialog_Main_Userinfo_1_Language_ErrorTip_Label ->setText("Error: CET4");
    else if(cet6_enable == 0)Dialog_Main_Userinfo_1_Language_ErrorTip_Label ->setText("Error: CET6");
    else if(tem4_enable == 0)Dialog_Main_Userinfo_1_Language_ErrorTip_Label ->setText("Error: TEM4");
    else if(tem8_enable == 0)Dialog_Main_Userinfo_1_Language_ErrorTip_Label ->setText("Error: TEM8");
    else Dialog_Main_Userinfo_1_Language_ErrorTip_Label ->setText("OK..");
    if(Dialog_Main_Userinfo_1_language_enable && Dialog_Main_Userinfo_1_Enable)Dialog_Main_Userinfo_Apply_Btn ->setEnabled(1);
    else Dialog_Main_Userinfo_Apply_Btn ->setEnabled(0);
}


//成功修改

void Dialog_Main_Userinfo::Dialog_Changeinfo_Success()
{
    if(Dialog_Main_Userinfo_1_Enable){
        Dialog_Main_Userinfo_1_Username_Enable = Dialog_Main_Userinfo_1_Username_Input;
        Dialog_Main_Userinfo_1_Password_Enable = Dialog_Main_Userinfo_1_Password_1_Input;
        Dialog_Main_Userinfo_1_Sex_Enable = Dialog_Main_Userinfo_1_Sex_Combox ->currentIndex();
        Dialog_Main_Userinfo_1_Sexs_Enable = Dialog_Main_Userinfo_1_Sex_Enable == 0 ? "Male" : "Female";

        Dialog_Main_Userinfo_1_CET4_Enabled = Dialog_Main_Userinfo_1_Language_Cet4_LineEdit ->text().toInt();
        Dialog_Main_Userinfo_1_CET6_Enabled = Dialog_Main_Userinfo_1_Language_Cet6_LineEdit ->text().toInt();
        Dialog_Main_Userinfo_1_TEM4_Enabled = Dialog_Main_Userinfo_1_Language_Tem4_LineEdit ->text().toInt();
        Dialog_Main_Userinfo_1_TEM8_Enabled = Dialog_Main_Userinfo_1_Language_Tem8_LineEdit ->text().toInt();
//if modified
        if(Dialog_Main_Userinfo_1_Username_Enable != OnlineUser.GetUsername()){
            OnlineUser.SetUsername(Dialog_Main_Userinfo_1_Username_Enable);
            OnlineUser.Changeinfoflag[0] = 1;
        }
        if(Dialog_Main_Userinfo_1_Password_Enable != OnlineUser.GetPassword()){
            OnlineUser.SetPassword(Dialog_Main_Userinfo_1_Password_Enable);
            OnlineUser.Changeinfoflag[1] = 1;
        }
        if(Dialog_Main_Userinfo_1_Sex_Enable != OnlineUser.GetSex()){
            OnlineUser.SetSex(Dialog_Main_Userinfo_1_Sex_Enable);
            OnlineUser.Changeinfoflag[6] = 1;
        }
        if(Dialog_Main_Userinfo_1_CET4_Enabled != OnlineUser.get_cet4_score()){
            qDebug() << "Change 13 15 16 23" << Dialog_Main_Userinfo_1_CET4_Enabled << OnlineUser.get_cet4_score();
            OnlineUser.set_cet4_score(Dialog_Main_Userinfo_1_CET4_Enabled);
            OnlineUser.Set_User_Language_Intergral();
            OnlineUser.Set_User_Intergral();
            OnlineUser.Changeinfoflag[13] = 1;
            OnlineUser.Changeinfoflag[15] = 1;
            OnlineUser.Changeinfoflag[16] = 1;
            OnlineUser.Changeinfoflag[23] = 1;
        }

        if(Dialog_Main_Userinfo_1_CET6_Enabled != OnlineUser.get_cet6_score()){
            qDebug() << "Change 13 15 17 24" << Dialog_Main_Userinfo_1_CET6_Enabled << OnlineUser.get_cet6_score();
            OnlineUser.set_cet6_score(Dialog_Main_Userinfo_1_CET6_Enabled);
            OnlineUser.Set_User_Language_Intergral();
            OnlineUser.Set_User_Intergral();
            OnlineUser.Changeinfoflag[13] = 1;
            OnlineUser.Changeinfoflag[15] = 1;
            OnlineUser.Changeinfoflag[17] = 1;
            OnlineUser.Changeinfoflag[24] = 1;
        }

        if(Dialog_Main_Userinfo_1_TEM4_Enabled != OnlineUser.get_tem4_score()){
            qDebug() << "Change 13 15 18 25" << Dialog_Main_Userinfo_1_TEM4_Enabled << OnlineUser.get_tem4_score();
            OnlineUser.set_tem4_score(Dialog_Main_Userinfo_1_TEM4_Enabled);
            OnlineUser.Set_User_Language_Intergral();
            OnlineUser.Set_User_Intergral();
            OnlineUser.Changeinfoflag[13] = 1;
            OnlineUser.Changeinfoflag[15] = 1;
            OnlineUser.Changeinfoflag[18] = 1;
            OnlineUser.Changeinfoflag[25] = 1;
        }

        if(Dialog_Main_Userinfo_1_TEM8_Enabled != OnlineUser.get_tem8_score()){
            qDebug() << "Change 13 15 19 26" << Dialog_Main_Userinfo_1_TEM8_Enabled << OnlineUser.get_tem8_score();
            OnlineUser.set_tem8_score(Dialog_Main_Userinfo_1_TEM8_Enabled);
            OnlineUser.Set_User_Language_Intergral();
            OnlineUser.Set_User_Intergral();
            OnlineUser.Changeinfoflag[13] = 1;
            OnlineUser.Changeinfoflag[15] = 1;
            OnlineUser.Changeinfoflag[19] = 1;
            OnlineUser.Changeinfoflag[26] = 1;
        }

        Userinfo_Hash.remove(OnlineUser.GetUsername());
        Userinfo_Hash.insert(OnlineUser.GetUsername(), OnlineUser);
        qDebug() << "modify info" << Dialog_Main_Userinfo_1_Username_Enable
                 << "password" << Dialog_Main_Userinfo_1_Password_Enable
                 << "sex" << Dialog_Main_Userinfo_1_Sexs_Enable
                 << "cet4" << Dialog_Main_Userinfo_1_CET4_Enabled << OnlineUser.get_cet4_level();
        }

    Dialog_Changeinfo_Success_Info();
    Dialog_Main_Userinfo_Intergral_Label ->setText("Intergral:" + QString("%1").arg(OnlineUser.Get_User_Intergral()));
    Dialog_Main_Userinfo_Lan_Intergral_Label ->setText("Lan_Intergral:" + QString("%1").arg(OnlineUser.Get_User_Language_Intergral()));
    Dialog_Main_Userinfo_Tas_Intergral_Label ->setText("Tas_Intergral:" + QString("%1").arg(OnlineUser.Get_User_Tasks_Intergral()));

}

bool Dialog_Main_Userinfo::Userinfo_GetState()
{
    return Dialog_Main_Userinfo_State;
}

//充值

void Dialog_Main_Userinfo::charge()
{
    double addmoney = QInputDialog::getDouble(this, "charge", "please input money", 0, 0, 10000, 2);
    OnlineUser.AddMoney(addmoney);
    OnlineUser.Changeinfoflag[27] = 1;
    qDebug() << Userinfo_Hash.find(OnlineUser.GetUsername()).value().Get_User_Money();
    Userinfo_Hash.find(OnlineUser.GetUsername()).value().AddMoney(addmoney);
     qDebug() << Userinfo_Hash.find(OnlineUser.GetUsername()).value().Get_User_Money();
     qDebug() << OnlineUser.Get_User_Money();
    Userinfo_Hash.find(OnlineUser.GetUsername()).value().Changeinfoflag[27] = 1;
    changemoney();
    QMessageBox::information(this, "Success" , QString("Charge Success, your money: %1").arg(OnlineUser.Get_User_Money()));
}


//余额改变

void Dialog_Main_Userinfo::changemoney()
{
    Dialog_Main_Userinfo_Money ->setText("Money: " + QString::number(Userinfo_Hash.find(OnlineUser.GetUsername()).value().Get_User_Money(), 'f', 2));
}
