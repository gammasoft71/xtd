#include "../../include/xtd/as.h"
#include "../../include/xtd/object.h"
#include "../../include/xtd/type_object.h"
#include "../../include/xtd/ustring.h"

using namespace std;
using namespace xtd;

bool object::equals(const object& obj) const noexcept {
  return this == &obj;
}

bool object::equals(const object& object_a, const object& object_b) noexcept {
  return object_a.equals(object_b);
  //return object_a == object_b;
}

size_t object::get_hash_code() const noexcept {
  return as<size_t>(reinterpret_cast<int64>(this) & 0x00000000FFFFFFFF) ^ as<size_t>((reinterpret_cast<int64>(this) >> 32) & 0x00000000FFFFFFFF);
}

type_object object::get_type() const noexcept {
  return type_object(typeid(*this));
}

bool object::reference_equals(const object& object_a, const object& object_b) noexcept {
  return &object_a == &object_b;
}

ustring object::to_string() const noexcept {
  return get_type().full_name();
}

std::ostream& xtd::operator <<(std::ostream& os, const object& obj) noexcept {
  return os << obj.to_string();
}
