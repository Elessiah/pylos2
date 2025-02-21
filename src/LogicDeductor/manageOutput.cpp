// ************************************************
// 21/02/2025 11:54:02
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"logicDeductor.hh"

void			ef::LogicDeductor::manageOutput(std::vector<s_learnSubjects>	&subjects,
							int				indexOutput)
{
  std::vector<std::vector<double>>	on;
  std::vector<std::vector<double>>	off;
  std::vector<s_logicDoor>		conditions;
  
  extractInputs(subjects, indexOutput, on, off);
  extractConditions(on, off, conditions);
  //  formatConditions(conditions);
}
