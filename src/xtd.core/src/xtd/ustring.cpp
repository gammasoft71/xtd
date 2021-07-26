#include "../../include/xtd/ustring.h"
#include "../../include/xtd/format_exception.h"
#include "../../include/xtd/diagnostics/stack_frame.h"

using namespace std;
using namespace xtd;

void __throw_ustring_format_exception() {
  throw format_exception(current_stack_frame_);
}

void __throw_ustring_format_exception_close_bracket() {
  throw format_exception("Invalid format expression : closing bracket '{' without open bracket '}'"_t, current_stack_frame_);
}

void __throw_ustring_format_exception_open_bracket() {
  throw format_exception("Invalid format expression : open bracket '}' without end bracket '{'"_t, current_stack_frame_);
}

void __throw_ustring_format_exception_start_colon() {
  throw format_exception("Invalid format expression : format argument must be start by ':'"_t, current_stack_frame_);
}

ustring::ustring() noexcept {
}

ustring::ustring(const allocator_type& allocator) noexcept : basic_string<value_type>(allocator) {
}

ustring::ustring(size_t count, value_type character) : basic_string<value_type>(count, character) {
}

ustring::ustring(size_t count, value_type character, const allocator_type& allocator) : basic_string<value_type>(count, character, allocator) {
}

ustring::ustring(const ustring& str, size_t index, size_t count) : basic_string<value_type>(str, index, count) {
}

ustring::ustring(const ustring& str, size_t index, size_t count, const allocator_type& allocator) : basic_string<value_type>(str, index, count, allocator) {
}

ustring::ustring(const ustring& str, size_t index) : basic_string<value_type>(str, index) {
}

ustring::ustring(const ustring& str, size_t index, const allocator_type& allocator) : basic_string<value_type>(str, index, allocator) {
}

ustring::ustring(const value_type* str, size_t count) : basic_string<value_type>(str, count) {
}

ustring::ustring(const value_type* str, size_t count, const allocator_type& allocator) : basic_string<value_type>(str, count, allocator) {
}

ustring::ustring(const value_type* str) : basic_string<value_type>(str) {
}

ustring::ustring(const value_type* str, const allocator_type& allocator) : basic_string<value_type>(str, allocator) {
}

ustring::ustring(value_type* str) : basic_string<value_type>(str) {
}

ustring::ustring(value_type* str, const allocator_type& allocator) : basic_string<value_type>(str, allocator) {
}

ustring::ustring(const ustring& str) noexcept : basic_string<value_type>(str) {
}

ustring::ustring(const ustring& str, const allocator_type& allocator) noexcept : basic_string<value_type>(str, allocator) {
}

ustring::ustring(const std::string& str) noexcept : basic_string<value_type>(reinterpret_cast<const value_type*>(str.c_str())) {
}

ustring::ustring(const std::string& str, const allocator_type& allocator) noexcept : basic_string<value_type>((value_type*)str.c_str(), allocator) {
}

ustring::ustring(const char* str) : basic_string<value_type>(reinterpret_cast<const value_type*>(str)) {
}

ustring::ustring(const char* str, const allocator_type& allocator) : basic_string<value_type>(reinterpret_cast<const value_type*>(str), allocator) {
}

ustring::ustring(char* str) : basic_string<value_type>(reinterpret_cast<const value_type*>(str)) {
}

ustring::ustring(char* str, const allocator_type& allocator) : basic_string<value_type>(reinterpret_cast<const value_type*>(str), allocator) {
}

ustring::ustring(const u8string& str) noexcept : basic_string<value_type>(str) {
}

ustring::ustring(const u8string& str, const allocator_type& allocator) noexcept : basic_string<value_type>(str, allocator) {
}

ustring::ustring(const std::u16string& str) noexcept : ustring(str, allocator_type()) {
}

ustring::ustring(const std::u16string& str, const allocator_type& allocator) noexcept : basic_string<value_type>(allocator) {
  for (auto c : str)
    *this += codepoint_to_string(c);
}

