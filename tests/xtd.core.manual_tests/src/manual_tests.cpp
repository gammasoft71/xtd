#include <xtd/xtd>

auto main() -> int {
#if __cplusplus > 202302L
  // Since C++26
  auto _ = 42;
  auto _ = "value string";
  auto _ = diagnostics::stopwatch::start_new();
  auto _ = date_time::now();
  // println("value {}", _); // does not build
#else
  // Since C++20 with xtd
  auto __ = 42;
  auto __ = "value string";
  auto __ = diagnostics::stopwatch::start_new();
  auto __ = date_time::now();
  // or
  auto unused_ = 42;
  auto unused_ = "value string";
  auto unused_ = diagnostics::stopwatch::start_new();
  auto unused_ = date_time::now();
  // println("value {}", __); // does not build
#endif
}

// This code produces the following output :
//
// Hello, World!
