#include "ui/ui_header/researchanddevelopment.h"
#include "ui/ui_header/mainwindow.h"
#include "data/datastorage.h"
#include "object/gamerresearch.h"
#include "object/gamer.h"


ResearchAndDevelopment::ResearchAndDevelopment(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResearchAndDevelopment)
{
    ui->setupUi(this);

    this->mainWindow = mainWindow;
    this->internetConnection = internetConnection;
    DataStorage *dataStorage = mainWindow->getDataStorage();
    GamerResearch *gamerResearch = mainWindow->getGamerResearch();


    QVector <ResearchCategoryData> researchCategoryData = dataStorage->getArrayOfResearchCategoryData();

    QListView *listView[5][3];
    listView[0][0]=ui->listViewAInTabA;
    listView[0][1]=ui->listViewBInTabA;
    listView[0][2]=ui->listViewCInTabA;
    listView[1][0]=ui->listViewAInTabB;
    listView[1][1]=ui->listViewBInTabB;
    listView[2][0]=ui->listViewAInTabC;
    listView[2][1]=ui->listViewBInTabC;
    listView[3][0]=ui->listViewAInTabD;
    listView[4][0]=ui->listViewAInTabE;


    QStandardItemModel *model;
    QStandardItem *colorItem;


    for(qint8 i=0; i<researchCategoryData.size(); i++)
    {
        ui->tabWidget->setTabText(i, researchCategoryData[i].getCategoryName());
        for(qint8 j=0; j<researchCategoryData[i].getSizeOfArrayOfResearchData(); j++)
        {
            model = new QStandardItemModel();
            listToDeleteA.append(model);

            colorItem = new QStandardItem(researchCategoryData[i].getResearchNameFromArrayOfResearchData(j));
            listToDeleteB.append(colorItem);

            colorItem->setData(QBrush(QColor(Qt::black)),
                               Qt::ForegroundRole);
            model->appendRow(colorItem);

            for(qint8 k=researchCategoryData[i].getFirstElementFromArrayOfResearchData(j);
                k<=researchCategoryData[i].getLastElementFromArrayOfResearchData(j);k++)
            {
                colorItem = new QStandardItem(dataStorage->getResearchNameAndCode(
                                                  researchCategoryData[i].getCategoryID(),
                                                  k));
                listToDeleteB.append(colorItem);

                if(gamerResearch->checkIsResearched(researchCategoryData[i].getCategoryID(),
                                                    k))
                {
                    colorItem->setData(QColor("green"), Qt::DecorationRole);
                }
                else
                {
                    colorItem->setData(QColor("red"), Qt::DecorationRole);
                }

                colorItem->setData(QBrush(QColor(Qt::black)),
                                   Qt::ForegroundRole);
                model->appendRow(colorItem);
            }
            listView[i][j]->setModel(model);
        }
    }
}

ResearchAndDevelopment::~ResearchAndDevelopment()
{

    qDeleteAll(listToDeleteB.begin(), listToDeleteB.end());
    listToDeleteB.clear();

    qDeleteAll(listToDeleteA.begin(), listToDeleteA.end());
    listToDeleteA.clear();
    delete ui;
}

void ResearchAndDevelopment::on_pushButton_clicked()
{
    mainWindow->setWidgetMainMenu();
}
void ResearchAndDevelopment::checkIsResearchFinishedToSetCorrectStateOnButton2()
{
    if(!mainWindow->getGamerResearch()->isCurrentResearch())
    {
        ui->pushButton_2->setVisible(false);
        ui->labelCurrentResearched->setText("Nothing is researched");
    }
    else
    {
        ui->pushButton_2->setVisible(true);
        setLabelCurrentResearched();
        if(mainWindow->getGamerResearch()->isResearchFinished())
        {
            ui->pushButton_2->setEnabled(true);
        }
        else
        {
            ui->pushButton_2->setEnabled(false);
        }
    }
}
void ResearchAndDevelopment::on_pushButton_2_clicked()
{
    QString error = "";
    if(mainWindow->getGamerResearch()->isCurrentResearch() &&
            mainWindow->getGamerResearch()->isResearchFinished())
    {

        if(internetConnection->sendCurrentResearch(mainWindow->getGamerResearch()->getCurrentResearchDataToSendToServer("E"), &error))
        {
            qint8 test = mainWindow->getGamerResearch()->setResearchAdvancer();
            listToDeleteB.at(test)->setData(QColor("green"), Qt::DecorationRole);
            mainWindow->getGamerResearch()->clearCurrentResearch();
            checkIsResearchFinishedToSetCorrectStateOnButton2();
        }
        else
        {
            ui->labelCurrentResearchedError->setText(error);
        }
    }
}
void ResearchAndDevelopment::setLabelCurrentResearched()
{
    ui->labelCurrentResearched->setText(
                mainWindow->getDataStorage()->
                    getResearchNameAndCode(mainWindow->getGamerResearch()->getCurrentResearchCategory(),
                                           mainWindow->getGamerResearch()->getCurrentResearchID())
                + "   " +
                mainWindow->getGamerResearch()->getCurrentResearchTimeEnd());
}

void ResearchAndDevelopment::startResearch(QString category, qint8 id, qint8 shift)
{
    if(!mainWindow->getGamerResearch()->isCurrentResearch() &&
            mainWindow->getGamerResearch()->checkIsResearchable(category, id+shift))
    {
        mainWindow->getGamerResearch()->setCurrentResearchData(category,
                                                               id-1+shift,
                                                               mainWindow->getDataStorage()->getResearchTime(category,
                                                                                                             id-1+shift));
        QString error;
        if(internetConnection->sendCurrentResearch(mainWindow->getGamerResearch()->getCurrentResearchDataToSendToServer("S"), &error))
        {
            setLabelCurrentResearched();
            checkIsResearchFinishedToSetCorrectStateOnButton2();
        }
        else
        {
            mainWindow->getGamerResearch()->clearCurrentResearch();
            ui->labelCurrentResearchedError->setText(error);
        }

    }
}

void ResearchAndDevelopment::on_listViewAInTabA_doubleClicked(const QModelIndex &index)
{
    int shift=0;
    startResearch("A", index.row(), shift);
}
void ResearchAndDevelopment::on_listViewBInTabA_doubleClicked(const QModelIndex &index)
{
    int shift=8;
    startResearch("A", index.row(), shift);
}

void ResearchAndDevelopment::on_listViewCInTabA_doubleClicked(const QModelIndex &index)
{
    int shift=16;
    startResearch("A", index.row(), shift);
}

void ResearchAndDevelopment::on_listViewAInTabB_doubleClicked(const QModelIndex &index)
{
    int shift=24;
    startResearch("A", index.row(), shift);
}

void ResearchAndDevelopment::on_listViewBInTabB_doubleClicked(const QModelIndex &index)
{
    int shift=30;
    startResearch("A", index.row(), shift);
}

void ResearchAndDevelopment::on_listViewAInTabC_doubleClicked(const QModelIndex &index)
{
    int shift=0;
    startResearch("B", index.row(), shift);
}

void ResearchAndDevelopment::on_listViewBInTabC_doubleClicked(const QModelIndex &index)
{
    int shift=8;
    startResearch("B", index.row(), shift);
}

void ResearchAndDevelopment::on_listViewAInTabD_doubleClicked(const QModelIndex &index)
{
    int shift=0;
    startResearch("C", index.row(), shift);
}

void ResearchAndDevelopment::on_listViewAInTabE_doubleClicked(const QModelIndex &index)
{
    int shift=0;
    startResearch("-", index.row(), shift);
}

