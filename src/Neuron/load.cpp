// ************************************************
// 10/01/2025 11:14:52
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"

void			ef::Neuron::load(std::ifstream				&file,
					 std::vector<std::shared_ptr<Neuron>>	&neuronInputs)
{
  if (readHeader(file) == false)
    throw std::runtime_error("Load of header has failed !");
  if (readNeuronContent(file, neuronInputs) == false)
    throw std::runtime_error("Load of neuron content has failed !");
}
