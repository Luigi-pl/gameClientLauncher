#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H

#include "mytcpsocket.h"
#include "ui_battleground.h"

namespace Ui {
class Battleground;
}

class Battleground : public QWidget
{
    Q_OBJECT

public:
    explicit Battleground(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent = 0);
    ~Battleground();

private:
    Ui::Battleground *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
};

#endif // BATTLEGROUND_H
