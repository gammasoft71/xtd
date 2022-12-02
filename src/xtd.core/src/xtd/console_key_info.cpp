#include "../../include/xtd/console_key_info.h"

using namespace xtd;

console_key_info::console_key_info(char32_t key_char, console_key key, bool shift, bool alt, bool control) noexcept : key_char_(key_char), key_(key) {
  if (shift == true) modifiers_ = (console_modifiers)((int)modifiers_ | (int)console_modifiers::shift);
  if (alt == true) modifiers_ = (console_modifiers)((int)modifiers_ | (int)console_modifiers::alt);
  if (control == true) modifiers_ = (console_modifiers)((int)modifiers_ | (int)console_modifiers::control);
}

bool console_key_info::operator ==(const console_key_info& key_info) const noexcept {
  return key_char_ == key_info.key_char_ && key_ == key_info.key_ && modifiers_ == key_info.modifiers_;
}

bool console_key_info::operator !=(const console_key_info& key_info) const noexcept {
  return !operator ==(key_info);
}

console_key console_key_info::key() const noexcept {
  return key_;
}

char32_t console_key_info::key_char() const noexcept {
  return key_char_;
}

console_modifiers console_key_info::modifiers() const noexcept {
  return modifiers_;
}
