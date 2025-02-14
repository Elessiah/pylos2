// ************************************************
// 23/01/2025 15:21:04
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include			"network.hh"

size_t				ef::Network::addNeuron(bool		sync)
{
  size_t			layerToAdd;

  layerToAdd = chooseLayerToAdd();
  if (layerToAdd == INPUT_LAYER)
    return (addLayer(sync));
  return (addNeuron(layerToAdd, sync));
}

size_t				ef::Network::addNeuron(size_t		nLayer,
						       bool		sync)
{
  size_t			nNeuron;
  std::shared_ptr<Neuron>	newNeuron;

  if (nLayer == 0)
    {
      std::vector<std::shared_ptr<ef::Neuron>>	empty;

      newNeuron = neurons[nLayer].emplace_back(std::make_shared<Neuron>(empty));
    }
  else
    newNeuron = neurons[nLayer].emplace_back(std::make_shared<Neuron>(neurons[nLayer - 1]));
  nLayer += 1;
  for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
    neurons[nLayer][nNeuron]->linkNewNeuron(newNeuron);
  initGradient(false);
  if (sync)
    syncCloneNetworks();
  return (1);
}
