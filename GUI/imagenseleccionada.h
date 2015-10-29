#ifndef IMAGENSELECCIONADA_H
#define IMAGENSELECCIONADA_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include <opencv2/opencv.hpp>
#include "GUI/resultadofinal.h"
#include "GUI/constantsGUI.h"
#include "Facade/facade.h"

/**
 * @file imagenseleccionada.h
 * @brief The imagenSeleccionada class, Muestra la imagen seleccionada y se la pasa al facade
 * @author Jairo Daniel Ortega Calderon
 * @date October 10, 2015
 */
class imagenSeleccionada : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    QImage image;
    cv::Mat _matrix;
    Facade* pFacade;
    void convertirMatrix(cv::Mat matrixImage);
public:
    imagenSeleccionada(QWidget *parent = CONSTANSGUI::CERO);
public slots:
    void crearVentanaEleccion(cv::Mat matrixImage);
    void procesar();

};

#endif // IMAGENSELECCIONADA_H
