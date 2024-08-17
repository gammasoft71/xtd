#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../include/xtd/string.h"
#include "../../include/xtd/typeof.h"
#include "../../include/xtd/argument_exception.h"
#include "../../include/xtd/convert_string.h"
#include "../../include/xtd/format_exception.h"
#include "../../include/xtd/hash_code.h"
#include "../../include/xtd/is.h"
#include "../../include/xtd/null_pointer_exception.h"
//#include "../../include/xtd/collections/generic/hasher.h"
#include "../../include/xtd/diagnostics/stack_frame.h"
#include <iomanip>

using namespace xtd;
using namespace xtd::collections::generic;

const string string::empty_string;

const std::vector<string::value_type> string::default_split_separators {9, 10, 11, 12, 13, 32};
const std::vector<string::value_type> string::default_trim_chars {string::default_split_separators};

string::string() noexcept {
}

string::string(const allocator_type& allocator) noexcept : basic_string<value_type>(allocator) {
}

string::string(xtd::size count, value_type character) : basic_string<value_type>(count, character) {
}

string::string(xtd::size count, value_type character, const allocator_type& allocator) : basic_string<value_type>(count, character, allocator) {
}

#if defined(__xtd__cpp_lib_char8_t)
string::string(xtd::size count, char8 character) : basic_string<value_type>(count, static_cast<value_type>(character)) {
}

string::string(xtd::size count, char8 character, const allocator_type& allocator) : basic_string<value_type>(count, static_cast<value_type>(character), allocator) {
}
#endif

string::string(xtd::size count, char16 character) {
  *this = convert_string::to_ustring(std::u16string(count, character));
}

string::string(xtd::size count, char16 character, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  *this = convert_string::to_ustring(std::u16string(count, character));
}

string::string(xtd::size count, char32 character) {
  *this = convert_string::to_ustring(std::u32string(count, character));
}

string::string(xtd::size count, char32 character, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  *this = convert_string::to_ustring(std::u32string(count, character));
}

string::string(xtd::size count, wchar character) {
  *this = convert_string::to_ustring(std::wstring(count, character));
}

string::string(xtd::size count, wchar character, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  *this = convert_string::to_ustring(std::wstring(count, character));
}

string::string(const string& str, xtd::size index, xtd::size count) : basic_string<value_type>(str, index, count) {
}

string::string(const string& str, xtd::size index, xtd::size count, const allocator_type& allocator) : basic_string<value_type>(str, index, count, allocator) {
}

string::string(const string& str, xtd::size index) : basic_string<value_type>(str, index) {
}

string::string(const string& str, xtd::size index, const allocator_type& allocator) : basic_string<value_type>(str, index, allocator) {
}

string::string(const value_type* str, xtd::size count) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(str, count);
}

string::string(const value_type* str, xtd::size count, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(str, count);
}

string::string(const value_type* str) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(str);
}

string::string(const value_type* str, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(str);
}

string::string(value_type* str) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(str);
}

string::string(value_type* str, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(str);
}

string::string(const string& str) noexcept : basic_string<value_type>(str) {
}

string::string(const string& str, const allocator_type& allocator) noexcept : basic_string<value_type>(str, allocator) {
}

string::string(const std::string& str) noexcept : basic_string<value_type>(str) {
}

string::string(const std::string& str, const allocator_type& allocator) noexcept : basic_string<value_type>(reinterpret_cast<const value_type*>(str.c_str()), allocator) {
}

#if defined(__xtd__cpp_lib_char8_t)
string::string(const std::u8string& str) noexcept : basic_string<value_type>(reinterpret_cast<const value_type*>(str.c_str())) {
}

string::string(const std::u8string& str, const allocator_type& allocator) noexcept : basic_string<value_type>(reinterpret_cast<const value_type*>(str.c_str()), allocator) {
}

string::string(const char8* str) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(reinterpret_cast<const value_type*>(str));
}

string::string(const char8* str, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(reinterpret_cast<const value_type*>(str));
}

string::string(char8* str) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(reinterpret_cast<value_type*>(str));
}

