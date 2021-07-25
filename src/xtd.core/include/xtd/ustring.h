/// @file
/// @brief Contains xtd::ustring class.
#pragma once
#include <string>
#include "string_comparison.h"
#include "types.h"
#include "object.h"
/// @cond
#define __XTD_CORE_INTERNAL__
#include "internal/__generic_stream_output.h"
#include "internal/__format_information.h"
#include "internal/__format_stringer.h"
#include "internal/__sprintf.h"
#undef __XTD_CORE_INTERNAL__
/// @endcond

/// @cond
template<typename ...args_t>
void __ustring_extract_format_arg(std::string& fmt, std::vector<__format_information<char>>& format, args_t&&... args);
void __throw_ustring_format_exception();
void __throw_ustring_format_exception_close_bracket();
void __throw_ustring_format_exception_open_bracket();
void __throw_ustring_format_exception_start_colon();
/// @endcond

namespace xtd {
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::ustring object is a sequential collection of xtd::char8 objects that represent a string; a xtd::char8 object corresponds to a UTF-8 code unit. The value of the xtd::utring object is the content of the sequential collection of xtd::char8 objects, and unlike std::basic_string that value is immutable (that is, it is read-only).
  /// @remarks if you want the same mutable string class, you can use xtd::text::ustring_builder class.
  class ustring : public object, public std::basic_string<char8_t> {
  public:
    /// @brief Initializes a new instance of xtd::ustring.
    ustring() noexcept;
    /// @brief Initializes a new instance of xtd::ustring with specitifed allocator.
    /// @param allocator The allocator to use for all memory allocations of this string.
    explicit ustring(const allocator_type& allocator) noexcept;
    
    /// @brief Initializes a new instance of xtd::ustring with specified count copies of character.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    ustring(size_t count, value_type character);
    /// @brief Initializes a new instance of xtd::ustring with specified count copies of character and specified allocator.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(size_t count, value_type character, const allocator_type& allocator);
    
    /// @brief Initializes a new instance of xtd::ustring with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring charecter where start copy.
    /// @param count The number of substring characters to copy.
    ustring(const ustring& str, size_t index, size_t count);
    /// @brief Initializes a new instance of xtd::ustring with specified substring at index, count characters and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring charecter where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(const ustring& str, size_t index, size_t count, const allocator_type& allocator);
    /// @brief Initializes a new instance of xtd::ustring with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring charecter where start copy.
    ustring(const ustring& str, size_t index);
    /// @brief Initializes a new instance of xtd::ustring with specified substring at index and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring charecter where start copy.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(const ustring& str, size_t index, const allocator_type& allocator);
    
    /// @brief Initializes a new instance of xtd::ustring with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    ustring(const value_type* str, size_t count);
    /// @brief Initializes a new instance of xtd::ustring with specified substring, count characters and allocator.
    /// @param str The string to copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(const value_type* str, size_t count, const allocator_type& allocator);
    
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy.
    ustring(const value_type* str);
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy, and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(const value_type* str, const allocator_type& allocator);
    
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy.
    ustring(const char* str);
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy, and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(const char* str, const allocator_type& allocator);
    
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy.
    /// @param str The string to copy.
    ustring(const ustring& str) noexcept;
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(const ustring& str, const allocator_type& allocator) noexcept;
    
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy.
    /// @param str The string to copy.
    ustring(const std::basic_string<value_type>& str) noexcept;
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(const std::basic_string<value_type>& str, const allocator_type& allocator) noexcept;
    
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy.
    /// @param str The string to copy.
    ustring(const std::string& str) noexcept;
    /// @brief Initializes a new instance of xtd::ustring with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(const std::string& str, const allocator_type& allocator) noexcept;
    
    /// @brief Initializes a new instance of xtd::ustring with specified string to move.
    /// @param str The string to move.
    ustring(ustring&& str) noexcept;
    /// @brief Initializes a new instance of xtd::ustring with specified string to move and allocator.
    /// @param str The string to move.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(ustring&& str, const allocator_type& allocator) noexcept;
    
