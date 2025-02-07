// ************************************************
// 07/02/2025 13:34:38
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"

void			ef::NetworkCloner::addClones(ef::Network	&network,
						     size_t		nbClones)
{
  size_t		nClone;

  for (nClone = 0; nClone < nbClones; nbClones += 1)
    addClone(network);
}
