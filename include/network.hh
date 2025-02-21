// ************************************************
// 10/01/2025 11:41:36
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef					__EF_NETWORK_HH__

#define					__EF_NETWORK_HH__

# include				"networkCloner.hh"
# include				"neuron.hh"
# include				"learnSubjects.hh"

# include				<cstddef>

# define	INPUT_LAYER		0
# define	MAX_SIZE_LAYER		neurons.size() * 3

namespace				ef
{
  class					Network
  {
  public:
    Network(std::vector<int>		&build);
    Network(std::ifstream		&file);
    Network(const Network		&other);
    ~Network();

    friend class ef::NetworkCloner;

    Network				&operator=(const Network			&other);
    bool				operator==(const Network			&other) const;
    bool				operator!=(const Network			&other) const;
    std::vector<double>			getOutput();
    std::vector<double>			getOutput(const std::vector<double>		&inputValues);
    void				resetNetworkReady();
    void				save(std::ofstream				&file) const;
    void				load(std::ifstream				&file);
    bool				verify();
    double				primaryLearning(std::vector<s_learnSubjects>	&subjects);
    double				learning(double					targetScore,
						 int					idExam);
    double				learning(double					targetScore,
						 std::vector<s_learnSubjects>		&subjects);
    size_t				addNeuron(bool					sync = true);
    size_t				addNeuron(size_t				nLayer,
						  bool					sync = true);
    size_t				addNeurons(size_t				nbNeurons,
						   bool					sync = true);
    size_t				addNeurons(size_t				nbNeurons,
						   size_t				nLayer,
						   bool					sync = true);
    size_t				addLayer(bool					sync = true);
    size_t				addLayers(size_t				nbLayers,
						  bool					sync = true);
    void				textDisplay();
    bool				isFullSize();
    bool				isLayerFullSize(size_t				nLayer);
    double				examen(const std::vector<s_learnSubjects>	&subjects);
    void				upgrade(int					nLayer,
						int					nNeuron,
						int					nLink,
						double					modCoef,
						bool					isReverse);
    std::vector<std::vector<std::vector<double>>>	get();

  private:
    std::vector<std::vector<std::shared_ptr<Neuron>>>	neurons;
    size_t				nbLinks;
    std::vector<std::vector<std::vector<double>>>	gradient;
    std::vector<double>			modCoef;
    ef::NetworkCloner			cloner;

    void				builder(int					idExam);
    void				builder(std::vector<s_learnSubjects>		&subjects);
    void				compute();
    double				averageVector(std::vector<double>		&values);
    size_t				getNbLinks();
    void				tryCoef(std::vector<s_learnSubjects>		&subjects,
						double					&currentScore,
						int					nLayer,
						int					nNeuron,
						int					nLink);
    void				testNewCoef(Network				network,
						    int					nLayer,
						    int					nNeuron,
						    int					nLink,
						    double				modCoef,
						    std::vector<s_learnSubjects>	&subjects,
						    double				&newScore,
						    char				&isReverse);
    void				testNewCoef(Network				&network,
						    s_testCoef				&testCoef);
    size_t				chooseLayerToAdd();
    void				unlinkLayer(size_t				nLayer);
    void				syncCloneNetworks();
  };
}

#endif	//	__EF_NETWORK_HH__
