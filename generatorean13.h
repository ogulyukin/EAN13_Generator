#ifndef GENERATOREAN13_H
#define GENERATOREAN13_H

#include <QDebug>

class GeneratorEAN13
{
public:
    static qint64 generatecode(qint64 code);
private:
    static int findNextTenNumber(int num);
};

#endif // GENERATOREAN13_H
