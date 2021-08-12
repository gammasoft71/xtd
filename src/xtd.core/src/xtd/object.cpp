#include "../../include/xtd/object.h"
#include "../../include/xtd/ustring.h"

using namespace std;
using namespace xtd;

bool object::equals(const object& obj) const noexcept {
  return this == &obj;
}

bool object::equals(const object& object_a, const object& object_b) noexcept {
  return object_a.equals(object_b);
}

size_t object::get_hash_code() const noexcept {
  return static_cast<size_t>(reinterpret_cast<int64_t>(this) & 0x00000000FFFFFFFF) ^ static_cast<size_t>((reinterpret_cast<int64_t>(this) >> 32) & 0x00000000FFFFFFFF);
}

bool object::reference_equals(const object& object_a, const object& object_b) noexcept {
  return &object_a == &object_b;
}

ustring object::to_string() const noexcept {
  return ustring::full_class_name(*this);
}
