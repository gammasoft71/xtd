#include <xtd/xtd.tunit>
#include <cstdint>
#include <limits>

using namespace xtd;
using namespace tunit;

template<typename type_t>
size_t get_max_value() {return 0;}

template<>
size_t get_max_value<bool>() {return 1;}

template<>
size_t get_max_value<int>() {return 2147483647;}

template<>
size_t get_max_value<char>() {return 127;}

template<>
size_t get_max_value<long int>() {return 9223372036854775807;}

template<>
size_t get_max_value<unsigned char>() {return 255;}

namespace unit_tests {
  // Used test_class_attribute<> to add unit test suit.
  template<typename type_t>
  class test;
  
  test_class_attribute<test<bool>> test_bool_class_attr {"test<bool>"};
  test_class_attribute<test<int>> test_int_class_attr {"test<int>"};
  test_class_attribute<test<long int>> test_double_class_attr {"test<long_int>"};
  test_class_attribute<test<char>> test_int8_t_class_attr {"test<sbyte>"};
  test_class_attribute<test<unsigned char>> test_uint8_t_class_attr {"test<byte>"};
  
  // The test class must be inherit from test_class class.
  template<typename type_t>
  class test : public test_class {
    void test_method_(test_max_value) {
      static auto expected_max_values = std::map<std::string, size_t> {{typeid(bool).name(), std::numeric_limits<bool>::max()}, {typeid(int).name(), std::numeric_limits<int>::max()}, {typeid(long int).name(), std::numeric_limits<long int>::max()}, {typeid(char).name(), std::numeric_limits<char>::max()}};
      
      if (expected_max_values.find(typeid(type_t).name()) == expected_max_values.end())
        assert::fail("expect max value for this type is not defined.");
        
      assert::are_equal(expected_max_values[typeid(type_t).name()], get_max_value<type_t>());
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code can produce the following output:
//
// Start 5 tests from 5 test cases
// Run tests:
//   SUCCEED test<bool>.test_max_value (0 ms total)
//   SUCCEED test<int>.test_max_value (0 ms total)
//   SUCCEED test<long int>.test_max_value (0 ms total)
//   SUCCEED test<sbyte>.test_max_value (0 ms total)
//   FAILED  test<byte>.test_max_value (0 ms total)
//     expect max value for this type is not defined.
//     Stack Trace: in |---OMITTED---|/generic_test_class.cpp:39
//
// Test results:
//   SUCCEED 4 tests.
//   FAILED  1 test.
// End 5 tests from 5 test cases ran. (0 ms total)
