// ************************************************
// 06/02/2025 15:31:09
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef			__EF_ORDER_HH__

#define			__EF_ORDER_HH__

#include		"learnSubjects.hh"

#include		<memory>

namespace		ef
{
   enum				e_orderType
    {
      TEST_COEF = 0,
      TRAIN_SUBJECT,
      SYNC_LINK,
      SYNC_NETWORK, // Ne synchronise pas les liens !!
      SEND_NETWORK,
      COMPARE_NETWORK
    };

  struct			s_testCoef
  {
    int				nLayer;
    int				nNeuron;
    int				nLink;
    double			modCoef;
    std::vector<s_learnSubjects>	*subjects;
    double			newScore;
    char			isReverse;
  };

  struct			s_splitOrder
  {
    e_orderType			type;
    union
    {
      s_testCoef		testCoef;
      s_learnSubjects		*subject;
    };
  };

  struct			s_syncLink
  {
    int				nLayer;
    int				nNeuron;
    int				nLink;
    double			modCoef;
    bool			reverse;
  };

  class				Network;
  class				Neuron;

  struct			s_compareNetwork
  {
    ef::Network			*network;
    bool			isEqual;
  };

  struct			s_joinOrder
  {
    e_orderType			type;
    union
    {
      s_syncLink		syncLink;
      std::vector<std::vector<std::shared_ptr<Neuron>>>	*neurons;
      s_compareNetwork		compareNetwork;
    };
  };
}

#endif	//		__EF_ORDER_HH__
