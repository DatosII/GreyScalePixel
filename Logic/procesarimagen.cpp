#include "procesarimagen.h"

procesarImagen::procesarImagen(){
}

cv::Mat* procesarImagen::matricesProcesar(cv::Mat pMatriz){
    this->r=0;
    this->g=0;
    this->b=0;
    cv::Mat mColor=pMatriz.clone();
    cv::Mat mGris=pMatriz.clone();
    cv::Mat* resultado = new cv::Mat[2];
    resultado[0]=cuadricular(mColor);
    resultado[1]=escalaGrises(mGris);
    return resultado;
}

cv::Mat procesarImagen::cuadricular(cv::Mat pMatriz){
    for(int x = 0; x<pMatriz.cols; x+=CONSTANS::TAMANO)
        for(int y =0; y<pMatriz.rows; y+=CONSTANS::TAMANO)
            cuadricularAux(pMatriz, x, y);
    return pMatriz;
}

cv::Mat procesarImagen::cuadricularAux(cv::Mat pMatriz, int pX, int pY){
    for(int x = pX; x<pX+CONSTANS::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANS::TAMANO; y++){
            b = (b+(int)pMatriz.at<cv::Vec3b>(y,x)[0])/2;
            g = (g+(int)pMatriz.at<cv::Vec3b>(y,x)[1])/2;
            r = (r+(int)pMatriz.at<cv::Vec3b>(y,x)[2])/2;
        }
    }
    for(int x = pX; x<pX+CONSTANS::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANS::TAMANO; y++){
            pMatriz.at<cv::Vec3b>(y,x)[0]=b;
            pMatriz.at<cv::Vec3b>(y,x)[1]=g;
            pMatriz.at<cv::Vec3b>(y,x)[2]=r;
        }
    }
    return pMatriz;
}

cv::Mat procesarImagen::escalaGrises(cv::Mat pMatriz){
    for(int x = 0; x<pMatriz.cols; x+=CONSTANS::TAMANO)
        for(int y =0; y<pMatriz.rows; y+=CONSTANS::TAMANO)
            escalaGrisesAux(pMatriz, x, y);
    return pMatriz;
}

cv::Mat procesarImagen::escalaGrisesAux(cv::Mat pMatriz, int pX, int pY){
    for(int x = pX; x<pX+CONSTANS::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANS::TAMANO; y++){
            b = (b+(int)pMatriz.at<cv::Vec3b>(y,x)[0])/2;
            g = (g+(int)pMatriz.at<cv::Vec3b>(y,x)[1])/2;
            r = (r+(int)pMatriz.at<cv::Vec3b>(y,x)[2])/2;
        }
    }
    int colorGris = (r+g+b)/3;
    for(int x = pX; x<pX+CONSTANS::TAMANO; x++){
        for (int y =pY; y<pY+CONSTANS::TAMANO; y++){
            pMatriz.at<cv::Vec3b>(y,x)[0]=colorGris;
            pMatriz.at<cv::Vec3b>(y,x)[1]=colorGris;
            pMatriz.at<cv::Vec3b>(y,x)[2]=colorGris;
        }
    }
    return pMatriz;
}
