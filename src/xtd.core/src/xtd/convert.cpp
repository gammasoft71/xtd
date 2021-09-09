#include <cmath>
#include "../../include/xtd/format_exception.h"
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
  return value;
}

std::any convert::to_any(char* value) noexcept {
  return value;
}

std::any convert::to_any(const char8_t* value) {
  //return value;
  throw invalid_cast_exception(csf_);
}

std::any convert::to_any(char8_t* value) {
  //return value;
  throw invalid_cast_exception(csf_);
}

std::any convert::to_any(const char16_t* value) noexcept {
  return value;
}

std::any convert::to_any(char16_t* value) noexcept {
  return value;
}

std::any convert::to_any(const char32_t* value) noexcept {
  return value;
}

std::any convert::to_any(char32_t* value) noexcept {
  return value;
}

std::any convert::to_any(const wchar_t* value) noexcept {
  return value;
}

std::any convert::to_any(wchar_t* value) noexcept {
  return value;
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
  if (value < static_cast<decimal_t>(numeric_limits<byte>::min()) || value > static_cast<decimal_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(round(value));
}

byte_t convert::to_byte(double value) {
  if (value < static_cast<double>(numeric_limits<byte>::min()) || value > static_cast<double>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(round(value));
}

byte_t convert::to_byte(float value) {
  if (value < static_cast<float>(numeric_limits<byte>::min()) || value > static_cast<float>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(round(value));
}

byte_t convert::to_byte(int16_t value) {
  if (value < static_cast<int16_t>(numeric_limits<byte>::min()) || value > static_cast<int16_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(int32_t value) {
  if (value < static_cast<int32_t>(numeric_limits<byte>::min()) || value > static_cast<int32_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(int64_t value) {
  if (value < static_cast<int64_t>(numeric_limits<byte>::min()) || value > static_cast<int64_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(llong_t value) {
  if (value < static_cast<llong_t>(numeric_limits<byte>::min()) || value > static_cast<llong_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(sbyte_t value) {
  if (value < static_cast<sbyte_t>(numeric_limits<byte>::min())) throw overflow_exception(csf_);
  return static_cast<byte_t>(value);
}

byte_t convert::to_byte(uint16_t value) {
  if (value > static_cast<uint16_t>(numeric_limits<byte_t>::max())) throw overflow_exception(csf_);
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

char convert::to_char(any value) {
  try {
    return any_cast<char>(value);
  } catch(...) {
    throw invalid_cast_exception(csf_);
  }
}

char convert::to_char(bool value) {
  throw invalid_cast_exception(csf_);
}

char convert::to_char(byte_t value) noexcept {
  return static_cast<char>(value);
}

char convert::to_char(char value) noexcept {
  return value;
}

char convert::to_char(char8_t value) noexcept {
  return static_cast<char>(value);
}

char convert::to_char(char16_t value) {
  if (value > static_cast<char16_t>(255)) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(char32_t value) {
  if (value > static_cast<char32_t>(255)) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(wchar_t value) {
  if (value > static_cast<wchar_t>(255)) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(decimal_t value) {
  if (value < 0.0l || value > 255.0l) throw overflow_exception(csf_);
  return static_cast<char>(round(value));
}

char convert::to_char(double value) {
  if (value < 0.0 || value > 255.0) throw overflow_exception(csf_);
  return static_cast<char>(round(value));
}

char convert::to_char(float value) {
  if (value < 0.0f || value > 255.0f) throw overflow_exception(csf_);
  return static_cast<byte_t>(round(value));
}

char convert::to_char(int16_t value) {
  if (value < 0 || value > 255) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(int32_t value) {
  if (value < 0 || value > 255) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(int64_t value) {
  if (value < 0l || value > 255l) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(llong_t value) {
  if (value < 0ll || value > 255ll) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(sbyte_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(uint16_t value) {
  if (value > 255u) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(uint32_t value) {
  if (value > 255u) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(uint64_t value) {
  if (value > 255lu) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(ullong_t value) {
  if (value > 255llu) throw overflow_exception(csf_);
  return static_cast<char>(value);
}

char convert::to_char(const ustring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const u8string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const u16string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const u32string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const wstring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(const wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char convert::to_char(wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(any value) {
  throw invalid_cast_exception(csf_);
}

char8_t convert::to_char8(bool value) {
  throw invalid_cast_exception(csf_);
}

char8_t convert::to_char8(byte_t value) noexcept {
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(char value) noexcept {
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(char8_t value) noexcept {
  return value;
}

char8_t convert::to_char8(char16_t value) {
  if (value > static_cast<char16_t>(255)) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(char32_t value) {
  if (value > static_cast<char32_t>(255)) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(wchar_t value) {
  if (value > static_cast<wchar_t>(255)) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(decimal_t value) {
  if (value < 0.0l || value > 255.0l) throw overflow_exception(csf_);
  return static_cast<char8_t>(round(value));
}

char8_t convert::to_char8(double value) {
  if (value < 0.0 || value > 255.0) throw overflow_exception(csf_);
  return static_cast<char8_t>(round(value));
}

char8_t convert::to_char8(float value) {
  if (value < 0.0f || value > 255.0f) throw overflow_exception(csf_);
  return static_cast<char8_t>(round(value));
}

char8_t convert::to_char8(int16_t value) {
  if (value < 0 || value > 255) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(int32_t value) {
  if (value < 0 || value > 255) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(int64_t value) {
  if (value < 0l || value > 255l) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(llong_t value) {
  if (value < 0ll || value > 255ll) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(sbyte_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(uint16_t value) {
  if (value > 255u) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(uint32_t value) {
  if (value > 255u) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(uint64_t value) {
  if (value > 255lu) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(ullong_t value) {
  if (value > 255llu) throw overflow_exception(csf_);
  return static_cast<char8_t>(value);
}

char8_t convert::to_char8(const ustring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const u8string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const u16string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const u32string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const wstring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(const wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char8_t convert::to_char8(wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(any value) {
  try {
    return any_cast<char16_t>(value);
  } catch(...) {
    try {
      return *any_cast<char16_t*>(value);
    } catch(...) {
      throw invalid_cast_exception(csf_);
    }
  }
}

char16_t convert::to_char16(bool value) {
  throw invalid_cast_exception(csf_);
}

char16_t convert::to_char16(byte_t value) noexcept {
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(char value) noexcept {
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(char8_t value) noexcept {
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(char16_t value) noexcept {
  return value;
}

char16_t convert::to_char16(char32_t value) {
  if (value > static_cast<char32_t>(65535)) throw overflow_exception(csf_);
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(wchar_t value) noexcept {
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(decimal_t value) {
  if (value < 0.0l || value > 65535.0l) throw overflow_exception(csf_);
  return static_cast<char16_t>(round(value));
}

char16_t convert::to_char16(double value) {
  if (value < 0.0 || value > 65535.0) throw overflow_exception(csf_);
  return static_cast<char16_t>(round(value));
}

char16_t convert::to_char16(float value) {
  if (value < 0.0f || value > 65535.0f) throw overflow_exception(csf_);
  return static_cast<char16_t>(round(value));
}

char16_t convert::to_char16(int16_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return value;
}

char16_t convert::to_char16(int32_t value) {
  if (value < 0 || value > 65535) throw overflow_exception(csf_);
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(int64_t value) {
  if (value < 0l || value > 65535l) throw overflow_exception(csf_);
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(llong_t value) {
  if (value < 0ll || value > 65535ll) throw overflow_exception(csf_);
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(sbyte_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(uint16_t value) noexcept {
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(uint32_t value) {
  if (value > 65535u) throw overflow_exception(csf_);
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(uint64_t value) {
  if (value > 65535lu) throw overflow_exception(csf_);
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(ullong_t value) {
  if (value > 65535llu) throw overflow_exception(csf_);
  return static_cast<char16_t>(value);
}

char16_t convert::to_char16(const ustring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const u8string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const u16string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const u32string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const wstring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(const wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char16_t convert::to_char16(wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(any value) {
  try {
    return any_cast<char32_t>(value);
  } catch(...) {
    try {
      return *any_cast<char32_t*>(value);
    } catch(...) {
      throw invalid_cast_exception(csf_);
    }
  }
}

char32_t convert::to_char32(bool value) {
  throw invalid_cast_exception(csf_);
}

char32_t convert::to_char32(byte_t value) noexcept {
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(char value) noexcept {
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(char8_t value) noexcept {
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(char16_t value) noexcept {
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(char32_t value) noexcept {
  return value;
}

char32_t convert::to_char32(wchar_t value) noexcept {
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(decimal_t value) {
  if (value < 0.0l || value > 4294967295.0l) throw overflow_exception(csf_);
  return static_cast<char32_t>(round(value));
}

char32_t convert::to_char32(double value) {
  if (value < 0.0 || value > 4294967295.0) throw overflow_exception(csf_);
  return static_cast<char32_t>(round(value));
}

char32_t convert::to_char32(float value) {
  if (value < 0.0f) throw overflow_exception(csf_);
  return static_cast<char32_t>(round(value));
}

char32_t convert::to_char32(int16_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return value;
}

char32_t convert::to_char32(int32_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(int64_t value) {
  if (value < 0l || value > 4294967295l) throw overflow_exception(csf_);
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(llong_t value) {
  if (value < 0ll || value > 4294967295ll) throw overflow_exception(csf_);
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(sbyte_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(uint16_t value) noexcept {
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(uint32_t value) noexcept {
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(uint64_t value) {
  if (value > 4294967295lu) throw overflow_exception(csf_);
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(ullong_t value) {
  if (value > 4294967295llu) throw overflow_exception(csf_);
  return static_cast<char32_t>(value);
}

char32_t convert::to_char32(const ustring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const u8string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const u16string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const u32string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const wstring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(const wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

char32_t convert::to_char32(wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(any value) {
  try {
    return any_cast<wchar_t>(value);
  } catch(...) {
    try {
      return *any_cast<wchar_t*>(value);
    } catch(...) {
      throw invalid_cast_exception(csf_);
    }
  }
}

wchar_t convert::to_wchar(bool value) {
  throw invalid_cast_exception(csf_);
}

wchar_t convert::to_wchar(byte_t value) noexcept {
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(char value) noexcept {
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(char8_t value) noexcept {
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(char16_t value) noexcept {
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(char32_t value) {
  if (value > static_cast<char32_t>(65535)) throw overflow_exception(csf_);
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(wchar_t value) noexcept {
  return value;
}

wchar_t convert::to_wchar(decimal_t value) {
  if (value < 0.0l || value > 65535.0l) throw overflow_exception(csf_);
  return static_cast<wchar_t>(round(value));
}

wchar_t convert::to_wchar(double value) {
  if (value < 0.0 || value > 65535.0) throw overflow_exception(csf_);
  return static_cast<wchar_t>(round(value));
}

wchar_t convert::to_wchar(float value) {
  if (value < 0.0f || value > 65535.0f) throw overflow_exception(csf_);
  return static_cast<wchar_t>(round(value));
}

wchar_t convert::to_wchar(int16_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return value;
}

wchar_t convert::to_wchar(int32_t value) {
  if (value < 0 || value > 65535) throw overflow_exception(csf_);
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(int64_t value) {
  if (value < 0l || value > 65535l) throw overflow_exception(csf_);
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(llong_t value) {
  if (value < 0ll || value > 65535ll) throw overflow_exception(csf_);
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(sbyte_t value) {
  if (value < 0) throw overflow_exception(csf_);
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(uint16_t value) noexcept {
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(uint32_t value) {
  if (value > 65535u) throw overflow_exception(csf_);
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(uint64_t value) {
  if (value > 65535lu) throw overflow_exception(csf_);
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(ullong_t value) {
  if (value > 65535llu) throw overflow_exception(csf_);
  return static_cast<wchar_t>(value);
}

wchar_t convert::to_wchar(const ustring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const u8string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const u16string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const u32string& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const wstring& value) {
  if (value.size() != 1) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(char* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(char8_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(char16_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(char32_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(const wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

wchar_t convert::to_wchar(wchar_t* value) {
  if (value[0] == 0 || value[1] != 0) throw format_exception(csf_);
  return to_char(value[0]);
}

decimal_t convert::to_decimal(any value) {
  try {
    return any_cast<decimal_t>(value);
  } catch(...) {
    throw invalid_cast_exception(csf_);
  }
}

decimal_t convert::to_decimal(bool value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(byte_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(char value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(char8_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(char16_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(char32_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(wchar_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(decimal_t value) noexcept {
  return value;
}

decimal_t convert::to_decimal(double value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(float value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(int16_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(int32_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(int64_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(llong_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(sbyte_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(uint16_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(uint32_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(uint64_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(ullong_t value) noexcept {
  return static_cast<decimal_t>(value);
}

decimal_t convert::to_decimal(const ustring& value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const string& value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const u8string& value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const u16string& value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const u32string& value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const wstring& value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const char* value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(char* value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const char8_t* value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(char8_t* value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const char16_t* value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(char16_t* value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const char32_t* value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(char32_t* value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(const wchar_t* value) {
  return ustring::parse<decimal_t>(value);
}

decimal_t convert::to_decimal(wchar_t* value) {
  return ustring::parse<decimal_t>(value);
}

double convert::to_double(any value) {
  try {
    return any_cast<double>(value);
  } catch(...) {
    throw invalid_cast_exception(csf_);
  }
}

double convert::to_double(bool value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(byte_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(char value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(char8_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(char16_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(char32_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(wchar_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(decimal_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(double value) noexcept {
  return value;
}

double convert::to_double(float value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(int16_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(int32_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(int64_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(llong_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(sbyte_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(uint16_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(uint32_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(uint64_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(ullong_t value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(const ustring& value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const string& value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const u8string& value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const u16string& value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const u32string& value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const wstring& value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const char* value) {
  return ustring::parse<double>(value);
}

double convert::to_double(char* value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const char8_t* value) {
  return ustring::parse<double>(value);
}

double convert::to_double(char8_t* value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const char16_t* value) {
  return ustring::parse<double>(value);
}

double convert::to_double(char16_t* value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const char32_t* value) {
  return ustring::parse<double>(value);
}

double convert::to_double(char32_t* value) {
  return ustring::parse<double>(value);
}

double convert::to_double(const wchar_t* value) {
  return ustring::parse<double>(value);
}

double convert::to_double(wchar_t* value) {
  return ustring::parse<double>(value);
}

float convert::to_single(any value) {
  try {
    return any_cast<float>(value);
  } catch(...) {
    throw invalid_cast_exception(csf_);
  }
}

float convert::to_single(bool value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(byte_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(char value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(char8_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(char16_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(char32_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(wchar_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(decimal_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(double value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(float value) noexcept {
  return value;
}

float convert::to_single(int16_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(int32_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(int64_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(llong_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(sbyte_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(uint16_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(uint32_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(uint64_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(ullong_t value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(const ustring& value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const string& value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const u8string& value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const u16string& value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const u32string& value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const wstring& value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const char* value) {
  return ustring::parse<float>(value);
}

float convert::to_single(char* value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const char8_t* value) {
  return ustring::parse<float>(value);
}

float convert::to_single(char8_t* value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const char16_t* value) {
  return ustring::parse<float>(value);
}

float convert::to_single(char16_t* value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const char32_t* value) {
  return ustring::parse<float>(value);
}

float convert::to_single(char32_t* value) {
  return ustring::parse<float>(value);
}

float convert::to_single(const wchar_t* value) {
  return ustring::parse<float>(value);
}

float convert::to_single(wchar_t* value) {
  return ustring::parse<float>(value);
}

int16_t convert::to_int16(any value) {
  try {
    return any_cast<int16_t>(value);
  } catch(...) {
    throw invalid_cast_exception(csf_);
  }
}

int16_t convert::to_int16(bool value) noexcept {
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(byte_t value) noexcept {
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(char value) noexcept {
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(char8_t value) noexcept {
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(char16_t value) noexcept {
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(char32_t value) {
  if (value > static_cast<char32_t>(0xFFFF)) throw overflow_exception(csf_);
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(wchar_t value) noexcept {
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(decimal_t value) {
  if (value < static_cast<decimal_t>(numeric_limits<int16_t>::min()) || value > static_cast<decimal_t>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(round(value));
}

int16_t convert::to_int16(double value) {
  if (value < static_cast<double>(numeric_limits<int16_t>::min()) || value > static_cast<double>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(round(value));
}

int16_t convert::to_int16(float value) {
  if (value < static_cast<float>(numeric_limits<int16_t>::min()) || value > static_cast<float>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(round(value));
}

int16_t convert::to_int16(int16_t value) noexcept {
  return value;
}

int16_t convert::to_int16(int32_t value) {
  if (value < static_cast<int32_t>(numeric_limits<int16_t>::min()) || value > static_cast<int32_t>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(int64_t value) {
  if (value < static_cast<int64_t>(numeric_limits<int16_t>::min()) || value > static_cast<int64_t>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(llong_t value) {
  if (value < static_cast<llong_t>(numeric_limits<int16_t>::min()) || value > static_cast<llong_t>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(sbyte_t value) noexcept {
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(uint16_t value) {
  if (value > static_cast<uint16_t>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(uint32_t value) {
  if (value > static_cast<uint32_t>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(uint64_t value) {
  if (value > static_cast<uint64_t>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(ullong_t value) {
  if (value > static_cast<ullong_t>(numeric_limits<int16_t>::max())) throw overflow_exception(csf_);
  return static_cast<int16_t>(value);
}

int16_t convert::to_int16(const ustring& value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const string& value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const u8string& value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const u16string& value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const u32string& value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const wstring& value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const char* value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(char* value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const char8_t* value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(char8_t* value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const char16_t* value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(char16_t* value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const char32_t* value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(char32_t* value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(const wchar_t* value) {
  return ustring::parse<int16_t>(value);
}

int16_t convert::to_int16(wchar_t* value) {
  return ustring::parse<int16_t>(value);
}

int32_t convert::to_int32(any value) {
  try {
    return any_cast<int32_t>(value);
  } catch(...) {
    throw invalid_cast_exception(csf_);
  }
}

int32_t convert::to_int32(bool value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(byte_t value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(char value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(char8_t value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(char16_t value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(char32_t value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(wchar_t value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(decimal_t value) {
  if (value < static_cast<decimal_t>(numeric_limits<int32_t>::min()) || value > static_cast<decimal_t>(numeric_limits<int32_t>::max())) throw overflow_exception(csf_);
  return static_cast<int32_t>(round(value));
}

int32_t convert::to_int32(double value) {
  if (value < static_cast<double>(numeric_limits<int32_t>::min()) || value > static_cast<double>(numeric_limits<int32_t>::max())) throw overflow_exception(csf_);
  return static_cast<int32_t>(round(value));
}

int32_t convert::to_int32(float value) noexcept {
  return static_cast<int32_t>(round(value));
}

int32_t convert::to_int32(int16_t value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(int32_t value) noexcept {
  return value;
}

int32_t convert::to_int32(int64_t value) {
  if (value < static_cast<int64_t>(numeric_limits<int32_t>::min()) || value > static_cast<int64_t>(numeric_limits<int32_t>::max())) throw overflow_exception(csf_);
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(llong_t value) {
  if (value < static_cast<llong_t>(numeric_limits<int32_t>::min()) || value > static_cast<llong_t>(numeric_limits<int32_t>::max())) throw overflow_exception(csf_);
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(sbyte_t value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(uint16_t value) noexcept {
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(uint32_t value) {
  if (value > static_cast<uint32_t>(numeric_limits<int32_t>::max())) throw overflow_exception(csf_);
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(uint64_t value) {
  if (value > static_cast<uint64_t>(numeric_limits<int32_t>::max())) throw overflow_exception(csf_);
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(ullong_t value) {
  if (value > static_cast<ullong_t>(numeric_limits<int32_t>::max())) throw overflow_exception(csf_);
  return static_cast<int32_t>(value);
}

int32_t convert::to_int32(const ustring& value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const string& value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const u8string& value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const u16string& value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const u32string& value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const wstring& value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const char* value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(char* value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const char8_t* value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(char8_t* value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const char16_t* value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(char16_t* value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const char32_t* value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(char32_t* value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(const wchar_t* value) {
  return ustring::parse<int32_t>(value);
}

int32_t convert::to_int32(wchar_t* value) {
  return ustring::parse<int32_t>(value);
}

int64_t convert::to_int64(any value) {
  try {
    return any_cast<int64_t>(value);
  } catch(...) {
    throw invalid_cast_exception(csf_);
  }
}

int64_t convert::to_int64(bool value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(byte_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(char value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(char8_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(char16_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(char32_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(wchar_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(decimal_t value) noexcept {
  return static_cast<int64_t>(round(value));
}

int64_t convert::to_int64(double value) noexcept {
  return static_cast<int64_t>(round(value));
}

int64_t convert::to_int64(float value) noexcept {
  return static_cast<int64_t>(round(value));
}

int64_t convert::to_int64(int16_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(int32_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(int64_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(llong_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(sbyte_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(uint16_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(uint32_t value) noexcept {
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(uint64_t value) {
  if (value > static_cast<uint64_t>(numeric_limits<int64_t>::max())) throw overflow_exception(csf_);
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(ullong_t value) {
  if (value > static_cast<ullong_t>(numeric_limits<int64_t>::max())) throw overflow_exception(csf_);
  return static_cast<int64_t>(value);
}

int64_t convert::to_int64(const ustring& value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const string& value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const u8string& value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const u16string& value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const u32string& value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const wstring& value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const char* value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(char* value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const char8_t* value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(char8_t* value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const char16_t* value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(char16_t* value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const char32_t* value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(char32_t* value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(const wchar_t* value) {
  return ustring::parse<int64_t>(value);
}

int64_t convert::to_int64(wchar_t* value) {
  return ustring::parse<int64_t>(value);
}
