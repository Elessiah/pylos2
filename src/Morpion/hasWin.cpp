// ************************************************
// 17/01/2025 17:16:41
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"morpion.hh"

bool			ef::Morpion::hasWin(char		x,
					    char		y,
					    int			npos)
{
  char			streak;
  char			testX;
  char			testY;

  // Check horizontal
  streak = 1;
  testX = x - 1;
  while (testX >= 0)
    {
      npos = y * BWIDTH + testX;
      if (board[npos] == turn)
	{
	  streak += 1;
	  testX -= 1;
	}
      else
	testX = -1;
    }
  testX = x + 1;
  while (testX <= BWIDTH)
    {
      npos = y * BWIDTH + testX;
      if (board[npos] == turn)
	{
	  streak += 1;
	  testX += 1;
	}
      else
	testX = BWIDTH + 1;
    }
  if (streak == 3)
    return (true);

  // Check vertical
  streak = 1;
  testY = y - 1;
  while (testY >= 0)
    {
      npos = testY * BWIDTH + x;
      if (board[npos] == turn)
	{
	  streak += 1;
	  testY -= 1;
	}
      else
	testY = -1;
    }
  testY = y + 1;
  while (testY <= BHEIGHT)
    {
      npos = testY * BWIDTH + x;
      if (board[npos] == turn)
	{
	  streak += 1;
	  testY += 1;
	}
      else
	testY = BHEIGHT + 1;
    }
  if (streak == 3)
    return (true);
  // Check diagonal ascendant
  if (board[4] == turn)
    {
      if (board[6] == turn && board[4] == turn && board[2] == turn)
	return (true);
      if (board[0] == turn && board[8] == turn)
	return (true);
    }
  return (false);
}
