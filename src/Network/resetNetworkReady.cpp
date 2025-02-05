// ************************************************
// 10/01/2025 14:53:42
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::Network::resetNetworkReady()
{
  size_t		nLayer;
  size_t		nNeuron;

  for (nLayer = 0; nLayer < neurons.size(); nLayer += 1)
    for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
      neurons[nLayer][nNeuron]->resetReady();
}
