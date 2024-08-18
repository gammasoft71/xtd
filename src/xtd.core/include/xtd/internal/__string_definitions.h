/// @file
/// @brief Contains string definitions.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include <string>
#define __XTD_STD_INTERNAL__
#include "__xtd_std_version.h"
#include "../char16.h"
#include "../char32.h"
#include "../char8.h"
#include "../wchar.h"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of character units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A basic_string is a sequential collection of characters that's used to represent text. A xtd::basic_string object is a sequential collection of char that represent a basic_string. The value of the xtd::basic_string object is the content of the sequential collection of `char_t`, and unlike [std::basic_string<char_t>](https://en.cppreference.com/w/cpp/basic_string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable basic_string class, you can use xtd::text::basic_string_builder <char_t> class.
  /// @remarks xtd::basic_string implements [std::basic_string<char>](https://en.cppreference.com/w/cpp/basic_string/basic_string) and therefore offers the full (immutable) API of [std::string](https://en.cppreference.com/w/cpp/string/basic_string).
  template<typename char_t, typename traits_t = std::char_traits<char_t>, typename allocator_t = std::allocator<char_t>>
  class basic_string;
  
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::string object is a sequential collection of char that represent a string; a char corresponds to a UTF-8 code unit. The value of the xtd::string object is the content of the sequential collection of char, and unlike [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::string_builder class.
  /// @remarks xtd::string implements xtd::basic_string and therefore offers the full (immutable) API of [std::string](https://en.cppreference.com/w/cpp/string/basic_string).
  /// @todo Rename `string_` to `string`.
  using string_ = xtd::basic_string<char>;
  
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::string object is a sequential collection of char that represent a string; a char corresponds to a UTF-8 code unit. The value of the xtd::string object is the content of the sequential collection of char, and unlike [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::string_builder class.
  /// @remarks xtd::string implements xtd::basic_string and therefore offers the full (immutable) API of [std::string](https://en.cppreference.com/w/cpp/string).
  /// @todo Remove `string` class.
  class string;
  
  /// @brief Represents text as a sequence of UTF-16 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::u16string object is a sequential collection of xtd::char16 that represent a string; a xtd::char16 corresponds to a UTF-16 code unit. The value of the xtd::u16string object is the content of the sequential collection of xtd::char16, and unlike [std::basic_string<char16_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::u16string_builder class.
  /// @remarks xtd::u16string implements xtd::basic_string and therefore offers the full (immutable) API of [std::u16string](https://en.cppreference.com/w/cpp/string).
  using u16string = xtd::basic_string<xtd::char16>;
  
  /// @brief Represents text as a sequence of UTF-32 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::u32string object is a sequential collection of xtd::char32 that represent a string; a xtd::char32 corresponds to a UTF-32 code unit. The value of the xtd::u32string object is the content of the sequential collection of xtd::char32, and unlike [std::basic_string<char16_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::u32string_builder class.
  /// @remarks xtd::u32string implements xtd::basic_string and therefore offers the full (immutable) API of [std::u32string](https://en.cppreference.com/w/cpp/string).
  using u32string = xtd::basic_string<xtd::char32>;
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::u8string object is a sequential collection of xtd::char8 that represent a string; a xtd::char8 corresponds to a UTF-8 code unit. The value of the xtd::u8string object is the content of the sequential collection of xtd::char8, and unlike [std::basic_string<char8_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::u8string_builder class.
  /// @remarks xtd::u8string implements xtd::basic_string and therefore offers the full (immutable) API of [std::u8string](https://en.cppreference.com/w/cpp/string).
  using u8string = xtd::basic_string<xtd::char8>;
#endif
  
  /// @brief Represents text as a sequence of UTF-16 code unit on Windows or UTF-32 code unit on non-Windows systems.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::wstring object is a sequential collection of xtd::wchar that represent a string; a xtd::wchar corresponds to a UTF-16 code unit on Windows or UTF-32 code unit on non-Windows systems. The value of the xtd::wstring object is the content of the sequential collection of xtd::wchar, and unlike [std::basic_string<wchar_t>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::wstring_builder class.
  /// @remarks xtd::wstring implements xtd::basic_string and therefore offers the full (immutable) API of [std::wstring](https://en.cppreference.com/w/cpp/string).
  using wstring = xtd::basic_string<xtd::wchar>;
}
