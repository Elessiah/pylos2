// ************************************************
// 17/01/2025 16:09:08
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"morpion.hh"

void		ef::Morpion::reset()
{
  size_t	i;

  for (i = 0; i < sizeof(board); i += 1)
    board[i] = EMPTY;
}
