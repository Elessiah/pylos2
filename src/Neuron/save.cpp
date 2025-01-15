// ************************************************
// 10/01/2025 10:51:38
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"
#include		<iostream>
#include		<stdexcept>

void			ef::Neuron::save(std::ofstream	&file) const
{
  if (writeHeader(file) == false)
    throw std::runtime_error("Save of header has failed !");
  if (writeNeuronContent(file) == false)
    throw std::runtime_error("Save of content has failed !");
}
