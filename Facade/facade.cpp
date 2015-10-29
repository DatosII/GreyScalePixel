#include "Facade/facade.h"

/**
 * @brief Facade::Facade, constructor de la clase
 */
Facade::Facade(){
    this->_imagenes = new procesarImagen();
}
/**
 * @brief Facade::enviar, metodo que le envia a la logica la imagen seleccionada
 * @param pMatriz, matriz seleccionada por el usuario
 * @return arreglo con la matriz pixeleada a color y la escala de grises
 */
cv::Mat* Facade::enviar(cv::Mat pMatriz){
    return this->_imagenes->matricesProcesar(pMatriz);
}
