// ************************************************
// 15/01/2025 16:45:15
// Keryan HOUSSIN 
// Pylos2
// See 'note' for more informations
// ************************************************

#include		"network.hh"
#include		<iostream>

double			ef::Network::primaryLearning(std::vector<s_learnSubjects>	&subjects)
{
  double		currentScore;
  size_t		nLayer;
  size_t		nNeuron;
  size_t		nLink;
  size_t		passedLinks;

  currentScore = examen(subjects);
  std::cout << "Starting Score is : " << currentScore << std::endl;
  passedLinks = 0;
  for (nLayer = 1; nLayer < neurons.size(); nLayer += 1)
    {
      for (nNeuron = 0; nNeuron < neurons[nLayer].size(); nNeuron += 1)
	{
	  for (nLink = 0; nLink < neurons[nLayer - 1].size(); nLink += 1)
	    {
	      if (currentScore > 10 || currentScore < -10)
		{
		  double	tryScore;
 
		  neurons[nLayer][nNeuron].tryNewCoef(nLink, 0.5);
		  tryScore = examen(subjects);
		  if ((currentScore < 0 && tryScore < currentScore)
		      || (currentScore > 0 && tryScore > currentScore))
		    {
		      neurons[nLayer][nNeuron].back();
		    }
		  else
		    currentScore = tryScore;
		}
	      passedLinks += 1;
	    }
	  std::cout << "Progression : " << passedLinks * 100 / nbLinks << "% ("
		    << passedLinks << " / " << nbLinks << ")" << std::endl;
	}
    }
  std::cout << "Final Score : " << currentScore << std::endl;
  return (currentScore);
}
