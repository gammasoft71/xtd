/// @file
/// @brief Contains std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const Type& value) function.
#pragma once
#include <array>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#if !__APPLE__ || __MAC_OS_X_VERSION_MAX_ALLOWED >= 101401
#include <optional>
#endif
#include <set>
#include <stdexcept>
#include <string>
#include <sstream>
#include <type_traits>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

/// @cond
template<class T> struct __tunit_is_printable : std::false_type {};
template<> struct __tunit_is_printable<bool> : std::true_type {};
template<> struct __tunit_is_printable<char> : std::true_type {};
template<> struct __tunit_is_printable<signed char> : std::true_type {};
template<> struct __tunit_is_printable<unsigned char> : std::true_type {};
template<> struct __tunit_is_printable<wchar_t> : std::true_type {};
template<> struct __tunit_is_printable<char16_t> : std::true_type {};
template<> struct __tunit_is_printable<char32_t> : std::true_type {};
template<> struct __tunit_is_printable<short> : std::true_type {};
template<> struct __tunit_is_printable<unsigned short> : std::true_type {};
template<> struct __tunit_is_printable<int> : std::true_type {};
template<> struct __tunit_is_printable<unsigned int> : std::true_type {};
template<> struct __tunit_is_printable<long> : std::true_type {};
template<> struct __tunit_is_printable<unsigned long> : std::true_type {};
template<> struct __tunit_is_printable<long long> : std::true_type {};
template<> struct __tunit_is_printable<unsigned long long> : std::true_type {};
template<> struct __tunit_is_printable<const char*> : std::true_type {};
template<> struct __tunit_is_printable<const wchar_t*> : std::true_type {};
template<> struct __tunit_is_printable<float> : std::true_type {};
template<> struct __tunit_is_printable<double> : std::true_type {};
template<> struct __tunit_is_printable<long double> : std::true_type {};
template<> struct __tunit_is_printable<std::string> : std::true_type {};
template<> struct __tunit_is_printable<std::wstring> : std::true_type {};

template<typename Char, typename CharTraits, typename Value>
static void __tunit_print_value(std::basic_ostream<Char, CharTraits>& os, const Value& value, std::true_type) {
  os.operator<<(value);
}

template<typename Char, typename CharTraits, typename Value>
static void __tunit_print_value(std::basic_ostream<Char, CharTraits>& os, Value* value, std::true_type) {
  os.operator<<(value);
}

template<typename Char, typename CharTraits, typename Value>
static void __tunit_print_value(std::basic_ostream<Char, CharTraits>& os, const Value* value, std::true_type) {
  os.operator<<(value);
}

template<typename Char, typename CharTraits, typename Value>
static void __tunit_print_value(std::basic_ostream<Char, CharTraits>& os, const Value& value, std::false_type) {
  size_t size = sizeof(value) > 32 ? 32 : sizeof(value);
  os << size << "-byte object <";
  for (size_t index = 0; index != size; index++)
    os <<  (index != 0 ? (index % 2 == 0 ? " " : "-") : "") << std::hex << std::setiosflags(std::ios_base::uppercase) << std::setw(2) << std::setfill('0') << static_cast<int>(reinterpret_cast<const unsigned char*>(&value)[index]) << std::resetiosflags(std::ios_base::dec) << std::dec;
  os << (size < sizeof(value) ? "-..." : "") << ">";
}

template<typename Char, typename CharTraits, typename Value>
static void __print(std::basic_ostream<Char, CharTraits>& os, const Value& value) {
  __tunit_print_value(os, value, __tunit_is_printable<Value>());
}

template<typename Char, typename CharTraits, typename Value>
static void __print(std::basic_ostream<Char, CharTraits>& os, Value* value) {
  __tunit_print_value(os, value, __tunit_is_printable<Value>());
}

template<typename Char, typename CharTraits, typename Value>
static void __print(std::basic_ostream<Char, CharTraits>& os, const Value* value) {
  __tunit_print_value(os, value, __tunit_is_printable<Value>());
}

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer {
  static void print(std::basic_ostream<Char, CharTraits>& os, const Value* & value) {
    __print(os, value);
  }
  static void print(std::basic_ostream<Char, CharTraits>& os, const Value* const & value) {
    __print(os, value);
  }
  static void print(std::basic_ostream<Char, CharTraits>& os, const Value& value) {
    __print(os, value);
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, std::exception> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::exception& value) {
    os << "exception: " << value.what();
  }
};

