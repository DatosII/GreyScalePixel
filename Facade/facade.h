#ifndef FACADE_H
#define FACADE_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Logic/procesarimagen.h"

class Facade{
private:
    procesarImagen* _imagenes;
public:
    Facade();
    cv::Mat* enviar(cv::Mat pMatriz);

};

#endif // FACADE_H
