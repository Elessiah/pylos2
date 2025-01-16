// ************************************************
// 16/01/2025 15:15:10
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

size_t			ef::Network::getNbLinks()
{
  size_t		result;
  size_t		i;

  result = 0;
  for (i = 1; i < neurons.size(); i += 1)
    result += neurons[i].size() * neurons[i - 1].size();
  return (result);
}
