#include "ui/ui_header/battleground.h"
#include "ui/ui_header/mainwindow.h"

Battleground::Battleground(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Battleground)
{
    ui->setupUi(this);

    this->mainWindow = mainWindow;
    this->internetConnection = internetConnection;
}

Battleground::~Battleground()
{
    delete ui;
}
