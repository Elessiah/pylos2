// ************************************************
// 24/01/2025 10:11:25
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

size_t			ef::Network::addLayer()
{
  size_t		indexNewLayer;

  indexNewLayer = neurons.size() - 1;
  neurons.push_back(neurons[indexNewLayer]);
  neurons[indexNewLayer].clear();
  unlinkLayer(neurons.size() - 1);
  return (addNeurons(neurons[neurons.size() - 1].size() + 2, indexNewLayer));
}
