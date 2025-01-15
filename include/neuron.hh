// ************************************************
// 10/01/2025 10:04:20
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef				__EF_NEURONS_HH__

#define				__EF_NEURONS_HH__

#include			<fstream>
#include			<vector>

namespace			ef
{
  class Neuron;
  struct			s_input
  {
    Neuron			*neuron;
    double			coef;
  };
  
  class				Neuron
  {
  public:
    Neuron();
    Neuron(std::vector<Neuron>	&neuronInputs);
    Neuron(std::ifstream	&file,
	   std::vector<Neuron>	&neuronInputs);
    Neuron(const Neuron		&other);
    ~Neuron();

    Neuron			&operator=(const Neuron			&other);
    bool			operator==(const Neuron			&other) const;
    bool			operator!=(const Neuron			&other) const;
    double			getOutput();
    void			save(std::ofstream			&file) const;
    void			load(std::ifstream			&file,
				     std::vector<Neuron>		&neuronInputs);
    void			resetReady();

  private:
    bool			isReady;
    bool			isReverse;
    double			outputValue;
    double			inputValue;
    std::vector<s_input>	inputs;

    double			compute();
    bool			writeHeader(std::ofstream		&file) const;
    bool			writeNeuronContent(std::ofstream	&file) const;
    bool			readHeader(std::ifstream		&file);
    bool			readNeuronContent(std::ifstream		&file,
						  std::vector<Neuron>	&neuronInputs);
  };
}

#endif	//			__EF_NEURONS_HH__