string::string(char8* str, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(reinterpret_cast<value_type*>(str));
}
#endif

string::string(const std::u16string& str) noexcept : string(str, allocator_type()) {
}

string::string(const std::u16string& str, const allocator_type& allocator) noexcept : basic_string<value_type>(allocator) {
  *this = convert_string::to_ustring(str);
}

string::string(const char16* str) {
  *this = str;
}

string::string(const char16* str, const allocator_type& allocator) : string(allocator) {
  *this = str;
}

string::string(char16* str) {
  *this = str;
}

string::string(char16* str, const allocator_type& allocator) : string(allocator) {
  *this = str;
}

string::string(const std::u32string& str) noexcept : string(str, allocator_type()) {
}

string::string(const std::u32string& str, const allocator_type& allocator) noexcept : basic_string<value_type>(allocator) {
  *this = convert_string::to_ustring(str);
}

string::string(const char32* str) {
  *this = str;
}

string::string(const char32* str, const allocator_type& allocator) : string(allocator) {
  *this = str;
}

string::string(char32* str) {
  *this = str;
}

string::string(char32* str, const allocator_type& allocator) : string(allocator) {
  *this = str;
}

string::string(const std::wstring& str) noexcept : string(str, allocator_type()) {
}

string::string(const std::wstring& str, const allocator_type& allocator) noexcept : basic_string<value_type>(allocator) {
  *this = convert_string::to_ustring(str);
}

string::string(const wchar* str) {
  *this = str;
}

string::string(const wchar* str, const allocator_type& allocator) : string(allocator) {
  *this = str;
}

string::string(wchar* str) {
  *this = str;
}

string::string(wchar* str, const allocator_type& allocator) : string(allocator) {
  *this = str;
}

string::string(string&& str) noexcept : basic_string<value_type>(str) {
}

string::string(string&& str, const allocator_type& allocator) noexcept : basic_string<value_type>(str, allocator) {
}

string::string(std::initializer_list<value_type> il) : basic_string<value_type>(il) {
}

string::string(std::initializer_list<value_type> il, const allocator_type& allocator) : basic_string<value_type>(il, allocator) {
}

#if defined(__xtd__cpp_lib_char8_t)
string::string(std::initializer_list<char8> il) {
  for (auto& c : il)
    push_back(static_cast<value_type>(c));
}

string::string(std::initializer_list<char8> il, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  for (auto& c : il)
    push_back(static_cast<value_type>(c));
}
#endif

string::string(std::initializer_list<char16> il) {
  *this = convert_string::to_ustring(std::u16string(il));
}

string::string(std::initializer_list<char16> il, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  *this = convert_string::to_ustring(std::u16string(il));
}

string::string(std::initializer_list<char32> il) {
  *this = convert_string::to_ustring(std::u32string(il));
}

string::string(std::initializer_list<char32> il, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  *this = convert_string::to_ustring(std::u32string(il));
}

string::string(std::initializer_list<wchar> il) {
  *this = convert_string::to_ustring(std::wstring(il));
}

string::string(std::initializer_list<wchar> il, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  *this = convert_string::to_ustring(std::wstring(il));
}

string& string::operator =(const string& str) noexcept {
  assign(str);
  return *this;
}

string& string::operator =(const std::string& str) noexcept {
  assign(str.c_str());
  return *this;
}

string& string::operator =(const value_type* str) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(str);
  return *this;
}

#if defined(__xtd__cpp_lib_char8_t)
string& string::operator =(const std::u8string& str) noexcept {
  assign(reinterpret_cast<const value_type*>(str.c_str()));
  return *this;
}

string& string::operator =(const char8* str) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  assign(reinterpret_cast<const value_type*>(str));
  return *this;
}
#endif

string& string::operator =(const std::u16string& str) noexcept {
  *this = convert_string::to_ustring(str);
  return *this;
}

string& string::operator =(const char16* str) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  return operator =(std::u16string(str));
}

string& string::operator =(const std::u32string& str) noexcept {
  *this = convert_string::to_ustring(str);
  return *this;
}

