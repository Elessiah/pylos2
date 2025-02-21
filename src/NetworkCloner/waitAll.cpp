// ************************************************
// 06/02/2025 15:21:12
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"

void			ef::NetworkCloner::waitAll()
{
  std::unique_lock<std::mutex>	lock(jobMutex);

  main.wait(lock, [this] { return clones.size() == 0 || (joinOrder.load() && splitTasks.empty() && splitRemaining.load() == 0); });
}
