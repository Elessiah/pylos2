// ************************************************
// 10/01/2025 11:22:21
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"

bool			ef::Neuron::readNeuronContent(std::ifstream		&file,
						      std::vector<Neuron>	&neuronInputs)
{
  size_t		i;
  s_input		new_input;

  for (i = 0; i < neuronInputs.size(); i += 1)
    {
      file.read((char *)&new_input.coef, sizeof(double));
      if (!file.good())
	return (false);
      new_input.neuron = &neuronInputs[i];
      inputs.push_back(new_input);
    }
  return (true);
}
