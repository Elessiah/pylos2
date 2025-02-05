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
      // threadPool.setTasksTarget(neurons[nLayer].size());
      for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
	neurons[nLayer][nNeuron]->compute();
      // threadPool.addToQueue([this, nLayer, nNeuron]() { this->neurons[nLayer][nNeuron]->compute(); } );
      // threadPool.waitAll();
    }
}
