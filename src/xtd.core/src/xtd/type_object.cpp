#include "../../include/xtd/type_object.hpp"
#include <cstring>

using namespace xtd;

namespace {
  auto normalize_xtd_type_name(string& name) -> string& {
    if (name.contains("xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>")) name = name.replace("xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>", "xtd::string");
    if (name.contains("xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>")) name = name.replace("xtd::basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>", "xtd::u16string");
    if (name.contains("xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>")) name = name.replace("xtd::basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>", "xtd::u32string");
    if (name.contains("xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>")) name = name.replace("xtd::basic_string<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>", "xtd::u8string");
    if (name.contains("xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>")) name = name.replace("xtd::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>", "xtd::wstring");

    if (name.contains("xtd::text::basic_string_builder<char, std::char_traits<char>, std::allocator<char>>")) name = name.replace("xtd::text::basic_string_builder<char, std::char_traits<char>, std::allocator<char>>", "xtd::text::string_builder");
    if (name.contains("xtd::text::basic_string_builder<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>")) name = name.replace("xtd::text::basic_string_builder<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>", "xtd::text::u16string_builder");
    if (name.contains("xtd::text::basic_string_builder<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>")) name = name.replace("xtd::text::basic_string_builder<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>", "xtd::text::u32string_builder");
    if (name.contains("xtd::text::basic_string_builder<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>")) name = name.replace("xtd::text::basic_string_builder<char8_t, std::char_traits<char8_t>, std::allocator<char8_t>>", "xtd::text::u8string_builder");
    if (name.contains("xtd::text::basic_string_builder<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>")) name = name.replace("xtd::text::basic_string_builder<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>", "xtd::text::wstring_builder");

    if ((name.contains("xtd::span<") || name.contains("xtd::read_only_span<")) && name.contains(", 18446744073709551615ul>")) name = name.replace(", 18446744073709551615ul>", ", xtd::dynamic_extent>");
    return name;
  }
}

type_object::type_object() noexcept : type_(typeid(*this)) {
}

type_object::type_object(const type& type) noexcept : type_(type) {
}

type_object& type_object::operator=(const type_object& value) noexcept {
  memcpy(reinterpret_cast<void*>(const_cast<type*>(&type_)), reinterpret_cast<void*>(const_cast<type*>(&value.type_)), sizeof(value.type_));
  return *this;
}

string type_object::full_name() const noexcept {
  auto name = string::demangle(type_.name());
  return normalize_xtd_type_name(name);
}

string type_object::name() const noexcept {
  auto full_name = this->full_name();
  auto length = full_name.index_of("<");
  if (length == string::npos) length = full_name.length();
  if (full_name.last_index_of("::", 0, length) == string::npos) return full_name;
  return full_name.substring(full_name.last_index_of("::", 0, length) + 2);
}

string type_object::namespace_() const noexcept {
  auto full_name = this->full_name();
  auto length = full_name.index_of("<");
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

usize type_object::get_hash_code() const noexcept {
  return hash_code::combine(full_name());
}

string type_object::to_string() const noexcept {
  return full_name();
}
