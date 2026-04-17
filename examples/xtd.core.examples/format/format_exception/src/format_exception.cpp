#include <xtd/xtd>

using namespace xtd::globalization;

class persona : public iformatable {
public:
  persona() = default;
  persona(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}
  
  string to_string() const noexcept {return to_string("", culture_info::current_culture());}
  string to_string(const string& format, const culture_info& culture) const override {
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
//    at persona::to_string(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::locale const&) const in /Users/gammasoft/Projects/xtd/examples/xtd.core.examples/format/format_exception/src/format_exception.cpp:line 22
//    at xtd::iformatable::__opague_internal_formatable__(long, long, long, long) const in iformatable.cpp:line 7
//    at void __basic_string_extract_format_arg<persona&>(std::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&,xtd::array<__format_information<char>, std::allocator<__format_information<char>>>&, persona&) in basic_string_.hpp:line 365
//    at void __basic_string_extract_format_arg<persona&>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>&, xtd::array<__format_information<char>, std::allocator<__format_information<char>>>&, persona&) in basic_string_.hpp:line 387
//    at xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>::format<persona&>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, persona&) in basic_string_.hpp:line 328
//    at void xtd::println<persona&>(char const*, persona&) in println.hpp:line 34
//    at main in format_exception.cpp:line 34
