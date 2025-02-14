// ************************************************
// 12/02/2025 19:03:17
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::Network::syncCloneNetworks()
{
  if (cloner.getNbClone() > 0)
    {
      s_joinOrder			order = {SYNC_NETWORK, .neurons = &neurons};

      cloner.join(order);
      cloner.waitJoin();
    }
}
