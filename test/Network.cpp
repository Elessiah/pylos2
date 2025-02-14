// ************************************************
// 24/01/2025 13:28:01
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		<gtest/gtest.h>

#include		"network.hh"

TEST(TEST_NETWORK, Test_Add_Neurons)
{
  std::vector<int>		build = {4, 8, 8, 3, 4};
  ef::Network			Network(build);
  size_t			nLayer = 1;

  EXPECT_EQ(Network.verify(), true);
  Network.addNeuron();
  EXPECT_EQ(Network.verify(), true);
  Network.addNeuron(nLayer);
  EXPECT_EQ(Network.verify(), true);
  Network.addLayer();
  EXPECT_EQ(Network.verify(), true);
}

TEST(TEST_NETWORK, Test_Save_Load)
{
  std::vector<int>		build = {4, 8, 8, 8, 4};
  ef::Network			Network(build);
  std::string			filename = "TestFile.save";
  std::ofstream			saveFile(filename, std::ios::binary);

  EXPECT_EQ(Network, Network);
  Network.save(saveFile);
  saveFile.close();
  std::ifstream			loadFile(filename, std::ios::binary);
  ef::Network			loadNetwork(loadFile);

  loadFile.close();
  EXPECT_EQ(Network.verify(), true);
  EXPECT_EQ(Network, loadNetwork);
  std::remove(filename.c_str());
}

TEST(TEST_NETWORK, Test_Constructor_Copy)
{
  std::vector<int>		build = {2, 8, 8, 8, 1};
  ef::Network			Network(build);
  ef::Network			cpy(Network);
  std::vector<ef::s_learnSubjects>	subjects;

  EXPECT_EQ(Network.verify(), true);
  EXPECT_EQ(cpy.verify(), true);
  EXPECT_EQ(Network, cpy);
  subjects = ef::getExam(EXAM_XOR);
  EXPECT_EQ(Network.examen(subjects), cpy.examen(subjects));
}

TEST(TEST_NETWORK, Test_Copy_Operator)
{
  std::vector<int>		build = {4, 8, 8, 8, 4};
  ef::Network			Network(build);
  build[1] = 4;
  ef::Network			copy(build);

  EXPECT_EQ(Network.verify(), true);
  EXPECT_EQ(copy.verify(), true);
  EXPECT_NE(Network, copy);

  copy = Network;
  EXPECT_EQ(Network.verify(), true);
  EXPECT_EQ(copy.verify(), true);
  EXPECT_EQ(Network, copy);

}

TEST(TEST_NETWORK, EXAM_REGULARITY)
{
  std::vector<int>		build = {2, 8, 8, 8, 1};
  ef::Network			Network(build);
  size_t			i;
  double			score;
  std::vector<ef::s_learnSubjects>	subjects;

  subjects = ef::getExam(EXAM_XOR);
  score = Network.examen(subjects);
  for (i = 0; i < 10; i += 1)
    EXPECT_EQ(score, Network.examen(subjects));
}

TEST(TEST_NETWORK, DUPLICATION_EQUALITY)
{
  std::vector<int>		build = { 2, 8, 8, 8, 1 };
  ef::Network			network1(build);
  ef::Network			network2(network1);
  std::vector<ef::s_learnSubjects>	subjects;

  subjects = ef::getExam(EXAM_XOR);
  EXPECT_EQ(network1, network2);
  EXPECT_EQ(network1.examen(subjects), network2.examen(subjects));
  network1.primaryLearning(subjects);
  network2.primaryLearning(subjects);
  EXPECT_EQ(network1.examen(subjects), network2.examen(subjects));
}
