#include "ui/ui_header/fleetsadmirals.h"
#include "ui/ui_header/mainwindow.h"

FleetsAdmirals::FleetsAdmirals(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FleetsAdmirals)
{
    ui->setupUi(this);

    this->mainWindow = mainWindow;
    this->internetConnection = internetConnection;
}


FleetsAdmirals::~FleetsAdmirals()
{
    delete ui;
}
