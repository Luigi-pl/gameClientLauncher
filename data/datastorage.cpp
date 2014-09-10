#include "datastorage.h"
#include "object/ship.h"
#include "object/gamerresearch.h"


DataStorage::DataStorage()
{
    QFile mainDataFile;
    QFile dataFile;
    QString pathToDataFolder = QApplication::applicationDirPath() + QDir::separator() + "data" + QDir::separator();
    qint8 type=0;
    qint8 readDataSize;

    qint8 researchDataSizePerCategory=-1;
    bool categoryLoaded=false;


    mainDataFile.setFileName(pathToDataFolder + "data");
    mainDataFile.open(QIODevice::ReadOnly);
    char buffer[100];
    QString stringBuffer;
    while(!mainDataFile.atEnd())
    {
        mainDataFile.readLine(buffer, 30);
        if(buffer[0]=='*')
        {
            type=0;
        }
        if(type!=0 && buffer[0]!='*')
        {
            stringBuffer = QString(buffer);
            stringBuffer.remove('\n');


            dataFile.setFileName(pathToDataFolder + stringBuffer);
            dataFile.open(QIODevice::ReadOnly);


            while(!dataFile.atEnd())
            {
                readDataSize = dataFile.readLine(buffer, 100);
                if(readDataSize>0)
                {
                    buffer[readDataSize-1]=0;
                    if(1<=type && type<=4)
                    {
                        interpretLineOfObjectData(buffer, type);
                    }
                    else if(type==5)
                    {
                        researchDataSizePerCategory = interpretLineOfResearchData(buffer, researchDataSizePerCategory, &categoryLoaded);
                    }
                }
            }
            dataFile.close();

        }
        if(buffer[0]=='*')
        {
            if(buffer[1]=='A')
            {
                type=1;
            }
            else if(buffer[1]=='B')
            {
                type=2;
            }
            else if(buffer[1]=='C')
            {
                type=3;
            }
            else if(buffer[1]=='D')
            {
                type=4;
            }
            else if(buffer[1]=='E')
            {
                type=5;
            }
            else if(buffer[1]=='*')
            {
                type=0;
            }
        }
    }
    mainDataFile.close();


}
QString DataStorage::getResearchNameAndCode(QString arrayType, qint8 id)
{
    if(arrayType[0]=='A')
    {
        return arrayOfEquipmentData[id].getName() + " " + arrayOfEquipmentData[id].getID();
    }
    else if(arrayType[0]=='B')
    {
        return arrayOfAccuracyModifierData[id].getName() + " " + arrayOfAccuracyModifierData[id].getID();
    }
    else if(arrayType[0]=='C')
    {
        return arrayOfShipData[id].getName() + " " + arrayOfShipData[id].getID();
    }
    else if(arrayType[0]=='-')
    {
        return "Squadron " + QString::number(id+1);
    }
    else
    {
        return "error";
    }
}
qint32 DataStorage::getResearchTime(QString arrayType, qint8 id)
{
    if(arrayType[0]=='A')
    {
        return arrayOfEquipmentData[id].getTime();
    }
    else if(arrayType[0]=='B')
    {
        return arrayOfAccuracyModifierData[id].getTime();
    }
    else if(arrayType[0]=='C')
    {
        return arrayOfShipData[id].getTime();
    }
    else if(arrayType[0]=='-')
    {
        if(id==1)
        {
            return 12;
        }
        else if(id==2)
        {
            return 24;
        }
        else if(id==3)
        {
            return 48;
        }
        else if(id==4)
        {
            return 96;
        }
        else if(id==5)
        {
            return 144;
        }
        else if(id==6)
        {
            return 240;
        }
        else if(id==7)
        {
            return 384;
        }
        else if(id==8)
        {
            return 624;
        }
        else if(id==9)
        {
            return 1008;
        }
        else
        {
            return 1632;
        }
    }
    else
    {
        return 2000;
    }
}

