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

class PrincipalMenu : public QMainWindow{
    Q_OBJECT
public:
    PrincipalMenu(QWidget *parent = 0);
    ~PrincipalMenu();
private slots:
    void crearVentanaDirectorio();
    void crearVentanaAyuda();
};

#endif // PRINCIPALMENU_H
