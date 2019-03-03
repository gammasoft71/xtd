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
    using __self = immutable_basic_string;
    using __self_view = std::basic_string_view<Char, CharTraits>;
    using traits_type = CharTraits;
    using value_type = Char;
    using allocator_type = Allocator;
    using __alloc_traits = std::allocator_traits<allocator_type>;
    using size_type = typename __alloc_traits::size_type;
    using difference_type = typename __alloc_traits::difference_type;
    using reference = value_type&;
    using const_reference =  const value_type&;
    using pointer = typename __alloc_traits::pointer;
    using const_pointer = typename __alloc_traits::const_pointer;
    using iterator = typename std::basic_string<Char, CharTraits, Allocator>::iterator;
    using const_iterator = typename std::basic_string<Char, CharTraits, Allocator>::const_iterator;
    using reverse_iterator = typename std::basic_string<Char, CharTraits, Allocator>::reverse_iterator;
    using const_reverse_iterator = typename std::basic_string<Char, CharTraits, Allocator>::reverse_iterator;

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
    
    const Char& at(size_t pos) {return this->std::basic_string<Char, CharTraits, Allocator>::at(pos);}
    const Char& at(size_t pos) const {return this->std::basic_string<Char, CharTraits, Allocator>::at(pos);}
    
    const Char& operator[](size_t pos) {return this->std::basic_string<Char, CharTraits, Allocator>::operator[](pos);}
    const Char& operator[](size_t pos) const {return this->std::basic_string<Char, CharTraits, Allocator>::operator[](pos);}

    const Char& front() {this->std::basic_string<Char, CharTraits, Allocator>::front();}
    const Char& front() const {this->std::basic_string<Char, CharTraits, Allocator>::front();}
    
    const Char& back() {this->std::basic_string<Char, CharTraits, Allocator>::back();}
    const Char& back() const {this->std::basic_string<Char, CharTraits, Allocator>::back();}
    
    const Char* data() {this->std::basic_string<Char, CharTraits, Allocator>::data();}
    const Char* data() const {this->std::basic_string<Char, CharTraits, Allocator>::data();}
    
    const Char* c_str() {this->basic_string::c_str();}
    const Char* c_str() const {this->basic_string::c_str();}
    
    const_iterator begin() {return this->std::basic_string<Char, CharTraits, Allocator>::begin();}
    const_iterator begin() const {return this->std::basic_string<Char, CharTraits, Allocator>::begin();}
    const_iterator cbegin() const {return this->std::basic_string<Char, CharTraits, Allocator>::cbegin();}
    
    const_iterator end() {return this->std::basic_string<Char, CharTraits, Allocator>::end();}
    const_iterator end() const {return this->std::basic_string<Char, CharTraits, Allocator>::end();}
    const_iterator cend() const {return this->std::basic_string<Char, CharTraits, Allocator>::cend();}
    
    const_iterator rbegin() {this->std::basic_string<Char, CharTraits, Allocator>::rbegin();}
    const_iterator rbegin() const {this->std::basic_string<Char, CharTraits, Allocator>::rbegin();}
    const_iterator crbegin() const {this->std::basic_string<Char, CharTraits, Allocator>::crbegin();}
    
    const_iterator rend() {this->std::basic_string<Char, CharTraits, Allocator>::rend();}
    const_iterator rend() const {this->std::basic_string<Char, CharTraits, Allocator>::rend();}
    const_iterator crend() const {this->std::basic_string<Char, CharTraits, Allocator>::crend();}

    immutable_basic_string operator=(const immutable_basic_string& str) {return this->std::basic_string<Char, CharTraits, Allocator>::assign(str);}
    immutable_basic_string operator=(Char ch) {return this->std::basic_string<Char, CharTraits, Allocator>::assign(ch);}
    immutable_basic_string operator=(const char* str) {return this->std::basic_string<Char, CharTraits, Allocator>::assign(str);}
    immutable_basic_string operator=(const std::initializer_list<Char>& il) {return this->std::basic_string<Char, CharTraits, Allocator>::assign(il);}
    template<typename T>
    immutable_basic_string operator=(const T& t) {return this->std::basic_string<Char, CharTraits, Allocator>::assign(t);}

    immutable_basic_string& operator+=(const immutable_basic_string& str) {this->std::basic_string<Char, CharTraits, Allocator>::operator+=(str); return *this;}
    immutable_basic_string& operator+=(Char ch) { this->std::basic_string<Char, CharTraits, Allocator>::operator+=(ch); return *this;}
    immutable_basic_string& operator+=(const Char* str) {this->std::basic_string<Char, CharTraits, Allocator>::operator+=(str); return *this;}
    immutable_basic_string& operator+=(const std::initializer_list<Char>& il) {this->std::basic_string<Char, CharTraits, Allocator>::operator+=(il); return *this;}
    template<typename T>
    immutable_basic_string& operator+=(const T& t) {this->std::basic_string<Char, CharTraits, Allocator>::operator+=(t); return *this;}
    
    int compare(const immutable_basic_string& str) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::compare(str);}
    int compare(size_type pos1, size_type count1, const immutable_basic_string& str, size_type pos2, size_type count2 = npos) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::compare(pos1, count1, str, pos2, count2);}
    int compare(const Char* str) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::compare(str);}
    int compare(size_type pos1, size_type count1, const Char* str) const {return this->std::basic_string<Char, CharTraits, Allocator>::compare(pos1, count1, str);}
    int compare(size_type pos1, size_type count1, const Char* str, size_type count2) const {return this->std::basic_string<Char, CharTraits, Allocator>::compare(pos1, count1, str, count2);}
    template < class T >
    int compare(const T& t) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::compare(t);}
    template < class T >
    int compare(size_type pos1, size_type count1, const T& t) const {return this->std::basic_string<Char, CharTraits, Allocator>::compare(pos1, count1, t);}
    template < class T >
    int compare(size_type pos1, size_type count1, const T& t, size_type pos2, size_type count2 = npos) const {return this->std::basic_string<Char, CharTraits, Allocator>::compare(pos1, count1, t, pos2, count2);}

    immutable_basic_string substr(size_type pos = 0, size_type count = npos) const {return this->std::basic_string<Char, CharTraits, Allocator>::substr(pos, count);}
    static const size_type npos = -1;
    
    size_type copy(Char* dest, size_type count, size_type pos = 0) const {return this->std::basic_string<Char, CharTraits, Allocator>::copy(dest, count, pos);}
    void swap(immutable_basic_string& other) noexcept {this->std::basic_string<Char, CharTraits, Allocator>::swap(other);}
    
    size_type find(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find(str, pos);}
    size_type find(const Char* str, size_type pos, size_type count) const {return this->std::basic_string<Char, CharTraits, Allocator>::find(str, pos, count);}
    size_type find(const Char* str, size_type pos = 0) const {return this->std::basic_string<Char, CharTraits, Allocator>::find(str, pos);}
    size_type find(Char ch, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find(ch, pos);}
    template < class T >
    size_type find(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find(t, pos);}
    
    size_type rfind(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::rfind(str, pos);}
    size_type rfind(const Char* str, size_type pos, size_type count) const {return this->std::basic_string<Char, CharTraits, Allocator>::rfind(str, pos, count);}
    size_type rfind(const Char* str, size_type pos = 0) const {return this->std::basic_string<Char, CharTraits, Allocator>::rfind(str, pos);}
    size_type rfind(Char ch, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::rfind(ch, pos);}
    template < class T >
    size_type rfind(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::rfind(t, pos);}

    size_type find_first_of(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_of(str, pos);}
    size_type find_first_of(const Char* str, size_type pos, size_type count) const {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_of(str, pos, count);}
    size_type find_first_of(const Char* str, size_type pos = 0) const {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_of(str, pos);}
    size_type find_first_of(Char ch, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_of(ch, pos);}
    template<typename T>
    size_type find_first_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_of(t, pos);}
    
    size_type find_first_not_of(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_not_of(str, pos);}
    size_type find_first_not_of(const Char* str, size_type pos, size_type count) const {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_not_of(str, pos, count);}
    size_type find_first_not_of(const Char* str, size_type pos = 0) const {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_not_of(str, pos);}
    size_type find_first_not_of(Char ch, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_not_of(ch, pos);}
    template<typename T>
    size_type find_first_not_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_first_not_of(t, pos);}

    size_type find_last_of(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_of(str, pos);}
    size_type find_last_of(const Char* str, size_type pos, size_type count) const {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_of(str, pos, count);}
    size_type find_last_of(const Char* str, size_type pos = 0) const {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_of(str, pos);}
    size_type find_last_of(Char ch, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_of(ch, pos);}
    template<typename T>
    size_type find_last_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_of(t, pos);}
    
    size_type find_last_not_of(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_not_of(str, pos);}
    size_type find_last_not_of(const Char* str, size_type pos, size_type count) const {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_not_of(str, pos, count);}
    size_type find_last_not_of(const Char* str, size_type pos = 0) const {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_not_of(str, pos);}
    size_type find_last_not_of(Char ch, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_not_of(ch, pos);}
    template<typename T>
    size_type find_last_not_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<Char, CharTraits, Allocator>::find_last_not_of(t, pos);}

    friend std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const immutable_basic_string<Char, CharTraits, Allocator>& str) {return os << ((const std::basic_string<Char, CharTraits, Allocator>&)str);}
    friend std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, immutable_basic_string<Char, CharTraits, Allocator>& str) {return os << ((std::basic_string<Char, CharTraits, Allocator>&)str);}

  private:
    immutable_basic_string& assign(size_t count, Char ch );
    void reserve(size_type new_cap);
    void shrink_to_fit();
    void clear();
    immutable_basic_string& insert(size_type index, size_type count, Char ch);
    immutable_basic_string& erase(size_type index = 0, size_type count = npos);
    void push_back(Char ch);
    void pop_back();
    immutable_basic_string& append(size_type count, Char ch);
    immutable_basic_string& replace(size_type pos, size_type count, const immutable_basic_string& str);
    void resize(size_type count);
  };
  
  inline namespace string_literals {
    inline std::basic_string<char> operator "" _s( const char* str, size_t len ) {
      return std::basic_string<char>(str, len);
    }
    
    inline std::basic_string<wchar_t> operator "" _s( const wchar_t* str, size_t len ) {
      return std::basic_string<wchar_t>(str, len);
    }
    
    inline std::basic_string<char16_t> operator "" _s( const char16_t* str, size_t len ) {
      return immutable_basic_string<char16_t>(str, len);
    }
    
    inline std::basic_string<char32_t> operator "" _s( const char32_t* str, size_t len ) {
      return std::basic_string<char32_t>(str, len);
    }

    inline immutable_basic_string<char> operator "" _is( const char* str, size_t len ) {
      return immutable_basic_string<char>(str, len);
    }
    
    inline immutable_basic_string<wchar_t> operator "" _is( const wchar_t* str, size_t len ) {
      return immutable_basic_string<wchar_t>(str, len);
    }
    
    inline immutable_basic_string<char16_t> operator "" _is( const char16_t* str, size_t len ) {
      return immutable_basic_string<char16_t>(str, len);
    }
    
    inline immutable_basic_string<char32_t> operator "" _is( const char32_t* str, size_t len ) {
      return immutable_basic_string<char32_t>(str, len);
    }
  }

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
