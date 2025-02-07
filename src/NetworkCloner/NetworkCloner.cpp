// ************************************************
// 06/02/2025 14:00:55
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"networkCloner.hh"

ef::NetworkCloner::NetworkCloner()
  : splitRemaining(0)
  , joinRemaining(0)
  , joinOrder(nullptr)
  , stop(false)
{
}

ef::NetworkCloner::~NetworkCloner()
{
  std::unique_lock<std::mutex>	lock(jobMutex);
  stop = true;
  lock.unlock();
  jobVar.notify_all();
  for (std::thread &clone : clones)
    clone.join();
}
