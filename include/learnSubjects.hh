// ************************************************
// 16/01/2025 14:00:33
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef				__EF_LEARN_SUBJECT_HH__

#define				__EF_LEARN_SUBJECT_HH__

# include			<vector>

namespace			ef
{
  struct				s_learnSubjects
  {
    std::vector<double>			inputValues;
    std::vector<double>			expectedResults;
  };

  std::vector<s_learnSubjects>		getExam(int	idExam);
}

#endif	//			__EF_LEARN_SUBJECT_HH__
