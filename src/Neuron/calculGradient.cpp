// ************************************************
// 25/01/2025 08:32:17
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"neuron.hh"

void		ef::Neuron::calculGradient(std::vector<double>				&gradient,
					   double					expectedResult,
					   size_t					compteur,
					   bool					        isOutputLayer)
{
  size_t	nLink;
  double	result;
  double	baseResult;

  if (isOutputLayer)
    baseResult = (outputValue - expectedResult) * (outputValue * (1 - outputValue));
  else
    baseResult = outputValue * (outputValue * (1 - outputValue));
  for (nLink = 0; nLink < inputs.size(); nLink += 1)
    {
      result = baseResult * (inputs[nLink].neuron->getOutput());
      if (compteur == 0)
	gradient[nLink] = result;
      else
	gradient[nLink] += (result - gradient[nLink]) / compteur;
    }
}
