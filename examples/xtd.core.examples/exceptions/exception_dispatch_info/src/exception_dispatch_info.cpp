#include <xtd/xtd>

auto main() -> int {
  auto capture_exception = exception_services::exception_dispatch_info {};
  
  auto thread1 = thread::start_new([&] {
    try {
      throw invalid_operation_exception("Ouch there are an exception !");
    } catch (...) {
      capture_exception = exception_services::exception_dispatch_info::capture();
    }
  });
  thread1.join();
  
  if (capture_exception) {
    try {
      console::write_line("Rethrow the captured exception :");
      capture_exception.rethrow();
    } catch (const exception& e) {
      console::write_line(e);
    }
  }
}

// This code can produce the following output :
//
// Rethrow the captured exception :
// xtd::invalid_operation_exception : Ouch there are an exception !
//    at xtd::invalid_operation_exception::invalid_operation_exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in invalid_operation_exception.cpp:line 10
//    at main::$_0::operator()() const in exception_dispatch_info.cpp:line 8
//    at xtd::threading::thread::thread_proc() in thread.cpp:line 579
//    at xtd::threading::thread::start()::$_0::operator()(long) const in thread.cpp:line 350
//    at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::operator()(void*) const in thread.mm:line 22
//    at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::__invoke(void*) in thread.mm:line 19
//    at _pthread_start
//    at thread_start
