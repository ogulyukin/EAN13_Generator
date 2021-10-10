#include "generatorean13.h"


qint64 GeneratorEAN13::generatecode(qint64 code)
{
    QString temp = QString::number(code);
    bool go = false;
    int even = 0;
    int odd = 0;
    foreach(auto i, temp)
    {
        if(go)
        {
            int one = QString(i).toInt();
            even += one;
            go = false;
        }else
        {
            int one = QString(i).toInt();
            odd += one;
            go = true;
        }
    }

    even *= 3;
    even += odd;
    int nextTen = findNextTenNumber(even);
    if(nextTen != 1000)
        return code * 10 + (nextTen - even);
    return 0;
}

int GeneratorEAN13::findNextTenNumber(int num)
{
    if(num <= 10)
    {
        return 10;
    }
    int result = 0;
    int temp;

    if (num > 200)
    {
        result = 200;
        temp = num - 200;
    } else if(num > 100)
    {
        result = 100;
        temp = num - 100;
    }else
    {
        temp = num;
    }
    for(int i = 20; i <= 100; i += 10)
    {
        if(i >= temp)
        {
            return result + i;
        }
    }
    qDebug() << "ОШИБКА!!!!!";
    return 1000;
}
