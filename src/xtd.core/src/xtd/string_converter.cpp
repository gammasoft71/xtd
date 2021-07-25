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

string string_converter::to_string(const wstring& str) noexcept {
  string result;
  for(auto c : str)
    result += codepoint_to_string<char>(c);
  return result;
}

string string_converter::to_string(const wchar_t* str) noexcept {
  return to_string(wstring(str));
}

string string_converter::to_string(wchar_t* str) noexcept {
  return to_string(wstring(str));
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

ustring string_converter::to_ustring(const wstring& str) noexcept {
  return str;
}

ustring string_converter::to_ustring(const wchar_t* str) noexcept {
  return str;
}

ustring string_converter::to_ustring(wchar_t* str) noexcept {
  return str;
}

u8string string_converter::to_u8string(const string& str) noexcept {
  return reinterpret_cast<const char8_t*>(str.c_str());
}

u8string string_converter::to_u8string(const char* str) noexcept {
  return reinterpret_cast<const char8_t*>(str);
}

u8string string_converter::to_u8string(char* str) noexcept {
  return reinterpret_cast<const char8_t*>(str);
}

u8string string_converter::to_u8string(const ustring& str) noexcept {
  return str;
}

u8string string_converter::to_u8string(const u8string& str) noexcept {
  return str;
}

u8string string_converter::to_u8string(const char8_t* str) noexcept {
  return str;
}

u8string string_converter::to_u8string(char8_t* str) noexcept {
  return str;
}

u8string string_converter::to_u8string(const u16string& str) noexcept {
  u8string result;
  for(auto c : str)
    result += codepoint_to_string<char8_t>(c);
  return result;
}

u8string string_converter::to_u8string(const char16_t* str) noexcept {
  return to_u8string(u16string(str));
}

u8string string_converter::to_u8string(char16_t* str) noexcept {
  return to_u8string(u16string(str));
}

u8string string_converter::to_u8string(const u32string& str) noexcept {
  u8string result;
  for(auto c : str)
    result += codepoint_to_string<char8_t>(c);
  return result;
}

u8string string_converter::to_u8string(const char32_t* str) noexcept {
  return to_u8string(u32string(str));
}

u8string string_converter::to_u8string(char32_t* str) noexcept {
  return to_u8string(u32string(str));
}

u8string string_converter::to_u8string(const wstring& str) noexcept {
  u8string result;
  for(auto c : str)
    result += codepoint_to_string<char8_t>(c);
  return result;
}

u8string string_converter::to_u8string(const wchar_t* str) noexcept {
  return to_u8string(wstring(str));
}

u8string string_converter::to_u8string(wchar_t* str) noexcept {
  return to_u8string(wstring(str));
}

u16string string_converter::to_u16string(const string& str) noexcept {
  return to_u16string(str.c_str());
}

u16string string_converter::to_u16string(const char* str) noexcept {
  std::u16string out;
  int32_t codepoint = 0;
  while (*str != 0) {
    unsigned char ch = static_cast<unsigned char>(*str);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str;
    if (((*str & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<char16_t>(0xd800 + (codepoint >> 10)));
        out.append(1, static_cast<char16_t>(0xdc00 + (codepoint & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<char16_t>(codepoint));
    }
  }
  return out;
}

u16string string_converter::to_u16string(char* str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str));
}

u16string string_converter::to_u16string(const ustring& str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str.c_str()));
}

u16string string_converter::to_u16string(const u8string& str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str.c_str()));
}

u16string string_converter::to_u16string(const char8_t* str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str));
}

u16string string_converter::to_u16string(char8_t* str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str));
}

u16string string_converter::to_u16string(const u16string& str) noexcept {
  return str;
}

u16string string_converter::to_u16string(const char16_t* str) noexcept {
  return str;
}

u16string string_converter::to_u16string(char16_t* str) noexcept {
  return str;
}

u16string string_converter::to_u16string(const u32string& str) noexcept {
  return to_u16string(to_ustring(str));
}

u16string string_converter::to_u16string(const char32_t* str) noexcept {
  return to_u16string(to_ustring(str));
}

u16string string_converter::to_u16string(char32_t* str) noexcept {
  return to_u16string(to_ustring(str));
}

u16string string_converter::to_u16string(const wstring& str) noexcept {
  return to_u16string(to_ustring(str));
}

u16string string_converter::to_u16string(const wchar_t* str) noexcept {
  return to_u16string(to_ustring(str));
}

u16string string_converter::to_u16string(wchar_t* str) noexcept {
  return to_u16string(to_ustring(str));
}
