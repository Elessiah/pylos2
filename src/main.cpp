// ************************************************
// 10/01/2025 15:06:41
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include			"network.hh"
#include			"morpion.hh"
#include			"utils.hh"

#define		HUMAN		0
#define		BOT		1

#include			<iostream>

int				main(void)
{
  std::vector<int>		build = { 2, 1 };
  ef::Network			network(build);
  std::ofstream			saveFile("XorNetwork.bin", std::ios::binary);

  network.learning(0, EXAM_XOR);
  network.save(saveFile);
  saveFile.close();
  //  network.retropropagation(EXAM_AND, 0.001);
  return (0);
}
