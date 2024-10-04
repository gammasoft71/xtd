# How to create user-defined exception (xtd.core)

xtd provides a hierarchy of exception classes ultimately derived from the Exception base class. 
However, if none of the predefined exceptions meet your needs, you can create your own exception class by deriving from the [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) class.

When creating your own exceptions, end the class name of the user-defined exception with the word "_exception", and implement the three common constructors, as shown in the following example. 
The example defines a new exception class named `employee_list_not_found_exception`. The class is derived from the [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) base class and includes three constructors.

```cpp
#include <xtd/exception>

using xtd;

class employee_list_not_found_exception : public exception {
public:
  employee_list_not_found_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception {"The employee list does not exist."_t, stack_frame} {
  }

  employee_list_not_found_exception(const string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception {message, stack_frame} {
  }

  template<typename exception_t>
  employee_list_not_found_exception(const string& message, const exception_t& inner, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(message, inner, stack_frame) {
  }
};
```

> [!NOTE]
> In situations where you're using remoting, you must ensure that the metadata for any user-defined exceptions is available at the server (callee) and to the client (the proxy object or caller). 
> For more information, see [Best practices for exceptions](/docs/documentation/Guides/xtd.core/Exceptions/exceptions_best_practices).

# See also
​
* [Exceptions](/docs/documentation/Guides/xtd.core/Exceptions/overview)
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

© 2024 Gammasoft.

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/exceptions/how-to-create-localized-exception-messages)
