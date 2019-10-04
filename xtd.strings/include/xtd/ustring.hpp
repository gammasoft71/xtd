/// @file
/// @brief Contains xtd::universal_basic_string class.
#pragma once

#include <codecvt>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Immutable basic_string<char>
  template<class char_traits_t = std::char_traits<char>, class allocator_t = std::allocator<char>>
  class universal_basic_string : public std::basic_string<char, char_traits_t, allocator_t> {
  public:
    /// @cond
    using __self = universal_basic_string;
    using __self_view = std::basic_string_view<char, char_traits_t>;
    using traits_type = char_traits_t;
    using value_type = char;
    using allocator_type = allocator_t;
    using __alloc_traits = std::allocator_traits<allocator_type>;
    using size_type = typename __alloc_traits::size_type;
    using difference_type = typename __alloc_traits::difference_type;
    using reference = value_type&;
    using const_reference =  const value_type&;
    using pointer = typename __alloc_traits::pointer;
    using const_pointer = typename __alloc_traits::const_pointer;
    using iterator = typename std::basic_string<char, char_traits_t, allocator_t>::iterator;
    using const_iterator = typename std::basic_string<char, char_traits_t, allocator_t>::const_iterator;
    using reverse_iterator = typename std::basic_string<char, char_traits_t, allocator_t>::reverse_iterator;
    using const_reverse_iterator = typename std::basic_string<char, char_traits_t, allocator_t>::reverse_iterator;

    universal_basic_string() noexcept {}
    explicit universal_basic_string(const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(a) {}

    universal_basic_string(size_t n, char c)  : std::basic_string<char, char_traits_t, allocator_t>(n, c) {}
    universal_basic_string(size_t n, char c, const allocator_t& a)  : std::basic_string<char, char_traits_t, allocator_t>(n, c, a) {}

    universal_basic_string(const universal_basic_string& str, size_t pos, size_t n, const allocator_t& a = allocator_t()) : std::basic_string<char, char_traits_t, allocator_t>(str, pos, n, a) {}
    universal_basic_string(const universal_basic_string& str, size_t pos, const allocator_t& a = allocator_t()) : std::basic_string<char, char_traits_t, allocator_t>(str, pos, a) {}

    universal_basic_string(const char* str, size_t n) : std::basic_string<char, char_traits_t, allocator_t>(str, n) {}
    universal_basic_string(const char* str, size_t n, const allocator_t& a) : std::basic_string<char, char_traits_t, allocator_t>(str, n, a) {}
    
    universal_basic_string(const char* str) : std::basic_string<char, char_traits_t, allocator_t>(str) {}
    universal_basic_string(const char* str, const allocator_t& a) : std::basic_string<char, char_traits_t, allocator_t>(str, a) {}

    template<class InputIterator>
    universal_basic_string(InputIterator first, InputIterator last) : std::basic_string<char, char_traits_t, allocator_t>(first, last) {}
    template<class InputIterator>
    universal_basic_string(InputIterator first, InputIterator last, const allocator_t& a) : std::basic_string<char, char_traits_t, allocator_t>(first, last, a) {}

    universal_basic_string(const universal_basic_string& str) noexcept : std::basic_string<char, char_traits_t, allocator_t>(str) {}
    universal_basic_string(const universal_basic_string& str, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(str, a) {}

    universal_basic_string(universal_basic_string&& str) noexcept : std::basic_string<char, char_traits_t, allocator_t>(str)  {}
    universal_basic_string(universal_basic_string&& str, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(str, a) {}

    universal_basic_string(std::initializer_list<char> il) : std::basic_string<char, char_traits_t, allocator_t>(il) {}
    universal_basic_string(std::initializer_list<char> il, const allocator_t& a) : std::basic_string<char, char_traits_t, allocator_t>(il, a) {}

    universal_basic_string(const std::string& str) noexcept : std::basic_string<char, char_traits_t, allocator_t>(str) {}
    universal_basic_string(const std::string& str, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(str, a) {}
    
    universal_basic_string(const std::wstring& str) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(str.c_str())) {}
    universal_basic_string(const std::wstring& str, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(str.c_str()), a) {}
    
    universal_basic_string(const wchar_t* str) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(str)) {}
    universal_basic_string(const wchar_t* str, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(str), a) {}
    
#pragma warning(push)
#pragma warning(suppress:4996)
    universal_basic_string(const wchar_t* str, size_t n) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(str), n) {}
    universal_basic_string(const wchar_t* str, size_t n, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(str), n, a) {}
#pragma warning(pop)

    universal_basic_string(std::initializer_list<wchar_t> il) : universal_basic_string(std::wstring(il)) {}
    universal_basic_string(std::initializer_list<wchar_t> il, const allocator_t& a) : universal_basic_string(std::wstring(il), a) {}

    universal_basic_string(const std::u16string& str) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t>().to_bytes(str.c_str())) {}
    universal_basic_string(const std::u16string& str, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t>().to_bytes(str.c_str()), a) {}
    
    universal_basic_string(const char16_t* str) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char16_t>,char16_t>().to_bytes(str)) {}
    universal_basic_string(const char16_t* str, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t>().to_bytes(str), a) {}
    
