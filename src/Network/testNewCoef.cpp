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
						 const std::vector<s_learnSubjects>	&subjects,
						 double				&newScore,
						 char				&isReverse)
{
  double		testScore;
  std::shared_ptr<Neuron>	neuron  = network.neurons[nLayer][nNeuron];

  if (modCoef != 1)
    {
      neuron->tryNewCoef(nLink, modCoef);
      newScore = network.examen(subjects);
    }
  neuron->switchReverse();
  testScore = network.examen(subjects);
  if (testScore < newScore)
    {
      newScore = testScore;
      isReverse = 1;
    }
  if (modCoef != 1)
    neuron->back();
  neuron->switchReverse();
}
