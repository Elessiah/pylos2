// ************************************************
// 15/01/2025 16:49:51
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

double			ef::Network::examen(std::vector<s_learnSubjects>		&subjects)
{
  std::vector<double>	outputs;
  double		globalResult;
  size_t		nSubject;
  size_t		nOutput;

  globalResult = 0;
  for (nSubject = 0; nSubject < subjects.size(); nSubject += 1)
    {
      outputs = getOutput(subjects[nSubject].inputValues);
      for (nOutput = 0; nOutput < outputs.size(); nOutput += 1)
	outputs[nOutput] -= subjects[nSubject].expectedResults[nOutput];
      globalResult += averageVector(outputs);
    }
  if (subjects.size() != 0)
    return (globalResult / subjects.size());
  return (0);
}
