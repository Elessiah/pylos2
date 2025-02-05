// ************************************************
// 17/01/2025 14:33:13
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef			__EF_IGAME_HH__

# define		__EF_IGAME_HH__

# include		<vector>
# include		"network.hh"

namespace		ef
{
  class			IGame
  {
  public:
    virtual ~IGame() = default;
    
    virtual void	start() = 0;
    virtual void	startGame(Network			*AI,
				  int				nbHuman) = 0;
    virtual bool	isRunning() = 0;
    virtual char	whosTurn() = 0;
    virtual void	getState(std::vector<double>		&state) = 0; // For AI, it's need to return the same "player" for both side
    virtual bool	play(std::vector<double>		&move) = 0;
    virtual void       	humanPlay() = 0;
    virtual void        display() = 0;
  };
}

#endif	//	__EF_IGAME_HH__
