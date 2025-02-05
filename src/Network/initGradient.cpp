// ************************************************
// 25/01/2025 07:55:39
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"network.hh"

void		ef::Network::initGradient(bool		onlyReset)
{
  size_t	nLayer;
  size_t	nNeuron;
  size_t	nLink;

  if (!onlyReset || gradient.size() != (neurons.size() - 1))
    {
      gradient.clear();
      for (nLayer = 0; nLayer < neurons.size(); nLayer += 1)
	gradient.emplace_back();
    }  
  for (nLayer = neurons.size() - 1; nLayer > INPUT_LAYER; nLayer -= 1)
    {
      for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
	{
	  if (!onlyReset || gradient[nLayer].size() == nNeuron)
	    gradient[nLayer].emplace_back();
	  for (nLink = 0; nLink < neurons[nLayer - 1].size(); nLink += 1)
	    {
	      if (onlyReset && gradient[nLayer][nNeuron].size() > nLink)
		gradient[nLayer][nNeuron][nLink] = 0;
	      else
		gradient[nLayer][nNeuron].emplace_back(0);
	    }
	}
    }
}
