#include <xtd/xtd>

auto main() -> int {
  scope_exit_ {
    println("End application");
  };
  
  println("Start application");
  
  environment::fail_fast();
}

// This code produces the following output :
//
// Start application
//
// Process terminated.
//    at xtd::environment::fail_fast()
//    at main