#pragma warning(push)
#pragma warning(suppress:4996)
    universal_basic_string(const char16_t* str, size_t n) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char16_t>,char16_t>().to_bytes(str), n) {}
    universal_basic_string(const char16_t* str, size_t n, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t>().to_bytes(str), n, a) {}
#pragma warning(pop)

    universal_basic_string(std::initializer_list<char16_t> il) : universal_basic_string(std::u16string(il)) {}
    universal_basic_string(std::initializer_list<char16_t> il, const allocator_t& a) : universal_basic_string(std::u16string(il), a) {}

    universal_basic_string(const std::u32string& str) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>().to_bytes(str.c_str())) {}
    universal_basic_string(const std::u32string& str, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>().to_bytes(str.c_str()), a) {}
    
    universal_basic_string(const char32_t* str) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t>().to_bytes(str)) {}
    universal_basic_string(const char32_t* str, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>().to_bytes(str), a) {}
    
#pragma warning(push)
#pragma warning(suppress:4996)
    universal_basic_string(const char32_t* str, size_t n) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char32_t>,char32_t>().to_bytes(str), n) {}
    universal_basic_string(const char32_t* str, size_t n, const allocator_t& a) noexcept : std::basic_string<char, char_traits_t, allocator_t>(std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>().to_bytes(str), n, a) {}
