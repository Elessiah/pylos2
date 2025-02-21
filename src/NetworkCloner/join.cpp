// ************************************************
// 06/02/2025 15:57:19
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"

void			ef::NetworkCloner::join(s_joinOrder	&order)
{
  repeatBeacon = !repeatBeacon;
  joinRemaining.store(clones.size());
  joinOrder.store(&order, std::memory_order_release);
  jobVar.notify_all();
}
