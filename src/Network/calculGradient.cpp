// ************************************************
// 23/01/2025 12:23:08
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::Network::calculGradient(s_learnSubjects		&subject,
						    size_t			compteur)
{
  size_t		nLayer;
  size_t		nNeuron;

  for (nLayer = neurons.size() - 1; nLayer > INPUT_LAYER; nLayer -= 1)
    {
      for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
	{
	  neurons[nLayer][nNeuron]->calculGradient(gradient[nLayer][nNeuron],
						   subject.expectedResults[nNeuron],
						   compteur,
						   nLayer == (neurons.size() - 1));
	}
    }
}
