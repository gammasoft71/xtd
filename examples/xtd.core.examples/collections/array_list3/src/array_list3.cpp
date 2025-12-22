#include <xtd/xtd>

auto main() -> int {
  for (auto item : collections::array_list {"42", 42, 12_h + 24_m + 42_s, .42}) {
    console::write("{,-8} --> ", item);
    if (is<string>(item)) console::write_line("{}", as<string>(item).quoted());
    else if (is<int>(item)) console::write_line("0x{:X4}", as<int>(item));
    else if (is<time_span>(item)) console::write_line("{} seconds", as<time_span>(item).seconds());
    else console::write_line("[{}]", item);
  }
}

// This code produces the following output :
//
// 42       --> "42"
// 42       --> 0x002A
// 12:24:42 --> 42 seconds
// 0.42     --> [0.42]
