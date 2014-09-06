#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include "includeFile.h"
#include "gameobjectdata.h"
#include "equipmentdata.h"
#include "offensivedata.h"
#include "defensivedata.h"
#include "accuracymodifierdata.h"
#include "shipdata.h"
#include "researchcategorydata.h"

class Ship;
class GamerResearch;

class DataStorage
{
public:
    DataStorage();
    Ship returnShip(QString ship);
    GamerResearch *returnGamerResearch(QString research);
    QString getResearchNameAndCode(QString arrayType, qint8 id);

    QVector<ResearchCategoryData> getArrayOfResearchCategoryData();

private:
    QVector <EquipmentData> arrayOfEquipmentData;
    QVector <AccuracyModifierData> arrayOfAccuracyModifierData;
    QVector <ShipData> arrayOfShipData;

    QVector <ResearchCategoryData> arrayOfResearchCategoryData;

    qint8 toQintFromQChar(QChar qChar, qint8 *smallLetter);

    void interpretLineOfObjectData(char *data, qint8 type);
    int interpretLineOfResearchData(char *data, qint8 researchDataSizePerCategory, bool *categoryLoaded);
};
#endif // DATASTORAGE_H
