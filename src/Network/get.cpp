// ************************************************
// 12/02/2025 12:45:45
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

std::vector<std::vector<std::vector<double>>>	ef::Network::get()
{
  std::vector<std::vector<std::vector<double>>>	result;
  size_t		nLayer;
  size_t		nNeuron;

  for (nLayer = 0; nLayer < neurons.size(); nLayer += 1)
    {
      result.emplace_back();
      for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
	result[nLayer].emplace_back(neurons[nLayer][nNeuron]->getLinksCoef());
    }
  return (result);
}