string& string::operator =(const char32* str) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  return operator =(std::u32string(str));
}

string& string::operator =(const std::wstring& str) noexcept {
  *this = convert_string::to_ustring(str);
  return *this;
}

string& string::operator =(const wchar* str) {
  if (str == nullptr) throw null_pointer_exception {csf_};
  return operator =(std::wstring(str));
}

string& string::operator =(string&& str) noexcept {
  basic_string<value_type>::operator =(str);
  return *this;
}

string& string::operator =(value_type character) {
  *this = string(1, character);
  return  *this;
}

#if defined(__xtd__cpp_lib_char8_t)
string& string::operator =(char8 character) {
  *this = string(1, character);
  return  *this;
}
#endif

string& string::operator =(char16 character) {
  *this = string(1, character);
  return  *this;
}

string& string::operator =(char32 character) {
  *this = string(1, character);
  return  *this;
}

string& string::operator =(wchar character) {
  *this = string(1, character);
  return  *this;
}

string& string::operator =(const std::initializer_list<value_type>& il) {
  assign(il);
  return *this;
}

#if defined(__xtd__cpp_lib_char8_t)
string& string::operator =(const std::initializer_list<char8>& il) {
  for (auto c : il)
    *this += static_cast<value_type>(c);
  return *this;
}
#endif

string& string::operator =(const std::initializer_list<char16>& il) {
  clear();
  *this = convert_string::to_ustring(std::u16string(il));
  return *this;
}

string& string::operator =(const std::initializer_list<char32>& il) {
  clear();
  *this = convert_string::to_ustring(std::u32string(il));
  return *this;
}

string& string::operator =(const std::initializer_list<wchar>& il) {
  clear();
  *this = convert_string::to_ustring(std::wstring(il));
  return *this;
}

string& string::operator +=(const string& str) {
  *this = *this + str;
  return *this;
}

string& string::operator +=(const std::string& str) {
  *this = *this + str;
  return *this;
}

string& string::operator +=(const value_type* str) {
  *this = *this + str;
  return *this;
}

#if defined(__xtd__cpp_lib_char8_t)
string& string::operator +=(const std::u8string& str) {
  *this = *this + str;
  return *this;
}

string& string::operator +=(const char8* str) {
  *this = *this + str;
  return *this;
}
#endif

string& string::operator +=(const std::u16string& str) {
  *this = *this + str;
  return *this;
}

string& string::operator +=(const char16* str) {
  *this = *this + str;
  return *this;
}

string& string::operator +=(const std::u32string& str) {
  *this = *this + str;
  return *this;
}

string& string::operator +=(const char32* str) {
  *this = *this + str;
  return *this;
}

string& string::operator +=(const std::wstring& str) {
  *this = *this + str;
  return *this;
}

string& string::operator +=(const wchar* str) {
  *this = *this + str;
  return *this;
}

string& string::operator +=(value_type character) {
  *this = *this + character;
  return *this;
}

#if defined(__xtd__cpp_lib_char8_t)
string& string::operator +=(char8 character) {
  *this = *this + character;
  return *this;
}
#endif

string& string::operator +=(char16 character) {
  *this = *this + character;
  return *this;
}

string& string::operator +=(char32 character) {
  *this = *this + character;
  return *this;
}

string& string::operator +=(wchar character) {
  *this = *this + character;
  return *this;
}

string& string::operator +=(const std::initializer_list<value_type>& il) {
  *this = *this + il;
  return *this;
}

#if defined(__xtd__cpp_lib_char8_t)
string& string::operator +=(const std::initializer_list<char8>& il) {
  *this = *this + il;
  return *this;
}
#endif

string& string::operator +=(const std::initializer_list<char16>& il) {
  *this = *this + il;
  return *this;
}

string& string::operator +=(const std::initializer_list<char32>& il) {
  *this = *this + il;
  return *this;
}

string& string::operator +=(const std::initializer_list<wchar>& il) {
  *this = *this + il;
  return *this;
}

