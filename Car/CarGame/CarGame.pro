TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Logger.cpp \
    UFerrariEngine.cpp \
        main.cpp \
    Car.cpp


LIBS += "$$PWD/FerrariEngine.dll"

HEADERS += \
    Engine.h \
    FerrariEngine.h \
    Car.h \
    Logger.h \
    UFerrariEngine.h \
    utilities.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Ferrari/build-FerrariEngine-Qt_5_12_0_mingw73_64_temporary-Debug/release/ -lFerrariEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Ferrari/build-FerrariEngine-Qt_5_12_0_mingw73_64_temporary-Debug/debug/ -lFerrariEngine
else:unix: LIBS += -L$$PWD/../../Ferrari/build-FerrariEngine-Qt_5_12_0_mingw73_64_temporary-Debug/ -lFerrariEngine

INCLUDEPATH += $$PWD/../../Ferrari/build-FerrariEngine-Qt_5_12_0_mingw73_64_temporary-Debug/debug
DEPENDPATH += $$PWD/../../Ferrari/build-FerrariEngine-Qt_5_12_0_mingw73_64_temporary-Debug/debug
