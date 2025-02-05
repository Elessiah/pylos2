// ************************************************
// 17/01/2025 16:37:59
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"morpion.hh"

bool			ef::Morpion::play(std::vector<double>	&move)
{
  if (!hasStarted)
    return (false);
  if (move.size() != 2 || move[0] < -1 || move[0] > 3 || move[1] < -1 || move[1] > 3)
    return (false);
  int			npos;
  char			x;
  char			y;

  x = static_cast<char>(move[XMOVE]);
  y = static_cast<char>(move[YMOVE]);
  npos = y * BWIDTH + x;
  if (npos < 0 || npos > 2 || board[npos] != -1)
    return (false);
  board[npos] = turn;
  if (hasWin(x, y, npos))
    hasStarted = false;
  else
    turn = ((turn == 0) ? 1 : 0);
  return (true);
}
