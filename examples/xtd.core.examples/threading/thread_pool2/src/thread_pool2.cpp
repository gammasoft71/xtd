#include <xtd/xtd>

auto main() -> int {
  thread::main_thread().name("Thread Main");
  constexpr auto max_number = 10;
  println("({} {}) -> start", thread::current_thread().name(), thread::current_thread().managed_thread_id());
  thread_pool::queue_user_work_item([&] {
    for (auto count = 1; count <= max_number; ++count) {
      println("  ({} {}) -> count {}", thread::current_thread().name(), thread::current_thread().managed_thread_id(), count);
      thread::sleep(100_ms);
    }
  });
  println("({} {}) -> sleep(200_ms)", thread::current_thread().name(), thread::current_thread().managed_thread_id());
  thread::sleep(200_ms);
  println("({} {}) -> join all threads of thread_pool", thread::current_thread().name(), thread::current_thread().managed_thread_id());
  thread_pool::join_all();
  println("({} {}) -> stop", thread::current_thread().name(), thread::current_thread().managed_thread_id());
}

// This code can produce the following output :
//
// (Thread Main 1) -> start
// (Thread Main 1) -> sleep(200)
//   (Thread Pool 5) -> count 1
//   (Thread Pool 5) -> count 2
// (Thread Main 1) -> join all threads of thread_pool
//   (Thread Pool 5) -> count 3
//   (Thread Pool 5) -> count 4
//   (Thread Pool 5) -> count 5
//   (Thread Pool 5) -> count 6
//   (Thread Pool 5) -> count 7
//   (Thread Pool 5) -> count 8
//   (Thread Pool 5) -> count 9
//   (Thread Pool 5) -> count 10
// (Thread Main 1) -> stop
