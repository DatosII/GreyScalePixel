#ifndef PROCESARIMAGEN_H
#define PROCESARIMAGEN_H

#include <opencv2/opencv.hpp>
#include "Logic/constantsLogic.h"
/**
 * @files procesarimagen.h
 * @brief The procesarImagen class, Clase para convertir la imagen a la forma deseada
 * @author Jairo Daniel Ortega Calderon
 * @date October 10, 2015 *
 */
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
