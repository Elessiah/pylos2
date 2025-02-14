// ************************************************
// 06/02/2025 16:39:48
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"
#include		"network.hh"

void			ef::NetworkCloner::manageJoinTask(ef::Network	&network,
							  s_joinOrder	*order)
{
  if (order->type == SYNC_LINK)
    {
      network.neurons[order->syncLink.nLayer][order->syncLink.nNeuron]->tryNewCoef(order->syncLink.nLink, order->syncLink.modCoef);
      if (order->syncLink.reverse)
	network.neurons[order->syncLink.nLayer][order->syncLink.nNeuron]->switchReverse();
    }
  else if (order->type == SYNC_NETWORK)
    syncNetwork(network, order);
  else if (order->type == SEND_NETWORK)
    order->neurons = &network.neurons;
  else if (order->type == COMPARE_NETWORK)
    order->compareNetwork.isEqual = *(order->compareNetwork.network) == network;
}
