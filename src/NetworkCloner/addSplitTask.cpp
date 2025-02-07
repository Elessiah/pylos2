// ************************************************
// 06/02/2025 15:49:16
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"

void			ef::NetworkCloner::addSplitTask(s_splitOrder		&order)
{
  splitTasks.push(&order);
}
