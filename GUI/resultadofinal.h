#ifndef RESULTADOFINAL_H
#define RESULTADOFINAL_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "GUI/principalmenu.h"
#include "Logic/Constants.h"

class resultadoFinal : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    cv::Mat _matrizColor;
    cv::Mat _matrizGris;
    QImage _imagenColor;
    QImage _imagenGris;
    void convertirMatrix(cv::Mat pMatrixImage, std::string pType);
public:
    resultadoFinal(QWidget *parent = 0);
    void ventanaFinal(cv::Mat pMatrixColor, cv::Mat pMatrixGris);
public slots:
    void volver();
};

#endif // RESULTADOFINAL_H
