// ************************************************
// 06/02/2025 16:13:37
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"
#include		"network.hh"

void			ef::NetworkCloner::addClone(ef::Network	&network)
{
  clones.emplace_back([this, network] { workerThread(network, getNbClone()); });
}
