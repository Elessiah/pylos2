// ************************************************
// 23/01/2025 14:59:40
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"network.hh"
#include	"utils.hh"

#include	<iostream>

double		ef::Network::learning(double				targetScore,
				      int				idExam)
{
  
  std::vector<ef::s_learnSubjects>	exam = ef::getExam(idExam);

  return (learning(targetScore, exam));
}

double		ef::Network::learning(double				targetScore,
				      std::vector<ef::s_learnSubjects>	&exam)
{
  double	lastScore;
  double	currentScore;
  int		nbPassage;
  bool		reachEnd;

  lastScore = 0;
  nbPassage = 1;
  reachEnd = false;
  currentScore = primaryLearning(exam);
  lastScore = currentScore;
  while (ef::dbAbs(currentScore) > targetScore && reachEnd == false)
    {
      currentScore = primaryLearning(exam);
      nbPassage += 1;
      if (lastScore == currentScore)
	{
	  if (!isFullSize())
	    {
	      std::cout << "\nTraining count : " << nbPassage << std::endl;
	      std::cout << "Adding " << addNeuron() << " neurons !" << std::endl;
	      textDisplay();
	    }
	  else
	    reachEnd = true;
	  lastScore = 0;
	}
      else
	lastScore = currentScore;
      
    }
  std::cout << "Training count : " << nbPassage << std::endl;
  if (reachEnd)
    std::cout << "Training limit has been reached !" << std::endl;
  textDisplay();
  return (currentScore);
}
