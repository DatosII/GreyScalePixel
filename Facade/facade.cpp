#include "Facade/facade.h"

Facade::Facade(){
    this->_imagenes = new procesarImagen();
}

cv::Mat* Facade::enviar(cv::Mat pMatriz){
    return this->_imagenes->matricesProcesar(pMatriz);
}
