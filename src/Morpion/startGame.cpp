// ************************************************
// 20/01/2025 07:23:59
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"morpion.hh"

#include		<iostream>

void			ef::Morpion::startGame(Network	*AI,
					       int	nbHuman)
{
  std::vector<double>	board;
  std::vector<double>	move;
    
  nbHuman -= 1;
  start();
  while (hasStarted)
    {
      getState(board);
      if (turn < nbHuman)
	{
	  std::cout << "Player " << turn << std::endl;
	  display();
	  humanPlay();
	}
      else
	{
	  move = AI->getOutput(board);
	  if (play(move) == false)
	    {
	      std::cout << "AI has failed !" << std::endl;
	      std::cout << "Move : " << move[XMOVE] << " " << move[YMOVE] << std::endl;
	      hasStarted = false;
	      return;
	    }
	}
    }
}
