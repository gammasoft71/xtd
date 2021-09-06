#include "../../include/xtd/invalid_cast_exception.h"
#include "../../include/xtd/convert.h"

using namespace std;
using namespace xtd;

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

bool convert::to_boolean(char value) noexcept {
  return value != 0;
}

bool convert::to_boolean(char8_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(char16_t value) noexcept {
  return value != 0;
}

bool convert::to_boolean(char32_t value) noexcept {
  return value != 0;
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

bool convert::to_boolean(const char8_t* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const char16_t* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const char32_t* value) {
  return ustring::parse<bool>(value);
}

bool convert::to_boolean(const wchar_t* value) {
  return ustring::parse<bool>(value);
}
