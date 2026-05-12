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
    
    if (name.contains("xtd::read_only_span<") && name.contains(", 18446744073709551615ul>")) name = name.replace(", 18446744073709551615ul>", ", xtd::dynamic_extent>");
    if (name.contains("xtd::span<") && name.contains(", 18446744073709551615ul>")) name = name.replace(", 18446744073709551615ul>", ", xtd::dynamic_extent>");
    
    if (name.contains("xtd::collections::generic::ordered_dictionary<xtd::any_object, xtd::any_object, std::allocator<std::pair<xtd::any_object const, xtd::any_object>>>")) name = name.replace("xtd::collections::generic::ordered_dictionary<xtd::any_object, xtd::any_object, std::allocator<std::pair<xtd::any_object const, xtd::any_object>>>", "xtd::collections::specialized::ordered_dictionary");
    if (name.contains("xtd::collections::generic::list<xtd::string, std::allocator<xtd::string>>")) name = name.replace("xtd::collections::generic::list<xtd::string, std::allocator<xtd::string>>", "xtd::collections::specialized::string_collection");
    if (name.contains("xtd::collections::generic::dictionary<xtd::string, xtd::string, xtd::collections::generic::helpers::hasher<xtd::string>, xtd::collections::generic::helpers::equator<xtd::string>, std::allocator<std::pair<xtd::string const, xtd::string>>>")) name = name.replace("xtd::collections::generic::dictionary<xtd::string, xtd::string, xtd::collections::generic::helpers::hasher<xtd::string>, xtd::collections::generic::helpers::equator<xtd::string>, std::allocator<std::pair<xtd::string const, xtd::string>>>", "xtd::collections::specialized::string_dictionary");
    if (name.contains("xtd::collections::generic::key_value_pair<xtd::string, xtd::string>")) name = name.replace("xtd::collections::generic::key_value_pair<xtd::string, xtd::string>", "xtd::collections::specialized::string_key_value_pair");

    if (name.contains("xtd::collections::generic::list<xtd::any_object, std::allocator<xtd::any_object>>")) name = name.replace("xtd::collections::generic::list<xtd::any_object, std::allocator<xtd::any_object>>", "xtd::collections::array_list");
    if (name.contains("xtd::collections::generic::comparer<xtd::any_object>")) name = name.replace("xtd::collections::generic::comparer<xtd::any_object>", "xtd::collections::comparer");
    if (name.contains("xtd::collections::generic::key_value_pair<xtd::any_object, xtd::any_object>")) name = name.replace("xtd::collections::generic::key_value_pair<xtd::any_object, xtd::any_object>", "xtd::collections::dictionary_entry");
    if (name.contains("xtd::collections::generic::enumerator<xtd::any_object>")) name = name.replace("xtd::collections::generic::enumerator<xtd::any_object>", "xtd::collections::enumerator");
    if (name.contains("xtd::collections::generic::dictionary<xtd::any_object, xtd::any_object, xtd::collections::generic::helpers::hasher<xtd::any_object>, xtd::collections::generic::helpers::equator<xtd::any_object>, std::allocator<std::pair<xtd::any_object const, xtd::any_object>>>")) name = name.replace("xtd::collections::generic::dictionary<xtd::any_object, xtd::any_object, xtd::collections::generic::helpers::hasher<xtd::any_object>, xtd::collections::generic::helpers::equator<xtd::any_object>, std::allocator<std::pair<xtd::any_object const, xtd::any_object>>>", "xtd::collections::hashtable");
    if (name.contains("xtd::collections::generic::icollection<xtd::any_object>")) name = name.replace("xtd::collections::generic::icollection<xtd::any_object>", "xtd::collections::icollection");
    if (name.contains("xtd::collections::generic::icomparer<xtd::any_object>")) name = name.replace("xtd::collections::generic::icomparer<xtd::any_object>", "xtd::collections::icomparer");
    if (name.contains("xtd::collections::generic::idictionary<xtd::any_object, xtd::any_object>")) name = name.replace("xtd::collections::generic::idictionary<xtd::any_object, xtd::any_object>", "xtd::collections::idictionary");
    if (name.contains("xtd::collections::generic::ienumerable<xtd::any_object>")) name = name.replace("xtd::collections::generic::ienumerable<xtd::any_object>", "xtd::collections::ienumerable");
    if (name.contains("xtd::collections::generic::ienumerator<xtd::any_object>")) name = name.replace("xtd::collections::generic::ienumerator<xtd::any_object>", "xtd::collections::ienumerator");
    if (name.contains("xtd::collections::generic::iequality_comparer<xtd::any_object>")) name = name.replace("xtd::collections::generic::iequality_comparer<xtd::any_object>", "xtd::collections::iequality_comparer");
    if (name.contains("xtd::collections::generic::ilist<xtd::any_object>")) name = name.replace("xtd::collections::generic::ilist<xtd::any_object>", "xtd::collections::ilist");
    if (name.contains("xtd::collections::generic::queue<xtd::any_object, std::deque<xtd::any_object, std::allocator<xtd::any_object>>>")) name = name.replace("xtd::collections::generic::queue<xtd::any_object, std::deque<xtd::any_object, std::allocator<xtd::any_object>>>", "xtd::collections::queue");
    if (name.contains("xtd::collections::generic::sorted_list<xtd::any_object, std::allocator<xtd::any_object>>")) name = name.replace("xtd::collections::generic::list<xtd::any_object, std::allocator<xtd::any_object>>", "xtd::collections::sorted_list");
    if (name.contains("xtd::collections::generic::stack<xtd::any_object, std::deque<xtd::any_object, std::allocator<xtd::any_object>>>")) name = name.replace("xtd::collections::generic::stack<xtd::any_object, std::deque<xtd::any_object, std::allocator<xtd::any_object>>>", "xtd::collections::stack");
    
    if (name.contains("xtd::collections::generic::sorted_dictionary<xtd::string, xtd::web::css::property>")) name = name.replace("xtd::collections::generic::sorted_dictionary<xtd::string, xtd::web::css::property>", "xtd::web::css::property_dictionary");
    
    return name;
  }
}

type_object::type_object() noexcept : type_ {new_ptr<ref<const type>>(typeid(*this))} {
}

type_object::type_object(const type& t) noexcept : type_ {new_ptr<ref<const type>>(t)} {
}

auto type_object::full_name() const noexcept -> string {
  auto name = string::demangle(type_->get().name());
  return normalize_xtd_type_name(name);
}

auto type_object::name() const noexcept -> string {
  auto name = full_name();
  auto length = name.index_of("<");
  if (length == string::npos) length = name.length();
  if (name.last_index_of("::", 0, length) == string::npos) return name;
  return name.substring(name.last_index_of("::", 0, length) + 2);
}

auto type_object::namespace_() const noexcept -> string {
  auto name = full_name();
  auto length = name.index_of("<");
  if (length == string::npos) length = name.length();
  if (name.last_index_of("::", 0, length) == string::npos) return "";
  return name.remove(name.last_index_of("::", 0, length));
}

auto type_object::equals(const object& obj) const noexcept -> bool {
  return is<type_object>(obj) && equals(static_cast<const type_object&>(obj));
}

auto type_object::equals(const type_object& type) const noexcept -> bool {
  return *type_ == *type.type_;
}

auto type_object::get_hash_code() const noexcept -> usize {
  return hash_code::combine(full_name());
}

auto type_object::to_string() const noexcept -> string {
  return full_name();
}
