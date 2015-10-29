#ifndef UPLOADIMAGE_H
#define UPLOADIMAGE_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QString>
#include <QFileDialog>

class uploadImage
{
public:
    uploadImage();
    cv::Mat seleccionarImagen();
};

#endif // UPLOADIMAGE_H