Ship DataStorage::returnShip(QString ship)
{
    QString sShipType = ship.left(2);
    ShipData *shipData = &(arrayOfShipData[sShipType.toInt()]);
    QString shipName = shipData->getName();

    QString sSquadronSize = ship.left(6);
    sSquadronSize.remove(0,2);


    QString sShipSize = ship.left(8);
    sShipSize.remove(0,6);

    QString shipEquipment = ship;
    shipEquipment.remove(0,8);


    qint32 nSquadronSize = sSquadronSize.toInt();
    qint32 nShipSize = sShipSize.toInt();

    qint32 attackModifier;
    if(nShipSize<14)
    {
        attackModifier=1;
    }
    else if(nShipSize<44)
    {
        attackModifier=2;
    }
    else
    {
        attackModifier=3;
    }

    qint32 ownAccuracyModifier=0;
    qint32 enemyAccuracyModifier=0;

    qint32 HPTakenPerAttackPerShip=0;
    qint32 APTakenPerAttackPerShip=0;
    qint32 SPTakenPerAttackPerShip=0;

    qint32 maxShipHP=nSquadronSize*nShipSize*10;
    qint32 maxShipAP=0;
    qint32 maxShipSP=0;

    GameObjectData *gameObjectData;
    qint8 smallLetter=0;
    for(int i=0; i<shipEquipment.size(); i++)
    {
        int c = toQintFromQChar(shipEquipment[i], &smallLetter);

        if((c*2+smallLetter)<=arrayOfEquipmentData.size())
        {
            gameObjectData = &(arrayOfEquipmentData[c*2+smallLetter]);
        }
        else
        {
            gameObjectData = &(arrayOfAccuracyModifierData[(c-18)*2+smallLetter]);
        }

        if(gameObjectData->getType()==1)
        {
            HPTakenPerAttackPerShip+=gameObjectData->getHitPoints();
            APTakenPerAttackPerShip+=gameObjectData->getArmorPoints();
            SPTakenPerAttackPerShip+=gameObjectData->getShieldPoints();
        }
        else if(gameObjectData->getType()==2)
        {
            maxShipAP+=(nSquadronSize*gameObjectData->getArmorPoints());
            maxShipSP+=(nSquadronSize*gameObjectData->getShieldPoints());
        }
        else if(gameObjectData->getType()==3)
        {
            int accuracyModifier = gameObjectData->getAccuracyModifier();
            if(accuracyModifier<0 && accuracyModifier<enemyAccuracyModifier)
            {
                enemyAccuracyModifier=accuracyModifier;
            }
            else if(accuracyModifier>0 && accuracyModifier>ownAccuracyModifier)
            {
                ownAccuracyModifier=accuracyModifier;
            }
        }

    }


    return Ship(sShipType, shipName, attackModifier, nSquadronSize,
                shipData->getMinSize(), nShipSize, shipData->getMaxSize(),
                ownAccuracyModifier, enemyAccuracyModifier,
                HPTakenPerAttackPerShip, APTakenPerAttackPerShip, SPTakenPerAttackPerShip,
                maxShipHP, maxShipAP, maxShipSP
           );
}
qint8 DataStorage::toQintFromQChar(QChar qChar, qint8 *smallLetter)
{
    qint8 ret = qChar.toLatin1();
    if(ret<=90)
    {
        ret-=65;
        *smallLetter=0;
    }
    else if(ret<=122)
    {
        ret=-97;
        *smallLetter=1;
    }
    return ret;
}

GamerResearch *DataStorage::returnGamerResearch(QString research)
{
    qint8 hullSize = research.left(2).toInt();
    research.remove(0, 2);
    qint8 smallLetter=0;

    qint8 missile =
            toQintFromQChar(research.left(1).at(0), &smallLetter)*2+smallLetter;
    research.remove(0, 1);
    qint8 ionCannon =
            toQintFromQChar(research.left(1).at(0), &smallLetter)*2+smallLetter;
    research.remove(0, 1);
    qint8 plasmaGun =
            toQintFromQChar(research.left(1).at(0), &smallLetter)*2+smallLetter;
    research.remove(0, 1);

    qint8 armor =
            toQintFromQChar(research.left(1).at(0), &smallLetter)*2+smallLetter;
    research.remove(0, 1);
    qint8 shield =
            toQintFromQChar(research.left(1).at(0), &smallLetter)*2+smallLetter;
    research.remove(0, 1);

    qint8 ecm =
            (toQintFromQChar(research.left(1).at(0), &smallLetter)-18)*2+smallLetter;
    research.remove(0, 1);
    qint8 eccm =
            (toQintFromQChar(research.left(1).at(0), &smallLetter)-18)*2+smallLetter;
    research.remove(0, 1);

    qint8 fleetSize = research.left(1).toInt();
    research.remove(0, 1);

    //2             1       1           1           1       1       1   1       1
    //SHIPS_SIZE    MISSILE ION_CANNON  PLASMA_GUN  ARMOR   SHIELD  ECM ECCM    RFLEET

    return new GamerResearch(hullSize,
                             missile, ionCannon, plasmaGun,
                             armor, shield,
                             ecm, eccm,
                             fleetSize,
            arrayOfResearchCategoryData[0].getLastElementFromArrayOfResearchData(0)+1,
            arrayOfResearchCategoryData[0].getLastElementFromArrayOfResearchData(1)+1,
            arrayOfResearchCategoryData[0].getLastElementFromArrayOfResearchData(2)+1,
            arrayOfResearchCategoryData[1].getLastElementFromArrayOfResearchData(0)+1,
            arrayOfResearchCategoryData[1].getLastElementFromArrayOfResearchData(1)+1,
            arrayOfResearchCategoryData[2].getLastElementFromArrayOfResearchData(0)+1,
            arrayOfResearchCategoryData[2].getLastElementFromArrayOfResearchData(1)+1);
}

