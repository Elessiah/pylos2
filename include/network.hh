// ************************************************
// 10/01/2025 11:41:36
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef					__EF_NETWORK_HH__

#define					__EF_NETWORK_HH__

#include				"neuron.hh"

namespace				ef
{
  class					Network
  {
  public:
    Network(std::vector<int>		&build);
    Network(std::ifstream		&file);
    Network(const Network		&other);
    ~Network();

    Network				&operator=(const Network	&other);
    bool				operator==(const Network	&other) const;
    bool				operator!=(const Network	&other) const;
    std::vector<double>			getOutput();
    void				resetNetworkReady();
    void				save(std::ofstream		&file) const;
    void				load(std::ifstream		&file);
    bool				verify();

  private:
    std::vector<std::vector<Neuron>>	neurons;
  };
}

#endif	//	__EF_NETWORK_HH__
