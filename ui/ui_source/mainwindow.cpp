#include "ui/ui_header/mainwindow.h"

#include "ui/ui_header/loginlauncher.h"
#include "ui/ui_header/downloadlauncher.h"
#include "ui/ui_header/mainmenu.h"
#include "ui/ui_header/gamestatistics.h"
#include "ui/ui_header/battleground.h"
#include "ui/ui_header/fleetsadmirals.h"
#include "ui/ui_header/researchanddevelopment.h"
#include "ui/ui_header/gamesettings.h"
#include "data/datastorage.h"
#include "object/gamer.h"
#include "object/ship.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)/*,
    ui(new Ui::MainWindow) *///Konstrkutor okna glownego
{

    ui = new Ui::MainWindow;
    ui->setupUi(this);

    setSizeAndPosition(500, 260);

    //Ustawienia launchera i gry
    QSettings settings;
    //settings.setValue("version", "0");

    if(settings.value("version").toString()=="")
    {
        //Tworzenie ustawien w wypadku pierwszego uruchomienia
        settings.setValue("version", "0");
    }

    //stworzenie polaczenia z serwerem
    internetConnection = new MyTCPSocket(this);
    internetConnection->connectToHost();

    //obsluga kilku widgetow
    qStackedWidget = new QStackedWidget;

    //tworzenie widgetow Launchera
    widgetLoginLauncher = new LoginLauncher(internetConnection, this);
    widgetDownloadLauncher = new DownloadLauncher(internetConnection, this);


    //wrzucenie widegtow na stos
    qStackedWidget->addWidget(widgetLoginLauncher);
    qStackedWidget->addWidget(widgetDownloadLauncher);

    //pokazanie najwyzszego widgetu
    ui->layout->addWidget(qStackedWidget);
}
void MainWindow::setSizeAndPosition(int width, int height)
{
    resize(width,height);
    setMaximumSize(width,height);
    setMinimumSize(width,height);
    adjustSize();

    ui->verticalLayoutWidget->setGeometry(QRect(10,10,width-20,height-20));

    QDesktopWidget widget;
    QRect mainScreenSize = widget.availableGeometry(widget.primaryScreen());
    QPoint startPoint = QPoint(
                mainScreenSize.width()/2-(width/2),
                mainScreenSize.height()/2-(height/2)
                );
    move(startPoint);
}

MainWindow::~MainWindow() //destruktor okna glownego
{
    delete gamer;
    delete dataStorage;
    delete qStackedWidget;
    delete ui;
}
DataStorage *MainWindow::getDataStorage()
{
    return this->dataStorage;
}
GamerResearch *MainWindow::getGamerResearch()
{
    return gamer->getResearch();
}
Gamer *MainWindow::getGamer()
{
    return gamer;
}
void MainWindow::getDataFromServerAboutGamer(Gamer *gamer)
{
    gamer->setResearch(dataStorage->returnGamerResearch(internetConnection->requestResearchInfo()));
    gamer->setCurrentResearch(internetConnection->requestcurrentResearchInfo());
}
void MainWindow::startGame()
{
    dataStorage = new DataStorage();
    gamer = new Gamer;
    getDataFromServerAboutGamer(gamer);

    setSizeAndPosition(500, 440);
    qStackedWidget->removeWidget(widgetLoginLauncher);
    qStackedWidget->removeWidget(widgetDownloadLauncher);

    delete widgetLoginLauncher;
    widgetLoginLauncher=NULL;
    delete widgetDownloadLauncher;
    widgetDownloadLauncher=NULL;

    widgetMainMenu = new MainMenu(internetConnection, this);
    widgetGameStatistics = new GameStatistics(internetConnection, this);
    widgetBattleground = new Battleground(internetConnection, this);
    widgetFleetsAdmirals = new FleetsAdmirals(internetConnection, this);
    widgetResearchAndDevelopment = new ResearchAndDevelopment(internetConnection, this);
    widgetGameSettings = new GameSettings(internetConnection, this);


    qStackedWidget->addWidget(widgetMainMenu);
    qStackedWidget->addWidget(widgetGameStatistics);
    qStackedWidget->addWidget(widgetBattleground);
    qStackedWidget->addWidget(widgetFleetsAdmirals);
    qStackedWidget->addWidget(widgetResearchAndDevelopment);
    qStackedWidget->addWidget(widgetGameSettings);

}
void MainWindow::setWidget(int nWidget) //przestawianie widgetu login na download w glownym oknie
{
    qStackedWidget->setCurrentIndex(nWidget);
    if(widgetDownloadLauncher!=NULL)
    {
        widgetDownloadLauncher->updateProcedure();
    }
}
void MainWindow::setWidgetMainMenu()
{
    setSizeAndPosition(500, 440);
    setWidget(widgetMainMenu);
}
void MainWindow::setWidgetGameStatistics()
{
    setWidget(widgetGameStatistics);
}
void MainWindow::setWidgetBattleground()
{
    setWidget(widgetBattleground);
}
void MainWindow::setWidgetFleetsAdmirals()
{
    setWidget(widgetFleetsAdmirals);
}
void MainWindow::setWidgetResearchAndDevelopment()
{
    setSizeAndPosition(700, 470);
    widgetResearchAndDevelopment->checkIsResearchFinishedToSetCorrectStateOnButton2();
    setWidget(widgetResearchAndDevelopment);
}
void MainWindow::setWidgetGameSettings()
{
    setWidget(widgetGameSettings);
}
void MainWindow::setWidget(QWidget *widgetToSet)
{
    qStackedWidget->setCurrentWidget(widgetToSet);
}

void MainWindow::setProgressBar(int i)
{
    widgetDownloadLauncher->setProgressBar(i);
}
