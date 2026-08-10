QT       += core gui quick svg

CONFIG   += c++17

# The .pro file must explicitly list every source file
SOURCES  += \
    main.cpp \
    src/model/fueldispensermodel.cpp \
    src/controller/dispensercontroller.cpp

HEADERS  += \
    src/model/fueldispensermodel.h \
    src/controller/dispensercontroller.h

RESOURCES += \
    resources.qrc

# QML Import Path (if using Qt Creator, otherwise handled by qrc)
QML_IMPORT_PATH =

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target