#include "../../include/xtd/istringable.h"
#include "../../include/xtd/ustring.h"

std::ostream& xtd::operator <<(std::ostream& os, const xtd::istringable& obj) {
  return os << obj.to_string();
}
