#include "equipmentdata.h"

EquipmentData::EquipmentData()
{
    id="";
    name="";
    time=0;
    cost=0;
    type=0;

    hit_points=0;
    armor_points=0;
    shield_points=0;
}

qint32 EquipmentData::getHitPoints()
{
    return hit_points;
}
qint32 EquipmentData::getArmorPoints()
{
    return armor_points;
}
qint32 EquipmentData::getShieldPoints()
{
    return shield_points;
}
