// ************************************************
// 06/02/2025 15:18:45
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"

void			ef::NetworkCloner::waitSplit()
{
  std::unique_lock<std::mutex>	lock(jobMutex);

  main.wait(lock, [this] { return clones.size() == 0 || (splitTasks.empty() && splitRemaining.load() == 0); });
}
