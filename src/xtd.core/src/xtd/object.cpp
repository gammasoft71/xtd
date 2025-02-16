#include "../../include/xtd/as.hpp"
#include "../../include/xtd/hash_code.hpp"
#include "../../include/xtd/iformatable.hpp"
#include "../../include/xtd/invalid_cast_exception.hpp"
#include "../../include/xtd/object.hpp"
#include "../../include/xtd/type_object.hpp"
#include "../../include/xtd/string.hpp"

using namespace xtd;
using namespace xtd::collections::generic;

bool object::operator ==(const object& obj) const noexcept {
  return equals(obj);
}

bool object::operator !=(const object& obj) const noexcept {
  return !operator==(obj);
}

bool object::equals(const object& obj) const noexcept {
  return reference_equals(*this, obj);
}

size object::get_hash_code() const noexcept {
  return hash_code::combine(reinterpret_cast<intptr_t>(this));
}

type_object object::get_type() const noexcept {
  return type_object(typeid(*this));
}

string object::to_string() const noexcept {
  if (dynamic_cast<const iformatable*>(this)) return dynamic_cast<const iformatable*>(this)->to_string("", std::locale {});
  return get_type().full_name();
}

std::ostream& operator <<(std::ostream& os, const object& obj) noexcept {
  return os << obj.to_string();
}

std::string __object_to_string__(const xtd::object& obj) {
  return obj.to_string();
}
