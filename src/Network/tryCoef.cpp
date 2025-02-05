// ************************************************
// 20/01/2025 09:08:20
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::Network::tryCoef(std::vector<s_learnSubjects>	&subjects,
					     double				&currentScore,
					     int				nLayer,
					     int				nNeuron,
					     size_t				nLink)
{
  std::vector<double>	modCoef = {1.95, 1.75, 1.5, 1.25, 1.1, 1, 0.95, 0.75, 0.5, 0.25, 0.1, 0};
  std::vector<double>	newScores;
  std::vector<char>	isReverse;
  size_t		nCoef;

  for (nCoef = 0; nCoef < modCoef.size(); nCoef += 1)
    {
      newScores.emplace_back(0);
      isReverse.emplace_back(0);
      threadPool.addToQueue([this, nLayer, nNeuron, nLink, subjects, &newScores, &isReverse, nCoef]() { this->testNewCoef(*this, nLayer, nNeuron, nLink, nCoef, subjects, newScores[nCoef], isReverse[nCoef]); } );
    }
  threadPool.waitAll();
  int			bestCoef;
  double		bestScore;
  bool			isBestReverse;

  bestCoef = -1;
  bestScore = currentScore;
  isBestReverse = false;
  for (nCoef = 1; nCoef < modCoef.size(); nCoef += 1)
    {
      if (bestScore > newScores[nCoef])
	{
	  bestScore = newScores[nCoef];
	  isBestReverse = (isReverse[nCoef] == 1);
	}
    }
  if (bestCoef != -1)
    {
      neurons[nLayer][nNeuron]->tryNewCoef(nLink, modCoef[bestCoef]);
      if (isBestReverse)
	neurons[nLayer][nNeuron]->switchReverse();
    }
}
