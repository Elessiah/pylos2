// ************************************************
// 21/02/2025 14:56:57
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include	"logicDeductor.hh"

#include	<map>

void		ef::LogicDeductor::extractConditions(std::vector<std::vector<double>>	&on,
						     std::vector<std::vector<double>>	&off,
						     std::vector<s_logicDoor>		&conditions)
{
  size_t	i;
  size_t	nInput;
  s_logicDoor	condition;
  std::vector<std::vector<int>>	onInput;
  std::vector<std::vector<int>>	offInput;

  for (i = 0; i < on.size(); i += 1)
    {
      onInput.emplace_back();
      for (nInput = 0; nInput < on[i].size(); nInput += 1)
	{
	  if (on[i][nInput] == 1)
	    onInput[i].push_back((int)nInput);
	}
    }
  for (i = 0; i < onInput.size(); i += 1)
    {
      
    }
}
