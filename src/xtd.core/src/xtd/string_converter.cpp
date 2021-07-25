#include "../../include/xtd/string_converter.h"

using namespace std;
using namespace xtd;

namespace {
  template<typename char_t>
  basic_string<char_t> codepoint_to_string(char32_t codepoint) noexcept {
    basic_string<char_t> result;
    if (codepoint < 0x80) {
      result.push_back(static_cast<char_t>(codepoint));
    }
    else  if (codepoint < 0x800) {
      result.push_back(static_cast<char_t>((codepoint >> 6) | 0xc0));
      result.push_back(static_cast<char_t>((codepoint & 0x3f) | 0x80));
    }
    else if (codepoint < 0x10000) {
      result.push_back(static_cast<char_t>((codepoint >> 12) | 0xe0));
      result.push_back(static_cast<char_t>(((codepoint >> 6) & 0x3f) | 0x80));
      result.push_back(static_cast<char_t>((codepoint & 0x3f) | 0x80));
    }
    else {
      result.push_back(static_cast<char_t>((codepoint >> 18) | 0xf0));
      result.push_back(static_cast<char_t>(((codepoint >> 12) & 0x3f) | 0x80));
      result.push_back(static_cast<char_t>(((codepoint >> 6) & 0x3f) | 0x80));
      result.push_back(static_cast<char_t>((codepoint & 0x3f) | 0x80));
    }
    return result;
  }
}

string string_converter::to_string(const string& str) noexcept {
  return str;
}

string string_converter::to_string(const char* str) noexcept {
  return str;
}

string string_converter::to_string(char* str) noexcept {
  return str;
}

string string_converter::to_string(const ustring& str) noexcept {
  return reinterpret_cast<const char*>(str.c_str());
}

string string_converter::to_string(const u8string& str) noexcept {
  return reinterpret_cast<const char*>(str.c_str());
}

string string_converter::to_string(const char8_t* str) noexcept {
  return reinterpret_cast<const char*>(str);
}

string string_converter::to_string(char8_t* str) noexcept {
  return reinterpret_cast<const char*>(str);
}

string string_converter::to_string(const u16string& str) noexcept {
  string result;
  for(auto c : str)
    result += codepoint_to_string<char>(c);
  return result;
}

string string_converter::to_string(const char16_t* str) noexcept {
  return to_string(u16string(str));
}

string string_converter::to_string(char16_t* str) noexcept {
  return to_string(u16string(str));
}

string string_converter::to_string(const u32string& str) noexcept {
  string result;
  for(auto c : str)
    result += codepoint_to_string<char>(c);
  return result;
}

string string_converter::to_string(const char32_t* str) noexcept {
  return to_string(u32string(str));
}

string string_converter::to_string(char32_t* str) noexcept {
  return to_string(u32string(str));
}

ustring string_converter::to_ustring(const string& str) noexcept {
  return str;
}

ustring string_converter::to_ustring(const char* str) noexcept {
  return str;
}

ustring string_converter::to_ustring(char* str) noexcept {
  return str;
}

const ustring& string_converter::to_ustring(const ustring& str) noexcept {
  return str;
}

ustring string_converter::to_ustring(const u8string& str) noexcept {
  return str;
}

ustring string_converter::to_ustring(const char8_t* str) noexcept {
  return str;
}

ustring string_converter::to_ustring(char8_t* str) noexcept {
  return str;
}

ustring string_converter::to_ustring(const u16string& str) noexcept {
  return str;
}

ustring string_converter::to_ustring(const char16_t* str) noexcept {
  return str;
}

ustring string_converter::to_ustring(char16_t* str) noexcept {
  return str;
}

ustring string_converter::to_ustring(const u32string& str) noexcept {
  return str;
}

ustring string_converter::to_ustring(const char32_t* str) noexcept {
  return str;
}

ustring string_converter::to_ustring(char32_t* str) noexcept {
  return str;
}
