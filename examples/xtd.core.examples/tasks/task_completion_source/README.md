# task_completion_source

Shows how to use [xtd::threading::tasks:task_completion_source](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1tasks_1_1task_1_1completion_1_1source.html) class.

## Sources

* [src/task_completion_source.cpp](src/task_completion_source.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
End with result = 100 and duration = 00:00:01.0064227
(Elapsed time=2430):
The following exceptions have been thrown by t2.result: (THIS WAS EXPECTED)

-------------------------------------------------
xtd::exception : SIMULATED EXCEPTION
   at xtd::exception::exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in exception.cpp:line 33
   at xtd::system_exception::system_exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in system_exception.cpp:line 12
   at xtd::invalid_operation_exception::invalid_operation_exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in invalid_operation_exception.cpp:line 10
   at xtd::invalid_operation_exception::invalid_operation_exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in invalid_operation_exception.cpp:line 10
   at main::$_1::operator()() in task_completion_source.cpp:line 37
   at xtd::threading::tasks::basic_task<void>::data::'lambda'(xtd::any_object const&, bool)::operator()(xtd::any_object const&, bool) const in basic_task.hpp:line 448
   at xtd::threading::thread_pool::thread_item<xtd::delegate<void (xtd::any_object const&, bool)>>::run(bool) in thread_pool.hpp:line 94
   at xtd::threading::thread_pool::asynchronous_io_run() in thread_pool.cpp:line 155
   at xtd::threading::thread::thread_proc() in thread.cpp:line 575
   at xtd::threading::thread::start()::$_0::operator()(long) const in thread.cpp:line 348
   at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::operator()(void*) const in thread.mm:line 22
   at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::__invoke(void*) in thread.mm:line 19
   at _pthread_start
   at thread_start
(Elapsed time=104):
The task_canceled_exception have been thrown by t3.result: (THIS WAS CANCELED)
```