bool string::operator ==(const string& other) const {
  return basic_string<value_type>(*this) == basic_string<value_type>(other);
}

bool string::operator !=(const string& other) const {
  return !operator ==(other);
}

bool string::operator ==(const std::string& other) const {
  return *this == string(other);
}

bool string::operator !=(const std::string& other) const {
  return !operator ==(other);
}

bool string::operator ==(const value_type* other) const {
  return basic_string<value_type>(*this) == other;
}

bool string::operator !=(const value_type* other) const {
  return !operator ==(other);
}

#if defined(__xtd__cpp_lib_char8_t)
bool string::operator ==(const char8* other) const {
  return *this == string(other);
}

bool string::operator !=(const char8* other) const {
  return !operator ==(other);
}
#endif

bool string::operator ==(const std::u16string& other) const {
  return *this == string(other);
}

bool string::operator !=(const std::u16string& other) const {
  return !operator ==(other);
}

bool string::operator ==(const char16* other) const {
  return *this == string(other);
}

bool string::operator !=(const char16* other) const {
  return !operator ==(other);
}

bool string::operator ==(const std::u32string& other) const {
  return *this == string(other);
}

bool string::operator !=(const std::u32string& other) const {
  return !operator ==(other);
}

bool string::operator ==(const char32* other) const {
  return *this == string(other);
}

bool string::operator !=(const char32* other) const {
  return !operator ==(other);
}

bool string::operator ==(const std::wstring& other) const {
  return *this == string(other);
}

bool string::operator !=(const std::wstring& other) const {
  return !operator ==(other);
}

bool string::operator ==(const wchar* other) const {
  return *this == string(other);
}

bool string::operator !=(const wchar* other) const {
  return !operator ==(other);
}

const string::value_type& string::operator [](xtd::size index) {
  return basic_string<value_type>::operator [](index);
}

const string::value_type& string::operator [](xtd::size index) const {
  return basic_string<value_type>::operator [](index);
}

xtd::size string::length() const noexcept {
  return size();
}

string string::class_name(const std::type_info& info) {
  return typeof_(info).name();
}

int32 string::compare(const string& str_a, const string& str_b) noexcept {
  return compare(str_a, str_b, false);
}

int32 string::compare(const string& str_a, const string& str_b, bool ignore_case) noexcept {
  return compare(str_a, str_b, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);
}

int32 string::compare(const string& str_a, const string& str_b, xtd::string_comparison comparison_type) noexcept {
  if (comparison_type == xtd::string_comparison::ordinal_ignore_case)
    return str_a.to_lower().compare(str_b.to_lower());
  return str_a.compare(str_b);
}

int32 string::compare(const string& str_a, xtd::size index_a, const string& str_b, xtd::size index_b, xtd::size length) noexcept {
  return compare(str_a, index_a, str_b, index_b, length, false);
}

int32 string::compare(const string& str_a, xtd::size index_a, const string& str_b, xtd::size index_b, xtd::size length, bool ignore_case) noexcept {
  return compare(str_a, index_a, str_b, index_b, length, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);
}

int32 string::compare(const string& str_a, xtd::size index_a, const string& str_b, xtd::size index_b, xtd::size length, xtd::string_comparison comparison_type) noexcept {
  auto sa = str_a.substr(index_a, length);
  auto sb = str_b.substr(index_b, length);
  if (comparison_type == xtd::string_comparison::ordinal_ignore_case)
    return sa.to_lower().compare(sb.to_lower());
  return sa.compare(sb);
}

int32 string::compare_to(const string& value) const noexcept {
  return compare(*this, value);
}

string string::concat(const string& str_a, const string& str_b, const string& str_c, const string& str_d) noexcept {
  return str_a + str_b + str_c + str_d;
}

string string::concat(const string& str_a, const string& str_b, const string& str_c) noexcept {
  return str_a + str_b + str_c;
}

string string::concat(const string& str_a, const string& str_b) noexcept {
  return str_a + str_b;
}

string string::concat(const std::vector<string>& values) noexcept {
  auto result = string::empty_string;
  std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
  return result;
}

