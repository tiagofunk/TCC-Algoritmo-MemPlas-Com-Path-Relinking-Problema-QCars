#include "gtest.h"
#include "../model/Solution.h"
#include "../utils/InstanceReader.h"

TEST( , TEST_FITNESS_SATISFACTION_1 ) {
	const char* file = "/home/tiago/Repositorios/Github/MemPlas-And-Path-Relinking/Instances/n/AfricaSul11n.pcar";

	try{
		readInstance( file );

		Solution* sol = new Solution( 11+1 );
		sol->addEnd(0,0);
		sol->addEnd(3,0);
		sol->addEnd(4,1);
		sol->addEnd(8,2);
		sol->addEnd(9,2);
		sol->addEnd(0,2);

		sol->calculeSatisfaction();
		EXPECT_EQ( sol->getSatisfaction(), 347 );

		sol->calculeFitness();
		EXPECT_EQ( sol->getFitness(), 569 );
	} catch (exception &e) {
		cout << e.what() << endl;
		FAIL();
	}
}

TEST( , TEST_FITNESS_SATISFACTOIN_2 ) {
	const char* file = "/home/tiago/Repositorios/Github/MemPlas-And-Path-Relinking/Instances/n/Etiopia10n.pcar";

	try{
		readInstance( file );

		Solution* sol = new Solution( 10+1 );
		sol->addEnd(0,1);
		sol->addEnd(5,1);
		sol->addEnd(2,2);
		sol->addEnd(7,3);
		sol->addEnd(4,3);
		sol->addEnd(0,3);

		sol->calculeSatisfaction();
		EXPECT_EQ( sol->getSatisfaction(), 280 );

		sol->calculeFitness();
		EXPECT_EQ( sol->getFitness(), 1826 );
	} catch (exception &e) {
		cout << e.what() << endl;
		FAIL();
	}
}


TEST( , TEST_FITNESS_SATISFACTOIN_3 ) {
	const char* file = "/home/tiago/Repositorios/Github/MemPlas-And-Path-Relinking/Instances/n/Mali11n.pcar";

	try{
		readInstance( file );

		Solution* sol = new Solution( 11+1 );
		sol->addEnd(0,2);
		sol->addEnd(1,2);
		sol->addEnd(3,2);
		sol->addEnd(5,1);
		sol->addEnd(0,3);

		sol->calculeSatisfaction();
		EXPECT_EQ( sol->getSatisfaction(), 204 );

		sol->calculeFitness();
		EXPECT_EQ( sol->getFitness(), 691 );
	} catch (exception &e) {
		cout << e.what() << endl;
		FAIL();
	}
}

TEST( , TEST_FITNESS_SATISFACTOIN_4 ) {
	const char* file = "/home/tiago/Repositorios/Github/MemPlas-And-Path-Relinking/Instances/n/Ira13n.pcar";

	try{
		readInstance( file );

		Solution* sol = new Solution( 13+1 );
		sol->addEnd(0,0);
		sol->addEnd(8,0);
		sol->addEnd(12,0);
		sol->addEnd(3,1);
		sol->addEnd(2,1);
		sol->addEnd(10,1);
		sol->addEnd(4,1);
		sol->addEnd(9,2);
		sol->addEnd(0,2);

		sol->calculeSatisfaction();
		EXPECT_EQ( sol->getSatisfaction(), 456 );

		sol->calculeFitness();
		EXPECT_EQ( sol->getFitness(), 694 );
	} catch (exception &e) {
		cout << e.what() << endl;
		FAIL();
	}
}

TEST( , TEST_SATISFACTION_PURE_1 ) {
	try{
		bonus_satisfaction_GLOBAL = new int[5]{ 1, 2, 4, 8, 16 };

		Solution* sol = new Solution( 11+1 );
		sol->addEnd(0,0);
		sol->addEnd(2,0);
		sol->addEnd(3,1);
		sol->addEnd(4,1);
		sol->addEnd(0,2);

		sol->calculeSatisfaction();
		EXPECT_EQ( sol->getSatisfaction(), 29 );

	} catch (exception &e) {
		cout << e.what() << endl;
		FAIL();
	}
}

TEST( , TEST_SATISFACTION_PURE_2 ) {
	try{
		bonus_satisfaction_GLOBAL = new int[5]{ 1, 2, 4, 8, 16 };

		Solution* sol = new Solution( 11+1 );
		sol->addEnd(0,0);
		sol->addEnd(2,0);
		sol->addEnd(3,1);
		sol->addEnd(4,1);

		sol->calculeSatisfaction();
		EXPECT_EQ( sol->getSatisfaction(), 29 );

	} catch (exception &e) {
		cout << e.what() << endl;
		FAIL();
	}
}
