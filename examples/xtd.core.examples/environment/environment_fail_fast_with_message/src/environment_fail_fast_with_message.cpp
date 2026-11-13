#include <xtd/xtd>

auto main() -> int {
  scope_exit_ {
    println("End application");
  };
  
  println("Start application");
  
  environment::fail_fast("User message.");
}

// This code produces the following output :
//
// Start application
//
// Process terminated.
// User message.
//    at xtd::environment::fail_fast(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)
//    at main
