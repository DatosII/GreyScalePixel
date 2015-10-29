#ifndef PRINCIPALMENU_H
#define PRINCIPALMENU_H

#include <QMainWindow>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QPixmap>
#include "uploadimage.h"
#include "imagenseleccionada.h"
#include "ventanaayuda.h"

class PrincipalMenu : public QMainWindow
{
    Q_OBJECT

public:
    PrincipalMenu(QWidget *parent = 0);
    ~PrincipalMenu();

private slots:
    void newWindow();
    void newWindow2();
};

#endif // PRINCIPALMENU_H
