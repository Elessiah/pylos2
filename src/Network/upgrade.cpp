// ************************************************
// 07/02/2025 14:11:58
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::Network::upgrade(int		nLayer,
					     int		nNeuron,
					     int		nLink,
					     double		modCoef,
					     bool		isReverse)
{
  neurons[nLayer][nNeuron]->tryNewCoef(nLink, modCoef);
  if (isReverse)
    neurons[nLayer][nNeuron]->switchReverse();
  s_joinOrder		order = {SYNC_LINK, .syncLink = {nLayer, nNeuron, nLink, modCoef, isReverse}};
  cloner.join(order);
  cloner.waitJoin();
}
