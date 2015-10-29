#include "GUI/imagenseleccionada.h"

imagenSeleccionada::imagenSeleccionada(QWidget *parent){
    this->pFacade = new Facade();
    this->fondo = new QLabel(this);
}

void imagenSeleccionada::crearVentanaEleccion(cv::Mat matrixImage){
    this->_matrix=matrixImage(cv::Rect(0, 0, (matrixImage.cols-(matrixImage.cols%CONSTANS::TAMANO)), (matrixImage.rows-(matrixImage.rows%CONSTANS::TAMANO))));
    QPixmap imagenFondo(":/Imagenes/Resources/fondoGeneral.jpg");
    QPixmap imagenProcesar(":/Imagenes/Resources/botonProcesarImagen.jpg");
    QIcon iconoProcesar(imagenProcesar);
    QPushButton* botonProcesar = new QPushButton(this);
    botonProcesar->setGeometry(860,280,imagenProcesar.width(), imagenProcesar.height());
    botonProcesar->setIcon(iconoProcesar);
    botonProcesar->setIconSize(imagenProcesar.rect().size());

    QObject::connect(botonProcesar, SIGNAL(clicked()), this, SLOT(procesar()));
    convertirMatrix(matrixImage);

    QPixmap *pixmap=new QPixmap(imagenFondo.width(), imagenFondo.height());
    QPainter *painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, imagenFondo.width(), imagenFondo.height(), imagenFondo);
    painter->drawPixmap(122, 134, this->image.width(), this->image.height(), QPixmap::fromImage(this->image));
    painter->end();

    this->fondo->setPixmap(*pixmap);
    this->fondo->resize(QSize(imagenFondo.width(),imagenFondo.height()));
    this->showMaximized();
}

void imagenSeleccionada::convertirMatrix(cv::Mat matrixImage){
    if(matrixImage.type()==CV_8UC1){
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        const uchar *qImageBuffer = (const uchar*)matrixImage.data;
        QImage newImage(qImageBuffer, matrixImage.cols, matrixImage.rows, matrixImage.step, QImage::Format_Indexed8);
        newImage.setColorTable(colorTable);
        this->image = newImage;
    }
    else if(matrixImage.type()==CV_8UC3){
        const uchar *qImageBuffer = (const uchar*)matrixImage.data;
        QImage newImage(qImageBuffer, matrixImage.cols, matrixImage.rows, matrixImage.step, QImage::Format_RGB888);
        this->image = newImage.rgbSwapped();
    }
}

void imagenSeleccionada::procesar(){
    cv::Mat* resultado = this->pFacade->enviar(this->_matrix);
    resultadoFinal* imagen = new resultadoFinal();
    imagen->ventanaFinal(resultado[0], resultado[1]);
    this->close();
    this->deleteLater();
}
