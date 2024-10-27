#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <algorithm>
#include <string>
#include <vector>

namespace xtd::native {
  namespace win32 {
    class strings final {
    public:
      strings() = delete;
      
      inline static const std::string empty_string;
      
      static bool contains(const std::string& str, const std::string& value) noexcept {
        return str.find(value) != str.npos;
      }
      
      static bool ends_with(const std::string& str, const std::string& value) noexcept {
        return str.rfind(value) + value.size() == str.size();
      }
      
      template<typename separator_t, typename collection_t>
      static std::string join(const separator_t& separator, const collection_t& values) noexcept {return join(separator, values, 0, values.size());}
      
      template<typename separator_t, typename collection_t>
      static std::string join(const separator_t& separator, const collection_t& values, size_t index, size_t count) noexcept {
        auto i = size_t {};
        auto ss = std::stringstream {};
        for (const auto& item : values) {
          if (i >= index) {
            if (i != index) ss << separator;
            ss << item;
          }
          if (++i >= index + count) break;
        }
        return ss.str();
      }
      
      static size_t last_index_of(const std::string& str, char value) noexcept {
        return last_index_of(str, value, 0, str.size());
      }
      
      static size_t last_index_of(const std::string& str, const std::string& value) noexcept {
        return last_index_of(str, value, 0, str.size());
      }
      
      static size_t last_index_of(const std::string& str, char value, size_t start_index) noexcept {
        return last_index_of(str, value, start_index, str.size() - start_index);
      }
      
      static size_t last_index_of(const std::string& str, const std::string& value, size_t start_index) noexcept {
        return last_index_of(str, value, start_index, str.size() - start_index);
      }
      
      static size_t last_index_of(const std::string& str, char value, size_t start_index, size_t count) noexcept {
        auto result = str.rfind(value, start_index + count - 1);
        return result < start_index ? str.npos : result;
      }
      
      static size_t last_index_of(const std::string& str, const std::string& value, size_t start_index, size_t count) noexcept {
        auto result = str.rfind(value, start_index + count - value.size());
        return result < start_index ? str.npos : result;
      }
      
      static std::string remove(const std::string& str, size_t start_index) noexcept {
        return remove(str, start_index, str.size() - start_index);
      }
      
      static std::string remove(const std::string& str, size_t start_index, size_t count) noexcept {
        if (start_index > str.size()) return str;
        auto result = str;
        return result.erase(start_index, count);
      }
      
      static std::string replace(const std::string& str, const std::string& old_string, const std::string& new_string) noexcept {
        auto result = str;
        auto index = size_t {};
        while (true) {
          index = result.find(old_string, index);
          if (index == std::string::npos) break;
          result.erase(index, old_string.size());
          result.insert(index, new_string);
          index += new_string.size();
        }
        return result;
      }
      
      static std::vector<std::string> split(const std::string& str, const std::vector<char>& separators, size_t count = std::numeric_limits<size_t>::max(), bool remove_empty_entries = false) noexcept {
        if (count == 0) return {};
        if (count == 1) return {str};
        
        auto list = std::vector<std::string> {};
        auto sub_string = std::string {};
        auto split_char_separators = separators.size() == 0 ? std::vector<char> {9, 10, 11, 12, 13, 32} : separators;
        for (auto it = str.begin(); it != str.end(); ++it) {
          auto is_separator = std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
          if (!is_separator) sub_string.append(std::string(1, *it));
          if ((static_cast<size_t>(it - str.begin()) == str.length() - 1 || is_separator) && (sub_string.length() > 0 || (sub_string.length() == 0  && !remove_empty_entries))) {
            if (list.size() == count - 1) {
              list.push_back(sub_string + std::string(str.c_str(), it - str.begin() + (is_separator ? 0 : 1), str.length() - (it - str.begin()) + (is_separator ? 0 : 1)));
              return list;
            }
            list.push_back(sub_string);
            sub_string.clear();
          }
        }
        
        return list;
      }
      
      static std::string sub_string(const std::string& str, size_t start_index, size_t length) noexcept {
        if (start_index >= str.size()) return "";
        return str.substr(start_index, length);
      }
      
      static const std::string to_lower(const std::string& str) noexcept {
        auto result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
      }
      
      static const std::string to_upper(const std::string& str) noexcept {
        auto result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
      }
      
      static std::string trim_end(const std::string& str, const std::vector<char>& trim_chars) noexcept {
        if (!str.size()) return str;
        auto result = str;
        while (std::find(trim_chars.begin(), trim_chars.end(), result[result.size() - 1]) != trim_chars.end())
          result.erase(result.size() - 1, 1);
        return result;
      }
      
      static bool try_parse(const std::string& str, int32_t& value) noexcept {
        try {
          value = std::atoi(str.c_str());
          return true;
        } catch (...) {
          return false;
        }
      }
    };
  }
}

