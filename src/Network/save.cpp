// ************************************************
// 10/01/2025 15:25:18
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"network.hh"

void		ef::Network::save(std::ofstream	&file) const
{
  uint32_t	nbLayer;
  uint32_t	nbNeuron;
  uint32_t	nLayer;
  uint32_t	nNeuron;

  nbLayer = static_cast<uint32_t>(neurons.size());
  file.write((char *)&nbLayer, sizeof(nbLayer));
  if (!file.good())
    throw std::runtime_error("Save of nbLayer has failed !");
  for (nLayer = 0; nLayer < nbLayer; nLayer += 1)
    {
      nbNeuron = neurons[nLayer].size();
      file.write((char *)&nbNeuron, sizeof(nbNeuron));
      if (!file.good())
	throw std::runtime_error("Save of nbNeuron has failed !");
      for (nNeuron = 0; nNeuron < nbNeuron; nNeuron += 1)
	neurons[nLayer][nNeuron]->save(file);
    }
  
}
