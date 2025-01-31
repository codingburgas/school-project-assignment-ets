QT       += core gui
QT += network
QT += core network
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    blueprintwidget.cpp \
    chat.cpp \
    databaseManager.cpp \
    main.cpp \
    mainwindow.cpp \
    message.cpp \
    messagewidget.cpp \
    profilewidget.cpp \
    register.cpp \
    encrypt.cpp \
    searchUser.cpp \
    signin.cpp \
    user.cpp

HEADERS += \
    encrypt.h \
    blueprintwidget.h \
    chat.h \
    databaseManager.h \
    mainwindow.h \
    message.h \
    messagewidget.h \
    profilewidget.h \
    register.h \
    searchUser.h \
    signin.h \
    user.h

FORMS += \
    blueprintwidget.ui \
    chat.ui \
    mainwindow.ui \
    messagewidget.ui \
    register.ui \
    signin.ui \
    subject.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    blueprint.qrc
