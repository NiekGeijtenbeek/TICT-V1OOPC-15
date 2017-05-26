#include "vector.hpp"
#include <iostream>

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

TEST_CASE ( "constructor, two_parameters" ){
   vector v( 4, 4 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "(4,4)");
} 

TEST_CASE ( "+=, two_parameters" ){
   vector v( 4, 4 );
   vector v2( 4, 5 );
   
   v2 += v;
   
   std::stringstream s;
   s << v2;
   REQUIRE( s.str() == "(8,9)");
} 

TEST_CASE ( "+, two_parameters" ){
   vector v( 5, 4 );
   vector v2( 4, 5 );
   
   vector v3 = v + v2;
   
   std::stringstream s;
   s << v3;
   REQUIRE( s.str() == "(9,9)");
}

TEST_CASE ( "*=, two_parameters" ){
   vector v( 10, 92 );
   v *= 3;
   
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "(30,276)");
}


TEST_CASE ( "*, two_parameters" ){
   vector v( 10, 5 );
   int m = 5;
   
   vector v2 = v * 5;
   
   std::stringstream s;
   s << v2;
   REQUIRE( s.str() == "(50,25)");
}

TEST_CASE ( "*, two_parameters (int first!)" ){
   vector v( 10, 5 );
   int m = 5;
   
   vector v2 = 5 * v;
   
   std::stringstream s;
   s << v2;
   REQUIRE( s.str() == "(50,25)");
}
