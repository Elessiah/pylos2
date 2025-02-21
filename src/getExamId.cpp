// ************************************************
// 21/02/2025 11:16:45
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

int			ef::getExamId(std::string	examName)
{
  if (examName == "morpion")
    return (EXAM_MORPION);
  else if (examName == "and")
    return (EXAM_AND);
  else if (examName == "or")
    return (EXAM_OR);
  else if (examName == "xor")
    return (EXAM_XOR);
  else if (examName == "nand")
    return (EXAM_NAND);
  else if (examName == "add2bit")
    return (EXAM_ADD2BIT);
  else
    return (-1);
}
