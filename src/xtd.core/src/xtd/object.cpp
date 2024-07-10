#include "../../include/xtd/as.h"
#include "../../include/xtd/iformatable.h"
#include "../../include/xtd/invalid_cast_exception.h"
#include "../../include/xtd/object.h"
#include "../../include/xtd/type_object.h"
#include "../../include/xtd/ustring.h"

using namespace std;
using namespace xtd;

bool object::equals(const object& obj) const noexcept {
  return equals(*this, obj);
}

bool object::equals(const object& object_a, const object& object_b) noexcept {
  if (dynamic_cast<const iequatable<decltype(object_a)>*>(&object_a)) return dynamic_cast<const iequatable<decltype(object_a)>*>(&object_a)->equals(object_b);
  return &object_a == &object_b;
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
  if (dynamic_cast<const iformatable*>(this)) return dynamic_cast<const iformatable*>(this)->to_string("", std::locale {});
  return get_type().full_name();
}

void object::__throw_invalid_cast_exception(const ustring& file, uint32 line, const ustring& method) const {
  throw invalid_cast_exception {{file, line, method}};
}

std::ostream& xtd::operator <<(std::ostream& os, const object& obj) noexcept {
  return os << obj.to_string();
}

