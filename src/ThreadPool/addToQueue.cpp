// ************************************************
// 30/01/2025 10:01:28
// Keryan HOUSSIN 
// ThreadPool
// ************************************************

#include		"threadPool.hh"

void			ef::ThreadPool::addToQueue(std::function<void()> task)
{
  std::unique_lock<std::mutex>	lock(mutex);
  tasks.push(std::move(task));
  condition.notify_one();
}
