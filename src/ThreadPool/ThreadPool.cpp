// ************************************************
// 30/01/2025 09:49:30
// Keryan HOUSSIN 
// ThreadPool
// ************************************************

#include		"threadPool.hh"

ef::ThreadPool::ThreadPool()
  : ThreadPool(std::thread::hardware_concurrency())
{
}

ef::ThreadPool::ThreadPool(int		nbThreads)
  : stop(false)
{
  int		i;

  for (i = 0; i < nbThreads; i += 1)
    workers.emplace_back([this, i] { workerThread(i); });
}

ef::ThreadPool::~ThreadPool()
{
  std::unique_lock<std::mutex> lock(mutex);
  stop = true;
  lock.unlock();
  condition.notify_all();
  for (std::thread &worker : workers)
    worker.join();
}
