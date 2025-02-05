// ************************************************
// 24/01/2025 10:13:25
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

size_t			ef::Network::addNeurons(size_t		nbNeurons,
						size_t		nLayer)
{
  size_t		nbNewNeurons;

  for (nbNewNeurons = 0; nbNewNeurons < nbNeurons; nbNewNeurons += addNeuron(nLayer));
  return (nbNewNeurons);
}

size_t			ef::Network::addNeurons(size_t		nbNeurons)
{
  size_t		nbNewNeurons;
  
  for (nbNewNeurons = 0; nbNewNeurons < nbNeurons; nbNewNeurons += addNeuron());
  return (nbNewNeurons);
}
