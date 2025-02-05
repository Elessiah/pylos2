// ************************************************
// 17/01/2025 15:56:40
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"morpion.hh"

#include	<cstdlib>

void		ef::Morpion::start()
{
  hasStarted = true;
  reset();
  turn = rand() % 2;
}
