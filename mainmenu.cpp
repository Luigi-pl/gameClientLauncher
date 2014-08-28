#include "mainmenu.h"
#include "mainwindow.h"

MainMenu::MainMenu(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    this->mainWindow = mainWindow;
    this->internetConnection = internetConnection;
}

MainMenu::~MainMenu()
{
    delete ui;
}