void DataStorage::interpretLineOfObjectData(char *data, qint8 type)
{
    QString lineOfData(data);
    QStringList listOfData = lineOfData.split(9);

    if(type==1)
    {
        /*QChar id, QString name, QString, qint8 time, qint8 cost,
                          qint8 hp, qint8 ap, qint8 sp, qint8 type=1*/
        arrayOfEquipmentData.append(OffensiveData(listOfData.at(0),
                                               listOfData.at(1),
                                               listOfData.at(2).toInt(),
                                               listOfData.at(3).toInt(),
                                               listOfData.at(4).toInt(),
                                               listOfData.at(5).toInt(),
                                               listOfData.at(6).toInt()
                                               ));
    }
    if(type==2)
    {
        /*QChar id, QString name, qint8 time, qint8 cost,
              qint8 hp, qint8 ap, qint8 sp, qint8 type*/
        arrayOfEquipmentData.append(DefensiveData(listOfData.at(0),
                                               listOfData.at(1),
                                               listOfData.at(2).toInt(),
                                               listOfData.at(3).toInt(),
                                               listOfData.at(4).toInt(),
                                               listOfData.at(5).toInt(),
                                               listOfData.at(6).toInt()
                                               ));
    }
    if(type==3)
    {
        /*QChar id, QString name, qint8 time, qint8 cost,
                     qint8 acc_mod, qint8 type*/
        arrayOfAccuracyModifierData.append(AccuracyModifierData(listOfData.at(0),
                                               listOfData.at(1),
                                               listOfData.at(2).toInt(),
                                               listOfData.at(3).toInt(),
                                               listOfData.at(4).toInt()
                                               ));
    }
    if(type==4)
    {
        /*QString idExt, QString name, qint8 time, qint8 cost,
         qint8 min_size, qint8 max_size,*/
        arrayOfShipData.append(ShipData( listOfData.at(0),
                                           listOfData.at(1),
                                           listOfData.at(2).toInt(),
                                           listOfData.at(3).toInt(),
                                           listOfData.at(4).toInt(),
                                           listOfData.at(5).toInt()
                                           ));
    }
}

int DataStorage::interpretLineOfResearchData(char *data, qint8 researchDataSizePerCategory, bool *categoryLoaded)
{
    QString lineOfData(data);
    QStringList listOfData = lineOfData.split(9);
    if(researchDataSizePerCategory==0)
    {
        *(categoryLoaded)=true;
    }

    if(!(*(categoryLoaded)) && researchDataSizePerCategory>0)
    {
        arrayOfResearchCategoryData.append(ResearchCategoryData(listOfData.at(0),
                                                                listOfData.at(1)));
    }
    else if(researchDataSizePerCategory>0)
    {
        this->arrayOfResearchCategoryData[listOfData.at(0).toInt()].
                addResearch(ResearchData(listOfData.at(1),
                                        listOfData.at(2).toInt(),
                                        listOfData.at(3).toInt()));
    }

    if(researchDataSizePerCategory<=0)
    {
        if(listOfData.at(0).at(0).toLatin1()=='*')
        {
            researchDataSizePerCategory=listOfData.at(1).toInt();
            researchDataSizePerCategory++;
        }
    }



/* */

    researchDataSizePerCategory--;
    return researchDataSizePerCategory;
}
QVector<ResearchCategoryData> DataStorage::getArrayOfResearchCategoryData()
{
    return this->arrayOfResearchCategoryData;
}
