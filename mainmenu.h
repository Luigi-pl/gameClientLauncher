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

private:
    Ui::MainMenu *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
};

#endif // MAINMENU_H
