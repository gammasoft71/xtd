#include <xtd/xtd.tunit>
#include <cstdint>
#include <limits>

using namespace xtd::tunit;

template<typename T>
size_t get_max_value() {return 0;}

template<>
size_t get_max_value<bool>() {return 1;}

template<>
size_t get_max_value<int>() {return 2147483647;}

template<>
size_t get_max_value<int8_t>() {return 127;}

template<>
size_t get_max_value<long int>() {return 9223372036854775807;}

template<>
size_t get_max_value<uint8_t>() {return 255;}

namespace unit_tests {
  // Used test_class_attribute<> to add unit test suit.
  template<typename T>
  class test;
  
  test_class_attribute<test<bool>> test_bool_class_attr {"test<bool>"};
  test_class_attribute<test<int>> test_int_class_attr {"test<int>"};
  test_class_attribute<test<long int>> test_double_class_attr {"test<long int>"};
  test_class_attribute<test<int8_t>> test_int8_t_class_attr {"test<int8_t>"};
  test_class_attribute<test<uint8_t>> test_uint8_t_class_attr {"test<uint8_t>"};

  // The test class must be inherit from test_class class.
  template<typename T>
  class test : public test_class {
  public:
    void test_method_(test_max_value) {
      static std::map<std::string, size_t> expected_max_values = {{typeid(bool).name(), std::numeric_limits<bool>::max()}, {typeid(int).name(), std::numeric_limits<int>::max()}, {typeid(long int).name(), std::numeric_limits<long int>::max()}, {typeid(int8_t).name(), std::numeric_limits<int8_t>::max()}};

      if (expected_max_values.find(typeid(T).name()) == expected_max_values.end())
        assert::fail("expect max value for this type is not defined.");
      
      assert::are_equal(expected_max_values[typeid(T).name()], get_max_value<T>());
    }
  };
}

int main() {
  return console_unit_test().run();
}

// This code can produce the following output:
//
// Start 5 tests from 5 test cases
// Run tests:
//   SUCCEED test<bool>.test_max_value (0 ms total)
//   SUCCEED test<int>.test_max_value (0 ms total)
//   SUCCEED test<long int>.test_max_value (0 ms total)
//   SUCCEED test<int8_t>.test_max_value (0 ms total)
//   FAILED  test<uint8_t>.test_max_value (0 ms total)
//     expect max value for this type is not defined.
//     Stack Trace: in |---OMITTED---|/generic_test_class.cpp:39
//
// Test results:
//   SUCCEED 4 tests.
//   FAILED  1 test.
// End 5 tests from 5 test cases ran. (0 ms total)
