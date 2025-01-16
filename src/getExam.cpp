// ************************************************
// 16/01/2025 14:03:46
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include				"learnSubjects.hh"

std::vector<ef::s_learnSubjects>	ef::getExam(int	idExam)
{
  if (idExam == 0)
    {
      std::vector<ef::s_learnSubjects>	exam = {
	{ {10, 10, 10,
	    10, 10, 10,
	    10, 10, 10}, {1, 1} },
	{ {15, 10, 15,
	    5, 10, 10,
	    5, 10, 10}, {1, 0} },
	{ {15, 10, 10,
	    10, 5, 15,
	    5, 10, 10}, {2, 0} },
	{ {5, 15, 5,
	    10, 15, 10,
	    15, 10, 10}, {1, 2} },
	{ {15, 10, 15,
	    5, 10, 5,
	    10, 10, 10}, {1, 1} },
	{ {5, 10, 10,
	    10, 15, 5,
	    15, 10, 10}, {2, 0} }	
      };

      return (exam);
    }
  else
    {
      std::vector<ef::s_learnSubjects> empty;

      return (empty);
    }
}
