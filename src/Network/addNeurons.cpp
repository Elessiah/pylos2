// ************************************************
// 24/01/2025 10:13:25
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

size_t			ef::Network::addNeurons(size_t		nbNeurons,
						size_t		nLayer,
						bool		sync)
{
  size_t		nbNewNeurons;

  for (nbNewNeurons = 0; nbNewNeurons < nbNeurons; nbNewNeurons += addNeuron(nLayer, false));
  if (sync)
    syncCloneNetworks();
  return (nbNewNeurons);
}

size_t			ef::Network::addNeurons(size_t		nbNeurons,
						bool		sync)
{
  size_t		nbNewNeurons;
  
  for (nbNewNeurons = 0; nbNewNeurons < nbNeurons; nbNewNeurons += addNeuron(false));
  if (sync)
    syncCloneNetworks();
  return (nbNewNeurons);
}