#if !__APPLE__ || __MAC_OS_X_VERSION_MAX_ALLOWED >= 101401
template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::optional<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::optional<Value>& value) {
    if (!value.has_value())
      os << "(null)";
    else {
      os << "(";
      __tunit_value_printer<Char, CharTraits, Value>::print(os, value.value());
      os << ")";
    }
  }
};
#endif

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, std::string> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::string& value) {
    os << "\"" << value << "\"";
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, std::u16string> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::u16string& value) {
    __tunit_value_printer<Char, CharTraits, char16_t>::print(os, value.c_str());
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, std::u32string> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::u32string& value) {
    __tunit_value_printer<Char, CharTraits, char32_t>::print(os, value.c_str());
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, std::wstring> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::wstring& value) {
    __tunit_value_printer<Char, CharTraits, wchar_t>::print(os, value.c_str());
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, const char*> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const char* const & value) {
    os << "\"" << value << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, const char* & value) {
    os << "\"" << value << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, char value) {
    os << value;
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, char> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const char* const & value) {
    os << "\"" << value << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, const char* & value) {
    os << "\"" << value << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, char value) {
    os << value;
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, const char16_t*> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const char16_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, char16_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, const char16_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, char16_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, char16_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else {
      os << "\\x" << std::hex << static_cast<int>(value);
    }
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, char16_t> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const char16_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, char16_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, const char16_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, char16_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, char16_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else {
      os << "\\x" << std::hex << static_cast<int>(value);
    }
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, const char32_t*> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const char32_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, char32_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, const char32_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, char32_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, char32_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else {
      os << "\\x" << std::hex << static_cast<int>(value);
    }
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, char32_t> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const char32_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, char32_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, const char32_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, char32_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, char32_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else {
      os << "\\x" << std::hex << static_cast<int>(value);
    }
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, const wchar_t*> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const wchar_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, const wchar_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, wchar_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else {
      os << "\\x" << std::hex << static_cast<int>(value);
    }
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, wchar_t> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const wchar_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, const wchar_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<Char, CharTraits, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<Char, CharTraits>& os, wchar_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else {
      os << "\\x" << std::hex << static_cast<int>(value);
    }
  }
};

template <typename Char, typename CharTraits, typename Type1, typename Type2>
struct __tunit_value_printer<Char, CharTraits, std::pair<Type1, Type2>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::pair<Type1, Type2>& value) {
    os << "(";
    __tunit_value_printer<Char, CharTraits, Type1>::print(os, value.first);
    os << ", ";
    __tunit_value_printer<Char, CharTraits, Type2>::print(os, value.second);
    os << ")";
  }
};

template<typename Char, typename CharTraits, typename Type, unsigned N, unsigned Last>
struct __tuple_printer {
  static void print(std::basic_ostream<Char, CharTraits>& os, const Type& value) {
    __tunit_value_printer<Char, CharTraits, typename std::tuple_element<N, Type>::type>::print(os, std::get<N>(value));
    os << ", ";
    __tuple_printer<Char, CharTraits, Type, N + 1, Last>::print(os, value);
  }
};

template<typename Char, typename CharTraits, typename Type, unsigned N>
struct __tuple_printer<Char, CharTraits, Type, N, N> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const Type& value) {
    __tunit_value_printer<Char, CharTraits, typename std::tuple_element<N, Type>::type>::print(os, std::get<N>(value));
  }
};

template <typename Char, typename CharTraits, typename ... Types>
struct __tunit_value_printer<Char, CharTraits, std::tuple<Types ...>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::tuple<Types ...>& value) {
    os << "(";
    __tuple_printer<Char, CharTraits, std::tuple<Types ...>, 0, sizeof...(Types) - 1>::print(os, value);
    os << ")";
  }
};

template <typename Char, typename CharTraits>
struct __tunit_value_printer<Char, CharTraits, std::tuple<>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::tuple<>&) {
    os << "()";
  }
};

template <typename Char, typename CharTraits, typename Iterator>
std::basic_ostream<Char, CharTraits>& __print_sequence_container(std::basic_ostream<Char, CharTraits>& os, const Iterator& begin, const Iterator& end) {
  os << "[";
  bool first = true;
  for (Iterator it = begin; it != end; ++it) {
    if (!first) os << ", ";
    __tunit_value_printer<Char, CharTraits, typename std::iterator_traits<Iterator>::value_type>::print(os, *it);
    first = false;
  }
  return os << "]";
}

