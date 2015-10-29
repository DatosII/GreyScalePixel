#ifndef PRINCIPALMENU_H
#define PRINCIPALMENU_H

#include <QMainWindow>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QPixmap>
#include "GUI/uploadimage.h"
#include "GUI/imagenseleccionada.h"
#include "GUI/ventanaayuda.h"

/**
 * @file principalmenu.h
 * @brief The PrincipalMenu class, Clase que permite crear la ventana inicial
 * @author Jairo Daniel Ortega Calderon
 * @date October 10, 2015
 */
class PrincipalMenu : public QMainWindow{
    Q_OBJECT
public:
    PrincipalMenu(QWidget *parent = CONSTANSGUI::CERO);
    ~PrincipalMenu();
private slots:
    void crearVentanaDirectorio();
    void crearVentanaAyuda();
};

#endif // PRINCIPALMENU_H
