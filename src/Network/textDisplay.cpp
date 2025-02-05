// ************************************************
// 24/01/2025 18:03:53
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

#include		<iostream>

void			ef::Network::textDisplay()
{
  size_t		i;

  std::cout << "Architecture of network : \n";
  for (i = 0; i < neurons.size(); i += 1)
    std::cout << neurons[i].size() << " / ";
  std::cout << std::endl;
}
