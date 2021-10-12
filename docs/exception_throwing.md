| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Exception Throwing

Exception-throwing guidelines described in this section require a good definition of the meaning of execution failure. Execution failure occurs whenever a member cannot do what it was designed to do (what the member name implies). For example, if the open_file method cannot return an opened file handle to the caller, it would be considered an execution failure.

Most developers have become comfortable using exceptions for errors such as division by zero or null references. In the Framework, exceptions are used for all error conditions, including execution errors.

**❌ DO NOT** return error codes.

Exceptions are the primary means of reporting errors in frameworks.

**✔️ DO** report execution failures by throwing exceptions.

**❌ DO NOT** use exceptions for the normal flow of control, if possible.

Except for system failures and operations with potential race conditions, framework designers should design APIs so users can write code that does not throw exceptions. For example, you can provide a way to check preconditions before calling a member so users can write code that does not throw exceptions.

The member used to check preconditions of another member is often referred to as a tester, and the member that actually does the work is called a doer.

There are cases when the *Tester-Doer* Pattern can have an unacceptable performance overhead. In such cases, the so-called *Try-Parse* Pattern should be considered (see [Exceptions and Performance](exceptions_and_performance.m) for more information).

**✔️ CONSIDER** the performance implications of throwing exceptions. Throw rates above 100 per second are likely to noticeably impact the performance of most applications.

**✔️ DO** document all exceptions thrown by publicly callable members because of a violation of the member contract (rather than a system failure) and treat them as part of your contract.

Exceptions that are a part of the contract should not change from one version to the next (i.e., exception type should not change, and new exceptions should not be added).

**❌ DO NOT** have public members that can either throw or not based on some option.

**❌ DO NOT** have public members that return exceptions as the return value or a ref parameter.

Returning exceptions from public APIs instead of throwing them defeats many of the benefits of exception-based error reporting.

**✔️ CONSIDER** using exception builder methods.

It is common to throw the same exception from different places. To avoid code bloat, use helper methods that create exceptions and initialize their properties.

Also, members that throw exceptions are not getting inlined. Moving the throw statement inside the builder might allow the member to be inlined.

**❌ DO NOT** throw exceptions from exception filter blocks.

# See also
​
* [Design Guidelines for Exception](design_guidelines_for_exception.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
