# Best practices for exceptions (xtd.core)

* [Handling exceptions](#handling-exceptions)
* [Throwing exceptions](#throwing-exceptions)
* [Custom exception types](#custom-exception-types)

Proper exception handling is essential for application reliability. 
You can intentionally handle expected exceptions to prevent your app from crashing. 
However, a crashed app is more reliable and diagnosable than an app with undefined behavior.

This article describes best practices for handling and creating exceptions.

## Handling exceptions

The following best practices concern how you handle exceptions:

* [Use try/catch/finally blocks to recover from errors or release resources](#use-trycatch-blocks-to-recover-from-errors-or-release-resources)
* [Handle common conditions to avoid exceptions](#handle-common-conditions-to-avoid-exceptions)
* [Call Try* methods to avoid exceptions](#call-try-methods-to-avoid-exceptions)
* [Catch cancellation and asynchronous exceptions](#catch-cancellation-and-asynchronous-exceptions)
* [Design classes so that exceptions can be avoided](#design-classes-so-that-exceptions-can-be-avoided)
* [Restore state when methods don't complete due to exceptions](#restore-state-when-methods-dont-complete-due-to-exceptions)
* [Capture and rethrow exceptions properly](#capture-and-rethrow-exceptions-properly)

### Use try/catch blocks to recover from errors or release resources

For code that can potentially generate an exception, and when your app can recover from that exception, use `try/catch` blocks around the code.
In `catch` blocks, always order exceptions from the most derived to the least derived. 
(All exceptions derive from the [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) class. 
More derived exceptions aren't handled by a `catch` clause that's preceded by a `catch` clause for a base exception class.)
When your code can't recover from an exception, don't catch that exception. Enable methods further up the call stack to recover if possible.

Don't forget to clean up allocated resources when an exception is raised. 
Use the [RAII](https://en.cppreference.com/w/cpp/language/raii) idiom for automatic cleanup. 
 
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
[`xd::collections::generic::dictionary<key_t,value_t>::try_get_value`](https://gammasoft71.github.io/xtd/reference_guides/latest/group__generic__collections.html#gabc6e9eab3efe7d40c7dd9c3287b36960) has similar behavior for attempting to get a value from a dictionary.

### Catch cancellation and asynchronous exceptions

It's better to catch [xd::operation_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1operation__canceled__exception.html) instead of [xtd::threading::tasks::task_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1tasks_1_1task__canceled__exception.html), which derives from [xd::operation_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1operation__canceled__exception.html), when you call an asynchronous method.
Many asynchronous methods throw an [xd::operation_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1operation__canceled__exception.html) exception if cancellation is requested.
These exceptions enable execution to be efficiently halted and the callstack to be unwound once a cancellation request is observed.

### Design classes so that exceptions can be avoided

A class can provide methods or properties that enable you to avoid making a call that would trigger an exception.
For example, the xtd:collections::generic::list class provides methods that help determine the number of items.
You can call these methods to avoid the exception that is thrown if you try to access an element outside the range.

The following example shows how to access list itemsd without triggering an exception:

```cpp
class program {
public:
  // Sums up a list of items using the specified initial value without throwing an exception.
  static constexpr int accumulate(const list<int>& items, int init_value = 0) noexcept {
    int result = init_value;
    // Accesses all elements in the element list using the xtd::collections::generic::list::size method to prevent accessing an element outside the list range.
    for (xtd::size index = 0; index < items.size(); ++index)
      result += items[index];
    return result;
  }
};
```

It is also advisable to add the `noexcept` attribute to the method to guarantee the user that the method will not throw an exception.

### Restore state when methods don't complete due to exceptions

Callers should be able to assume that there are no side effects when an exception is thrown from a method. 
For example, if you have code that transfers money by withdrawing from one account and depositing in another account, and an exception is thrown while executing the deposit, you don't want the withdrawal to remain in effect.

```cpp
static void transfer_funds(account& from, &ccount& to, decimal amount) noexcept {
  from.withdrawal(amount);
  // If the deposit fails, the withdrawal shouldn't remain in effect.
  to.deposit(amount);
}
```

The preceding method doesn't directly throw any exceptions. However, you must write the method so that the withdrawal is reversed if the deposit operation fails.

One way to handle this situation is to catch any exceptions thrown by the deposit transaction and roll back the withdrawal.

```cpp
static void transfer_funds(account& from, account& to, decimal amount) noexcept {
  string withdrawal_trx_id = from.withdrawal(amount);
  try {
    to.deposit(amount);
  } catch (...) {
    from.rollback_transaction(withdrawal_trx_id);
    throw;
  }
}
```

This example illustrates the use of throw to rethrow the original exception, making it easier for callers to see the real cause of the problem without having to examine the [inner_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html#ad05d51d23eeffcdfd0d86d6668514384) property.
An alternative is to throw a new exception and include the original exception as the inner exception.


```cpp
static void transfer_funds(account& from, account& to, decimal amount) noexcept {
  string withdrawal_trx_id = from.withdrawal(amount);
  try {
    to.deposit(amount);
  } catch (const exception& ex) {
    from.rollback_transaction(withdrawal_trx_id);
    throw transfer_funds_exception("Withdrawal failed.", ex);
  }
}
```

### Capture and rethrow exceptions properly

Once an exception is thrown, part of the information it carries is the stack trace.
The stack trace is a list of the method call hierarchy that starts with the method that throws the exception and ends with the method that catches the exception.
If you rethrow an exception by specifying the exception in the `throw` statement, for example, `throw e`, the stack trace is restarted at the current method and the list of method calls between the original method that threw the exception and the current method is lost.
To keep the original stack trace information with the exception, there are two options that depend on where you're rethrowing the exception from:

* If you rethrow the exception from within the handler (`catch` block) that's caught the exception instance, use the throw statement without specifying the exception.
* If you're rethrowing the exception from somewhere other than the handler (`catch` block), use [xtd::runtime::exception_services::exception_dispatch_info::capture(const xtd:exception&)](javascript:void(0)) to capture the exception in the handler and [xtd::runtime::exception_services::exception_dispatch_info::rerhrow()](javascript:void(0)) when you want to rethrow it. You can use the [xtd::runtime::exception_services::exception_dispatch_info::source_exception](javascript:void(0)) property to inspect the captured exception.

The following example shows how the [xtd::runtime::exception_services::exception_dispatch_info](javascript:void(0)) class can be used, and what the output might look like.

```cpp
auto edi = exception_dispatch_info {};
try {
  auto txt = file::read_all_text("C:\\temp\\file.txt");
} catch (const file_not_found_exception& e) {
  edi = exception_dispatch_info::capture(e);
}

// ...

console::write_line("I was here.");

if (edi.exception_captured())
  edi.rethrow();
```

If the file in the example code doesn't exist, the following output is produced:

```
I was here.

Unhandled exception: xtd::io::file_not_found_exception : Unable to find the specified file.
   at xtd::io::file::read_all_text [0x0000037C] in C:\Users\yves\Projects\xtd\src\xtd.core\src\xtd\io\file.cpp:line 225
   at xtd_console_app::program::main [0x00000080] in C:\Users\yves\Projects\xtd_console_app\xtd_console_app\src\program.cpp:line 12
   at xtd::startup::run [0x000000A0] in C:\Users\yves\Projects\xtd\src\xtd.core\src\xtd\startup.cpp:line 157
   at xtd::startup::internal_safe_run<void (__cdecl*)(xtd::collections::generic::list<xtd::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<xtd::basic_string<char,std::char_traits<char>,std::allocator<char> > > > const &)> [0x000000F8] in C:\Users\yves\Projects\xtd\src\xtd.core\include\xtd\startup.h:line 105
   at xtd::startup::safe_run [0x0000009C] in C:\Users\yves\Projects\xtd\src\xtd.core\src\xtd\startup.cpp:line 70
   at main [0x0000003C] in C:\Users\yves\Projects\xtd_console_app\xtd_console_app\properties\startup.cpp:line 10
```

## Throwing exceptions

The following best practices concern how you throw exceptions:

* [Use predefined exception types](#use-predefined-exception-types)
* [Use exception builder methods](#use-exception-builder-methods)
* [Include a localized string message](#include-a-localized-string-message)
* [Use proper grammar](#use-proper-grammar)
* [Place throw statements well](#place-throw-statements-well)
* [Don't raise exceptions in noexcept methods](#dont-raise-exceptions-in-noexcept-methods)
* [Throw argument validation exceptions synchronously](#throw-argument-validation-exceptions-synchronously)

### Use predefined exception types

Introduce a new exception class only when a predefined one doesn't apply. For example:

* If a property set or method call isn't appropriate given the object's current state, throw an [xtd::invalid_operation_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__operation__exception.html) exception.
* If invalid parameters are passed, throw an [xtd::argument_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__exception.html) exception or one of the predefined classes that derive from [xtd::argument_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__exception.html).

> **Notes**
> While it's best to use predefined exception types when possible, you shouldn't raise some reserved exception types, such as [xtd::access_violation_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1access__violation__exception.html), [xtd::index_out_of_range_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1index__out__of__range__exception.html), and [xtd::null_pointer_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1null__pointer__exception.html). See [exceptions](https://gammasoft71.github.io/xtd/reference_guides/latest/group__exceptions.html) to view all xtd exceptions.

### Use exception builder methods

It's common for a class to throw the same exception from different places in its implementation. 
To avoid excessive code, create a helper method that creates the exception and returns it.
For example:

```cpp
class file_reader {
public:
  file_reader(const string& path) noexcept : file_name_ {path} {}

  optional<array<byte>> read(int bytes) {
    optional<array<byte>> results = file_utils.read_from_file(file_name_, bytes);
    if (!results) throw file_reader_exception();
    return results;
  }

  static file_io_exception file_reader_exception() noexcept {
    string description = "My file_reader_exception description";
    return file_io_exception {description};
  }

private:
  string file_name_;
};
```

Some key xtd exception types have such static throw helper methods that allocate and throw the exception. 
You should call these methods instead of constructing and throwing the corresponding exception type:

* [xtd::argument_null_exception::throw_if_null](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__null__exception.html#a2238e664c08b9a214361494544a9dee7)
* [xtd::argument_exception::throw_if_empty](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__exception.html#aa904822ef2bb340d8b5ac44d4c452b32)
* [xtd::argument_exception::throw_if_empty_or_white_space](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__exception.html#a73af69f77f9705387150935434a8e709)
* [xtd::argument_out_of_range_exception::throw_if_zero](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#a2882385050c42bf510bec42ee8177983)
* [xtd::argument_out_of_range_exception::throw_if_negative](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#aaef683b1532f1016a2aae21836a486ed)
* [xtd::argument_out_of_range_exception::throw_if_positive](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#a0ca0b3dd187796f1b2bb03846d73c5b5)
* [xtd::argument_out_of_range_exception::throw_if_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#a84bda1e0473c5515ee86b869c33db9d8)
* [xtd::argument_out_of_range_exception::throw_if_less_than](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#a2a631cb65cbd57eebe3b2330af3aeda1)
* [xtd::argument_out_of_range_exception::throw_if_not_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#a8c0a02040287a3142ca095b11fade612)
* [xtd::argument_out_of_range_exception::throw_if_negative_or_zero](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#a4fd301574e5c0e079ba93a0ca7d69d50)
* [xtd::argument_out_of_range_exception::throw_if_positive_or_zero](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#a4dbf51ceefb8e881778ce0fa26baf2d7)
* [xtd::argument_out_of_range_exception::throw_if_greater_than](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#ab46390f7974712fd8f942ba36b63faaf)
* [xtd::argument_out_of_range_exception::throw_if_less_than_or_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#a120e488fa6378121a110404733282f98)
* [xtd::argument_out_of_range_exception::throw_if_greater_than_or_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html#a665d7e453ad6aab6cc61f182a4906e3b)

If you're implementing an asynchronous method, call [xtd::threading::cancellation_token::throw_if_cancellation_requested()](javascript:void(0)) instead of checking if cancellation was requested and then constructing and throwing [operation_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1operation__canceled__exception.html).

### Include a localized string message

The error message the user sees is derived from the [xtd::exception::message](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html#a472b56575bd47dbd829931c900a16600) property of the exception that was thrown, and not from the name of the exception class. 
Typically, you assign a value to the [xtd::exception::message](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html#a472b56575bd47dbd829931c900a16600) property by passing the message string to the message argument of an [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) constructor.

For localized applications, you should provide a localized message string for every exception that your application can throw. 
You use `locale` files to provide localized error messages.
For information on localizing applications and retrieving localized strings, see the following article:

* [Internationalization](/docs/documentation/guides/xtd.core/globalization/internationalization)

### Use proper grammar

Write clear sentences and include ending punctuation. 
Each sentence in the string assigned to the [xtd::exception::message](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html#a472b56575bd47dbd829931c900a16600) property should end in a period. 
For example, "The log table has overflowed." uses correct grammar and punctuation.

### Place throw statements well

Place throw statements where the stack trace will be helpful.
The stack trace begins at the statement where the exception is thrown and ends at the catch statement that catches the exception.

### Don't raise exceptions in noexcept methods

Don't raise exceptions in noexcept methods. For example:

```cpp
void the_method() noexcept {
  throw argument_exception {}; // Error because you specify to the user that the_method has no exception, yet you throw an exception.
}
```

### Throw argument validation exceptions synchronously

In task-returning methods, you should validate arguments and throw any corresponding exceptions, such as [xtd::argument_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__exception.html) and [xtd::argument_null_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__null__exception.html), before entering the asynchronous part of the method. 
Exceptions that are thrown in the asynchronous part of the method are stored in the returned task and don't emerge until, for example, the task is awaited.

## Custom exception types

The following best practices concern custom exception types:

* [End exception class names with `_exception`](#end-exception-class-names-with-_exception)
* [Include three constructors](#include-three-constructors)
* [Provide additional properties as needed](#provide-additional-properties-as-needed)

### End exception class names with `_exception`

When a custom exception is necessary, name it appropriately and derive it from the [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html) class. For example:

```cpp
class my_file_not_found_exception : public xtd::exception {

};
```

### Include three constructors

Use at least the three common constructors when creating your own exception classes: the parameterless constructor, a constructor that takes a string message, and a constructor that takes a string message and an inner exception.

  * [xtd::exception(const xtd::diagnostics::stack_frame &information=xtd::diagnostics::stack_frame::empty())](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html#a292b8c4b43580256fdb1513113a20fca), which uses default values and optional stack frame.
  * [xtd::exception(const xtd::string &message, const xtd::diagnostics::stack_frame &information=xtd::diagnostics::stack_frame::empty())](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html#ad43693d8a3723ec0b995123b2d14a297), which accepts a string message and optional stack frame.
  * [xtd::exception(const xtd::string &message, const std::exception &inner_exception, const xtd::diagnostics::stack_frame &information=xtd::diagnostics::stack_frame::empty())](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html#a946c0dec93a72997929197b1699e7040), which accepts a string message, an inner exception and optional stack frame.

For an example, see [How to: Create user-defined exceptions](/docs/documentation/guides/xtd.core/Exceptions/how_tos/create_user_defined_exceptions).

### Provide additional properties as needed

Provide additional properties for an exception (in addition to the custom message string) only when there's a programmatic scenario where the additional information is useful.
For example, the [xtd::io::file_not_found_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__not__found__exception.html) provides the [file_name](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__not__found__exception.html#a7cd16d6b427a9f14245ad77bcc19b4eb) property.

# See also
​
* [Exceptions](/docs/documentation/guides/xtd.core/Exceptions/overview)
* [Guides](/docs/documentation/guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/exceptions/best-practices-for-exceptions)
