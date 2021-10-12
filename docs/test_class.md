| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Test class (test_class)

This is the inherited class that marks a class that contains tests and, optionally, setup or teardown methods.

Most restrictions on a class that is used as a test fixture have now been eliminated. A test fixture class:

* May be generic, so long as any type parameters are provided or can be inferred from the actual arguments.
* May not be abstract - although the attribute may be applied to an abstract class intended to serve as a base class for test fixtures.
* Only default constructor may be defined.
* Other parametrized constructor can not be defined.

If any of these restrictions are violated, the class is not buildable or runnable as a test and will display as an error.

It is advisable that the constructor not have any side effects, since NUnit may construct the object multiple times in the course of a session.

## Classic test_class

The following examples shows how to register a test class with test_class_ helper:

```c++
#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    // ...
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

## Generic test_class

For generic test_class actually no helper is provided.

The following example show how to register a generic test class without helper:

```c++
#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  template<typename T>
  class test;

  // Register generic test class with 'std:string' as generic parameter.
  test_class_attribute<test<std::string>> test_class_string_attr {"test<string>"};

  // Register generic test class with 'int' as generic parameter.
  test_class_attribute<test<int>> test_class_int_attr {"test<int>"};

  // Create new test fixture inherited test_class.
  template<typename T>
  class test : public test_class {
  public:
    void test_method_(test_case1) {
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

## Inheritance

The test_class may be applied to a base class and is inherited by any derived classes. This includes any abstract base class, so the well-known Abstract Fixture pattern may be implemented if desired.

The following code show how to register a derived class with helper :

```c++
#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class base_test : public test_class {
  public:
    void test_method_(base_test_case1) {
    }
  };
  
  class test_class_from_(test, base_test) {
  public:
    void test_method_(test_case1) {
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
```

## See also

* [Writing test applications](writing_test_applications.md)
* [Writing applications](writing_applications.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
