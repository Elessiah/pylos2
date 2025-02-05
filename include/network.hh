// ************************************************
// 10/01/2025 11:41:36
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#ifndef					__EF_NETWORK_HH__

#define					__EF_NETWORK_HH__

# include				"neuron.hh"
# include				"learnSubjects.hh"
# include				"threadPool.hh"

# include				<cstddef>

# define	INPUT_LAYER		0

namespace				ef
{
  class					Network
  {
  public:
    Network(std::vector<int>		&build);
    Network(std::ifstream		&file);
    Network(const Network		&other);
    ~Network();

    Network				&operator=(const Network			&other);
    bool				operator==(const Network			&other) const;
    bool				operator!=(const Network			&other) const;
    std::vector<double>			getOutput();
    std::vector<double>			getOutput(const std::vector<double>		&inputValues);
    void				resetNetworkReady();
    void				save(std::ofstream				&file) const;
    void				load(std::ifstream				&file);
    bool				verify();
    double				retropropagation(int				idExam,
							 double				speed);
    double				primaryLearning(std::vector<s_learnSubjects>	&subjects);
    double				learning(double					targetScore,
						 int					idExam);
    size_t				addNeuron();
    size_t				addNeuron(size_t				nLayer);
    size_t				addNeurons(size_t				nbNeurons);
    size_t				addNeurons(size_t				nbNeurons,
						   size_t				nLayer);
    size_t				addLayer();
    size_t				addLayers(size_t				nbLayers);
    void				calculGradient(std::vector<s_learnSubjects>	&subjects);
    void				textDisplay();
    bool				isFullSize();
    bool				isLayerFullSize(size_t				nLayer);

  private:
    std::vector<std::vector<std::shared_ptr<Neuron>>>	neurons;
    size_t				nbLinks;
    std::vector<std::vector<std::vector<double>>>	gradient;
    double				networkError;
    ef::ThreadPool			threadPool;

    void				compute();
    double				examen(const std::vector<s_learnSubjects>	&subjects);
    double				averageVector(std::vector<double>		&values);
    size_t				getNbLinks();
    void				tryCoef(std::vector<s_learnSubjects>		&subjects,
						double					&currentScore,
						int					nLayer,
						int					nNeuron,
						size_t					nLink);
    void				testNewCoef(Network				network,
						    int					nLayer,
						    int					nNeuron,
						    int					nLink,
						    double				modCoef,
						    const std::vector<s_learnSubjects>	&subjects,
						    double				&newScore,
						    char				&isReverse);
    size_t				chooseLayerToAdd();
    void				unlinkLayer(size_t				nLayer);
    void				initGradient(bool				onlyReset = false);
    void				calculError(s_learnSubjects			&subject,
						    std::vector<double>			&outputs,
						    size_t				compteur);
    void				calculGradient(s_learnSubjects			&subject,
						       size_t				compteur);
    void				calculRetropropagation(std::vector<s_learnSubjects>	&subjects);
    void				applyRetropropagation(double			speed);
  };
}

#endif	//	__EF_NETWORK_HH__
