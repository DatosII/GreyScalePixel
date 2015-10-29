#include "GUI/uploadimage.h"

uploadImage::uploadImage(){
}

cv::Mat uploadImage::seleccionarImagen(){
    QString direccion= QFileDialog::getOpenFileName();
    cv::Mat matrixImage= cv::imread(direccion.toStdString());
    return matrixImage;
}