ustring::ustring(const char16_t* str) : ustring(u16string(str)) {
}

ustring::ustring(const char16_t* str, const allocator_type& allocator) : ustring(u16string(str), allocator) {
}

ustring::ustring(char16_t* str) : ustring(u16string(str)) {
}

ustring::ustring(char16_t* str, const allocator_type& allocator) : ustring(u16string(str), allocator) {
}

ustring::ustring(const std::u32string& str) noexcept : ustring(str, allocator_type()) {
}

ustring::ustring(const std::u32string& str, const allocator_type& allocator) noexcept : basic_string<value_type>(allocator) {
  for (auto c : str)
    *this += codepoint_to_string(c);
}

ustring::ustring(const char32_t* str) : ustring(u32string(str)) {
}

ustring::ustring(const char32_t* str, const allocator_type& allocator) : ustring(u32string(str), allocator) {
}

ustring::ustring(char32_t* str) : ustring(u32string(str)) {
}

ustring::ustring(char32_t* str, const allocator_type& allocator) : ustring(u32string(str), allocator) {
}

ustring::ustring(const std::wstring& str) noexcept : ustring(str, allocator_type()) {
}

ustring::ustring(const std::wstring& str, const allocator_type& allocator) noexcept : basic_string<value_type>(allocator) {
  for (auto c : str)
    *this += codepoint_to_string(c);
}

ustring::ustring(const wchar_t* str) : ustring(wstring(str)) {
}

ustring::ustring(const wchar_t* str, const allocator_type& allocator) : ustring(wstring(str), allocator) {
}

ustring::ustring(wchar_t* str) : ustring(wstring(str)) {
}

ustring::ustring(wchar_t* str, const allocator_type& allocator) : ustring(wstring(str), allocator) {
}

ustring::ustring(ustring&& str) noexcept : basic_string<value_type>(str) {
}

ustring::ustring(ustring&& str, const allocator_type& allocator) noexcept : basic_string<value_type>(str, allocator) {
}

ustring::ustring(initializer_list<value_type> il) : basic_string<value_type>(il) {
}

ustring::ustring(initializer_list<value_type> il, const allocator_type& allocator) : basic_string<value_type>(il, allocator) {
}

ustring::ustring(initializer_list<char> il) {
  for (auto& c : il)
    push_back(c);
}

ustring::ustring(initializer_list<char> il, const allocator_type& allocator) : basic_string<value_type>(allocator) {
  for (auto& c : il)
    push_back(c);
}

ustring& ustring::operator=(const ustring& str) {
  assign(str);
  return *this;
}

ustring& ustring::operator=(value_type character) {
  *this = ustring(1, character);
  return  *this;;
}

ustring& ustring::operator=(char character) {
  *this = ustring(1, character);
  return  *this;;
}

ustring& ustring::operator=(const value_type* str) {
  assign(str);
  return *this;
}

ustring& ustring::operator=(const char* str) {
  assign(reinterpret_cast<const value_type*>(str));
  return *this;
}

ustring& ustring::operator=(const std::initializer_list<value_type>& il) {
  assign(il);
  return *this;
}

const ustring::value_type& ustring::operator[](size_t index) {
  return basic_string<value_type>::operator[](index);
}

const ustring::value_type& ustring::operator[](size_t index) const {
  return basic_string<value_type>::operator[](index);
}

ustring ustring::substr(size_type index, size_type count) const {
  return basic_string<value_type>::substr(index, count);
}

int ustring::compare(const ustring& str_a, const ustring& str_b) noexcept {
  return compare(str_a, str_b, false);
}

int ustring::compare(const ustring& str_a, const ustring& str_b, bool ignore_case) noexcept {
  return compare(str_a, str_b, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);
}

