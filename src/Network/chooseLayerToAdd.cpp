// ************************************************
// 23/01/2025 15:30:06
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

size_t			ef::Network::chooseLayerToAdd()
{
  size_t		nLayer;

  for (nLayer = neurons.size() - 2; nLayer > INPUT_LAYER; nLayer += 1)
    {
      if (!isLayerFullSize(nLayer))
	return (nLayer);
    }
  return (0);
}
