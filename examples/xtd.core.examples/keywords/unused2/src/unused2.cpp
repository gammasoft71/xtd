#include <xtd/xtd>

struct foo {
  foo() {println("foo constructor");}
};

auto main() -> int {
  // unused_ is same as C++26 _ (https://cppreference.com/cpp/language/conflicting_declarations#Potentially-conflict_declarations) but for C++20 and later.
  [[maybe_unused]] auto unused_ = 42;
  [[maybe_unused]] auto unused_ = "value string";
  auto unused_ = diagnostics::stopwatch::start_new();
  auto unused_ = date_time::now();
  auto unused_ = foo {};
  auto [i2, unused_, chrono2, unused_, f2] = std::make_tuple(42, "value string", diagnostics::stopwatch::start_new(), date_time::now(), foo {});
  // println("value {}", unused_); // does not build
}

// This code produces the following output :
//
// foo constructor
// foo constructor
