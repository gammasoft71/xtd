#include <xtd/xtd>

auto main() -> int {
  scope_exit_ {
    println("End application");
  };
  
  println("Start application");
  
  environment::fail_fast("User message.", std::invalid_argument {"This is a test exception for fail_fast."});
}

// This code produces the following output :
//
// Start application
//
// Process terminated.
// User message.
//    at void xtd::environment::fail_fast<std::invalid_argument>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::invalid_argument const&)
//    at main
// std::invalid_argument (Parameter 'This is a test exception for fail_fast.')
