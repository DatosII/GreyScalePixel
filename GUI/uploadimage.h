#ifndef UPLOADIMAGE_H
#define UPLOADIMAGE_H

#include <opencv2/opencv.hpp>
#include <QString>
#include <QFileDialog>
class PrincipalMenu;

/**
 * @brief The uploadImage class, Clase para cargar la imagen del directorio
 */
class uploadImage{
public:
    uploadImage();
    cv::Mat seleccionarImagen(PrincipalMenu *pMenu);
};

#endif // UPLOADIMAGE_H
