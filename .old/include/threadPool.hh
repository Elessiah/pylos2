// ************************************************
// 30/01/2025 09:34:53
// Keryan HOUSSIN 
// ThreadPool
// ************************************************

#ifndef				__EF_THREAD_POOL_HH__

#define				__EF_THREAD_POOL_HH__

#define		FREE_THREAD	0

#include			<iostream>
#include			<vector>
#include			<queue>
#include			<thread>
#include			<mutex>
#include			<condition_variable>
#include			<future>
#include			<functional>
#include			<atomic>


namespace			ef
{
  class				Neuron;
  class				Network;

  class				ThreadPool {
  public:
    ThreadPool();
    ThreadPool(int		nbThreads);
    ~ThreadPool();

    friend class ef::Neuron;
    friend class ef::Network;

    void			addToQueue(std::function<void()>);
    void			waitAll();
    
  private:
    std::atomic<int>			tasksRemaining;
    std::vector<std::thread>		workers;
    std::queue<std::function<void()>>	tasks;
    std::mutex				mutex;
    std::condition_variable		condition;
    std::condition_variable		main;
    bool				stop;

    void			workerThread(int	id);
  };
}

#endif	//			__EF_THREAD_POOL_HH__
