#ifndef FLEETSADMIRALS_H
#define FLEETSADMIRALS_H

#include "ui_fleetsadmirals.h"
#include "mytcpsocket.h"

namespace Ui {
class FleetsAdmirals;
}

class FleetsAdmirals : public QWidget
{
    Q_OBJECT

public:
    explicit FleetsAdmirals(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent = 0);
    ~FleetsAdmirals();

private:
    Ui::FleetsAdmirals *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
    QWidget *shipToEditWidget[10];
};

#endif // FLEETSADMIRALS_H
