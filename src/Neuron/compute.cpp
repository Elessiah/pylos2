// ************************************************
// 10/01/2025 10:39:58
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"

#include		<cmath>


void			ef::Neuron::compute()
{
  size_t		i;

  outputValue = 0;
  for (i = 0; i < inputs.size(); i += 1)
    outputValue += inputs[i].neuron->getOutput() * inputs[i].coef;
  if (isReverse)
    outputValue *= -1;
  outputValue = (1 / (1  + exp(outputValue)));
  isReady = true;
}
