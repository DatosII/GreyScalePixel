#include "procesarimagen.h"

/**
 * @brief procesarImagen::procesarImagen, Constructor de la clase
 */
procesarImagen::procesarImagen(){
}
/**
 * @brief procesarImagen::matricesProcesar, Metodo
 * @param pMatriz
 * @return
 */
cv::Mat* procesarImagen::matricesProcesar(cv::Mat pMatriz){
    this->r = CONSTANSLOGIC::CERO;
    this->g = CONSTANSLOGIC::CERO;
    this->b = CONSTANSLOGIC::CERO;
    cv::Mat mColor=pMatriz.clone();
    cv::Mat mGris=pMatriz.clone();
    cv::Mat* resultado = new cv::Mat[CONSTANSLOGIC::DOS];
    resultado[CONSTANSLOGIC::CERO]=cuadricular(mColor);
    resultado[CONSTANSLOGIC::UNO]=escalaGrises(mGris);
    return resultado;
}
/**
 * @brief procesarImagen::cuadricular, Metodo que define los limites de la cuadriculacion
 * @param pMatriz, matriz a trabajar
 * @return matriz procesada
 */
cv::Mat procesarImagen::cuadricular(cv::Mat pMatriz){
    for(int x = CONSTANSLOGIC::CERO; x<pMatriz.cols; x+=CONSTANSLOGIC::TAMANO)
        for(int y = CONSTANSLOGIC::CERO; y<pMatriz.rows; y+=CONSTANSLOGIC::TAMANO)
            cuadricularAux(pMatriz, x, y);
    return pMatriz;
}
/**
 * @brief procesarImagen::cuadricularAux, Metodo auxiliar que permite recorrer los cuadros para obtener el bgr y
 * modificar la imagen
 * @param pMatriz, matriz a trabajar
 * @param pX, posicion x de la matriz
 * @param pY, posicion y de la matriz
 * @return parte de la matriz procesada
 */
cv::Mat procesarImagen::cuadricularAux(cv::Mat pMatriz, int pX, int pY){
    for(int x = pX; x<pX+CONSTANSLOGIC::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANSLOGIC::TAMANO; y++){
            b = (b+(int)pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::CERO])/CONSTANSLOGIC::DOS;
            g = (g+(int)pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::UNO])/CONSTANSLOGIC::DOS;
            r = (r+(int)pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::DOS])/CONSTANSLOGIC::DOS;
        }
    }
    for(int x = pX; x<pX+CONSTANSLOGIC::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANSLOGIC::TAMANO; y++){
            pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::CERO]=b;
            pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::UNO]=g;
            pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::DOS]=r;
        }
    }
    return pMatriz;
}
/**
 * @brief procesarImagen::escalaGrises,  Metodo que define los limites de la cuadriculacion
 * @param pMatriz, matriz a trabajar
 * @return matriz procesada
 */
cv::Mat procesarImagen::escalaGrises(cv::Mat pMatriz){
    for(int x = CONSTANSLOGIC::CERO; x<pMatriz.cols; x+=CONSTANSLOGIC::TAMANO)
        for(int y =CONSTANSLOGIC::CERO; y<pMatriz.rows; y+=CONSTANSLOGIC::TAMANO)
            escalaGrisesAux(pMatriz, x, y);
    return pMatriz;
}
/**
 * @brief procesarImagen::escalaGrisesAux, Metodo auxiliar que permite recorrer los cuadros para obtener el bgr y
 * modificar la imagen, sacando un promedio entre ellos y poder asignarlos a llos pixeles
 * @param pMatriz, matriz a trabajar
 * @param pX, posicion x de la matriz
 * @param pY, posicion y de la matriz
 * @return parte de la matriz procesada
 */
cv::Mat procesarImagen::escalaGrisesAux(cv::Mat pMatriz, int pX, int pY){
    for(int x = pX; x<pX+CONSTANSLOGIC::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANSLOGIC::TAMANO; y++){
            b = (b+(int)pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::CERO])/CONSTANSLOGIC::DOS;
            g = (g+(int)pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::UNO])/CONSTANSLOGIC::DOS;
            r = (r+(int)pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::DOS])/CONSTANSLOGIC::DOS;
        }
    }
    int colorGris = (r+g+b)/CONSTANSLOGIC::TRES;
    for(int x = pX; x<pX+CONSTANSLOGIC::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANSLOGIC::TAMANO; y++){
            pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::CERO]=colorGris;
            pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::UNO]=colorGris;
            pMatriz.at<cv::Vec3b>(y,x)[CONSTANSLOGIC::DOS]=colorGris;
        }
    }
    return pMatriz;
}