    /// @brief Initializes a new instance of xtd::ustring with specified first and last iterators of substring.
    /// @param first The first iterator of substring.
    /// @param last The first iterator of substring.
    template<typename input_iterator_t>
    ustring(input_iterator_t first, input_iterator_t last) : std::basic_string<value_type>(first, last) {}
    /// @brief Initializes a new instance of xtd::ustring with specified first and last iterators of substring and allocator.
    /// @param first The first iterator of substring.
    /// @param last The first iterator of substring.
    /// @param allocator The allocator to use for all memory allocations of this string.
    template<typename input_iterator_t>
    ustring(input_iterator_t first, input_iterator_t last, const allocator_type& allocator) : std::basic_string<value_type>(first, last, allocator) {}
    
    /// @brief Initializes a new instance of xtd::ustring with specified initializer list.
    /// @param il The initalizer list to fill.
    ustring(std::initializer_list<value_type> il);
    /// @brief Initializes a new instance of xtd::ustring with specified initializer list and allocator.
    /// @param il The initalizer list to fill.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(std::initializer_list<value_type> il, const allocator_type& allocator);
    
    /// @brief Initializes a new instance of xtd::ustring with specified initializer list.
    /// @param il The initalizer list to fill.
    ustring(std::initializer_list<char> il);
    /// @brief Initializes a new instance of xtd::ustring with specified initializer list and allocator.
    /// @param il The initalizer list to fill.
    /// @param allocator The allocator to use for all memory allocations of this string.
    ustring(std::initializer_list<char> il, const allocator_type& allocator);
    
    /// @cond
    template<typename type_t>
    ustring(const type_t& object) : std::basic_string<value_type>(object) {}
    template<typename type_t>
    ustring(const type_t& object, const allocator_type& allocator) : std::basic_string<value_type>(object, allocator) {}
    template<typename type_t>
    ustring(const type_t& object, size_t index, size_t count) : std::basic_string<value_type>(object, index, count) {}
    template<typename type_t>
    ustring(const type_t& object, size_t index, size_t count, const allocator_type& allocator) : std::basic_string<value_type>(object, index, count, allocator) {}
    template<typename type_t>
    ustring(const type_t& object, size_t count) : std::basic_string<value_type>(object, 0, count) {}
    template<typename type_t>
    ustring(const type_t& object, size_t count, const allocator_type& allocator) : std::basic_string<value_type>(object, 0, count, allocator) {}
    
    ustring& operator=(const ustring& str);
    ustring& operator=(value_type character);
    ustring& operator=(char character);
    ustring& operator=(const value_type* str);
    ustring& operator=(const char* str);
    ustring& operator=(const std::initializer_list<value_type>& il);
    template<typename type_t>
    ustring operator=(const type_t& object) {return std::basic_string<value_type>::assign(object);}
    const value_type& operator[](size_t index);
    const value_type& operator[](size_t index) const;
    ustring substr(size_type index = 0, size_type count = npos) const;
    /// @endcond
    
    using std::basic_string<value_type>::compare;
    /// @brief Compares two specified String objects and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first string to compare.
    /// @param str_b The second string to compare.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two comparands.
    /// | Value             | Condition                                                     |
    /// |-------------------|---------------------------------------------------------------|
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    static int compare(const ustring& str_a, const ustring& str_b) noexcept;
    /// @brief Compares two specified String objects, ignoring or honoring their case, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first string to compare.
    /// @param str_b The second string to compare.
    /// @param ignore_case true to ignore case during the comparison; otherwise, false.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two comparands.
    /// | Value             | Condition                                                     |
    /// |-------------------|---------------------------------------------------------------|
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    static int compare(const ustring& str_a, const ustring& str_b, bool ignore_case) noexcept;
    
