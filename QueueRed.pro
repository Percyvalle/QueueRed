VERSION = 0.1.4

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT       += core gui sql network

MOC_DIR = .build
OBJECTS_DIR = .build
UI_DIR = .build


SOURCES += \
    src/QueueRedDatabaseManager.cpp \
    src/QueueRedMainWindow.cpp \
    src/QueueRedProfile.cpp \
    src/QueueRedProfileMember.cpp \
    src/QueueRedProfileWidget.cpp \
    src/main.cpp

HEADERS += \
    src/QueueRedDatabaseManager.h \
    src/QueueRedMainWindow.h \
    src/QueueRedProfile.h \
    src/QueueRedProfileMember.h \
    src/QueueRedProfileWidget.h

FORMS += \
    src/QueueRedMainWindow.ui

RESOURCES += \
    resource.qrc
