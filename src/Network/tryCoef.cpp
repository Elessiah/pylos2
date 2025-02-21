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
					     int				nLink)
{
  std::vector<s_splitOrder>	orders;
  size_t		nCoef;

  orders.resize(modCoef.size());
  for (nCoef = 0; nCoef < modCoef.size(); nCoef += 1)
    {
      orders[nCoef] = { TEST_COEF, .testCoef = {nLayer, nNeuron, nLink, modCoef[nCoef], &subjects, -1, 0}};
      if (cloner.getNbClone() > 0)
	cloner.addSplitTask(orders[nCoef]);
      else
	testNewCoef(*this, orders[nCoef].testCoef);
    }
  if (cloner.getNbClone() > 0)
    cloner.waitSplit();
  int			bestCoef;
  double		bestScore;
  bool			isBestReverse;

  bestCoef = -1;
  bestScore = currentScore;
  isBestReverse = false;
  for (nCoef = 1; nCoef < modCoef.size(); nCoef += 1)
    {
      if (orders[nCoef].testCoef.newScore != -1 && bestScore > orders[nCoef].testCoef.newScore)
	{
	  bestCoef = nCoef;
	  bestScore = orders[bestCoef].testCoef.newScore;
	  isBestReverse = (orders[bestCoef].testCoef.isReverse == 1);
	}
    }
  if (bestCoef != -1)
    {
      upgrade(nLayer, nNeuron, nLink, modCoef[bestCoef], isBestReverse);
      currentScore = bestScore;
    }
}
