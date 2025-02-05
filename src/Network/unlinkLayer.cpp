// ************************************************
// 24/01/2025 10:32:22
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::Network::unlinkLayer(size_t	nLayer)
{
  size_t		i;

  for (i = 0; i < neurons[nLayer].size(); i += 1)
    neurons[nLayer][i]->unlink();
}
