#include <xtd/tunit>
#include <iostream>

using namespace xtd::tunit;
using namespace std;

namespace unit_tests {
  // Used test_class_attribute<> to add unit test suit.
  class test;
  test_class_attribute<test> test_class_attr {"Test"};
  
  // The class DirectoryTest must be declared with TestClass_
  class test : public test_class {
  public:
    class_initialize_attribute class_initialize_attr {"class_initialize", *this, &test::class_initialize};
    static void class_initialize() {
      cout << line_info {__func__, __FILE__, __LINE__} << endl;
    }
    
    class_cleanup_attribute class_cleanup_attr {"class_cleanup", *this, &test::class_cleanup};
    static void class_cleanup() {
      cout << line_info {__func__, __FILE__, __LINE__} << endl;
    }
    
    // This is the method that is called before any tests in a fixture are run.
    test_initialize_attribute test_initialize_attr {"test_initialize", *this, &test::test_initialize};
    static void test_initialize() {
      cout << line_info {__func__, __FILE__, __LINE__} << endl;
    }
    
    // This is the method that is called after any tests in a fixture are run.
    test_cleanup_attribute test_cleanup_attr {"test_cleanup", *this, &test::test_cleanup};
    static void test_cleanup() {
      cout << line_info {__func__, __FILE__, __LINE__} << endl;
    }
    
    test_method_attribute test_case1_attr {"test_case1", *this, &test::test_case1};
    void test_case1() {
      cout << line_info {__func__, __FILE__, __LINE__} << endl;
    }
    
    test_method_attribute test_case2_attr {"test_case2", *this, &test::test_case2};
    void test_case2() {
      cout << line_info {__func__, __FILE__, __LINE__} << endl;
    }
    
    test_method_attribute test_case3_attr {"test_case3", *this, &test::test_case3, test_state::ignored};
    void test_case3() {
      cout << line_info {__func__, __FILE__, __LINE__} << endl;
    }
  };
}

int main(int argc, char* argv[]) {
  cout << line_info {__func__, __FILE__, __LINE__} << endl;
  return unit_test(argv, argc).run();
}
