# Variables de compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -g -ggdb -I./include --coverage
LDFLAGS = --coverage -lgtest -lgtest_main -pthread

SRCDIR = ./src
INCDIR = ./include
TESTDIR = ./test
OBJDIR = ./obj
TARGET = network

# Couleurs
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m

# Recherche des fichiers sources
SRCS = $(shell find $(SRCDIR) -name '*.cpp')
# Séparer main.cpp des autres fichiers sources
MAIN_SRC = $(SRCDIR)/main.cpp
# Objets sauf main.cpp
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(filter-out $(MAIN_SRC), $(SRCS)))

# Recherche des fichiers de test
TEST_SRCS = $(shell find $(TESTDIR) -name '*.cpp')
TEST_OBJS = $(patsubst $(TESTDIR)/%.cpp, $(OBJDIR)/%.o, $(TEST_SRCS))

# Règle principale
all: $(TARGET)

# Compilation du programme principal
$(TARGET): $(OBJS) $(OBJDIR)/main.o
	@echo "$(CYAN)[LINK]$(RESET) Linking $(TARGET)..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(GREEN)[DONE]$(RESET) $(TARGET) built successfully."

# Compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$(YELLOW)[COMPILE]$(RESET) Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

# Compilation des tests unitaires
test: $(TEST_OBJS) $(OBJS)
	@echo "$(CYAN)[TEST]$(RESET) Compiling tests..."
	@$(CXX) $(CXXFLAGS) -o test_runner $(OBJS) $(TEST_OBJS) $(LDFLAGS)
	@echo "$(GREEN)[DONE]$(RESET) Test runner built successfully."

# Compilation des fichiers objets des tests
$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$(YELLOW)[COMPILE TEST]$(RESET) Compiling test $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

# Règle pour exécuter les tests
run_tests: test
	@echo "$(CYAN)[TEST]$(RESET) Running tests..."
	@./test_runner || echo "$(RED)[FAILURE]$(RESET) One or more tests failed."
	@echo "$(GREEN)[SUCCESS]$(RESET) All tests passed."

# Règle pour générer le rapport de couverture
coverage: run_tests
	@echo "$(CYAN)[COVERAGE]$(RESET) Generating coverage report..."
	@gcov $(SRCS) $(TEST_SRCS)

# Nettoyage des fichiers temporaires
clean:
	@echo "$(CYAN)[CLEAN]$(RESET) Cleaning build artifacts..."
	@rm -rf $(OBJDIR) *.gcda *.gcno *.gcov test_runner
	@find . -name "*~" -type f -delete

# Nettoyage complet, y compris le binaire cible
fclean: clean
	@echo "$(CYAN)[FCLEAN]$(RESET) Removing $(TARGET)..."
	@rm -f $(TARGET)

# Nettoyage et recompilation complète
re: fclean all

# Règles de base
.PHONY: all test run_tests coverage clean fclean re
