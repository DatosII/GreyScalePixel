#ifndef FACADE_H
#define FACADE_H

#include <opencv2/opencv.hpp>
#include "Logic/procesarimagen.h"

/**
 * @file facade.h
 * @brief The Facade class, Comunica GUI con Logic. Esta clase permite la comunicacion
 *  entre ambas partes, pasando la imagen seleccionada
 * @author Jairo Daniel Ortega Calderon
 * @date October 10, 2015
 */
class Facade{
private:
    procesarImagen* _imagenes;
public:
    Facade();
    cv::Mat* enviar(cv::Mat pMatriz);

};

#endif // FACADE_H
