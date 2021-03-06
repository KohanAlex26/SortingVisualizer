#include "gui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gui w(60);
    w.showMaximized();
    return a.exec();
}
