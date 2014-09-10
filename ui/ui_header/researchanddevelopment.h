#ifndef RESEARCHANDDEVELOPMENT_H
#define RESEARCHANDDEVELOPMENT_H

#include "mytcpsocket.h"
#include "ui_researchanddevelopment.h"


namespace Ui {
class ResearchAndDevelopment;
}

class ResearchAndDevelopment : public QWidget
{
    Q_OBJECT

public:
    explicit ResearchAndDevelopment(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent = 0);
    void checkIsResearchFinishedToSetCorrectStateOnButton2();
    ~ResearchAndDevelopment();

private slots:
    void on_pushButton_clicked();

    void on_listViewAInTabA_doubleClicked(const QModelIndex &index);

    void on_listViewBInTabA_doubleClicked(const QModelIndex &index);

    void on_listViewCInTabA_doubleClicked(const QModelIndex &index);

    void on_listViewAInTabB_doubleClicked(const QModelIndex &index);

    void on_listViewBInTabB_doubleClicked(const QModelIndex &index);

    void on_listViewAInTabC_doubleClicked(const QModelIndex &index);

    void on_listViewBInTabC_doubleClicked(const QModelIndex &index);

    void on_listViewAInTabD_doubleClicked(const QModelIndex &index);

    void on_listViewAInTabE_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    void startResearch(QString category, qint8 id, qint8 shift);
    void setLabelCurrentResearched();

    Ui::ResearchAndDevelopment *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
    QVector <QStandardItemModel *> listToDeleteA;
    QVector <QStandardItem *> listToDeleteB;

};

#endif // RESEARCHANDDEVELOPMENT_H