    /// @brief Compares two specified String objects using the specified rules, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first string to compare.
    /// @param str_b The second string to compare.
    /// @param comparison_type One of the enumeration values that specifies the rules to use in the comparison.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two comparands.
    /// | Value             | Condition                                                     |
    /// |-------------------|---------------------------------------------------------------|
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    static int compare(const ustring& str_a, const ustring& str_b, xtd::string_comparison comparison_type) noexcept;
    /// @brief Compares substrings of two specified String objects and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first string to use in the comparison.
    /// @param index_a The position of the substring within str_a.
    /// @param str_b The second string to use in the comparison.
    /// @param index_b The position of the substring within str_b.
    /// @param length The maximum number of characters in the substrings to compare
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two comparands.
    /// | Value             | Condition                                                     |
    /// |-------------------|---------------------------------------------------------------|
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    static int compare(const ustring& str_a, size_t index_a, const ustring& str_b, size_t index_b, size_t length) noexcept;
    /// @brief Compares substrings of two specified String objects, ignoring or honoring their case, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first string to use in the comparison.
    /// @param index_a The position of the substring within str_a.
    /// @param str_b The second string to use in the comparison.
    /// @param index_b The position of the substring within str_b.
    /// @param length The maximum number of characters in the substrings to compare
    /// @param ignore_case true to ignore case during the comparison; otherwise, false.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two comparands.
    /// | Value             | Condition                                                     |
    /// |-------------------|---------------------------------------------------------------|
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    static int compare(const ustring& str_a, size_t index_a, const ustring& str_b, size_t index_b, size_t length, bool ignore_case) noexcept;
    /// @brief Compares substrings of two specified String objects using the specified rules, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first string to use in the comparison.
    /// @param index_a The position of the substring within str_a.
    /// @param str_b The second string to use in the comparison.
    /// @param index_b The position of the substring within str_b.
    /// @param length The maximum number of characters in the substrings to compare
    /// @param comparison_type One of the enumeration values that specifies the rules to use in the comparison.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two comparands.
    /// | Value             | Condition                                                     |
    /// |-------------------|---------------------------------------------------------------|
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    static int compare(const ustring& str_a, size_t index_a, const ustring& str_b, size_t index_b, size_t length, xtd::string_comparison comparison_type) noexcept;
    
    /// @brief Concatenates four specified instances of string.
    /// @param str_a The first string to concatenate.
    /// @param str_b The second string to concatenate.
    /// @param str_c The third string to concatenate.
    /// @param str_d The fourth string to concatenate.
    /// @return The concatenation of str_a, str_b, str_c and str_d.
    static ustring concat(const ustring& str_a, const ustring& str_b, const ustring& str_c, const ustring& str_d) noexcept;
    
    /// @brief Concatenates four specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @param obj_d The fourth object to concatenate.
    /// @return The concatenation of obj_a, obj_b, obj_c and obj_d.
    template<typename object_a_t, typename object_b_t, typename object_c_t, typename object_d_t>
    static ustring concat(object_a_t obj_a, object_b_t obj_b, object_c_t obj_c, object_d_t obj_d) noexcept {
      return format("{}{}{}{}", obj_a, obj_b, obj_c, obj_d);
    }
    
    /// @brief Concatenates three specified instances of string.
    /// @param str_a The first string to concatenate.
    /// @param str_b The second string to concatenate.
    /// @param str_c The third string to concatenate.
    /// @return String The concatenation of str_a, str_b and str_c.
    static ustring concat(const ustring& str_a, const ustring& str_b, const ustring& str_c) noexcept;
    
    /// @brief Concatenates three specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @return The concatenation of obj_a, obj_b and obj_c.
    template<typename object_a_t, typename object_b_t, typename object_c_t>
    static ustring concat(object_a_t obj_a, object_b_t obj_b, object_c_t obj_c) noexcept {
      return format("{}{}{}", obj_a, obj_b, obj_c);
    }
    
    /// @brief Concatenates two specified instances of string.
    /// @param str_a The first string to concatenate.
    /// @param str_b The second string to concatenate.
    /// @return String The concatenation of str_a and str_b.
    static ustring concat(const ustring& str_a, const ustring& str_b) noexcept;
    
    /// @brief Concatenates two specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @return The concatenation of obj_a and obj_b.
    template<typename object_a_t, typename object_b_t>
    static ustring concat(object_a_t obj_a, object_b_t obj_b) noexcept {
      return format("{}{}", obj_a, obj_b);
    }
    
    /// @brief Concatenates the elements of a specified string array.
    /// @param values An array of string instances.
    /// @return The concatenated elements of values.
    static ustring concat(const std::vector<ustring>& values) noexcept;
    
