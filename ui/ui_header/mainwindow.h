#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mytcpsocket.h"
#include "ui_mainwindow.h"

class LoginLauncher;
class DownloadLauncher;
class MainMenu;
class GameStatistics;
class Battleground;
class FleetsAdmirals;
class ResearchAndDevelopment;
class GameSettings;
class DataStorage;
class Gamer;
class GamerResearch;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setWidget(int nWidget);
    void setWidgetMainMenu();
    void setWidgetGameStatistics();
    void setWidgetBattleground();
    void setWidgetFleetsAdmirals();
    void setWidgetResearchAndDevelopment();
    void setWidgetGameSettings();
    void setProgressBar(int i);
    void startGame();
    DataStorage *getDataStorage();
    GamerResearch *getGamerResearch();

private:
    void setSizeAndPosition(int width, int height);
    void setWidget(QWidget *widgetToSet);

    Ui::MainWindow *ui;

    MyTCPSocket *internetConnection;
    LoginLauncher *widgetLoginLauncher;
    DownloadLauncher *widgetDownloadLauncher;
    MainMenu *widgetMainMenu;
    GameStatistics *widgetGameStatistics;
    Battleground *widgetBattleground;
    FleetsAdmirals *widgetFleetsAdmirals;
    ResearchAndDevelopment *widgetResearchAndDevelopment;
    GameSettings *widgetGameSettings;
    QStackedWidget *qStackedWidget;

    DataStorage *dataStorage;
    Gamer *gamer;

};

#endif // MAINWINDOW_H
