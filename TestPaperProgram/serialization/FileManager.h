#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QChar>
#include <string>
#include <list>
 
 using namespace std;
 
class FileManager
{
 
public:

   static QChar LoadFromFile(string filePath);
   static void SaveToFile(const char* jsonObject,string filePath);
 
private:
    FileManager();
};

#endif
