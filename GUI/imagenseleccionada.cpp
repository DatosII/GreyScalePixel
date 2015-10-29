#include "GUI/imagenseleccionada.h"

/**
 * @brief imagenSeleccionada::imagenSeleccionada, constructor de la clase
 * @param parent
 */
imagenSeleccionada::imagenSeleccionada(QWidget *parent){
    this->pFacade = new Facade();
    this->fondo = new QLabel(this);
}
/**
 * @brief imagenSeleccionada::crearVentanaEleccion, crea la ventana para mostrar la imagen seleccionada
 * @param matrixImage
 */
void imagenSeleccionada::crearVentanaEleccion(cv::Mat matrixImage){
    this->_matrix=matrixImage(cv::Rect(CONSTANSGUI::CERO, CONSTANSGUI::CERO, (matrixImage.cols-(matrixImage.cols%CONSTANSGUI::TAMANO)), (matrixImage.rows-(matrixImage.rows%CONSTANSGUI::TAMANO))));
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
    painter->drawPixmap(CONSTANSGUI::CERO, CONSTANSGUI::CERO, imagenFondo.width(), imagenFondo.height(), imagenFondo);
    painter->drawPixmap(122, 134, this->image.width(), this->image.height(), QPixmap::fromImage(this->image));
    painter->end();
    this->fondo->setPixmap(*pixmap);
    this->fondo->resize(QSize(imagenFondo.width(),imagenFondo.height()));
    this->showMaximized();
}
/**
 * @brief imagenSeleccionada::convertirMatrix, Este metodo permite convertir un cv::Mat a un QImage
 * @param matrixImage, imagen en formato cv::Mat
 */
void imagenSeleccionada::convertirMatrix(cv::Mat matrixImage){
    if(matrixImage.type()==CV_8UC1){
        QVector<QRgb> colorTable;
        for (int i=CONSTANSGUI::CERO; i<256; i++)
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
/**
 * @brief imagenSeleccionada::procesar, Metodo que pasa la matriz al facade, los resultados a la ventana final
 */
void imagenSeleccionada::procesar(){
    cv::Mat* resultado = this->pFacade->enviar(this->_matrix);
    resultadoFinal* imagen = new resultadoFinal();
    imagen->ventanaFinal(resultado[CONSTANSGUI::CERO], resultado[CONSTANSGUI::UNO]);
    this->close();
    this->deleteLater();
}
