#include "../../include/xtd/istringable.hpp"
#include "../../include/xtd/string.hpp"

std::ostream& operator <<(std::ostream& os, const xtd::istringable& obj) noexcept {
  return os << obj.to_string();
}
