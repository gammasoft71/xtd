#include <xtd/xtd>

auto main_async() -> task<> {
  println("[main], thread {}] -> start", thread::current_thread().managed_thread_id());
  
  auto message = co_await [] -> task<string> {co_return "Hello, World!";}();
  //auto length = co_await [](auto message) -> task<xtd::size> {co_return message.length();}(message);
  auto length = co_await [](const string& m) -> task<string> {co_return m;}(message);
  
  println("message : {}", message);
  println("length  : {}", length);
  println("[main, thread {}] -> end", thread::current_thread().managed_thread_id());
};

auto main() -> int {
  main_async().wait();
  thread_pool::join_all();
}

// This code produces the following output :
//
// 
