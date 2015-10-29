#ifndef VENTANAAYUDA_H
#define VENTANAAYUDA_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include "GUI/principalmenu.h"

class ventanaAyuda : public QMainWindow{
    Q_OBJECT
public:
    ventanaAyuda(QWidget *parent = 0);

public slots:
    void volver();
};

#endif // VENTANAAYUDA_H
