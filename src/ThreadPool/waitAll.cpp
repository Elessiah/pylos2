// ************************************************
// 31/01/2025 02:22:38
// Keryan HOUSSIN 
// ThreadPool
// ************************************************

#include		"threadPool.hh"

void			ef::ThreadPool::waitAll()
{
  std::unique_lock<std::mutex>	lock(mutex);

  main.wait(lock, [this] { return tasks.empty() && tasksRemaining.load() == 0; });
}
