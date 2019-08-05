#include "dialog_main_userinfo_onlyread.h"

extern QHash<QString, User> Userinfo_Hash;
extern QHash<QString, User> ::const_iterator Userinfo_Hash_Iter;

dialog_main_userinfo_onlyread::dialog_main_userinfo_onlyread(QWidget *parent) : QWidget(parent)
{

}

dialog_main_userinfo_onlyread::~dialog_main_userinfo_onlyread()
{

}

//带参构造：罗列个人信息

dialog_main_userinfo_onlyread::dialog_main_userinfo_onlyread(QString checkuser) : MainUser(checkuser)
{
    Dialog_Main_Userinfo_onlyread_Username_Label = new QLabel(tr("Username*:"));
    Dialog_Main_Userinfo_onlyread_Nickname_Label = new QLabel(tr("Nickname:"));
    Dialog_Main_Userinfo_onlyread_Realname_Label = new QLabel(tr("Realname:"));
    Dialog_Main_Userinfo_onlyread_FreeSign_Label = new QLabel(tr("FreeSign:"));
    Dialog_Main_Userinfo_onlyread_Sex_Label = new QLabel(tr("Sex:"));
    Dialog_Main_Userinfo_onlyread_Age_Label = new QLabel(tr("Age:"));
    Dialog_Main_Userinfo_onlyread_Address_Label = new QLabel(tr("Address"));
    Dialog_Main_Userinfo_onlyread_Address_Country_Label = new QLabel(tr("Country:"));
    Dialog_Main_Userinfo_onlyread_Address_Province_Label = new QLabel(tr("Province:"));
    Dialog_Main_Userinfo_onlyread_Address_City_Label = new QLabel(tr("City:"));
    Dialog_Main_Userinfo_onlyread_PhoneNumber_Label = new QLabel(tr("Phone Number:"));
    Dialog_Main_Userinfo_onlyread_Email_Label = new QLabel(tr("Email:"));
    Dialog_Main_Userinfo_onlyread_ID_Number_Label = new QLabel(tr("ID Number:"));
    Dialog_Main_Userinfo_onlyread_Language_Label = new QLabel(tr("Language Qualifies:"));
    Dialog_Main_Userinfo_onlyread_Language_Cet4_Label = new QLabel(tr("CET4 Score:"));
    Dialog_Main_Userinfo_onlyread_Language_Cet6_Label = new QLabel(tr("CET6 Score:"));
    Dialog_Main_Userinfo_onlyread_Language_Tem4_Label = new QLabel(tr("TEM4 Score:"));
    Dialog_Main_Userinfo_onlyread_Language_Tem8_Label = new QLabel(tr("TEM8 Score:"));
    Dialog_Main_Userinfo_onlyread_Language_Toefl_Label = new QLabel(tr("TOEFL Score:"));
    Dialog_Main_Userinfo_onlyread_Language_Ielts_Label = new QLabel(tr("IELTS Score:"));
    Dialog_Main_Userinfo_onlyread_Language_Gre_Label = new QLabel(tr("GRE Score:"));
    Dialog_Main_Userinfo_onlyread_Lan_Intergral_Label = new QLabel(tr("Language Intergral:"));
    Dialog_Main_Userinfo_onlyread_Tas_Intergral_Label = new QLabel(tr("Task Intergral:"));
    Dialog_Main_Userinfo_onlyread_Intergral_Label = new QLabel(tr("Intergral:"));

    Dialog_Main_Userinfo_onlyread_Userinfo_onlyread_Layout = new QGridLayout;
    Dialog_Main_Userinfo_onlyread_UserSelf_Layout = new QGridLayout;
    Dialog_Main_Userinfo_onlyread_Address_Layout = new QGridLayout;
    Dialog_Main_Userinfo_onlyread_Language_Layout = new QGridLayout;
    Dialog_Main_Userinfo_onlyread_Btn_Layout = new QHBoxLayout;
    Dialog_Main_Userinfo_onlyread_Layout = new QVBoxLayout(this);

    Dialog_Main_Userinfo_onlyread_Userinfo_onlyread_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Username_Label, 0, 0);

    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Nickname_Label, 0, 0);
    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Realname_Label, 1, 0);
    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_FreeSign_Label, 2, 0);
    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Sex_Label, 3, 0);
    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Age_Label, 4, 0);

    //    Dialog_Main_Userinfo_onlyread_1_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_1_Address_Label, 0, 1);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Address_Country_Label, 1, 0);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Address_Province_Label, 2, 0);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Address_City_Label, 3, 0);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_PhoneNumber_Label, 1, 2);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Email_Label, 2, 2);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_ID_Number_Label, 3, 2);

    //    Dialog_Main_Userinfo_onlyread_1_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_1_Language_Label, 0, 1);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Language_Cet4_Label, 1, 0);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Language_Cet6_Label, 2, 0);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Language_Tem4_Label, 3, 0);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Language_Tem8_Label, 4, 0);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Intergral_Label, 5, 0);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Language_Toefl_Label, 1, 2);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Language_Ielts_Label, 2, 2);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Language_Gre_Label, 3, 2);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Lan_Intergral_Label, 5, 2);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_Tas_Intergral_Label, 5, 3);


    Dialog_Main_Userinfo_onlyread_0_Username_Label = new QLabel(Userinfo_Hash.find(MainUser).value().GetUsername());
    Dialog_Main_Userinfo_onlyread_0_Nickname_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Realname_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_FreeSign_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Sex_Label = new QLabel(Userinfo_Hash.find(MainUser).value().GetSex() ? "Female" : "Male");
    Dialog_Main_Userinfo_onlyread_0_Age_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Address_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Address_Country_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Address_Province_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Address_City_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_PhoneNumber_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Email_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_ID_Number_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Language_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Language_Cet4_Label = new QLabel(QString("%1").arg(Userinfo_Hash.find(MainUser).value().get_cet4_score()));
    Dialog_Main_Userinfo_onlyread_0_Language_Cet6_Label = new QLabel(QString("%1").arg(Userinfo_Hash.find(MainUser).value().get_cet6_score()));
    Dialog_Main_Userinfo_onlyread_0_Language_Tem4_Label = new QLabel(QString("%1").arg(Userinfo_Hash.find(MainUser).value().get_tem4_score()));
    Dialog_Main_Userinfo_onlyread_0_Language_Tem8_Label = new QLabel(QString("%1").arg(Userinfo_Hash.find(MainUser).value().get_tem8_score()));
    Dialog_Main_Userinfo_onlyread_0_Language_Toefl_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Language_Ielts_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_0_Language_Gre_Label = new QLabel;
    Dialog_Main_Userinfo_onlyread_Intergral_Label ->setText("Intergral:" + QString("%1").arg(Userinfo_Hash.find(MainUser).value().Get_User_Intergral()));
    Dialog_Main_Userinfo_onlyread_Lan_Intergral_Label ->setText("Lan_Intergral:" + QString("%1").arg(Userinfo_Hash.find(MainUser).value().Get_User_Language_Intergral()));
    Dialog_Main_Userinfo_onlyread_Tas_Intergral_Label ->setText("Tas_Intergral:" + QString("%1").arg(Userinfo_Hash.find(MainUser).value().Get_User_Tasks_Intergral()));

    Dialog_Main_Userinfo_onlyread_Userinfo_onlyread_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Username_Label, 0, 1);

    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Nickname_Label, 0, 1);
    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Realname_Label, 1, 1);
    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_FreeSign_Label, 2, 1);
    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Sex_Label, 3, 1);
    Dialog_Main_Userinfo_onlyread_UserSelf_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Age_Label, 4, 1);

    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Address_Country_Label, 1, 1);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Address_Province_Label, 2, 1);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Address_City_Label, 3, 1);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_PhoneNumber_Label, 1, 3);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Email_Label, 2, 3);
    Dialog_Main_Userinfo_onlyread_Address_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_ID_Number_Label, 3, 3);

    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Language_Cet4_Label, 1, 1);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Language_Cet6_Label, 2, 1);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Language_Tem4_Label, 3, 1);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Language_Tem8_Label, 4, 1);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Language_Toefl_Label, 1, 3);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Language_Ielts_Label, 2, 3);
    Dialog_Main_Userinfo_onlyread_Language_Layout ->addWidget(Dialog_Main_Userinfo_onlyread_0_Language_Gre_Label, 3, 3);


    Dialog_Main_Userinfo_onlyread_Layout ->addLayout(Dialog_Main_Userinfo_onlyread_Userinfo_onlyread_Layout);
    Dialog_Main_Userinfo_onlyread_Layout ->addLayout(Dialog_Main_Userinfo_onlyread_UserSelf_Layout);
    Dialog_Main_Userinfo_onlyread_Layout ->addLayout(Dialog_Main_Userinfo_onlyread_Address_Layout);
    Dialog_Main_Userinfo_onlyread_Layout ->addLayout(Dialog_Main_Userinfo_onlyread_Language_Layout);

    Dialog_Main_Userinfo_onlyread_Layout ->setSpacing(25);
}
