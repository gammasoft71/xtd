#include "../../include/xtd/iformatable.hpp"
#include "../../include/xtd/string.hpp"
#include "../../include/xtd/globalization/culture_info.hpp"

auto operator << (std::ostream& os, const xtd::iformatable& value) -> std::ostream& {
  return os << value.to_string("", xtd::globalization::culture_info::current_culture());
}
