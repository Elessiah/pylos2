// ************************************************
// 10/01/2025 14:36:23
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

std::vector<double>	ef::Network::getOutput()
{
  std::vector<double>	result;

  if (neurons.size() == 0)
    return (result);
  size_t		lastLayer;
  size_t		i;

  lastLayer = neurons.size() - 1;
  for (i = 0; i < neurons[lastLayer].size(); i += 1)
    result.emplace_back(neurons[lastLayer][i].getOutput());
  return (result);
}
