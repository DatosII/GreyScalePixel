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
#include "GUI/resultadofinal.h"
#include "Logic/Constants.h"
#include "Facade/facade.h"


class imagenSeleccionada : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    QImage image;
    cv::Mat _matrix;
    Facade* pFacade;
    void convertirMatrix(cv::Mat matrixImage);
public:
    imagenSeleccionada(QWidget *parent = 0);
public slots:
    void crearVentanaEleccion(cv::Mat matrixImage);
    void procesar();

};

#endif // IMAGENSELECCIONADA_H
