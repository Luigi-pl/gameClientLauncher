#ifndef OFFENSIVEDATA_H
#define OFFENSIVEDATA_H

#include "includeFile.h"
#include "equipmentdata.h"

class OffensiveData : public EquipmentData
{
public:
    OffensiveData(QString id, QString name, qint32 time, qint32 cost,
                  qint32 hp, qint32 ap, qint32 sp);
};
#endif // OFFENSIVEDATA_H
