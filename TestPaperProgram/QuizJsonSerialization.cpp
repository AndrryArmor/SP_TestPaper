#include "jsonserializable.h"
#include "quizjsonserialization.h"
#include <QJsonDocument>

QByteArray QuizJsonSerializer::serialize(const JsonSerializable &obj)
{
    QJsonObject jsonObj;
    obj.write(jsonObj);
    QJsonDocument doc(jsonObj);
    //QString result(
    QByteArray result= doc.toJson(QJsonDocument::Indented);
    return result;
}

void QuizJsonSerializer::parse(const QString &json, JsonSerializable &jsonSerializable)
{
    QJsonDocument document = QJsonDocument::fromJson(json.toUtf8());

    // The document wrap a jsonObject
    QJsonObject jsonObj = document.object();

    jsonSerializable.read(jsonObj);

}
