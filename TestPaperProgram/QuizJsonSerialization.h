#ifndef QuizJsonSerializer_H
#define QuizJsonSerializer_H
#include "jsonserializable.h"
#include <QJsonObject>

class QuizJsonSerializer
{

public:

   static QByteArray serialize(const JsonSerializable &obj);

   static void parse(const QString &json, JsonSerializable *jsonSerializable);

private:

    QuizJsonSerializer();

};
#endif
