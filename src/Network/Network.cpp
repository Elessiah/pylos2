// ************************************************
// 10/01/2025 11:41:44
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"
#include		<ctime>

ef::Network::Network(std::vector<int>		&build)
  : networkError(0)
{
  size_t		i;
  int			nNeuron;

  srand(static_cast<unsigned>(std::time(0)));
  for (i = 0; i < build.size(); i += 1)
    {
      neurons.emplace_back();
      for (nNeuron = 0; nNeuron < build[i]; nNeuron += 1)
	{
	  if (i == 0)
	    neurons[i].emplace_back(std::make_shared<Neuron>(threadPool));
	  else
	    neurons[i].emplace_back(std::make_shared<Neuron>(neurons[i - 1], threadPool));
	}
    }
  initGradient(false);
  nbLinks = getNbLinks();
}

ef::Network::Network(std::ifstream		&file)
  : networkError(0)
{
  srand(static_cast<unsigned>(std::time(0)));
  load(file);
  initGradient(false);
  nbLinks = getNbLinks();
}

ef::Network::Network(const Network		&other)
  : neurons(other.neurons)
  , nbLinks(other.nbLinks)
  , networkError(0)
{
  initGradient(false);
  srand(static_cast<unsigned>(std::time(0)));
}

ef::Network		&ef::Network::operator=(const Network	&other)
{
  size_t		nLayer;
  size_t		nNeuron;
  std::vector<std::shared_ptr<Neuron>>	emptyLayer;

  neurons.clear();
  networkError = 0;
  nbLinks = other.nbLinks;
  for (nLayer = 0; nLayer < other.neurons.size(); nLayer += 1)
    {
      neurons.emplace_back();
      for (nNeuron = 0; nNeuron < other.neurons[nLayer].size(); nNeuron += 1)
	{
	  if (nLayer == 0)
	    neurons[nLayer].emplace_back(std::make_shared<Neuron>(other.neurons[nLayer][nNeuron], emptyLayer, threadPool));
	  else
	    neurons[nLayer].emplace_back(std::make_shared<Neuron>(other.neurons[nLayer][nNeuron], neurons[nLayer - 1], threadPool));
	}
    }
  initGradient(false);
  return (*this);
}

bool			ef::Network::operator==(const Network	&other) const
{
  if (neurons.size() != other.neurons.size())
    return (false);
  size_t		nLayer;
  size_t		nNeuron;

  for (nLayer = 0; nLayer < neurons.size(); nLayer += 1)
    {
      if (neurons[nLayer].size() != other.neurons[nLayer].size())
	return (false);
      for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
	{
	  if (*neurons[nLayer][nNeuron] != *other.neurons[nLayer][nNeuron])
	    return (false);
	}
    }
  return (true);
}

bool			ef::Network::operator!=(const Network	&other) const
{
  return(!(*this == other));
}

ef::Network::~Network()
{

}
