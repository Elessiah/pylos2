// ************************************************
// 24/01/2025 19:41:12
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"network.hh"

bool		ef::Network::isFullSize()
{
  if (neurons.size() < (neurons[INPUT_LAYER].size() * 3))
    return (false);
  if (isLayerFullSize(neurons.size() - 2))
    return (true);
  return (false);
}
