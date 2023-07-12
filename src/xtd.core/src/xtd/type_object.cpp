#include "../../include/xtd/type_object.h"
#include <cstring>

using namespace xtd;

type_object::type_object() noexcept : type_(typeid(*this)) {
}

type_object::type_object(const xtd::type& type) noexcept : type_(type) {
}

type_object& type_object::operator=(const type_object& value) noexcept {
  memcpy(reinterpret_cast<void*>(const_cast<xtd::type*>(&type_)), reinterpret_cast<void*>(const_cast<xtd::type*>(&value.type_)), sizeof(value.type_));
  return *this;
}

xtd::ustring type_object::full_name() const noexcept {
  return ustring::demangle(type_.name());
}

xtd::ustring type_object::name() const noexcept {
  auto full_name = this->full_name();
  auto length = full_name.last_index_of("<");
  if (length == ustring::npos) length = full_name.length();
  if (full_name.last_index_of("::", 0, length) == ustring::npos) return full_name;
  return full_name.substring(full_name.last_index_of("::", 0, length) + 2);
}

xtd::ustring type_object::namespace_() const noexcept {
  auto full_name = this->full_name();
  auto length = full_name.last_index_of("<");
  if (length == ustring::npos) length = full_name.length();
  if (full_name.last_index_of("::", 0, length) == ustring::npos) return full_name;
  return full_name.remove(full_name.last_index_of("::", 0, length));
}

bool type_object::equals(const type_object& type) const noexcept {
  return type_ == type.type_;
}

xtd::ustring type_object::to_string() const noexcept {
  return full_name();
}
