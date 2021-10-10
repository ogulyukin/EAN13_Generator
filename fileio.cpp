#include "fileio.h"

FileIO::FileIO(QString filename) : filename(filename)
{

}

bool FileIO::saveFile(QList<QString> list)
{
    QFile target(filename);
    if (!target.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        qDebug() << "Невозможно открыть файл " << filename  << " для записи";
        return false;
    }
    QTextStream ofstr(&target);
    foreach(QString i, list)
    {
        qDebug() << i;
        if(i == 0)
        {
            return false;
        }
        ofstr << i << Qt::endl;
    }
    target.close();
    return true;
}
