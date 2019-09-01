#-------------------------------------------------
#
# Project created by QtCreator 2019-08-26T21:11:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DAG_For_LinkedList
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
        dialog_addarc.cpp \
        dialog_addvex.cpp \
        dialog_criticalpath.cpp \
        dialog_deletearc.cpp \
        dialog_deletevex.cpp \
        dialog_failalert.cpp \
        dialog_showadjacentlist.cpp \
        dialog_successalert.cpp \
        dialog_topologysort.cpp \
        dialog_vexinit.cpp \
        graph.cpp \
        main.cpp \
        mainwindow.cpp \
        queue.cpp \
        stack.cpp

HEADERS += \
        dialog_addarc.h \
        dialog_addvex.h \
        dialog_criticalpath.h \
        dialog_deletearc.h \
        dialog_deletevex.h \
        dialog_failalert.h \
        dialog_showadjacentlist.h \
        dialog_successalert.h \
        dialog_topologysort.h \
        dialog_vexinit.h \
        graph.h \
        mainwindow.h \
        queue.h \
        stack.h

FORMS += \
        ../DepartmentMangagement/dialog_failalert.ui \
        ../DepartmentMangagement/dialog_successalert.ui \
        dialog_addarc.ui \
        dialog_addvex.ui \
        dialog_criticalpath.ui \
        dialog_deletearc.ui \
        dialog_deletevex.ui \
        dialog_failalert.ui \
        dialog_showadjacentlist.ui \
        dialog_successalert.ui \
        dialog_topologysort.ui \
        dialog_vexinit.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_FILE += icon2.rc