#pragma warning(pop)

    universal_basic_string(std::initializer_list<char32_t> il) : universal_basic_string(std::u32string(il)) {}
    universal_basic_string(std::initializer_list<char32_t> il, const allocator_t& a) : universal_basic_string(std::u32string(il), a) {}

    template<class T>
    universal_basic_string(const T& t, const allocator_t& a = allocator_t()) : std::basic_string<char, char_traits_t, allocator_t>(t, a) {}

    template<class T>
    universal_basic_string(const T& t, size_t pos, size_t n, const allocator_t& a = allocator_t()) : std::basic_string<char, char_traits_t, allocator_t>(t, pos, n, a) {}

    ~universal_basic_string() {}
    
    const char& at(size_t pos) {return this->std::basic_string<char, char_traits_t, allocator_t>::at(pos);}
    const char& at(size_t pos) const {return this->std::basic_string<char, char_traits_t, allocator_t>::at(pos);}
    
    const char& operator[](size_t pos) {return this->std::basic_string<char, char_traits_t, allocator_t>::operator[](pos);}
    const char& operator[](size_t pos) const {return this->std::basic_string<char, char_traits_t, allocator_t>::operator[](pos);}

    const char& front() {this->std::basic_string<char, char_traits_t, allocator_t>::front();}
    const char& front() const {this->std::basic_string<char, char_traits_t, allocator_t>::front();}
    
    const char& back() {this->std::basic_string<char, char_traits_t, allocator_t>::back();}
    const char& back() const {this->std::basic_string<char, char_traits_t, allocator_t>::back();}
    
    const char* data() {this->std::basic_string<char, char_traits_t, allocator_t>::data();}
    const char* data() const {this->std::basic_string<char, char_traits_t, allocator_t>::data();}
    
    const char* c_str() {return this->std::basic_string<char, char_traits_t, allocator_t>::c_str();}
    const char* c_str() const {return this->std::basic_string<char, char_traits_t, allocator_t>::c_str();}

    const wchar_t* wc_str() {return std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().from_bytes(this->c_str()).c_str();}
    const wchar_t* wc_str() const {return std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().from_bytes(this->c_str()).c_str();}

    const_iterator begin() {return this->std::basic_string<char, char_traits_t, allocator_t>::begin();}
    const_iterator begin() const {return this->std::basic_string<char, char_traits_t, allocator_t>::begin();}
    const_iterator cbegin() const {return this->std::basic_string<char, char_traits_t, allocator_t>::cbegin();}
    
    const_iterator end() {return this->std::basic_string<char, char_traits_t, allocator_t>::end();}
    const_iterator end() const {return this->std::basic_string<char, char_traits_t, allocator_t>::end();}
    const_iterator cend() const {return this->std::basic_string<char, char_traits_t, allocator_t>::cend();}
    
    const_iterator rbegin() {this->std::basic_string<char, char_traits_t, allocator_t>::rbegin();}
    const_iterator rbegin() const {this->std::basic_string<char, char_traits_t, allocator_t>::rbegin();}
    const_iterator crbegin() const {this->std::basic_string<char, char_traits_t, allocator_t>::crbegin();}
    
    const_iterator rend() {this->std::basic_string<char, char_traits_t, allocator_t>::rend();}
    const_iterator rend() const {this->std::basic_string<char, char_traits_t, allocator_t>::rend();}
    const_iterator crend() const {this->std::basic_string<char, char_traits_t, allocator_t>::crend();}

    universal_basic_string operator=(const universal_basic_string& str) {return this->std::basic_string<char, char_traits_t, allocator_t>::assign(str);}
    universal_basic_string operator=(char ch) {return this->std::basic_string<char, char_traits_t, allocator_t>::assign(ch);}
    universal_basic_string operator=(const char* str) {return this->std::basic_string<char, char_traits_t, allocator_t>::assign(str);}
    universal_basic_string operator=(const std::initializer_list<char>& il) {return this->std::basic_string<char, char_traits_t, allocator_t>::assign(il);}
    template<typename T>
    universal_basic_string operator=(const T& t) {return this->std::basic_string<char, char_traits_t, allocator_t>::assign(t);}

    universal_basic_string operator+(const universal_basic_string& str) const {return this->std::basic_string<char, char_traits_t, allocator_t>::operator+(str);;}
    universal_basic_string operator+(char ch) const {return this->std::basic_string<char, char_traits_t, allocator_t>::operator+(ch);}
    universal_basic_string operator+(const char* str) const {return this->std::basic_string<char, char_traits_t, allocator_t>::operator+(str);}
    universal_basic_string operator+(const std::initializer_list<char>& il) const {return this->std::basic_string<char, char_traits_t, allocator_t>::operator+(il);}
    template<typename T>
    universal_basic_string operator+(const T& t) const {this->std::basic_string<char, char_traits_t, allocator_t>::operator+=(t); return *this;}

    universal_basic_string& operator+=(const universal_basic_string& str) {this->std::basic_string<char, char_traits_t, allocator_t>::operator+=(str); return *this;}
    universal_basic_string& operator+=(char ch) {this->std::basic_string<char, char_traits_t, allocator_t>::operator+=(ch); return *this;}
    universal_basic_string& operator+=(const char* str) {this->std::basic_string<char, char_traits_t, allocator_t>::operator+=(str); return *this;}
    universal_basic_string& operator+=(const std::initializer_list<char>& il) {this->std::basic_string<char, char_traits_t, allocator_t>::operator+=(il); return *this;}
    template<typename T>
    universal_basic_string& operator+=(const T& t) {this->std::basic_string<char, char_traits_t, allocator_t>::operator+=(t); return *this;}
    
    int compare(const universal_basic_string& str) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::compare(str);}
    int compare(size_type pos1, size_type count1, const universal_basic_string& str, size_type pos2, size_type count2 = npos) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::compare(pos1, count1, str, pos2, count2);}
    int compare(const char* str) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::compare(str);}
    int compare(size_type pos1, size_type count1, const char* str) const {return this->std::basic_string<char, char_traits_t, allocator_t>::compare(pos1, count1, str);}
    int compare(size_type pos1, size_type count1, const char* str, size_type count2) const {return this->std::basic_string<char, char_traits_t, allocator_t>::compare(pos1, count1, str, count2);}
    template < class T >
    int compare(const T& t) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::compare(t);}
    template < class T >
    int compare(size_type pos1, size_type count1, const T& t) const {return this->std::basic_string<char, char_traits_t, allocator_t>::compare(pos1, count1, t);}
    template < class T >
    int compare(size_type pos1, size_type count1, const T& t, size_type pos2, size_type count2 = npos) const {return this->std::basic_string<char, char_traits_t, allocator_t>::compare(pos1, count1, t, pos2, count2);}

    universal_basic_string substr(size_type pos = 0, size_type count = npos) const {return this->std::basic_string<char, char_traits_t, allocator_t>::substr(pos, count);}
    static const size_type npos = -1;
    
    size_type copy(char* dest, size_type count, size_type pos = 0) const {return this->std::basic_string<char, char_traits_t, allocator_t>::copy(dest, count, pos);}
    void swap(universal_basic_string& other) noexcept {this->std::basic_string<char, char_traits_t, allocator_t>::swap(other);}
    
    size_type find(const universal_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find(str, pos);}
    size_type find(const char* str, size_type pos, size_type count) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find(str, pos, count);}
    size_type find(const char* str, size_type pos = 0) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find(str, pos);}
    size_type find(char ch, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find(ch, pos);}
    template < class T >
    size_type find(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find(t, pos);}
    
    size_type rfind(const universal_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::rfind(str, pos);}
    size_type rfind(const char* str, size_type pos, size_type count) const {return this->std::basic_string<char, char_traits_t, allocator_t>::rfind(str, pos, count);}
    size_type rfind(const char* str, size_type pos = 0) const {return this->std::basic_string<char, char_traits_t, allocator_t>::rfind(str, pos);}
    size_type rfind(char ch, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::rfind(ch, pos);}
    template < class T >
    size_type rfind(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::rfind(t, pos);}

    size_type find_first_of(const universal_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_of(str, pos);}
    size_type find_first_of(const char* str, size_type pos, size_type count) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_of(str, pos, count);}
    size_type find_first_of(const char* str, size_type pos = 0) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_of(str, pos);}
    size_type find_first_of(char ch, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_of(ch, pos);}
    template<typename T>
    size_type find_first_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_of(t, pos);}
    
    size_type find_first_not_of(const universal_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_not_of(str, pos);}
    size_type find_first_not_of(const char* str, size_type pos, size_type count) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_not_of(str, pos, count);}
    size_type find_first_not_of(const char* str, size_type pos = 0) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_not_of(str, pos);}
    size_type find_first_not_of(char ch, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_not_of(ch, pos);}
    template<typename T>
    size_type find_first_not_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_first_not_of(t, pos);}

    size_type find_last_of(const universal_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_of(str, pos);}
    size_type find_last_of(const char* str, size_type pos, size_type count) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_of(str, pos, count);}
    size_type find_last_of(const char* str, size_type pos = 0) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_of(str, pos);}
    size_type find_last_of(char ch, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_of(ch, pos);}
    template<typename T>
    size_type find_last_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_of(t, pos);}
    
    size_type find_last_not_of(const universal_basic_string& str, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_not_of(str, pos);}
    size_type find_last_not_of(const char* str, size_type pos, size_type count) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_not_of(str, pos, count);}
    size_type find_last_not_of(const char* str, size_type pos = 0) const {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_not_of(str, pos);}
    size_type find_last_not_of(char ch, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_not_of(ch, pos);}
    template<typename T>
    size_type find_last_not_of(const T& t, size_type pos = 0) const noexcept {return this->std::basic_string<char, char_traits_t, allocator_t>::find_last_not_of(t, pos);}

    friend std::basic_ostream<char, char_traits_t>& operator<<(std::basic_ostream<char, char_traits_t>& os, const universal_basic_string<char_traits_t, allocator_t>& str) {return os << ((const std::basic_string<char, char_traits_t, allocator_t>&)str);}
    friend std::basic_ostream<char, char_traits_t>& operator<<(std::basic_ostream<char, char_traits_t>& os, universal_basic_string<char_traits_t, allocator_t>& str) {return os << ((std::basic_string<char, char_traits_t, allocator_t>&)str);}
    /// @endcond

  private:
    universal_basic_string& assign(size_t count, char ch );
    void reserve(size_type new_cap);
    void shrink_to_fit();
    void clear();
    universal_basic_string& insert(size_type index, size_type count, char ch);
    universal_basic_string& erase(size_type index = 0, size_type count = npos);
    void push_back(char ch);
    void pop_back();
    universal_basic_string& append(size_type count, char ch);
    universal_basic_string& replace(size_type pos, size_type count, const universal_basic_string& str);
    void resize(size_type count);
  };


  /// @brief universal string<char>
  /// @remarks It can be replaced by const std::string<char>.
  using ustring = universal_basic_string<std::char_traits<char>>;

  namespace string_literals {
    inline std::basic_string<char> operator "" _s( const char* str, size_t len ) {
      return std::basic_string<char>(str, len);
    }
    
    inline std::basic_string<wchar_t> operator "" _s( const wchar_t* str, size_t len ) {
      return std::basic_string<wchar_t>(str, len);
    }
    
    inline std::basic_string<char16_t> operator "" _s( const char16_t* str, size_t len ) {
      return std::basic_string<char16_t>(str, len);
    }
    
    inline std::basic_string<char32_t> operator "" _s( const char32_t* str, size_t len ) {
      return std::basic_string<char32_t>(str, len);
    }

    inline ustring operator "" _us( const char* str, size_t len ) {
      return ustring(str, len);
    }
    
    inline ustring operator "" _us( const wchar_t* str, size_t len ) {
      return ustring(str, len);
    }
    
    inline ustring operator "" _us( const char16_t* str, size_t len ) {
      return ustring(str, len);
    }
    
    inline ustring operator "" _us( const char32_t* str, size_t len ) {
      return ustring(str, len);
    }
  }
}
