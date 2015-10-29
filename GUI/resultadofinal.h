#ifndef RESULTADOFINAL_H
#define RESULTADOFINAL_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include <opencv2/opencv.hpp>
#include "GUI/principalmenu.h"
#include "GUI/constantsGUI.h"

/**
 * @file resultadofinal.h
 * @brief The resultadoFinal class, Clase que muestra los resutados del algoritmo
 * @author Jairo Daniel Ortega Calderon
 * @date October 10, 2015
 */
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
    resultadoFinal(QWidget *parent = CONSTANSGUI::CERO);
    void ventanaFinal(cv::Mat pMatrixColor, cv::Mat pMatrixGris);
public slots:
    void volver();
};

#endif // RESULTADOFINAL_H
