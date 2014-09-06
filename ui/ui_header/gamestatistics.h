#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include "mytcpsocket.h"
#include "ui_gamestatistics.h"

namespace Ui {
class GameStatistics;
}

class GameStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit GameStatistics(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent = 0);
    ~GameStatistics();

private:
    Ui::GameStatistics *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
};

#endif // GAMESTATISTICS_H
