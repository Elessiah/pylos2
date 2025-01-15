// ************************************************
// 15/01/2025 15:22:33
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"neuron.hh"

bool		ef::Neuron::verify(std::vector<Neuron>	&prevLayer)
{
  if (prevLayer.size() != inputs.size())
    return (false);
  size_t	nNeuron;

  for (nNeuron = 0; nNeuron < prevLayer.size(); nNeuron += 1)
    {
      if (&prevLayer[nNeuron] != inputs[nNeuron].neuron)
	return (false);
    }
  return (true);
}