int ustring::compare(const ustring& str_a, const ustring& str_b, xtd::string_comparison comparison_type) noexcept {
  if (comparison_type == xtd::string_comparison::ordinal_ignore_case)
    return str_a.to_lower().compare(str_b.to_lower());
  return str_a.compare(str_b);
}

int ustring::compare(const ustring& str_a, size_t index_a, const ustring& str_b, size_t index_b, size_t length) noexcept {
  return compare(str_a, index_a, str_b, index_b, length, false);
}

int ustring::compare(const ustring& str_a, size_t index_a, const ustring& str_b, size_t index_b, size_t length, bool ignore_case) noexcept {
  return compare(str_a, index_a, str_b, index_b, length, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);
}

int ustring::compare(const ustring& str_a, size_t index_a, const ustring& str_b, size_t index_b, size_t length, xtd::string_comparison comparison_type) noexcept {
  ustring sa(str_a.substr(index_a, length));
  ustring sb(str_b.substr(index_b, length));
  if (comparison_type == xtd::string_comparison::ordinal_ignore_case)
    return sa.to_lower().compare(sb.to_lower());
  return sa.compare(sb);
}

ustring ustring::concat(const ustring& str_a, const ustring& str_b, const ustring& str_c, const ustring& str_d) noexcept {
  return str_a + str_b + str_c + str_d;
}

ustring ustring::concat(const ustring& str_a, const ustring& str_b, const ustring& str_c) noexcept {
  return str_a + str_b + str_c;
}

ustring ustring::concat(const ustring& str_a, const ustring& str_b) noexcept {
  return str_a + str_b;
}

ustring ustring::concat(const std::vector<ustring>& values) noexcept {
  ustring result;
  for (const auto& item : values)
    result += item;
  return result;
}

ustring ustring::concat(const std::vector<const value_type*>& values) noexcept {
  ustring result;
  for (const auto& item : values)
    result += item;
  return result;
}

ustring ustring::concat(const std::vector<const char*>& values) noexcept {
  ustring result;
  for (const auto& item : values)
    result += ustring(item);
  return result;
}

ustring ustring::concat(const std::initializer_list<ustring>& values) noexcept {
  ustring result;
  for (const auto& item : values)
    result += item;
  return result;
}

ustring ustring::concat(const std::initializer_list<const value_type*>& values) noexcept {
  ustring result;
  for (const auto& item : values)
    result += item;
  return result;
}

ustring ustring::concat(const std::initializer_list<const char*>& values) noexcept {
  ustring result;
  for (const auto& item : values)
    result += ustring(item);
  return result;
}

bool ustring::contains(const ustring& value) const noexcept {
  return find(value) != npos;
}

ustring ustring::empty() noexcept {
  return {};
}

bool ustring::ends_with(value_type value) const noexcept {
  return rfind(value) == size() - 1;
}

bool ustring::ends_with(char value) const noexcept {
  return rfind(value) == size() - 1;
}

bool ustring::ends_with(const ustring& value) noexcept {
  return ends_with(value, false);
}

bool ustring::ends_with(const ustring& value, bool ignore_case) noexcept {
  return ends_with(value, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);
}

bool ustring::ends_with(const ustring& value, xtd::string_comparison comparison_type) noexcept {
  if (comparison_type == xtd::string_comparison::ordinal_ignore_case)
    return to_lower().rfind(value.to_lower()) + value.to_lower().size() == size();
  return rfind(value) + value.size() == size();
}

size_t ustring::get_hash_code() const noexcept {
  return std::hash<std::basic_string<value_type>>()(*this);
}

size_t ustring::index_of(value_type value) const noexcept {
  return index_of(value, 0, size());
}

size_t ustring::index_of(const ustring& value) const noexcept {
  return index_of(value, 0, size());
}

size_t ustring::index_of(value_type value, size_t start_index) const noexcept {
  return index_of(value, start_index, size() - start_index);
}

size_t ustring::index_of(const ustring& value, size_t start_index) const noexcept {
  return index_of(value, start_index, size() - start_index);
}

