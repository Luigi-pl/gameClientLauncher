#include "mainwindow.h"
//#include <QRect>
#include <QPoint>
#include <QDesktopWidget>
#include <QRect>

#include "loginlauncher.h"
#include "downloadlauncher.h"
#include "mainmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)/*,
    ui(new Ui::MainWindow) *///Konstrkutor okna glownego
{

    ui = new Ui::MainWindow;
    ui->setupUi(this);

    setSizeAndPosition(500, 260);

    //Ustawienia launchera i gry
    QSettings settings;
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
    delete ui;
    delete widgetLoginLauncher;
    delete qStackedWidget;
}
void MainWindow::startGame()
{
    setSizeAndPosition(620, 820);
    qStackedWidget->removeWidget(widgetLoginLauncher);
    qStackedWidget->removeWidget(widgetDownloadLauncher);

    widgetMainMenu = new MainMenu(internetConnection, this);


    qStackedWidget->addWidget(widgetMainMenu);
}
void MainWindow::setWidget(int nWidget) //przestawianie widgetu login na download w glownym oknie
{
    qStackedWidget->setCurrentIndex(nWidget);
    if(widgetDownloadLauncher!=NULL)
    {
        widgetDownloadLauncher->updateProcedure();
    }
}
void MainWindow::setProgressBar(int i)
{
    widgetDownloadLauncher->setProgressBar(i);
}
