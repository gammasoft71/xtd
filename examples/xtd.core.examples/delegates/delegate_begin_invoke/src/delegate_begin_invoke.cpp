#include <xtd/xtd>

auto main() -> int {
  auto d1 = delegate<int(const string&)> {[](const string& name) -> int {
    console::write_line("(Thread {}) Hello {}!", thread::current_thread().managed_thread_id(), name);
    return name == "xtd" ? 42 : 24;
  }};
  
  auto result = d1.begin_invoke("Gammasoft");
  console::write_line("return = {}", d1.invoke("xtd"));
  console::write_line("return = {}", d1.end_invoke(result));
}

// This code produces the following output :
//
// (Thread 1) Hello xtd!
// return = 42
// (Thread 4) Hello Gammasoft!
// return = 24
