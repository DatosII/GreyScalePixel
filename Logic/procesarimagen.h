#ifndef PROCESARIMAGEN_H
#define PROCESARIMAGEN_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Constants.h"
#include <QDebug>

class procesarImagen{
private:
    int r;
    int g;
    int b;
    cv::Mat cuadricular(cv::Mat pMatriz);
    cv::Mat cuadricularAux(cv::Mat pMatriz, int pX, int pY);
    cv::Mat escalaGrises(cv::Mat pMatriz);
    cv::Mat escalaGrisesAux(cv::Mat pMatriz, int pX, int pY);
public:
    procesarImagen();
    cv::Mat* matricesProcesar(cv::Mat pMatriz);
};

#endif // PROCESARIMAGEN_H