    /// @cond
    static ustring concat(const std::vector<const value_type*>& values) noexcept;
    static ustring concat(const std::vector<const char*>& values) noexcept;
    static ustring concat(const std::initializer_list<ustring>& values) noexcept;
    static ustring concat(const std::initializer_list<const value_type*>& values) noexcept;
    static ustring concat(const std::initializer_list<const char*>& values) noexcept;
    /// @endcond
    
    /// @brief Concatenates the string representations of the elements in a specified object array.
    /// @param args An object array that contains the elements to concatenate.
    /// @return The concatenated string representations of the values of the elements in args.
    template<typename object_t>
    static ustring concat(const std::vector<object_t>& args) noexcept {
      ustring result;
      for (const auto& arg : args)
        result += format("{}", arg);
      return result;
    }
    
    /// @cond
    template<typename object_t>
    static ustring concat(const std::initializer_list<object_t>& args) noexcept {
      ustring result;
      for (const auto& arg : args)
        result += format("{}", arg);
      return result;
    }
    /// @endcond
    
    /// @brief Creates the string representation of a specified object.
    /// @param value The object to represent.
    /// @return The string representation of the value of arg.
    template<typename value_t>
    static ustring concat(value_t value) noexcept {
      return format("{}", value);
    }
    
    /// @brief Returns a value indicating whether a specified substring occurs within the specified string.
    /// @param value The string to seek.
    /// @return true if the value parameter occurs within this string, or if value is the empty string (""); otherwise, false.
    bool contains(const ustring& value) const noexcept;
    
    /// @brief Represents the empty string.
    /// @remarks The value of this method is the zero-length string, "".
    static ustring empty() noexcept;

    /// @brief Determines whether the end of the specified string matches the specified char_t.
    /// @param str The string to match.
    /// @param value The char_t to compare to the substring at the end of this instance.
    /// @return true if value matches the end of this instance; otherwise, false.
    bool ends_with(value_type value) const noexcept;

    /// @brief Determines whether the end of the specified string matches the specified char_t.
    /// @param str The string to match.
    /// @param value The char_t to compare to the substring at the end of this instance.
    /// @return true if value matches the end of this instance; otherwise, false.
    bool ends_with(char value) const noexcept;
    
    /// @brief Determines whether the end of the specified string matches the specified string.
    /// @param value The string to compare to the substring at the end of this instance.
    /// @return true if value matches the end of this instance; otherwise, false.
    bool ends_with(const ustring& value) noexcept;
    
    /// @brief Determines whether the end of this string instance matches the specified string when compared using the specified culture.
    /// @param ignore_case true to ignore case during the comparison; otherwise, false.
    /// @return bool true if value matches the end of the specified string; otherwise, false.
    bool ends_with(const ustring& value, bool ignore_case) noexcept;
    
    /// @brief Determines whether the end of the specified string matches the specified string when compared using the specified comparison option.
    /// @param comparison_type One of the enumeration values that determines how this string and value are compared.
    /// @return bool true if value matches the end of the specified string; otherwise, false.
    bool ends_with(const ustring& value, xtd::string_comparison comparison_type) noexcept;

