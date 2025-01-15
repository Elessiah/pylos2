// ************************************************
// 10/01/2025 11:10:44
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"

bool			ef::Neuron::writeNeuronContent(std::ofstream	&file) const
{
  size_t		i;

  for (i = 0; i < inputs.size(); i += 1)
    {
      file.write((char *)&inputs[i].coef, sizeof(double));
      if (!file.good())
	return (false);
    }
  return (true);
}
