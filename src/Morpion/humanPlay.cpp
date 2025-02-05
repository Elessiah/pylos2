// ************************************************
// 17/01/2025 23:49:35
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"morpion.hh"

#include		<iostream>

void			ef::Morpion::humanPlay()
{
  std::vector<double>	move;
  int			moveNpos;
  
  std::cout << "\nEnter your next move : " << std::flush;
  std::cin >> moveNpos;
  move.emplace_back(moveNpos % BWIDTH);
  move.emplace_back(moveNpos / BHEIGHT);
  if (play(move) == false)
    std::cout << "Your move is wrong !" << std::endl;
}
