#ifndef VENTANAAYUDA_H
#define VENTANAAYUDA_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include "GUI/principalmenu.h"
#include "GUI/constantsGUI.h"

/**
 * @file ventanaayuda.h
 * @brief The ventanaAyuda class, ventana para mostrar la ayuda (tutorial) para correr el programa
 * @author Jairo Daniel Ortega Calderon
 * @date October 10, 2015
 */
class ventanaAyuda : public QMainWindow{
    Q_OBJECT
public:
    ventanaAyuda(QWidget *parent = CONSTANSGUI::CERO);
public slots:
    void volver();
};

#endif // VENTANAAYUDA_H
