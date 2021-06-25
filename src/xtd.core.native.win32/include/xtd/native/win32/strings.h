#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <string>
#include <vector>

namespace xtd::native {
  class debugger;
  class environment;
  class process;
  class translator;
  namespace win32 {
    class strings final {
      friend xtd::native::debugger;
      friend xtd::native::environment;
      friend xtd::native::process;
      friend xtd::native::translator;
    protected:
      strings() = delete;
      
      static bool contains(const std::string& str, const std::string& value) noexcept {
        return str.find(value) != str.npos;
      }

      static bool ends_with(const std::string& str, const std::string& value) noexcept {
        return to_lower(str).rfind(to_lower(value)) + to_lower(value).size() == str.size();
      }

      static std::string replace(const std::string& str, const std::string& old_string, const std::string& new_string) noexcept {
        std::string result(str);
        size_t index = 0;
        while (true) {
          index = result.find(old_string, index);
          if (index == std::string::npos) break;
          result.erase(index, old_string.size());
          result.insert(index, new_string);
          index += new_string.size();
        }
        return result;
      }
      
      static std::vector<std::string> split(const std::string& str, const std::vector<char>& separators) noexcept {
        std::vector<std::string> list;
        std::string subString;
        std::vector<char> split_char_separators = separators.size() == 0 ? std::vector<char> {9, 10, 11, 12, 13, 32} : separators;
        for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
          bool is_separator =  std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
          if (!is_separator) subString.append(std::string(1, *it));
          if ((static_cast<size_t>(it - str.begin()) == str.length() - 1 || is_separator) && (subString.length() > 0 || (subString.length() == 0))) {
            list.push_back(subString);
            subString.clear();
          }
        }
        
        return list;
      }

      static std::string substring(const std::string& str, size_t start_index, size_t length) noexcept {
        if (start_index >= str.size()) return "";
        return str.substr(start_index, length);
      }

      static const std::string to_lower(const std::string& str) noexcept {
        std::string result;
        for(auto c : str)
          result.push_back(static_cast<char>(tolower(c)));
        return result;
      }

      static std::wstring to_wstring(const std::string& str) {return to_wstring(str.c_str());}
      static std::wstring to_wstring(const char* str) {
        std::wstring out;
        char32_t codepoint;
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
              out.append(1, static_cast<wchar_t>(0xd800 + (codepoint >> 10)));
              out.append(1, static_cast<wchar_t>(0xdc00 + (codepoint & 0x03ff)));
            } else if (codepoint < 0xd800 || codepoint >= 0xe000)
              out.append(1, static_cast<wchar_t>(codepoint));
          }
        }
        return out;
      }

      static std::string trim_end(const std::string& str, const std::vector<char>& trim_chars) noexcept {
        if (!str.size()) return str;
        std::string result(str);
        while (std::find(trim_chars.begin(), trim_chars.end(), result[result.size() - 1]) != trim_chars.end())
          result.erase(result.size() - 1, 1);
        return result;
      }
      
      static bool try_parse(const std::string& str, int32_t& value) {
        try {
          value = std::atoi(str.c_str());
          return true;
        } catch(...) {
          return false;
        }
      }
      
    };
  }
}

