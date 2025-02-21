// ************************************************
// 21/02/2025 11:43:07
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"logicDeductor.hh"

ef::LogicDeductor::LogicDeductor()
  : isLoad(false)
{
}

ef::LogicDeductor::LogicDeductor(std::vector<s_learnSubjects>	&subjects)
  : isLoad(true)
{
  load(subjects);
}

ef::LogicDeductor::~LogicDeductor()
{
}
