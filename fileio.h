#ifndef FILEIO_H
#define FILEIO_H

#include <QFile>
#include <QDebug>
#include <QList>

class FileIO
{
public:
    FileIO(QString filename);
    bool saveFile(QList<QString> list);
private:
    QString filename;
};

#endif // FILEIO_H
