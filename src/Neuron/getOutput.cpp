// ************************************************
// 10/01/2025 10:36:25
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"

double			ef::Neuron::getOutput()
{
  if (isReady)
    return (outputValue);
  if (inputs.size() == 0)
    return (inputValue);
  compute();
  return (outputValue);
}
