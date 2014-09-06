#include "ui/ui_header/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Luigi's soft");
    QCoreApplication::setOrganizationDomain("mat.umk.pl/~luigi");
    QCoreApplication::setApplicationName("Game name");

    MainWindow w;
    w.show();

    return a.exec();
}
