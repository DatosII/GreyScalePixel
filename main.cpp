#include "GUI/principalmenu.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication aplication(argc, argv);
    PrincipalMenu *principal = new PrincipalMenu();
    return aplication.exec();
}
