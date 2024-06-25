#include <xtd/threading/jthread>
#include <xtd/block_scope>
#include <xtd/console>

using namespace xtd;
using namespace xtd::threading;

int main() {
  auto thread_proc = [] {
    thread::current_thread().name("thread_proc");
    for (auto index = 0; index < 10; ++index, thread::sleep(100_ms))
      console::write_line("  ({}) index = {}", thread::current_thread().name(), index);
  };
  
  thread::current_thread().name("main");
  console::write_line("({}) begin", thread::current_thread().name());
  block_scope_(auto thread1 = jthread::start_new(thread_proc)) {
    // Remarks :
    // * The `thread1` will be joined when the scope of the current block is closed.
    // * If you create `thread1` with xtd::threading::thread, `thread1` will be joined when the end of main.
    // * If you create `thread1` with std::jthread, `thread1` will be joined when the scope of the current block is closed too.
    // * If you create `thread1` with std::thread, there will be a runtime error.
    // You can try it yourself to see the different scenarios.
  }
  console::write_line("({}) end", thread::current_thread().name());
}

// This code can produce the following output if `thread1` is created with xtd::threading::jthread :
//
// (main) begin
//   (thread_proc) index = 0
//   (thread_proc) index = 1
//   (thread_proc) index = 2
//   (thread_proc) index = 3
//   (thread_proc) index = 4
//   (thread_proc) index = 5
//   (thread_proc) index = 6
//   (thread_proc) index = 7
//   (thread_proc) index = 8
//   (thread_proc) index = 9
// (main) end

// This code can produce the following output if `thread1` is created with xtd::threading::thread :
//
// (main) begin
// (main) end
//   (thread_proc) index = 0
//   (thread_proc) index = 1
//   (thread_proc) index = 2
//   (thread_proc) index = 3
//   (thread_proc) index = 4
//   (thread_proc) index = 5
//   (thread_proc) index = 6
//   (thread_proc) index = 7
//   (thread_proc) index = 8
//   (thread_proc) index = 9

// This code can produce the following output if `thread1` is created with std::jthread :
//
// (main) begin
//   (thread_proc) index = 0
//   (thread_proc) index = 1
//   (thread_proc) index = 2
//   (thread_proc) index = 3
//   (thread_proc) index = 4
//   (thread_proc) index = 5
//   (thread_proc) index = 6
//   (thread_proc) index = 7
//   (thread_proc) index = 8
//   (thread_proc) index = 9
// (main) end

// This code can produce the following output if `thread1` is created std::thread :
//
// (main) begin
// libc++abi: terminating
