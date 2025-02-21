// ************************************************
// 23/01/2025 15:30:06
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

size_t			ef::Network::chooseLayerToAdd()
{
  size_t		nLayer;
  size_t		limit = neurons.size() - 1;
  size_t	        smallestSizeLayer;
  size_t	        smallestLayerIndex;

  smallestSizeLayer = MAX_SIZE_LAYER;
  smallestLayerIndex = 0;
  for (nLayer = INPUT_LAYER + 1; nLayer < limit; nLayer += 1)
    {
      if (neurons[nLayer].size() < smallestSizeLayer)
	{
	  smallestSizeLayer = neurons[nLayer].size();
	  smallestLayerIndex = nLayer;
	}
    }
  return (smallestLayerIndex);
}
