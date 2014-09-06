#include "ui/ui_header/gamestatistics.h"
#include "ui/ui_header/mainwindow.h"

GameStatistics::GameStatistics(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStatistics)
{
    ui->setupUi(this);

    this->mainWindow = mainWindow;
    this->internetConnection = internetConnection;
}

GameStatistics::~GameStatistics()
{
    delete ui;
}
