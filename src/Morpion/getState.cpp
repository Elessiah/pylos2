// ************************************************
// 17/01/2025 16:24:04
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"morpion.hh"

void			ef::Morpion::getState(std::vector<double>	&state)
{
  state.clear();
  if (!hasStarted)
    return;
  size_t		i;

  for (i = 0; i < sizeof(board); i += 1)
    {
      if (board[i] == EMPTY)
	state.emplace_back(10);
      else if (board[i] == turn)
	state.emplace_back(5);
      else
	state.emplace_back(15);
    }
}
