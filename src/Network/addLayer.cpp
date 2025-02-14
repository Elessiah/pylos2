// ************************************************
// 24/01/2025 10:11:25
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

size_t			ef::Network::addLayer(bool		sync)
{
  size_t		indexNewLayer;
  size_t		nbNewNeurons;

  indexNewLayer = neurons.size() - 1;
  neurons.push_back(neurons[indexNewLayer]);
  neurons[indexNewLayer].clear();
  unlinkLayer(neurons.size() - 1);
  nbNewNeurons = addNeurons(neurons[neurons.size() - 1].size() + 2, indexNewLayer, false);
  if (sync)
    syncCloneNetworks();
  return (nbNewNeurons);
}