string string::concat(const std::vector<const value_type*>& values) noexcept {
  auto result = string::empty_string;
  std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
  return result;
}

#if defined(__xtd__cpp_lib_char8_t)
string string::concat(const std::vector<const char8*>& values) noexcept {
  auto result = string::empty_string;
  std::for_each(values.begin(), values.end(), [&](const auto & item) {result += string(item);});
  return result;
}
#endif

string string::concat(const std::initializer_list<string>& values) noexcept {
  auto result = string::empty_string;
  std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
  return result;
}

string string::concat(const std::initializer_list<const value_type*>& values) noexcept {
  auto result = string::empty_string;
  std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
  return result;
}

#if defined(__xtd__cpp_lib_char8_t)
string string::concat(const std::initializer_list<const char8*>& values) noexcept {
  auto result = string::empty_string;
  std::for_each(values.begin(), values.end(), [&](const auto & item) {result += string(item);});
  return result;
}
#endif

string string::demangle(const string& name) {
  return native::types::demangle(name);
}

bool string::contains(value_type value) const noexcept {
  return find(value) != npos;
}

#if defined(__xtd__cpp_lib_char8_t)
bool string::contains(char8 value) const noexcept {
  auto str = convert_string::to_u8string(*this);
  return str.find(value) != str.npos;
}
#endif

bool string::contains(char16 value) const noexcept {
  auto str = convert_string::to_u16string(*this);
  return str.find(value) != str.npos;
}

bool string::contains(char32 value) const noexcept {
  auto str = convert_string::to_u32string(*this);
  return str.find(value) != str.npos;
}

bool string::contains(wchar value) const noexcept {
  auto str = convert_string::to_wstring(*this);
  return str.find(value) != str.npos;
}

bool string::contains(const string& value) const noexcept {
  return find(value) != npos;
}

bool string::equals(const object& obj) const noexcept {
  return is<string>(obj) && equals(static_cast<const string&>(obj));
}

bool string::equals(const string& value) const noexcept {
  return equals(value, false);
}

bool string::equals(const string& value, bool ignore_case) const noexcept {
  if (ignore_case) return to_lower().compare_to(value.to_lower()) == 0;
  return compare_to(value) == 0;
}

bool string::ends_with(value_type value) const noexcept {
  return rfind(value) == size() - 1;
}

#if defined(__xtd__cpp_lib_char8_t)
bool string::ends_with(char8 value) const noexcept {
  auto str = convert_string::to_u8string(*this);
  return str.rfind(value) == str.size() - 1;
}
#endif

bool string::ends_with(char16 value) const noexcept {
  auto str = convert_string::to_u16string(*this);
  return str.rfind(value) == str.size() - 1;
}

bool string::ends_with(char32 value) const noexcept {
  auto str = convert_string::to_u32string(*this);
  return str.rfind(value) == str.size() - 1;
}

bool string::ends_with(wchar value) const noexcept {
  auto str = convert_string::to_wstring(*this);
  return str.rfind(value) == str.size() - 1;
}

bool string::ends_with(const string& value) const noexcept {
  return ends_with(value, false);
}

bool string::ends_with(const string& value, bool ignore_case) const noexcept {
  return ends_with(value, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);
}

bool string::ends_with(const string& value, xtd::string_comparison comparison_type) const noexcept {
  if (comparison_type == xtd::string_comparison::ordinal_ignore_case)
    return to_lower().rfind(value.to_lower()) + value.to_lower().size() == size();
  return rfind(value) + value.size() == size();
}

string string::full_class_name(const std::type_info& info) {
  return typeof_(info).full_name();
}

xtd::size string::get_hash_code() const noexcept {
  return hash_code::combine(basic_string<value_type> {*this});
}

xtd::size string::index_of(value_type value) const noexcept {
  return index_of(value, 0, size());
}

xtd::size string::index_of(const string& value) const noexcept {
  return index_of(value, 0, size());
}

xtd::size string::index_of(value_type value, xtd::size start_index) const noexcept {
  return index_of(value, start_index, size() - start_index);
}

