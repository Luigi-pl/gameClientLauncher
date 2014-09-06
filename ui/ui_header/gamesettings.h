#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include "mytcpsocket.h"
#include "ui_gamesettings.h"

namespace Ui {
class GameSettings;
}

class GameSettings : public QWidget
{
    Q_OBJECT

public:
    explicit GameSettings(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent = 0);
    ~GameSettings();

private:
    Ui::GameSettings *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
};

#endif // GAMESETTINGS_H
