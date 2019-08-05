#-------------------------------------------------
#
# Project created by QtCreator 2019-07-25T19:30:59
#
#-------------------------------------------------

QT       += core gui
QT       += sql xml
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 22_frontend
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        connection.cpp \
        connection_taskinfo.cpp \
        connection_userinfo.cpp \
        dialog_admin.cpp \
        dialog_main_message.cpp \
        dialog_main_peoplelist.cpp \
        dialog_main_peoplelist_task.cpp \
        dialog_main_peoplelist_trans.cpp \
        dialog_main_task.cpp \
        dialog_main_task_exchange.cpp \
        dialog_main_task_tab.cpp \
        dialog_main_task_tab_endtask.cpp \
        dialog_main_task_tab_link_role_0.cpp \
        dialog_main_task_tab_link_role_1_state_0.cpp \
        dialog_main_task_tab_link_role_1_state_1.cpp \
        dialog_main_task_tab_link_role_1_state_1_tab_0.cpp \
        dialog_main_task_tab_link_role_1_state_1_tab_1.cpp \
        dialog_main_task_tab_link_role_1_state_1_tab_2.cpp \
        dialog_main_task_tab_link_role_2_state_2.cpp \
        dialog_main_task_tab_link_role_2_state_2_tab_1.cpp \
        dialog_main_task_tab_link_state_4.cpp \
        dialog_main_task_tab_new.cpp \
        dialog_main_userinfo.cpp \
        dialog_main_userinfo_onlyread.cpp \
        dialog_signup.cpp \
        main.cpp \
        dialog_main.cpp \
        message.cpp \
        role_change.cpp \
        task.cpp \
        task_infomation.cpp \
        user.cpp \
        user_language_qualification.cpp

HEADERS += \
        connection.h \
        connection_taskinfo.h \
        connection_userinfo.h \
        dialog_admin.h \
        dialog_main.h \
        dialog_main_message.h \
        dialog_main_peoplelist.h \
        dialog_main_peoplelist_task.h \
        dialog_main_peoplelist_trans.h \
        dialog_main_task.h \
        dialog_main_task_exchange.h \
        dialog_main_task_tab.h \
        dialog_main_task_tab_endtask.h \
        dialog_main_task_tab_link_role_0.h \
        dialog_main_task_tab_link_role_1_state_0.h \
        dialog_main_task_tab_link_role_1_state_1.h \
        dialog_main_task_tab_link_role_1_state_1_tab_0.h \
        dialog_main_task_tab_link_role_1_state_1_tab_1.h \
        dialog_main_task_tab_link_role_1_state_1_tab_2.h \
        dialog_main_task_tab_link_role_2_state_2.h \
        dialog_main_task_tab_link_role_2_state_2_tab_1.h \
        dialog_main_task_tab_link_state_4.h \
        dialog_main_task_tab_new.h \
        dialog_main_userinfo.h \
        dialog_main_userinfo_onlyread.h \
        dialog_signup.h \
        message.h \
        project.h \
        role_change.h \
        task.h \
        task_infomation.h \
        user.h \
        user_caps.h \
        user_language_qualification.h

FORMS += \
        dialog_main.ui \
        dialog_signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
