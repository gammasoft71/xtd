#include <xtd/as>
#include <xtd/console>
#include <xtd/enum_class>

using namespace xtd;

enum class text_attribute {
  normal = 0b0,
  bold = 0b1,
  italic = 0b10,
  underline = 0b100,
  strikeout = 0b1000
};

text_attribute operator|(text_attribute lhs, text_attribute rhs) {return static_cast<text_attribute>(static_cast<std::underlying_type<text_attribute>::type>(lhs) | static_cast<std::underlying_type<text_attribute>::type>(rhs));}

template<> struct xtd::enum_set_attribute<text_attribute> {
  explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
};

template<> struct xtd::enum_register<text_attribute> {
  explicit operator auto() const noexcept {return xtd::enum_collection<text_attribute> {{text_attribute::normal, "normal"}, {text_attribute::bold, "bold"}, {text_attribute::italic, "italic"}, {text_attribute::underline, "underline"}, {text_attribute::strikeout, "strikeout"}};}
};

auto main() -> int {
  console::write_line("name = {}", text_attribute::bold | text_attribute::italic);
  console::write_line("value = {}", enum_object(text_attribute::bold | text_attribute::italic).to_int32());
  console::write_line("as<int> = {}", as<int>(text_attribute::bold | text_attribute::italic));
  console::write_line("values = {}", enum_object<>::get_values_as_int32<text_attribute>());
  console::write_line("names = {}", enum_object<>::get_names<text_attribute>());
  console::write_line("entries = {}", enum_object<>::get_entries_as_int32<text_attribute>());
}
