#include <xtd/xtd>

class example {
public:
  static auto main() async_ {
    println("[main], thread {}] -> start", thread::current_thread().managed_thread_id());
    
    auto message = co_await [] -> task<string> {co_return "Hello, World!";}();
    auto length = co_await [](auto message) -> task<size> {co_return message.length();}(message);
    
    println("length : {}", length);
    println("[main, thread {}] -> end", thread::current_thread().managed_thread_id());
  }
};

startup_(example::main);

// This code produces the following output :
//
// [main], thread 1] -> start
// length : 13
// [main, thread 11] -> end
