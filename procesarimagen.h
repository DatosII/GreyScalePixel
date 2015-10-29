#ifndef PROCESARIMAGEN_H
#define PROCESARIMAGEN_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "principalmenu.h"
#include "Constants.h"


class procesarImagen : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    cv::Mat image1;
    cv::Mat image2;
    QImage finalImage1;
    QImage finalImage2;
    int r;
    int g;
    int b;
    void cuadricular();
    void cuadricularAux(int pX, int pY);
    void escalaGrises();
    void escalaGrisesAux(int pX, int pY);
    void convertMatrix(cv::Mat matrixImage, std::string pType);
public:
    procesarImagen(QWidget *parent = 0);
    void newWIndow(cv::Mat matrixImage);
public slots:
    void volver();

};

#endif // PROCESARIMAGEN_H
