#include <xtd/xtd>

struct foo {
  foo() {println("foo constructor");}
};

auto main() -> int {
  // __ is same as C++26 _ (https://cppreference.com/cpp/language/conflicting_declarations#Potentially-conflict_declarations) but for C++20 and later.
  [[maybe_unused]] auto __ = 42;
  [[maybe_unused]] auto __ = "value string";
  auto __ = diagnostics::stopwatch::start_new();
  auto __ = date_time::now();
  auto __ = foo {};
  auto [i1, __, chrono1, __, f1] = std::make_tuple(42, "value string", diagnostics::stopwatch::start_new(), date_time::now(), foo {});
  // println("value {}", __); // does not build
}

// This code produces the following output :
//
// foo constructor
// foo constructor
