// ************************************************
// 31/01/2025 19:38:43
// Keryan HOUSSIN 
// ThreadPool
// ************************************************

#include		"threadPool.hh"

void			ef::ThreadPool::setTasksTarget(int	nbTasksTarget)
{
  //  std::cout << "Ajout d'une todolist de " << nbTasksTarget << " tâches." << std::endl;
  tasksRemaining.store(nbTasksTarget);
}
