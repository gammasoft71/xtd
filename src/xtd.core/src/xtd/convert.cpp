#include "../../include/xtd/convert.hpp"
#include "../../include/xtd/math.hpp"
#include "../../include/xtd/fixed_array.hpp"

using namespace xtd;
using namespace xtd::helpers;

namespace {
  static const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  
  static bool is_base64(byte c) {return (std::isalnum(c) || (c == '+') || (c == '/'));}
}

// https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c
array<byte> convert::from_base64_string(const string& s) {
  //if (s.size() % 4 != 0) throw_helper::throws(xtd::helpers::exception_case::format);
  auto in_len = s.size();
  auto i = 0_z;
  auto j = 0_z;
  auto in_ = 0_z;
  auto char_array_4 = fixed_array<byte, 4> {};
  auto char_array_3 = fixed_array<byte, 3> {};
  std::vector<byte> ret;
  
  while (in_len-- && ( s[in_] != '=') && is_base64(s[in_])) {
    char_array_4[i++] = s[in_]; in_++;
    if (i == 4) {
      for (i = 0; i < 4; i++)
        char_array_4[i] = static_cast<byte>(base64_chars.find(char_array_4[i]));
      
      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
      
      for (i = 0; (i < 3); i++)
        ret.push_back(char_array_3[i]);
      i = 0;
    }
  }
  
  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;
    
    for (j = 0; j <4; j++)
      char_array_4[j] = static_cast<byte>(base64_chars.find(char_array_4[j]));
    
    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
    
    for (j = 0; (j < i - 1); j++) ret.push_back(char_array_3[j]);
  }
  
  return ret;
}

std::any convert::to_any(std::any value) noexcept {
  return value;
}

std::any convert::to_any(bool value) noexcept {
  return value;
}

std::any convert::to_any(xtd::byte value) noexcept {
  return value;
}

std::any convert::to_any(char value) noexcept {
  return value;
}

#if defined(__xtd__cpp_lib_char8_t)
std::any convert::to_any(char8 value) {
  //return value;
  throw_helper::throws(exception_case::invalid_cast);
}
#endif

std::any convert::to_any(char16 value) noexcept {
  return value;
}

std::any convert::to_any(char32 value) noexcept {
  return value;
}

std::any convert::to_any(wchar value) noexcept {
  return value;
}

std::any convert::to_any(decimal value) noexcept {
  return value;
}

std::any convert::to_any(double value) noexcept {
  return value;
}

std::any convert::to_any(float value) noexcept {
  return value;
}

std::any convert::to_any(int16 value) noexcept {
  return value;
}

std::any convert::to_any(int32 value) noexcept {
  return value;
}

std::any convert::to_any(int64 value) noexcept {
  return value;
}

std::any convert::to_any(slong value) noexcept {
  return value;
}

std::any convert::to_any(sbyte value) noexcept {
  return value;
}

std::any convert::to_any(uint16 value) noexcept {
  return value;
}

std::any convert::to_any(uint32 value) noexcept {
  return value;
}

std::any convert::to_any(uint64 value) noexcept {
  return value;
}

std::any convert::to_any(xtd::ulong value) noexcept {
  return value;
}

std::any convert::to_any(const string& value) noexcept {
  return value;
}

std::any convert::to_any(const std::string& value) noexcept {
  return value;
}

#if defined(__xtd__cpp_lib_char8_t)
std::any convert::to_any(const std::u8string& value) noexcept {
  return value;
}
#endif

std::any convert::to_any(const std::u16string& value) noexcept {
  return value;
}

std::any convert::to_any(const std::u32string& value) noexcept {
  return value;
}

std::any convert::to_any(const std::wstring& value) noexcept {
  return value;
}

std::any convert::to_any(const char* value) noexcept {
  return value;
}

std::any convert::to_any(char* value) noexcept {
  return value;
}

#if defined(__xtd__cpp_lib_char8_t)
std::any convert::to_any(const char8* value) {
  //return value;
  throw_helper::throws(exception_case::invalid_cast);
}

std::any convert::to_any(char8* value) {
  //return value;
  throw_helper::throws(exception_case::invalid_cast);
}
#endif

std::any convert::to_any(const char16* value) noexcept {
  return value;
}

std::any convert::to_any(char16* value) noexcept {
  return value;
}

std::any convert::to_any(const char32* value) noexcept {
  return value;
}

std::any convert::to_any(char32* value) noexcept {
  return value;
}

std::any convert::to_any(const wchar* value) noexcept {
  return value;
}

std::any convert::to_any(wchar* value) noexcept {
  return value;
}

// https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c
string convert::to_base64_string(const array<byte>& in_array) {
  return to_base64_string(read_only_span<byte>(in_array));
}

string convert::to_base64_string(const xtd::read_only_span<xtd::byte>& bytes) {
  auto ret = string {};
  auto i = 0_z;
  auto j = 0_z;
  byte char_array_3[3];
  byte char_array_4[4];
  auto buf = bytes.data();
  auto bufLen = bytes.size();
  
  while (bufLen--) {
    char_array_3[i++] = *(buf++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;
      
      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }
  
  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';
    
    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;
    
    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];
    
    while((i++ < 3))
      ret += '=';
  }
  
  return ret;
}

