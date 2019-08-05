/* 文件名 dialog_admin.h
 * 用途  定义 dialog_admin 类： 平台管理员操作入口
*/

#ifndef DIALOG_ADMIN_H
#define DIALOG_ADMIN_H

#include <QWidget>
#include "project.h"
#include "user.h"

/* 类名 dialog_admin
 * 用途  ： 平台管理员操作入口
*/
class dialog_admin : public QWidget
{
    Q_OBJECT
public:
    explicit dialog_admin(QWidget *parent = nullptr);

signals:

public slots:


    /* 函数名 admin_login（）
     * 用途  当输入密码匹配平台密码， 进入管理员操作模式
    */
    void admin_login();


    /* 函数名 change_integral（）
     * 用途  点击Apply 保存管理员修改信息
    */
    void change_integral();

private:
    //界面元素
    QLabel *adminLabel;
    QLineEdit *adminEdit;
    QPushButton *adminButton;
    QPushButton *applyButton;
    QTableWidget *adminTable_user;
    QHBoxLayout *adminToplayout;
    QVBoxLayout *adminLayout;
};

#endif // DIALOG_ADMIN_H
