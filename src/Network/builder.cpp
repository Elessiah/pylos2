// ************************************************
// 21/02/2025 10:26:47
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

void			ef::Network::builder(int				idExam)
{
  std::vector<s_learnSubjects>	subjects = ef::getExam(idExam);

  builder(subjects);
}

void			ef::Network::builder(std::vector<s_learnSubjects>	&subjects)
{
}
