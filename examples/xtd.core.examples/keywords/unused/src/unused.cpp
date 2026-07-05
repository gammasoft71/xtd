#include <xtd/xtd>

struct foo {
  foo() {println("foo constructor");}
};

auto main() -> int {
  // __ is same as C++26 _ (https://cppreference.com/cpp/language/conflicting_declarations#Potentially-conflict_declarations) but for C++20 and later.
  auto __ = 42;
  auto __ = "value string";
  auto __ = diagnostics::stopwatch::start_new();
  auto __ = date_time::now();
  auto __ = foo {};
  // println("value {}", __); // does not build
  
  // unused_ is same as C++26 _ (https://cppreference.com/cpp/language/conflicting_declarations#Potentially-conflict_declarations) but for C++20 and later.
  auto unused_ = 42;
  auto unused_ = "value string";
  auto unused_ = diagnostics::stopwatch::start_new();
  auto unused_ = date_time::now();
  auto unused_ = foo {};
  // println("value {}", unused_); // does not build
}

// This code produces the following output :
//
// foo constructor
// foo constructor
