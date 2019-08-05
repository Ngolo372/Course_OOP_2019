//用户语言资质

#ifndef USER_LANGUAGE_QUALIFICATION_H
#define USER_LANGUAGE_QUALIFICATION_H

#define uint16_t     unsigned short int

class User_Language_Qualification
{
public:
    User_Language_Qualification();
    ~User_Language_Qualification();

    void set_cet4_score(uint16_t cet4_score0);
    void set_cet6_score(uint16_t cet6_score0);
    void set_tem4_score(uint16_t tem4_score0);
    void set_tem8_score(uint16_t tem8_score0);
    void set_toefl_score(uint16_t toefl_score0);
    void set_ielts_score(uint16_t ielts_score0);
    void set_gre_score(uint16_t gre_score0);

    uint16_t get_cet4_score()const;
    char get_cet4_level()const;
    uint16_t get_cet6_score()const;
    char get_cet6_level()const;
    uint16_t get_tem4_score()const;
    char get_tem4_level()const;
    uint16_t get_tem8_score()const;
    char get_tem8_level()const;
    uint16_t get_toefl_score()const;
    uint16_t get_ielts_score()const;
    uint16_t get_gre_score()const;


private:
    uint16_t cet4_score;
    char cet4_level;
    uint16_t cet6_score;
    char cet6_level;
    uint16_t tem4_score;
    char tem4_level;
    uint16_t tem8_score;
    char tem8_level;
    uint16_t toefl_score;
    uint16_t ielts_score;
    uint16_t gre_score;
};

#endif // USER_LANGUAGE_QUALIFICATION_H
