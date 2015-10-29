#ifndef IMAGENSELECCIONADA_H
#define IMAGENSELECCIONADA_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "procesarimagen.h"
#include "Constants.h"


class imagenSeleccionada : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    QImage image;
    cv::Mat _matrix;
    void convertMatrix(cv::Mat matrixImage);
public:
    imagenSeleccionada(QWidget *parent = 0);
public slots:
    void newWindow(cv::Mat matrixImage);
    void procesar();

};

#endif // IMAGENSELECCIONADA_H
