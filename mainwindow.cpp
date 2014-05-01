#include "mainwindow.h"
//#include <QRect>
#include <QPoint>
#include <QDesktopWidget>
#include <QRect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) //Konstrkutor okna glownego
{
    ui->setupUi(this);

    //Ustawienia gry
    QSettings settings;
    if(settings.value("version").toString()=="")
    {
        QDesktopWidget widget;
        QRect mainScreenSize = widget.availableGeometry(widget.primaryScreen());
        QPoint startPoint = QPoint(
                    mainScreenSize.width()/2-250,
                    mainScreenSize.height()/2-130
                    );
        settings.setValue("pos", startPoint);
        settings.setValue("version", "0");

    }
    else
    {
        move(settings.value("pos", QPoint(200, 200)).toPoint());
    }

    //stworzenie polaczenia z serwerem
    internetConnection = new MyTCPSocket();
    internetConnection->connectToHost();

    //obsluga kilku widgetow
    qStackedWidget = new QStackedWidget;

    //tworzenie widgetow Launchera
    widgetLoginLauncher = new loginLauncher(internetConnection, this);
    widgetDownloadLauncher = new downloadLauncher(internetConnection, this);


    //wrzucenie widegtow na stos
    qStackedWidget->addWidget(widgetLoginLauncher);
    qStackedWidget->addWidget(widgetDownloadLauncher);

    //pokazanie najwyzszego widgetu
    ui->layout->addWidget(qStackedWidget);


}

MainWindow::~MainWindow() //destruktor okna glownego
{
    delete ui;
    delete widgetLoginLauncher;
    delete qStackedWidget;
}

void MainWindow::setWidget(int nWidget) //przestawianie widgetu login na download w glownym oknie
{
    qStackedWidget->setCurrentIndex(nWidget);
    widgetDownloadLauncher->updateProcedure();
}
