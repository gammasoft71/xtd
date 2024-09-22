#include "../../include/xtd/istringable.h"
#include "../../include/xtd/string.h"

std::ostream& xtd::operator <<(std::ostream& os, const xtd::istringable& obj) noexcept {
  return os << obj.to_string();
}
