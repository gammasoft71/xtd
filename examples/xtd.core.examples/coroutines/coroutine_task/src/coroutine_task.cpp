#include <xtd/xtd>

class example {
public:
  static auto main() async_ {
    println("[main], thread {}] -> start", thread::current_thread().managed_thread_id());
    
    auto message = co_await task<string>::run([] {return "Hello, World!";});
    auto length = co_await task<size>::run([](const any_object& message) {return as<string>(message).size();}, message);
    
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
// [main, thread 8] -> end
