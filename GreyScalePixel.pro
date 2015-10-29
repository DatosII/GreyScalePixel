#-------------------------------------------------
#
# Project created by QtCreator 2015-10-25T22:22:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GreyScalePixel
TEMPLATE = app


SOURCES += main.cpp\
        principalmenu.cpp \
    uploadimage.cpp \
    imagenseleccionada.cpp \
    procesarimagen.cpp \
    ventanaayuda.cpp \
    facade.cpp

HEADERS  += principalmenu.h \
    uploadimage.h \
    imagenseleccionada.h \
    procesarimagen.h \
    ventanaayuda.h \
    Constants.h \
    facade.h

FORMS    +=

OTHER_FILES += \
    Resources/FondoGreyScalePixel.jpg

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui

RESOURCES += \
    Recursos.qrc
