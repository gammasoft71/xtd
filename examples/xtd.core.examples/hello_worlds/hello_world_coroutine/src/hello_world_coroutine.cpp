#include <xtd/xtd>

#include <xtd/xtd>

class example {
public:
  static auto main() async_ {
    println("[main], thread {}] -> start", thread::current_thread().managed_thread_id());
    
    auto message = co_await get_message();
    auto length = co_await get_size(message);
    
    println("length : {}", length);
    println("[main, thread {}] -> end", thread::current_thread().managed_thread_id());
  }
  
private:
  static auto get_message() -> task<string> {
    co_return "Hello, World!";
  }
  
  static auto get_size(auto message) -> task<size> {
    co_return message.length();
  }
};

startup_(example::main);

// This code produces the following output with colors :
//
// [main], thread 1] -> start
// message : Hello, World!
// length  : 13
// [main, thread 3] -> end
