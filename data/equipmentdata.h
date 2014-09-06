#ifndef EQUIPMENTDATA_H
#define EQUIPMENTDATA_H
#include "includeFile.h"
#include "gameobjectdata.h"

class EquipmentData : public GameObjectData
{
public:
    EquipmentData();
    virtual qint32 getHitPoints();
    virtual qint32 getArmorPoints();
    virtual qint32 getShieldPoints();

protected:
    qint32 hit_points;
    qint32 armor_points;
    qint32 shield_points;
};

#endif // EQUIPMENTDATA_H
