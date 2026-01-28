#include <xtd/xtd>

class example {
public:
  static auto main() async_ {
    println("[main], thread {}] -> start", thread::current_thread().managed_thread_id());
    
    auto get_message = delegate<task<string>()> {[] -> task<string> {co_return "Hello, World!";}};
    auto get_size = func<task<size>, string> {[](auto message) -> task<size> {co_return message.length();}};
    
    auto message = co_await get_message();
    auto length = co_await get_size(message);
    
    println("message : {}", message);
    println("length  : {}", length);
    println("[main, thread {}] -> end", thread::current_thread().managed_thread_id());
  }
};

startup_(example::main);

// This code produces the following output :
//
// [main], thread 1] -> start
// message : Hello, World!
// length  : 13
// [main, thread 4] -> end
