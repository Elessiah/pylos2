// ************************************************
// 22/01/2025 16:38:31
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"network.hh"

#include	<iostream>

double		ef::Network::retropropagation(int				idExam,
					      double				speed)
{
  std::vector<s_learnSubjects>	subjects = ef::getExam(idExam);
  size_t        i;

  calculRetropropagation(subjects);
  std::cout << "Start Error score : " << networkError << std::endl;
  i = 0;
  while (networkError > 0 && i < 100000)
    {
      applyRetropropagation(speed);
      calculRetropropagation(subjects);
      i += 1;
      //      std::cout << "New Error score : " << networkError << std::endl;
    }
  std::cout << "End training : " << networkError << std::endl;
  return (networkError);
}
