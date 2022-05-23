#include "cStringVisual.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cStringVisual w;
    w.show();
    return a.exec();
}
