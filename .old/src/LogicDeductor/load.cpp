// ************************************************
// 21/02/2025 11:46:46
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"logicDeductor.hh"

#include		<iostream>

void			ef::LogicDeductor::load(std::vector<s_learnSubjects>	&subjects)
{
  if (isLoad)
    logicNetwork.clear();
  if (subjects.size() == 0)
    {
      std::cerr << "Cannot load anything without subjects !" << std::endl;
      return;
    }
  size_t		i;
  //  for (i = 0; i < subjects[0].expectedResults.size(); i += 1)
  manageOutput(subjects, 2);
}
