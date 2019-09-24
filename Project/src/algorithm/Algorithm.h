#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "../utils/Validate.h"
#include "../utils/Prints.h"
#include "GenerateInitialPopulation.h"
#include "MultiOperatorsLocalSearch.h"
#include "Selections.h"
#include "Crossover.h"
#include "Plasmid.h"
#include "RestoringOperations.h"
#include "BinaryTournament.h"

class Algorithm {
private:
	int sizePopulation;
	int sizePlasmideo;
	double cross;
	double elite;
	int limitIterations;
	string strategy;
	string selectionStrategy;
	string intermediaryStrategy;

	vector< Solution > population;
	vector< Solution > elitePopulation;
	vector< Solution > selection;
	vector< Solution > offspring;

	void applyMemplasAndCrossover( int interation );
	void applyMemplasAndCrossoverAndPathRelinking();
	void applyPathRelinking();


public:
	Algorithm(
		string strategy, int sizePopulation, double elite, int limitIterations,
		int sizePlasmideo, double cross, string selectionStrategy, string intermediaryStrategy );

	void lets_go();
};

#endif /* ALGORITHM_H_ */
