// ************************************************
// 10/01/2025 16:17:54
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"network.hh"

void		ef::Network::load(std::ifstream	&file)
{
  uint32_t	nbLayer;
  uint32_t	nbNeuron;
  uint32_t	nLayer;
  uint32_t	nNeuron;

  file.read((char *)&nbLayer, sizeof(nbLayer));
  if (!file.good())
    throw std::runtime_error("Load of nbLayer has failed !");
  for (nLayer = 0; nLayer < nbLayer; nLayer += 1)
    {
      neurons.emplace_back();
      file.read((char *)&nbNeuron, sizeof(nbNeuron));
      if (!file.good())
	throw std::runtime_error("Load of nbNeuron has failed !");
      for (nNeuron = 0; nNeuron < nbNeuron; nNeuron += 1)
	{
	  if (nLayer == 0)
	    {
	      std::vector<std::shared_ptr<Neuron>>	emptyVector;	  
	      neurons[nLayer].emplace_back(std::make_shared<Neuron>(file, emptyVector));
	    }
	  else
	    neurons[nLayer].emplace_back(std::make_shared<Neuron>(file, neurons[nLayer - 1]));
	}
    }
}
