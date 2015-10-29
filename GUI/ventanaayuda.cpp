#include "GUI/ventanaayuda.h"

ventanaAyuda::ventanaAyuda(QWidget *parent){
    QLabel* fondo = new QLabel(this);

    QPixmap imagenFondo(":/Imagenes/Resources/fondoAyuda.jpg");
    QPixmap imagenVolver(":/Imagenes/Resources/botonVolver.jpg");
    QIcon iconoVolver(imagenVolver);
    QPushButton* botonVolver = new QPushButton(this);
    botonVolver->setGeometry(1169,0,imagenVolver.width(), imagenVolver.height());
    botonVolver->setIcon(iconoVolver);
    botonVolver->setIconSize(imagenVolver.rect().size());

    QObject::connect(botonVolver, SIGNAL(clicked()), this, SLOT(volver()));
    fondo->setPixmap(imagenFondo);
    fondo->setGeometry(0,0,imagenFondo.width(),imagenFondo.height());
    this->showMaximized();
}

void ventanaAyuda::volver(){
    PrincipalMenu* menu = new PrincipalMenu();
    this->close();
    this->deleteLater();
}
