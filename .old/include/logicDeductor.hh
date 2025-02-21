// ************************************************
// 21/02/2025 11:31:56
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef		__EF_LOGIC_DEDUCTOR_HH__

# define	__EF_LOGIC_DEDUCTOR_HH__

# define	INPUT	0
# define	AND	1
# define	OR	2
# define	XOR	3
# define	NAND	4
# define	BUFFER	5
# define	REVERSE	6

# include	"learnSubjects.hh"

# include	<memory>

namespace	ef
{
  struct	s_logicDoor
  {
    int		doorName;
    double	inputValue;
    std::shared_ptr<s_logicDoor>	input[2];
  };

  class		LogicDeductor
  {
  public:
    LogicDeductor();
    LogicDeductor(std::vector<s_learnSubjects>	&subjects);
    ~LogicDeductor();

    void	load(std::vector<s_learnSubjects>		&subjects);
  private:
    bool	isLoad;
    std::vector<std::vector<s_logicDoor>>	logicNetwork;

    void	manageOutput(std::vector<s_learnSubjects>		&subjects,
			     int					indexOutput);
    void	extractInputs(std::vector<s_learnSubjects>		&subjects,
			      int					indexOutput,
			      std::vector<std::vector<double>>		&on,
			      std::vector<std::vector<double>>		&off);
    void	extractConditions(std::vector<std::vector<double>>	&on,
				  std::vector<std::vector<double>>	&off,
				  std::vector<s_logicDoor>		&conditions);
    void	formatConditions(std::vector<s_logicDoor>		&conditions);
  };
}

#endif	//	__EF_LOGIC_DEDUCTOR_HH__

