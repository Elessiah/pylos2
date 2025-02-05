// ************************************************
// 25/01/2025 08:25:58
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::Network::calculRetropropagation(std::vector<s_learnSubjects>	&subjects)
{
  std::vector<double>	outputs;
  size_t		nSubject;

  initGradient(true);
  networkError = 0;
  for (nSubject = 0; nSubject < subjects.size(); nSubject += 1)
    {
      outputs = getOutput(subjects[nSubject].inputValues);
      calculError(subjects[nSubject], outputs, nSubject + 1);
      calculGradient(subjects[nSubject], nSubject + 1);
    }
}
