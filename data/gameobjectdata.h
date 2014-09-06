#ifndef GAMEOBJECTDATA_H
#define GAMEOBJECTDATA_H

#include "includeFile.h"

class GameObjectData
{
public:
    GameObjectData();
    QString getID();
    QString getName();
    qint32 getTime();
    qint32 getCost();
    qint8 getType();

    virtual qint32 getAccuracyModifier();
    virtual qint32 getHitPoints();
    virtual qint32 getArmorPoints();
    virtual qint32 getShieldPoints();
protected:
    QString id;
    QString name;
    qint32 time;
    qint32 cost;
    qint8 type;
};

#endif // GAMEOBJECTDATA_H
