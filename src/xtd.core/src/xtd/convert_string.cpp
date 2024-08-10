#include "../../include/xtd/convert_string.h"

using namespace xtd;

namespace {
  template<typename target_t, typename source_t>
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

const std::string& convert_string::to_string(const std::string& str) noexcept {
  return str;
}

std::string convert_string::to_string(const char* str) noexcept {
  return str;
}

std::string convert_string::to_string(char* str) noexcept {
  return str;
}

std::string convert_string::to_string(const ustring& str) noexcept {
  return str;
}

#if defined(__xtd__cpp_lib_char8_t)
std::string convert_string::to_string(const std::u8string& str) noexcept {
  return reinterpret_cast<const char*>(str.c_str());
}

std::string convert_string::to_string(const char8* str) noexcept {
  return reinterpret_cast<const char*>(str);
}

std::string convert_string::to_string(char8* str) noexcept {
  return reinterpret_cast<const char*>(str);
}
#endif

std::string convert_string::to_string(const std::u16string& str) noexcept {
  return convert_to_string<char>(str);
}

std::string convert_string::to_string(const char16* str) noexcept {
  return to_string(std::u16string(str));
}

std::string convert_string::to_string(char16* str) noexcept {
  return to_string(std::u16string(str));
}

std::string convert_string::to_string(const std::u32string& str) noexcept {
  return convert_to_string<char>(str);
}

std::string convert_string::to_string(const char32* str) noexcept {
  return to_string(std::u32string(str));
}

std::string convert_string::to_string(char32* str) noexcept {
  return to_string(std::u32string(str));
}

std::string convert_string::to_string(const std::wstring& str) noexcept {
  return convert_to_string<char>(str);
}

std::string convert_string::to_string(const wchar* str) noexcept {
  return to_string(std::wstring(str));
}

std::string convert_string::to_string(wchar* str) noexcept {
  return to_string(std::wstring(str));
}

ustring convert_string::to_ustring(const std::string& str) noexcept {
  return str;
}

ustring convert_string::to_ustring(const char* str) noexcept {
  return str;
}

ustring convert_string::to_ustring(char* str) noexcept {
  return str;
}

const ustring& convert_string::to_ustring(const ustring& str) noexcept {
  return str;
}

#if defined(__xtd__cpp_lib_char8_t)
ustring convert_string::to_ustring(const std::u8string& str) noexcept {
  return reinterpret_cast<const char*>(str.c_str());
}

ustring convert_string::to_ustring(const char8* str) noexcept {
  return reinterpret_cast<const char*>(str);
}

ustring convert_string::to_ustring(char8* str) noexcept {
  return reinterpret_cast<char*>(str);
}
#endif

ustring convert_string::to_ustring(const std::u16string& str) noexcept {
  return to_string(str);
}

ustring convert_string::to_ustring(const char16* str) noexcept {
  return to_string(std::u16string(str));
}

ustring convert_string::to_ustring(char16* str) noexcept {
  return to_string(std::u16string(str));
}

ustring convert_string::to_ustring(const std::u32string& str) noexcept {
  return to_string(str);
}

ustring convert_string::to_ustring(const char32* str) noexcept {
  return to_string(std::u32string(str));
}

ustring convert_string::to_ustring(char32* str) noexcept {
  return to_string(std::u32string(str));
}

ustring convert_string::to_ustring(const std::wstring& str) noexcept {
  return to_string(str);
}

ustring convert_string::to_ustring(const wchar* str) noexcept {
  return to_string(std::wstring(str));
}

ustring convert_string::to_ustring(wchar* str) noexcept {
  return to_string(std::wstring(str));
}

#if defined(__xtd__cpp_lib_char8_t)
std::u8string convert_string::to_u8string(const std::string& str) noexcept {
  return reinterpret_cast<const char8*>(str.c_str());
}

std::u8string convert_string::to_u8string(const char* str) noexcept {
  return reinterpret_cast<const char8*>(str);
}

std::u8string convert_string::to_u8string(char* str) noexcept {
  return reinterpret_cast<const char8*>(str);
}

std::u8string convert_string::to_u8string(const ustring& str) noexcept {
  return reinterpret_cast<const char8*>(str.c_str());
}

const std::u8string& convert_string::to_u8string(const std::u8string& str) noexcept {
  return str;
}

std::u8string convert_string::to_u8string(const char8* str) noexcept {
  return str;
}

std::u8string convert_string::to_u8string(char8* str) noexcept {
  return str;
}

std::u8string convert_string::to_u8string(const std::u16string& str) noexcept {
  return convert_to_string<char8>(str);
}

std::u8string convert_string::to_u8string(const char16* str) noexcept {
  return to_u8string(std::u16string(str));
}

std::u8string convert_string::to_u8string(char16* str) noexcept {
  return to_u8string(std::u16string(str));
}

std::u8string convert_string::to_u8string(const std::u32string& str) noexcept {
  return convert_to_string<char8>(str);
}

std::u8string convert_string::to_u8string(const char32* str) noexcept {
  return to_u8string(std::u32string(str));
}

std::u8string convert_string::to_u8string(char32* str) noexcept {
  return to_u8string(std::u32string(str));
}

std::u8string convert_string::to_u8string(const std::wstring& str) noexcept {
  return convert_to_string<char8>(str);
}

std::u8string convert_string::to_u8string(const wchar* str) noexcept {
  return to_u8string(std::wstring(str));
}

std::u8string convert_string::to_u8string(wchar* str) noexcept {
  return to_u8string(std::wstring(str));
}
#endif

std::u16string convert_string::to_u16string(const std::string& str) noexcept {
  return to_u16string(str.c_str());
}

std::u16string convert_string::to_u16string(const char* str) noexcept {
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

std::u16string convert_string::to_u16string(char* str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str));
}

