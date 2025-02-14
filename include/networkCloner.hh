// ************************************************
// 06/02/2025 13:43:58
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef				__EF_NETWORK_CLONER_HH__

#define				__EF_NETWORK_CLONER_HH__

#include			<iostream>
#include			<vector>
#include			<queue>
#include			<thread>
#include			<mutex>
#include			<condition_variable>
#include			<future>
#include			<functional>
#include			<atomic>

#include			"order.hh"

namespace			ef
{
  class				Network;
  class				NetworkCloner
  {
  public:
    NetworkCloner();
    ~NetworkCloner();

    void			addClone(ef::Network		&network);
    void			addClones(ef::Network		&network,
					  size_t		nbClones);
    void			addSplitTask(s_splitOrder	&order);
    void			join(s_joinOrder		&order);
    void			waitAll();
    void			waitJoin();
    void			waitSplit();
    size_t			getNbClone();
  private:
    std::atomic<int>		splitRemaining;
    std::atomic<int>		joinRemaining;
    std::vector<std::thread>    clones;
    std::queue<s_splitOrder*>	splitTasks;
    s_joinOrder			*joinOrder;
    std::mutex		        jobMutex;
    std::condition_variable	jobVar;
    std::condition_variable	main;
    bool			stop;

    void			workerThread(ef::Network	network);
    void			manageSplitTask(ef::Network	&network,
						s_splitOrder    *order);
    void			manageJoinTask(ef::Network	&network,
					       s_joinOrder	*order);
    void			syncNetwork(ef::Network		&network,
					    s_joinOrder		*order);
  };
}

#endif	//		__EF_NETWORK_CLONER_HH__
