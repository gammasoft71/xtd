# exception_ptr

Shows how to use std::exception_ptr and [invalid_operation_exception](../../../../src/xtd.core/include/xtd/invalid_operation_exception.h) exception.

## Sources

[src/exception_ptr.cpp](src/exception_ptr.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Exception occured :
-------------------
xtd::invalid_operation_exception : Ouch there are an exception !
   at main::$_0::operator()() const [0x0000C1F0] in /|---OMITTED---|/exception_ptr/src/exception_ptr.cpp:line 13
   at decltype(std::__1::forward<main::$_0>(fp)()) std::__1::__invoke<main::$_0>(main::$_0&&) [0x0000C180] in /|---OMITTED---|/exception_ptr/Debug/exception_ptr:line 0
   at void std::__1::__thread_execute<std::__1::unique_ptr<std::__1::__thread_struct, std::__1::default_delete<std::__1::__thread_struct> >, main::$_0>(std::__1::tuple<std::__1::unique_ptr<std::__1::__thread_struct, std::__1::default_delete<std::__1::__thread_struct> >, main::$_0>&, std::__1::__tuple_indices<>) [0x0000C0E0] in /|---OMITTED---|/exception_ptr/Debug/exception_ptr:line 0
   at void* std::__1::__thread_proxy<std::__1::tuple<std::__1::unique_ptr<std::__1::__thread_struct, std::__1::default_delete<std::__1::__thread_struct> >, main::$_0> >(void*) [0x0000B8E0] in /|---OMITTED---|/exception_ptr/Debug/exception_ptr:line 0
   at _pthread_start [0x000060D8] in /usr/lib/system/introspection/libsystem_pthread.dylib:line 0
```
