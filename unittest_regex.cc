#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "regex.h"

using TestData = std::tuple<char const*, char const*, bool>;
static auto g_TestData{std::vector<TestData>{
	TestData{"", "", true},
	TestData{"a", "", false},
	TestData{"a", "a", true},
	TestData{"b", "a", false},
	TestData{"", "a", false},
	TestData{"", "a*", true},
	TestData{"a", "a*", true},
	TestData{"aa", "a*", true},
	TestData{"a", "a*a", true},
	TestData{"aa", "a*a", true},
	TestData{"a", ".", true},
	TestData{"b", ".", true},
	TestData{"", ".*", true},
	TestData{"ab", ".*b", true},
}};
BOOST_DATA_TEST_CASE(RegexMatch_VariousData_ReturnExpected, g_TestData, s, p, expected)
{
	BOOST_TEST(expected == regex_match(s, p));
}
