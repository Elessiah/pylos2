// ************************************************
// 17/01/2025 16:15:55
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"morpion.hh"

char			ef::Morpion::whosTurn()
{
  if (hasStarted)
    return (turn);
  return (-1);
}
