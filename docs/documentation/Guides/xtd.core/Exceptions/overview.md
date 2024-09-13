# Exceptions

## Overview

Applications must be able to handle errors that occur during execution in a consistent manner. 
xtd provides a model for notifying applications of errors in a uniform way: xtd operations indicate failure by throwing exceptions.

## Exceptions

An exception is any error condition or unexpected behavior that is encountered by an executing program.
Exceptions can be thrown because of a fault in your code or in code that you call (such as a shared library), unavailable operating system resources, unexpected conditions that the runtime encounters (such as code that can't be verified), and so on.
Your application can recover from some of these conditions, but not from others. Although you can recover from most application exceptions, you can't recover from most runtime exceptions.

In xtd, an exception is an object that inherits from the [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) class. 
An exception is thrown from an area of code where a problem has occurred. The exception is passed up the stack until the application handles it or the program terminates.

## Exceptions vs. traditional error-handling methods

Traditionally, the C++ error handling model has relied either on the language's own way of detecting and handling errors, or on the error handling mechanism provided by the operating system.
The way xtd implements exception handling provides the following advantages:

* Throwing and exception handling work in the same way for xtd as for C++.
* Requires no special syntax for exception handling: xtd relies entirely on C++ syntax.
* Exceptions can be thrown across process and even machine boundaries.
* Exception-handling code can be added to an application to increase program reliability.

Exceptions offer advantages over other methods of error notification, such as return codes.
Failures don't go unnoticed because if an exception is thrown and you don't handle it, the runtime terminates your application.
Invalid values don't continue to propagate through the system as a result of code that fails to check for a failure return code.

## Common exceptions

The following table lists some common exceptions with examples of what can cause them.

| Exception type                                                                                                                                         | Description                                                        | Example                                                                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------ | --------------------------------------------------------------------------------------- |
| [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html)                                                 | Base class for all exceptions.                                     | None (use a derived class of this exception).                                           |
| [xtd::index_out_of_range_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1index__out__of__range__exception.html)       | Thrown by methods when an array is indexed improperly.             | Indexing an array outside its valid range: `arr[arr.length() + 1]`                      |
| [xtd::null_pointer_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1null__pointer__exception.html)                     | Thrown by methods when a null object pointer is accessed.          | `const char* ptr = null; xtd::text::string_builder str {v};`                            |
| [xtd::invalid_operation_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__operation__exception.html)           | Thrown by methods when in an invalid state.                        | Calling `enumerator.move_next()` after removing an item from the underlying collection. |
| [xtd::argument_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__exception.html)                              | Base class for all argument exceptions.                            | None (use a derived class of this exception).                                           |
| [xtd::argument_null_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__null__exception.html)                   | Thrown by methods that do not allow an argument to be null.        | `byte* buffer = null; random {}.next_bytes(buffer, 10);`                                |
| [xtd::argument_out_of_range_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html) | Thrown by methods that verify that arguments are in a given range. | `string s = "string"; s.substring(s.length() + 1);`                                     |

The [exceptions](https://gammasoft71.github.io/xtd/reference_guides/latest/group__exceptions.html) category contains all xtd exceptions definitions.

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
