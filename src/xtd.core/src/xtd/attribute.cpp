#include "../../include/xtd/attribute"

using namespace xtd;

std::shared_ptr<object> attribute::type_id() const noexcept {
  return get_type_id();
}
