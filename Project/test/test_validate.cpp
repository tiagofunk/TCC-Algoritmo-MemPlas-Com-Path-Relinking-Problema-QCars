#include <utils/Validate.h>
#include "gtest/gtest.h"

#include "../src/GLOBAL.h"

TEST( , IS_OK_1 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,2,3,0};
	sol->cars = new int[5]{1,1,1,2,2};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_2 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,2,3,0};
	sol->cars = new int[5]{1,1,1,1,1};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_3 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,3,0,-1};
	sol->cars = new int[5]{1,1,1,1,-1};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_4 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,0,-1,-1};
	sol->cars = new int[5]{1,1,1,-1,-1};

	ASSERT_TRUE( isOk( sol ) );
}

TEST( , IS_OK_FAIL_01 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Not starting in the correct city, that city 0
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{2,3,4,1,0};
	sol->cars = new int[5]{1,1,1,1,1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "The first city in a solution must always be equal to 0.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_02 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// It's repeating the city one after another
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,2,4,0};
	sol->cars = new int[5]{1,1,1,2,2};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution is invalid: city sequence is repeated\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_03 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// It is repeating the city in an interspersed way
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,3,2,0};
	sol->cars = new int[5]{1,1,1,2,2};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution is invalid: city sequence is repeated\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_04 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Is repeating the car intercalately
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,3,1,0};
	sol->cars = new int[5]{1,1,2,2,1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution is invalid: cars sequence is repeated\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_05 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// All values are null
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{-1,-1,-1,-1,-1};
	sol->cars = new int[5]{-1,-1,-1,-1,-1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution is null.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_06 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// All values are null, although values still exist after the number -1.
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{-1,2,3,4,5};
	sol->cars = new int[5]{-1,1,1,1,1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution is null.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_07 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Has only one city before value -1.
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,-1,3,4,5};
	sol->cars = new int[5]{0,-1,1,1,1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution has only one city.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_08 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Solution has only two cities, but ends up in the correct city
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,0,-1,-1,-1};
	sol->cars = new int[5]{1,1,-1,-1,-1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution has only two cities.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_09 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Solution has only two cities
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,2,-1,-1,-1};
	sol->cars = new int[5]{1,1,-1,-1,-1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Solution has only two cities.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_10 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Starts in the correct city, but does not end in it.
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,3,4,2};
	sol->cars = new int[5]{0,1,1,1,1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "The final city in a solution must always be equal to 0.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_11 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// You are using a city that does not exist
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,3,5,0};
	sol->cars = new int[5]{0,1,1,1,1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Invalid value for city: 5.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_12 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 2;

	// You're using a car that doesn't exist
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,3,2,0};
	sol->cars = new int[5]{0,1,1,1,2};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "Invalid value for car: 2.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_13 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Cars vector ends before cities vector
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,3,0,-1};
	sol->cars = new int[5]{0,1,1,-1,2};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "The cars vector ends before the cities vector.\n", exc.what() );
	}
}

TEST( , IS_OK_FAIL_14 ){
	numberCities_GLOBAL = 5;
	numberCars_GLOBAL = 3;

	// Cities vector ends before cars vector
	Solution* sol = new Solution( 5 );
	sol->cities = new int[5]{0,1,0,-1,-1};
	sol->cars = new int[5]{0,1,1,1,-1};

	try{
		isOk( sol );
		FAIL();
	}catch( runtime_error& exc ){
		ASSERT_STREQ( "The cities vector ends before the cars vector.\n", exc.what() );
	}
}
