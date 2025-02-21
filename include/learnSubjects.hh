// ************************************************
// 16/01/2025 14:00:33
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef				__EF_LEARN_SUBJECT_HH__

#define				__EF_LEARN_SUBJECT_HH__

# include			<vector>
# include			<string>

# define	EXAM_MORPION	0
# define        EXAM_AND	1
# define	EXAM_OR		2
# define        EXAM_XOR	3
# define	EXAM_NAND	4
# define	EXAM_ADD2BIT	5

namespace			ef
{
  struct				s_learnSubjects
  {
    std::vector<double>			inputValues;
    std::vector<double>			expectedResults;
  };

  std::vector<s_learnSubjects>		getExam(int		idExam);
  int					getExamId(std::string	examName);
}

#endif	//			__EF_LEARN_SUBJECT_HH__
