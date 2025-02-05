// ************************************************
// 23/01/2025 14:59:40
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"network.hh"
#include	"utils.hh"

#include	<iostream>

double		ef::Network::learning(double		targetScore,
				      int		idExam)
{
  std::vector<ef::s_learnSubjects>	exam = ef::getExam(idExam);
  double	lastScore;
  double	currentScore;
  int		nbPassage;
  bool		reachEnd;

  lastScore = 0;
  nbPassage = 1;
  reachEnd = false;
  currentScore = primaryLearning(exam);
  while (ef::dbAbs(currentScore) > targetScore && reachEnd == false)
    {
      lastScore = currentScore;
      currentScore = primaryLearning(exam);
      nbPassage += 1;
      if (lastScore == currentScore)
	{
	  if (!isFullSize())
	    {
	      std::cout << "\nNombre d'entraînements : " << nbPassage << std::endl;
	      std::cout << "Ajout de " << addNeuron() << " neurones !" << std::endl;
	      textDisplay();
	    }
	  else
	    reachEnd = true;
	}
    }
  std::cout << "Nombre d'entraînements : " << nbPassage << std::endl;
  if (reachEnd)
    std::cout << "Limite de l'entraînement atteinte." << std::endl;
  textDisplay();
  return (currentScore);
}