size_t ustring::index_of(value_type value, size_t start_index, size_t count) const noexcept {
  size_t result = find(value, start_index);
  return result > start_index + count ? npos : result;
}

size_t ustring::index_of(const ustring& value, size_t start_index, size_t count) const noexcept {
  size_t result = find(value, start_index);
  return result > start_index + count ? npos : result;
}

size_t ustring::index_of_any(const std::vector<value_type>& values) noexcept {
  return index_of_any(values, 0, size());
}

size_t ustring::index_of_any(const std::vector<value_type>& values, size_t start_index) noexcept {
  return index_of_any(values, start_index, size() - start_index);
}

size_t ustring::index_of_any(const std::vector<value_type>& values, size_t start_index, size_t count) noexcept {
  size_t index = 0;
  for (const auto& item : *this) {
    if (index++ < start_index) continue;
    if (index - 1 > start_index + count) break;
    if (std::find(values.begin(), values.end(), item) != values.end()) return index - 1;
  }
  return npos;
}

size_t ustring::index_of_any(const std::initializer_list<value_type>& values) noexcept {
  return index_of_any(std::vector<value_type>(values));
}

size_t ustring::index_of_any(const std::initializer_list<value_type>& values, size_t start_index) noexcept {
  return index_of_any(std::vector<value_type>(values), start_index);
}

size_t ustring::index_of_any(const std::initializer_list<value_type>& values, size_t start_index, size_t count) noexcept {
  return index_of_any(std::vector<value_type>(values), start_index, count);
}

ustring ustring::insert(size_t start_index, const ustring& value) const noexcept {
  ustring result(*this);
  result.basic_string<value_type>::insert(start_index, value);
  return result;
}

bool ustring::is_empty() const noexcept {
  return basic_string<value_type>::empty();
}

size_t ustring::last_index_of(value_type value) const noexcept {
  return last_index_of(value, 0, size());
}

size_t ustring::last_index_of(const ustring& value) const noexcept {
  return last_index_of(value, 0, size());
}

size_t ustring::last_index_of(value_type value, size_t start_index) const noexcept {
  return last_index_of(value, start_index, size() - start_index);
}

size_t ustring::last_index_of(const ustring& value, size_t start_index) const noexcept {
  return last_index_of(value, start_index, size() - start_index);
}

size_t ustring::last_index_of(value_type value, size_t start_index, size_t count) const noexcept {
  size_t result = rfind(value, start_index + count - 1);
  return result < start_index ? npos : result;
}

size_t ustring::last_index_of(const ustring& value, size_t start_index, size_t count) const noexcept {
  size_t result = rfind(value, start_index + count - value.size());
  return result < start_index ? npos : result;
}

size_t ustring::last_index_of_any(const std::vector<value_type>& values) const noexcept {
  return last_index_of_any(values, 0, size());
}

size_t ustring::last_index_of_any(const std::vector<value_type>& values, size_t start_index) const noexcept {
  return last_index_of_any(values, start_index, size() - start_index);
}

size_t ustring::last_index_of_any(const std::vector<value_type>& values, size_t start_index, size_t count) const noexcept {
  size_t index = size() - 1;
  for (const_reverse_iterator it = crbegin(); it != crend(); ++it) {
    if (index-- > start_index + count) continue;
    if (index + 1 < start_index) break;
    if (std::find(values.begin(), values.end(), *it) != values.end()) return index + 1;
  }
  return npos;
}

size_t ustring::last_index_of_any(const std::initializer_list<value_type>& values) noexcept {
  return last_index_of_any(std::vector<value_type>(values));
}

size_t ustring::last_index_of_any(const std::initializer_list<value_type>& values, size_t start_index) noexcept {
  return last_index_of_any(std::vector<value_type>(values), start_index);
}

size_t ustring::last_index_of_any(const std::initializer_list<value_type>& values, size_t start_index, size_t count) noexcept {
  return last_index_of_any(std::vector<value_type>(values), start_index, count);
}

