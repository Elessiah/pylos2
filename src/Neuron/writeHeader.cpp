// ************************************************
// 10/01/2025 11:03:30
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"

bool			ef::Neuron::writeHeader(std::ofstream	&file) const
{
  file.write((char *)&isReady, sizeof(isReady));
  if (!file.good())
    return (false);
  file.write((char *)&isReverse, sizeof(isReverse));
  if (!file.good())
    return (false);
  return (true);
}
