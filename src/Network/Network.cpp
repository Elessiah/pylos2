// ************************************************
// 10/01/2025 11:41:44
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

ef::Network::Network(std::vector<int>		&build)
{
  size_t		i;
  int			nNeuron;

  for (i = 0; i < build.size(); i += 1)
    {
      neurons.emplace_back();
      for (nNeuron = 0; nNeuron < build[i]; nNeuron += 1)
	{
	  if (i == 0)
	    neurons[i].emplace_back();
	  else
	    neurons[i].emplace_back(neurons[i - 1]);
	}
    }
}

ef::Network::Network(std::ifstream		&file)
{
  load(file);
}

ef::Network::Network(const Network		&other)
{
  *this = other;
}

ef::Network		&ef::Network::operator=(const Network	&other)
{
  size_t		nLayer;
  size_t		nNeuron;

  for (nLayer = 0; nLayer < other.neurons.size(); nLayer += 1)
    {
      neurons.emplace_back();
      for (nNeuron = 0; nNeuron < other.neurons.size(); nNeuron += 1)
	neurons[nLayer].emplace_back(other.neurons[nLayer][nNeuron]);
    }
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
	  if (neurons[nLayer][nNeuron] != other.neurons[nLayer][nNeuron])
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
