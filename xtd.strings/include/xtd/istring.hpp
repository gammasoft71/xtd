/// @file
/// @brief Contains xtd::strings class.
#pragma once

#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Immutable basic_string<Char>
  template<class Char, class CharTraits = std::char_traits<Char>, class Allocator = std::allocator<Char>>
  class immutable_basic_string : public std::basic_string<Char, CharTraits, Allocator> {
  public:
    /// @cond
    immutable_basic_string() noexcept {}
    
    explicit immutable_basic_string(const Allocator& a) noexcept : std::basic_string<Char, CharTraits, Allocator>(a) {}
    
    immutable_basic_string(const immutable_basic_string& str) noexcept : std::basic_string<Char, CharTraits, Allocator>(str) {}
    immutable_basic_string(const immutable_basic_string& str, const Allocator& a) noexcept : std::basic_string<Char, CharTraits, Allocator>(str, a) {}
    
    immutable_basic_string(immutable_basic_string&& str) noexcept : std::basic_string<Char, CharTraits, Allocator>(str)  {}
    
    immutable_basic_string(immutable_basic_string&& str, const Allocator& a) noexcept : std::basic_string<Char, CharTraits, Allocator>(str, a) {}

    immutable_basic_string(const Char* str) : std::basic_string<Char, CharTraits, Allocator>(str) {}
    immutable_basic_string(const Char* str, const Allocator& a) : std::basic_string<Char, CharTraits, Allocator>(str, a) {}
    immutable_basic_string(const Char* str, size_t n) : std::basic_string<Char, CharTraits, Allocator>(str, n) {}
    immutable_basic_string(const Char* str, size_t n, const Allocator& a) : std::basic_string<Char, CharTraits, Allocator>(str, n, a) {}
    immutable_basic_string(size_t n, Char c)  : std::basic_string<Char, CharTraits, Allocator>(n, c) {}
    immutable_basic_string(size_t n, Char c, const Allocator& a)  : std::basic_string<Char, CharTraits, Allocator>(n, c, a) {}
    immutable_basic_string(const immutable_basic_string& str, size_t pos, size_t n, const Allocator& a = Allocator()) : std::basic_string<Char, CharTraits, Allocator>(str, pos, n, a) {}
    immutable_basic_string(const immutable_basic_string& str, size_t pos, const Allocator& a = Allocator()) : std::basic_string<Char, CharTraits, Allocator>(str, pos, a) {}
    //template<class T>
    //immutable_basic_string(const T& t, size_t pos, size_t n, const Allocator& a = Allocator(), typename std::enable_if<std::__can_be_converted_to_string_view<Char, CharTraits, T>::value, void>::type* = 0) : std::basic_string<Char, CharTraits, Allocator>(t, pos, n, a, typename std::enable_if<std::__can_be_converted_to_string_view<Char, CharTraits, T>::value, void>::type* = 0) {}
    //explicit immutable_basic_string(std::__self_view sv) : std::basic_string<Char, CharTraits, Allocator>(sv) {}
    //immutable_basic_string(std::__self_view sv, const Allocator& a) : std::basic_string<Char, CharTraits, Allocator>(sv, a) {}
    template<class InputIterator>
    immutable_basic_string(InputIterator first, InputIterator last) : std::basic_string<Char, CharTraits, Allocator>(first, last) {}
    template<class InputIterator>
    immutable_basic_string(InputIterator first, InputIterator last, const Allocator& a) : std::basic_string<Char, CharTraits, Allocator>(first, last, a) {}
    immutable_basic_string(std::initializer_list<Char> il) : std::basic_string<Char, CharTraits, Allocator>(il) {}
    immutable_basic_string(std::initializer_list<Char> il, const Allocator& a)  : std::basic_string<Char, CharTraits, Allocator>(il, a) {}
    /// @endcond
  };
  
  /// @brief Immutable string<Char>
  /// @remarks It can be replaced by const std::string<Char>.
  using istring = immutable_basic_string<char>;

  /// @brief Immutable u16string<Char>
  /// @remarks It can be replaced by const std::u16string<Char>.
  using iu16string = immutable_basic_string<char16_t>;

  /// @brief Immutable u32string<Char>
  /// @remarks It can be replaced by const std::u32string<Char>.
  using iu32string =immutable_basic_string<char32_t>;

  /// @brief Immutable wstring<Char>
  /// @remarks It can be replaced by const std::wstring<Char>.
  using iwstring = immutable_basic_string<wchar_t>;
}
