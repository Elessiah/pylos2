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
      if (ac > 2)
	filename = av[2];
      else
	filename = "output.bin";
      std::vector<int>		build = { 2, 1 };
      ef::Network			network(build);
      std::ofstream			saveFile(filename, std::ios::binary);

      network.learning(0.1, EXAM_XOR);
      network.save(saveFile);
      saveFile.close();
    }
  else
    {
      std::string		filename;

      if (ac > 1)
	filename = av[1];
      else
	{
	  std::cerr << "Wrong format :\n\t- To create new set : ./main new [optional filename output]\n\t- To load set : ./main [filename output]" << std::endl;
	  return (-1);
	}
      std::ifstream		loadFile(filename, std::ios::binary);
      ef::Network		network(loadFile);
      std::vector<ef:: s_learnSubjects>	subjects = ef::getExam(EXAM_XOR);
      std::vector<double>	result;
      size_t			i;
      size_t			iVector;
      
      loadFile.close();
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
