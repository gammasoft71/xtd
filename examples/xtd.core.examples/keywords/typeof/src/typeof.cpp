#include <xtd/collections/generic/list>
#include <xtd/diagnostics/stopwatch>
#include <xtd/console>
#include <xtd/date_time>
#include <xtd/typeof>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

auto main() -> int {
  console::write_line(typeof_<int>());
  console::write_line(typeof_<std::pair<int, double>>().name());
  console::write_line(typeof_<list<int>>());
  console::write_line(typeof_<date_time>().full_name());
  console::write_line(typeof_<time_span>().name());
  console::write_line();
  console::write_line(typeof_((124 + 26) / 2));
  console::write_line(typeof_(std::make_pair(42, .42)).name());
  console::write_line(typeof_(list {1, 2, 3, 4, 5}));
  console::write_line(typeof_(date_time::now()).full_name());
  console::write_line(typeof_(stopwatch::start_new().elapsed()).name());
}

// This code produces the following output :
//
// int
// pair<int, double>
// xtd::collections::generic::list<int, std::allocator<int>>
// xtd::date_time
// time_span
//
// int
// pair<int, double>
// xtd::collections::generic::list<int, std::allocator<int>>
// xtd::date_time
// time_span
