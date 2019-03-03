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

    immutable_basic_string(size_t n, Char c)  : std::basic_string<Char, CharTraits, Allocator>(n, c) {}
    immutable_basic_string(size_t n, Char c, const Allocator& a)  : std::basic_string<Char, CharTraits, Allocator>(n, c, a) {}

    immutable_basic_string(const immutable_basic_string& str, size_t pos, size_t n, const Allocator& a = Allocator()) : std::basic_string<Char, CharTraits, Allocator>(str, pos, n, a) {}
    immutable_basic_string(const immutable_basic_string& str, size_t pos, const Allocator& a = Allocator()) : std::basic_string<Char, CharTraits, Allocator>(str, pos, a) {}

    immutable_basic_string(const Char* str, size_t n) : std::basic_string<Char, CharTraits, Allocator>(str, n) {}
    immutable_basic_string(const Char* str, size_t n, const Allocator& a) : std::basic_string<Char, CharTraits, Allocator>(str, n, a) {}
    
    immutable_basic_string(const Char* str) : std::basic_string<Char, CharTraits, Allocator>(str) {}
    immutable_basic_string(const Char* str, const Allocator& a) : std::basic_string<Char, CharTraits, Allocator>(str, a) {}

    template<class InputIterator>
    immutable_basic_string(InputIterator first, InputIterator last) : std::basic_string<Char, CharTraits, Allocator>(first, last) {}
    template<class InputIterator>
    immutable_basic_string(InputIterator first, InputIterator last, const Allocator& a) : std::basic_string<Char, CharTraits, Allocator>(first, last, a) {}

    immutable_basic_string(const immutable_basic_string& str) noexcept : std::basic_string<Char, CharTraits, Allocator>(str) {}
    immutable_basic_string(const immutable_basic_string& str, const Allocator& a) noexcept : std::basic_string<Char, CharTraits, Allocator>(str, a) {}

    immutable_basic_string(immutable_basic_string&& str) noexcept : std::basic_string<Char, CharTraits, Allocator>(str)  {}
    immutable_basic_string(immutable_basic_string&& str, const Allocator& a) noexcept : std::basic_string<Char, CharTraits, Allocator>(str, a) {}

    immutable_basic_string(std::initializer_list<Char> il) : std::basic_string<Char, CharTraits, Allocator>(il) {}
    immutable_basic_string(std::initializer_list<Char> il, const Allocator& a)  : std::basic_string<Char, CharTraits, Allocator>(il, a) {}

    template<class T>
    immutable_basic_string(const T& t, const Allocator& a = Allocator()) : std::basic_string<Char, CharTraits, Allocator>(t, a) {}

    template<class T>
    immutable_basic_string(const T& t, size_t pos, size_t n, const Allocator& a = Allocator()) : std::basic_string<Char, CharTraits, Allocator>(t, pos, n, a) {}

    ~immutable_basic_string() {}
    /// @endcond
    
    const Char& at(size_t pos) {return this->basic_string::at(pos);}
    const Char& at(size_t pos) const {return this->basic_string::at(pos);}
    
    const Char& operator[](size_t pos) {return this->basic_string::operator[](pos);}
    const Char& operator[](size_t pos) const {return this->basic_string::operator[](pos);}

    const Char& front() {this->basic_string::front();}
    const Char& front() const {this->basic_string::front();}
    
    const Char& back() {this->basic_string::back();}
    const Char& back() const {this->basic_string::back();}
    
    const Char* data() {this->basic_string::data();}
    const Char* data() const {this->basic_string::data();}
    
    const Char* c_str() {this->basic_string::c_str();}
    const Char* c_str() const {this->basic_string::c_str();}

  private:
    immutable_basic_string& assign(size_t count, Char ch );
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
