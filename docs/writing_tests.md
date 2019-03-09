| [Home](home.md) | [Downloads](downloads.md) | [Examples](examples.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd.tunit) | [Project](https://sourceforge.net/projects/tunitpro/) | [Contact](contact.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |

# Writing tests

## In This Section

* [Helpers](#helpers)
* [Assertions](#assertions)
* [Validations](#validations)
* [Assumptions](#assumptions)
* [Initilize and Cleanup](#initialize-and-cleanup)
* [Test case](#test-case)
* [Test class](#test-class)
* [Test](#test)

## Helpers

xtd.tunit uses custom helpers to identify test fixtures and test methods. It's the easy way to create tests.

| helpers                            | Usage                                                                                                                            |
|------------------------------------|----------------------------------------------------------------------------------------------------------------------------------|
| test_class_(class_name)            | Is used to define the class (test fixture) wtih class_name name.                                                                 |
| class_initialize_(initialize_name) | Is used to define class initialize method with initialize_name name.                                                             |
| class_cleanup_(cleanup_name).      | Is used to define class cleanup method with cleanup_name name.                                                                   |
| test_initialize_(initialize_name)  | Is used to define test initialize method with initialize_name name.                                                              |
| test_cleanup_(cleanup_name)        | Is used to define test cleanup method with cleanup_name name.                                                                    |
| test_method_(method_name)          | Is used to define test method (test case) with method_name name.                                                                 |
| ingore_test_method_(method_name)   | Is used to define ignored test method (test case) with method_name name.                                                         |
| line_info_                         | Is used to create a xtd::tunit::line_info class initialized with current method name, current file name and current line number. |

### Examples

The following example shows how to create and register fixture and test cases with helpers :

```c++
#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  // Create new test fixture with test_class_ helper.
  class test_class_(test) {
  public:
    // This is the method that is called 1 time before test class run.
    static void class_initialize_(class_initialize) {
    }
    
    // This is the method that is called 1 time after test class run.
    static void class_cleanup_(class_cleanup) {
    }
    
    // This is the method that is called before each test case of test fixture.
    static void test_initialize_(test_initialize) {
    }
    
    // This is the method that is called after each test case of test fixture.
    static void test_cleanup_(test_cleanup) {
    }
    
    // Test case 1
    void test_method_(test_case1) {
    }
    
    // Test case 2
    void test_method_(test_case2) {
    }
    
    // Ignore Test case 3
    void ignore_test_method_(test_case3) {
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

The following example shows how to create and register same fixture and same test cases without helpers :

```c++
#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  // Used test_class_attribute<> to register test fixture.
  class test;
  test_class_attribute<test> test_class_attr {"test"};

  // Create new test fixture inherited test_class.
  class test : public test_class {
  public:
    // Used class_initialize_attribute object to register class initialize method.
    class_initialize_attribute class_initialize_attr {"class_initialize", *this, &test::class_initialize};
    
    // This is the method that is called 1 time after test class run.
    static void class_cleanup_(class_cleanup) {
    }

    // Used class_cleanup_attribute object to register class cleanup method.
    class_cleanup_attribute class_cleanup_attr {"class_cleanup", *this, &test::class_cleanup};

    // This is the method that is called 1 time before test class run.
    static void class_cleanup() {
    }

    // Used test_initialize_attribute object to register test initialize method.
    test_initialize_attribute test_initialize_attr {"test_initialize", *this, &test::test_initialize};
    
    // This is the method that is called before each test case of test fixture.
    static void test_initialize() {
    }

    // Used test_cleanup_attribute object to register test cleanup method.
    test_cleanup_attribute test_cleanup_attr {"test_cleanup", *this, &test::test_cleanup};
   
    // This is the method that is called after each test case of test fixture.
    static void test_cleanup() {
    }

    // Used test_method_attribute object to register test case 1 method.
    test_method_attribute test_case1_attr {"test_case1", *this, &test::test_case1};
    
    // Test case 1
    void test_case1() {
    }

    // Used test_method_attribute object to register test case 2 method.
    test_method_attribute test_case2_attr {"test_case2", *this, &test::test_case2};
    
    // Test case 2
    void test_case2() {
    }

    // Used test_method_attribute object to register and ignore test case 3 method.
    test_method_attribute test_case3_attr {"test_case3", *this, &test::test_case3, test_state::ignored};
    
    // Ignore Test case 3
    void test_case3() {
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

The following example shows how to get current informations with helper :

```c++
#include <xtd/tunit>
#include <iostream>

using namespace std;
using namespace xtd::tunit;

void trace_message(const string& message, const line_info& info) {
  cout << "message: " << message << endl;
  cout << "member name: " << info.member_name() << endl;
  cout << "source file path: " << info.file_path() << endl;
  cout << "source line number: " << info.line_number() << endl;
}

int main() {
  trace_message("Something happened.", line_info_);
}
```

The following example shows how to get same current informations without helper :

```c++
#include <xtd/tunit>
#include <iostream>

using namespace std;
using namespace xtd::tunit;

void trace_message(const string& message, const line_info& info) {
  cout << "message: " << message << endl;
  cout << "member name: " << info.member_name() << endl;
  cout << "source file path: " << info.file_path() << endl;
  cout << "source line number: " << info.line_number() << endl;
}

int main() {
  trace_message("Something happened.", line_info(__func__, __FILE__, __LINE__));
}
```

### More helpers

For each assertion, validation or assumption test, the last parameter is line_info class that contains current informations.
To simplify the code helpers are create.

The following example shows hot to call are_equal assertion tests with helper :

```c++
#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_1) {
      int i = 24;
      assert::are_equal_(24, i);
      assert::are_equal_(24, i, "My message");
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

The following example shows hot to call the same are_equal assertion tests without helper :

```c++
#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_1) {
      int i = 24;
      assert::are_equal(24, i, line_info(__func__, __FILE__, __LINE__));
      assert::are_equal(24, i, "My message", line_info(__func__, __FILE__, __LINE__));
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

## Assertions

## Validations

## Assumptions

## Initialize and Cleanup

## Test case

***Not yet implemented.***

## Test class

Test class or Test fixture...

## Test

## See also

[Documentation](documentation.md)

______________________________________________________________________________________________

© 2019 Gammasoft.