    /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
    /// @param fmt A composite format string.
    /// @param args anarguments list to write using format.
    /// @return string formated.
    /// @ingroup format_parse
    /// @remarks for more information about format see @ref FormatPage "Format".
    template<typename ...args_t>
    static ustring format(const ustring& fmt, args_t&&... args) {
      std::string result;
      size_t index = 0;
      std::string sfmt = reinterpret_cast<const char*>(fmt.c_str());
      std::vector<__format_information<char>> formats;
      typename std::string::const_iterator begin_format_iterator =  sfmt.cend();
      typename std::string::const_iterator end_format_iterator =  sfmt.cend();
      for (typename std::string::const_iterator iterator = sfmt.cbegin(); iterator != sfmt.cend(); ++iterator) {
        if (*iterator == '{') {
          ++iterator;
          if (*iterator == '{')
            result += *iterator;
          else {
            begin_format_iterator = iterator;
            while (*iterator != '}' && iterator != sfmt.end()) ++iterator;
            if (iterator == sfmt.end())
              __throw_ustring_format_exception_open_bracket();
            end_format_iterator = iterator;
            __format_information<char> fi;
            fi.location = result.size();
            std::string format {begin_format_iterator, end_format_iterator};
            if (format.size() == 0)
              fi.index = index++;
            else {
              size_t index_alignment_separator = ustring(format).index_of(',');
              size_t index_format_separator = ustring(format).index_of(u8':');
              
              if (index_alignment_separator != std::string::npos && index_format_separator != std::string::npos && index_alignment_separator > index_format_separator)
                index_alignment_separator = std::string::npos;
              
              if (index_alignment_separator != std::string::npos)
                fi.alignment = format.substr(index_alignment_separator + 1, index_format_separator != std::string::npos ? index_format_separator - index_alignment_separator - 1 : std::string::npos);
              
              if (index_format_separator != std::string::npos)
                fi.format = format.substr(index_format_separator + 1);
              
              if (index_alignment_separator == 0 || index_format_separator == 0)
                fi.index = index++;
              else {
                std::string index_str;
                if (index_alignment_separator != std::string::npos)
                  index_str = format.substr(0, index_alignment_separator);
                else if (index_format_separator != std::string::npos)
                  index_str = format.substr(0, index_format_separator);
                else
                  index_str = format;
                try {
                  for (auto c : index_str)
                    if (!std::isdigit(c)) __throw_ustring_format_exception_start_colon();
                  fi.index = std::stoi(index_str);
                } catch(...) {
                  __throw_ustring_format_exception_start_colon();
                }
              }
            }
            formats.push_back(fi);
          }
        } else if (*iterator == '}') {
          if (++iterator == sfmt.cend())
            __throw_ustring_format_exception_close_bracket();
          if (*iterator != '}')
            __throw_ustring_format_exception_close_bracket();
          result += *iterator;
        } else
          result += *iterator;
      }
      
      __ustring_extract_format_arg(result, formats, std::forward<args_t>(args)...);
      return result.c_str();
    }

    /// @brief Returns the hash code for this string.
    /// @return A hash code.
    size_t get_hash_code() const noexcept override;

    /// @brief Reports the index of the first occurrence of the specified character in the sêcified tring.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @return size_t The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    size_t index_of(value_type value) const noexcept;
    
    /// @brief Reports the index of the first occurrence of the specified string in the specified string.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @return size_t The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    size_t index_of(const ustring& value) const noexcept;

    /// @brief Reports the index of the first occurrence of the specified character in the spexified string. The search starts at a specified character position.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @return size_t The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    size_t index_of(value_type value, size_t start_index) const noexcept;
    
    /// @brief Reports the index of the first occurrence of the specified character in the spexified string. The search starts at a specified character position.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @return size_t The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    size_t index_of(const ustring& value, size_t start_index) const noexcept;

    /// @brief Reports the index of the first occurrence of the specified character in the spexified string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return size_t The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    size_t index_of(value_type value, size_t start_index, size_t count) const noexcept;
    
    /// @brief Reports the index of the first occurrence of the specified character in the spexified string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return size_t The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    size_t index_of(const ustring& value, size_t start_index, size_t count) const noexcept;

    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters.
    /// @param str A String to find index of any.
    /// @param values A Unicode character array containing one or more characters to seek
    /// @return size_t The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    size_t index_of_any(const std::vector<value_type>& values) noexcept;
    
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param str A String to find index of any.
    /// @param values A Unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @return size_t The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    size_t index_of_any(const std::vector<value_type>& values, size_t start_index) noexcept;
    
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param str A String to find index of any.
    /// @param values A Unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine.
    /// @return size_t The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    size_t index_of_any(const std::vector<value_type>& values, size_t start_index, size_t count) noexcept;
    
    /// @cond
    size_t index_of_any(const std::initializer_list<value_type>& values) noexcept;
    size_t index_of_any(const std::initializer_list<value_type>& values, size_t start_index) noexcept;
    size_t index_of_any(const std::initializer_list<value_type>& values, size_t start_index, size_t count) noexcept;
    /// @endcond
    
    /// @brief Inserts a specified instance of String at a specified index position in this instance.
    /// @param start_index The index position of the insertion.
    /// @param value The String to insert.
    /// @return String A new String equivalent to this instance but with value inserted at position start_index.
    /// @remarks If start_index is equal to the length of this instance, value is appended to the end of this instance.
    /// @remarks For example, the return value of "abc".Insert(2, "XYZ") is "abXYZc".
    ustring insert(size_t start_index, const ustring& value) const noexcept;
    
