// ************************************************
// 15/01/2025 16:57:22
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

double			ef::Network::averageVector(std::vector<double>			&values)
{
  double		total;
  size_t		i;

  total = 0;
  for (i = 0; i < values.size(); i += 1)
    total += values[i];
  if (total != 0)
    return (total / values.size());
  return (0);
}
