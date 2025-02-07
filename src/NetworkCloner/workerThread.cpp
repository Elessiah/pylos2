// ************************************************
// 06/02/2025 14:03:52
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include				"networkCloner.hh"
#include				"network.hh"

void					ef::NetworkCloner::workerThread(ef::Network	network)
{
  while (true)
    {
      s_splitOrder			*splitTask;
      std::unique_lock<std::mutex>	lock(jobMutex);

      jobVar.wait(lock, [this] { return stop || !splitTasks.empty() || joinOrder != nullptr; });
      if (stop && splitTasks.empty() && joinOrder == nullptr)
	return;
      if (!splitTasks.empty())
	{
	  splitRemaining.fetch_add(1);
	  splitTask = std::move(splitTasks.front());
	  splitTasks.pop();
	  lock.unlock();
	  manageSplitTask(network, splitTask);
	  splitRemaining.fetch_sub(1);
	  if (splitRemaining.load() == 0)
	    main.notify_all();
	}
      else if (joinOrder != nullptr)
	{
	  lock.unlock();
	  manageJoinTask(network, joinOrder);
	  joinRemaining.fetch_sub(1);
	  if (joinRemaining.load() == 0)
	    {
	      joinOrder = nullptr;
	      main.notify_all();
	    }
	}
    }
}
