#include <xtd/xtd>

using namespace xtd::globalization;

class persona : public iformatable {
public:
  persona() = default;
  persona(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  auto name() const noexcept -> const string& {return name_;}
  auto rank() const noexcept -> const string& {return rank_;}
  
  auto to_string() const noexcept -> string {return to_string("", culture_info::current_culture());}
  auto to_string(const string& format, const culture_info& culture) const -> string override {
    auto fmt = string::is_empty(format) ? "F" : format;
    if (fmt == "F") return name_ + " (" + rank_ + ")";
    if (fmt == "N") return name_;
    if (fmt == "R") return rank_;
    throw format_exception {xtd::format("The \"{}\" value is not valid format.", fmt)};
  }
  
private:
  string name_;
  string rank_;
};

auto main() -> int {
  try {
    auto char1 = ::persona {"Jean-Luc Picard", "Captain"};
    println("1 : {}", char1);
    println("2 : {:N}", char1);
    println("2 : {:B}", char1);
  } catch (const exception& e) {
    println(e);
  }
}

// This code can produce the following output :
//
// 1 : Jean-Luc Picard (Captain)
// 2 : Jean-Luc Picard
// xtd::format_exception : The "B" value is not valid format.
//    at xtd::format_exception::format_exception(std::__1::optional<xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>> const&, xtd::diagnostics::stack_frame const&) in format_exception.cpp:line 10
//    at persona::to_string(xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&, xtd::globalization::culture_info const&) const in format_exception.cpp:line 19
//    at __to_string_iformatable_to_string(xtd::iformatable const*, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&, std::__1::locale const&) in __iformatable_formatter.cpp:line 10
//    at xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> xtd::to_string<persona>(persona const&, xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&, std::__1::locale const&) in to_string_.hpp:line 21
//    at void __basic_string_extract_format_arg<persona&>(std::__1::locale const&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>&, unsigned long&, std::__1::vector<__format_information<char>, std::__1::allocator<__format_information<char>>>&, persona&) in basic_string_.hpp:line 387
//    at void __basic_string_extract_format_arg<persona&>(std::__1::locale const&, xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>&, std::__1::vector<__format_information<char>, std::__1::allocator<__format_information<char>>>&, persona&) in basic_string_.hpp:line 411
//    at xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::format<persona&>(std::__1::locale const&, xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&, persona&) in basic_string_.hpp:line 348
//    at xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::format<persona&>(xtd::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&, persona&) in basic_string_.hpp:line 276
//    at void xtd::println<persona&>(__sFILE*, char const*, persona&) in println.hpp:line 50
//    at void xtd::println<persona&>(char const*, persona&) in println.hpp:line 191
//    at main in format_exception.cpp:line 32
