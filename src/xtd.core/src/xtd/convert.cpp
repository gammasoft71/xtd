#include <cmath>
#include "../../include/xtd/invalid_cast_exception.h"
#include "../../include/xtd/overflow_exception.h"
#include "../../include/xtd/convert.h"

using namespace std;
using namespace xtd;

std::any convert::to_any(any value) noexcept {
  return value;
}

std::any convert::to_any(bool value) noexcept {
  return value;
}

std::any convert::to_any(byte_t value) noexcept {
  return value;
}

std::any convert::to_any(char value) noexcept {
  return value;
}

std::any convert::to_any(char8_t value) {
  //return value;
  throw invalid_cast_exception(csf_);
}

std::any convert::to_any(char16_t value) noexcept {
  return value;
}

std::any convert::to_any(char32_t value) noexcept {
  return value;
}

std::any convert::to_any(wchar_t value) noexcept {
  return value;
}

std::any convert::to_any(decimal_t value) noexcept {
  return value;
}

std::any convert::to_any(double value) noexcept {
  return value;
}

std::any convert::to_any(float value) noexcept {
  return value;
}

std::any convert::to_any(int16_t value) noexcept {
  return value;
}

std::any convert::to_any(int32_t value) noexcept {
  return value;
}

std::any convert::to_any(int64_t value) noexcept {
  return value;
}

std::any convert::to_any(llong_t value) noexcept {
  return value;
}

std::any convert::to_any(sbyte_t value) noexcept {
  return value;
}

std::any convert::to_any(uint16_t value) noexcept {
  return value;
}

std::any convert::to_any(uint32_t value) noexcept {
  return value;
}

std::any convert::to_any(uint64_t value) noexcept {
  return value;
}

std::any convert::to_any(ullong_t value) noexcept {
  return value;
}

std::any convert::to_any(const ustring& value) noexcept {
  return value;
}

std::any convert::to_any(const string& value) noexcept {
  return value;
}

std::any convert::to_any(const u8string& value) noexcept {
  return value;
}

std::any convert::to_any(const u16string& value) noexcept {
  return value;
}

std::any convert::to_any(const u32string& value) noexcept {
  return value;
}

std::any convert::to_any(const wstring& value) noexcept {
  return value;
}

std::any convert::to_any(const char* value) noexcept {
  return ustring(value);
}

std::any convert::to_any(char* value) noexcept {
  return ustring(value);
}

std::any convert::to_any(const char8_t* value) noexcept {
  return ustring(value);
}

std::any convert::to_any(const char16_t* value) noexcept {
  return ustring(value);
}

std::any convert::to_any(char16_t* value) noexcept {
  return ustring(value);
}

std::any convert::to_any(const char32_t* value) noexcept {
  return ustring(value);
}

std::any convert::to_any(char32_t* value) noexcept {
  return ustring(value);
}

std::any convert::to_any(const wchar_t* value) noexcept {
  return ustring(value);
}

std::any convert::to_any(wchar_t* value) noexcept {
  return ustring(value);
}

bool convert::to_boolean(any value) {
  try {
    return any_cast<bool>(value);
  } catch(...) {
    throw invalid_cast_exception(csf_);
  }
}

bool convert::to_boolean(bool value) noexcept {
  return value;
}

bool convert::to_boolean(byte_t value) noexcept {
  return value != 0u;
}

bool convert::to_boolean(char value) {
  throw invalid_cast_exception(csf_);
}

bool convert::to_boolean(char8_t value) {
  throw invalid_cast_exception(csf_);
}

bool convert::to_boolean(char16_t value) {
  throw invalid_cast_exception(csf_);
}

bool convert::to_boolean(char32_t value) {
  throw invalid_cast_exception(csf_);
}

bool convert::to_boolean(wchar_t value) {
  throw invalid_cast_exception(csf_);
}

bool convert::to_boolean(decimal_t value) noexcept {
  return value != .0l;
}

bool convert::to_boolean(double value) noexcept {
  return value != .0;
}

bool convert::to_boolean(float value) noexcept {
  return value != .0f;
}

bool convert::to_boolean(int16_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(int32_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(int64_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(llong_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(sbyte_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(uint16_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(uint32_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(uint64_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(ullong_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(const ustring& value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const string& value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const u8string& value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const u16string& value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const u32string& value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const wstring& value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const char* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(char* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const char8_t* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const char16_t* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(char16_t* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const char32_t* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(char32_t* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const wchar_t* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(wchar_t* value) {
  return ustring::parse<bool>(value);
}

byte_t convert::to_byte(any value) {
  try {
    return any_cast<byte_t>(value);
  } catch(...) {
    throw invalid_cast_exception(csf_);
  }
}

byte_t convert::to_byte(bool value) noexcept {
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(byte_t value) noexcept {
  return value;
}

byte_t convert::to_byte(char value) noexcept {
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(char8_t value) noexcept {
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(char16_t value) {
  if (value > static_cast<char16_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(char32_t value) {
  if (value > static_cast<char32_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(wchar_t value) {
  if (value > static_cast<wchar_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(decimal_t value) {
  if (value < 0 || value > static_cast<decimal_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(round(value));
}

byte_t convert::to_byte(double value) {
  if (value < 0 || value > static_cast<double>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(round(value));
}

byte_t convert::to_byte(float value) {
  if (value < 0 || value > static_cast<float>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(round(value));
}

byte_t convert::to_byte(int16_t value) {
  if (value < 0 || value > static_cast<int16_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(int32_t value) {
  if (value < 0 || value > static_cast<int32_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(int64_t value) {
  if (value < 0 || value > static_cast<int64_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(llong_t value) {
  if (value < 0 || value > static_cast<llong_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(sbyte_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(uint16_t value) {
  if (value > static_cast<uint32_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(uint32_t value) {
  if (value > static_cast<uint32_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(uint64_t value) {
  if (value > static_cast<uint64_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(ullong_t value) {
  if (value > static_cast<ullong_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(const ustring& value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const string& value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const u8string& value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const u16string& value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const u32string& value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const wstring& value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const char* value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(char* value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const char8_t* value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(char8_t* value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const char16_t* value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(char16_t* value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const char32_t* value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(char32_t* value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(const wchar_t* value) {
  return ustring::parse<byte_t>(value);
}

byte_t convert::to_byte(wchar_t* value) {
  return ustring::parse<byte_t>(value);
}
