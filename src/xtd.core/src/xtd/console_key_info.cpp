#include "../../include/xtd/console_key_info.hpp"

using namespace xtd;

console_key_info::console_key_info(char32 key_char, console_key key, bool shift, bool alt, bool control) noexcept : key_char_(key_char), key_(key) {
  if (shift == true) modifiers_ = modifiers_ | console_modifiers::shift;
  if (alt == true) modifiers_ = modifiers_ | console_modifiers::alt;
  if (control == true) modifiers_ = modifiers_ | console_modifiers::control;
}

console_key console_key_info::key() const noexcept {
  return key_;
}

char32 console_key_info::key_char() const noexcept {
  return key_char_;
}

console_modifiers console_key_info::modifiers() const noexcept {
  return modifiers_;
}

bool console_key_info::equals(const object& obj) const noexcept {
  return is<console_key_info>(obj) && equals(static_cast<const console_key_info&>(obj));
}

bool console_key_info::equals(const console_key_info& key_info) const noexcept {
  return key_char_ == key_info.key_char_ && key_ == key_info.key_ && modifiers_ == key_info.modifiers_;
}

size console_key_info::get_hash_code() const noexcept {
  return hash_code::combine(key_char_, key_, modifiers_);
}
