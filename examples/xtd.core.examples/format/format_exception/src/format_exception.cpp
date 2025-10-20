#include <xtd/xtd>

using namespace xtd::globalization;

class character : public iformatable {
public:
  character() = default;
  character(const string& name, const string& rank) noexcept : name_(name), rank_(rank) {}
  
  const string& name() const noexcept {return name_;}
  const string& rank() const noexcept {return rank_;}
  
  string to_string() const noexcept {return to_string("", culture_info::current_culture());}
  string to_string(const string& format, const std::locale& loc) const override {
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
    auto char1 = character {"Jean-Luc Picard", "Captain"};
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
//    at character::to_string(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::locale const&) const in /Users/gammasoft/Projects/xtd/examples/xtd.core.examples/format/format_exception/src/format_exception.cpp:line 22
//    at xtd::iformatable::__opague_internal_formatable__(long, long, long, long) const in iformatable.cpp:line 7
//    at void __basic_string_extract_format_arg<character&>(std::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&,xtd::array<__format_information<char>, std::allocator<__format_information<char>>>&, character&) in basic_string_.hpp:line 365
//    at void __basic_string_extract_format_arg<character&>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>&, xtd::array<__format_information<char>, std::allocator<__format_information<char>>>&, character&) in basic_string_.hpp:line 387
//    at xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>::format<character&>(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, character&) in basic_string_.hpp:line 328
//    at void xtd::println<character&>(char const*, character&) in println.hpp:line 34
//    at main in format_exception.cpp:line 34