xtd::size string::index_of(const string& value, xtd::size start_index) const noexcept {
  return index_of(value, start_index, size() - start_index);
}

xtd::size string::index_of(value_type value, xtd::size start_index, xtd::size count) const noexcept {
  auto result = find(value, start_index);
  return result > start_index + count ? npos : result;
}

xtd::size string::index_of(const string& value, xtd::size start_index, xtd::size count) const noexcept {
  auto result = find(value, start_index);
  return result > start_index + count ? npos : result;
}

xtd::size string::index_of_any(const std::vector<value_type>& values) const noexcept {
  return index_of_any(values, 0, size());
}

xtd::size string::index_of_any(const std::vector<value_type>& values, xtd::size start_index) const noexcept {
  return index_of_any(values, start_index, size() - start_index);
}

xtd::size string::index_of_any(const std::vector<value_type>& values, xtd::size start_index, xtd::size count) const noexcept {
  auto index = 0_z;
  for (const auto& item : *this) {
    if (index++ < start_index) continue;
    if (index - 1 > start_index + count) break;
    if (std::find(values.begin(), values.end(), item) != values.end()) return index - 1;
  }
  return npos;
}

xtd::size string::index_of_any(const std::initializer_list<value_type>& values) const noexcept {
  return index_of_any(std::vector<value_type>(values));
}

xtd::size string::index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index) const noexcept {
  return index_of_any(std::vector<value_type>(values), start_index);
}

xtd::size string::index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index, xtd::size count) const noexcept {
  return index_of_any(std::vector<value_type>(values), start_index, count);
}

string string::insert(xtd::size start_index, const string& value) const noexcept {
  auto result = *this;
  result.basic_string<value_type>::insert(start_index, value);
  return result;
}

bool string::is_empty(const string& sttring) noexcept {
  return sttring.empty();
}

xtd::size string::last_index_of(value_type value) const noexcept {
  return last_index_of(value, 0, size());
}

xtd::size string::last_index_of(const string& value) const noexcept {
  return last_index_of(value, 0, size());
}

xtd::size string::last_index_of(value_type value, xtd::size start_index) const noexcept {
  return last_index_of(value, start_index, size() - start_index);
}

xtd::size string::last_index_of(const string& value, xtd::size start_index) const noexcept {
  return last_index_of(value, start_index, size() - start_index);
}

xtd::size string::last_index_of(value_type value, xtd::size start_index, xtd::size count) const noexcept {
  auto result = rfind(value, start_index + count - 1);
  return result < start_index ? npos : result;
}

xtd::size string::last_index_of(const string& value, xtd::size start_index, xtd::size count) const noexcept {
  auto result = rfind(value, start_index + count - value.size());
  return result < start_index ? npos : result;
}

xtd::size string::last_index_of_any(const std::vector<value_type>& values) const noexcept {
  return last_index_of_any(values, 0, size());
}

xtd::size string::last_index_of_any(const std::vector<value_type>& values, xtd::size start_index) const noexcept {
  return last_index_of_any(values, start_index, size() - start_index);
}

xtd::size string::last_index_of_any(const std::vector<value_type>& values, xtd::size start_index, xtd::size count) const noexcept {
  auto index = size() - 1;
  for (const_reverse_iterator it = crbegin(); it != crend(); ++it) {
    if (index-- > start_index + count) continue;
    if (index + 1 < start_index) break;
    if (std::find(values.begin(), values.end(), *it) != values.end()) return index + 1;
  }
  return npos;
}

xtd::size string::last_index_of_any(const std::initializer_list<value_type>& values) const noexcept {
  return last_index_of_any(std::vector<value_type>(values));
}

xtd::size string::last_index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index) const noexcept {
  return last_index_of_any(std::vector<value_type>(values), start_index);
}

xtd::size string::last_index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index, xtd::size count) const noexcept {
  return last_index_of_any(std::vector<value_type>(values), start_index, count);
}

string string::pad_left(xtd::size total_width) const noexcept {
  return pad_left(total_width, ' ');
}

