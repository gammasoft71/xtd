#include <xtd/xtd>

using namespace xtd;

enum_class_(text_attribute, {
  normal = 0b0,
  bold = 0b1,
  italic = 0b10,
  underline = 0b100,
  strikeout = 0b1000,
});

flags_attribute_(, text_attribute);

int main() {
  console::write_line("name = {}", text_attribute::bold | text_attribute::italic);
  console::write_line("value = {}", enum_object(text_attribute::bold | text_attribute::italic).to_int32());
  console::write_line("as<int> = {}", as<int>(text_attribute::bold | text_attribute::italic));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<text_attribute>());
  console::write_line("names = {}", enum_object<>::get_names<text_attribute>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<text_attribute>());
}
