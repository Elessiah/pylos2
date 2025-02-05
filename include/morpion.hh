// ************************************************
// 17/01/2025 14:44:54
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef			__EF_MORPION_HH__

# define		__EF_MORPION_HH__

# define	EMPTY	-1

# define	BWIDTH	3
# define	BHEIGHT	3

# define	XMOVE	0
# define	YMOVE	1

#include		"IGame.hh"
#include		"network.hh"

#include		<cstddef>

namespace		ef
{
  class			Morpion : public IGame
  {
  public:
    Morpion();
  
    void		start() override;
    void		startGame(Network			*AI,
				  int				nbHuman) override;
    bool		isRunning() override;
    char		whosTurn() override;
    void		getState(std::vector<double>		&state) override;
    bool		play(std::vector<double>		&move) override;
    void		humanPlay() override;
    void		display() override;
  private:
    bool	        hasStarted;
    char		board[9];
    char	        turn;

    void		reset();
    bool		hasWin(char				x,
			       char				y,
			       int				npos);
  };
}

#endif	//		__EF_MORPION_HH__
