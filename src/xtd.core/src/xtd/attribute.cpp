#include "../../include/xtd/attribute.h"

using namespace xtd;

xtd::sptr<object> attribute::type_id() const noexcept {
  return get_type_id();
}
