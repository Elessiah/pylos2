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
  else if (order->type == SEND_NETWORK)
    {
      size_t		nLayer;
      size_t		nNeuron;

      order->neuronsCoef->clear();
      for (nLayer = 0; nLayer < network.neurons.size(); nLayer += 1)
	{
	  order->neuronsCoef->emplace_back();
	  for (nNeuron = 0; nNeuron < network.neurons[nLayer].size(); nNeuron += 1)
	    order->neuronsCoef[nLayer][nNeuron].emplace_back(network.neurons[nLayer][nNeuron]->getLinksCoef());
	}
    }
}
