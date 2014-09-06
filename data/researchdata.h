#ifndef RESEARCHDATA_H
#define RESEARCHDATA_H
#include "includeFile.h"

class ResearchData
{
public:
    ResearchData() {}
    ResearchData(QString researchName,
                 qint8 firstElementFromArray, qint8 lastElementFromArray);
    QString getResearchName();
    qint8 getFirstElement();
    qint8 getLastElement();
private:
    QString researchName;
    qint8 firstElementFromArray;
    qint8 lastElementFromArray;
};

#endif // RESEARCHDATA_H
