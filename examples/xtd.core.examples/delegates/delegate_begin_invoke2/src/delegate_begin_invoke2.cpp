#include <xtd/xtd>

auto main() -> int {
  console::write_line("(main) thread id = {}", thread::current_thread().managed_thread_id());
  
  auto d1 = delegate<void(int)>([](auto value) {
    console::write_line("(invoker) thread id = {}, value = {}", thread::current_thread().managed_thread_id(), value);
  });
  
  d1(42);
  d1.end_invoke(d1.begin_invoke(24));
  d1.invoke(42);
}

// This code produces the following output :
//
// main) thread id = 1
// (invoker) thread id = 1, value = 42
// (invoker) thread id = 2, value = 24
// (invoker) thread id = 1, value = 42

