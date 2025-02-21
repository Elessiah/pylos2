// ************************************************
// 02/02/2025 20:51:00
// Keryan HOUSSIN 
// Pylos
// ************************************************

#include		"network.hh"

void			ef::Network::testNewCoef(Network			network,
						 int				nLayer,
						 int				nNeuron,
						 int				nLink,
						 double				modCoef,
						 std::vector<s_learnSubjects>	&subjects,
						 double				&newScore,
						 char				&isReverse)
{
  s_testCoef		testCoef = {nLayer, nNeuron, nLink, modCoef, &subjects, newScore, isReverse};

  testNewCoef(network, testCoef);
  newScore = testCoef.newScore;
  isReverse = testCoef.isReverse;
}

void			ef::Network::testNewCoef(Network			&network,
						 s_testCoef			&testCoef)
{
  double		testScore;
  std::shared_ptr<Neuron>	neuron  = network.neurons[testCoef.nLayer][testCoef.nNeuron];

  if (testCoef.modCoef != 1)
    {
      neuron->tryNewCoef(testCoef.nLink, testCoef.modCoef);
      testCoef.newScore = network.examen(*testCoef.subjects);
    }
  neuron->switchReverse();
  testScore = network.examen(*testCoef.subjects);
  if (testScore < testCoef.newScore || testCoef.modCoef == 1)
    {
      testCoef.newScore = testScore;
      testCoef.isReverse = 1;
    }
  neuron->switchReverse();
  if (testCoef.modCoef != 1)
    neuron->back();
}
