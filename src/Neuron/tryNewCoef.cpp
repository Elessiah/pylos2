// ************************************************
// 16/01/2025 15:36:53
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"neuron.hh"

void			ef::Neuron::tryNewCoef(int		nLink,
					       double		coefEdit)
{
  lastCoef = inputs[nLink].coef;
  lastEditInput = nLink;
  inputs[nLink].coef *= coefEdit;
}
