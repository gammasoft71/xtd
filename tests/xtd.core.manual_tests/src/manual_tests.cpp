#include <xtd/xtd>

#undef unused_
#  define unused_ \
  __xtd_unused_concat_(__xtd_no_name_, xtd_unique_id_)


auto main() -> int {
  [[maybe_unused]] auto __ = 42;
  [[maybe_unused]] auto __ = "value string";
  [[maybe_unused]] auto __ = diagnostics::stopwatch::start_new();
  [[maybe_unused]] auto __ = date_time::now();
  
  auto [a, __, b, __] = std::make_tuple(42, "value string", diagnostics::stopwatch::start_new(), date_time::now());
}

// This code produces the following output :
//
// Hello, World!
