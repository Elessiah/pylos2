// ************************************************
// 25/01/2025 09:40:14
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::Network::applyRetropropagation(double			speed)
{
  size_t		nLayer;
  size_t		nNeuron;

  for (nLayer = INPUT_LAYER + 1; nLayer < neurons.size(); nLayer += 1)
    {
      for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
	neurons[nLayer][nNeuron]->applyGradient(gradient[nLayer][nNeuron], speed);
    }
}
