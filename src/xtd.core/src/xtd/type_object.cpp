#include "../../include/xtd/type_object.hpp"
#include <cstring>

using namespace xtd;

type_object::type_object() noexcept : type_(typeid(*this)) {
}

type_object::type_object(const type& type) noexcept : type_(type) {
}

type_object& type_object::operator=(const type_object& value) noexcept {
  memcpy(reinterpret_cast<void*>(const_cast<type*>(&type_)), reinterpret_cast<void*>(const_cast<type*>(&value.type_)), sizeof(value.type_));
  return *this;
}

string type_object::full_name() const noexcept {
  return string::demangle(type_.name());
}

string type_object::name() const noexcept {
  auto full_name = this->full_name();
  auto length = full_name.last_index_of("<");
  if (length == string::npos) length = full_name.length();
  if (full_name.last_index_of("::", 0, length) == string::npos) return full_name;
  return full_name.substring(full_name.last_index_of("::", 0, length) + 2);
}

string type_object::namespace_() const noexcept {
  auto full_name = this->full_name();
  auto length = full_name.last_index_of("<");
  if (length == string::npos) length = full_name.length();
  if (full_name.last_index_of("::", 0, length) == string::npos) return full_name;
  return full_name.remove(full_name.last_index_of("::", 0, length));
}

bool type_object::equals(const object& obj) const noexcept {
  return is<type_object>(obj) && equals(static_cast<const type_object&>(obj));
}

bool type_object::equals(const type_object& type) const noexcept {
  return type_ == type.type_;
}

size type_object::get_hash_code() const noexcept {
  return hash_code::combine(full_name());
}

string type_object::to_string() const noexcept {
  return full_name();
}
