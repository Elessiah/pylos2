// ************************************************
// 30/01/2025 17:36:38
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

#include		<unistd.h>

void			ef::Network::compute()
{
  size_t		nLayer;
  size_t		nNeuron;

  for (nLayer = 1; nLayer < neurons.size(); nLayer += 1)
    {
      for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
	neurons[nLayer][nNeuron]->compute();
    }
}
