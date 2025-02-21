// ************************************************
// 10/01/2025 15:06:41
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include			"network.hh"
#include			"morpion.hh"
#include			"utils.hh"

#define		HUMAN		0
#define		BOT		1

#include			<iostream>
#include			<cstring>

int				main(int		ac,
				     char		**av)
{
  if (ac == 1 || strcmp(av[1], "new") == 0)
    {
      std::string		filename;
      int			examId;
      if (ac > 3)
	{
	  filename = av[2];
	  examId = ef::getExamId(av[3]);
	  if (examId == -1)
	    {
	      std::cerr << "Unknown exam, please try again or look learnSubjects.hh" << std::endl;
	      return (-1);
	    }
	}
      else
	filename = "output.bin";
      std::vector<ef::s_learnSubjects>	subjects = ef::getExam(examId);
      std::vector<int>		build = { (int)subjects[0].inputValues.size(), (int)subjects[0].expectedResults.size() };
      ef::Network		network(build);
      std::ofstream		saveFile(filename, std::ios::binary);

      network.learning(0, examId);
      network.save(saveFile);
      saveFile.close();
    }
  else
    {
      std::string		filename;
      int			examId;

      if (ac > 2)
	{
	  filename = av[1];
	  examId = ef::getExamId(av[2]);
	  if (examId == -1)
	    {
	      std::cerr << "Unknown exam, please try again or look learnSubjects.hh" << std::endl;
	      return (-1);
	    }
	}
      else
	{
	  std::cerr << "Wrong format :\n\t- To create new set : ./network new [optional filename output] [exam name]\n\t- To load set : ./network [filename output] [exam name]" << std::endl;
	  return (-1);
	}
      std::ifstream		loadFile(filename, std::ios::binary);
      ef::Network		network(loadFile);
      std::vector<ef:: s_learnSubjects>	subjects = ef::getExam(examId);
      std::vector<double>	result;
      size_t			i;
      size_t			iVector;

      loadFile.close();
      std::cout << "Score of this network : " << network.examen(subjects) << std::endl;
      for (i = 0; i < subjects.size(); i += 1)
	{
	  std::cout << "Injecting inputs : ";
	  for (iVector = 0; iVector < subjects[i].inputValues.size(); iVector += 1)
	    {
	      std::cout << subjects[i].inputValues[iVector];
	      if (iVector == (subjects[i].inputValues.size() - 1))
		std::cout << std::endl;
	      else
		std::cout << ", ";
	    }
	  result = network.getOutput(subjects[i].inputValues);
	  for (iVector = 0; iVector < result.size(); iVector += 1)
	    std::cout << "Output n°" << iVector << " : Network result is " << result[iVector] << " and " << subjects[i].expectedResults[iVector] << " was expected." << std::endl;
	}
    }
  //  network.retropropagation(EXAM_AND, 0.001);
  return (0);
}