string string::pad_left(xtd::size total_width, char32 padding_char) const noexcept {
  auto str = convert_string::to_u32string(*this);
  return total_width < str.size() ? str : std::u32string(total_width - str.size(), padding_char) + str;
}

string string::pad_right(xtd::size total_width) const noexcept {
  return pad_right(total_width, ' ');
}

string string::pad_right(xtd::size total_width, char32 padding_char) const noexcept {
  auto str = convert_string::to_u32string(*this);
  return total_width < str.size() ? str : str + std::u32string(total_width - str.size(), padding_char);
}

string string::quoted() const {
  return quoted('"', '\\');
}

string string::quoted(value_type delimiter, value_type escape) const {
  std::stringstream ss;
  ss << std::quoted(*this, delimiter, escape);
  return ss.str();
}

string string::remove(xtd::size start_index) const noexcept {
  return remove(start_index, size() - start_index);
}

string string::remove(xtd::size start_index, xtd::size count) const noexcept {
  if (start_index > size()) return *this;
  return string(*this).erase(start_index, count);
}

string string::replace(value_type old_char, value_type new_char) const noexcept {
  return replace(string(1, old_char), string(1, new_char));
}

string string::replace(const string& old_string, const string& new_string) const noexcept {
  auto result = *this;
  auto old_size = old_string.length();
  auto new_size = new_string.length();
  auto index = 0_z;
  while (true) {
    index = result.find(old_string, index);
    if (index == npos) break;
    if (old_size == new_size) result.replace(index, old_size, new_string);
    else {
      result.erase(index, old_string.size());
      result.basic_string<value_type>::insert(index, new_string);
    }
    index += new_string.size();
  }
  return result;
}

std::vector<string> string::split(const std::vector<value_type>& separators, xtd::size count, string_split_options options) const noexcept {
  if (count == 0) return {};
  if (count == 1) return {*this};
  
  auto list = std::vector<string> {};
  auto sub_string = string::empty_string;
  auto split_char_separators = separators.size() == 0 ? default_split_separators : separators;
  for (auto it = begin(); it != end(); ++it) {
    auto is_separator = std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
    if (!is_separator) sub_string.append(string(1, *it));
    if ((static_cast<xtd::size>(it - begin()) == length() - 1 || is_separator) && (sub_string.length() > 0 || (sub_string.length() == 0 && options != string_split_options::remove_empty_entries))) {
      if (list.size() == count - 1) {
        list.push_back(sub_string + string(c_str(), it - begin() + (is_separator ? 0 : 1), length() - (it - begin()) + (is_separator ? 0 : 1)));
        return list;
      }
      list.push_back(sub_string);
      sub_string.clear();
    }
  }
  
  return list;
}

std::vector<string> string::split() const noexcept {
  return split(default_split_separators, std::numeric_limits<xtd::size>::max(), string_split_options::none);
}

std::vector<string> string::split(const std::vector<value_type>& separators) const noexcept {
  return split(separators, std::numeric_limits<xtd::size>::max(), string_split_options::none);
}

std::vector<string> string::split(const std::vector<value_type>& separators, string_split_options options) const noexcept {
  return split(separators, std::numeric_limits<xtd::size>::max(), options);
}

std::vector<string> string::split(const std::vector<value_type>& separators, xtd::size count) const noexcept {
  return split(separators, count, string_split_options::none);
}

bool string::starts_with(value_type value) const noexcept {
  return starts_with(value, false);
}

bool string::starts_with(value_type value, bool ignore_case) const noexcept {
  if (ignore_case) return to_lower().find(static_cast<value_type>(tolower(value))) == 0;
  return find(value) == 0;
}

bool string::starts_with(const string& value) const noexcept {
  return starts_with(value, false);
}

bool string::starts_with(const string& value, bool ignore_case) const noexcept {
  if (ignore_case) return to_lower().find(value.to_lower()) == 0;
  return find(value) == 0;
}

string string::substr(size_type index, size_type count) const {
  return basic_string<value_type>::substr(index, count);
}

