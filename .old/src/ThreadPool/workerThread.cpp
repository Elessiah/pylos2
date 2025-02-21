// ************************************************
// 30/01/2025 10:04:18
// Keryan HOUSSIN 
// ThreadPool
// ************************************************

#include			"threadPool.hh"

void				ef::ThreadPool::workerThread(int	id)
{
  while (true)
    {
      std::function<void()>	task;
      {
      std::unique_lock<std::mutex>	lock(mutex);

      condition.wait(lock, [this] { return stop || !tasks.empty(); });
      if (stop && tasks.empty())
	return;
      tasksRemaining.fetch_add(1);
      task = std::move(tasks.front());
      tasks.pop();
      }
      task();
      if ((tasksRemaining.fetch_sub(1) - 1) == 0)
	main.notify_all();
    }
}
