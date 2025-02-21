#include		"network.hh"

int			main(void)
{
  std::vector<int>	build = {2, 4, 1};
  ef::Network		network(build);
  std::ofstream		file("blankNetwork.bin", std::ios::binary);

  network.save(file);
  file.close();
}
