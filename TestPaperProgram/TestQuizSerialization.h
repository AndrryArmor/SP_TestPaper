#ifndef TESTQUIZSERIALIZATION_H
#define TESTQUIZSERIALIZATION_H

#include <Quiz.h>

class TestQuizSerialization
{

public:
 TestQuizSerialization();
 ~TestQuizSerialization();
 static void testSerializeAndDeserializeQuestion();

private:
   static Quiz *GetTestQuizesData();

   static void Serialize(Quiz *quiz);

   static Quiz *Deserialize();
};
#endif // TESTQUIZSERIALIZATION_H
