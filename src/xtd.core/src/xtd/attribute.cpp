#include "../../include/xtd/attribute.h"

using namespace xtd;

std::shared_ptr<object> attribute::type_id() const noexcept {
  return get_type_id();
}
