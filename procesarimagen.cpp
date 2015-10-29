#include "procesarimagen.h"

procesarImagen::procesarImagen(QWidget *parent){
    this->fondo = new QLabel(this);
}

void procesarImagen::newWIndow(cv::Mat matrixImage){
    this->r=0;
    this->g=0;
    this->b=0;
    this->image1 = matrixImage;
    this->image2 = this->image1.clone();
    QPixmap imagenFondo(":/Imagenes/Resources/fondoGeneral.jpg");
    QPixmap imagenVolver(":/Imagenes/Resources/botonVolver.jpg");
    QIcon iconoVolver(imagenVolver);
    QPushButton* botonVolver = new QPushButton(this);
    botonVolver->setGeometry(1169,0,imagenVolver.width(), imagenVolver.height());
    botonVolver->setIcon(iconoVolver);
    botonVolver->setIconSize(imagenVolver.rect().size());

    QObject::connect(botonVolver, SIGNAL(clicked()), this, SLOT(volver()));


    cuadricular();
    escalaGrises();
    convertMatrix(this->image1, "color");
    convertMatrix(this->image2, "gris");

    QPixmap *pixmap=new QPixmap(imagenFondo.width(), imagenFondo.height());
    QPainter *painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, imagenFondo.width(), imagenFondo.height(), imagenFondo);
    painter->drawPixmap(122, 134, this->finalImage1.width(), this->finalImage1.height(), QPixmap::fromImage(this->finalImage1));
    painter->drawPixmap(744, 134, this->finalImage2.width(), this->finalImage2.height(), QPixmap::fromImage(this->finalImage2));
    painter->end();


    this->fondo->setPixmap(*pixmap);
    this->fondo->resize(QSize(imagenFondo.width(),imagenFondo.height()));
    this->showMaximized();
}

void procesarImagen::convertMatrix(cv::Mat matrixImage, std::string pType){
    if(matrixImage.type()==CV_8UC1){
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        const uchar *qImageBuffer = (const uchar*)matrixImage.data;
        QImage newImage(qImageBuffer, matrixImage.cols, matrixImage.rows, matrixImage.step, QImage::Format_Indexed8);
        newImage.setColorTable(colorTable);
        if(pType=="color")
            this->finalImage1 = newImage;
        else
            this->finalImage2 = newImage;
    }
    else if(matrixImage.type()==CV_8UC3){
        const uchar *qImageBuffer = (const uchar*)matrixImage.data;
        QImage newImage(qImageBuffer, matrixImage.cols, matrixImage.rows, matrixImage.step, QImage::Format_RGB888);
        if(pType=="color")
            this->finalImage1 = newImage.rgbSwapped();
        else
            this->finalImage2 = newImage.rgbSwapped();
    }
}

void procesarImagen::cuadricular(){
    for(int x = 0; x<this->image1.cols; x+=CONSTANS::TAMANO)
        for(int y =0; y<this->image1.rows; y+=CONSTANS::TAMANO)
            cuadricularAux(x, y);
}

void procesarImagen::cuadricularAux(int pX, int pY){
    for(int x = pX; x<pX+CONSTANS::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANS::TAMANO; y++){
            b = (b+(int)this->image1.at<cv::Vec3b>(y,x)[0])/2;
            g = (g+(int)this->image1.at<cv::Vec3b>(y,x)[1])/2;
            r = (r+(int)this->image1.at<cv::Vec3b>(y,x)[2])/2;
        }
    }
    for(int x = pX; x<pX+CONSTANS::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANS::TAMANO; y++){
            this->image1.at<cv::Vec3b>(y,x)[0]=b;
            this-> image1.at<cv::Vec3b>(y,x)[1]=g;
            this->image1.at<cv::Vec3b>(y,x)[2]=r;
        }
    }
}

void procesarImagen::escalaGrises(){
    for(int x = 0; x<this->image2.cols; x+=CONSTANS::TAMANO)
        for(int y =0; y<this->image2.rows; y+=CONSTANS::TAMANO)
            escalaGrisesAux(x, y);
}

void procesarImagen::escalaGrisesAux(int pX, int pY){
    for(int x = pX; x<pX+CONSTANS::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANS::TAMANO; y++){
            b = (b+(int)this->image2.at<cv::Vec3b>(y,x)[0])/2;
            g = (g+(int)this->image2.at<cv::Vec3b>(y,x)[1])/2;
            r = (r+(int)this->image2.at<cv::Vec3b>(y,x)[2])/2;
        }
    }
    int colorGris = (r+g+b)/3;
    for(int x = pX; x<pX+CONSTANS::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANS::TAMANO; y++){
            this->image2.at<cv::Vec3b>(y,x)[0]=colorGris;
            this->image2.at<cv::Vec3b>(y,x)[1]=colorGris;
            this->image2.at<cv::Vec3b>(y,x)[2]=colorGris;
        }
    }
}

void procesarImagen::volver(){
    PrincipalMenu* menu = new PrincipalMenu();
    this->close();
    this->deleteLater();
}