    /// @brief Indicates whether the specified string is an empty string ("").
    /// @param str The string to test.
    /// @return true if the value parameter is null or an empty string (""); otherwise, false.
    bool is_empty() const noexcept;

    /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
    /// @param separator A String separator.
    /// @param values An array of Object.
    /// @return A String consisting of the elements of value interspersed with the separator String.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename collection_t>
    static ustring join(const ustring separator, const collection_t& values) noexcept {return join(separator, values, 0, values.size());}
    
    /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
    /// @param separator A String separator.
    /// @param values An array of Object.
    /// @param start_index The first array element in value to use.
    /// @return A String consisting of the elements of value interspersed with the separator String.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename collection_t>
    static ustring join(const ustring& separator, const collection_t& values, size_t index) noexcept {return join(separator, values, index, values.size()-index);}
    
    /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
    /// @param separator A String separator.
    /// @param values An array of Object.
    /// @param start_index The first array element in value to use.
    /// @param count The number of elements of value to use.
    /// @return A String consisting of the elements of value interspersed with the separator String.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename collection_t>
    static ustring join(const ustring& separator, const collection_t& values, size_t index, size_t count) noexcept {
      size_t i = 0;
      ustring result;
      for (const auto& item : values) {
        if (i >= index) {
          if (i != index) result += separator;
          result += format("{}", item);
        }
        if (++i >= index + count) break;
      }
      return result;
    }
    
    /// @cond
    template<typename value_t>
    static ustring join(const ustring& separator, const std::initializer_list<value_t>& values) noexcept {return join(separator, std::vector<value_t>(values));}
    template<typename value_t>
    static ustring join(const ustring& separator, const std::initializer_list<value_t>& values, size_t index) noexcept {return join(separator, std::vector<value_t>(values), index);}
    template<typename value_t>
    static ustring join(const ustring& separator, const std::initializer_list<value_t>& values, size_t index, size_t count) noexcept {return join(separator, std::vector<value_t>(values), index, count);}
    /// @endcond
    
    /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
    /// @param fmt A composite format string.
    /// @param args anarguments list to write using format.
    /// @return string formated.
    /// @ingroup format_parse
    /// @remarks A format specifier follows this prototype:
    /// @remarks %[flags][width][.precision][length]specifier
    /// | specifier | Output                                                                                                                                                   | Example      |
    /// |-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------|--------------|
    /// | d or i    | Signed decimal integer                                                                                                                                   | 392          |
    /// | u         | Unsigned decimal integer                                                                                                                                 | 7235         |
    /// | o         | Unsigned octal                                                                                                                                           | 610          |
    /// | x         | Unsigned hexadecimal integer                                                                                                                             | 7fa          |
    /// | X         | Unsigned hexadecimal integer (uppercase)                                                                                                                 | 7FA          |
    /// | f         | Decimal floating point, lowercase                                                                                                                        | 392.65       |
    /// | F         | Decimal floating point, lowercase (uppercase)                                                                                                            | 392.65       |
    /// | e         | Scientific notation (mantissa/exponent), lowercase                                                                                                       | 3.9265e+2    |
    /// | E         | Scientific notation (mantissa/exponent), uppercase                                                                                                       | 3.9265E+2    |
    /// | g         | Use the shortest representation: %e or %f                                                                                                                | 392.65       |
    /// | G         | Use the shortest representation: %E or %F                                                                                                                | 392.65       |
    /// | a         | Hexadecimal floating point, lowercase                                                                                                                    | -0xc.90fep-2 |
    /// | A         | Hexadecimal floating point, uppercase                                                                                                                    | -0XC.90FEP-2 |
    /// | c         | Character                                                                                                                                                | a            |
    /// | s         | String of characters                                                                                                                                     | sample       |
    /// | p         | Pointer address                                                                                                                                          | b8000000     |
    /// | n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location |              |
    /// | %         | A % followed by another % character will write a single % to the stream.                                                                                 | %            |
    /// @remarks The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:
    /// | flags   | description                                                                                                                                                                                                                                                                                                 |
    /// |---------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    /// | -       | Left-justify within the given field width; Right justification is the default (see width sub-specifier).                                                                                                                                                                                                    |
    /// | +       | Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.                                                                                                                                                    |
    /// | (space) | If no sign is going to be written, a blank space is inserted before the value.                                                                                                                                                                                                                              |
    /// | #       | Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written. |
    /// | 0       | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).                                                                                                                                                                                                 |
    ///
    /// | width    | description                                                                                                                                                                                          |
    /// |----------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    /// | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
    /// | *        | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                                        |
    ///
    /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
    /// |------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
    /// | .*         | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
    /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
    /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n              |
    /// |--------|---------------|------------------------|-----------------|-------|----------|-------|----------------|
    /// | (none) | int           | unsigned int           | double          | int   | char*    | void* | int*           |
    /// | hh     | signed char   | unsigned char          |                 |       |          |       | unsigned char* |
    /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*     |
    /// | l      | long int      | unsigned long int      |                 | win_t | wchar_t* |       | long int*      |
    /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int* |
    /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*      |
    /// | z      | size_t        | size_t                 |                 |       |          |       | size_t*        |
    /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*     |
    /// | L      |               |                        | long double     |       |          |       |                |
    /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char value (or a wchar_t) before formatting it for output.
    /// @remarks you can use std::string or std::wstring with format param %%s.
    template<typename ... args_t>
    static ustring sprintf(const ustring& fmt, args_t&& ... args) noexcept {return __sprintf(reinterpret_cast<const char*>(fmt.c_str()), std::forward<args_t>(args) ...);}

