#include "resultadofinal.h"
/**
 * @brief resultadoFinal::resultadoFinal, constructor de la clase
 * @param parent
 */
resultadoFinal::resultadoFinal(QWidget *parent){
    this->fondo = new QLabel(this);
}
/**
 * @brief resultadoFinal::ventanaFinal, Metodo que crea la ventana para mostrar los resultados
 * @param pMatrixColor
 * @param pMatrixGris
 */
void resultadoFinal::ventanaFinal(cv::Mat pMatrixColor, cv::Mat pMatrixGris){
    this->_matrizColor = pMatrixColor;
    this->_matrizGris = pMatrixGris;
    QPixmap imagenFondo(":/Imagenes/Resources/fondoGeneral.jpg");
    QPixmap imagenVolver(":/Imagenes/Resources/botonVolver.jpg");
    QIcon iconoVolver(imagenVolver);
    QPushButton* botonVolver = new QPushButton(this);
    botonVolver->setGeometry(1169, CONSTANSGUI::CERO,imagenVolver.width(), imagenVolver.height());
    botonVolver->setIcon(iconoVolver);
    botonVolver->setIconSize(imagenVolver.rect().size());
    QObject::connect(botonVolver, SIGNAL(clicked()), this, SLOT(volver()));
    convertirMatrix(this->_matrizColor, "color");
    convertirMatrix(this->_matrizGris, "gris");
    QPixmap *pixmap=new QPixmap(imagenFondo.width(), imagenFondo.height());
    QPainter *painter=new QPainter(pixmap);
    painter->drawPixmap(CONSTANSGUI::CERO, CONSTANSGUI::CERO, imagenFondo.width(), imagenFondo.height(), imagenFondo);
    painter->drawPixmap(122, 134, this->_imagenColor.width(), this->_imagenColor.height(), QPixmap::fromImage(this->_imagenColor));
    painter->drawPixmap(744, 134, this->_imagenGris.width(), this->_imagenGris.height(), QPixmap::fromImage(this->_imagenGris));
    painter->end();
    this->fondo->setPixmap(*pixmap);
    this->fondo->resize(QSize(imagenFondo.width(),imagenFondo.height()));
    this->showMaximized();
}
/**
 * @brief resultadoFinal::convertirMatrix, Metodo que permite convertir un cv::Mat a QImage
 * @param pMatrixImage, matriz a convertir
 * @param pType, Tipo de conversion (imagen a color o escala grises)
 */
void resultadoFinal::convertirMatrix(cv::Mat pMatrixImage, std::string pType){
    if(pMatrixImage.type()==CV_8UC1){
        QVector<QRgb> colorTable;
        for (int i=CONSTANSGUI::CERO; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        const uchar *qImageBuffer = (const uchar*)pMatrixImage.data;
        QImage newImage(qImageBuffer, pMatrixImage.cols, pMatrixImage.rows, pMatrixImage.step, QImage::Format_Indexed8);
        newImage.setColorTable(colorTable);
        if(pType=="color")
            this->_imagenColor = newImage;
        else
            this->_imagenGris = newImage;
    }
    else if(pMatrixImage.type()==CV_8UC3){
        const uchar *qImageBuffer = (const uchar*)pMatrixImage.data;
        QImage newImage(qImageBuffer, pMatrixImage.cols, pMatrixImage.rows, pMatrixImage.step, QImage::Format_RGB888);
        if(pType=="color")
            this->_imagenColor = newImage.rgbSwapped();
        else
            this->_imagenGris = newImage.rgbSwapped();
    }
}
/**
 * @brief resultadoFinal::volver, Metodo que permite volver al menu principal
 */
void resultadoFinal::volver(){
    PrincipalMenu* menu = new PrincipalMenu();
    this->close();
    this->deleteLater();
}
