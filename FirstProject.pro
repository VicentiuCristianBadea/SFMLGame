QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        enemy.cpp \
        game.cpp \
        main.cpp \
        node.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    game.h \
    node.h

#-----------------------------------------------------------
# LINUX

LIBS += -lsfml-audio
LIBS += -lsfml-graphics
LIBS += -lsfml-network
LIBS += -lsfml-window
LIBS += -lsfml-system

#-----------------------------------------------------------
#WINDOWS

#LIBS += -L$$PWD/../Libraries/SFML-2.5.1/lib
#LIBS += -L$$PWD/../Libraries/SFML-2.5.1/bin

#CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
#CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#INCLUDEPATH += $$PWD/../Libraries/SFML-2.5.1/include
#DEPENDPATH += $$PWD/../Libraries/SFML-2.5.1/include


