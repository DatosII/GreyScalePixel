#include "GUI/ventanaayuda.h"

/**
 * @brief ventanaAyuda::ventanaAyuda, Constructor de la clase, crea la ventana de ayuda
 * @param parent
 */
ventanaAyuda::ventanaAyuda(QWidget *parent){
    QLabel* fondo = new QLabel(this);
    QPixmap imagenFondo(":/Imagenes/Resources/fondoAyuda.jpg");
    QPixmap imagenVolver(":/Imagenes/Resources/botonVolver.jpg");
    QIcon iconoVolver(imagenVolver);
    QPushButton* botonVolver = new QPushButton(this);
    botonVolver->setGeometry(CONSTANSGUI::POSXVOLVER, CONSTANSGUI::CERO,imagenVolver.width(), imagenVolver.height());
    botonVolver->setIcon(iconoVolver);
    botonVolver->setIconSize(imagenVolver.rect().size());
    QObject::connect(botonVolver, SIGNAL(clicked()), this, SLOT(volver()));
    fondo->setPixmap(imagenFondo);
    fondo->setGeometry(CONSTANSGUI::CERO, CONSTANSGUI::CERO,imagenFondo.width(),imagenFondo.height());
    this->showMaximized();
}
/**
 * @brief ventanaAyuda::volver, Metodo para volver al menu principal
 */
void ventanaAyuda::volver(){
    PrincipalMenu* menu = new PrincipalMenu();
    this->close();
    this->deleteLater();
}
