# thread_and_exception2

Demonstrates how to use [xtd::threading::thread](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread.html) class with exception.

## Sources

* [src/thread_and_exception2.cpp](src/thread_and_exception2.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
start main (1)
  start thread (2)

Unhandled exception: xtd::argument_exception : Value does not fall within the expected range.
   at xtd::argument_exception::argument_exception(xtd::diagnostics::stack_frame const&) in argument_exception.hpp:line 31
   at thread_and_exception_example::main()::'lambda0'()::operator()() const in thread_and_exception2.cpp:line 13
   at xtd::threading::thread::thread_proc() in thread.cpp:line 590
   at xtd::threading::thread::start()::$_0::operator()(long) const in thread.cpp:line 324
   at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::operator()(void*) const in thread.mm:line 22
   at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::__invoke(void*) in thread.mm:line 19
   at _pthread_start
   at thread_start
end main (1)
```
