/**
 * @author Canberk Sönmez
 * 
 * @date Tue Jul 17 05:58:28 +03 2018
 * 
 */

#define BOOST_TEST_MODULE __FILE__
#include <boost/test/unit_test.hpp>
namespace utf   = boost::unit_test;

#include <riot/mpl/overload.hpp>
#include <riot/mpl/filtered_overload.hpp>

using namespace riot::mpl;

BOOST_AUTO_TEST_CASE(test_overload) {
    {
        constexpr auto f = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; });
        
        constexpr auto val1 = f(1);         // call int
        constexpr auto val2 = f('c');       // call int
        constexpr auto val3 = f("canberk"); // call const char*
        constexpr auto val4 = f(1.2);       // call int
        
        BOOST_CHECK_EQUAL(val1, 1);
        BOOST_CHECK_EQUAL(val2, 1);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 1);
    }
    
    {
        auto f = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; });
        
        auto val1 = f(1);           // call int
        auto val2 = f('c');         // call int
        auto val3 = f("canberk");   // call const char*
        auto val4 = f(1.2);         // call int
        
        BOOST_CHECK_EQUAL(val1, 1);
        BOOST_CHECK_EQUAL(val2, 1);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 1);
    }
    
    {
        constexpr auto val1 = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })(1);           // call int
        constexpr auto val2 = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })('c');         // call int
        constexpr auto val3 = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })("canberk");   // call const char*
        constexpr auto val4 = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })(1.2);         // call int
        
        BOOST_CHECK_EQUAL(val1, 1);
        BOOST_CHECK_EQUAL(val2, 1);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 1);
    }
    
    {
        auto val1 = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })(1);           // call int
        auto val2 = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })('c');         // call int
        auto val3 = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })("canberk");   // call const char*
        auto val4 = overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })(1.2);         // call int
        
        BOOST_CHECK_EQUAL(val1, 1);
        BOOST_CHECK_EQUAL(val2, 1);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 1);
    }
}

BOOST_AUTO_TEST_CASE(test_filtered_overload) {
    {
        constexpr auto f = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; });
        
        constexpr auto val1 = f(1);         // call int
        constexpr auto val2 = f('c');       // call int
        constexpr auto val3 = f("canberk"); // call const char*
        constexpr auto val4 = f(1.2);       // call int
        
        BOOST_CHECK_EQUAL(val1, 1);
        BOOST_CHECK_EQUAL(val2, 1);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 1);
    }
    
    {
        auto f = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; });
        
        auto val1 = f(1);           // call int
        auto val2 = f('c');         // call int
        auto val3 = f("canberk");   // call const char*
        auto val4 = f(1.2);         // call int
        
        BOOST_CHECK_EQUAL(val1, 1);
        BOOST_CHECK_EQUAL(val2, 1);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 1);
    }
    
    {
        constexpr auto val1 = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })(1);           // call int
        constexpr auto val2 = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })('c');         // call int
        constexpr auto val3 = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })("canberk");   // call const char*
        constexpr auto val4 = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })(1.2);         // call int
        
        BOOST_CHECK_EQUAL(val1, 1);
        BOOST_CHECK_EQUAL(val2, 1);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 1);
    }
    
    {
        auto val1 = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })(1);           // call int
        auto val2 = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })('c');         // call int
        auto val3 = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })("canberk");   // call const char*
        auto val4 = filtered_overload(
            [](int) { return 1; },
            [](char) { return 2; },
            [](const char *) { return 3; },
            [](double) { return 4; })(1.2);         // call int
        
        BOOST_CHECK_EQUAL(val1, 1);
        BOOST_CHECK_EQUAL(val2, 1);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 1);
    }
    
#define FALSE_  [](...) { return false; }
#define TRUE_   [](...) { return true; }
    
    {
        constexpr auto f = filtered_overload(
            filter(FALSE_, [](int) { return 1; }),
            filter(FALSE_, [](char) { return 2; }),
            [](const char *) { return 3; },
            [](double) { return 4; });
        
        constexpr auto val1 = f(1);
        constexpr auto val2 = f('c');
        constexpr auto val3 = f("canberk");
        constexpr auto val4 = f(1.2);
        
        BOOST_CHECK_EQUAL(val1, 4);
        BOOST_CHECK_EQUAL(val2, 4);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 4);
    }
    
    {
        constexpr auto f = filtered_overload(
            filter(TRUE_, [](int) { return 0; }, [](int) { return 1; }),
            filter(FALSE_, [](char) { return 2; }),
            [](const char *) { return 3; },
            [](double) { return 4; });
        
        constexpr auto val1 = f(1);
        constexpr auto val2 = f('c');
        constexpr auto val3 = f("canberk");
        constexpr auto val4 = f(1.2);
        
        BOOST_CHECK_EQUAL(val1, 0);
        BOOST_CHECK_EQUAL(val2, 0);
        BOOST_CHECK_EQUAL(val3, 3);
        BOOST_CHECK_EQUAL(val4, 0);
    }
    
#undef TRUE_
#undef FALSE_
}