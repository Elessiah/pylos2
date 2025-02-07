// ************************************************
// 06/02/2025 15:57:19
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"

void			ef::NetworkCloner::join(s_joinOrder	&order)
{
  joinRemaining.store(clones.size());
  joinOrder = &order;
}
