// ************************************************
// 23/01/2025 15:21:04
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include			"network.hh"

size_t				ef::Network::addNeuron()
{
  size_t			layerToAdd;

  layerToAdd = chooseLayerToAdd();
  if (layerToAdd == INPUT_LAYER)
    return (addLayer());
  return (addNeuron(layerToAdd));
}

size_t				ef::Network::addNeuron(size_t		nLayer)
{
  size_t			nNeuron;
  std::shared_ptr<Neuron>	newNeuron;

  newNeuron = neurons[nLayer].emplace_back(std::make_shared<Neuron>(neurons[nLayer - 1], threadPool));
  nLayer += 1;
  for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
    neurons[nLayer][nNeuron]->linkNewNeuron(newNeuron);
  initGradient(false);
  return (1);
}
