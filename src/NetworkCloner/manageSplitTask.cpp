// ************************************************
// 06/02/2025 15:22:21
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"networkCloner.hh"
#include	"network.hh"

void		ef::NetworkCloner::manageSplitTask(ef::Network				&network,
						   s_splitOrder				*order)
{
  if (order->type == TEST_COEF)
    network.testNewCoef(network, order->testCoef);
  else if (order->type == TRAIN_SUBJECT)
    {
      std::vector<s_learnSubjects>	subjects;

      subjects.push_back(*order->subject);
      network.learning(0, subjects);
    }
}
