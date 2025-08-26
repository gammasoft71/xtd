#include <xtd/xtd>

enum class enum_test {
  value_one,
  value_two,
  value_three,
  value_four
};

template<> struct xtd::enum_register<enum_test> {
  explicit operator auto() const noexcept {return xtd::enum_collection<enum_test> {{enum_test::value_one, "value_one"}, {enum_test::value_two, "value_two"}, {enum_test::value_three, "value_three"}, {enum_test::value_four, "value_four"}};}
};

auto main() -> int {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_int32());
  console::write_line("as<int> = {}", as<int>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<enum_test>());
}

// This code produces the following output :
//
// name = value_four
// value = 3
// as<int> = 3
// values = [0, 1, 2, 3]
// names = [value_one, value_two, value_three, value_four]
// entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
