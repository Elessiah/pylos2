// ************************************************
// 06/02/2025 14:03:52
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include				"networkCloner.hh"
#include				"network.hh"

void					ef::NetworkCloner::workerThread(ef::Network	network,
									int		id)
{
  s_splitOrder				*splitTask;
  bool					beacon = repeatBeacon;

  //  std::cout << "Clone " << id << " starting..." << std::endl;
  while (true)
    {
      std::unique_lock<std::mutex>	lock(jobMutex);

      jobVar.wait(lock, [this, beacon] { return (stop || !splitTasks.empty() || (joinOrder.load() != nullptr && beacon != repeatBeacon)); });
      if (stop && splitTasks.empty() && joinOrder.load() == nullptr)
	return;
      if (!splitTasks.empty())
	{
	  splitRemaining.fetch_add(1);
	  splitTask = std::move(splitTasks.front());
	  splitTasks.pop();
	  lock.unlock();
	  manageSplitTask(network, splitTask);
	  splitRemaining.fetch_sub(1);
	  if (splitTasks.empty() && splitRemaining.load() == 0)
	    main.notify_all();
	}
      else if (joinOrder.load() != nullptr)
	{
	  beacon = !beacon;
	  lock.unlock();
	  manageJoinTask(network, joinOrder.load());
	  joinRemaining.fetch_sub(1);
	  if (joinRemaining.load() == 0)
	    {
	    //	      std::this_thread::sleep_for(std::chrono::microseconds(5));
	      {
		std::lock_guard<std::mutex> lock(jobMutex);
		joinOrder.store(nullptr, std::memory_order_release);
	      }
	      main.notify_all();
	    }
	}
      else
	std::cerr << "No order after wake up !" << std::endl;
    }
}
