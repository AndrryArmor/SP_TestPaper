#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QChar>
#include <QDebug>

#include "FileManager.h"

using namespace std;

void FileManager::SaveToFile(QChar jsonObject,string filePath)
{
    QString filename = QString::fromStdString(filePath);
    QFile file(filename);

    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Could not open " << filename;
        return;
    }

    QDataStream cout(&file);
    cout.setVersion(QDataStream::Qt_5_1);
    cout << jsonObject;
    file.flush();
    file.close();
}

QChar FileManager::LoadFromFile(string filePath)
{

    QString filename = QString::fromStdString(filePath);
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open " << filename;
        return QChar::fromLatin1('0') ;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_1);
    QChar parsedJsonOnjectInString;
    in >> parsedJsonOnjectInString;

    file.close();
	return parsedJsonOnjectInString ;
}
