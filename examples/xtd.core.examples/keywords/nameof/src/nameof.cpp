#include <xtd/console>
#include <xtd/nameof>

using namespace xtd;

template<typename value_t>
void print_names(value_t value) {
  auto the_answer_to_life_the_universe_and_everything = value;
  console::write_line("{}", nameof_(print_names));
  console::write_line("{}", nameof_(value_t));
  console::write_line("{} is {}", nameof_(the_answer_to_life_the_universe_and_everything), the_answer_to_life_the_universe_and_everything);
  console::write_line("{} = {}", nameof_((124 + 26) / 2), (124 + 26) / 2);
}

auto main() -> int {
  print_names(42);
}

// This code produces the following output :
//
// print_names
// value_t
// the_answer_to_life_the_universe_and_everything is 42
// (124 + 26) / 2 = 75

