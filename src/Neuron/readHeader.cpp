// ************************************************
// 10/01/2025 11:16:55
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"

bool			ef::Neuron::readHeader(std::ifstream	&file)
{
  file.read((char *)&isReady, sizeof(isReady));
  if (!file.good())
    return (false);
  file.read((char *)&isReverse, sizeof(isReverse));
  if (!file.good())
    return (false);
  return (true);
}
