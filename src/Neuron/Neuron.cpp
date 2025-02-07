// ************************************************
// 10/01/2025 10:28:06
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	<iostream>
#include	<stdexcept>

#include	"neuron.hh"

ef::Neuron::Neuron()
  : isReady(false)
  , isReverse(rand() % 2)
  , outputValue(0)
  , inputValue(0)
{
}

ef::Neuron::Neuron(std::vector<std::shared_ptr<Neuron>>			&neuronInputs)
  : isReady(false)
  , isReverse(rand() % 2)
  , outputValue(0)
{
  s_input	input;
  size_t	i;

  for (i = 0; i < neuronInputs.size(); i += 1)
    {
      input.coef = ((double)(rand() % 1000) / 1000) + 1;
      input.neuron = neuronInputs[i];
      inputs.push_back(input);
    }
}

ef::Neuron::Neuron(std::ifstream					&file,
		   std::vector<std::shared_ptr<Neuron>>			&neuronInputs)
  : isReady(false)
{
  load(file, neuronInputs);
}

ef::Neuron::Neuron(const std::shared_ptr<Neuron>			&other)
  : isReady(false)
  , isReverse(other->isReverse)
  , outputValue(0)
  , inputValue(other->inputValue)
  , inputs(other->inputs)
{
}

ef::Neuron::Neuron(const std::shared_ptr<Neuron>			&other,
		   std::vector<std::shared_ptr<Neuron>>			&prevLayer)
  : isReady(false)
  , isReverse(other->isReverse)
  , outputValue(0)
  , inputValue(other->inputValue)
{
  if (prevLayer.size() != other->inputs.size())
    throw std::runtime_error("Neuron inputs size different from other inputs size");
  size_t	i;

  for (i = 0; i < other->inputs.size(); i++)
    inputs.emplace_back(s_input{ prevLayer[i], other->inputs[i].coef });
}


ef::Neuron	&ef::Neuron::operator=(const Neuron			&other)
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

bool		ef::Neuron::operator==(const Neuron			&other) const
{
  if (isReverse != other.isReverse)
    return (false);
  if (inputs.size() != other.inputs.size())
    return (false);
  if (inputs.size() == 0)
    return (true);
  size_t	i;

  for (i = 0; i < inputs.size(); i += 1)
    {
      if (inputs[i].coef != other.inputs[i].coef)
	return (false);
      //      std::cout << inputs[i].coef << " == " << other.inputs[i].coef << std::endl;
    }
  return (true);
}

bool		ef::Neuron::operator!=(const Neuron			&other) const
{
  return (!(*this == other));
}

ef::Neuron::~Neuron()
{
}
