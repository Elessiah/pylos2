// ************************************************
// 15/01/2025 14:53:58
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include				"network.hh"

bool					ef::Network::verify()
{
  std::vector<std::shared_ptr<Neuron>>	empty;
  size_t				nLayer;
  size_t				nNeuron;

  for (nLayer = 0; nLayer < neurons.size(); nLayer += 1)
    {
      for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
	{
	  if (nLayer == 0)
	    {
	      if (neurons[nLayer][nNeuron]->verify(empty) == false)
		return (false);
	    }
	  else
	    {
	      if (neurons[nLayer][nNeuron]->verify(neurons[nLayer - 1]) == false)
		return (false);
	    }
	}
    }
  return (true);
}
