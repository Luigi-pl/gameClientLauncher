#include "gameobjectdata.h"

GameObjectData::GameObjectData()
{
    id="";
    name="";
    time=0;
    cost=0;
    type=0;
}

QString GameObjectData::getID()
{
    return id;
}
QString GameObjectData::getName()
{
    return name;
}
qint32 GameObjectData::getTime()
{
    return time;
}
qint32 GameObjectData::getCost()
{
    return cost;
}
qint8 GameObjectData::getType()
{
    return type;
}
qint32 GameObjectData::getHitPoints()
{
    return 0;
}

qint32 GameObjectData::getArmorPoints()
{
    return 0;
}

qint32 GameObjectData::getShieldPoints()
{
    return 0;
}
qint32 GameObjectData::getAccuracyModifier()
{
    return 0;
}
