// ************************************************
// 23/01/2025 15:51:18
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"neuron.hh"

void		ef::Neuron::linkNewNeuron(std::shared_ptr<Neuron>	&neuron)
{
  s_input	newInput;

  newInput.neuron = neuron;
  newInput.coef = ((double)(rand() % 1000) / 1000) + 1;
  inputs.push_back(newInput);
}
