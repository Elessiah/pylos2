// ************************************************
// 06/02/2025 16:58:23
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"

std::vector<double>	ef::Neuron::getLinksCoef()
{
  std::vector<double>	links;

  for (ef::s_input &input : inputs)
    links.emplace_back(input.coef);
  return (links);
}
