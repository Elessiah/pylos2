// ************************************************
// 24/01/2025 10:38:30
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

size_t			ef::Network::addLayers(size_t		nbLayers)
{
  size_t		i;
  size_t		nbNewNeurons;

  nbNewNeurons = 0;
  for (i = 0; i < nbLayers; i += 1)
    nbNewNeurons += addLayer();
  return (nbNewNeurons);
}