template <typename Char, typename CharTraits, typename Value, size_t Size>
struct __tunit_value_printer<Char, CharTraits, std::array<Value, Size>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::array<Value, Size>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::deque<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::deque<Value>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::forward_list<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::forward_list<Value>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::list<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::list<Value>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::initializer_list<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::initializer_list<Value>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::vector<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::vector<Value>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Iterator>
std::basic_ostream<Char, CharTraits>& __print_associative_container(std::basic_ostream<Char, CharTraits>& os, const Iterator& begin, const Iterator& end) {
  os << "{";
  bool first = true;
  for (Iterator it = begin; it != end; ++it) {
    if (!first) os << ", ";
    __tunit_value_printer<Char, CharTraits, typename std::iterator_traits<Iterator>::value_type>::print(os, *it);
    first = false;
  }
  return os << "}";
}

template <typename Char, typename CharTraits, typename Key, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::map<Key, Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::map<Key, Value>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Key, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::multimap<Key, Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::multimap<Key, Value>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::multiset<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::multiset<Value>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::set<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::set<Value>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Key, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::unordered_map<Key, Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::unordered_map<Key, Value>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Key, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::unordered_multimap<Key, Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::unordered_multimap<Key, Value>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::unordered_multiset<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::unordered_multiset<Value>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Value>
struct __tunit_value_printer<Char, CharTraits, std::unordered_set<Value>> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const std::unordered_set<Value>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename Char, typename CharTraits, typename Type>
std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const Type& value) {
  __tunit_value_printer<Char, CharTraits, Type>::print(os, value);
  return os;
}

template <typename Char, typename CharTraits, typename Type>
std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const Type* value) {
  __tunit_value_printer<Char, CharTraits, Type>::print(os, value);
  return os;
}

template <typename Char, typename CharTraits, typename Type>
std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, Type* value) {
  __tunit_value_printer<Char, CharTraits, Type>::print(os, value);
  return os;
}

inline std::string __tunit_codepoint_to_string(char32_t codepoint) {
  std::string result;
  if (codepoint < 0x80) {
    result.push_back(static_cast<char>(codepoint));
  } else  if (codepoint < 0x800) {
    result.push_back(static_cast<char>((codepoint >> 6) | 0xc0));
    result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
  } else if (codepoint < 0x10000) {
    result.push_back(static_cast<char>((codepoint >> 12) | 0xe0));
    result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
  } else {
    result.push_back(static_cast<char>((codepoint >> 18) | 0xf0));
    result.push_back(static_cast<char>(((codepoint >> 12) & 0x3f) | 0x80));
    result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
  }
  return result;
}

inline std::string __tunit_to_string(const char16_t& value) {
  std::stringstream ss;
  ss << "\"" << __tunit_codepoint_to_string(value) << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const char32_t& value) {
  std::stringstream ss;
  ss << "\"" << __tunit_codepoint_to_string(value) << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const wchar_t& value) {
  std::stringstream ss;
  ss << "\"" << __tunit_codepoint_to_string(value) << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const std::string& value) {
  std::stringstream ss;
  ss << "\"" << value << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const std::u16string& value) {
  std::string result;
  result += "\"";
  for (auto codepoint : value)
    result += __tunit_codepoint_to_string(codepoint);
  result += "\"";
  return result;
}

inline std::string __tunit_to_string(const std::u32string& value) {
  std::string result;
  result += "\"";
  for (auto codepoint : value)
    result += __tunit_codepoint_to_string(codepoint);
  result += "\"";
  return result;
}

inline std::string __tunit_to_string(const std::wstring& value) {
  std::string result;
  result += "\"";
  for (auto codepoint : value)
    result += __tunit_codepoint_to_string(codepoint);
  result += "\"";
  return result;
}

inline std::string __tunit_to_string(const char* value) {
  std::stringstream ss;
  ss << "\"" << value << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const char16_t* value) {
  return __tunit_to_string(std::u16string(value));
}

inline std::string __tunit_to_string(const char32_t* value) {
  return __tunit_to_string(std::u32string(value));
}

inline std::string __tunit_to_string(const wchar_t* value) {
  return __tunit_to_string(std::wstring(value));
}

template <typename TValue>
inline std::string __tunit_to_string(const TValue& value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}

template <typename TValue>
inline std::string __tunit_to_string(const TValue* value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}
/// @endcond
