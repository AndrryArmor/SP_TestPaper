#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QChar>
#include <string>
#include <list>
 
 using namespace std;
 
class FileManager
{
 
public:

   QChar LoadFromFile(string filePath);
   static void SaveToFile(QChar jsonObject,string filePath);
 
private:
    FileManager();
};

#endif
