#include "../../include/xtd/as.h"
#include "../../include/xtd/hash_code.h"
#include "../../include/xtd/iformatable.h"
#include "../../include/xtd/invalid_cast_exception.h"
#include "../../include/xtd/object.h"
#include "../../include/xtd/type_object.h"
#include "../../include/xtd/string.h"

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

size_t object::get_hash_code() const noexcept {
  return hash_code::combine(reinterpret_cast<intptr_t>(this));
}

type_object object::get_type() const noexcept {
  return type_object(typeid(*this));
}

string object::to_string() const noexcept {
  if (dynamic_cast<const iformatable*>(this)) return dynamic_cast<const iformatable*>(this)->to_string("", std::locale {});
  return get_type().full_name();
}

void object::__throw_invalid_cast_exception(const string& file, uint32 line, const string& method) const {
  throw invalid_cast_exception {{file, line, method}};
}

std::ostream& xtd::operator <<(std::ostream& os, const object& obj) noexcept {
  return os << obj.to_string();
}

