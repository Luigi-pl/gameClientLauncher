#include "shipdata.h"

ShipData::ShipData(QString idExt, QString name, qint32 time, qint32 cost,
         qint32 min_size, qint32 max_size)
{
    this->id=idExt;
    this->name=name;
    this->time=time;
    this->cost=cost;
    this->min_size=min_size;
    this->max_size=max_size;
    type=4;
}

qint32 ShipData::getMinSize()
{
    return min_size;
}
qint32 ShipData::getMaxSize()
{
    return max_size;
}
