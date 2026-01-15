#include <xtd/xtd>

struct my_formatable_string : public iformatable {
  my_formatable_string(const string& value) : value {value} {}
  auto to_string(const string& format, const globalization::culture_info& culture) const noexcept -> string override {return value;}
  
  string value;
};

struct my_stringable_string : public istringable<my_stringable_string> {
  my_stringable_string(const string& value) : value {value} {}
  auto to_string() const noexcept -> string override {return value;}
  
  string value;
};

struct my_streamable_string {
  friend auto operator <<(std::ostream& os, const my_streamable_string& value) noexcept -> std::ostream& {return os << value.value;}
  
  string value;
};

struct my_object_string : public object {
  my_object_string(const string& value) : value {value} {}
  auto to_string() const noexcept -> string override {return value;}
  
  string value;
};

struct my_to_string_string {
  string value;
};

template<>
auto xtd::to_string(const my_to_string_string& value, const string& format, const std::locale& loc) -> string {
  return value.value;
}

struct my_string {
  string value;
};

template<stringable value_t>
auto log_to_console(const value_t& value) noexcept {
  console::write_line(value);
}

auto main() -> int {
  log_to_console(my_formatable_string {"my_formatable_string"});
  log_to_console(my_stringable_string {"my_stringable_string"});
  log_to_console(my_streamable_string {"my_streamable_string"});
  log_to_console(my_object_string {"my_object_string"});
  //log_to_console(my_to_string_string {"my_to_string_string"}); // Does not build
  //log_to_console(my_string {"my_string"}); // Does not build
  log_to_console(date_time::now());
  log_to_console(environment::version());
  log_to_console(day_of_week::saturday);
  log_to_console(42);
  log_to_console(std::vector {1, 2, 3, 4, 5});
  log_to_console(array {1, 2, 3, 4, 5}.select(delegate_(auto v) {return v * v;}));
  log_to_console(array {1, 2, 3, 4, 5} | std::views::transform(delegate_(auto v) {return v * v * v;}));
  log_to_console(argument_out_of_range_exception {});
}

// This code can produce the following output :
//
// my_formatable_string
// my_stringable_string
// my_streamable_string
// my_object_string
// 1/11/2026 6:33:25 PM
// 0.2.0
// saturday
// 42
// [1, 2, 3, 4, 5]
// [1, 4, 9, 16, 25]
// [1, 8, 27, 64, 125]
// xtd::argument_out_of_range_exception : Specified argument is out of range of valid values.
//    at xtd::argument_out_of_range_exception::argument_out_of_range_exception(xtd::diagnostics::stack_frame const&) in argument_out_of_range_exception.hpp:line 30
//    at main in stringable.cpp:line 62
