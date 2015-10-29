#include "GUI/uploadimage.h"

/**
 * @brief uploadImage::uploadImage, Constructor de la clase
 */
uploadImage::uploadImage(){
}
/**
 * @brief uploadImage::seleccionarImagen, Metodo para elegir la imagen
 * @param pMenu
 * @return la imagen cargada en formato cv::Mat
 */
cv::Mat uploadImage::seleccionarImagen(PrincipalMenu* pMenu){
    QString direccion= QFileDialog::getOpenFileName((QWidget*)pMenu);
    cv::Mat matrixImage= cv::imread(direccion.toStdString());
    return matrixImage;
}
