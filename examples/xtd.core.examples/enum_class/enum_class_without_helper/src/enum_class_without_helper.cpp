#include <xtd/xtd>

using namespace xtd;

enum class enum_test {
  value_one,
  value_two,
  value_three,
  value_four
};

template<> struct xtd::enum_register<enum_test> {
  explicit operator auto() const noexcept {return xtd::enum_collection<enum_test> {{enum_test::value_one,  "value_one"}, {enum_test::value_two,  "value_two"}, {enum_test::value_three,  "value_three"}, {enum_test::value_four,  "value_four"}};}
};

int main() {
  console::write_line("name = {}", enum_test::value_four);
  console::write_line("value = {}", enum_object(enum_test::value_four).to_int32());
  console::write_line("as<int> = {}", as<int>(enum_test::value_four));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<enum_test>());
  console::write_line("names = {}", enum_object<>::get_names<enum_test>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<enum_test>());
}
