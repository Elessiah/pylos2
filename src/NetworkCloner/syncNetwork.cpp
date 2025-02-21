// ************************************************
// 12/02/2025 16:00:16
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::NetworkCloner::syncNetwork(ef::Network	&network,
						       s_joinOrder	*order)
{
  size_t		nLayer;
  size_t		nNeuron;

  // Assure que les deux réseaux ont le même nombres de couches
  for (; network.neurons.size() < (*order->neurons).size(); network.neurons.emplace_back());
  for (; network.neurons.size() > (*order->neurons).size(); network.neurons.pop_back());
  for (nLayer = 0; nLayer < (*order->neurons).size(); nLayer += 1)
    {
      // Assure que les deux réseaux ont le même nombres de neurones par couches
      while (network.neurons[nLayer].size() < (*order->neurons)[nLayer].size())
	{
	  if (nLayer == 0)
	    {
	      std::vector<std::shared_ptr<Neuron>>	empty;
	      
	      network.neurons[nLayer].emplace_back(std::make_shared<Neuron>());
	    }
	  else
	    network.neurons[nLayer].emplace_back(std::make_shared<Neuron>(network.neurons[nLayer - 1]));
	}
      while (network.neurons[nLayer].size() > (*order->neurons)[nLayer].size())
	network.neurons[nLayer].pop_back();
      // Assure que les deux réseaux ont les mêmes liens par neurones
      for (nNeuron = 0; nNeuron < network.neurons[nLayer].size(); nNeuron += 1)
	{
	  if (network.neurons[nLayer][nNeuron] != (*order->neurons)[nLayer][nNeuron])
	    {
	      if (nLayer == 0)
		{
		  std::vector<std::shared_ptr<Neuron>>	empty;
		  
		  network.neurons[nLayer][nNeuron]->syncWithNetwork((*order->neurons)[nLayer][nNeuron], empty);
		}
	      else
		network.neurons[nLayer][nNeuron]->syncWithNetwork((*order->neurons)[nLayer][nNeuron], network.neurons[nLayer - 1]);
	    }	    
	}
    }
}
