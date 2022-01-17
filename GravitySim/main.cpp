#include "gravitysim.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GravitySim w;
    w.show();
    return a.exec();
}
