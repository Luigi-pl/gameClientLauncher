#include "defensivedata.h"
DefensiveData::DefensiveData(QString id, QString name, qint32 time, qint32 cost,
              qint32 hp, qint32 ap, qint32 sp)
{
    this->id=id;
    this->name=name;
    this->time=time;
    this->cost=cost;
    this->hit_points=hp;
    this->armor_points=ap;
    this->shield_points=sp;
    type=2;
}
