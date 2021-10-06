| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Using Standard Exception Types

This section describes the standard exceptions provided by the Framework and the details of their usage. The list is by no means exhaustive. Please refer to the xtd Framework reference documentation for usage of other Framework exception types.

# Exception and SystemException

**❌ DO NOT** throw xtd::system_exception.

**❌ DO NOT** catch xtd::system_exception in framework code, unless you intend to rethrow.

**❌ AVOID** catching xtd::system_exception, except in top-level exception handlers.

# application_exception

**❌ DO NOT** throw or derive from xtd::application_exception.

# invalid_operation_exception

**✔️ DO** throw an xtd::invalid_operation_exception if the object is in an inappropriate state.

# argument_exception, argument_null_exception, and argument_out_of_range_exception

**✔️ DO** throw xtd::argument_exception or one of its subtypes if bad arguments are passed to a member. Prefer the most derived exception type, if applicable.

**✔️ DO** set the param_name property when throwing one of the subclasses of argument_exception.

This property represents the name of the parameter that caused the exception to be thrown. Note that the property can be set using one of the constructor overloads.

**✔️ DO** use value for the name of the implicit value parameter of property setters.

# null_pointer_exception, index_out_of_range_exception, and access_violation_exception

**❌ DO NOT** allow publicly callable APIs to explicitly or implicitly throw xtd::null_pointer_exception, xtd::access_violation_exception, or xtd::index_out_of_range_exception. These exceptions are reserved and thrown by the execution engine and in most cases indicate a bug.

Do argument checking to avoid throwing these exceptions. Throwing these exceptions exposes implementation details of your method that might change over time.

# stack_overflow_exception

**❌ DO NOT** explicitly throw xtd::stack_overflow_exception. The exception should be explicitly thrown only by the Operating System.

**❌ DO NOT** catch xtd::stack_overflow_exception.

It is almost impossible to write code that remains consistent in the presence of arbitrary stack overflows.

# out_of_memory_exception

**❌ DO NOT** explicitly throw xtd::out_of_memory_exception. This exception is to be thrown only by the xtd infrastructure.

# com_exception, seh_exception, and execution_engine_exception

**❌ DO NOT** explicitly throw xtd::com_exception, xtd::execution_engine_exception, and xtd::seh_exception. These exceptions are to be thrown only by the xtd infrastructure.

# See also
​
* [Design Guidelines for Exception](design_guidelines_for_exception.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
