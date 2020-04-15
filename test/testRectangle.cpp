//
// Created by Russo, Michelangelo (GE Global Research) on 2/28/18.
//

#define BOOST_TEST_MODULE ExampleTestModule

#include <iostream>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>

#include "rectangle.h"

using namespace std;
using namespace boost;
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(ExampleTestSuite)

    struct TestFixture
    {
        TestFixture() : i( 0 ) {
            cout << "Initialize Test" << endl;
        }

        ~TestFixture() {
            cout << "Cleanup Test" << endl;
        }
        int i ;
    };


    BOOST_FIXTURE_TEST_CASE(BoostCheckTest, TestFixture)
    {
        // Provide a test predicate (i.e. a conditional statement) that evaluates
        // to true to allow the test to pass and will not indicate a failed test.

        rectangle rect;
        rect.set_values (3,4);
        BOOST_CHECK(rect.area()==12);

        // Provide a test predicate (i.e. a conditional statement) that evaluates
        // to false to force the test to fail and will issue a warning with message.
        //BOOST_CHECK(rect.area()==18);
    }

BOOST_AUTO_TEST_SUITE_END()

// More test suites

