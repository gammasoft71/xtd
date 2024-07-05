#include <xtd/console>
#include <xtd/iasync_result>
#include <xtd/threading/thread>

using namespace xtd;
using namespace xtd::threading;

class async_demo {
public:
  // The method to be executed asynchronously.
  ustring test_method(int call_duration, int* thread_id) {
    console::write_line("Test method begins.");
    thread::sleep(call_duration);
    *thread_id = thread::current_thread().managed_thread_id();
    return ustring::format("My call time was {}.", call_duration);
  }
};

// The delegate must have the same signature as the method
// it will call asynchronously.
using async_method_caller = delegate<ustring(int call_duration, int* thread_id)>;

auto main() -> int {
  // The asynchronous method puts the thread id here.
  auto thread_id = 0;
  
  // Create an instance of the test class.
  auto ad = async_demo {};
  
  // Create the delegate.
  auto caller = async_method_caller {ad, &async_demo::test_method};
  
  // Initiate the asychronous call.
  auto result = caller.begin_invoke(3000, &thread_id);
  
  thread::sleep(0);
  console::write_line("Main thread {} does some work.", thread::current_thread().managed_thread_id());
  
  // Wait for the wait_handle to become signaled.
  result->async_wait_handle().wait_one();
  
  // Perform additional processing here.
  // Call end_invoke to retrieve the results.
  auto return_value = caller.end_invoke(result);
  
  // Close the wait handle.
  result->async_wait_handle().close();
  
  console::write_line("The call executed on thread {}, with return value \"{}\".", thread_id, return_value);
}

// This code produces the following output :
//
// Main thread 1 does some work.
// Test method begins.
// The call executed on thread 2, with return value "My call time was 3000.".
