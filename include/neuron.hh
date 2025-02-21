// ************************************************
// 12/02/2025 16:13:37
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef				__EF_NEURONS_HH__

# define			__EF_NEURONS_HH__

# include			<fstream>
# include			<vector>
# include			<memory>

namespace			ef
{
  class Neuron;
  class NetworkCloner;
  struct			s_input
  {
    std::shared_ptr<Neuron>	neuron;
    double			coef;
  };
  
  class				Neuron
  {
  public:
    Neuron();
    Neuron(std::vector<std::shared_ptr<Neuron>>		&neuronInputs);
    Neuron(std::ifstream				&file,
	   std::vector<std::shared_ptr<Neuron>>		&neuronInputs);
    Neuron(const std::shared_ptr<Neuron>		&other);
    Neuron(const std::shared_ptr<Neuron>		&other,
	   std::vector<std::shared_ptr<Neuron>>		&prevLayer);
    ~Neuron();

    friend class		NetworkCloner;

    Neuron			&operator=(const Neuron					&other);
    bool			operator==(const Neuron					&other) const;
    bool			operator!=(const Neuron					&other) const;
    double			getOutput();
    void		        setInput(double						value);
    void			save(std::ofstream					&file) const;
    void			load(std::ifstream					&file,
				     std::vector<std::shared_ptr<Neuron>>		&neuronInputs);
    void			resetReady();
    bool			verify(std::vector<std::shared_ptr<Neuron>>		&prevLayer);
    void			tryNewCoef(int						nLink,
					   double					coefEdit);
    void			switchReverse();
    void			back();
    void			linkNewNeuron(std::shared_ptr<Neuron>			&neuron);
    void			unlink();
    void			calculGradient(std::vector<double>			&gradient,
					       double					expectedResult,
					       size_t					compteur,
					       bool					isOutputLayer);
    void			applyGradient(std::vector<double>			&gradient,
					      double					speed);
    void			compute();
    std::vector<double>		getLinksCoef();
    void			syncWithNetwork(std::shared_ptr<Neuron>			&neuron,
						std::vector<std::shared_ptr<Neuron>>	&prevLayer);
    
  private:
    bool			isReady;
    bool			isReverse;
    double			outputValue;
    double			inputValue;
    std::vector<s_input>	inputs;
    double			lastCoef;
    size_t			lastEditInput;

    bool			writeHeader(std::ofstream				&file) const;
    bool			writeNeuronContent(std::ofstream			&file) const;
    bool			readHeader(std::ifstream				&file);
    bool			readNeuronContent(std::ifstream				&file,
						  std::vector<std::shared_ptr<Neuron>>	&neuronInputs);
  };
}

#endif	//			__EF_NEURONS_HH__
