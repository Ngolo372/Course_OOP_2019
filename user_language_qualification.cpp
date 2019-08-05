#include "user_language_qualification.h"


User_Language_Qualification::User_Language_Qualification()
{
     cet4_score = 0;
     cet6_score = 0;
     tem4_score = 0;
     tem8_score = 0;
     toefl_score = 0;
     ielts_score = 0;
     gre_score = 0;
}

User_Language_Qualification::~User_Language_Qualification()
{

}

void User_Language_Qualification::set_cet4_score(unsigned short cet4_score0)
{
    if(cet4_score0 <= 710)
    {
        cet4_score = cet4_score0;
        if(cet4_score < 426)cet4_level = 'F';
        else if(426 <= cet4_score && cet4_score < 600)cet4_level = 'P';
        else if(600 <=cet4_score)cet4_level = 'A';
    }
}

void User_Language_Qualification::set_cet6_score(unsigned short cet6_score0)
{
    if(cet6_score0 <= 710)
    {
        cet6_score = cet6_score0;
        if(cet6_score < 426)cet6_level = 'F';
        else if(426 <= cet6_score && cet6_score < 600)cet6_level = 'P';
        else if(600 <= cet6_score)cet6_level = 'A';
    }
}


void User_Language_Qualification::set_tem4_score(unsigned short tem4_score0)
{
    if(tem4_score0 <=100)
    {
        tem4_score = tem4_score0;
        if(tem4_score < 60)tem4_level = 'F';
        else if(60 <= tem4_score && tem4_score < 90)tem4_level = 'P';
        else if(90 <= tem4_score)tem4_level = 'A';
    }

}

void User_Language_Qualification::set_tem8_score(unsigned short tem8_score0)
{
    if(tem8_score0 <=100)
    {
        tem8_score = tem8_score0;
        if(tem8_score < 60)tem8_level = 'F';
        else if(60 <= tem8_score && tem8_score < 90)tem8_level = 'P';
        else if(90 <= tem8_score)tem8_level = 'A';
    }

}

void User_Language_Qualification::set_toefl_score(unsigned short toefl_score0)
{
    toefl_score = toefl_score0;
}

void User_Language_Qualification::set_ielts_score(unsigned short ielts_score0)
{
    ielts_score = ielts_score0;
}

void User_Language_Qualification::set_gre_score(unsigned short gre_score0)
{
    gre_score = gre_score0;
}


uint16_t User_Language_Qualification::get_cet4_score()const
{
    return cet4_score;
}

char User_Language_Qualification::get_cet4_level()const
{
    return cet4_level;
}

uint16_t User_Language_Qualification::get_cet6_score()const
{
    return cet6_score;
}

char User_Language_Qualification::get_cet6_level()const
{
    return cet6_level;
}

uint16_t User_Language_Qualification::get_tem4_score()const
{
    return tem4_score;
}

char User_Language_Qualification::get_tem4_level()const
{
    return tem4_level;
}

uint16_t User_Language_Qualification::get_tem8_score()const
{
    return tem8_score;
}

char User_Language_Qualification::get_tem8_level()const
{
    return tem8_level;
}


uint16_t User_Language_Qualification::get_toefl_score()const
{
    return toefl_score;
}

uint16_t User_Language_Qualification::get_ielts_score()const
{
    return ielts_score;
}

uint16_t User_Language_Qualification::get_gre_score()const
{
    return gre_score;
}
