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
  
  for (; network.neurons.size() < (*order->neurons).size(); network.neurons.emplace_back());
  for (; network.neurons.size() > (*order->neurons).size(); network.neurons.pop_back());
  for (nLayer = 0; nLayer < (*order->neurons).size(); nLayer += 1)
    {
      if (network.neurons[nLayer].size() != (*order->neurons)[nLayer].size())
	{	  
	  nNeuron = network.neurons[nLayer].size();
	  network.addNeurons((*order->neurons)[nLayer].size() - nNeuron, nLayer);
	  if (nLayer == 0)
	    {
	      std::vector<std::shared_ptr<Neuron>>	empty;

	      for (nNeuron = 0; nNeuron < network.neurons[nLayer].size(); nNeuron += 1)
		network.neurons[nLayer][nNeuron]->syncWithNetwork((*order->neurons)[nLayer][nNeuron], empty);
	    }
	  else
	    {
	      for (nNeuron = 0; nNeuron < network.neurons[nLayer].size(); nNeuron += 1)
		network.neurons[nLayer][nNeuron]->syncWithNetwork((*order->neurons)[nLayer][nNeuron], network.neurons[nLayer - 1]);
	    }
	  if ((nLayer + 1) < network.neurons.size())
	    {
	      size_t	nextLayer;
		  
	      nextLayer = nLayer + 1;
	      for (nNeuron = 0; nNeuron < network.neurons[nextLayer].size(); nNeuron += 1)
		network.neurons[nextLayer][nNeuron]->syncWithNetwork((*order->neurons)[nextLayer][nNeuron], network.neurons[nLayer - 1]);
	    }
	}
      if (nLayer > 0)
	{
	  for (nNeuron = 0; nNeuron < network.neurons[nLayer].size(); nNeuron += 1)
	    {
	      if (*(network.neurons[nLayer][nNeuron]) != *((*order->neurons)[nLayer][nNeuron]))
		network.neurons[nLayer][nNeuron]->syncWithNetwork((*order->neurons)[nLayer][nNeuron], network.neurons[nLayer - 1]);
	      if (*(network.neurons[nLayer][nNeuron]) != *((*order->neurons)[nLayer][nNeuron]))
		std::cout << "Ça marche pas !" << std::endl;
	    }
	}
    }
  // Debug !
  size_t		nLink;

  for (nLayer = 0; nLayer < network.neurons.size(); nLayer += 1)
    {
      if (network.neurons[nLayer].size() != (*order->neurons)[nLayer].size())
	std::cout << "Tailles de couches " << nLayer << " différentes" << std::endl;
      for (nNeuron = 0; nNeuron < network.neurons[nLayer].size(); nNeuron += 1)
	{
	  if (network.neurons[nLayer][nNeuron]->inputs.size() != (*order->neurons)[nLayer][nNeuron]->inputs.size())
	    std::cout << "Nombres d'inputs différents :\n\t-nLayer: " << nLayer << "\n\t- nNeuron: " << nNeuron << std::endl;
	  for (nLink = 0; nLink < network.neurons[nLayer][nNeuron]->inputs.size(); nLink += 1)
	    {
	      if (network.neurons[nLayer][nNeuron]->inputs[nLink].coef != (*order->neurons)[nLayer][nNeuron]->inputs[nLink].coef)
		std::cout << "Coefs différents !\n\t- nLayer: " << nLayer << "\n\t- nNeuron: " << nNeuron << "\n\t- nLink: " << nLink << std::endl;
	    }
	}
    }
}
