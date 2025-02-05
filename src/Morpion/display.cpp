// ************************************************
// 17/01/2025 23:45:14
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"morpion.hh"

#include		<iostream>

void			ef::Morpion::display()
{
  size_t		i;

  std::cout << "X : you, Y : Opponent" << std::endl;
  for (i = 0; i < sizeof(board); i += 1)
    {
      if ((i % 3) == 0)
	std::cout << "\n";
      if (board[i] == turn)
	std::cout << "[" << "X" << "]";
      else if (board[i] == EMPTY)
	std::cout << "[" << i << "]";
      else
	std::cout << "[" << "Y" << "]";
    }
  std::cout << std::endl;
}
