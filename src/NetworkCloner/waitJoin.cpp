// ************************************************
// 06/02/2025 15:14:31
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"

void			ef::NetworkCloner::waitJoin()
{
  std::unique_lock<std::mutex>	lock(jobMutex);

  main.wait(lock, [this] { return !(clones.size()) || joinOrder == nullptr; });
}
