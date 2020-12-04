#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QChar>
#include <string>
#include <list>
#include <qjsonobject.h>

 using namespace std;

class FileManager
{

public:

    FileManager();
   QString LoadFromFile(QString openFileName);
   void SaveToFile(QByteArray jsonObject,QString saveFileName);

private:

};

#endif