ustring ustring::pad_left(size_t total_width) const noexcept {
  return pad_left(total_width, static_cast<value_type>(0x20));
}

ustring ustring::pad_left(size_t total_width, value_type padding_char) const noexcept {
  if (total_width < size()) return *this;
  return ustring(total_width - size(), padding_char).append(*this);
}

ustring ustring::pad_right(size_t total_width) const noexcept {return pad_right(total_width, static_cast<value_type>(0x20));}

ustring ustring::pad_right(size_t total_width, value_type padding_char) const noexcept {
  if (total_width < size()) return *this;
  ustring result(*this);
  return result.append(total_width - size(), padding_char);
}

ustring ustring::remove(size_t start_index) const noexcept {
  return remove(start_index, size() - start_index);
}

ustring ustring::remove(size_t start_index, size_t count) const noexcept {
  if (start_index > size()) return *this;
  ustring result(*this);
  return result.erase(start_index, count);
}

ustring ustring::replace(value_type old_char, value_type new_char) const noexcept {
  return replace(ustring(1, old_char), ustring(1, new_char));
}

ustring ustring::replace(const ustring& old_string, const ustring& new_string) const noexcept {
  ustring result(*this);
  auto old_size = old_string.length();
  auto new_size = new_string.length();
  size_t index = 0;
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

std::vector<ustring> ustring::split(const std::vector<value_type>& separators, size_t count, string_split_options options) const noexcept {
  if (count == 0) return {};
  if (count == 1) return {*this};
  
  std::vector<ustring> list;
  ustring sub_string;
  std::vector<value_type> split_char_separators = separators.size() == 0 ? std::vector<value_type> {9, 10, 11, 12, 13, 32} : separators;
  for (const_iterator it = begin(); it != end(); it++) {
    bool is_separator =  std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
    if (!is_separator) sub_string.append(ustring(1, *it));
    if ((static_cast<size_t>(it - begin()) == length() - 1 || is_separator) && (sub_string.length() > 0 || (sub_string.length() == 0 && options != string_split_options::remove_empty_entries))) {
      if (list.size() == count - 1) {
        list.push_back(sub_string + ustring(c_str(), it - begin() + (is_separator ? 0 : 1), length() - (it - begin()) + (is_separator ? 0 : 1)));
        return list;
      }
      list.push_back(sub_string);
      sub_string.clear();
    }
  }
  
  return list;
}

std::vector<ustring> ustring::split() const noexcept {
  return split(std::vector<value_type> {9, 10, 11, 12, 13, 32}, std::numeric_limits<size_t>::max(), string_split_options::none);
}

std::vector<ustring> ustring::split(const std::vector<value_type>& separators) const noexcept {
  return split(separators, std::numeric_limits<size_t>::max(), string_split_options::none);
}

std::vector<ustring> ustring::split(const std::vector<value_type>& separators, string_split_options options) const noexcept {
  return split(separators, std::numeric_limits<size_t>::max(), options);
}

std::vector<ustring> ustring::split(const std::vector<value_type>& separators, size_t count) const noexcept {
  return split(separators, count, string_split_options::none);
}

bool ustring::starts_with(value_type value) const noexcept {
  return starts_with(value, false);
}

bool ustring::starts_with(value_type value, bool ignore_case) const noexcept {
  if (ignore_case) return to_lower().find(static_cast<value_type>(tolower(value))) == 0;
  return find(value) == 0;
}

bool ustring::starts_with(const ustring& value) const noexcept {
  return starts_with(value, false);
}

bool ustring::starts_with(const ustring& value, bool ignore_case) const noexcept {
  if (ignore_case) return to_lower().find(value.to_lower()) == 0;
  return find(value) == 0;
}

ustring ustring::substring(size_t start_index) const noexcept {
  if (start_index >= size()) return "";
  return substr(start_index);
}

ustring ustring::substring(size_t start_index, size_t length) const noexcept {
  if (start_index >= size()) return "";
  return substr(start_index, length);
}

std::vector<ustring::value_type> ustring::to_array() const noexcept {
  return to_array(0, size());
}

std::vector<ustring::value_type> ustring::to_array(size_t start_index) const noexcept {
  return to_array(start_index, size() - start_index);
}

std::vector<ustring::value_type> ustring::to_array(size_t start_index, size_t length) const noexcept {
  if (start_index >= size()) return {};
  if (start_index + length >= size()) return {begin() + start_index, end()};
  return {begin() + start_index, begin() + start_index + length};
}

ustring ustring::to_lower() const noexcept {
  ustring result;
  for(auto c : *this) result.push_back(static_cast<value_type>(tolower(c)));
  return result;
}

string ustring::to_string() const noexcept {
  return reinterpret_cast<const char*>(c_str());
}

//ustring ustring::to_string() const noexcept {
//  return *this;
//}

ustring ustring::to_upper() const noexcept {
  ustring result;
  for(auto c : *this) result.push_back(static_cast<value_type>(toupper(c)));
  return result;
}

ustring ustring::trim() const noexcept {
  return trim(std::vector<value_type> {9, 10, 11, 12, 13, 32});
}

ustring ustring::trim(value_type trim_char) const noexcept {
  return trim(std::vector<value_type> {trim_char});
}

ustring ustring::trim(const std::vector<value_type>& trim_chars) const noexcept {
  return trim_start(trim_chars).trim_end(trim_chars);
}

ustring ustring::trim_end() const noexcept {
  return trim_end(std::vector<value_type> {9, 10, 11, 12, 13, 32});
}

ustring ustring::trim_end(value_type trim_char) const noexcept {
  return trim_end(std::vector<value_type> {trim_char});
}

ustring ustring::trim_end(const std::vector<value_type>& trim_chars) const noexcept {
  if (!size()) return *this;
  ustring result(*this);
  while (std::find(trim_chars.begin(), trim_chars.end(), result[result.size() - 1]) != trim_chars.end())
    result.erase(result.size() - 1, 1);
  return result;
}

ustring ustring::trim_start() const noexcept {
  return trim_start(std::vector<value_type> {9, 10, 11, 12, 13, 32});
}

ustring ustring::trim_start(value_type trim_char) const noexcept {
  return trim_start(std::vector<value_type> {trim_char});
}

ustring ustring::trim_start(const std::vector<value_type>& trim_chars) const noexcept {
  ustring result(*this);
  while (std::find(trim_chars.begin(), trim_chars.end(), result[0]) != trim_chars.end())
    result.erase(0, 1);
  return result;
}

ustring ustring::codepoint_to_string(char32_t codepoint) {
  ustring result;
  if (codepoint < 0x80) {
    result.push_back(static_cast<value_type>(codepoint));
  } else  if (codepoint < 0x800) {
    result.push_back(static_cast<value_type>((codepoint >> 6) | 0xc0));
    result.push_back(static_cast<value_type>((codepoint & 0x3f) | 0x80));
  } else if (codepoint < 0x10000) {
    result.push_back(static_cast<value_type>((codepoint >> 12) | 0xe0));
    result.push_back(static_cast<value_type>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<value_type>((codepoint & 0x3f) | 0x80));
  } else {
    result.push_back(static_cast<value_type>((codepoint >> 18) | 0xf0));
    result.push_back(static_cast<value_type>(((codepoint >> 12) & 0x3f) | 0x80));
    result.push_back(static_cast<value_type>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<value_type>((codepoint & 0x3f) | 0x80));
  }
  return result;
}

ustring ustring::get_class_name(const ustring& full_name) {
  size_t length = full_name.last_index_of("<");
  if (length == npos) length = full_name.length();
  if (full_name.last_index_of("::", 0, length) == npos) return full_name;
  return full_name.substring(full_name.last_index_of("::", 0, length) + 2);
}
