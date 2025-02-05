// ************************************************
// 25/01/2025 08:22:59
// Keryan HOUSSIN 
// Pylos2
// ************************************************

#include		"network.hh"

#include		<cmath>
#include		<iostream>

void			ef::Network::calculError(s_learnSubjects	&subject,
						 std::vector<double>	&outputs,
						 size_t			compteur)
{
   double		subjectError;
   size_t		nOutput;

   subjectError = 0;
   for (nOutput = 0; nOutput < outputs.size(); nOutput += 1)
     subjectError += pow(subject.expectedResults[nOutput] - outputs[nOutput], 2);
   if (compteur == 0)
     networkError = 0.5 * subjectError;
   else
     networkError += ((0.5 * subjectError) - networkError) / (compteur);
}

