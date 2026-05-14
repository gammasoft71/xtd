#include <xtd/xtd>

// Demonstrated features:
//     task_completion_source ctor()
//     task_completion_source::set_result()
//     task_completion_source::set_exception()
//     Task.Result
// Expected results:
//     The attempt to get t1.result blocks for ~1000ms until tcs1 gets signaled. 15 is printed out.
//     The attempt to get t2.result blocks for ~1000ms until tcs2 gets signaled. An exception is printed out.
auto main() -> int {
  auto tcs1 = task_completion_source<int> {};
  auto t1 = tcs1.task();
  
  // Start a background task that will complete tcs1.Task
  auto tf = task_factory {}.start_new([tcs1] mutable {
    thread::sleep(1000);
    tcs1.set_result(15);
  });
  
  // The attempt to get the result of t1 blocks the current thread until the completion source gets signaled.
  // It should be a wait of ~1000 ms.
  auto sw = diagnostics::stopwatch::start_new();
  auto result = t1.result();
  sw.stop();
  println("(Elapsed time={}): t1.result={} (expected 15) ", sw.elapsed_milliseconds(), result);
  
  // ------------------------------------------------------------------
  
  // Alternatively, an exception can be manually set on a task_completion_source::task
  auto tcs2 = task_completion_source<int> {};
  auto t2 = tcs2.task();
  
  // Start a background Task that will complete tcs2.task with an exception
  tf = task_factory {}.start_new([tcs2] mutable {
    thread::sleep(1000);
    tcs2.set_exception(invalid_operation_exception("SIMULATED EXCEPTION"));
  });
  
  sw = diagnostics::stopwatch::start_new();
  try {
    result = t2.result();
    console::write_line("t2.result succeeded. THIS WAS NOT EXPECTED.");
  } catch (const exception& e) {
    console::write_line("(Elapsed time={}): ", sw.elapsed_milliseconds());
    console::write_line("The following exceptions have been thrown by t2.result: (THIS WAS EXPECTED)");
    console::write_line("\n-------------------------------------------------\n{}", e.to_string());
  }
  
  // ------------------------------------------------------------------
  
  // Alternatively, a cancellation can be manually set on a task_completion_source::task
  auto tcs3 = task_completion_source<int> {};
  auto t3 = tcs3.task();
  
  // Start a background Task that will complete tcs2.task with an exception
  tf = task_factory {}.start_new([tcs3] mutable {
    tcs3.set_canceled();
    thread::sleep(1000);
    tcs3.set_result(45);
  });
  
  sw = diagnostics::stopwatch::start_new();
  try {
    result = t3.result();
    console::write_line("t3.result succeeded. THIS WAS NOT CANCELD.");
  } catch (const task_canceled_exception& e) {
    console::write_line("(Elapsed time={}): ", sw.elapsed_milliseconds());
    console::write_line("The task_canceled_exception have been thrown by t3.result: (THIS WAS CANCELED)");
  }
}

// This code produces the following output :
//
// End with result = 100 and duration = 00:00:01.0064227
// (Elapsed time=2430):
// The following exceptions have been thrown by t2.result: (THIS WAS EXPECTED)
//
// -------------------------------------------------
// xtd::exception : SIMULATED EXCEPTION
//    at xtd::exception::exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in exception.cpp:line 33
//    at xtd::system_exception::system_exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in system_exception.cpp:line 12
//    at xtd::invalid_operation_exception::invalid_operation_exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in invalid_operation_exception.cpp:line 10
//    at xtd::invalid_operation_exception::invalid_operation_exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in invalid_operation_exception.cpp:line 10
//    at main::$_1::operator()() in task_completion_source.cpp:line 37
//    at xtd::threading::tasks::basic_task<void>::data::'lambda'(xtd::any_object const&, bool)::operator()(xtd::any_object const&, bool) const in basic_task.hpp:line 448
//    at xtd::threading::thread_pool::thread_item<xtd::delegate<void (xtd::any_object const&, bool)>>::run(bool) in thread_pool.hpp:line 94
//    at xtd::threading::thread_pool::asynchronous_io_run() in thread_pool.cpp:line 155
//    at xtd::threading::thread::thread_proc() in thread.cpp:line 575
//    at xtd::threading::thread::start()::$_0::operator()(long) const in thread.cpp:line 348
//    at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::operator()(void*) const in thread.mm:line 22
//    at xtd::native::thread::create(std::__1::function<void (long)>, long, int, bool, long&)::$_0::__invoke(void*) in thread.mm:line 19
//    at _pthread_start
//    at thread_start
// (Elapsed time=104):
// The task_canceled_exception have been thrown by t3.result: (THIS WAS CANCELED)
