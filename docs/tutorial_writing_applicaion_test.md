| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Writing test applications

## In This Section

* [Namespace](#namespace)
* [Helpers](#helpers)
* [Assertions](#assertions)
* [Validations](#validations)
* [Assumptions](#assumptions)
* [Initialize and Cleanup](#initialize-and-cleanup)
* [Test case](#test-case)
* [Test class](#test-class)
* [Test](#test)

## Namespace

xtd.tunit has a unique namespace : ***xtd::tunit***.

This example show how to use xtd.tunit with using namespace:

```c++
#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    // Test case 1
    void test_method_(test_case1) {
      assert::is_true(2 + 2 == 4);
    }
  };
}


int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```


This example show how to use xtd.tunit without using namespace:

```c++
#include <xtd/tunit>

namespace unit_tests {
  class test_class_(test) {
  public:
    // Test case 1
    void test_method_(test_case1) {
      xtd::tunit::assert::is_true(2 + 2 == 4);
    }
  };
}


int main(int argc, char* argv[]) {
  return xtd::tunit::console_unit_test(argv, argc).run();
}
```

## Helpers

xtd.tunit uses custom helpers to identify test fixtures and test methods. It's the easy way to create tests.

| helpers                                                   | Usage                                                                                                                                    |
|-----------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------|
| [test_class_(class_name)](test_class.md)                  | Is used to define the class (test fixture) with class_name name.                                                                         |
| [class_initialize_(initialize_name)](class_initialize.md) | Is used to define class initialize method with initialize_name name.                                                                     |
| [class_cleanup_(cleanup_name)](class_cleanup.md)          | Is used to define class cleanup method with cleanup_name name.                                                                           |
| [test_initialize_(initialize_name)](test_initialize.md)   | Is used to define test initialize method with initialize_name name.                                                                      |
| [test_cleanup_(cleanup_name)](test_cleanup.md)            | Is used to define test cleanup method with cleanup_name name.                                                                            |
| [test_method_(method_name)](test_method.md)               | Is used to define test method (test case) with method_name name.                                                                         |
| [ignore_test_method_(method_name)](ingore_test_method.md) | Is used to define ignored test method (test case) with method_name name.                                                                 |
| [csf_](csf.md)                                            | Is used to create a xtd::diagnostics::stack_frame class initialized with current method name, current file name and current line number. |

### Examples

The following example shows how to create and register fixture and test cases with helpers :

```c++
#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  // Create new test fixture with test_class_ helper.
  class test_class_(test) {
  public:
    // This method is called 1 time before test class run
    static void class_initialize_(class_initialize) {
    }
    
    // This method is called 1 time after test class run
    static void class_cleanup_(class_cleanup) {
    }
    
    // This method that is called before each test case of test fixture.
    static void test_initialize_(test_initialize) {
    }
    
    // This method is called after each test case of test fixture.
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
    
    // This method is called 1 time before test class run.
    static void class_initialize() {
    }

    // Used class_cleanup_attribute object to register class cleanup method.
    class_cleanup_attribute class_cleanup_attr {"class_cleanup", *this, &test::class_cleanup};

    // This method is called 1 time after test class run.
    static void class_cleanup() {
    }

    // Used test_initialize_attribute object to register test initialize method.
    test_initialize_attribute test_initialize_attr {"test_initialize", *this, &test::test_initialize};
    
    // This method is called before each test case of test fixture.
    static void test_initialize() {
    }

    // Used test_cleanup_attribute object to register test cleanup method.
    test_cleanup_attribute test_cleanup_attr {"test_cleanup", *this, &test::test_cleanup};
   
    // This method that is called after each test case of test fixture.
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

void trace_message(const string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  cout << "message: " << message << endl;
  cout << "member name: " << stack_frame.get_method() << endl;
  cout << "source file path: " << stack_frame.get_file_name() << endl;
  cout << "source line number: " << stack_frame.get_file_line_number() << endl;
}

int main() {
  trace_message("Something happened.", csf_);
}
```

The following example shows how to get same current informations without helper :

```c++
#include <xtd/tunit>
#include <iostream>

using namespace std;
using namespace xtd::tunit;

void trace_message(const string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  cout << "message: " << message << endl;
  cout << "member name: " << stack_frame.get_method() << endl;
  cout << "source file path: " << stack_frame.get_file_name() << endl;
  cout << "source line number: " << stack_frame.get_file_line_number() << endl;
}

int main() {
  trace_message("Something happened.", xtd::diagnostics::stack_frame(__FILE__, __LINE__, __func__));
}
```

### More helpers

For each assertion, validation or assumption test method, the last parameter is xtd::diagnostics::stack_frame class that contains current informations.
To add automatically xtd::diagnostics::stack_frame, helpers are create. Add '_' at the end of test method member to used helper.

example without helper :
```c++
assert::contains('a', str, csf_);
string_valid::are_equal_ignoring_case("value", str, csf_);
```

example with helper :
```c++
assert::contains_('a', str);
string_valid::are_equal_ignoring_case_("value", str);
```

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
      assert::are_equal(24, i, xtd::diagnostics::stack_frame(__FILE__, __LINE__, __func__));
      assert::are_equal(24, i, "My message", xtd::diagnostics::stack_frame(__FILE__, __LINE__, _-func__));
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

#### Remarks

Some functions are template, in this case the template parameter becomes the first parameter of the helper.

example without helper : 

```c++
assert::is_instance_of<std::ios_base>(stream, csf_);
```

example with helper :

```c++
assert::is_instance_of_(std::ios_base, stream);
```

## Assertions

Assertions are central to unit testing in any of the xUnit frameworks, and xtd.tunit is no exception. xtd.tunit provides a rich set of assertions as static methods of the Assert class.

If an assertion fails, the method call does not return and an error is reported. If a test contains multiple assertions, any that follow the one that failed will not be executed. For this reason, it's usually best to try for one assertion per test.

Each method may be called without a message, with a simple text message or with a message and arguments. In the last case the message is formatted using the provided text and arguments.

Assertions make use with the following static classes :

* assert
* string_assert
* collection_assert
* file_assert
* directory_assert.

### Example

```c++
void test_method_(test_case_1) {
  assert::are_equal(4, 2 + 2, csf_);
  string_Assert::start_width("Hello", "Hello, World!", csf_)
}
```

## Validations

Validations are the same as assertions with the difference, no exception is thrown, but an error is generated. 

If a validation fails, he test can be continued to the end or to an assertion is generated.

Validations make use with the following static classes :

* valid
* string_valid
* collection_valid
* file_valid
* directory_valid.

### Example

```c++
void test_method_(test_case_1) {
  valid::are_equal(4, 2 + 2, csf_);
  string_valid::start_width("Hello", "Hello, World!", csf_)
}
```

## Assumptions

Assumptions are intended to express the state a test must be in to provide a meaningful result. They are functionally similar to assertions, however a unmet assumption will produce an aborted test result, as opposed to a failure.

Assumptions make use with the following static classes :

* assume
* string_assume
* collection_assume
* file_assume
* directory_assume.

### Example

```c++
void test_method_(test_case_1) {
  assume::are_equal(4, 2 + 2, csf_);
  string_assume::start_width("Hello", "Hello, World!", csf_)
}
```

## Initialize and Cleanup

Coming soon...

## Test case

Coming soon...

## Test class

Coming soon...

## Test

Coming soon...

## See also

## See also
* [Writing applications](writing_applications.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
