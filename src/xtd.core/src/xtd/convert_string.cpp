#include "../../include/xtd/convert_string.hpp"

using namespace xtd;

namespace {
  template<class target_t, class source_t>
  std::basic_string<target_t> convert_to_string(const std::basic_string<source_t>& str) noexcept {
    auto out = std::basic_string<target_t> {};
    auto codepoint = 0u;
    for (auto character : str) {
      if (character >= 0xd800 && character <= 0xdbff)
        codepoint = ((character - 0xd800) << 10) + 0x10000;
      else  {
        if (character >= 0xdc00 && character <= 0xdfff) codepoint |= character - 0xdc00;
        else codepoint = character;
          
        if (codepoint <= 0x7f)
          out.append(1, static_cast<target_t>(codepoint));
        else if (codepoint <= 0x7ff) {
          out.append(1, static_cast<target_t>(0xc0 | ((codepoint >> 6) & 0x1f)));
          out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
        } else if (codepoint <= 0xffff) {
          out.append(1, static_cast<target_t>(0xe0 | ((codepoint >> 12) & 0x0f)));
          out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
          out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
        } else {
          out.append(1, static_cast<target_t>(0xf0 | ((codepoint >> 18) & 0x07)));
          out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 12) & 0x3f)));
          out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
          out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
        }
        codepoint = 0;
      }
    }
    return out;
  }
}

const string& convert_string::to_string(const string& str) noexcept {
  return str;
}

string convert_string::to_string(const std::string& str) noexcept {
  return str;
}

string convert_string::to_string(const char* str) noexcept {
  return str;
}

string convert_string::to_string(char* str) noexcept {
  return str;
}

#if defined(__xtd__cpp_lib_char8_t)
string convert_string::to_string(const u8string& str) noexcept {
  return str;
}

string convert_string::to_string(const std::u8string& str) noexcept {
  return str;
}

string convert_string::to_string(const char8* str) noexcept {
  return str;
}

string convert_string::to_string(char8* str) noexcept {
  return str;
}
#endif

string convert_string::to_string(const xtd::u16string& str) noexcept {
  return str;
}

string convert_string::to_string(const std::u16string& str) noexcept {
  return str;
}

string convert_string::to_string(const char16* str) noexcept {
  return str;
}

string convert_string::to_string(char16* str) noexcept {
  return str;
}

string convert_string::to_string(const u32string& str) noexcept {
  return str;
}

string convert_string::to_string(const std::u32string& str) noexcept {
  return str;
}

string convert_string::to_string(const char32* str) noexcept {
  return str;
}

string convert_string::to_string(char32* str) noexcept {
  return str;
}

string convert_string::to_string(const wstring& str) noexcept {
  return str;
}

string convert_string::to_string(const std::wstring& str) noexcept {
  return str;
}

string convert_string::to_string(const wchar* str) noexcept {
  return str;
}

string convert_string::to_string(wchar* str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const string& str) noexcept {
  return str;
}

#if defined(__xtd__cpp_lib_char8_t)
u8string convert_string::to_u8string(const std::string& str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const char* str) noexcept {
  return str;
}

u8string convert_string::to_u8string(char* str) noexcept {
  return str;
}

const u8string& convert_string::to_u8string(const u8string& str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const std::u8string& str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const char8* str) noexcept {
  return str;
}

u8string convert_string::to_u8string(char8* str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const u16string& str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const std::u16string& str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const char16* str) noexcept {
  return str;
}

u8string convert_string::to_u8string(char16* str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const u32string& str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const std::u32string& str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const char32* str) noexcept {
  return str;
}

u8string convert_string::to_u8string(char32* str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const std::wstring& str) noexcept {
  return str;
}

u8string convert_string::to_u8string(const wchar* str) noexcept {
  return str;
}

u8string convert_string::to_u8string(wchar* str) noexcept {
  return str;
}
#endif

u16string convert_string::to_u16string(const std::string& str) noexcept {
  return to_u16string(str.c_str());
}

u16string convert_string::to_u16string(const char* str) noexcept {
  auto out = std::u16string {};
  auto codepoint = 0u;
  while (*str != 0) {
    auto ch = static_cast<unsigned char>(*str);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str;
    if (((*str & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<char16>(0xd800 + (static_cast<char16>(codepoint) >> 10)));
        out.append(1, static_cast<char16>(0xdc00 + (static_cast<char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<char16>(codepoint));
    }
  }
  return out;
}

u16string convert_string::to_u16string(char* str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str));
}

u16string convert_string::to_u16string(const string& str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str.c_str()));
}

#if defined(__xtd__cpp_lib_char8_t)
u16string convert_string::to_u16string(const std::u8string& str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str.c_str()));
}

u16string convert_string::to_u16string(const char8* str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str));
}

u16string convert_string::to_u16string(char8* str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str));
}
#endif