string string::substring(xtd::size start_index) const noexcept {
  if (start_index >= size()) return "";
  return substr(start_index);
}

string string::substring(xtd::size start_index, xtd::size length) const noexcept {
  if (start_index >= size()) return "";
  return substr(start_index, length);
}

std::vector<string::value_type> string::to_array() const noexcept {
  return to_array(0, size());
}

std::vector<string::value_type> string::to_array(xtd::size start_index) const noexcept {
  return to_array(start_index, size() - start_index);
}

std::vector<string::value_type> string::to_array(xtd::size start_index, xtd::size length) const noexcept {
  if (start_index >= size()) return {};
  if (start_index + length >= size()) return {begin() + start_index, end()};
  return {begin() + start_index, begin() + start_index + length};
}

string string::to_lower() const noexcept {
  auto result = string::empty_string;
  std::for_each(begin(), end(), [&](auto c) {result += static_cast<char>(tolower(c));});
  return result;
}

string string::to_title_case() const noexcept {
  auto words = split({' '});
  for (auto& word : words)
    if (word.size() && word != word.to_upper()) word = static_cast<char>(toupper(word[0])) + word.substring(1).to_lower();
  return string::join(" ", words);
}

string string::to_string() const noexcept {
  return *this;
}

string string::to_upper() const noexcept {
  auto result = string::empty_string;
  std::for_each(begin(), end(), [&](auto c) {result += static_cast<char>(toupper(c));});
  return result;
}

string string::trim() const noexcept {
  return trim(default_trim_chars);
}

string string::trim(value_type trim_char) const noexcept {
  return trim(std::vector<value_type> {trim_char});
}

string string::trim(const std::vector<value_type>& trim_chars) const noexcept {
  return trim_start(trim_chars).trim_end(trim_chars);
}

string string::trim_end() const noexcept {
  return trim_end(default_trim_chars);
}

string string::trim_end(value_type trim_char) const noexcept {
  return trim_end(std::vector<value_type> {trim_char});
}

string string::trim_end(const std::vector<value_type>& trim_chars) const noexcept {
  if (!size()) return *this;
  auto result = *this;
  while (std::find(trim_chars.begin(), trim_chars.end(), result[result.size() - 1]) != trim_chars.end())
    result.erase(result.size() - 1, 1);
  return result;
}

string string::trim_start() const noexcept {
  return trim_start(default_trim_chars);
}

string string::trim_start(value_type trim_char) const noexcept {
  return trim_start(std::vector<value_type> {trim_char});
}

string string::trim_start(const std::vector<value_type>& trim_chars) const noexcept {
  if (!size()) return *this;
  auto result = *this;
  while (std::find(trim_chars.begin(), trim_chars.end(), result[0]) != trim_chars.end())
    result.erase(0, 1);
  return result;
}

bool string::equals(const string& a, const string& b) noexcept {
  return a.equals(b);
}

bool string::equals(const string& a, const string& b, bool ignore_case) noexcept {
  return a.equals(b, ignore_case);
}

string string::get_class_name(const string& full_name) {
  auto length = full_name.last_index_of("<");
  if (length == npos) length = full_name.length();
  if (full_name.last_index_of("::", 0, length) == npos) return full_name;
  return full_name.substring(full_name.last_index_of("::", 0, length) + 2);
}

string xtd::to_ustring(int val) {
  return string::format("{}", val);
}

string xtd::to_ustring(unsigned val) {
  return string::format("{}", val);
}

string xtd::to_ustring(long val) {
  return string::format("{}", val);
}

string xtd::to_ustring(unsigned long val) {
  return string::format("{}", val);
}

string xtd::to_ustring(long long val) {
  return string::format("{}", val);
}

string xtd::to_ustring(unsigned long long val) {
  return string::format("{}", val);
}

string xtd::to_ustring(float val) {
  return string::format("{}", val);
}

string xtd::to_ustring(double val) {
  return string::format("{}", val);
}

string xtd::to_ustring(long double val) {
  return string::format("{}", val);
}
