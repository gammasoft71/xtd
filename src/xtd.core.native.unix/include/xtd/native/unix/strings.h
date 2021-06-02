#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <limits>
#include <vector>
#include <string>

#undef unix

namespace xtd::native {
  class environment;
  class process;
  class translator;
  namespace unix {
    class strings final {
      friend xtd::native::environment;
      friend xtd::native::process;
      friend xtd::native::translator;
    protected:
      strings() = delete;
      
      static bool contains(const std::string& str, const std::string& value) noexcept {
        return str.find(value) != str.npos;
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
      
      static std::vector<std::string> split(const std::string& str, const std::vector<char>& separators, size_t count = std::numeric_limits<size_t>::max()) noexcept {
        if (count == 0) return {};
        if (count == 1) return {str};
        
        std::vector<std::string> list;
        std::string subString;
        std::vector<char> split_char_separators = separators.size() == 0 ? std::vector<char> {9, 10, 11, 12, 13, 32} : separators;
        for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
          bool is_separator =  std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
          if (!is_separator) subString.append(std::string(1, *it));
          if ((static_cast<size_t>(it - str.begin()) == str.length() - 1 || is_separator) && (subString.length() > 0 || (subString.length() == 0))) {
            if (list.size() == count - 1) {
              list.push_back(subString + std::string(str.c_str(), it - str.begin() + (is_separator ? 0 : 1), str.length() - (it - str.begin()) + (is_separator ? 0 : 1)));
              return list;
            }
            list.push_back(subString);
            subString.clear();
          }
        }
        
        return list;
      }

      static const std::string to_lower(const std::string& str) noexcept {
        std::string result;
        for(auto c : str)
          result.push_back(static_cast<char>(tolower(c)));
        return result;
      }
      
      static std::string substring(const std::string& str, size_t start_index, size_t length) noexcept {
        if (start_index >= str.size()) return "";
        return str.substr(start_index, length);
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

