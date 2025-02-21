// ************************************************
// 16/01/2025 14:03:46
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include				"learnSubjects.hh"

std::vector<ef::s_learnSubjects>	ef::getExam(int	idExam)
{
  if (idExam == EXAM_MORPION)
    {
      std::vector<ef::s_learnSubjects>	exam = {
	{ {10, 10, 10,
	    10, 5, 10,
	    15, 15, 5},
	  {0, 0,
	   0, 0} },
	{ {15, 10, 15,
	    5, 10, 10,
	    5, 10, 10},
	  {0, 1,
	   0, 0} },
	{ {5, 10, 10,
	    10, 15, 5,
	    15, 10, 10},
	  {1, 0,
	   0, 0} },
	{ {10, 10, 5,
	    10, 15, 15,
	    15, 10, 5},
	  {0, 0,
	   0, 1} },
	{ {15, 10, 15,
	    5, 10, 5,
	    10, 10, 10},
	  {0, 1,
	   0, 1} },
	{ {10, 10, 15,
	    10, 5, 10,
	    5, 10, 15},
	  {1, 0,
	   0, 1} },
	{ {10, 15, 10,
	    10, 15, 15,
	    10, 5, 5},
	  {0, 0,
	   1, 0} },
	{ {5, 15, 5,
	    10, 15, 10,
	    15, 10, 10},
	  {0, 1,
	   1, 0} },
	{ {5, 10, 15,
	    10, 5, 15,
	    10, 10, 10},
	  {1, 0,
	   1, 0} },
	{ {15, 10, 10,
	    10, 5, 15,
	    5, 10, 10},
	  {1, 0,
	   0, 0} }
      };
      return (exam);
    }
  else if (idExam == EXAM_AND)
    {
      std::vector<ef::s_learnSubjects>	exam = {
	{ {1, 1}, {1} },
	{ {1, 0}, {0} },
	{ {0, 1}, {0} },
	{ {0, 0}, {0} }
      };
      return (exam);
    }
  else if (idExam == EXAM_OR)
    {
      std::vector<ef::s_learnSubjects> exam = {
	{ {1, 1}, {1} },
	{ {1, 0}, {1} },
	{ {0, 1}, {1} },
	{ {0, 0}, {0} }
      };
      return (exam);
    }
  else if (idExam == EXAM_XOR)
    {
      std::vector<ef::s_learnSubjects>	exam = {
	{ {1, 1}, {0} },
	{ {1, 0}, {1} },
	{ {0, 1}, {1} },
	{ {0, 0}, {0} }
      };
      return (exam);
    }
  else
    {
      std::vector<ef::s_learnSubjects> empty;

      return (empty);
    }
}
