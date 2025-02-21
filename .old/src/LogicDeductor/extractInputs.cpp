// ************************************************
// 21/02/2025 14:51:27
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"logicDeductor.hh"

void		ef::LogicDeductor::extractInputs(std::vector<s_learnSubjects>		&subjects,
						 int					indexOutput,
						 std::vector<std::vector<double>>	&on,
						 std::vector<std::vector<double>>	&off)
{
  size_t		nSubject;

  for (nSubject = 0; nSubject < subjects.size(); nSubject += 1)
    {
      if (subjects[nSubject].expectedResults[indexOutput] == 1)
	on.push_back(subjects[nSubject].inputValues);
      else
	off.push_back(subjects[nSubject].inputValues);
    }
}

