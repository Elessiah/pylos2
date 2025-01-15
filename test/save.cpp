// ************************************************
// 15/01/2025 10:37:08
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include			<gtest/gtest.h>
#include			<iostream>
#include			<cstdio>

#include			"network.hh"

TEST(NETWORK_SAVE_TEST, Test_Save_Load)
{
  std::vector<int>		build = {4, 8, 8, 8, 4};
  ef::Network			Network(build);
  std::string			filename = "TestFile.save";
  std::ofstream			saveFile(filename, std::ios::binary);

  Network.save(saveFile);
  saveFile.close();
  std::ifstream			loadFile(filename, std::ios::binary);
  ef::Network			loadNetwork(loadFile);

  loadFile.close();
  EXPECT_EQ(Network.verify(), true);
  EXPECT_EQ(Network, loadNetwork);
  std::remove(filename.c_str());
}