bool convert::to_boolean(std::any value) {
  try {
    return std::any_cast<bool>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

bool convert::to_boolean(bool value) noexcept {
  return value;
}

bool convert::to_boolean(xtd::byte value) noexcept {
  return value != 0u;
}

bool convert::to_boolean(char value) {
  throw_helper::throws(exception_case::invalid_cast);
}

#if defined(__xtd__cpp_lib_char8_t)
bool convert::to_boolean(char8 value) {
  throw_helper::throws(exception_case::invalid_cast);
}
#endif

bool convert::to_boolean(char16 value) {
  throw_helper::throws(exception_case::invalid_cast);
}

bool convert::to_boolean(char32 value) {
  throw_helper::throws(exception_case::invalid_cast);
}

bool convert::to_boolean(wchar value) {
  throw_helper::throws(exception_case::invalid_cast);
}

bool convert::to_boolean(decimal value) noexcept {
  return value != .0l;
}

bool convert::to_boolean(double value) noexcept {
  return value != .0;
}

bool convert::to_boolean(float value) noexcept {
  return value != .0f;
}

bool convert::to_boolean(int16 value) noexcept {
  return value != 0;
}

bool convert::to_boolean(int32 value) noexcept {
  return value != 0;
}

bool convert::to_boolean(int64 value) noexcept {
  return value != 0;
}

bool convert::to_boolean(slong value) noexcept {
  return value != 0;
}

bool convert::to_boolean(sbyte value) noexcept {
  return value != 0;
}

bool convert::to_boolean(uint16 value) noexcept {
  return value != 0;
}

bool convert::to_boolean(uint32 value) noexcept {
  return value != 0;
}

bool convert::to_boolean(uint64 value) noexcept {
  return value != 0;
}

bool convert::to_boolean(xtd::ulong value) noexcept {
  return value != 0;
}

bool convert::to_boolean(const string& value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(const std::string& value) {
  return string::parse<bool>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
bool convert::to_boolean(const std::u8string& value) {
  return string::parse<bool>(value);
}
#endif

bool convert::to_boolean(const std::u16string& value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(const std::u32string& value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(const std::wstring& value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(const char* value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(char* value) {
  return string::parse<bool>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
bool convert::to_boolean(const char8* value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(char8* value) {
  return string::parse<bool>(value);
}
#endif

bool convert::to_boolean(const char16* value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(char16* value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(const char32* value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(char32* value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(const wchar* value) {
  return string::parse<bool>(value);
}

bool convert::to_boolean(wchar* value) {
  return string::parse<bool>(value);
}

xtd::byte convert::to_byte(std::any value) {
  try {
    return std::any_cast<xtd::byte>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

xtd::byte convert::to_byte(bool value) noexcept {
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(xtd::byte value) noexcept {
  return value;
}

xtd::byte convert::to_byte(char value) noexcept {
  return static_cast<xtd::byte>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::byte convert::to_byte(char8 value) noexcept {
  return static_cast<xtd::byte>(value);
}
#endif

xtd::byte convert::to_byte(char16 value) {
  if (value > static_cast<char16>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(char32 value) {
  if (value > static_cast<char32>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(wchar value) {
  if (value > static_cast<wchar>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(decimal value) {
  if (value < static_cast<decimal>(std::numeric_limits<xtd::byte>::lowest()) || value > static_cast<decimal>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(math::round(value));
}

xtd::byte convert::to_byte(double value) {
  if (value < static_cast<double>(std::numeric_limits<xtd::byte>::lowest()) || value > static_cast<double>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(math::round(value));
}

xtd::byte convert::to_byte(float value) {
  if (value < static_cast<float>(std::numeric_limits<xtd::byte>::lowest()) || value > static_cast<float>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(math::round(value));
}

xtd::byte convert::to_byte(int16 value) {
  if (value < static_cast<int16>(std::numeric_limits<xtd::byte>::lowest()) || value > static_cast<int16>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(int32 value) {
  if (value < static_cast<int32>(std::numeric_limits<xtd::byte>::lowest()) || value > static_cast<int32>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(int64 value) {
  if (value < static_cast<int64>(std::numeric_limits<xtd::byte>::lowest()) || value > static_cast<int64>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(slong value) {
  if (value < static_cast<slong>(std::numeric_limits<xtd::byte>::lowest()) || value > static_cast<slong>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(sbyte value) {
  if (value < static_cast<sbyte>(std::numeric_limits<xtd::byte>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(uint16 value) {
  if (value > static_cast<uint16>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(uint32 value) {
  if (value > static_cast<uint32>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(uint64 value) {
  if (value > static_cast<uint64>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(xtd::ulong value) {
  if (value > static_cast<xtd::ulong>(std::numeric_limits<xtd::byte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(value);
}

xtd::byte convert::to_byte(const string& value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<xtd::byte>(value, number_styles::binary_number); break;
    case 8: return parse<xtd::byte>(value, number_styles::octal_number); break;
    case 10: return parse<xtd::byte>(value, number_styles::integer); break;
    case 16: return parse<xtd::byte>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

xtd::byte convert::to_byte(const std::string& value) {
  return string::parse<xtd::byte>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::byte convert::to_byte(const std::u8string& value) {
  return string::parse<xtd::byte>(value);
}
#endif

xtd::byte convert::to_byte(const std::u16string& value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(const std::u32string& value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(const std::wstring& value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(const char* value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(char* value) {
  return string::parse<xtd::byte>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::byte convert::to_byte(const char8* value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(char8* value) {
  return string::parse<xtd::byte>(value);
}
#endif

xtd::byte convert::to_byte(const char16* value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(char16* value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(const char32* value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(char32* value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(const wchar* value) {
  return string::parse<xtd::byte>(value);
}

xtd::byte convert::to_byte(wchar* value) {
  return string::parse<xtd::byte>(value);
}

char convert::to_char(std::any value) {
  try {
    return std::any_cast<char>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

char convert::to_char(bool value) {
  throw_helper::throws(exception_case::invalid_cast);
}

char convert::to_char(xtd::byte value) noexcept {
  return static_cast<char>(value);
}

char convert::to_char(char value) noexcept {
  return value;
}

#if defined(__xtd__cpp_lib_char8_t)
char convert::to_char(char8 value) noexcept {
  return static_cast<char>(value);
}
#endif

char convert::to_char(char16 value) {
  if (value > static_cast<char16>(255)) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(char32 value) {
  if (value > static_cast<char32>(255)) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(wchar value) {
  if (value > static_cast<wchar>(255)) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(decimal value) {
  if (value < 0.0l || value > 255.0l) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(math::round(value));
}

char convert::to_char(double value) {
  if (value < 0.0 || value > 255.0) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(math::round(value));
}

char convert::to_char(float value) {
  if (value < 0.0f || value > 255.0f) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::byte>(math::round(value));
}

char convert::to_char(int16 value) {
  if (value < 0 || value > 255) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(int32 value) {
  if (value < 0 || value > 255) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(int64 value) {
  if (value < 0l || value > 255l) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(slong value) {
  if (value < 0ll || value > 255ll) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(sbyte value) {
  if (value < 0) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(uint16 value) {
  if (value > 255u) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(uint32 value) {
  if (value > 255u) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(uint64 value) {
  if (value > 255lu) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(xtd::ulong value) {
  if (value > 255llu) throw_helper::throws(exception_case::overflow);
  return static_cast<char>(value);
}

char convert::to_char(const string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(const std::string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

#if defined(__xtd__cpp_lib_char8_t)
char convert::to_char(const std::u8string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}
#endif

char convert::to_char(const std::u16string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(const std::u32string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(const std::wstring& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

#if defined(__xtd__cpp_lib_char8_t)
char convert::to_char(const char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}
#endif

char convert::to_char(const char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(const char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(const wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char convert::to_char(wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

#if defined(__xtd__cpp_lib_char8_t)
char8 convert::to_char8(std::any value) {
  throw_helper::throws(exception_case::invalid_cast);
}

char8 convert::to_char8(bool value) {
  throw_helper::throws(exception_case::invalid_cast);
}

char8 convert::to_char8(xtd::byte value) noexcept {
  return static_cast<char8>(value);
}

char8 convert::to_char8(char value) noexcept {
  return static_cast<char8>(value);
}

char8 convert::to_char8(char8 value) noexcept {
  return value;
}

char8 convert::to_char8(char16 value) {
  if (value > static_cast<char16>(255)) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(char32 value) {
  if (value > static_cast<char32>(255)) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(wchar value) {
  if (value > static_cast<wchar>(255)) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(decimal value) {
  if (value < 0.0l || value > 255.0l) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(math::round(value));
}

char8 convert::to_char8(double value) {
  if (value < 0.0 || value > 255.0) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(math::round(value));
}

char8 convert::to_char8(float value) {
  if (value < 0.0f || value > 255.0f) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(math::round(value));
}

char8 convert::to_char8(int16 value) {
  if (value < 0 || value > 255) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(int32 value) {
  if (value < 0 || value > 255) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(int64 value) {
  if (value < 0l || value > 255l) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(slong value) {
  if (value < 0ll || value > 255ll) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(sbyte value) {
  if (value < 0) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(uint16 value) {
  if (value > 255u) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(uint32 value) {
  if (value > 255u) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(uint64 value) {
  if (value > 255lu) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(xtd::ulong value) {
  if (value > 255llu) throw_helper::throws(exception_case::overflow);
  return static_cast<char8>(value);
}

char8 convert::to_char8(const string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const std::string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const std::u8string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const std::u16string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const std::u32string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const std::wstring& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(const wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char8 convert::to_char8(wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}
#endif

char16 convert::to_char16(std::any value) {
  try {
    return std::any_cast<char16>(value);
  } catch (...) {
    try {
      return *std::any_cast<char16*>(value);
    } catch (...) {
      throw_helper::throws(exception_case::invalid_cast);
    }
  }
}

char16 convert::to_char16(bool value) {
  throw_helper::throws(exception_case::invalid_cast);
}

char16 convert::to_char16(xtd::byte value) noexcept {
  return static_cast<char16>(value);
}

char16 convert::to_char16(char value) noexcept {
  return static_cast<char16>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
char16 convert::to_char16(char8 value) noexcept {
  return static_cast<char16>(value);
}
#endif

char16 convert::to_char16(char16 value) noexcept {
  return value;
}

char16 convert::to_char16(char32 value) {
  if (value > static_cast<char32>(65535)) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(value);
}

char16 convert::to_char16(wchar value) noexcept {
  return static_cast<char16>(value);
}

char16 convert::to_char16(decimal value) {
  if (value < 0.0l || value > 65535.0l) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(math::round(value));
}

char16 convert::to_char16(double value) {
  if (value < 0.0 || value > 65535.0) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(math::round(value));
}

char16 convert::to_char16(float value) {
  if (value < 0.0f || value > 65535.0f) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(math::round(value));
}

char16 convert::to_char16(int16 value) {
  if (value < 0) throw_helper::throws(exception_case::overflow);
  return value;
}

char16 convert::to_char16(int32 value) {
  if (value < 0 || value > 65535) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(value);
}

char16 convert::to_char16(int64 value) {
  if (value < 0l || value > 65535l) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(value);
}

char16 convert::to_char16(slong value) {
  if (value < 0ll || value > 65535ll) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(value);
}

char16 convert::to_char16(sbyte value) {
  if (value < 0) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(value);
}

char16 convert::to_char16(uint16 value) noexcept {
  return static_cast<char16>(value);
}

char16 convert::to_char16(uint32 value) {
  if (value > 65535u) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(value);
}

char16 convert::to_char16(uint64 value) {
  if (value > 65535lu) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(value);
}

char16 convert::to_char16(xtd::ulong value) {
  if (value > 65535llu) throw_helper::throws(exception_case::overflow);
  return static_cast<char16>(value);
}

char16 convert::to_char16(const string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(const std::string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

#if defined(__xtd__cpp_lib_char8_t)
char16 convert::to_char16(const std::u8string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}
#endif

char16 convert::to_char16(const std::u16string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(const std::u32string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(const std::wstring& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

#if defined(__xtd__cpp_lib_char8_t)
char16 convert::to_char16(const char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}
#endif

char16 convert::to_char16(const char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(const char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(const wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char16 convert::to_char16(wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(std::any value) {
  try {
    return std::any_cast<char32>(value);
  } catch (...) {
    try {
      return *std::any_cast<char32*>(value);
    } catch (...) {
      throw_helper::throws(exception_case::invalid_cast);
    }
  }
}

char32 convert::to_char32(bool value) {
  throw_helper::throws(exception_case::invalid_cast);
}

char32 convert::to_char32(xtd::byte value) noexcept {
  return static_cast<char32>(value);
}

char32 convert::to_char32(char value) noexcept {
  return static_cast<char32>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
char32 convert::to_char32(char8 value) noexcept {
  return static_cast<char32>(value);
}
#endif

char32 convert::to_char32(char16 value) noexcept {
  return static_cast<char32>(value);
}

char32 convert::to_char32(char32 value) noexcept {
  return value;
}

char32 convert::to_char32(wchar value) noexcept {
  return static_cast<char32>(value);
}

char32 convert::to_char32(decimal value) {
  if (value < 0.0l || value > 4294967295.0l) throw_helper::throws(exception_case::overflow);
  return static_cast<char32>(math::round(value));
}

char32 convert::to_char32(double value) {
  if (value < 0.0 || value > 4294967295.0) throw_helper::throws(exception_case::overflow);
  return static_cast<char32>(math::round(value));
}

char32 convert::to_char32(float value) {
  if (value < 0.0f) throw_helper::throws(exception_case::overflow);
  return static_cast<char32>(math::round(value));
}

char32 convert::to_char32(int16 value) {
  if (value < 0) throw_helper::throws(exception_case::overflow);
  return value;
}

char32 convert::to_char32(int32 value) {
  if (value < 0) throw_helper::throws(exception_case::overflow);
  return static_cast<char32>(value);
}

char32 convert::to_char32(int64 value) {
  if (value < 0l || value > 4294967295l) throw_helper::throws(exception_case::overflow);
  return static_cast<char32>(value);
}

char32 convert::to_char32(slong value) {
  if (value < 0ll || value > 4294967295ll) throw_helper::throws(exception_case::overflow);
  return static_cast<char32>(value);
}

char32 convert::to_char32(sbyte value) {
  if (value < 0) throw_helper::throws(exception_case::overflow);
  return static_cast<char32>(value);
}

char32 convert::to_char32(uint16 value) noexcept {
  return static_cast<char32>(value);
}

char32 convert::to_char32(uint32 value) noexcept {
  return static_cast<char32>(value);
}

char32 convert::to_char32(uint64 value) {
  if (value > 4294967295lu) throw_helper::throws(exception_case::overflow);
  return static_cast<char32>(value);
}

char32 convert::to_char32(xtd::ulong value) {
  if (value > 4294967295llu) throw_helper::throws(exception_case::overflow);
  return static_cast<char32>(value);
}

char32 convert::to_char32(const string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(const std::string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

#if defined(__xtd__cpp_lib_char8_t)
char32 convert::to_char32(const std::u8string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}
#endif

char32 convert::to_char32(const std::u16string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(const std::u32string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(const std::wstring& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

#if defined(__xtd__cpp_lib_char8_t)
char32 convert::to_char32(const char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}
#endif

char32 convert::to_char32(const char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(const char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(const wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

char32 convert::to_char32(wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(std::any value) {
  try {
    return std::any_cast<wchar>(value);
  } catch (...) {
    try {
      return *std::any_cast<wchar*>(value);
    } catch (...) {
      throw_helper::throws(exception_case::invalid_cast);
    }
  }
}

wchar convert::to_wchar(bool value) {
  throw_helper::throws(exception_case::invalid_cast);
}

wchar convert::to_wchar(xtd::byte value) noexcept {
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(char value) noexcept {
  return static_cast<wchar>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
wchar convert::to_wchar(char8 value) noexcept {
  return static_cast<wchar>(value);
}
#endif

wchar convert::to_wchar(char16 value) noexcept {
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(char32 value) {
  if (value > static_cast<char32>(65535)) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(wchar value) noexcept {
  return value;
}

wchar convert::to_wchar(decimal value) {
  if (value < 0.0l || value > 65535.0l) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(math::round(value));
}

wchar convert::to_wchar(double value) {
  if (value < 0.0 || value > 65535.0) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(math::round(value));
}

wchar convert::to_wchar(float value) {
  if (value < 0.0f || value > 65535.0f) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(math::round(value));
}

wchar convert::to_wchar(int16 value) {
  if (value < 0) throw_helper::throws(exception_case::overflow);
  return value;
}

wchar convert::to_wchar(int32 value) {
  if (value < 0 || value > 65535) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(int64 value) {
  if (value < 0l || value > 65535l) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(slong value) {
  if (value < 0ll || value > 65535ll) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(sbyte value) {
  if (value < 0) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(uint16 value) noexcept {
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(uint32 value) {
  if (value > 65535u) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(uint64 value) {
  if (value > 65535lu) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(xtd::ulong value) {
  if (value > 65535llu) throw_helper::throws(exception_case::overflow);
  return static_cast<wchar>(value);
}

wchar convert::to_wchar(const string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(const std::string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

#if defined(__xtd__cpp_lib_char8_t)
wchar convert::to_wchar(const std::u8string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}
#endif

wchar convert::to_wchar(const std::u16string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(const std::u32string& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(const std::wstring& value) {
  if (value.size() != 1) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(const char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(char* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

#if defined(__xtd__cpp_lib_char8_t)
wchar convert::to_wchar(const char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(char8* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}
#endif

wchar convert::to_wchar(const char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(char16* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(const char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(char32* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(const wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

wchar convert::to_wchar(wchar* value) {
  if (value[0] == 0 || value[1] != 0) throw_helper::throws(exception_case::format);
  return to_char(value[0]);
}

decimal convert::to_decimal(std::any value) {
  try {
    return std::any_cast<decimal>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

decimal convert::to_decimal(bool value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(xtd::byte value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(char value) noexcept {
  return static_cast<decimal>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
decimal convert::to_decimal(char8 value) noexcept {
  return static_cast<decimal>(value);
}
#endif

decimal convert::to_decimal(char16 value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(char32 value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(wchar value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(decimal value) noexcept {
  return value;
}

decimal convert::to_decimal(double value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(float value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(int16 value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(int32 value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(int64 value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(slong value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(sbyte value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(uint16 value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(uint32 value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(uint64 value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(xtd::ulong value) noexcept {
  return static_cast<decimal>(value);
}

decimal convert::to_decimal(const string& value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(const std::string& value) {
  return string::parse<decimal>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
decimal convert::to_decimal(const std::u8string& value) {
  return string::parse<decimal>(value);
}
#endif

decimal convert::to_decimal(const std::u16string& value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(const std::u32string& value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(const std::wstring& value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(const char* value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(char* value) {
  return string::parse<decimal>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
decimal convert::to_decimal(const char8* value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(char8* value) {
  return string::parse<decimal>(value);
}
#endif

decimal convert::to_decimal(const char16* value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(char16* value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(const char32* value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(char32* value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(const wchar* value) {
  return string::parse<decimal>(value);
}

decimal convert::to_decimal(wchar* value) {
  return string::parse<decimal>(value);
}

double convert::to_double(std::any value) {
  try {
    return std::any_cast<double>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

double convert::to_double(bool value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(xtd::byte value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(char value) noexcept {
  return static_cast<double>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
double convert::to_double(char8 value) noexcept {
  return static_cast<double>(value);
}
#endif

double convert::to_double(char16 value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(char32 value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(wchar value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(decimal value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(double value) noexcept {
  return value;
}

double convert::to_double(float value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(int16 value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(int32 value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(int64 value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(slong value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(sbyte value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(uint16 value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(uint32 value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(uint64 value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(xtd::ulong value) noexcept {
  return static_cast<double>(value);
}

double convert::to_double(const string& value) {
  return string::parse<double>(value);
}

double convert::to_double(const std::string& value) {
  return string::parse<double>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
double convert::to_double(const std::u8string& value) {
  return string::parse<double>(value);
}
#endif

double convert::to_double(const std::u16string& value) {
  return string::parse<double>(value);
}

double convert::to_double(const std::u32string& value) {
  return string::parse<double>(value);
}

double convert::to_double(const std::wstring& value) {
  return string::parse<double>(value);
}

double convert::to_double(const char* value) {
  return string::parse<double>(value);
}

double convert::to_double(char* value) {
  return string::parse<double>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
double convert::to_double(const char8* value) {
  return string::parse<double>(value);
}

double convert::to_double(char8* value) {
  return string::parse<double>(value);
}
#endif

double convert::to_double(const char16* value) {
  return string::parse<double>(value);
}

double convert::to_double(char16* value) {
  return string::parse<double>(value);
}

double convert::to_double(const char32* value) {
  return string::parse<double>(value);
}

double convert::to_double(char32* value) {
  return string::parse<double>(value);
}

double convert::to_double(const wchar* value) {
  return string::parse<double>(value);
}

double convert::to_double(wchar* value) {
  return string::parse<double>(value);
}

float convert::to_single(std::any value) {
  try {
    return std::any_cast<float>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

float convert::to_single(bool value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(xtd::byte value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(char value) noexcept {
  return static_cast<float>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
float convert::to_single(char8 value) noexcept {
  return static_cast<float>(value);
}
#endif

float convert::to_single(char16 value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(char32 value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(wchar value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(decimal value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(double value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(float value) noexcept {
  return value;
}

float convert::to_single(int16 value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(int32 value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(int64 value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(slong value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(sbyte value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(uint16 value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(uint32 value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(uint64 value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(xtd::ulong value) noexcept {
  return static_cast<float>(value);
}

float convert::to_single(const string& value) {
  return string::parse<float>(value);
}

float convert::to_single(const std::string& value) {
  return string::parse<float>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
float convert::to_single(const std::u8string& value) {
  return string::parse<float>(value);
}
#endif

float convert::to_single(const std::u16string& value) {
  return string::parse<float>(value);
}

float convert::to_single(const std::u32string& value) {
  return string::parse<float>(value);
}

float convert::to_single(const std::wstring& value) {
  return string::parse<float>(value);
}

float convert::to_single(const char* value) {
  return string::parse<float>(value);
}

float convert::to_single(char* value) {
  return string::parse<float>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
float convert::to_single(const char8* value) {
  return string::parse<float>(value);
}

float convert::to_single(char8* value) {
  return string::parse<float>(value);
}
#endif

float convert::to_single(const char16* value) {
  return string::parse<float>(value);
}

float convert::to_single(char16* value) {
  return string::parse<float>(value);
}

float convert::to_single(const char32* value) {
  return string::parse<float>(value);
}

float convert::to_single(char32* value) {
  return string::parse<float>(value);
}

float convert::to_single(const wchar* value) {
  return string::parse<float>(value);
}

float convert::to_single(wchar* value) {
  return string::parse<float>(value);
}

int16 convert::to_int16(std::any value) {
  try {
    return std::any_cast<int16>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

int16 convert::to_int16(bool value) noexcept {
  return static_cast<int16>(value);
}

int16 convert::to_int16(xtd::byte value) noexcept {
  return static_cast<int16>(value);
}

int16 convert::to_int16(char value) noexcept {
  return static_cast<int16>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
int16 convert::to_int16(char8 value) noexcept {
  return static_cast<int16>(value);
}
#endif

int16 convert::to_int16(char16 value) noexcept {
  return static_cast<int16>(value);
}

int16 convert::to_int16(char32 value) {
  if (value > static_cast<char32>(0xFFFF)) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(value);
}

int16 convert::to_int16(wchar value) noexcept {
  return static_cast<int16>(value);
}

int16 convert::to_int16(decimal value) {
  if (value < static_cast<decimal>(std::numeric_limits<int16>::lowest()) || value > static_cast<decimal>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(math::round(value));
}

int16 convert::to_int16(double value) {
  if (value < static_cast<double>(std::numeric_limits<int16>::lowest()) || value > static_cast<double>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(math::round(value));
}

int16 convert::to_int16(float value) {
  if (value < static_cast<float>(std::numeric_limits<int16>::lowest()) || value > static_cast<float>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(math::round(value));
}

int16 convert::to_int16(int16 value) noexcept {
  return value;
}

int16 convert::to_int16(int32 value) {
  if (value < static_cast<int32>(std::numeric_limits<int16>::lowest()) || value > static_cast<int32>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(value);
}

int16 convert::to_int16(int64 value) {
  if (value < static_cast<int64>(std::numeric_limits<int16>::lowest()) || value > static_cast<int64>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(value);
}

int16 convert::to_int16(slong value) {
  if (value < static_cast<slong>(std::numeric_limits<int16>::lowest()) || value > static_cast<slong>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(value);
}

int16 convert::to_int16(sbyte value) noexcept {
  return static_cast<int16>(value);
}

int16 convert::to_int16(uint16 value) {
  if (value > static_cast<uint16>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(value);
}

int16 convert::to_int16(uint32 value) {
  if (value > static_cast<uint32>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(value);
}

int16 convert::to_int16(uint64 value) {
  if (value > static_cast<uint64>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(value);
}

int16 convert::to_int16(xtd::ulong value) {
  if (value > static_cast<xtd::ulong>(std::numeric_limits<int16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int16>(value);
}

int16 convert::to_int16(const string& value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<int16>(value, number_styles::binary_number); break;
    case 8: return parse<int16>(value, number_styles::octal_number); break;
    case 10: return parse<int16>(value, number_styles::integer); break;
    case 16: return parse<int16>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

int16 convert::to_int16(const std::string& value) {
  return string::parse<int16>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
int16 convert::to_int16(const std::u8string& value) {
  return string::parse<int16>(value);
}
#endif

int16 convert::to_int16(const std::u16string& value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(const std::u32string& value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(const std::wstring& value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(const char* value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(char* value) {
  return string::parse<int16>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
int16 convert::to_int16(const char8* value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(char8* value) {
  return string::parse<int16>(value);
}
#endif

int16 convert::to_int16(const char16* value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(char16* value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(const char32* value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(char32* value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(const wchar* value) {
  return string::parse<int16>(value);
}

int16 convert::to_int16(wchar* value) {
  return string::parse<int16>(value);
}

int32 convert::to_int32(std::any value) {
  try {
    return std::any_cast<int32>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

int32 convert::to_int32(bool value) noexcept {
  return static_cast<int32>(value);
}

int32 convert::to_int32(xtd::byte value) noexcept {
  return static_cast<int32>(value);
}

int32 convert::to_int32(char value) noexcept {
  return static_cast<int32>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
int32 convert::to_int32(char8 value) noexcept {
  return static_cast<int32>(value);
}
#endif

int32 convert::to_int32(char16 value) noexcept {
  return static_cast<int32>(value);
}

int32 convert::to_int32(char32 value) noexcept {
  return static_cast<int32>(value);
}

int32 convert::to_int32(wchar value) noexcept {
  return static_cast<int32>(value);
}

int32 convert::to_int32(decimal value) {
  if (value < static_cast<decimal>(std::numeric_limits<int32>::lowest()) || value > static_cast<decimal>(std::numeric_limits<int32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int32>(math::round(value));
}

int32 convert::to_int32(double value) {
  if (value < static_cast<double>(std::numeric_limits<int32>::lowest()) || value > static_cast<double>(std::numeric_limits<int32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int32>(math::round(value));
}

int32 convert::to_int32(float value) noexcept {
  return static_cast<int32>(math::round(value));
}

int32 convert::to_int32(int16 value) noexcept {
  return static_cast<int32>(value);
}

int32 convert::to_int32(int32 value) noexcept {
  return value;
}

int32 convert::to_int32(int64 value) {
  if (value < static_cast<int64>(std::numeric_limits<int32>::lowest()) || value > static_cast<int64>(std::numeric_limits<int32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int32>(value);
}

int32 convert::to_int32(slong value) {
  if (value < static_cast<slong>(std::numeric_limits<int32>::lowest()) || value > static_cast<slong>(std::numeric_limits<int32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int32>(value);
}

int32 convert::to_int32(sbyte value) noexcept {
  return static_cast<int32>(value);
}

int32 convert::to_int32(uint16 value) noexcept {
  return static_cast<int32>(value);
}

int32 convert::to_int32(uint32 value) {
  if (value > static_cast<uint32>(std::numeric_limits<int32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int32>(value);
}

int32 convert::to_int32(uint64 value) {
  if (value > static_cast<uint64>(std::numeric_limits<int32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int32>(value);
}

int32 convert::to_int32(xtd::ulong value) {
  if (value > static_cast<xtd::ulong>(std::numeric_limits<int32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int32>(value);
}

int32 convert::to_int32(const string& value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<int32>(value, number_styles::binary_number); break;
    case 8: return parse<int32>(value, number_styles::octal_number); break;
    case 10: return parse<int32>(value, number_styles::integer); break;
    case 16: return parse<int32>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

int32 convert::to_int32(const std::string& value) {
  return string::parse<int32>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
int32 convert::to_int32(const std::u8string& value) {
  return string::parse<int32>(value);
}
#endif

int32 convert::to_int32(const std::u16string& value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(const std::u32string& value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(const std::wstring& value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(const char* value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(char* value) {
  return string::parse<int32>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
int32 convert::to_int32(const char8* value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(char8* value) {
  return string::parse<int32>(value);
}
#endif

int32 convert::to_int32(const char16* value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(char16* value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(const char32* value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(char32* value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(const wchar* value) {
  return string::parse<int32>(value);
}

int32 convert::to_int32(wchar* value) {
  return string::parse<int32>(value);
}

int64 convert::to_int64(std::any value) {
  try {
    return std::any_cast<int64>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

int64 convert::to_int64(bool value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(xtd::byte value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(char value) noexcept {
  return static_cast<int64>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
int64 convert::to_int64(char8 value) noexcept {
  return static_cast<int64>(value);
}
#endif

int64 convert::to_int64(char16 value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(char32 value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(wchar value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(decimal value) noexcept {
  return static_cast<int64>(math::round(value));
}

int64 convert::to_int64(double value) noexcept {
  return static_cast<int64>(math::round(value));
}

int64 convert::to_int64(float value) noexcept {
  return static_cast<int64>(math::round(value));
}

int64 convert::to_int64(int16 value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(int32 value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(int64 value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(slong value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(sbyte value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(uint16 value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(uint32 value) noexcept {
  return static_cast<int64>(value);
}

int64 convert::to_int64(uint64 value) {
  if (value > static_cast<uint64>(std::numeric_limits<int64>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int64>(value);
}

int64 convert::to_int64(xtd::ulong value) {
  if (value > static_cast<xtd::ulong>(std::numeric_limits<int64>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<int64>(value);
}

int64 convert::to_int64(const string& value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<int64>(value, number_styles::binary_number); break;
    case 8: return parse<int64>(value, number_styles::octal_number); break;
    case 10: return parse<int64>(value, number_styles::integer); break;
    case 16: return parse<int64>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

int64 convert::to_int64(const std::string& value) {
  return string::parse<int64>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
int64 convert::to_int64(const std::u8string& value) {
  return string::parse<int64>(value);
}
#endif

int64 convert::to_int64(const std::u16string& value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(const std::u32string& value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(const std::wstring& value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(const char* value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(char* value) {
  return string::parse<int64>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
int64 convert::to_int64(const char8* value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(char8* value) {
  return string::parse<int64>(value);
}
#endif

int64 convert::to_int64(const char16* value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(char16* value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(const char32* value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(char32* value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(const wchar* value) {
  return string::parse<int64>(value);
}

int64 convert::to_int64(wchar* value) {
  return string::parse<int64>(value);
}

slong convert::to_llong(std::any value) {
  try {
    return std::any_cast<slong>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

slong convert::to_llong(bool value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(xtd::byte value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(char value) noexcept {
  return static_cast<slong>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
slong convert::to_llong(char8 value) noexcept {
  return static_cast<slong>(value);
}
#endif

slong convert::to_llong(char16 value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(char32 value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(wchar value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(decimal value) noexcept {
  return static_cast<slong>(math::round(value));
}

slong convert::to_llong(double value) noexcept {
  return static_cast<slong>(math::round(value));
}

slong convert::to_llong(float value) noexcept {
  return static_cast<slong>(math::round(value));
}

slong convert::to_llong(int16 value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(int32 value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(int64 value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(slong value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(sbyte value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(uint16 value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(uint32 value) noexcept {
  return static_cast<slong>(value);
}

slong convert::to_llong(uint64 value) {
  if (value > static_cast<uint64>(std::numeric_limits<slong>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<slong>(value);
}

slong convert::to_llong(xtd::ulong value) {
  if (value > static_cast<xtd::ulong>(std::numeric_limits<slong>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<slong>(value);
}

slong convert::to_llong(const string& value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<slong>(value, number_styles::binary_number); break;
    case 8: return parse<slong>(value, number_styles::octal_number); break;
    case 10: return parse<slong>(value, number_styles::integer); break;
    case 16: return parse<slong>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

slong convert::to_llong(const std::string& value) {
  return string::parse<slong>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
slong convert::to_llong(const std::u8string& value) {
  return string::parse<slong>(value);
}
#endif

slong convert::to_llong(const std::u16string& value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(const std::u32string& value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(const std::wstring& value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(const char* value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(char* value) {
  return string::parse<slong>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
slong convert::to_llong(const char8* value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(char8* value) {
  return string::parse<slong>(value);
}
#endif

slong convert::to_llong(const char16* value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(char16* value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(const char32* value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(char32* value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(const wchar* value) {
  return string::parse<slong>(value);
}

slong convert::to_llong(wchar* value) {
  return string::parse<slong>(value);
}

sbyte convert::to_sbyte(std::any value) {
  try {
    return std::any_cast<sbyte>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

sbyte convert::to_sbyte(bool value) noexcept {
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(xtd::byte value) noexcept {
  return value;
}

sbyte convert::to_sbyte(char value) noexcept {
  return static_cast<sbyte>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
sbyte convert::to_sbyte(char8 value) noexcept {
  return static_cast<sbyte>(value);
}
#endif

sbyte convert::to_sbyte(char16 value) {
  if (value > static_cast<char16>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(char32 value) {
  if (value > static_cast<char32>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(wchar value) {
  if (value > static_cast<wchar>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(decimal value) {
  if (value < static_cast<decimal>(std::numeric_limits<sbyte>::lowest()) || value > static_cast<decimal>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(math::round(value));
}

sbyte convert::to_sbyte(double value) {
  if (value < static_cast<double>(std::numeric_limits<sbyte>::lowest()) || value > static_cast<double>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(math::round(value));
}

sbyte convert::to_sbyte(float value) {
  if (value < static_cast<float>(std::numeric_limits<sbyte>::lowest()) || value > static_cast<float>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(math::round(value));
}

sbyte convert::to_sbyte(int16 value) {
  if (value < static_cast<int16>(std::numeric_limits<sbyte>::lowest()) || value > static_cast<int16>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(int32 value) {
  if (value < static_cast<int32>(std::numeric_limits<sbyte>::lowest()) || value > static_cast<int32>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(int64 value) {
  if (value < static_cast<int64>(std::numeric_limits<sbyte>::lowest()) || value > static_cast<int64>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(slong value) {
  if (value < static_cast<slong>(std::numeric_limits<sbyte>::lowest()) || value > static_cast<slong>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(sbyte value) {
  return value;
}

sbyte convert::to_sbyte(uint16 value) {
  if (value > static_cast<uint16>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(uint32 value) {
  if (value > static_cast<uint32>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(uint64 value) {
  if (value > static_cast<uint64>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(xtd::ulong value) {
  if (value > static_cast<xtd::ulong>(std::numeric_limits<sbyte>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<sbyte>(value);
}

sbyte convert::to_sbyte(const string& value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<sbyte>(value, number_styles::binary_number); break;
    case 8: return parse<sbyte>(value, number_styles::octal_number); break;
    case 10: return parse<sbyte>(value, number_styles::integer); break;
    case 16: return parse<sbyte>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

sbyte convert::to_sbyte(const std::string& value) {
  return string::parse<sbyte>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
sbyte convert::to_sbyte(const std::u8string& value) {
  return string::parse<sbyte>(value);
}
#endif

sbyte convert::to_sbyte(const std::u16string& value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(const std::u32string& value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(const std::wstring& value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(const char* value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(char* value) {
  return string::parse<sbyte>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
sbyte convert::to_sbyte(const char8* value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(char8* value) {
  return string::parse<sbyte>(value);
}
#endif

sbyte convert::to_sbyte(const char16* value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(char16* value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(const char32* value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(char32* value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(const wchar* value) {
  return string::parse<sbyte>(value);
}

sbyte convert::to_sbyte(wchar* value) {
  return string::parse<sbyte>(value);
}

uint16 convert::to_uint16(std::any value) {
  try {
    return std::any_cast<uint16>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

uint16 convert::to_uint16(bool value) noexcept {
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(xtd::byte value) noexcept {
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(char value) noexcept {
  return static_cast<uint16>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
uint16 convert::to_uint16(char8 value) noexcept {
  return static_cast<uint16>(value);
}
#endif

uint16 convert::to_uint16(char16 value) noexcept {
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(char32 value) {
  if (value > static_cast<char32>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(wchar value) noexcept {
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(decimal value) {
  if (value < static_cast<decimal>(std::numeric_limits<uint16>::lowest()) || value > static_cast<decimal>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(math::round(value));
}

uint16 convert::to_uint16(double value) {
  if (value < static_cast<double>(std::numeric_limits<uint16>::lowest()) || value > static_cast<double>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(math::round(value));
}

uint16 convert::to_uint16(float value) {
  if (value < static_cast<float>(std::numeric_limits<uint16>::lowest()) || value > static_cast<float>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(math::round(value));
}

uint16 convert::to_uint16(int16 value) {
  if (value < static_cast<int16>(std::numeric_limits<uint16>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(int32 value) {
  if (value < static_cast<int32>(std::numeric_limits<uint16>::lowest()) || value > static_cast<int32>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(int64 value) {
  if (value < static_cast<int64>(std::numeric_limits<uint16>::lowest()) || value > static_cast<int64>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(slong value) {
  if (value < static_cast<slong>(std::numeric_limits<uint16>::lowest()) || value > static_cast<slong>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(sbyte value) {
  if (value < static_cast<sbyte>(std::numeric_limits<uint16>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(uint16 value) noexcept {
  return value;
}

uint16 convert::to_uint16(uint32 value) {
  if (value > static_cast<uint32>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(uint64 value) {
  if (value > static_cast<uint64>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(xtd::ulong value) {
  if (value > static_cast<xtd::ulong>(std::numeric_limits<uint16>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint16>(value);
}

uint16 convert::to_uint16(const string& value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<uint16>(value, number_styles::binary_number); break;
    case 8: return parse<uint16>(value, number_styles::octal_number); break;
    case 10: return parse<uint16>(value, number_styles::integer); break;
    case 16: return parse<uint16>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

uint16 convert::to_uint16(const std::string& value) {
  return string::parse<uint16>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
uint16 convert::to_uint16(const std::u8string& value) {
  return string::parse<uint16>(value);
}
#endif

uint16 convert::to_uint16(const std::u16string& value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(const std::u32string& value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(const std::wstring& value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(const char* value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(char* value) {
  return string::parse<uint16>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
uint16 convert::to_uint16(const char8* value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(char8* value) {
  return string::parse<uint16>(value);
}
#endif

uint16 convert::to_uint16(const char16* value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(char16* value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(const char32* value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(char32* value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(const wchar* value) {
  return string::parse<uint16>(value);
}

uint16 convert::to_uint16(wchar* value) {
  return string::parse<uint16>(value);
}

uint32 convert::to_uint32(std::any value) {
  try {
    return std::any_cast<uint32>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

uint32 convert::to_uint32(bool value) noexcept {
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(xtd::byte value) noexcept {
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(char value) noexcept {
  return static_cast<uint32>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
uint32 convert::to_uint32(char8 value) noexcept {
  return static_cast<uint32>(value);
}
#endif

uint32 convert::to_uint32(char16 value) noexcept {
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(char32 value) noexcept {
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(wchar value) noexcept {
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(decimal value) {
  if (value < static_cast<decimal>(std::numeric_limits<uint32>::lowest()) || value > static_cast<decimal>(std::numeric_limits<uint32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(math::round(value));
}

uint32 convert::to_uint32(double value) {
  if (value < static_cast<double>(std::numeric_limits<uint32>::lowest()) || value > static_cast<double>(std::numeric_limits<uint32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(math::round(value));
}

uint32 convert::to_uint32(float value) {
  if (value < static_cast<float>(std::numeric_limits<uint32>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(math::round(value));
}

uint32 convert::to_uint32(int16 value) {
  if (value < static_cast<int16>(std::numeric_limits<uint32>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(int32 value) {
  if (value < static_cast<int32>(std::numeric_limits<uint32>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(int64 value) {
  if (value < static_cast<int64>(std::numeric_limits<uint32>::lowest()) || value > static_cast<int64>(std::numeric_limits<uint32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(slong value) {
  if (value < static_cast<slong>(std::numeric_limits<uint32>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(sbyte value) {
  if (value < static_cast<sbyte>(std::numeric_limits<uint32>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(uint16 value) noexcept {
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(uint32 value) noexcept {
  return value;
}

uint32 convert::to_uint32(uint64 value) {
  if (value > static_cast<uint64>(std::numeric_limits<uint32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(xtd::ulong value) {
  if (value > static_cast<xtd::ulong>(std::numeric_limits<uint32>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(value);
}

uint32 convert::to_uint32(const string& value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<uint32>(value, number_styles::binary_number); break;
    case 8: return parse<uint32>(value, number_styles::octal_number); break;
    case 10: return parse<uint32>(value, number_styles::integer); break;
    case 16: return parse<uint32>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

uint32 convert::to_uint32(const std::string& value) {
  return string::parse<uint32>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
uint32 convert::to_uint32(const std::u8string& value) {
  return string::parse<uint32>(value);
}
#endif

uint32 convert::to_uint32(const std::u16string& value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(const std::u32string& value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(const std::wstring& value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(const char* value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(char* value) {
  return string::parse<uint32>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
uint32 convert::to_uint32(const char8* value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(char8* value) {
  return string::parse<uint32>(value);
}
#endif

uint32 convert::to_uint32(const char16* value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(char16* value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(const char32* value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(char32* value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(const wchar* value) {
  return string::parse<uint32>(value);
}

uint32 convert::to_uint32(wchar* value) {
  return string::parse<uint32>(value);
}

uint64 convert::to_uint64(std::any value) {
  try {
    return std::any_cast<uint64>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

uint64 convert::to_uint64(bool value) noexcept {
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(xtd::byte value) noexcept {
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(char value) noexcept {
  return static_cast<uint64>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
uint64 convert::to_uint64(char8 value) noexcept {
  return static_cast<uint64>(value);
}
#endif

uint64 convert::to_uint64(char16 value) noexcept {
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(char32 value) noexcept {
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(wchar value) noexcept {
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(decimal value) {
  if (value < static_cast<decimal>(std::numeric_limits<uint64>::lowest()) || value > static_cast<decimal>(std::numeric_limits<uint64>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint64>(math::round(value));
}

uint64 convert::to_uint64(double value) {
  if (value < static_cast<double>(std::numeric_limits<uint64>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint64>(math::round(value));
}

uint64 convert::to_uint64(float value) {
  if (value < static_cast<float>(std::numeric_limits<uint64>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint64>(math::round(value));
}

uint64 convert::to_uint64(int16 value) {
  if (value < static_cast<int16>(std::numeric_limits<uint64>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(int32 value) {
  if (value < static_cast<int32>(std::numeric_limits<uint64>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(int64 value) {
  if (value < static_cast<int64>(std::numeric_limits<uint64>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint32>(value);
}

uint64 convert::to_uint64(slong value) {
  if (value < static_cast<slong>(std::numeric_limits<uint64>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(sbyte value) {
  if (value < static_cast<sbyte>(std::numeric_limits<uint64>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(uint16 value) noexcept {
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(uint32 value) noexcept {
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(uint64 value) noexcept {
  return value;
}

uint64 convert::to_uint64(xtd::ulong value) noexcept {
  return static_cast<uint64>(value);
}

uint64 convert::to_uint64(const string& value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(const std::string& value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<uint64>(value, number_styles::binary_number); break;
    case 8: return parse<uint64>(value, number_styles::octal_number); break;
    case 10: return parse<uint64>(value, number_styles::integer); break;
    case 16: return parse<uint64>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

#if defined(__xtd__cpp_lib_char8_t)
uint64 convert::to_uint64(const std::u8string& value) {
  return string::parse<uint64>(value);
}
#endif

uint64 convert::to_uint64(const std::u16string& value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(const std::u32string& value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(const std::wstring& value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(const char* value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(char* value) {
  return string::parse<uint64>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
uint64 convert::to_uint64(const char8* value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(char8* value) {
  return string::parse<uint64>(value);
}
#endif

uint64 convert::to_uint64(const char16* value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(char16* value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(const char32* value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(char32* value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(const wchar* value) {
  return string::parse<uint64>(value);
}

uint64 convert::to_uint64(wchar* value) {
  return string::parse<uint64>(value);
}

xtd::ulong convert::to_ullong(std::any value) {
  try {
    return std::any_cast<xtd::ulong>(value);
  } catch (...) {
    throw_helper::throws(exception_case::invalid_cast);
  }
}

xtd::ulong convert::to_ullong(bool value) noexcept {
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(xtd::byte value) noexcept {
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(char value) noexcept {
  return static_cast<xtd::ulong>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::ulong convert::to_ullong(char8 value) noexcept {
  return static_cast<xtd::ulong>(value);
}
#endif

xtd::ulong convert::to_ullong(char16 value) noexcept {
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(char32 value) noexcept {
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(wchar value) noexcept {
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(decimal value) {
  if (value < static_cast<decimal>(std::numeric_limits<xtd::ulong>::lowest()) || value > static_cast<decimal>(std::numeric_limits<xtd::ulong>::max())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::ulong>(math::round(value));
}

xtd::ulong convert::to_ullong(double value) {
  if (value < static_cast<double>(std::numeric_limits<xtd::ulong>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::ulong>(math::round(value));
}

xtd::ulong convert::to_ullong(float value) {
  if (value < static_cast<float>(std::numeric_limits<xtd::ulong>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::ulong>(math::round(value));
}

xtd::ulong convert::to_ullong(int16 value) {
  if (value < static_cast<int16>(std::numeric_limits<xtd::ulong>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(int32 value) {
  if (value < static_cast<int32>(std::numeric_limits<xtd::ulong>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(int64 value) {
  if (value < static_cast<int64>(std::numeric_limits<xtd::ulong>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(slong value) {
  if (value < static_cast<slong>(std::numeric_limits<xtd::ulong>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(sbyte value) {
  if (value < static_cast<sbyte>(std::numeric_limits<xtd::ulong>::lowest())) throw_helper::throws(exception_case::overflow);
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(uint16 value) noexcept {
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(uint32 value) noexcept {
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(uint64 value) noexcept {
  return static_cast<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(xtd::ulong value) noexcept {
  return value;
}

xtd::ulong convert::to_ullong(const string& value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(const string& value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return parse<xtd::ulong>(value, number_styles::binary_number); break;
    case 8: return parse<xtd::ulong>(value, number_styles::octal_number); break;
    case 10: return parse<xtd::ulong>(value, number_styles::integer); break;
    case 16: return parse<xtd::ulong>(value, number_styles::hex_number); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

xtd::ulong convert::to_ullong(const std::string& value) {
  return string::parse<xtd::ulong>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::ulong convert::to_ullong(const std::u8string& value) {
  return string::parse<xtd::ulong>(value);
}
#endif

xtd::ulong convert::to_ullong(const std::u16string& value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(const std::u32string& value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(const std::wstring& value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(const char* value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(char* value) {
  return string::parse<xtd::ulong>(value);
}

#if defined(__xtd__cpp_lib_char8_t)
xtd::ulong convert::to_ullong(const char8* value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(char8* value) {
  return string::parse<xtd::ulong>(value);
}
#endif

xtd::ulong convert::to_ullong(const char16* value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(char16* value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(const char32* value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(char32* value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(const wchar* value) {
  return string::parse<xtd::ulong>(value);
}

xtd::ulong convert::to_ullong(wchar* value) {
  return string::parse<xtd::ulong>(value);
}

string convert::to_string(std::any value) {
  return string::format("{}", value);
}

string convert::to_string(bool value) noexcept {
  return string::format("{}", value);
}

string convert::to_string(xtd::byte value) noexcept {
  return string::format("{}", value);
}

string convert::to_string(xtd::byte value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(char value) noexcept {
  return string::format("{}", value);
}

#if defined(__xtd__cpp_lib_char8_t)
string convert::to_string(char8 value) noexcept {
  return string::format("{}", value);
}
#endif

string convert::to_string(char16 value) noexcept {
  return string::format("{}", value);
}

string convert::to_string(char32 value) noexcept {
  return string::format("{}", value);
}

string convert::to_string(wchar value) noexcept {
  return string::format("{}", value);
}

string convert::to_string(decimal value) {
  return string::format("{}", value);
}

string convert::to_string(double value) {
  return string::format("{}", value);
}

string convert::to_string(float value) {
  return string::format("{}", value);
}

string convert::to_string(int16 value) {
  return string::format("{}", value);
}

string convert::to_string(int16 value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(int32 value) {
  return string::format("{}", value);
}

string convert::to_string(int32 value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(int64 value) {
  return string::format("{}", value);
}

string convert::to_string(int64 value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(slong value) {
  return string::format("{}", value);
}

string convert::to_string(slong value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(sbyte value) {
  return string::format("{}", value);
}

string convert::to_string(sbyte value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(uint16 value) noexcept {
  return string::format("{}", value);
}

string convert::to_string(uint16 value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(uint32 value) noexcept {
  return string::format("{}", value);
}

string convert::to_string(uint32 value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(uint64 value) noexcept {
  return string::format("{}", value);
}

string convert::to_string(uint64 value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(xtd::ulong value) noexcept {
  return string::format("{}", value);
}

string convert::to_string(xtd::ulong value, xtd::byte from_base) {
  switch (from_base) {
    case 2: return string::format("{:B}", value); break;
    case 8: return string::format("{:O}", value); break;
    case 10: return string::format("{:D}", value); break;
    case 16: return string::format("{:X}", value); break;
    default: throw_helper::throws(exception_case::argument);
  }
}

string convert::to_string(const string& value) {
  return value;
}

string convert::to_string(const std::string& value) {
  return value;
}

#if defined(__xtd__cpp_lib_char8_t)
string convert::to_string(const std::u8string& value) {
  return value;
}
#endif

string convert::to_string(const std::u16string& value) {
  return value;
}

string convert::to_string(const std::u32string& value) {
  return value;
}

string convert::to_string(const std::wstring& value) {
  return value;
}

string convert::to_string(const char* value) {
  return value;
}

string convert::to_string(char* value) {
  return value;
}

#if defined(__xtd__cpp_lib_char8_t)
string convert::to_string(const char8* value) {
  return value;
}

string convert::to_string(char8* value) {
  return value;
}
#endif

string convert::to_string(const char16* value) {
  return value;
}

string convert::to_string(char16* value) {
  return value;
}

string convert::to_string(const char32* value) {
  return value;
}

string convert::to_string(char32* value) {
  return value;
}

string convert::to_string(const wchar* value) {
  return value;
}

string convert::to_string(wchar* value) {
  return value;
}

string convert::to_ustring(std::any value) {
  return to_string(value);
}

string convert::to_ustring(bool value) noexcept {
  return to_string(value);
}

string convert::to_ustring(xtd::byte value) noexcept {
  return to_string(value);
}

string convert::to_ustring(xtd::byte value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(char value) noexcept {
  return to_string(value);
}

#if defined(__xtd__cpp_lib_char8_t)
string convert::to_ustring(char8 value) noexcept {
  return to_string(value);
}
#endif

string convert::to_ustring(char16 value) noexcept {
  return to_string(value);
}

string convert::to_ustring(char32 value) noexcept {
  return to_string(value);
}

string convert::to_ustring(wchar value) noexcept {
  return to_string(value);
}

string convert::to_ustring(decimal value) {
  return to_string(value);
}

string convert::to_ustring(double value) {
  return to_string(value);
}

string convert::to_ustring(float value) {
  return to_string(value);
}

string convert::to_ustring(int16 value) {
  return to_string(value);
}

string convert::to_ustring(int16 value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(int32 value) {
  return to_string(value);
}

string convert::to_ustring(int32 value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(int64 value) {
  return to_string(value);
}

string convert::to_ustring(int64 value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(slong value) {
  return to_string(value);
}

string convert::to_ustring(slong value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(sbyte value) {
  return to_string(value);
}

string convert::to_ustring(sbyte value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(uint16 value) noexcept {
  return to_string(value);
}

string convert::to_ustring(uint16 value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(uint32 value) noexcept {
  return to_string(value);
}

string convert::to_ustring(uint32 value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(uint64 value) noexcept {
  return to_string(value);
}

string convert::to_ustring(uint64 value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(xtd::ulong value) noexcept {
  return to_string(value);
}

string convert::to_ustring(xtd::ulong value, xtd::byte from_base) {
  return to_string(value, from_base);
}

string convert::to_ustring(const string& value) {
  return to_string(value);
}

string convert::to_ustring(const std::string& value) {
  return to_string(value);
}

#if defined(__xtd__cpp_lib_char8_t)
string convert::to_ustring(const std::u8string& value) {
  return to_string(value);
}
#endif

string convert::to_ustring(const std::u16string& value) {
  return to_string(value);
}

string convert::to_ustring(const std::u32string& value) {
  return to_string(value);
}

string convert::to_ustring(const std::wstring& value) {
  return to_string(value);
}

string convert::to_ustring(const char* value) {
  return to_string(value);
}

string convert::to_ustring(char* value) {
  return to_string(value);
}

#if defined(__xtd__cpp_lib_char8_t)
string convert::to_ustring(const char8* value) {
  return to_string(value);
}

string convert::to_ustring(char8* value) {
  return to_string(value);
}
#endif

string convert::to_ustring(const char16* value) {
  return to_string(value);
}

string convert::to_ustring(char16* value) {
  return to_string(value);
}

string convert::to_ustring(const char32* value) {
  return to_string(value);
}

string convert::to_ustring(char32* value) {
  return to_string(value);
}

string convert::to_ustring(const wchar* value) {
  return to_string(value);
}

string convert::to_ustring(wchar* value) {
  return to_string(value);
}
