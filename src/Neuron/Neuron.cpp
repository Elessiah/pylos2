// ************************************************
// 10/01/2025 10:28:06
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"neuron.hh"

ef::Neuron::Neuron()
  : isReady(false),
    isReverse(rand() % 2),
    outputValue(0),
    inputValue(0)
{
}

ef::Neuron::Neuron(std::vector<Neuron>			&neuronInputs)
  : isReady(false),
    isReverse(rand() % 2),
    outputValue(0)
{
  s_input	input;
  size_t	i;

  input.coef = ((double)(rand() % 1000) / 100) + 1;
  for (i = 0; i < neuronInputs.size(); i += 1)
    {
      input.neuron = &neuronInputs[i];
      inputs.push_back(input);
    }
}

ef::Neuron::Neuron(std::ifstream			&file,
		   std::vector<Neuron>			&neuronInputs)
  : isReady(false)
{
  load(file, neuronInputs);
}

ef::Neuron::Neuron(const Neuron				&other)
 : isReady(false)
  , isReverse(other.isReverse)
  , outputValue(0)
  , inputValue(other.inputValue)
  , inputs(other.inputs)
{
}

ef::Neuron	&ef::Neuron::operator=(const Neuron	&other)
{
  if (this != &other)
    {
      isReady = false;
      isReverse = other.isReverse;
      outputValue = 0;
      inputValue = other.inputValue;
      inputs = other.inputs;
    }
  return (*this);
}

bool		ef::Neuron::operator==(const Neuron	&other) const
{
  if (isReverse != other.isReverse)
    return (false);
  if (inputs.size() == 0 && inputValue == other.inputValue)
    return (true);
  else if (inputs.size() == 0 || inputs.size() != other.inputs.size())
    return (false);
  size_t	i;

  for (i = 0; i < inputs.size(); i += 1)
    {
      if (inputs[i].coef != other.inputs[i].coef)
	return (false);
    }
  return (true);
}

bool		ef::Neuron::operator!=(const Neuron	&other) const
{
  return (!(*this == other));
}

ef::Neuron::~Neuron()
{
}
