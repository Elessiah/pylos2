// ************************************************
// 12/02/2025 15:25:22
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"neuron.hh"

void		ef::Neuron::syncWithNetwork(std::shared_ptr<Neuron>			&neuron,
					    std::vector<std::shared_ptr<Neuron>>	&prevLayer)
{
  size_t	nCoef;

  isReverse = neuron->isReverse;
  for (nCoef = 0; nCoef < inputs.size(); nCoef += 1)
    inputs[nCoef].coef = neuron->inputs[nCoef].coef;
  for (; nCoef < neuron->inputs.size(); nCoef += 1)
    inputs.emplace_back(s_input{ prevLayer[nCoef], neuron->inputs[nCoef].coef });
}
