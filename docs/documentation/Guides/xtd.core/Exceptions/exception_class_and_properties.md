# system exception class and properties (xtd.core)

The [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) class is the base class from which exceptions inherit. 
For example, the [xtd::invalid_cast_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__cast__exception.html) class hierarchy is as follows:

[xtd::object](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html)
  
  [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html)
  
    [xtd::system_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1system__exception.html)
    
      [xtd::invalid_cast_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__cast__exception.html)

The [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) class has the following properties that help make understanding an exception easier.

| Property name | Description |
| ------------- | ----------- |
| [help_link]() | Can hold a URL (or URN) to a help file that provides extensive information about the cause of an exception. |
| [inner_exception]() | This property can be used to create and preserve a series of exceptions during exception handling. You can use it to create a new exception that contains previously caught exceptions. The original exception can be captured by the second exception in the InnerException property, allowing code that handles the second exception to examine the additional information. For example, suppose you have a method that receives an argument that's improperly formatted. The code tries to read the argument, but an exception is thrown. The method catches the exception and throws a FormatException. To improve the caller's ability to determine the reason an exception is thrown, it is sometimes desirable for a method to catch an exception thrown by a helper routine and then throw an exception more indicative of the error that has occurred. A new and more meaningful exception can be created, where the inner exception reference can be set to the original exception. This more meaningful exception can then be thrown to the caller. Note that with this functionality, you can create a series of linked exceptions that ends with the exception that was thrown first. |

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/exceptions/exception-class-and-properties)
