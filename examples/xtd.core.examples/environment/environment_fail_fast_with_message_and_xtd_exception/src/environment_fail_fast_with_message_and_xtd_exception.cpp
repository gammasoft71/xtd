#include <xtd/xtd>

auto main() -> int {
  scope_exit_ {
    println("End application");
  };
  
  println("Start application");
  
  environment::fail_fast("User message.", argument_out_of_range_exception {"This is a test exception for fail_fast."});
}

// This code produces the following output :
//
// Start application
//
// Process terminated.
// User message.
//    at void xtd::environment::fail_fast<xtd::argument_out_of_range_exception>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::argument_out_of_range_exception const&)
//    at main
// xtd::argument_out_of_range_exception: Specified argument is out of range of valid values. (Parameter 'This is a test exception for FailFast.')
