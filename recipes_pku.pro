QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    avatarbutton.cpp \
    createwindow.cpp \
    designui.cpp \
    imagebutton.cpp \
    main.cpp \
    mainwindow.cpp \
    mystorewindow.cpp \
    postdata.cpp \
    postdatamanager.cpp \
    recipeswindow.cpp \
    userdata.cpp

HEADERS += \
    avatarbutton.h \
    createwindow.h \
    designui.h \
    imagebutton.h \
    mainwindow.h \
    mystorewindow.h \
    postdata.h \
    postdatamanager.h \
    recipeswindow.h \
    userdata.h

FORMS += \
    createwindow.ui \
    mainwindow.ui \
    mystorewindow.ui \
    recipeswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc

