#ifndef SHIPDATA_H
#define SHIPDATA_H
#include "includeFile.h"
#include "gameobjectdata.h"

class ShipData : public GameObjectData
{
public:
    ShipData() {}
    ShipData(QString idExt, QString name, qint32 time, qint32 cost,
             qint32 min_size, qint32 max_size);
    qint32 getMinSize();
    qint32 getMaxSize();
protected:
    qint32 min_size;
    qint32 max_size;
};
#endif // SHIPDATA_H
