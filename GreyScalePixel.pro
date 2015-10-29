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
    Facade/facade.cpp \
    GUI/imagenseleccionada.cpp \
    GUI/principalmenu.cpp \
    GUI/uploadimage.cpp \
    GUI/ventanaayuda.cpp \
    GUI/resultadofinal.cpp \
    Logic/procesarimagen.cpp

HEADERS  += Facade/facade.h \
    Logic/Constants.h \
    GUI/imagenseleccionada.h \
    GUI/principalmenu.h \
    GUI/uploadimage.h \
    GUI/ventanaayuda.h \
    GUI/resultadofinal.h \
    Logic/procesarimagen.h

FORMS    +=

OTHER_FILES += \
    Resources/FondoGreyScalePixel.jpg

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui

RESOURCES += \
    Recursos.qrc
