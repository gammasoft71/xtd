/// @file
/// @brief Contains xtd fundamental types.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <string>
#include <typeinfo>
#include "core_export.h"

/// @cond
#if !defined(__cpp_lib_char8_t)
class char8_t {
public:
  char8_t() {}
  char8_t(char value) : value_(value) {}
  char8_t(const char8_t&) = default;
  char8_t(char8_t&&) = default;
  
  operator char() const {return value_;}
  bool operator==(char8_t c) const {return value_ == c.value_;}
  bool operator!=(char8_t c) const {return value_ != c.value_;}
  bool operator<(char8_t c) const {return value_ < c.value_;}
  bool operator>(char8_t c) const {return value_ > c.value_;}
  bool operator<=(char8_t c) const {return value_ <= c.value_;}
  bool operator>=(char8_t c) const {return value_ >= c.value_;}
  
  char8_t operator+(char8_t c) const {return char8_t(value_ + c.value_);}
  char8_t operator-(char8_t c) const {return char8_t(value_ - c.value_);}
  char8_t& operator=(char8_t c) {value_ = c.value_; return *this;}
  char8_t& operator++() {value_ += 1; return *this;}
  char8_t operator++(int) {char8_t result(*this); ++(*this); return result;}
  char8_t& operator--() {value_ -= 1; return *this;}
  char8_t operator--(int) {char8_t result(*this); --(*this); return result;}
  
  bool operator==(char c) const {return value_ == c;}
  bool operator!=(char c) const {return value_ != c;}
  bool operator<(char c) const {return value_ < c;}
  bool operator>(char c) const {return value_ > c;}
  bool operator<=(char c) const {return value_ <= c;}
  bool operator>=(char c) const {return value_ >= c;}
  
  friend std::ostream& operator <<(std::ostream& os, const char8_t& c) noexcept {return os << std::to_string(static_cast<int32_t>(c.value_));}
  
private:
  char value_ = 0;
};

namespace std {
  using u8string=basic_string<char8_t>;
}
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  using byte_t = uint8_t;
  using decimal_t = long double;
  using sbyte_t = int8_t;
  using single_t = float;
  using ushort_t = unsigned short;
  using ulong_t = unsigned long;
  
#if defined(__linux__) && defined(_LP64)
  using llong_t = long long int;
  using ullong_t = unsigned long long int;
#else
  using llong_t = long;
  using ullong_t = unsigned long;
#endif
  /// @endcond

  /// @brief Represents a 8-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using byte = uint8_t;
  
  /// @brief Represents a 16-bit unicode character.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using char8 = char8_t;
  
  /// @brief Represents a 8-bit unicode character.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using char16 = char16_t;

  /// @brief Represents a 32-bit unicode character.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using char32 = char32_t;
  
  /// @brief Represents a decimal-precision floating-point number.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using decimal = decimal_t;
  
  /// @brief Represents a 16-bit signed integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using int16 = int16_t;
  
  /// @brief Represents a 32-bit signed integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using int32 = int32_t;
  
  /// @brief Represents a 64-bit signed integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using int64 = int64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @ingroup xtd_core types
  using intptr = intptr_t;
  
  /// @brief Represents a null pointer value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// std::unique_ptr<foo_class> foo = std::make_unique<foo_class>();
  /// ...
  /// foo = null; // release the unique pointer.
  /// @endcode
  /// @ingroup xtd_core types
  extern core_export_ std::nullptr_t null;
  
  /// @brief Represents a 8-bit signed integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using sbyte = int8_t;
  
  /// @brief Represents a size of any object in bytes
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using size = size_t;
  
  /// @brief Stores information about a type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using type = std::type_info;
  
  /// @brief Represents a 8-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uchar = unsigned char;
  
  /// @brief Represents a 32-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uint = unsigned int;
  
  /// @brief Represents a 16-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uint16 = uint16_t;
  
  /// @brief Represents a 32-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uint32 = uint32_t;
  
  /// @brief Represents a 64-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uint64 = uint64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using uintptr = uintptr_t;
  
  /// @brief Represents a 16-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using ushort = ushort_t;
  
  /// @brief Represents a 32-bit or 64-bit unsigned integer.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using ulong = ulong_t;
  
  /// @brief Represents a wide character.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using wchar = wchar_t;
}

/*
/// @cond
namespace __ {
  /// @endcond
  /// @brief The system namespace contains all fundamental classes to access Hardware, Os, System, and more.
  namespace system = xtd;
}
using namespace __;
*/
