//用户角色 int -> QString 转换

#include "role_change.h"

QString role_change(int role)
{
    switch (role) {
    case 0:
        return "no relation";
    case 1:
        return "publisher";
    case 2:
        return "header";
    case 3:
        return "reviewer";
    case 4:
        return "translator";
    case 5:
        return "pre_header";
    case 6:
        return "pre_reviewer";
    case 7:
        return "pre_translator";
    }
}
