#include "ui/ui_header/gamesettings.h"
#include "ui/ui_header/mainwindow.h"


GameSettings::GameSettings(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameSettings)
{
    ui->setupUi(this);

    this->mainWindow = mainWindow;
    this->internetConnection = internetConnection;
}
GameSettings::~GameSettings()
{
    delete ui;
}