    /// @brief Returns a copy of the current string converted to lowercase.
    /// @return String A new String in lowercase.
    ustring to_lower() const noexcept;
    
    std::string to_string() const noexcept override;
    
    /// @brief Returns a copy of the current string converted to uppercase.
    /// @return String A new String in uppercase.
    ustring to_upper() const noexcept;
    
    /// @cond
    friend std::ostream& operator<<(std::ostream& os, const ustring& str) {return os << (reinterpret_cast<const char*>(str.c_str()));}
    /// @endcond
    
  private:
    using std::basic_string<value_type>::assign;
    using std::basic_string<value_type>::reserve;
    using std::basic_string<value_type>::shrink_to_fit;
    using std::basic_string<value_type>::clear;
    using std::basic_string<value_type>::insert;
    using std::basic_string<value_type>::erase;
    using std::basic_string<value_type>::push_back;
    using std::basic_string<value_type>::pop_back;
    using std::basic_string<value_type>::append;
    using std::basic_string<value_type>::replace;
    using std::basic_string<value_type>::resize;
  };
}

#include <xtd/parse.h>
#include <xtd/to_string.h>

/// @cond
template<typename arg_t>
void __ustring_extract_format_arg(std::string& fmt, size_t& index, std::vector<__format_information<char>>& formats, arg_t&& arg) {
  size_t offset = 0;
  for (auto& format : formats) {
    format.location += offset;
    if (format.index == index) {
      std::string arg_str = format.format.empty() ? __format_stringer<char, arg_t>(arg) : xtd::to_string(arg, format.format);
      
      if (!format.alignment.empty()) {
        int alignment = 0;
        try {
          alignment = std::stoi(format.alignment);
        } catch(...) {
          __throw_ustring_format_exception();
        }
        if (alignment > 0) arg_str = xtd::strings::pad_left(arg_str, alignment);
        else if (alignment < 0) arg_str = xtd::strings::pad_right(arg_str, -alignment);
      }
      fmt.insert(format.location, arg_str);
      offset += arg_str.size();
    }
  }
  ++index;
}

template <typename ...args_t>
void __xtd_ustrings_unused(args_t&& ... args) {}

template<typename ...args_t>
void __ustring_extract_format_arg(std::string& fmt, std::vector<__format_information<char>>& formats, args_t&&... args) {
  size_t index = 0;
  (__ustring_extract_format_arg(fmt, index, formats, args),...);
  __xtd_ustrings_unused(index); // workouround to mute gcc warning: unused-but-set-variable
}
/// @endcond
