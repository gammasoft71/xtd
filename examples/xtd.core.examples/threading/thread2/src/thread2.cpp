#include <xtd/xtd>

auto main() -> int {
  constexpr auto max_number = 10;
  println("(thread {}) main -> start", thread::current_thread().managed_thread_id());
  auto worker = thread::start_new([&] {
    for (auto count = 1; count <= max_number; ++count) {
      println("  (thread {}) -> count {}", thread::current_thread().managed_thread_id(), count);
      thread::sleep(100_ms);
    }
  });
  println("(thread {}) main -> sleep(200)", thread::current_thread().managed_thread_id());
  thread::sleep(200_ms);
  println("(thread {}) main -> join thread {}", thread::current_thread().managed_thread_id(), worker.managed_thread_id());
  worker.join();
  println("(thread {}) main -> stop", thread::current_thread().managed_thread_id());
}

// This code can produce the following output :
//
// (thread 1) main -> start
// (thread 1) main -> sleep(200)
//   (thread 2) -> count 1
//   (thread 2) -> count 2
// (thread 1) main -> join thread 2
//   (thread 2) -> count 3
//   (thread 2) -> count 4
//   (thread 2) -> count 5
//   (thread 2) -> count 6
//   (thread 2) -> count 7
//   (thread 2) -> count 8
//   (thread 2) -> count 9
//   (thread 2) -> count 10
// (thread 1) -> main stop