std::u16string convert_string::to_u16string(const ustring& str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str.c_str()));
}

#if defined(__xtd__cpp_lib_char8_t)
std::u16string convert_string::to_u16string(const std::u8string& str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str.c_str()));
}

std::u16string convert_string::to_u16string(const char8* str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str));
}

std::u16string convert_string::to_u16string(char8* str) noexcept {
  return to_u16string(reinterpret_cast<const char*>(str));
}
#endif

const std::u16string& convert_string::to_u16string(const std::u16string& str) noexcept {
  return str;
}

std::u16string convert_string::to_u16string(const char16* str) noexcept {
  return str;
}

std::u16string convert_string::to_u16string(char16* str) noexcept {
  return str;
}

std::u16string convert_string::to_u16string(const std::u32string& str) noexcept {
  return to_u16string(to_ustring(str));
}

std::u16string convert_string::to_u16string(const char32* str) noexcept {
  return to_u16string(to_ustring(str));
}

std::u16string convert_string::to_u16string(char32* str) noexcept {
  return to_u16string(to_ustring(str));
}

std::u16string convert_string::to_u16string(const std::wstring& str) noexcept {
  return to_u16string(to_ustring(str));
}

std::u16string convert_string::to_u16string(const wchar* str) noexcept {
  return to_u16string(to_ustring(str));
}

std::u16string convert_string::to_u16string(wchar* str) noexcept {
  return to_u16string(to_ustring(str));
}

std::u32string convert_string::to_u32string(const std::string& str) noexcept {
  return to_u32string(str.c_str());
}

std::u32string convert_string::to_u32string(const char* str) noexcept {
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

std::u32string convert_string::to_u32string(char* str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str));
}

std::u32string convert_string::to_u32string(const ustring& str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str.c_str()));
}

#if defined(__xtd__cpp_lib_char8_t)
std::u32string convert_string::to_u32string(const std::u8string& str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str.c_str()));
}

std::u32string convert_string::to_u32string(const char8* str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str));
}

std::u32string convert_string::to_u32string(char8* str) noexcept {
  return to_u32string(reinterpret_cast<const char*>(str));
}
#endif

std::u32string convert_string::to_u32string(const std::u16string& str) noexcept {
  return to_u32string(to_ustring(str));
}

std::u32string convert_string::to_u32string(const char16* str) noexcept {
  return to_u32string(to_ustring(str));
}

std::u32string convert_string::to_u32string(char16* str) noexcept {
  return to_u32string(to_ustring(str));
}

const std::u32string& convert_string::to_u32string(const std::u32string& str) noexcept {
  return str;
}

std::u32string convert_string::to_u32string(const char32* str) noexcept {
  return str;
}

std::u32string convert_string::to_u32string(char32* str) noexcept {
  return str;
}

std::u32string convert_string::to_u32string(const std::wstring& str) noexcept {
  return to_u32string(to_ustring(str));
}

std::u32string convert_string::to_u32string(const wchar* str) noexcept {
  return to_u32string(to_ustring(str));
}

std::u32string convert_string::to_u32string(wchar* str) noexcept {
  return to_u32string(to_ustring(str));
}

std::wstring convert_string::to_wstring(const std::string& str) noexcept {
  return to_wstring(str.c_str());
}

std::wstring convert_string::to_wstring(const char* str) noexcept {
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

std::wstring convert_string::to_wstring(char* str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str));
}

std::wstring convert_string::to_wstring(const ustring& str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str.c_str()));
}

#if defined(__xtd__cpp_lib_char8_t)
std::wstring convert_string::to_wstring(const std::u8string& str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str.c_str()));
}

std::wstring convert_string::to_wstring(const char8* str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str));
}

std::wstring convert_string::to_wstring(char8* str) noexcept {
  return to_wstring(reinterpret_cast<const char*>(str));
}
#endif

std::wstring convert_string::to_wstring(const std::u16string& str) noexcept {
  return to_wstring(to_ustring(str));
}

std::wstring convert_string::to_wstring(const char16* str) noexcept {
  return to_wstring(to_ustring(str));
}

std::wstring convert_string::to_wstring(char16* str) noexcept {
  return to_wstring(to_ustring(str));
}

std::wstring convert_string::to_wstring(const std::u32string& str) noexcept {
  return to_wstring(to_ustring(str));
}

std::wstring convert_string::to_wstring(const char32* str) noexcept {
  return to_wstring(to_ustring(str));
}

std::wstring convert_string::to_wstring(char32* str) noexcept {
  return to_wstring(to_ustring(str));
}

const std::wstring& convert_string::to_wstring(const std::wstring& str) noexcept {
  return str;
}

std::wstring convert_string::to_wstring(const wchar* str) noexcept {
  return str;
}

std::wstring convert_string::to_wstring(wchar* str) noexcept {
  return str;
}
