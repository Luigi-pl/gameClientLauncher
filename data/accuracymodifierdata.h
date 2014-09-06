#ifndef ACCURACYMODIFIERDATA_H
#define ACCURACYMODIFIERDATA_H
#include "includeFile.h"
#include "gameobjectdata.h"

class AccuracyModifierData : public GameObjectData
{
public:
    AccuracyModifierData() {}
    AccuracyModifierData(QString id, QString name, qint32 time, qint32 cost,
                         qint32 acc_mod);
    virtual qint32 getAccuracyModifier();
protected:
    qint32 accuracy_modifier;
};

#endif // ACCURACYMODIFIERDATA_H
