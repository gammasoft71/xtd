/// @file
/// @brief Contains xtd::strings class.
#pragma once

#include "__format.hpp"
#include "istring.hpp"
#include "string_comparison.hpp"
#include "string_split_options.hpp"

#include <algorithm>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

/// @cond
template<typename Char>
struct __format_information {
  size_t index = -1;
  size_t location;
  std::basic_string<Char> format;
};

template<typename Char, typename ...Args>
void __extract_format_arg(std::basic_string<Char>& fmt, std::vector<__format_information<Char>>& format, Args&&... args);
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The strings Caintains string operation methods.
  class strings {
  public:
    /// @cond
    strings() = delete;
    /// @endcond

    /// @brief Compares two specified String objects and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first string to compare.
    /// @param str_b The second string to compare.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two comparands.
    /// | Value             | Condition                                                     |
    /// |-------------------|---------------------------------------------------------------|
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, const std::basic_string<Char>& str_b) noexcept {return compare(str_a, str_b, false);}

    /// @cond
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, const Char* str_b) noexcept {return compare(str_a, str_b, false);}
    template<typename Char>
    static int compare(const Char* str_a, const std::basic_string<Char>& str_b) noexcept {return compare(str_a, str_b, false);}
    template<typename Char>
    static int compare(const Char* str_a, const Char* str_b) noexcept {return compare(str_a, str_b, false);}
    /// @endcond

    
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
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, const std::basic_string<Char>& str_b, bool ignore_case) noexcept {return compare(str_a, str_b, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);}
    
    /// @cond
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, const Char* str_b, bool ignore_case) noexcept {return compare(str_a, std::basic_string<Char>(str_b), ignore_case);}
    template<typename Char>
    static int compare(const Char* str_a, const std::basic_string<Char>& str_b, bool ignore_case) noexcept {return compare(std::basic_string<Char>(str_a), str_b, ignore_case);}
    template<typename Char>
    static int compare(const Char* str_a, const Char* str_b, bool ignore_case) noexcept {return compare(std::basic_string<Char>(str_a), std::basic_string<Char>(str_b), ignore_case);}
    /// @endcond

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
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, const std::basic_string<Char>& str_b, xtd::string_comparison comparison_type) noexcept {
      if (comparison_type == xtd::string_comparison::ordinal_ignore_case)
        return to_lower(str_a).compare(to_lower(str_b));
      return str_a.compare(str_b);
    }
    
    /// @cond
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, const Char* str_b, xtd::string_comparison comparison_type) noexcept {return compare(str_a, std::basic_string<Char>(str_b), comparison_type);}
    template<typename Char>
    static int compare(const Char* str_a, const std::basic_string<Char>& str_b, xtd::string_comparison comparison_type) noexcept {return compare(std::basic_string<Char>(str_a), str_b, comparison_type);}
    template<typename Char>
    static int compare(const Char* str_a, const Char* str_b, xtd::string_comparison comparison_type) noexcept {return compare(std::basic_string<Char>(str_a), std::basic_string<Char>(str_b), comparison_type);}
    /// @endcond

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
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, size_t index_a, const std::basic_string<Char>& str_b, size_t index_b, size_t length) noexcept {return compare(str_a, index_a, str_b, index_b, length, false);}
    
    /// @cond
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, size_t index_a, const Char* str_b, size_t index_b, size_t length) noexcept {return compare(str_a, index_a, str_b, index_b, length, false);}
    template<typename Char>
    static int compare(const Char* str_a, size_t index_a, const std::basic_string<Char>& str_b, size_t index_b, size_t length) noexcept {return compare(str_a, index_a, str_b, index_b, length, false);}
    template<typename Char>
    static int compare(const Char* str_a, size_t index_a, const Char* str_b, size_t index_b, size_t length) noexcept {return compare(str_a, index_a, str_b, index_b, length, false);}
    /// @endcond
    
    
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
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, size_t index_a, const std::basic_string<Char>& str_b, size_t index_b, size_t length, bool ignore_case) noexcept {
      std::basic_string<Char> sa(str_a.substr(index_a, length));
      std::basic_string<Char> sb(str_b.substr(index_b, length));
      return compare(str_a, index_a, str_b, index_b, length, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);
    }
    
    /// @cond
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, size_t index_a, const Char* str_b, size_t index_b, size_t length, bool ignore_case) noexcept {return compare(str_a, index_a, std::basic_string<Char>(str_b), index_b, length, ignore_case);}
    template<typename Char>
    static int compare(const Char* str_a, size_t index_a, const std::basic_string<Char>& str_b, size_t index_b, size_t length, bool ignore_case) noexcept {return compare(std::basic_string<Char>(str_a), index_a, str_b, index_b, length, ignore_case);}
    template<typename Char>
    static int compare(const Char* str_a, size_t index_a, const Char* str_b, size_t index_b, size_t length, bool ignore_case) noexcept {return compare(std::basic_string<Char>(str_a), index_a, std::basic_string<Char>(str_b), index_b, length, ignore_case);}
    /// @endcond

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
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, size_t index_a, const std::basic_string<Char>& str_b, size_t index_b, size_t length, xtd::string_comparison comparison_type) noexcept {
      std::basic_string<Char> sa(str_a.substr(index_a, length));
      std::basic_string<Char> sb(str_b.substr(index_b, length));
      if (comparison_type == xtd::string_comparison::ordinal_ignore_case)
        return to_lower(sa).compare(to_lower(sb));
      return sa.compare(sb);
    }
    
    /// @cond
    template<typename Char>
    static int compare(const std::basic_string<Char>& str_a, size_t index_a, const Char* str_b, size_t index_b, size_t length, xtd::string_comparison comparison_type) noexcept {return compare(str_a, index_a, std::basic_string<Char>(str_b), index_b, length, comparison_type);}
    template<typename Char>
    static int compare(const Char* str_a, size_t index_a, const std::basic_string<Char>& str_b, size_t index_b, size_t length, xtd::string_comparison comparison_type) noexcept {return compare(std::basic_string<Char>(str_a), index_a, str_b, index_b, length, comparison_type);}
    template<typename Char>
    static int compare(const Char* str_a, size_t index_a, const Char* str_b, size_t index_b, size_t length, xtd::string_comparison comparison_type) noexcept {return compare(std::basic_string<Char>(str_a), index_a, std::basic_string<Char>(str_b), index_b, length, comparison_type);}
    /// @endcond

    /// @brief Concatenates four specified instances of string.
    /// @param str_a The first string to concatenate.
    /// @param str_b The second string to concatenate.
    /// @param str_c The third string to concatenate.
    /// @param str_d The fourth string to concatenate.
    /// @return The concatenation of str_a, str_b, str_c and str_d.
    template<typename Char>
    static std::basic_string<Char> concat(const std::basic_string<Char>& str_a, const std::basic_string<Char>& str_b, const std::basic_string<Char>& str_c, const std::basic_string<Char>& str_d) noexcept {
      std::basic_stringstream<Char> ss;
      ss << str_a;
      ss << str_b;
      ss << str_c;
      ss << str_d;
      return ss.str();
    }

    /// @brief Concatenates four specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @param obj_d The fourth object to concatenate.
    /// @return The concatenation of obj_a, obj_b, obj_c and obj_d.
    template<typename Char, typename ObjectA, typename ObjectB, typename ObjectC, typename ObjectD>
    static std::basic_string<Char> concat(ObjectA obj_a, ObjectB obj_b, ObjectC obj_c, ObjectD obj_d) noexcept {
      std::basic_stringstream<Char> ss;
      ss << obj_a;
      ss << obj_b;
      ss << obj_c;
      ss << obj_d;
      return ss.str();
    }
 
    /// @brief Concatenates four specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @param obj_d The fourth object to concatenate.
    /// @return The concatenation of obj_a, obj_b, obj_c and obj_d.
    template<typename ObjectA, typename ObjectB, typename ObjectC, typename ObjectD>
    static std::string concat(ObjectA obj_a, ObjectB obj_b, ObjectC obj_c, ObjectD obj_d) noexcept {
      std::stringstream ss;
      ss << obj_a;
      ss << obj_b;
      ss << obj_c;
      ss << obj_d;
      return ss.str();
    }
    
    /// @brief Concatenates three specified instances of string.
    /// @param str_a The first string to concatenate.
    /// @param str_b The second string to concatenate.
    /// @param str_c The third string to concatenate.
    /// @return String The concatenation of str_a, str_b and str_c.
    template<typename Char>
    static std::basic_string<Char> concat(const std::basic_string<Char>& str_a, const std::basic_string<Char>& str_b, const std::basic_string<Char>& str_c) noexcept {
      std::basic_stringstream<Char> ss;
      ss << str_a;
      ss << str_b;
      ss << str_c;
      return ss.str();
    }
    
    /// @brief Concatenates three specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @return The concatenation of obj_a, obj_b and obj_c.
    template<typename Char, typename ObjectA, typename ObjectB, typename ObjectC>
    static std::basic_string<Char> concat(ObjectA obj_a, ObjectB obj_b, ObjectC obj_c) noexcept {
      std::basic_stringstream<Char> ss;
      ss << obj_a;
      ss << obj_b;
      ss << obj_c;
      return ss.str();
    }
    
    /// @brief Concatenates three specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @return The concatenation of obj_a, obj_b and obj_c.
    template<typename ObjectA, typename ObjectB, typename ObjectC>
    static std::string concat(ObjectA obj_a, ObjectB obj_b, ObjectC obj_c) noexcept {
      std::stringstream ss;
      ss << obj_a;
      ss << obj_b;
      ss << obj_c;
      return ss.str();
    }

    /// @brief Concatenates two specified instances of string.
    /// @param str_a The first string to concatenate.
    /// @param str_b The second string to concatenate.
    /// @return String The concatenation of str_a and str_b.
    template<typename Char>
    static std::basic_string<Char> concat(const std::basic_string<Char>& str_a, const std::basic_string<Char>& str_b) noexcept {
      std::basic_stringstream<Char> ss;
      ss << str_a;
      ss << str_b;
      return ss.str();
    }
    
    /// @brief Concatenates two specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @return The concatenation of obj_a and obj_b.
    template<typename Char, typename ObjectA, typename ObjectB>
    static std::basic_string<Char> concat(ObjectA obj_a, ObjectB obj_b) noexcept {
      std::basic_stringstream<Char> ss;
      ss << obj_a;
      ss << obj_b;
      return ss.str();
    }
    
    /// @brief Concatenates two specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @return The concatenation of obj_a and obj_b.
    template<typename ObjectA, typename ObjectB>
    static std::string concat(const ObjectA& obj_a, const ObjectB& obj_b) noexcept {
      std::stringstream ss;
      ss << obj_a;
      ss << obj_b;
      return ss.str();
    }
    
    /// @brief Concatenates the elements of a specified string array.
    /// @param values An array of string instances.
    /// @return The concatenated elements of values.
    template<typename Char>
    static std::basic_string<Char> concat(const std::vector<std::basic_string<Char>>& values) noexcept {
      std::basic_stringstream<Char> ss;
      for (const auto& item : values)
        ss << item;
      return ss.str();
    }
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> concat(const std::vector<const Char*>& values) noexcept {
      std::basic_stringstream<Char> ss;
      for (const auto& item : values)
        ss << item;
      return ss.str();
    }
    
    template<typename Char>
    static std::basic_string<Char> concat(const std::initializer_list<std::basic_string<Char>>& values) noexcept {
      std::basic_stringstream<Char> ss;
      for (const auto& item : values)
        ss << item;
      return ss.str();
    }
    
    template<typename Char>
    static std::basic_string<Char> concat(const std::initializer_list<const Char*>& values) noexcept {
      std::basic_stringstream<Char> ss;
      for (const auto& item : values)
        ss << item;
      return ss.str();
    }
    /// @endcond

    /// @brief Concatenates the string representations of the elements in a specified Object array.
    /// @param args An object array that contains the elements to concatenate.
    /// @return The concatenated string representations of the values of the elements in args.
    template<typename Char, typename Object>
    static std::basic_string<Char> concat(const std::vector<Object>& args) noexcept {
      std::basic_stringstream<Char> ss;
      for (const auto& item : args)
        ss << item;
      return ss.str();
    }
    
    /// @cond
    template<typename Char, typename Object>
    static std::basic_string<Char> concat(const std::initializer_list<Object>& args) noexcept {
      std::basic_stringstream<Char> ss;
      for (const auto& item : args)
        ss << item;
      return ss.str();
    }
    /// @endcond

    /// @brief Concatenates the string representations of the elements in a specified Object array.
    /// @param args An object array that contains the elements to concatenate.
    /// @return The concatenated string representations of the values of the elements in args.
    template<typename Object>
    static std::string concat(const std::vector<Object>& args) noexcept {
      std::stringstream ss;
      for (const auto& item : args)
        ss << item;
      return ss.str();
    }
    
    /// @cond
    template<typename Object>
    static std::string concat(const std::initializer_list<Object>& args) noexcept {
      std::stringstream ss;
      for (const auto& item : args)
        ss << item;
      return ss.str();
    }
    /// @endcond

    /// @brief Creates the string representation of a specified object.
    /// @param obj_a The object to represent.
    /// @return The string representation of the value of arg0.
    template<typename Char, typename Value>
    static std::basic_string<Char> concat(Value value) noexcept {
      std::basic_stringstream<Char> ss;
      ss << value;
      return ss.str();
    }
    
    /// @brief Creates the string representation of a specified object.
    /// @param obj_a The object to represent.
    /// @return The string representation of the value of arg0.
    template<typename Value>
    static std::string concat(Value value) noexcept {
      std::stringstream ss;
      ss << value;
      return ss.str();
    }
    
    /// @brief Returns a value indicating whether a specified substring occurs within the specified string.
    /// @param str The string to check.
    /// @param value The string to seek.
    /// @return true if the value parameter occurs within this string, or if value is the empty string (""); otherwise, false.
    template<typename Char>
    static bool contains(const std::basic_string<Char>& str, const std::basic_string<Char>& value) noexcept {
      return str.find(value) != str.npos;
    }
    
    /// @cond
    template<typename Char>
    static bool contains(const std::basic_string<Char>& str, const Char* value) noexcept {return contains(str, std::basic_string<Char>(value));}
    template<typename Char>
    static bool contains(const Char* str, const std::basic_string<Char>& value) noexcept {return contains(std::basic_string<Char>(str), value);}
    template<typename Char>
    static bool contains(const Char* str, const Char* value) noexcept {return contains(std::basic_string<Char>(str), std::basic_string<Char>(value));}
    /// @endcond
    
    /// @brief Represents the empty string.
    /// @remarks The value of this method is the zero-length string, "".
    template<typename Char>
    static std::basic_string<Char> empty() noexcept {return {};}
    
    /// @brief Represents the empty string.
    /// @remarks The value of this method is the zero-length string, "".
    static std::string empty() noexcept {return {};}
    
    /// @brief Determines whether the end of the specified string matches the specified Char.
    /// @param str The string to match.
    /// @param value The Char to compare to the substring at the end of this instance.
    /// @return true if value matches the end of this instance; otherwise, false.
    template<typename Char>
    static bool ends_with(const std::basic_string<Char>& str, Char value) noexcept {return str.rfind(value) == str.size() - 1;}
    
    /// @cond
    template<typename Char>
    static bool ends_with(const Char* str, Char value) noexcept {return ends_with(std::basic_string<Char>(str), value);}
    /// @endcond

    /// @brief Determines whether the end of the specified string matches the specified string.
    /// @param str The string to match.
    /// @param value The string to compare to the substring at the end of this instance.
    /// @return true if value matches the end of this instance; otherwise, false.
    template<typename Char>
    static bool ends_with(const std::basic_string<Char>& str, const std::basic_string<Char>& value) noexcept {return ends_with(str, value, false);}
    
    /// @brief Determines whether the end of this string instance matches the specified string when compared using the specified culture.
    /// @param str The string to match.
    /// @param ignore_case true to ignore case during the comparison; otherwise, false.
    /// @return bool true if value matches the end of the specified string; otherwise, false.
    template<typename Char>
    static bool ends_with(const std::basic_string<Char>& str, const std::basic_string<Char>& value, bool ignore_case) noexcept {return ends_with(str, value, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);}
    
    /// @brief Determines whether the end of the specified string matches the specified string when compared using the specified comparison option.
    /// @param str The string to match.
    /// @param comparison_type One of the enumeration values that determines how this string and value are compared.
    /// @return bool true if value matches the end of the specified string; otherwise, false.
    template<typename Char>
    static bool ends_with(const std::basic_string<Char>& str, const std::basic_string<Char>& value, xtd::string_comparison comparison_type) noexcept {
      if (comparison_type == xtd::string_comparison::ordinal_ignore_case)
        return to_lower(str).rfind(to_lower(value)) + to_lower(value).size() == str.size();
      return str.rfind(value) + value.size() == str.size();
    }

    /// @cond
    template<typename Char>
    static bool ends_with(const std::basic_string<Char>& str, const Char* value) noexcept {return ends_with(str, std::basic_string<Char>(value), false);}
    template<typename Char>
    static bool ends_with(const Char* str, const std::basic_string<Char>& value) noexcept {return ends_with(std::basic_string<Char>(str), value, false);}
    template<typename Char>
    static bool ends_with(const Char* str, const Char* value) noexcept {return ends_with(std::basic_string<Char>(str), std::basic_string<Char>(value), false);}

    template<typename Char>
    static bool ends_with(const std::basic_string<Char>& str, const Char* value, bool ignore_case) noexcept {return ends_with(str, std::basic_string<Char>(value), ignore_case);}
    template<typename Char>
    static bool ends_with(const Char* str, const std::basic_string<Char>& value, bool ignore_case) noexcept {return ends_with(std::basic_string<Char>(str), value, ignore_case);}
    template<typename Char>
    static bool ends_with(const Char* str, const Char* value, bool ignore_case) noexcept {return ends_with(std::basic_string<Char>(str), std::basic_string<Char>(value), ignore_case);}

    template<typename Char>
    static bool ends_with(const std::basic_string<Char>& str, const Char* value, xtd::string_comparison comparison_type) noexcept {return ends_with(str, std::basic_string<Char>(value), comparison_type);}
    template<typename Char>
    static bool ends_with(const Char* str, const std::basic_string<Char>& value, xtd::string_comparison comparison_type) noexcept {return ends_with(std::basic_string<Char>(str), value, comparison_type);}
    template<typename Char>
    static bool ends_with(const Char* str, const Char* value, xtd::string_comparison comparison_type) noexcept {return ends_with(std::basic_string<Char>(str), std::basic_string<Char>(value), comparison_type);}
    /// @endcond

    template<typename Char, typename ...Args>
    static std::basic_string<Char> format(const std::basic_string<Char>&& fmt, Args&&... args) {
      std::basic_string<Char> result;
      size_t index = 0;
      std::vector<__format_information<Char>> formats;
      
      typename std::basic_string<Char>::const_iterator begin_format_iterator =  fmt.cend();
      typename std::basic_string<Char>::const_iterator end_format_iterator =  fmt.cend();
      for (typename std::basic_string<Char>::const_iterator iterator = fmt.cbegin(); iterator != fmt.cend(); ++iterator) {
        if (*iterator == '{') {
          ++iterator;
          if (*iterator == '{')
            result += *iterator;
          else {
            begin_format_iterator = iterator;
            while (*iterator != '}' && iterator != fmt.end()) ++iterator;
            if (iterator == fmt.end())
              throw std::invalid_argument("Invalid format expression : open bracket '}' without end bracket '{'");
            end_format_iterator = iterator;
            __format_information<Char> fi;
            fi.location = result.size();
            std::basic_string<Char> format {begin_format_iterator, end_format_iterator};
            if (format.size() == 0)
              fi.index = index++;
            else {
              size_t index_format_separator = format.find(':');
              if (index_format_separator == std::basic_string<Char>::npos) {
                fi.index = std::stoi(format.substr(0, index_format_separator));
              } else if (index_format_separator == 0) {
                fi.index = index++;
                fi.format = format;
              } else {
                fi.index = std::stoi(format.substr(0, index_format_separator));
                fi.format = format.substr(index_format_separator+1);
              }
            }
            formats.push_back(fi);
          }
        } else if (*iterator == '}') {
          if (++iterator == fmt.cend())
            throw std::invalid_argument("Invalid format expression : closing bracket '{' without open bracket '}'");
          if (*iterator != '}')
            throw std::invalid_argument("Invalid format expression : closing bracket '{' without open bracket '}'");
          result += *iterator;
        } else
          result += *iterator;
      }

      __extract_format_arg(result, formats, std::forward<Args>(args)...);
      return result;
    }
    
    template<typename Char, typename ...Args>
    static std::basic_string<Char> format(const Char* fmt, Args&&... args) {return format(std::basic_string<Char>(fmt), std::forward<Args>(args)...);}

    /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
    /// @param fmt A composite format string.
    /// @param args anarguments list to write using format.
    /// @return string formated.
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
    /// | *        | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                                        |
    ///
    /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
    /// |------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
    /// | .*         | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
    /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
    /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n              |
    /// |--------|---------------|------------------------|-----------------|-------|----------|-------|----------------|
    /// | (none) | int           | unsigned int           | double          | int   | char*    | void* | int*           |
    /// | hh     | signed char   | unsigned char          |                 |       |          |       | unsigned char* |
    /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*     |
    /// | l      | long int      | unsigned long int      |                 | win_t | wchar_t* |       | long int*      |
    /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int* |
    /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*      |
    /// | z      | size_t        | size_t                 |                 |       |          |       | size_t*        |
    /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*     |
    /// | L      |               |                        | long double     |       |          |       |                |
    /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char value (or a wchar_t) before formatting it for output.
    /// @remarks you can use std::string or std::wstring with format param %%s.
    template<typename Char, typename ... Args>
    static std::basic_string<Char> formatf(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {return __formatf(fmt.c_str(), convert_param(std::forward<Args>(args)) ...);}

    /// @cond
    template<typename Char, typename ... Args>
    static std::basic_string<Char> formatf(const Char* fmt, Args&& ... args) noexcept {return formatf(std::basic_string<Char>(fmt), std::forward<Args>(args) ...);}
    /// @endcond

    /// @brief Returns the hash code for this string.
    /// @return A hash code.
    template<typename Char>
    static size_t get_hash_code(const std::basic_string<Char>& str) noexcept {return std::hash<std::basic_string<Char>>()(str);}

    /// @cond
    template<typename Char>
    static size_t get_hash_code(const Char* str) noexcept {return std::hash<std::basic_string<Char>>{}(std::basic_string<Char>(str));}
    /// @endcond

    /// @brief Reports the index of the first occurrence of the specified character in the sêcified tring.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t index_of(const std::basic_string<Char>& str, Char value) noexcept {return index_of(str, value, 0, str.size());}
    
    /// @brief Reports the index of the first occurrence of the specified string in the specified string.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t index_of(const std::basic_string<Char>& str, const std::basic_string<Char>& value) noexcept {return index_of(str, value, 0, str.size());}

    /// @cond
    template<typename Char>
    static size_t index_of(const Char* str, Char value) noexcept {return index_of(std::basic_string<Char>(str), value);}
    template<typename Char>
    static size_t index_of(const std::basic_string<Char>& str, const Char* value) noexcept {return index_of(str, std::basic_string<Char>(value));}
    template<typename Char>
    static size_t index_of(const Char* str, const std::basic_string<Char>& value) noexcept {return index_of(std::basic_string<Char>(str), value);}
    template<typename Char>
    static size_t index_of(const Char* str, const Char* value) noexcept {return index_of(std::basic_string<Char>(str), std::basic_string<Char>(value));}
    /// @endcond
    
    /// @brief Reports the index of the first occurrence of the specified character in the spexified string. The search starts at a specified character position.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t index_of(const std::basic_string<Char>& str, Char value, size_t start_index) noexcept {return index_of(str, value, start_index, str.size() - start_index);}
    
    /// @brief Reports the index of the first occurrence of the specified character in the spexified string. The search starts at a specified character position.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t index_of(const std::basic_string<Char>& str, const std::basic_string<Char>& value, size_t start_index) noexcept {return index_of(str, value, start_index, str.size() - start_index);}
    
    /// @cond
    template<typename Char>
    static size_t index_of(const Char* str, Char value, size_t start_index) noexcept {return index_of(std::basic_string<Char>(str), value, start_index);}
    template<typename Char>
    static size_t index_of(const std::basic_string<Char>& str, const Char* value, size_t start_index) noexcept {return index_of(str, std::basic_string<Char>(value), start_index);}
    template<typename Char>
    static size_t index_of(const Char* str, const std::basic_string<Char>& value, size_t start_index) noexcept {return index_of(std::basic_string<Char>(str), value, start_index);}
    template<typename Char>
    static size_t index_of(const Char* str, const Char* value, size_t start_index) noexcept {return index_of(std::basic_string<Char>(str), std::basic_string<Char>(value), start_index);}
    /// @endcond
    
    /// @brief Reports the index of the first occurrence of the specified character in the spexified string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t index_of(const std::basic_string<Char>& str, Char value, size_t start_index, size_t count) noexcept {
      size_t result = str.find(value, start_index);
      return result > start_index + count ? std::basic_string<Char>::npos : result;
    }
    
    /// @brief Reports the index of the first occurrence of the specified character in the spexified string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param str A String to find index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t index_of(const std::basic_string<Char>& str, const std::basic_string<Char>& value, size_t start_index, size_t count) noexcept {
      size_t result = str.find(value, start_index);
      return result > start_index + count ? std::basic_string<Char>::npos : result;
    }
    
    /// @cond
    template<typename Char>
    static size_t index_of(const Char* str, Char value, size_t start_index, size_t count) noexcept {return index_of(std::basic_string<Char>(str), value, start_index, count);}
    template<typename Char>
    static size_t index_of(const std::basic_string<Char>& str, const Char* value, size_t start_index, size_t count) noexcept {return index_of(str, std::basic_string<Char>(value), start_index, count);}
    template<typename Char>
    static size_t index_of(const Char* str, const std::basic_string<Char>& value, size_t start_index, size_t count) noexcept {return index_of(std::basic_string<Char>(str), value, start_index, count);}
    template<typename Char>
    static size_t index_of(const Char* str, const Char* value, size_t start_index, size_t count) noexcept {return index_of(std::basic_string<Char>(str), std::basic_string<Char>(value), start_index, count);}
    /// @endcond

    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters.
    /// @param str A String to find index of any.
    /// @param values A Unicode character array containing one or more characters to seek
    /// @return size_t The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<Char>::npos if no character in values was found.
    template<typename Char>
    static size_t index_of_any(const std::basic_string<Char>& str, const std::vector<Char>& values) noexcept {return index_of_any(str, values, 0, str.size());}

    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param str A String to find index of any.
    /// @param values A Unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @return size_t The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<Char>::npos if no character in values was found.
    template<typename Char>
    static size_t index_of_any(const std::basic_string<Char>& str, const std::vector<Char>& values, size_t start_index) noexcept {return index_of_any(str, values, start_index, str.size() - start_index);}

    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param str A String to find index of any.
    /// @param values A Unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine.
    /// @return size_t The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<Char>::npos if no character in values was found.
    template<typename Char>
    static size_t index_of_any(const std::basic_string<Char>& str, const std::vector<Char>& values, size_t start_index, size_t count) noexcept {
      size_t index = 0;
      for (const auto& item : str) {
        if (index++ < start_index) continue;
        if (index - 1 > start_index + count) break;
        if (std::find(values.begin(), values.end(), item) != values.end()) return index - 1;
      }
      return std::basic_string<Char>::npos;
    }
    
    /// @cond
    template<typename Char>
    static size_t index_of_any(const std::basic_string<Char>& str, const std::initializer_list<Char>& values) noexcept {return index_of_any(str, std::vector<Char>(values));}
    
    template<typename Char>
    static size_t index_of_any(const std::basic_string<Char>& str, const std::initializer_list<Char>& values, size_t start_index) noexcept {return index_of_any(str, std::vector<Char>(values), start_index);}
    
    template<typename Char>
    static size_t index_of_any(const std::basic_string<Char>& str, const std::initializer_list<Char>& values, size_t start_index, size_t count) noexcept {return index_of_any(str, std::vector<Char>(values), start_index, count);}

    template<typename Char>
    static size_t index_of_any(const Char* str, const std::vector<Char>& values) noexcept {return index_of_any(std::basic_string<Char>(str), values);}
    
    template<typename Char>
    static size_t index_of_any(const Char* str, const std::vector<Char>& values, size_t start_index) noexcept {return index_of_any(std::basic_string<Char>(str), values, start_index);}
    
    template<typename Char>
    static size_t index_of_any(const Char* str, const std::vector<Char>& values, size_t start_index, size_t count) noexcept {return index_of_any(std::basic_string<Char>(str), std::vector<Char>(values), start_index, count);}

    template<typename Char>
    static size_t index_of_any(const Char* str, const std::initializer_list<Char>& values) noexcept {return index_of_any(std::basic_string<Char>(str), std::vector<Char>(values));}
    
    template<typename Char>
    static size_t index_of_any(const Char* str, const std::initializer_list<Char>& values, size_t start_index) noexcept {return index_of_any(std::basic_string<Char>(str), std::vector<Char>(values), start_index);}
    
    template<typename Char>
    static size_t index_of_any(const Char* str, const std::initializer_list<Char>& values, size_t start_index, size_t count) noexcept {return index_of_any(std::basic_string<Char>(str), std::vector<Char>(values), start_index, count);}
    /// @endcond

    /// @brief Inserts a specified instance of String at a specified index position in this instance.
    /// @param start_index The index position of the insertion.
    /// @param value The String to insert.
    /// @return String A new String equivalent to this instance but with value inserted at position start_index.
    /// @remarks If start_index is equal to the length of this instance, value is appended to the end of this instance.
    /// @remarks For example, the return value of "abc".Insert(2, "XYZ") is "abXYZc".
    template<typename Char>
    static std::basic_string<Char> insert(const std::basic_string<Char>& str, size_t start_index, const std::basic_string<Char>& value) noexcept {
      std::basic_string<Char> result(str);
      result.insert(start_index, value);
      return result;
    }
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> insert(const Char* str, size_t start_index, const std::basic_string<Char>& value) noexcept {return insert(std::basic_string<Char>(str), start_index, value);}
    template<typename Char>
    static std::basic_string<Char> insert(const std::basic_string<Char>& str, size_t start_index, Char* value) noexcept {return insert(str, start_index, std::basic_string<Char>(value));}
    template<typename Char>
    static std::basic_string<Char> insert(const Char* str, size_t start_index, const Char* value) noexcept {return insert(std::basic_string<Char>(str), start_index, std::basic_string<Char>(value));}
    /// @endcond

    /// @brief Indicates whether the specified string is an empty string ("").
    /// @param str The string to test.
    /// @return true if the value parameter is null or an empty string (""); otherwise, false.
    template<typename Char>
    static bool is_empty(const std::basic_string<Char>& str) {return str.empty();}

    /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
    /// @param separator A String separator.
    /// @param values An array of Object.
    /// @return A String consisting of the elements of value interspersed with the separator String.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename Char, typename Collection>
    static std::basic_string<Char> join(const std::basic_string<Char>& separator, const Collection& values) noexcept {return join(separator, values, 0, values.size());}
    
    /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
    /// @param separator A String separator.
    /// @param values An array of Object.
    /// @param start_index The first array element in value to use.
    /// @return A String consisting of the elements of value interspersed with the separator String.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename Char, typename Collection>
    static std::basic_string<Char> join(const std::basic_string<Char>& separator, const Collection& values, size_t index) noexcept {return join(separator, values, index, values.size()-index);}
    
    /// @brief Concatenates a specified separator String between each element of a specified Object array, yielding a single concatenated String.
    /// @param separator A String separator.
    /// @param values An array of Object.
    /// @param start_index The first array element in value to use.
    /// @param count The number of elements of value to use.
    /// @return A String consisting of the elements of value interspersed with the separator String.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
   template<typename Char, typename Collection>
    static std::basic_string<Char> join(const std::basic_string<Char>& separator, const Collection& values, size_t index, size_t count) noexcept {
      size_t i = 0;
      std::basic_stringstream<Char> ss;
      for (const auto& item : values) {
        if (i >= index) {
          if (i != index) ss << separator;
          ss << item;
        }
        if (++i >= index + count) break;
      }
      return ss.str();
    }

    /// @cond
    template<typename Char, typename Value>
    static std::basic_string<Char> join(const Char* separator, const std::initializer_list<Value>& values) noexcept {return join(std::basic_string<Char>(separator), values);}
    template<typename Char, typename Value>
    static std::basic_string<Char> join(const Char* separator, const std::initializer_list<Value>& values, size_t index) noexcept {return join(std::basic_string<Char>(separator), values, index);}
    template<typename Char, typename Value>
    static std::basic_string<Char> join(const Char* separator, const std::initializer_list<Value>& values, size_t index, size_t count) noexcept {return join(std::basic_string<Char>(separator), values, index, count);}
    /// @endcond
    
    /// @brief Reports the index of the last occurrence of the specified character in the sêcified tring.
    /// @param str A String to find last index of.
    /// @param value A Unicode character to seek
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t last_index_of(const std::basic_string<Char>& str, Char value) noexcept {return last_index_of(str, value, 0, str.size());}
    
    /// @brief Reports the index of the last occurrence of the specified string in the specified string.
    /// @param str A String to find last index of.
    /// @param value A Unicode character to seek
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t last_index_of(const std::basic_string<Char>& str, const std::basic_string<Char>& value) noexcept {return last_index_of(str, value, 0, str.size());}
    
    /// @cond
    template<typename Char>
    static size_t last_index_of(const Char* str, Char value) noexcept {return last_index_of(std::basic_string<Char>(str), value);}
    template<typename Char>
    static size_t last_index_of(const std::basic_string<Char>& str, const Char* value) noexcept {return last_index_of(str, std::basic_string<Char>(value));}
    template<typename Char>
    static size_t last_index_of(const Char* str, const std::basic_string<Char>& value) noexcept {return last_index_of(std::basic_string<Char>(str), value);}
    template<typename Char>
    static size_t last_index_of(const Char* str, const Char* value) noexcept {return last_index_of(std::basic_string<Char>(str), std::basic_string<Char>(value));}
    /// @endcond
    
    /// @brief Reports the index of the last occurrence of the specified character in the spexified string. The search starts at a specified character position.
    /// @param str A String to find last index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t last_index_of(const std::basic_string<Char>& str, Char value, size_t start_index) noexcept {return last_index_of(str, value, start_index, str.size() - start_index);}
    
    /// @brief Reports the index of the last occurrence of the specified character in the spexified string. The search starts at a specified character position.
    /// @param str A String to find last index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t last_index_of(const std::basic_string<Char>& str, const std::basic_string<Char>& value, size_t start_index) noexcept {return last_index_of(str, value, start_index, str.size() - start_index);}
    
    /// @cond
    template<typename Char>
    static size_t last_index_of(const Char* str, Char value, size_t start_index) noexcept {return last_index_of(std::basic_string<Char>(str), value, start_index);}
    template<typename Char>
    static size_t last_index_of(const std::basic_string<Char>& str, const Char* value, size_t start_index) noexcept {return last_index_of(str, std::basic_string<Char>(value), start_index);}
    template<typename Char>
    static size_t last_index_of(const Char* str, const std::basic_string<Char>& value, size_t start_index) noexcept {return last_index_of(std::basic_string<Char>(str), value, start_index);}
    template<typename Char>
    static size_t last_index_of(const Char* str, const Char* value, size_t start_index) noexcept {return last_index_of(std::basic_string<Char>(str), std::basic_string<Char>(value), start_index);}
    /// @endcond
    
    /// @brief Reports the index of the last occurrence of the specified character in the spexified string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param str A String to find last index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t last_index_of(const std::basic_string<Char>& str, Char value, size_t start_index, size_t count) noexcept {
      size_t result = str.rfind(value, start_index + count - 1);
      return result < start_index ? std::basic_string<Char>::npos : result;
    }
    
    /// @brief Reports the index of the last occurrence of the specified character in the spexified string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param str A String to find last index of.
    /// @param value A Unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return size_t The index position of value if that character is found, or std::basic_string<Char>::npos if it is not.
    template<typename Char>
    static size_t last_index_of(const std::basic_string<Char>& str, const std::basic_string<Char>& value, size_t start_index, size_t count) noexcept {
      size_t result = str.rfind(value, start_index + count - value.size());
      return result < start_index ? std::basic_string<Char>::npos : result;
    }
    
    /// @cond
    template<typename Char>
    static size_t last_index_of(const Char* str, Char value, size_t start_index, size_t count) noexcept {return last_index_of(std::basic_string<Char>(str), value, start_index, count);}
    template<typename Char>
    static size_t last_index_of(const std::basic_string<Char>& str, const Char* value, size_t start_index, size_t count) noexcept {return last_index_of(str, std::basic_string<Char>(value), start_index, count);}
    template<typename Char>
    static size_t last_index_of(const Char* str, const std::basic_string<Char>& value, size_t start_index, size_t count) noexcept {return last_index_of(std::basic_string<Char>(str), value, start_index, count);}
    template<typename Char>
    static size_t last_index_of(const Char* str, const Char* value, size_t start_index, size_t count) noexcept {return last_index_of(std::basic_string<Char>(str), std::basic_string<Char>(value), start_index, count);}
    /// @endcond

    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters.
    /// @param str A String to find last index of any.
    /// @param values A Unicode character array containing one or more characters to seek
    /// @return size_t The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<Char>::npos if no character in values was found.
    template<typename Char>
    static size_t last_index_of_any(const std::basic_string<Char>& str, const std::vector<Char>& values) noexcept {return last_index_of_any(str, values, 0, str.size());}
    
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param str A String to find index of any.
    /// @param values A Unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @return size_t The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<Char>::npos if no character in values was found.
    template<typename Char>
    static size_t last_index_of_any(const std::basic_string<Char>& str, const std::vector<Char>& values, size_t start_index) noexcept {return last_index_of_any(str, values, start_index, str.size() - start_index);}
    
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param str A String to find last index of any.
    /// @param values A Unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine.
    /// @return size_t The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<Char>::npos if no character in values was found.
    template<typename Char>
    static size_t last_index_of_any(const std::basic_string<Char>& str, const std::vector<Char>& values, size_t start_index, size_t count) noexcept {
      size_t index = str.size() - 1;
      for (typename std::basic_string<Char>::const_reverse_iterator it = str.crbegin(); it != str.crend(); ++it) {
        if (index-- > start_index + count) continue;
        if (index + 1 < start_index) break;
        if (std::find(values.begin(), values.end(), *it) != values.end()) return index + 1;
      }
      return std::basic_string<Char>::npos;
    }
    
    /// @cond
    template<typename Char>
    static size_t last_index_of_any(const std::basic_string<Char>& str, const std::initializer_list<Char>& values) noexcept {return last_index_of_any(str, std::vector<Char>(values));}
    
    template<typename Char>
    static size_t last_index_of_any(const std::basic_string<Char>& str, const std::initializer_list<Char>& values, size_t start_index) noexcept {return last_index_of_any(str, std::vector<Char>(values), start_index);}
    
    template<typename Char>
    static size_t last_index_of_any(const std::basic_string<Char>& str, const std::initializer_list<Char>& values, size_t start_index, size_t count) noexcept {return last_index_of_any(str, std::vector<Char>(values), start_index, count);}
    
    template<typename Char>
    static size_t last_index_of_any(const Char* str, const std::vector<Char>& values) noexcept {return last_index_of_any(std::basic_string<Char>(str), values);}
    
    template<typename Char>
    static size_t last_index_of_any(const Char* str, const std::vector<Char>& values, size_t start_index) noexcept {return last_index_of_any(std::basic_string<Char>(str), values, start_index);}
    
    template<typename Char>
    static size_t last_index_of_any(const Char* str, const std::vector<Char>& values, size_t start_index, size_t count) noexcept {return last_index_of_any(std::basic_string<Char>(str), std::vector<Char>(values), start_index, count);}
    
    template<typename Char>
    static size_t last_index_of_any(const Char* str, const std::initializer_list<Char>& values) noexcept {return last_index_of_any(std::basic_string<Char>(str), std::vector<Char>(values));}
    
    template<typename Char>
    static size_t last_index_of_any(const Char* str, const std::initializer_list<Char>& values, size_t start_index) noexcept {return last_index_of_any(std::basic_string<Char>(str), std::vector<Char>(values), start_index);}
    
    template<typename Char>
    static size_t last_index_of_any(const Char* str, const std::initializer_list<Char>& values, size_t start_index, size_t count) noexcept {return last_index_of_any(std::basic_string<Char>(str), std::vector<Char>(values), start_index, count);}
    /// @endcond

    /// @brief Right-aligns the characters iin the specified string, padding with spaces on the left for a specified total length.
    /// @param str String to pad left.
    /// @param total_width The number of characters in the resulting String, equal to the number of original characters plus any additional padding characters.
    /// @return String A new String that is equivalent to the specified string, but right-aligned and padded on the left with as many spaces as needed to create a length of total_width. Or, if total_width is less than the length of the specified string, a new String object that is identical to the specified string.
    /// @remarks A Unicode space is defined as hexadecimal 0x20.
    /// @remarks The pad_left(const std::basic_string<Char>&, int) method pads the beginning of the returned String. This means that, when used with right-to-left languages, it pads the right portion of the String..
    template<typename Char>
    static std::basic_string<Char> pad_left(const std::basic_string<Char>& str, size_t total_width) noexcept {return pad_left(str, total_width, static_cast<Char>(0x20));}
    
    /// @brief Right-aligns the characters in the specified string, padding with spaces on the left for a specified total length.
    /// @param str String to pad left.
    /// @param total_width The number of characters in the resulting String, equal to the number of original characters plus any additional padding characters.
    /// @param paddingChar A Unicode padding character.
    /// @return String A new String that is equivalent to the specified string, but right-aligned and padded on the left with as many spaces as needed to create a length of total_width. Or, if total_width is less than the length of the specified string, a new String object that is identical the specified string.
    /// @remarks A Unicode space is defined as hexadecimal 0x20.
    /// @remarks The pad_left(const std::basic_string<Char>&, int) method pads the beginning of the returned String. This means that, when used with right-to-left languages, it pads the right portion of the String..
    template<typename Char>
    static std::basic_string<Char> pad_left(const std::basic_string<Char>& str, size_t total_width, Char padding_char) noexcept {
      if (total_width < str.size()) return str;
      return std::basic_string<Char>(total_width - str.size(), padding_char).append(str);
    }
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> pad_left(const Char* str, size_t total_width) noexcept {return pad_left(std::basic_string<Char>(str), total_width, static_cast<Char>(0x20));}
    
    template<typename Char>
    static std::basic_string<Char> pad_left(const Char* str, size_t total_width, Char padding_char) noexcept {return pad_left(std::basic_string<Char>(str), total_width, padding_char);}
    /// @endcond
    
    /// @brief Left-aligns the characters in the specified string, padding with spaces on the right for a specified total length.
    /// @param str String to pad right.
    /// @param totalWidth The number of characters in the resulting String, equal to the number of original characters plus any additional padding characters.
    /// @return String A new String that is equivalent to the specified string, but left-aligned and padded on the right with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of the specified string, a new String object that is identical to the specified string.
    /// @remarks A Unicode space is defined as hexadecimal 0x20.
    /// @remarks The PadRight(const std::basic_string<Char>&, int) method pads the end of the returned String. This means that, when used with right-to-left languages, it pads the left portion of the String..
    template<typename Char>
    static std::basic_string<Char> pad_right(const std::basic_string<Char>& str, size_t total_width) noexcept {return pad_right(str, total_width, static_cast<Char>(0x20));}
    
    /// @brief Left-aligns the characters in the specified string, padding with spaces on the right for a specified total length.
    /// @param str String to pad right.
    /// @param totalWidth The number of characters in the resulting String, equal to the number of original characters plus any additional padding characters.
    /// @param paddingChar A Unicode padding character.
    /// @return String A new String that is equivalent to the specified string, but left-aligned and padded on the tight with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of the specified string, a new String object that is identical to the specified string.
    /// @remarks A Unicode space is defined as hexadecimal 0x20.
    /// @remarks The PadRight(const std::basic_string<Char>&, int) method pads the end of the returned String. This means that, when used with right-to-left languages, it pads the left portion of the String..
    template<typename Char>
    static std::basic_string<Char> pad_right(const std::basic_string<Char>& str, size_t total_width, Char padding_char) noexcept {
      if (total_width < str.size()) return str;
      return std::basic_string<Char>(str).append(total_width - str.size(), padding_char);
    }
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> pad_right(const Char* str, size_t total_width) noexcept {return pad_right(std::basic_string<Char>(str), total_width, static_cast<Char>(0x20));}
    
    template<typename Char>
    static std::basic_string<Char> pad_right(const Char* str, size_t total_width, Char padding_char) noexcept {return pad_right(std::basic_string<Char>(str), total_width, padding_char);}
    /// @endcond
    
    /// @brief Deletes all the characters from this String beginning at a specified position and continuing through the last position.
    /// @param start_index The position to begin deleting characters.
    /// @return String A A new String object that is equivalent to this String less the removed characters.
    template<typename Char>
    static std::basic_string<Char> remove(const std::basic_string<Char>& str, size_t start_index) noexcept {return remove(str, start_index, str.size() - start_index);}
    
    /// @brief Deletes all the characters from this String beginning at a specified position and continuing through the last position.
    /// @param start_index The position to begin deleting characters.
    /// @param count The number of characters to delete.
    /// @return String A A new String object that is equivalent to this String less the removed characters.
    template<typename Char>
    static std::basic_string<Char> remove(const std::basic_string<Char>& str, size_t start_index, size_t count) noexcept {
      if (start_index > str.size()) return str;
      std::basic_string<Char> result(str);
      return result.erase(start_index, count);}
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> remove(const Char* str, size_t start_index) noexcept {return remove(std::basic_string<Char>(str), start_index);}
    template<typename Char>
    static std::basic_string<Char> remove(const Char* str, size_t start_index, size_t count) noexcept {return remove(std::basic_string<Char>(str), start_index, count);}
    /// @endcond
    
    /// @brief Replaces all occurrences of a specified Char in the specified string with another specified Char.
    /// @param str String containing string to replace.
    /// @param old_char A Char to be replaced.
    /// @param new_char A Char to replace all occurrences of old_char.
    /// @return String A A new String equivalent to the specified string but with all instances of old_char replaced with new_char.
    template<typename Char>
    static std::basic_string<Char> replace(const std::basic_string<Char>& str, Char old_char, Char new_char) noexcept {return replace(str, std::basic_string<Char>(1, old_char), std::basic_string<Char>(1, new_char));}
    
    /// @brief Replaces all occurrences of a specified String in the specified string with another specified String.
    /// @param str String containing string to replace.
    /// @param old_string A String to be replaced.
    /// @param new_string A String to replace all occurrences of old_string.
    /// @return String A A new String equivalent to the specified string but with all instances of old_string replaced with new_string.
    /// @remarks If new_string is empty, all occurrences of old_string are removed
    template<typename Char>
    static std::basic_string<Char> replace(const std::basic_string<Char>& str, const std::basic_string<Char>& old_string, const std::basic_string<Char>& new_string) noexcept {
      std::basic_string<Char> result(str);
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
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> replace(const Char* str, Char old_char, Char new_char) noexcept {return replace(std::basic_string<Char>(str), old_char, new_char);}
    template<typename Char>
    static std::basic_string<Char> replace(const Char* str, const Char* old_string, const Char* new_string) noexcept {return replace(std::basic_string<Char>(str), std::basic_string<Char>(old_string), std::basic_string<Char>(new_string));}
    template<typename Char>
    static std::basic_string<Char> replace(const std::basic_string<Char>& str, const Char* old_string, const Char* new_string) noexcept {return replace(str, std::basic_string<Char>(old_string), std::basic_string<Char>(new_string));}
    template<typename Char>
    static std::basic_string<Char> replace(const Char* str, std::basic_string<Char>& old_string, const Char* new_string) noexcept {return replace(std::basic_string<Char>(str), old_string, std::basic_string<Char>(new_string));}
    template<typename Char>
    static std::basic_string<Char> replace(const Char* str, const Char* old_string, const std::basic_string<Char>& new_string) noexcept {return replace(std::basic_string<Char>(str), std::basic_string<Char>(old_string), new_string);}
    template<typename Char>
    static std::basic_string<Char> replace(const std::basic_string<Char>& str, const std::basic_string<Char>& old_string, const Char* new_string) noexcept {return replace(str, old_string, std::basic_string<Char>(new_string));}
    template<typename Char>
    static std::basic_string<Char> replace(const std::basic_string<Char>& str, const Char* old_string, const std::basic_string<Char>& new_string) noexcept {return replace(str, std::basic_string<Char>(old_string), new_string);}
    template<typename Char>
    static std::basic_string<Char> replace(const Char* str, const std::basic_string<Char>& old_string, const std::basic_string<Char>& new_string) noexcept {return replace(std::basic_string<Char>(str), old_string, new_string);}
    /// @endcond

    /// @brief Splits a specified string into a maximum number of substrings based on the characters in an array.
    /// @param str string to split.
    /// @param separators A character array that delimits the substrings in this string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @param options xtd::string_split_options::remove_empty_entries to omit empty array elements from the array returned; or None to include empty array elements in the array returned.
    /// @return An array whose elements contain the substrings in this string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified string.
    /// @remarks If the count parameter is zero, or the options parameter is remove_empty_entries and the length of the specified string is zero, an empty array is returned.
    /// @remarks Each element of separator defines a separate delimiter character. If the options parameter is None, and two delimiters are adjacent or a delimiter is found at the beginning or end of the specified string, the corresponding array element contains an empty string.
    /// @remarks If there are more than count substrings in the specified string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified string are returned in the last element of the return value.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
   template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str, const std::vector<Char>& separators, size_t count, string_split_options options) noexcept {
      if (count == 0) return {};
      if (count == 1) return {str};
      
      std::vector<std::basic_string<Char>> list;
      std::basic_string<Char> subString;
      std::vector<Char> split_char_separators = separators.size() == 0 ? std::vector<Char> {9, 10, 11, 12, 13, 32} : separators;
      for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        bool is_separator =  std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
        if (!is_separator) subString.append(std::string(1, *it));
        if ((it - str.begin() == str.length() - 1 || is_separator) && (subString.length() > 0 || (subString.length() == 0 && options != string_split_options::remove_empty_entries))) {
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

    /// @brief Splits a specified string into substrings that are based on the default white-space characters. White-space characters are defined by the c++ standard and return true if they are passed to the std::isspace() or std::iswspace() method.
    /// @param str string to split.
    /// @return An array whose elements contain the substrings in this string that are delimited by one or more characters in white-space separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified string.
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str) noexcept {return split(str, std::vector<Char> {9, 10, 11, 12, 13, 32}, std::numeric_limits<size_t>::max(), string_split_options::none);}
    
    /// @brief Splits a specified string into substrings that are based on the characters in an array.
    /// @param str string to split.
    /// @param separators A character array that delimits the substrings in this string, an empty array that contains no delimiters.
    /// @return An array whose elements contain the substrings in this string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified string.
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str, const std::vector<Char>& separators) noexcept {return split(str, separators, std::numeric_limits<size_t>::max(), string_split_options::none);}
    
    /// @brief Splits a specified string into substrings based on the characters in an array. You can specify whether the substrings include empty array elements.
    /// @param str string to split.
    /// @param separators A character array that delimits the substrings in this string, an empty array that contains no delimiters.
    /// @param options xtd::string_split_options::remove_empty_entries to omit empty array elements from the array returned; or None to include empty array elements in the array returned.
    /// @return An array whose elements contain the substrings in this string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified string.
    /// @remarks If the specified string does not contain any of the characters in separator, the returned array consists of a single element that contains the specified string.
    /// @remarks If the options parameter is remove_empty_entries and the length of the specified string is zero, the method returns an empty array.
    /// @remarks Each element of separator defines a separate delimiter that consists of a single character. If the options argument is none, and two delimiters are adjacent or a delimiter is found at the beginning or end of the specified string, the corresponding array element contains empty string. For example, if separator includes two elements, "-" and "_", the value of the string instance is "-_aa-_", and the value of the options argument is None, the method returns a string array with the following five elements:
    ///   1. empty string, which represents the empty string that precedes the "-" character at index 0.
    ///   2. empty string, which represents the empty string between the "-" character at index 0 and the "_" character at index 1.
    ///   3. "aa",
    ///   4. empty string, which represents the empty string that follows the "_" character at index 4.
    ///   5. empty string, which represents the empty string that follows the "-" character at index 5.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the c++ standard and return true if they are passed to the std::isspace() or std::iswspace() method.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str, const std::vector<Char>& separators, string_split_options options) noexcept {return split(str, separators, std::numeric_limits<size_t>::max(), options);}
    
    /// Splits a specified string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
    /// @param str string to split.
    /// @param separators A character array that delimits the substrings in this string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified string.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the Unicode standard and return true if they are passed to the Char.IsWhiteSpace method.
    /// @remarks Each element of separator defines a separate delimiter character. If two delimiters are adjacent, or a delimiter is found at the beginning or end of the specified string, the corresponding array element contains empty string.
    /// @remarks If there are more than count substrings in the specified string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified string are returned in the last element of the return value.
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str, const std::vector<Char>& separators, size_t count) noexcept {return split(str, separators, count, string_split_options::none);}

    /// @cond
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str, const std::vector<Char>& separators, size_t count, string_split_options options) noexcept {return split(std::basic_string<Char>(str), separators, count, options);}
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str) noexcept {return split(str, std::vector<Char> {9, 10, 11, 12, 13, 32}, std::numeric_limits<size_t>::max(), string_split_options::none);}
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str, const std::vector<Char>& separators) noexcept {return split(str, separators, std::numeric_limits<size_t>::max(), string_split_options::none);}
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str, const std::vector<Char>& separators, string_split_options options) noexcept {return split(str, separators, std::numeric_limits<size_t>::max(), options);}
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str, const std::vector<Char>& separators, size_t count) noexcept {return split(str, separators, count, string_split_options::none);}
    /// @endcond

    /// @brief Determines whether the beginning of an instance of String matches a specified String.
    /// @param str string beginning with value.
    /// @param value A String to compare to.
    /// @return bool true if value matches the beginning of the specified string; otherwise, false.
    /// @remarks This method compares value to the substring at the beginning of the specified string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified string.
    template<typename Char>
    static bool starts_with(const std::basic_string<Char>& str, Char value) noexcept {return starts_with(str, value, false);}
    
    /// @brief Determines whether the beginning of an instance of String matches a specified String, ignoring or honoring their case.
    /// @param str string beginning with value.
    /// @param value A String to compare to.
    /// @param ignore_case true to ignore case when comparing the specified string and value; otherwise, false
    /// @return bool true if value matches the beginning of the specified string; otherwise, false.
    /// @remarks This method compares value to the substring at the beginning of the specified string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified string.
    template<typename Char>
    static bool starts_with(const std::basic_string<Char>& str, Char value, bool ignore_case) noexcept {
      if (ignore_case)
        return to_lower(str).find(tolower(value)) == 0;
      return str.find(value) == 0;
    }

    /// @brief Determines whether the beginning of an instance of String matches a specified String.
    /// @param str string beginning with value.
    /// @param value A String to compare to.
    /// @return bool true if value matches the beginning of the specified string; otherwise, false.
    /// @remarks This method compares value to the substring at the beginning of the specified string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified string.
    template<typename Char>
    static bool starts_with(const std::basic_string<Char>& str, const std::basic_string<Char>& value) noexcept {return starts_with(str, value, false);}
    
    /// @brief Determines whether the beginning of an instance of String matches a specified String, ignoring or honoring their case.
    /// @param str string beginning with value.
    /// @param value A String to compare to.
    /// @param ignore_case true to ignore case when comparing the specified string and value; otherwise, false
    /// @return bool true if value matches the beginning of the specified string; otherwise, false.
    /// @remarks This method compares value to the substring at the beginning of the specified string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified string.
    template<typename Char>
    static bool starts_with(const std::basic_string<Char>& str, const std::basic_string<Char>& value, bool ignore_case) noexcept {
      if (ignore_case)
        return to_lower(str).find(to_lower(value)) == 0;
      return str.find(value) == 0;
    }

    /// @cond
    template<typename Char>
    static bool starts_with(const Char* str, Char value) noexcept {return starts_with(std::basic_string<Char>(str), value, false);}
    template<typename Char>
    static bool starts_with(const Char* str, Char value, bool ignore_case) noexcept {return starts_with(std::basic_string<Char>(str), value, ignore_case);}
    template<typename Char>
    static bool starts_with(const std::basic_string<Char>& str, const Char* value) noexcept {return starts_with(str, std::basic_string<Char>(value), false);}
    template<typename Char>
    static bool starts_with(const Char* str, const std::basic_string<Char>& value) noexcept {return starts_with(std::basic_string<Char>(str), value, false);}
    template<typename Char>
    static bool starts_with(const Char* str, const Char* value) noexcept {return starts_with(std::basic_string<Char>(str), std::basic_string<Char>(value), false);}

    template<typename Char>
    static bool starts_with(const std::basic_string<Char>& str, const Char* value, bool ignore_case) noexcept {return starts_with(str, std::basic_string<Char>(value), ignore_case);}
    template<typename Char>
    static bool starts_with(const Char* str, const std::basic_string<Char>& value, bool ignore_case) noexcept {return starts_with(std::basic_string<Char>(str), value, ignore_case);}
    template<typename Char>
    static bool starts_with(const Char* str, const Char* value, bool ignore_case) noexcept {return starts_with(std::basic_string<Char>(str), std::basic_string<Char>(value), ignore_case);}
    /// @endcond
    
    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param str string to substring.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @return String A String equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    template<typename Char>
    static std::basic_string<Char> substring(const std::basic_string<Char>& str, size_t start_index) noexcept {
      if (start_index >= str.size()) return "";
      return str.substr(start_index);
    }
    
    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param str string to substring.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @param length The number of characters in the substring.
    /// @return String A String equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    template<typename Char>
    static std::basic_string<Char> substring(const std::basic_string<Char>& str, size_t start_index, size_t length) noexcept {
      if (start_index >= str.size()) return "";
      return str.substr(start_index, length);
    }
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> substring(const Char* str, size_t start_index) noexcept {return substring(std::basic_string<Char>(str), start_index);}
    template<typename Char>
    static std::basic_string<Char> substring(const Char* str, size_t start_index, size_t length) noexcept {return substring(std::basic_string<Char>(str), start_index, length);}
    /// @endcond
    
    /// @brief Copies the characters in this instance to a Unicode character array.
    /// @param str string to convert to array.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty String, the returned array is empty and has a zero length.
    template<typename Char>
    static const std::vector<Char> to_array(const std::basic_string<Char>& str) noexcept {return to_array(str, 0, str.size());}
    
    /// @brief Copies the characters in this instance to a Unicode character array starting at specitied index.
    /// @param str string to convert to array.
    /// @param start_index The starting position of string to convert.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty String, the returned array is empty and has a zero length.
    template<typename Char>
    static const std::vector<Char> to_array(const std::basic_string<Char>& str, size_t start_index) noexcept {return to_array(str, start_index, str.size() - start_index);}
    
    /// @brief Copies the characters in this instance to a Unicode character array starting at specitied index with specified legnth.
    /// @param str string to convert to array.
    /// @param start_index The starting position of string to convert.
    /// @param length The length of the string to convert
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty String, the returned array is empty and has a zero length.
    template<typename Char>
    static const std::vector<Char> to_array(const std::basic_string<Char>& str, size_t start_index, size_t length) noexcept {
      if (start_index >= str.size()) return {};
      if (start_index + length >= str.size()) return {str.begin() + start_index, str.end()};
      return {str.begin() + start_index, str.begin() + start_index + length};
    }
    
    /// @cond
    template<typename Char>
    static const std::vector<Char> to_array(const Char* str) noexcept {return to_array(std::basic_string<Char>(str));}
    template<typename Char>
    static const std::vector<Char> to_array(const Char* str, size_t start_index) noexcept {return to_array(std::basic_string<Char>(str), start_index);}
    template<typename Char>
    static const std::vector<Char> to_array(const Char* str, size_t start_index, size_t length) noexcept {return to_array(std::basic_string<Char>(str), start_index, length);}
    /// @endcond


    /// @brief Returns a copy of the specified string converted to lowercase.
    /// @param str string to convert to lower.
    /// @return String A new String in lowercase.
    template<typename Char>
    static const std::basic_string<Char> to_lower(const std::basic_string<Char>& str) noexcept {
      std::basic_string<Char> result;
      std::locale lc = std::locale();
      for(char c : str) result.push_back(std::tolower(c, lc));
      return result;
    }
    
    /// @cond
    static const std::basic_string<char16_t> to_lower(const std::basic_string<char16_t>& str) noexcept {
      std::basic_string<char16_t> result;
      std::locale lc = std::locale();
      //for(char16_t c : str) result.push_back(std::tolower(c, lc));
      for(char16_t c : str) result.push_back(c <= 0xFF ? static_cast<char16_t>(std::tolower(static_cast<char>(c), lc)) : c);
      return result;
    }
    
    static const std::basic_string<char32_t> to_lower(const std::basic_string<char32_t>& str) noexcept {
      std::basic_string<char32_t> result;
      std::locale lc = std::locale();
      //for(char c : str) result.push_back(std::tolower(c, lc));
      for(char32_t c : str) result.push_back(c <= 0xFF ? static_cast<char32_t>(std::tolower(static_cast<char>(c), lc)) : c);
      return result;
    }
    
    template<typename Char>
    static const std::basic_string<Char> to_lower(const Char* str) noexcept {return to_lower(std::basic_string<Char>(str));}
    /// @endcond
    
    /// @brief Returns a copy of the specified string converted to uppercase.
    /// @param str string to convert to upper.
  /// @return String A new String in uppercase.
    template<typename Char>
    static const std::basic_string<Char> to_upper(const std::basic_string<Char>& str) noexcept {
      std::basic_string<Char> result;
      std::locale lc = std::locale();
      for(char c : str) result.push_back(std::toupper(c, lc));
      return result;
    }
    
    /// @cond
    static const std::basic_string<char16_t> to_upper(const std::basic_string<char16_t>& str) noexcept {
      std::basic_string<char16_t> result;
      std::locale lc = std::locale();
      //for(char16_t c : str) result.push_back(std::toupper(c, lc));
      for(char16_t c : str) result.push_back(c <= 0xFF ? static_cast<char16_t>(std::toupper(static_cast<char>(c), lc)) : c);
      return result;
    }
    
    static const std::basic_string<char32_t> to_upper(const std::basic_string<char32_t>& str) noexcept {
      std::basic_string<char32_t> result;
      std::locale lc = std::locale();
      //for(char c : str) result.push_back(std::toupper(c, lc));
      for(char32_t c : str) result.push_back(c <= 0xFF ? static_cast<char32_t>(std::toupper(static_cast<char>(c), lc)) : c);
      return result;
    }
    
    template<typename Char>
    static const std::basic_string<Char> to_upper(const Char* str) noexcept {return to_upper(std::basic_string<Char>(str));}
    /// @endcond
    
    /// @brief Removes all leading and trailing occurrences of white-space characters from the specifed String.
    /// @param str String to trim end.
    /// @param trim_char A character to remove.
    /// @return The String that remains after all occurrences of the character in the trim_char parameter are removed from the start and te and of the specified String.
    template<typename Char>
    static std::basic_string<Char> trim(const std::basic_string<Char>& str) noexcept {return trim(str, static_cast<Char>(0x20));}
    
    /// @brief Removes all eading and trailing occurrences of a character specified from the specifed String .
    /// @param str String to trim start.
    /// @param trim_char A character to remove.
    /// @return The String that remains after all occurrences of the character in the trim_char parameter are removed from the start and the end of the specofoed String.
    template<typename Char>
    static std::basic_string<Char> trim(const std::basic_string<Char>& str, Char trim_char) noexcept {return trim(str, std::vector<Char> {trim_char});}
    
    /// @brief Removes all eading and trailing occurrences of a set of characters specified in an array from the specified String.
    /// @param str String to trim end.
    /// @param trim_chars An array of characters to remove.
    /// @return The String that remains after all occurrences of the characters in the trim_chars parameter are removed from the start and the edn of the specified String.
    template<typename Char>
    static std::basic_string<Char> trim(const std::basic_string<Char>& str, const std::vector<Char>& trim_chars) noexcept {return trim_end(trim_start(str, trim_chars), trim_chars);}
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> trim(const Char* str) noexcept {return trim(std::basic_string<Char>(str), static_cast<Char>(0x20));}
    
    template<typename Char>
    static std::basic_string<Char> trim(const Char* str, Char trim_char) noexcept {return trim(std::basic_string<Char>(str), std::vector<Char> {trim_char});}
    
    template<typename Char>
    static std::basic_string<Char> trim(const Char* str, const std::vector<Char>& trim_chars) noexcept {return trim(std::basic_string<Char>(str), trim_chars);}
    /// @endcond

    /// @brief Removes all trailing occurrences of white-space characters from the specifed String.
    /// @param str String to trim end.
    /// @param trim_char A character to remove.
    /// @return The String that remains after all occurrences of the character in the trim_char parameter are removed from the end of the specified String.
    template<typename Char>
    static std::basic_string<Char> trim_end(const std::basic_string<Char>& str) noexcept {return trim_end(str, static_cast<Char>(0x20));}
    
    /// @brief Removes all trailing occurrences of a character specified from the specifed String .
    /// @param str String to trim start.
    /// @param trim_char A character to remove.
    /// @return The String that remains after all occurrences of the character in the trim_char parameter are removed from the end of the specofoed String.
    template<typename Char>
    static std::basic_string<Char> trim_end(const std::basic_string<Char>& str, Char trim_char) noexcept {return trim_end(str, std::vector<Char> {trim_char});}
    
    /// @brief Removes all trailing occurrences of a set of characters specified in an array from the specified String.
    /// @param str String to trim end.
    /// @param trim_chars An array of characters to remove.
    /// @return The String that remains after all occurrences of the characters in the trim_chars parameter are removed from the end of the specified String.
    template<typename Char>
    static std::basic_string<Char> trim_end(const std::basic_string<Char>& str, const std::vector<Char>& trim_chars) noexcept {
      std::basic_string<Char> result(str);
      while (std::find(trim_chars.begin(), trim_chars.end(), result[result.size() - 1]) != trim_chars.end())
        result.erase(result.size() - 1, 1);
      return result;
    }
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> trim_end(const Char* str) noexcept {return trim_end(std::basic_string<Char>(str), static_cast<Char>(0x20));}
    
    template<typename Char>
    static std::basic_string<Char> trim_end(const Char* str, Char trim_char) noexcept {return trim_end(std::basic_string<Char>(str), std::vector<Char> {trim_char});}
    
    template<typename Char>
    static std::basic_string<Char> trim_end(const Char* str, const std::vector<Char>& trim_chars) noexcept {return trim_end(std::basic_string<Char>(str), trim_chars);}
    /// @endcond
    
    /// @brief Removes all leading occurrences of white-space characters from the specifed String.
    /// @param str String to trim start.
    /// @param trim_char A character to remove.
    /// @return The String that remains after all occurrences of the character in the trim_char parameter are removed from the start of the specified String.
    template<typename Char>
    static std::basic_string<Char> trim_start(const std::basic_string<Char>& str) noexcept {return trim_start(str, static_cast<Char>(0x20));}
    
    /// @brief Removes all leading occurrences of a character specified from the specifed String .
    /// @param str String to trim start.
    /// @param trim_char A character to remove.
    /// @return The String that remains after all occurrences of the character in the trim_char parameter are removed from the start of the specofoed String.
    template<typename Char>
    static std::basic_string<Char> trim_start(const std::basic_string<Char>& str, Char trim_char) noexcept {return trim_start(str, std::vector<Char> {trim_char});}
    
    /// @brief Removes all leading occurrences of a set of characters specified in an array from the specified String.
    /// @param str String to trim start.
    /// @param trim_chars An array of characters to remove.
    /// @return The String that remains after all occurrences of the characters in the trim_chars parameter are removed from the start of the specified String.
    template<typename Char>
    static std::basic_string<Char> trim_start(const std::basic_string<Char>& str, const std::vector<Char>& trim_chars) noexcept {
      std::basic_string<Char> result(str);
      while (std::find(trim_chars.begin(), trim_chars.end(), result[0]) != trim_chars.end())
        result.erase(0, 1);
      return result;
    }
    
    /// @cond
    template<typename Char>
    static std::basic_string<Char> trim_start(const Char* str) noexcept {return trim_start(std::basic_string<Char>(str), static_cast<Char>(0x20));}
    
    template<typename Char>
    static std::basic_string<Char> trim_start(const Char* str, Char trim_char) noexcept {return trim_start(std::basic_string<Char>(str), std::vector<Char> {trim_char});}
    
    template<typename Char>
    static std::basic_string<Char> trim_start(const Char* str, const std::vector<Char>& trim_chars) noexcept {return trim_start(std::basic_string<Char>(str), trim_chars);}
    /// @endcond

  private:
    template<typename Arg>
    static auto convert_param(Arg&& arg) noexcept {
      if constexpr (std::is_same<std::remove_cv_t<std::remove_reference_t<Arg>>, std::string>::value) return std::forward<Arg>(arg).c_str();
      else if constexpr (std::is_same<std::remove_cv_t<std::remove_reference_t<Arg>>, xtd::istring>::value) return std::forward<Arg>(arg).c_str();
      else if constexpr (std::is_same<std::remove_cv_t<std::remove_reference_t<Arg>>, std::wstring>::value) return std::forward<Arg>(arg).c_str();
      else if constexpr (std::is_same<std::remove_cv_t<std::remove_reference_t<Arg>>, xtd::iwstring>::value) return std::forward<Arg>(arg).c_str();
      else return std::forward<Arg>(arg);
    }
  };
}

