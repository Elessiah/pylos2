// ************************************************
// 06/02/2025 15:21:12
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"

void			ef::NetworkCloner::waitAll()
{
  std::unique_lock<std::mutex>	lock(jobMutex);

  if (clones.size() == 0)
    throw std::runtime_error("No clone defined, deadlock !");
  main.wait(lock, [this] { return joinOrder && splitTasks.empty() && splitRemaining.load() == 0; });
}
