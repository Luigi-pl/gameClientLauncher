#ifndef MAINMENU_H
#define MAINMENU_H

#include "mytcpsocket.h"
#include "ui_mainmenu.h"

class MainWindow;

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_exit_clicked();
    void on_statisticWindow_clicked();
    void on_lookingFor_clicked();
    void on_fleetsAdmiralsWindow_clicked();
    void on_researchDevelopmentWindow_clicked();
    void on_settings_clicked();

private:
    Ui::MainMenu *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
};

#endif // MAINMENU_H
