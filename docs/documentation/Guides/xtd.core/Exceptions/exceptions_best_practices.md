# Best practices for exceptions (xtd.core)

* [Handling exceptions](#handling-exceptions)

Proper exception handling is essential for application reliability. 
You can intentionally handle expected exceptions to prevent your app from crashing. 
However, a crashed app is more reliable and diagnosable than an app with undefined behavior.

This article describes best practices for handling and creating exceptions.

## Handling exceptions

The following best practices concern how you handle exceptions:

* [Use try/catch/finally blocks to recover from errors or release resources](#use-try-catch-blocks-to-recover-from-errors-or-release-resources)
* [Handle common conditions to avoid exceptions](#handle-common-conditions-to-avoid-exceptions)
* [Call Try* methods to avoid exceptions](#call-try-methods-to-avoid-exceptions)
* [Catch cancellation and asynchronous exceptions](#catch-cancellation-and-asynchronous-exceptions)

### Use try/catch blocks to recover from errors or release resources

For code that can potentially generate an exception, and when your app can recover from that exception, use `try/catch` blocks around the code.
In `catch` blocks, always order exceptions from the most derived to the least derived. 
(All exceptions derive from the [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) class. 
More derived exceptions aren't handled by a `catch` clause that's preceded by a `catch` clause for a base exception class.)
When your code can't recover from an exception, don't catch that exception. Enable methods further up the call stack to recover if possible.

Don't forget to clean up allocated resources when an exception is raised. 
Use the [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) idiom for automatic cleanup. 
 
### Handle common conditions to avoid exceptions

For conditions that are likely to occur but might trigger an exception, consider handling them in a way that avoids the exception. 
For example, if you try to close a connection that's already closed, you'll get an `invalid_operation_exception`. 
You can avoid that by using an `if` statement to check the connection state before trying to close it.

```cpp
if (conn.state() != connection_state::closed) {
  conn.close();
}
```

If you don't check the connection state before closing, you can catch the `invalid_operation_exception` exception.

```cpp
try {
  conn.close();
} catch (const invalid_operation_exception& ex) {
  console::write_line(ex.get_type().full_name());
  console::write_line(ex.message());
}
```

The approach to choose depends on how often you expect the event to occur.

* Use exception handling if the event doesn't occur often, that is, if the event is truly exceptional and indicates an error, such as an unexpected end-of-file. When you use exception handling, less code is executed in normal conditions.
* Check for error conditions in code if the event happens routinely and could be considered part of normal execution. When you check for common error conditions, less code is executed because you avoid exceptions.

> **Notes**
> Up-front checks eliminate exceptions most of the time. However, there can be race conditions where the guarded condition changes between the check and the operation, and in that case, you could still incur an exception.

### Call Try* methods to avoid exceptions

If the performance cost of exceptions is prohibitive, some xtd library methods provide alternative forms of error handling. 
For example, [xtd::int32_object::parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box.html#ae719848b746e3df3c3e5755d87a24c6d) throws an [xtd::overflow_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1overflow__exception.html) if the value to be parsed is too large to be represented by [xtd::int32](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga205462e259a4eca1545511085c2c350e).
However, [xtd::int32_object::try_parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1box.html#a45ebbd8f1e23cadfa07d79b2282205ac) doesn't throw this exception. Instead, it returns a boolean and has an `out` parameter that contains the parsed valid integer upon success.
[xd::collections::generic::dictionary<key_t,value_t>::try_get_value](https://gammasoft71.github.io/xtd/reference_guides/latest/group__generic__collections.html#gabc6e9eab3efe7d40c7dd9c3287b36960) has similar behavior for attempting to get a value from a dictionary.

### Catch cancellation and asynchronous exceptions

It's better to catch [xd::operation_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1operation__canceled__exception.html) instead of [xtd::threading::tasks::task_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1tasks_1_1task__canceled__exception.html), which derives from [xd::operation_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1operation__canceled__exception.html), when you call an asynchronous method.
Many asynchronous methods throw an [xd::operation_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1operation__canceled__exception.html) exception if cancellation is requested.
These exceptions enable execution to be efficiently halted and the callstack to be unwound once a cancellation request is observed.

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/exceptions/best-practices-for-exceptions)
