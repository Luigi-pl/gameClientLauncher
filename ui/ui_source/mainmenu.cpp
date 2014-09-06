#include "ui/ui_header/mainmenu.h"
#include "ui/ui_header/mainwindow.h"

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

void MainMenu::on_exit_clicked()
{
    internetConnection->closeConnection();
    mainWindow->close();
}

void MainMenu::on_statisticWindow_clicked()
{
    mainWindow->setWidgetGameStatistics();
}

void MainMenu::on_lookingFor_clicked()
{
    mainWindow->setWidgetBattleground();
}

void MainMenu::on_fleetsAdmiralsWindow_clicked()
{
    mainWindow->setWidgetFleetsAdmirals();
}

void MainMenu::on_researchDevelopmentWindow_clicked()
{
    mainWindow->setWidgetResearchAndDevelopment();
}

void MainMenu::on_settings_clicked()
{
    mainWindow->setWidgetGameSettings();
}
