#include "researchdata.h"

ResearchData::ResearchData(QString researchName,
                           qint8 firstElementFromArray, qint8 lastElementFromArray)
{
    this->researchName=researchName;
    this->firstElementFromArray=firstElementFromArray;
    this->lastElementFromArray=lastElementFromArray;
}
QString ResearchData::getResearchName()
{
    return this->researchName;
}
qint8 ResearchData::getFirstElement()
{
    return this->firstElementFromArray;
}
qint8 ResearchData::getLastElement()
{
    return this->lastElementFromArray;
}
