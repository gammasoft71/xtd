/// @file
/// @brief Contains xtd::basic_string class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_BASIC_STRING_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/basic_string> or <xtd/basic_string.hpp> instead."
#endif

#include "array.hpp"
//#include "formatter.hpp"

/// @cond
template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t>::basic_string(const allocator_type& allocator) noexcept : chars_(allocator) {}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::index_of_any(const xtd::array<value_type>& values) const noexcept {
  return index_of_any(values, 0, size());
}

template<class char_t, class traits_t, class allocator_t>
xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::index_of_any(const xtd::array<value_type>& values, xtd::size start_index) const {
  return index_of_any(values, start_index, size() - start_index);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::index_of_any(const xtd::array<value_type>& values, xtd::size start_index, xtd::size count) const {
  if (start_index > size() || start_index + count > size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
  auto index = xtd::size {0};
  for (const auto& item : *this) {
    if (index++ < start_index) continue;
    if (index - 1 > start_index + count) break;
    if (std::find(values.begin(), values.end(), item) != values.end()) return index - 1;
  }
  return npos;
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::index_of_any(const std::initializer_list<value_type>& values) const noexcept {
  return index_of_any(xtd::array<value_type>(values));
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index) const {
  return index_of_any(xtd::array<value_type>(values), start_index);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index, xtd::size count) const {
  return index_of_any(xtd::array<value_type>(values), start_index, count);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::last_index_of_any(const xtd::array<value_type>& values) const noexcept {
  return last_index_of_any(values, 0, size());
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::last_index_of_any(const xtd::array<value_type>& values, xtd::size start_index) const {
  return last_index_of_any(values, start_index, size() - start_index);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::last_index_of_any(const xtd::array<value_type>& values, xtd::size start_index, xtd::size count) const {
  if (start_index > size() || start_index + count > size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
  auto index = size() - 1;
  for (auto iterator = crbegin(); iterator != crend(); ++iterator) {
    if (index-- > start_index + count) continue;
    if (index + 1 < start_index) break;
    if (std::find(values.begin(), values.end(), *iterator) != values.end()) return index + 1;
  }
  return npos;
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::last_index_of_any(const std::initializer_list<value_type>& values) const noexcept {
  return last_index_of_any(xtd::array<value_type>(values));
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::last_index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index) const {
  return last_index_of_any(xtd::array<value_type>(values), start_index);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::size xtd::basic_string<char_t, traits_t, allocator_t>::last_index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index, xtd::size count) const {
  return last_index_of_any(xtd::array<value_type>(values), start_index, count);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split() const noexcept {
  return split(default_split_separators, std::numeric_limits<xtd::size>::max(), xtd::string_split_options::none);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(value_type separator) const noexcept {
  return split(xtd::array<value_type> {separator}, std::numeric_limits<xtd::size>::max(), xtd::string_split_options::none);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(value_type separator, xtd::string_split_options options) const noexcept {
  return split(xtd::array<value_type> {separator}, std::numeric_limits<xtd::size>::max(), options);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(value_type separator, xtd::size count) const noexcept {
  return split(xtd::array<value_type> {separator}, count, xtd::string_split_options::none);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(value_type separator, xtd::size count, xtd::string_split_options options) const noexcept {
  return split(xtd::array<value_type> {separator}, count, options);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(const xtd::array<value_type>& separators) const noexcept {
  return split(separators, std::numeric_limits<xtd::size>::max(), xtd::string_split_options::none);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(const xtd::array<value_type>& separators, xtd::string_split_options options) const noexcept {
  return split(separators, std::numeric_limits<xtd::size>::max(), options);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(const xtd::array<value_type>& separators, xtd::size count) const noexcept {
  return split(separators, count, xtd::string_split_options::none);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>> xtd::basic_string<char_t, traits_t, allocator_t>::split(const xtd::array<value_type>& separators, xtd::size count, xtd::string_split_options options) const noexcept {
  if (count == 0) return {};
  if (count == 1) return {*this};
  
  auto result = std::vector<basic_string> {};
  auto sub_string = basic_string {};
  auto split_char_separators = separators.size() == 0 ? default_split_separators : separators;
  for (auto it = begin(); it != end(); ++it) {
    auto is_separator = std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
    if (!is_separator) sub_string.chars_.append(basic_string(1, *it));
    auto is_last = (it + 1 == end());
    auto should_add = is_last || is_separator;
    auto keep_empty = sub_string.length() > 0 || (options != xtd::string_split_options::remove_empty_entries);
    
    if (should_add && keep_empty) {
      if (result.size() == count - 1) {
        result.push_back(sub_string + basic_string(c_str(), it - begin() + (is_separator ? 0 : 1), length() - (it - begin()) + (is_separator ? 0 : 1)));
        return result;
      }
      result.push_back(sub_string);
      sub_string.chars_.clear();
    }
  }
  
  if (size() > 0 && std::find(split_char_separators.begin(), split_char_separators.end(), at(size() - 1)) != split_char_separators.end() && options != xtd::string_split_options::remove_empty_entries) result.push_back(basic_string {});
  
  return result;
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_array() const noexcept {
  return to_array(0, size());
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_array(xtd::size start_index) const {
  return to_array(start_index, size() - start_index);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_array(xtd::size start_index, xtd::size length) const {
  if (start_index >= size()) return {};
  if (start_index + length >= size()) return {begin() + start_index, end()};
  return {begin() + start_index, begin() + start_index + length};
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_char_array() const noexcept {
  return to_array(0, size());
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::to_char_array(xtd::size start_index, xtd::size length) const {
  return to_array(start_index, length);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::to_title_case() const noexcept {
  auto words = split({' '});
  for (auto& word : words)
    if (word.size() && word != word.to_upper()) word = static_cast<value_type>(toupper(word[0])) + word.substring(1).to_lower();
  return basic_string::join(" ", words);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::trim(value_type trim_char) const noexcept {
  return trim(xtd::array<value_type> {trim_char});
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::trim(const xtd::array<value_type>& trim_chars) const noexcept {
  return trim_start(trim_chars).trim_end(trim_chars);
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::trim_end(value_type trim_char) const noexcept {
  return trim_end(xtd::array<value_type> {trim_char});
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::trim_end(const xtd::array<value_type>& trim_chars) const noexcept {
  if (!size()) return *this;
  auto result = chars_;
  while (std::find(trim_chars.begin(), trim_chars.end(), result[result.size() - 1]) != trim_chars.end())
    result.erase(result.size() - 1, 1);
  return result;
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::trim_start(value_type trim_char) const noexcept {return trim_start(xtd::array<value_type> {trim_char});}

template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::trim_start(const xtd::array<value_type>& trim_chars) const noexcept {
  if (!size()) return *this;
  auto result = chars_;
  while (std::find(trim_chars.begin(), trim_chars.end(), result[0]) != trim_chars.end())
    result.erase(0, 1);
  return result;
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::concat(const xtd::array<basic_string>& values) noexcept {
  auto result = basic_string::empty_string;
  std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
  return result;
}

template<class char_t, class traits_t, class allocator_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::concat(const xtd::array<const_pointer>& values) noexcept {
  auto result = basic_string::empty_string;
  std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
  return result;
}

template<class char_t, class traits_t, class allocator_t>
template<class other_char_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::concat(const xtd::array<const other_char_t*>& values) noexcept {
  auto result = basic_string::empty_string;
  std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
  return result;
}


template<class char_t, class traits_t, class allocator_t>
template<class object_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::concat(const xtd::array<object_t>& args) noexcept {
  basic_string result;
  for (const auto& arg : args)
    result += format("{}", arg);
  return result;
}

template<class char_t, class traits_t, class allocator_t>
template<class ...args_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::format(const basic_string<char>& fmt, args_t&& ... args) {
  auto result = basic_string<char> {};
  auto index = xtd::size {0};
  auto formats = std::vector<__format_information<char>> {};
  auto begin_format_iterator = fmt.end();
  auto end_format_iterator = fmt.end();
  for (auto iterator = fmt.begin(); iterator != fmt.end(); ++iterator) {
    if (*iterator == '{') {
      if (++iterator == fmt.end())
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_opened_bracket_without_end_bracket);
      if (*iterator == '{')
        result += *iterator;
      else {
        begin_format_iterator = iterator;
        while (iterator != fmt.end() && *iterator != '}') ++iterator;
        if (iterator == fmt.end())
          xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_opened_bracket_without_end_bracket);
        end_format_iterator = iterator;
        __format_information<char> fi;
        fi.location = result.size();
        auto format_str = std::basic_string<char> {begin_format_iterator, end_format_iterator};
        if (format_str.size() == 0)
          fi.index = index++;
        else {
          xtd::size index_alignment_separator = basic_string(format_str).index_of(',');
          xtd::size index_format_separator = basic_string(format_str).index_of(u':');
          
          if (index_alignment_separator != std::basic_string<char>::npos && index_format_separator != std::basic_string<char>::npos && index_alignment_separator > index_format_separator)
            index_alignment_separator = std::basic_string<char>::npos;
            
          if (index_alignment_separator != basic_string<char_t>::npos)
            fi.alignment = format_str.substr(index_alignment_separator + 1, index_format_separator != std::basic_string<char>::npos ? index_format_separator - index_alignment_separator - 1 : std::basic_string<char>::npos);
            
          if (index_format_separator != basic_string<char>::npos)
            fi.format = format_str.substr(index_format_separator + 1);
            
          if (index_alignment_separator == 0 || index_format_separator == 0)
            fi.index = index++;
          else {
            auto index_str = std::basic_string<char> {};
            if (index_alignment_separator != basic_string<char>::npos)
              index_str = format_str.substr(0, index_alignment_separator);
            else if (index_format_separator != basic_string<char>::npos)
              index_str = format_str.substr(0, index_format_separator);
            else
              index_str = std::move(format_str);
            try {
              for (auto c : index_str)
                if (!std::isdigit(c)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format);
              fi.index = std::stoi(index_str);
            } catch (...) {
              xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format);
            }
          }
        }
        formats.push_back(fi);
      }
    } else if (*iterator == '}') {
      if (++iterator == fmt.end())
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_closing_bracket_without_open_bracket);
      if (*iterator != '}')
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format_closing_bracket_without_open_bracket);
      result += *iterator;
    } else
      result += *iterator;
  }
  
  __basic_string_extract_format_arg(result, formats, std::forward<args_t>(args)...);
  return result.c_str();
}

template<class char_t, class traits_t, class allocator_t>
template<class value_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::join(const basic_string& separator, const std::initializer_list<value_t>& values) noexcept {
  return join(separator, xtd::array<value_t>(values));
}

template<class char_t, class traits_t, class allocator_t>
template<class value_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::join(const basic_string& separator, const std::initializer_list<value_t>& values, xtd::size index) {
  return join(separator, xtd::array<value_t>(values), index);
}

template<class char_t, class traits_t, class allocator_t>
template<class value_t>
inline xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::join(const basic_string& separator, const std::initializer_list<value_t>& values, xtd::size index, xtd::size count) {
  return join(separator, xtd::array<value_t>(values), index, count);
}

template<class char_t, class traits_t, class allocator_t>
inline const xtd::basic_string<char_t, traits_t, allocator_t> xtd::basic_string<char_t, traits_t, allocator_t>::empty_string;

template<class char_t, class traits_t, class allocator_t>
inline const xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::default_split_separators = {9, 10, 11, 12, 13, 32};

template<class char_t, class traits_t, class allocator_t>
inline const xtd::array<typename xtd::basic_string<char_t, traits_t, allocator_t>::value_type> xtd::basic_string<char_t, traits_t, allocator_t>::default_trim_chars = {9, 10, 11, 12, 13, 32};

template<class arg_t>
void __basic_string_extract_format_arg(std::basic_string<char>& fmt, xtd::size& index, std::vector<__format_information<char >> & formats, arg_t&& arg) {
  //void __basic_string_extract_format_arg(xtd::basic_string<char>& fmt, xtd::size& index, std::vector<__format_information<char>>& formats, arg_t&& arg) {
  auto offset = xtd::size {0};
  for (auto& format : formats) {
    format.location += offset;
    if (format.index == index) {
      //xtd::basic_string<char> arg_str = xtd::formatter<arg_t> {}(arg, format.format, std::locale());
      xtd::basic_string<char> arg_str = xtd::to_string(arg, format.format);
      
      if (!format.alignment.empty()) {
        xtd::int32 alignment = 0;
        try {
          alignment = std::stoi(format.alignment);
        } catch (...) {
          xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format);
        }
        if (alignment > 0) arg_str = arg_str.pad_left(alignment);
        else if (alignment < 0) arg_str = arg_str.pad_right(-alignment);
      }
      fmt.insert(format.location, arg_str);
      offset += arg_str.size();
    }
  }
  ++index;
}

template<class ...args_t>
void __basic_string_extract_format_arg(xtd::basic_string<char>& fmt, std::vector<__format_information<char >> & formats, args_t&&... args) {
  auto index = xtd::size {0};
  (__basic_string_extract_format_arg(const_cast<std::basic_string<char>& > (fmt.chars()), index, formats, args), ...);
  //(__basic_string_extract_format_arg(fmt, index, formats, args), ...);
  unused_(index); // workaround to mute gcc warning: unused-but-set-variable
}

template<class target_t, class source_t>
inline std::basic_string<target_t> __xtd_convert_to_string(std::basic_string<source_t>&& str) noexcept {
  auto out = std::basic_string<target_t> {};
  auto codepoint = 0u;
  for (const auto& character : str) {
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

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, char>(std::basic_string<char>&& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, char>(std::basic_string<char>&& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, char>(std::basic_string<char>&& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  return out;
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  return out;
}

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, char>(std::basic_string<char>&& str) noexcept {
  return std::move(str);
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char16>(std::basic_string<xtd::char16>&& str) noexcept {
  return std::move(str);
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char32>(std::basic_string<xtd::char32>&& str) noexcept {
  return std::move(str);
}

template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  return std::move(str);
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::wchar>(std::basic_string<xtd::wchar>&& str) noexcept {
  return std::move(str);
}

template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, char>(std::basic_string<char>&& str) noexcept {
  return std::basic_string<xtd::char8> {reinterpret_cast<const xtd::char8*>(str.c_str())};
}

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  return std::basic_string<char> {reinterpret_cast<const char*>(str.c_str())};
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char32>(std::basic_string<xtd::char32>&& str) noexcept {
  return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(std::move(str)));
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::wchar>(std::basic_string<xtd::wchar>&& str) noexcept {
  return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(std::move(str)));
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char16>(std::basic_string<xtd::char16>&& str) noexcept {
  return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(std::move(str)));
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::wchar>(std::basic_string<xtd::wchar>&& str) noexcept {
  return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(std::move(str)));
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char16>(std::basic_string<xtd::char16>&& str) noexcept {
  return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(std::move(str)));
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char32>(std::basic_string<xtd::char32>&& str) noexcept {
  return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(std::move(str)));
}

template<class target_t, class source_t>
inline std::basic_string<target_t> __xtd_convert_to_string(const std::basic_string<source_t>& str) noexcept {
  auto out = std::basic_string<target_t> {};
  auto codepoint = 0u;
  for (const auto& character : str) {
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

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, char>(const std::basic_string<char>& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, char>(const std::basic_string<char>& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, char>(const std::basic_string<char>& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  return out;
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  return out;
}

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, char>(const std::basic_string<char>& str) noexcept {
  return str;
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char16>(const std::basic_string<xtd::char16>& str) noexcept {
  return str;
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char32>(const std::basic_string<xtd::char32>& str) noexcept {
  return str;
}

template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  return str;
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::wchar>(const std::basic_string<xtd::wchar>& str) noexcept {
  return str;
}

template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, char>(const std::basic_string<char>& str) noexcept {
  return reinterpret_cast<const xtd::char8*>(str.c_str());
}

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  return reinterpret_cast<const char*>(str.c_str());
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char32>(const std::basic_string<xtd::char32>& str) noexcept {
  return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::wchar>(const std::basic_string<xtd::wchar>& str) noexcept {
  return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char16>(const std::basic_string<xtd::char16>& str) noexcept {
  return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::wchar>(const std::basic_string<xtd::wchar>& str) noexcept {
  return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char16>(const std::basic_string<xtd::char16>& str) noexcept {
  return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(str));
}

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char32>(const std::basic_string<xtd::char32>& str) noexcept {
  return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(str));
}
/// @endcond
