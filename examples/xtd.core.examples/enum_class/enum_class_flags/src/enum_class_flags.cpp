#include <xtd/xtd>

using namespace xtd;

enum_class_(text_attribute, {
  normal = 0b0,
  bold = 0b1,
  italic = 0b10,
  underline = 0b100,
  strikeout = 0b1000,
});

add_enum_flag_operators_(, text_attribute);

int main() {
  console::write_line("name = {}", text_attribute::bold | text_attribute::italic);
  console::write_line("value = {}", enum_object(text_attribute::bold | text_attribute::italic).to_int32());
  console::write_line("as<int> = {}", as<int>(text_attribute::bold | text_attribute::italic));
  console::write_line("values = {}", enum_object<>::get_values<text_attribute>());
  console::write_line("names = {}", enum_object<>::get_names<text_attribute>());
  console::write("entries = [");
  for (auto entry : enum_object<>::get_entries<text_attribute>()) {
    static auto index = 0;
    console::write("{}({}, {})", index++ == 0 ? "" : ", ", as<int>(entry.first), entry.second);
  }
  console::write_line("]");
}
