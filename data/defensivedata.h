#ifndef DEFENSIVEDATA_H
#define DEFENSIVEDATA_H
#include "includeFile.h"
#include "equipmentdata.h"

class DefensiveData : public EquipmentData
{
public:
    DefensiveData(QString id, QString name, qint32 time, qint32 cost,
                  qint32 hp, qint32 ap, qint32 sp);
};

#endif // DEFENSIVEDATA_H
