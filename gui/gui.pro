TEMPLATE = app
TARGET = hub-gui

QT = core gui

HEADERS = hubmainwidget.h \
          hubshiftwidget.h \
          hubvaluewidget.h

SOURCES = main.cpp \
          hubmainwidget.cpp \
          hubshiftwidget.cpp \
          hubvaluewidget.cpp

target.path = /usr/bin/
INSTALLS += target
