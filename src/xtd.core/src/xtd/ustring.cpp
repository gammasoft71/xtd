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

ustring::ustring(const allocator_type& allocator) noexcept : basic_string<char8_t>(allocator) {
}

ustring::ustring(size_t count, char8_t character) : basic_string<char8_t>(count, character) {
}

ustring::ustring(size_t count, char8_t character, const allocator_type& allocator) : basic_string<char8_t>(count, character, allocator) {
}

ustring::ustring(const ustring& str, size_t index, size_t count) : basic_string<char8_t>(str, index, count) {
}

ustring::ustring(const ustring& str, size_t index, size_t count, const allocator_type& allocator) : basic_string<char8_t>(str, index, count, allocator) {
}

ustring::ustring(const ustring& str, size_t index) : basic_string<char8_t>(str, index) {
}

ustring::ustring(const ustring& str, size_t index, const allocator_type& allocator) : basic_string<char8_t>(str, index, allocator) {
}

ustring::ustring(const char8_t* str, size_t count) : basic_string<char8_t>(str, count) {
}

ustring::ustring(const char8_t* str, size_t count, const allocator_type& allocator) : basic_string<char8_t>(str, count, allocator) {
}

ustring::ustring(const char8_t* str) : basic_string<char8_t>(str) {
}

ustring::ustring(const char8_t* str, const allocator_type& allocator) : basic_string<char8_t>(str, allocator) {
}

ustring::ustring(const char* str) : basic_string<char8_t>(reinterpret_cast<const char8_t*>(str)) {
}

ustring::ustring(const char* str, const allocator_type& allocator) : basic_string<char8_t>(reinterpret_cast<const char8_t*>(str), allocator) {
}

ustring::ustring(const ustring& str) noexcept : basic_string<char8_t>(str) {
}

ustring::ustring(const ustring& str, const allocator_type& allocator) noexcept : basic_string<char8_t>(str, allocator) {
}

ustring::ustring(const basic_string<char8_t>& str) noexcept : basic_string<char8_t>(str) {
}

ustring::ustring(const basic_string<char8_t>& str, const allocator_type& allocator) noexcept : basic_string<char8_t>(str, allocator) {
}

ustring::ustring(const std::string& str) noexcept : basic_string<char8_t>(reinterpret_cast<const char8_t*>(str.c_str())) {
}

ustring::ustring(const std::string& str, const allocator_type& allocator) noexcept : basic_string<char8_t>((char8_t*)str.c_str(), allocator) {
}

ustring::ustring(ustring&& str) noexcept : basic_string<char8_t>(str) {
}

ustring::ustring(ustring&& str, const allocator_type& allocator) noexcept : basic_string<char8_t>(str, allocator) {
}

ustring::ustring(initializer_list<char8_t> il) : basic_string<char8_t>(il) {
}

ustring::ustring(initializer_list<char8_t> il, const allocator_type& allocator) : basic_string<char8_t>(il, allocator) {
}

ustring::ustring(initializer_list<char> il) {
  for (auto& c : il)
    push_back(c);
}

ustring::ustring(initializer_list<char> il, const allocator_type& allocator) : basic_string<char8_t>(allocator) {
  for (auto& c : il)
    push_back(c);
}

ustring& ustring::operator=(const ustring& str) {
  assign(str);
  return *this;
}

ustring& ustring::operator=(value_type character) {
  *this = format("{}", character);
  return  *this;;
}

ustring& ustring::operator=(char character) {
  *this = format("{}", character);
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

const char8_t& ustring::operator[](size_t index) {
  return basic_string<char8_t>::operator[](index);
}

const char8_t& ustring::operator[](size_t index) const {
  return basic_string<char8_t>::operator[](index);
}

ustring ustring::substr(size_type index, size_type count) const {
  return basic_string<char8_t>::substr(index, count);
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

ustring ustring::to_lower() const noexcept {
  ustring result;
  for(auto c : *this) result.push_back(static_cast<value_type>(tolower(c)));
  return result;
}

string ustring::to_string() const noexcept {
  return reinterpret_cast<const char*>(c_str());
}

ustring ustring::to_upper() const noexcept {
  ustring result;
  for(auto c : *this) result.push_back(static_cast<value_type>(toupper(c)));
  return result;
}
