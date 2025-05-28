/// @file
/// @brief Contains xtd::time_span suffixes.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../time_span.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Time span suffixes
    
    /// @{
    /// @brief Used to convert the specified value as hours to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 10_h;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_h(unsigned long long h);
    
    /// @brief Used to convert the specified value as minutes to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 25_m;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_m(unsigned long long m);
    
    /// @brief Used to convert the specified value as minutes to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 25_min;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_min(unsigned long long min);
    
    /// @brief Used to convert the specified value as millisconds to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 25_ms;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_ms(unsigned long long ms);
    
    /// @brief Used to convert the specified value as nanoseconds to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 25_ns;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_ns(unsigned long long ns);
    
    /// @brief Used to convert the specified value as seconds to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 42_s;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_s(unsigned long long s);
    
    /// @brief Used to convert the specified value as tiks to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 42_t;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_t(unsigned long long t);
    
    /// @brief Used to convert the specified value as microseconds to xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = 42_us;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_us(unsigned long long us);
    
    /// @brief Used to convert specified value into xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = "6::12::24"_ts;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_ts(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = u8"6::12::24"_ts;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_ts(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = u"6::12::24"_ts;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_ts(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = U"6::12::24"_ts;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_ts(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::time_span.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::time_span ts = L"6::12::24"_ts;
    /// xtd::console::out << ts << xtd::environment::new_line;
    /// ```
    xtd::time_span operator""_ts(const wchar* s, xtd::size n);
    /// @}
  }
}
