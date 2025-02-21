// ************************************************
// 21/02/2025 15:53:15
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		<gtest/gtest.h>

#include	"logicDeductor.hh"

TEST(LOGIC_DEDUCTOR, ADD2BIT)
{
  ef::LogicDeductor	deductor;
  std::vector<ef::s_learnSubjects>	subjects = ef::getExam(EXAM_ADD2BIT);

  deductor.load(subjects);
}
