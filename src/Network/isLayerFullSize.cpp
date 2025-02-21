// ************************************************
// 24/01/2025 19:52:05
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"network.hh"

bool		ef::Network::isLayerFullSize(size_t		nLayer)
{
  if (neurons[nLayer].size() < (MAX_SIZE_LAYER))
    return (false);
  return (true);
}
