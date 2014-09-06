#include "accuracymodifierdata.h"

AccuracyModifierData::AccuracyModifierData(QString id, QString name, qint32 time, qint32 cost,
                     qint32 acc_mod)
{
    this->id=id;
    this->name=name;
    this->time=time;
    this->cost=cost;
    this->accuracy_modifier=acc_mod;
    type=3;
}
qint32 AccuracyModifierData::getAccuracyModifier()
{
    return accuracy_modifier;
}