const u16string& convert_string::to_u16string(const u16string& str) noexcept {
  return str;
}

u16string convert_string::to_u16string(const std::u16string& str) noexcept {
  return str;
}

u16string convert_string::to_u16string(const char16* str) noexcept {
  return str;
}

u16string convert_string::to_u16string(char16* str) noexcept {
  return str;
}

u16string convert_string::to_u16string(const std::u32string& str) noexcept {
  return to_u16string(to_string(str));
}

u16string convert_string::to_u16string(const char32* str) noexcept {
  return to_u16string(to_string(str));
}

u16string convert_string::to_u16string(char32* str) noexcept {
  return to_u16string(to_string(str));
}

u16string convert_string::to_u16string(const std::wstring& str) noexcept {
  return to_u16string(to_string(str));
}

u16string convert_string::to_u16string(const wchar* str) noexcept {
  return to_u16string(to_string(str));
}

u16string convert_string::to_u16string(wchar* str) noexcept {
  return to_u16string(to_string(str));
}

u32string convert_string::to_u32string(const std::string& str) noexcept {
  return to_u32string(str.c_str());
}

u32string convert_string::to_u32string(const char* str) noexcept {
  auto out = std::u32string {};
  auto codepoint = 0u;
  while (*str != 0) {
    auto ch = static_cast<unsigned char>(*str);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str;
    if (((*str & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<char32>(codepoint));
  }
  return out;
}

u32string convert_string::to_u32string(char* str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str));
}

u32string convert_string::to_u32string(const string& str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str.c_str()));
}

#if defined(__xtd__cpp_lib_char8_t)
u32string convert_string::to_u32string(const std::u8string& str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str.c_str()));
}

u32string convert_string::to_u32string(const char8* str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str));
}

u32string convert_string::to_u32string(char8* str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str));
}
#endif

u32string convert_string::to_u32string(const std::u16string& str) noexcept {
  return to_u32string(to_string(str));
}

u32string convert_string::to_u32string(const char16* str) noexcept {
  return to_u32string(to_string(str));
}

u32string convert_string::to_u32string(char16* str) noexcept {
  return to_u32string(to_string(str));
}

const u32string& convert_string::to_u32string(const u32string& str) noexcept {
  return str;
}

u32string convert_string::to_u32string(const std::u32string& str) noexcept {
  return str;
}

u32string convert_string::to_u32string(const char32* str) noexcept {
  return str;
}

u32string convert_string::to_u32string(char32* str) noexcept {
  return str;
}

u32string convert_string::to_u32string(const std::wstring& str) noexcept {
  return to_u32string(to_string(str));
}

u32string convert_string::to_u32string(const wchar* str) noexcept {
  return to_u32string(to_string(str));
}

u32string convert_string::to_u32string(wchar* str) noexcept {
  return to_u32string(to_string(str));
}

wstring convert_string::to_wstring(const std::string& str) noexcept {
  return to_wstring(str.c_str());
}

wstring convert_string::to_wstring(const char* str) noexcept {
  auto out = std::wstring {};
  auto codepoint = 0u;
  while (*str != 0) {
    auto ch = static_cast<unsigned char>(*str);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str;
    if (((*str & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(wchar) > 2)
        out.append(1, static_cast<wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<wchar>(0xd800 + (static_cast<wchar>(codepoint) >> 10)));
        out.append(1, static_cast<wchar>(0xdc00 + (static_cast<wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<wchar>(codepoint));
    }
  }
  return out;
}

wstring convert_string::to_wstring(char* str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str));
}

wstring convert_string::to_wstring(const string& str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str.c_str()));
}

#if defined(__xtd__cpp_lib_char8_t)
wstring convert_string::to_wstring(const std::u8string& str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str.c_str()));
}

wstring convert_string::to_wstring(const char8* str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str));
}

wstring convert_string::to_wstring(char8* str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str));
}
#endif

wstring convert_string::to_wstring(const std::u16string& str) noexcept {
  return to_wstring(to_string(str));
}

wstring convert_string::to_wstring(const char16* str) noexcept {
  return to_wstring(to_string(str));
}

wstring convert_string::to_wstring(char16* str) noexcept {
  return to_wstring(to_string(str));
}

wstring convert_string::to_wstring(const std::u32string& str) noexcept {
  return to_wstring(to_string(str));
}

wstring convert_string::to_wstring(const char32* str) noexcept {
  return to_wstring(to_string(str));
}

wstring convert_string::to_wstring(char32* str) noexcept {
  return to_wstring(to_string(str));
}

const wstring& convert_string::to_wstring(const wstring& str) noexcept {
  return str;
}

wstring convert_string::to_wstring(const std::wstring& str) noexcept {
  return str;
}

wstring convert_string::to_wstring(const wchar* str) noexcept {
  return str;
}

wstring convert_string::to_wstring(wchar* str) noexcept {
  return str;
}
