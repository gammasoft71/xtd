#include <xtd/xtd>

class thread_and_exception_example {
public:
  static auto main() {
    println("start main ({})", thread::current_thread().managed_thread_id());
    scope_exit_ {
      println("end main ({})", thread::current_thread().managed_thread_id());
    };
    
    auto thread1 = thread::start_new([] {
      println("  start thread ({})", thread::current_thread().managed_thread_id());
      throw argument_exception {};
      println("  end thread ({})", thread::current_thread().managed_thread_id());
    });
    thread1.join();
  }
};

startup_(thread_and_exception_example::main);

// This code can produce the following output :
//
// start main (1)
//   start thread (2)
//
// Unhandled exception: xtd::argument_exception : Value does not fall within the expected range.
//    at xtd::argument_exception::argument_exception(xtd::diagnostics::stack_frame const&) in argument_exception.hpp:line 31
//    at thread_and_exception_example::main()::'lambda0'()::operator()() const in thread_and_exception2.cpp:line 13
//    at xtd::threading::thread::thread_proc() in thread.cpp:line 590
//    at xtd::threading::thread::start()::$_0::operator()(long) const in thread.cpp:line 324
//    at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::operator()(void*) const in thread.mm:line 22
//    at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::__invoke(void*) in thread.mm:line 19
//    at _pthread_start
//    at thread_start
// end main (1)
