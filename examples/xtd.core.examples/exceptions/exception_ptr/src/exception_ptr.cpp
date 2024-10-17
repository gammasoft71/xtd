#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/invalid_operation_exception>

using namespace xtd;
using namespace xtd::threading;

auto main() -> int {
  auto exception_pointer = std::exception_ptr {};
  
  auto thread1 = thread {[&] {
    try {
      throw invalid_operation_exception("Ouch there are an exception !");
    } catch (...) {
      exception_pointer = std::current_exception();
    }
  }};
  
  thread1.start();
  thread1.join();
  
  if (exception_pointer) {
    try {
      rethrow_exception(exception_pointer);
    } catch (const system_exception& e) {
      console::write_line(e);
    }
  }
}

// This code can produce the following output :
//
// xtd::invalid_operation_exception : Ouch there are an exception !
//    at main::$_0::operator()() const [0x0000C1F0] in /|---OMITTED---|/exception_ptr/src/exception_ptr.cpp:line 13
//    at decltype(std::forward<main::$_0>(fp)()) std::__invoke<main::$_0>(main::$_0&&) [0x0000C180] in /|---OMITTED---|/exception_ptr/Debug/exception_ptr:line 0
//    at void std::__thread_execute<std::unique_ptr<std::__thread_struct, std::default_delete<std::__thread_struct> >, main::$_0>(std::tuple<std::unique_ptr<std::__thread_struct, std::default_delete<std::__thread_struct> >, main::$_0>&, std::__tuple_indices<>) [0x0000C0E0] in /|---OMITTED---|/exception_ptr/Debug/exception_ptr:line 0
//    at void* std::__thread_proxy<std::tuple<std::unique_ptr<std::__thread_struct, std::default_delete<std::__thread_struct> >, main::$_0> >(void*) [0x0000B8E0] in /|---OMITTED---|/exception_ptr/Debug/exception_ptr:line 0
//    at _pthread_start [0x000060D8] in /usr/lib/system/introspection/libsystem_pthread.dylib:line 0
