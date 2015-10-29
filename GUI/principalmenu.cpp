#include "GUI/principalmenu.h"

PrincipalMenu::PrincipalMenu(QWidget *parent){
    QLabel* fondo = new QLabel(this);

    QPixmap imagenFondo(":/Imagenes/Resources/fondoGreyScalePixel.jpg");
    QPixmap imagenSeleccion(":/Imagenes/Resources/botonSeleccionar.jpg");
    QPixmap imagenAyuda(":/Imagenes/Resources/botonAyuda.jpg");
    QPixmap imagenSalir(":/Imagenes/Resources/botonSalir.jpg");

    QIcon iconoAyuda(imagenAyuda);
    QIcon iconoSeleccion(imagenSeleccion);
    QIcon iconoSalir(imagenSalir);

    QPushButton* botonAyuda = new QPushButton(this);
    QPushButton* botonSeleccion = new QPushButton(this);
    QPushButton* botonSalir = new QPushButton(this);

    botonAyuda->setGeometry(545,562,imagenAyuda.width(), imagenAyuda.height());
    botonAyuda->setIcon(iconoAyuda);
    botonAyuda->setIconSize(imagenAyuda.rect().size());
    botonSeleccion->setGeometry(545,490,imagenSeleccion.width(), imagenSeleccion.height());
    botonSeleccion->setIcon(iconoSeleccion);
    botonSeleccion->setIconSize(imagenSeleccion.rect().size());
    botonSalir->setGeometry(545,632,imagenSalir.width(),imagenSalir.height());
    botonSalir->setIcon(iconoSalir);
    botonSalir->setIconSize(imagenSalir.rect().size());

    QObject::connect(botonAyuda, SIGNAL(clicked()), this, SLOT(crearVentanaAyuda()));
    QObject::connect(botonSeleccion, SIGNAL(clicked()), this, SLOT(crearVentanaDirectorio()));
    QObject::connect(botonSalir, SIGNAL(clicked()), this, SLOT(close()));

    fondo->setPixmap(imagenFondo);
    fondo->setGeometry(0,0,imagenFondo.width(),imagenFondo.height());
    this->showMaximized();
}

void PrincipalMenu::crearVentanaDirectorio(){
    uploadImage* upload = new uploadImage();
    cv::Mat matrixImage = upload->seleccionarImagen();
    if(matrixImage.data){
        imagenSeleccionada *imagen = new imagenSeleccionada();
        imagen->crearVentanaEleccion(matrixImage);
        this->close();
        this->deleteLater();
    }
}

void PrincipalMenu::crearVentanaAyuda(){
    ventanaAyuda* ayuda = new ventanaAyuda();
    this->close();
    this->deleteLater();
}

PrincipalMenu::~PrincipalMenu(){
}
