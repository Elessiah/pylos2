// ************************************************
// 10/01/2025 15:06:41
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include			"network.hh"

static double			myAbs(double	value)
{
  if (value < 0)
    return (-value);
  return (value);
}

int				main(void)
{
  std::vector<int>		build = { 9, 6, 3, 2};
  ef::Network			network(build);
  std::vector<ef::s_learnSubjects>	exam = ef::getExam(0);

  while (myAbs(network.primaryLearning(exam)) > 10);
  return (0);
}