#include "to_string.hpp"

template<typename Char>
std::basic_string<Char> __extract_format_information(const std::basic_string<Char>& fmt, size_t index, size_t& pos, size_t& length) {
  std::basic_string<Char> result;
  std::basic_string<Char> starting_format;
  
  starting_format = index != std::basic_string<Char>::npos ? "{" + std::to_string(index) : "{";
  pos = fmt.find(starting_format, pos);
  size_t close_bace_pos = fmt.find("}", pos);
  length = close_bace_pos - pos + 1;
  return fmt.substr(pos + starting_format.length(), length - starting_format.length() - 1);
}

template<typename Char, typename Arg>
void __extract_format_arg(std::basic_string<Char>& fmt, size_t& index, std::vector<__format_information<Char>>& formats, Arg&& arg) {
  size_t offset = 0;
  for (auto& format : formats) {
    format.location += offset;
    if (format.index == index) {
      std::basic_string<Char> arg_str = format.format.empty() ? xtd::to_string(arg) : xtd::to_string(arg, format.format);
      fmt.insert(format.location, arg_str);
      offset += arg_str.size();
    }
  }
  ++index;
}

template<typename Char, typename ...Args>
void __extract_format_arg(std::basic_string<Char>& fmt, std::vector<__format_information<Char>>& formats, Args&&... args) {
  size_t index = 0;
  (__extract_format_arg(fmt, index, formats, args),...);
}
