#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QChar>
#include <QDebug>
#include <QJsonParseError>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "filemanager.h"

using namespace std;

void FileManager::SaveToFile(QByteArray jsonObject,QString saveFileName)
{
        QFileInfo fileInfo(saveFileName);   // Using QFileInfo
        QDir::setCurrent(fileInfo.path());  // set the current working directory where the file will be, otherwise it may not work
        // Create a file object and open it for writing.
        QFile jsonFile(saveFileName);
        if (!jsonFile.open(QIODevice::WriteOnly))
        {
            return;
        }

        // Write the current Json object to a file.
        jsonFile.write(jsonObject);
        jsonFile.close();   // Close file
}

FileManager::FileManager(){

}

QString FileManager::LoadFromFile(QString openFileName)
{

       QFileInfo fileInfo(openFileName);   // Using QFileInfo
       QDir::setCurrent(fileInfo.path());  // set the current working directory where the file will be
       // Create a file object and open it for reading.
       QFile jsonFile(openFileName);
       if (!jsonFile.open(QIODevice::ReadOnly))
       {
           return "";
       }

       // Read the entire file
       QByteArray saveData = jsonFile.readAll();
       // Create QJsonDocument
       QJsonDocument jsonDocument(QJsonDocument::fromJson(saveData));
       // From which we select an object into the current working QJsonObject
       QJsonObject m_currentJsonObject = jsonDocument.object();
       QString parserJsonObject = QJsonDocument(m_currentJsonObject).toJson(QJsonDocument::Indented);
       return parserJsonObject;
}

