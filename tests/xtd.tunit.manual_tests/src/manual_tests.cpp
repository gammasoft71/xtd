#include <xtd/tunit>
#include <iostream>

using namespace xtd::tunit;
using namespace std;

namespace unit_tests {
  // Used test_class_attribute<> to add unit test suit.
  class test;
  test_class_attribute<test> test_class_attribute {"Test"};
  
  // The class DirectoryTest must be declared with TestClass_
  class test : public test_class {
  public:
    class_initialize_attribute class_initialize_attribute {"class_initialize", *this, &test::class_initialize};
    static void class_initialize() {
      cout << caller_ << endl;
    }
    
    class_cleanup_attribute class_cleanup_attribute {"class_cleanup", *this, &test::class_cleanup};
    static void class_cleanup() {
      cout << caller_ << endl;
    }
    
    // This is the method that is called before any tests in a fixture are run.
    test_initialize_attribute test_initialize_attribute {"test_initialize", *this, &test::test_initialize};
    static void test_initialize() {
      cout << caller_ << endl;
    }
    
    // This is the method that is called after any tests in a fixture are run.
    test_cleanup_attribute test_cleanup_attribute {"test_cleanup", *this, &test::test_cleanup};
    static void test_cleanup() {
      cout << caller_ << endl;
    }
    
    test_method_attribute test_case1_attribute {"test_case1", *this, &test::test_case1};
    void test_case1() {
      cout << caller_ << endl;
    }
    
    test_method_attribute test_case2_attribute {"test_case2", *this, &test::test_case2};
    void test_case2() {
      cout << caller_ << endl;
    }
    
    test_method_attribute test_case3_attribute {"test_case3", *this, &test::test_case3, test_state::ignored};
    void test_case3() {
      cout << caller_ << endl;
    }
  };
}

int main(int argc, char* argv[]) {
  cout << caller_ << endl;
  return unit_test(argv, argc).run();
}
