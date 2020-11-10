#ifndef QuizJsonSerializer_H
#define QuizJsonSerializer_H
#include "serialization/JsonSerializable.h"
#include <QJsonObject>

class QuizJsonSerializer
{
 
public:
 
   static QString serialize(JsonSerializable &obj);
 
   static void parse(const QString &json, JsonSerializable &jsonSerializable);
 
private:
 
    QuizJsonSerializer();
 
};
#endif
