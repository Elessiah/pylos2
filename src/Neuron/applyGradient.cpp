// ************************************************
// 25/01/2025 09:47:56
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"neuron.hh"

void		ef::Neuron::applyGradient(std::vector<double>	&gradient,
					  double		speed)
{
  size_t	nLink;

  for (nLink = 0; nLink < inputs.size(); nLink += 1)
    inputs[nLink].coef = inputs[nLink].coef - speed * gradient[nLink];
}
