/// @file
/// @brief Contains xtd::immutable_basic_string class.
#pragma once

#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Immutable basic_string<char_t>
  template<class char_t, class char_traits_t = std::char_traits<char_t>, class allocator_t = std::allocator<char_t>>
  class immutable_basic_string : public std::basic_string<char_t, char_traits_t, allocator_t> {
  public:
    /// @cond
    using __self = immutable_basic_string;
    using __self_view = std::basic_string_view<char_t, char_traits_t>;
    using traits_type = char_traits_t;
    using value_type = char_t;
    using allocator_type = allocator_t;
    using __alloc_traits = std::allocator_traits<allocator_type>;
    using size_type = typename __alloc_traits::size_type;
    using difference_type = typename __alloc_traits::difference_type;
    using reference = value_type&;
    using const_reference =  const value_type&;
    using pointer = typename __alloc_traits::pointer;
    using const_pointer = typename __alloc_traits::const_pointer;
    using iterator = typename std::basic_string<char_t, char_traits_t, allocator_t>::iterator;
    using const_iterator = typename std::basic_string<char_t, char_traits_t, allocator_t>::const_iterator;
    using reverse_iterator = typename std::basic_string<char_t, char_traits_t, allocator_t>::reverse_iterator;
    using const_reverse_iterator = typename std::basic_string<char_t, char_traits_t, allocator_t>::reverse_iterator;

    immutable_basic_string() noexcept {}
    explicit immutable_basic_string(const allocator_t& a) noexcept : std::basic_string<char_t, char_traits_t, allocator_t>(a) {}

    immutable_basic_string(size_t n, char_t c)  : std::basic_string<char_t, char_traits_t, allocator_t>(n, c) {}
    immutable_basic_string(size_t n, char_t c, const allocator_t& a)  : std::basic_string<char_t, char_traits_t, allocator_t>(n, c, a) {}

    immutable_basic_string(const immutable_basic_string& str, size_t pos, size_t n, const allocator_t& a = allocator_t()) : std::basic_string<char_t, char_traits_t, allocator_t>(str, pos, n, a) {}
    immutable_basic_string(const immutable_basic_string& str, size_t pos, const allocator_t& a = allocator_t()) : std::basic_string<char_t, char_traits_t, allocator_t>(str, pos, a) {}

    immutable_basic_string(const char_t* str, size_t n) : std::basic_string<char_t, char_traits_t, allocator_t>(str, n) {}
    immutable_basic_string(const char_t* str, size_t n, const allocator_t& a) : std::basic_string<char_t, char_traits_t, allocator_t>(str, n, a) {}
    
    immutable_basic_string(const char_t* str) : std::basic_string<char_t, char_traits_t, allocator_t>(str) {}
    immutable_basic_string(const char_t* str, const allocator_t& a) : std::basic_string<char_t, char_traits_t, allocator_t>(str, a) {}

    template<class InputIterator>
    immutable_basic_string(InputIterator first, InputIterator last) : std::basic_string<char_t, char_traits_t, allocator_t>(first, last) {}
    template<class InputIterator>
    immutable_basic_string(InputIterator first, InputIterator last, const allocator_t& a) : std::basic_string<char_t, char_traits_t, allocator_t>(first, last, a) {}

    immutable_basic_string(const immutable_basic_string& str) noexcept : std::basic_string<char_t, char_traits_t, allocator_t>(str) {}
    immutable_basic_string(const immutable_basic_string& str, const allocator_t& a) noexcept : std::basic_string<char_t, char_traits_t, allocator_t>(str, a) {}

    immutable_basic_string(immutable_basic_string&& str) noexcept : std::basic_string<char_t, char_traits_t, allocator_t>(str)  {}
    immutable_basic_string(immutable_basic_string&& str, const allocator_t& a) noexcept : std::basic_string<char_t, char_traits_t, allocator_t>(str, a) {}

    immutable_basic_string(std::initializer_list<char_t> il) : std::basic_string<char_t, char_traits_t, allocator_t>(il) {}
    immutable_basic_string(std::initializer_list<char_t> il, const allocator_t& a)  : std::basic_string<char_t, char_traits_t, allocator_t>(il, a) {}

    template<class T>
    immutable_basic_string(const T& t, const allocator_t& a = allocator_t()) : std::basic_string<char_t, char_traits_t, allocator_t>(t, a) {}

    template<class T>
    immutable_basic_string(const T& t, size_t pos, size_t n, const allocator_t& a = allocator_t()) : std::basic_string<char_t, char_traits_t, allocator_t>(t, pos, n, a) {}

    ~immutable_basic_string() {}
    
    const char_t& at(size_t pos) {return this->std::basic_string<char_t, char_traits_t, allocator_t>::at(pos);}
    const char_t& at(size_t pos) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::at(pos);}
    
    const char_t& operator[](size_t pos) {return this->std::basic_string<char_t, char_traits_t, allocator_t>::operator[](pos);}
    const char_t& operator[](size_t pos) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::operator[](pos);}

    const char_t& front() {return this->std::basic_string<char_t, char_traits_t, allocator_t>::front();}
    const char_t& front() const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::front();}
    
    const char_t& back() {return this->std::basic_string<char_t, char_traits_t, allocator_t>::back();}
    const char_t& back() const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::back();}
    
    const char_t* data() {return this->std::basic_string<char_t, char_traits_t, allocator_t>::data();}
    const char_t* data() const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::data();}
    
    const char_t* c_str() {return this->std::basic_string<char_t, char_traits_t, allocator_t>::c_str();}
    const char_t* c_str() const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::c_str();}

    const_iterator begin() {return this->std::basic_string<char_t, char_traits_t, allocator_t>::begin();}
    const_iterator begin() const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::begin();}
    const_iterator cbegin() const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::cbegin();}
    
    const_iterator end() {return this->std::basic_string<char_t, char_traits_t, allocator_t>::end();}
    const_iterator end() const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::end();}
    const_iterator cend() const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::cend();}
    
    const_iterator rbegin() {this->std::basic_string<char_t, char_traits_t, allocator_t>::rbegin();}
    const_iterator rbegin() const {this->std::basic_string<char_t, char_traits_t, allocator_t>::rbegin();}
    const_iterator crbegin() const {this->std::basic_string<char_t, char_traits_t, allocator_t>::crbegin();}
    
    const_iterator rend() {this->std::basic_string<char_t, char_traits_t, allocator_t>::rend();}
    const_iterator rend() const {this->std::basic_string<char_t, char_traits_t, allocator_t>::rend();}
    const_iterator crend() const {this->std::basic_string<char_t, char_traits_t, allocator_t>::crend();}

    immutable_basic_string operator=(const immutable_basic_string& str) {return this->std::basic_string<char_t, char_traits_t, allocator_t>::assign(str);}
    immutable_basic_string operator=(char_t ch) {return this->std::basic_string<char_t, char_traits_t, allocator_t>::assign(ch);}
    immutable_basic_string operator=(const char* str) {return this->std::basic_string<char_t, char_traits_t, allocator_t>::assign(str);}
    immutable_basic_string operator=(const std::initializer_list<char_t>& il) {return this->std::basic_string<char_t, char_traits_t, allocator_t>::assign(il);}
    template<typename T>
    immutable_basic_string operator=(const T& t) {return this->std::basic_string<char_t, char_traits_t, allocator_t>::assign(t);}

    /*
    immutable_basic_string operator+(const immutable_basic_string& str) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+(str);;}
    immutable_basic_string operator+(char_t ch) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+(ch);}
    immutable_basic_string operator+(const char_t* str) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+(str);}
    immutable_basic_string operator+(const std::initializer_list<char_t>& il) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+(il);}
    template<typename T>
    immutable_basic_string operator+(const T& t) const {this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+=(t); return *this;}

    immutable_basic_string& operator+=(const immutable_basic_string& str) {this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+=(str); return *this;}
    immutable_basic_string& operator+=(char_t ch) {this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+=(ch); return *this;}
    immutable_basic_string& operator+=(const char_t* str) {this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+=(str); return *this;}
    immutable_basic_string& operator+=(const std::initializer_list<char_t>& il) {this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+=(il); return *this;}
    template<typename T>
    immutable_basic_string& operator+=(const T& t) {this->std::basic_string<char_t, char_traits_t, allocator_t>::operator+=(t); return *this;}
     */
    
    int compare(const immutable_basic_string& str) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::compare(str);}
    int compare(size_type pos1, size_type count1, const immutable_basic_string& str, size_type pos2, size_type count2 = npos) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::compare(pos1, count1, str, pos2, count2);}
    int compare(const char_t* str) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::compare(str);}
    int compare(size_type pos1, size_type count1, const char_t* str) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::compare(pos1, count1, str);}
    int compare(size_type pos1, size_type count1, const char_t* str, size_type count2) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::compare(pos1, count1, str, count2);}
    template < class T >
    int compare(const T& t) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::compare(t);}
    template < class T >
    int compare(size_type pos1, size_type count1, const T& t) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::compare(pos1, count1, t);}
    template < class T >
    int compare(size_type pos1, size_type count1, const T& t, size_type pos2, size_type count2 = npos) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::compare(pos1, count1, t, pos2, count2);}

    immutable_basic_string substr(size_type pos = 0, size_type count = npos) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::substr(pos, count);}
    static const size_type npos = -1;
    
    size_type copy(char_t* dest, size_type count, size_type pos = 0) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::copy(dest, count, pos);}
    void swap(immutable_basic_string& other) noexcept {this->std::basic_string<char_t, char_traits_t, allocator_t>::swap(other);}
    
    size_type find(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find(str, pos);}
    size_type find(const char_t* str, size_type pos, size_type count) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find(str, pos, count);}
    size_type find(const char_t* str, size_type pos = 0) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find(str, pos);}
    size_type find(char_t ch, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find(ch, pos);}
    template < class T >
    size_type find(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find(t, pos);}
    
    size_type rfind(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::rfind(str, pos);}
    size_type rfind(const char_t* str, size_type pos, size_type count) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::rfind(str, pos, count);}
    size_type rfind(const char_t* str, size_type pos = 0) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::rfind(str, pos);}
    size_type rfind(char_t ch, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::rfind(ch, pos);}
    template < class T >
    size_type rfind(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::rfind(t, pos);}

    size_type find_first_of(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_of(str, pos);}
    size_type find_first_of(const char_t* str, size_type pos, size_type count) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_of(str, pos, count);}
    size_type find_first_of(const char_t* str, size_type pos = 0) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_of(str, pos);}
    size_type find_first_of(char_t ch, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_of(ch, pos);}
    template<typename T>
    size_type find_first_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_of(t, pos);}
    
    size_type find_first_not_of(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_not_of(str, pos);}
    size_type find_first_not_of(const char_t* str, size_type pos, size_type count) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_not_of(str, pos, count);}
    size_type find_first_not_of(const char_t* str, size_type pos = 0) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_not_of(str, pos);}
    size_type find_first_not_of(char_t ch, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_not_of(ch, pos);}
    template<typename T>
    size_type find_first_not_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_first_not_of(t, pos);}

    size_type find_last_of(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_of(str, pos);}
    size_type find_last_of(const char_t* str, size_type pos, size_type count) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_of(str, pos, count);}
    size_type find_last_of(const char_t* str, size_type pos = 0) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_of(str, pos);}
    size_type find_last_of(char_t ch, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_of(ch, pos);}
    template<typename T>
    size_type find_last_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_of(t, pos);}
    
    size_type find_last_not_of(const immutable_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_not_of(str, pos);}
    size_type find_last_not_of(const char_t* str, size_type pos, size_type count) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_not_of(str, pos, count);}
    size_type find_last_not_of(const char_t* str, size_type pos = 0) const {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_not_of(str, pos);}
    size_type find_last_not_of(char_t ch, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_not_of(ch, pos);}
    template<typename T>
    size_type find_last_not_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char_t, char_traits_t, allocator_t>::find_last_not_of(t, pos);}

    friend std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const immutable_basic_string<char_t, char_traits_t, allocator_t>& str) {return os << ((const std::basic_string<char_t, char_traits_t, allocator_t>&)str);}
    friend std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, immutable_basic_string<char_t, char_traits_t, allocator_t>& str) {return os << ((std::basic_string<char_t, char_traits_t, allocator_t>&)str);}
    /// @endcond

  private:
    immutable_basic_string& assign(size_t count, char_t ch );
    void reserve(size_type new_cap);
    void shrink_to_fit();
    void clear();
    immutable_basic_string& insert(size_type index, size_type count, char_t ch);
    immutable_basic_string& erase(size_type index = 0, size_type count = npos);
    void push_back(char_t ch);
    void pop_back();
    immutable_basic_string& append(size_type count, char_t ch);
    immutable_basic_string& replace(size_type pos, size_type count, const immutable_basic_string& str);
    void resize(size_type count);
  };
  
  namespace string_literals {
    inline std::basic_string<char> operator "" _is( const char* str, size_t len ) {
      return std::basic_string<char>(str, len);
    }
    
    inline std::basic_string<wchar_t> operator "" _is( const wchar_t* str, size_t len ) {
      return std::basic_string<wchar_t>(str, len);
    }
    
    inline std::basic_string<char16_t> operator "" _is( const char16_t* str, size_t len ) {
      return std::basic_string<char16_t>(str, len);
    }
    
    inline std::basic_string<char32_t> operator "" _is( const char32_t* str, size_t len ) {
      return std::basic_string<char32_t>(str, len);
    }
  }

  /// @brief Immutable string<char_t>
  /// @remarks It can be replaced by const std::string<char_t>.
  using istring = immutable_basic_string<char, std::char_traits<char>>;

  /// @brief Immutable u16string<char_t>
  /// @remarks It can be replaced by const std::u16string<char_t>.
  using iu16string = immutable_basic_string<char16_t, std::char_traits<char16_t>>;

  /// @brief Immutable u32string<char_t>
  /// @remarks It can be replaced by const std::u32string<char_t>.
  using iu32string = immutable_basic_string<char32_t, std::char_traits<char32_t>>;

  /// @brief Immutable wstring<char_t>
  /// @remarks It can be replaced by const std::wstring<char_t>.
  using iwstring = immutable_basic_string<wchar_t, std::char_traits<wchar_t>>;
}
