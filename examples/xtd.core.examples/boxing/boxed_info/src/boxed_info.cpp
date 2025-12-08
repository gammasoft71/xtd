#include <xtd/xtd>

// To box a structure or class, it must inherit the xtd::icomparable, xtd::iequatable and xtd::ihashable interfaces.
struct foo : icomparable<foo>, iequatable<foo>, ihashable, istringable {
  foo() = default;
  foo(int value) : value {value} {}
  
  int value = 0;
  
  int32 compare_to(const foo& other) const noexcept override {return value - other.value;}
  size get_hash_code() const noexcept override {return hash_code::combine(value);}
  bool equals(const foo& other) const noexcept override {return value == other.value;}
  string to_string() const noexcept override {return string::format("{}", value);}
};

namespace std {
  template<>
  struct hash<foo> {
    size_t operator()(const foo&) {return 0;}
  };
}

template<typename type_t>
string get_boxed_info(const type_t& value) {
  auto boxed_value = boxing(value);
  return string::format("[type = {}, boxed type = {}, value = {}]", typeof_(value), typeof_(boxed_value), boxed_value.to_string());
}

auto main() -> int {
  console::write_line(get_boxed_info(42));
  console::write_line(get_boxed_info(42.84));
  console::write_line(get_boxed_info(true));
  console::write_line(get_boxed_info(day_of_week::saturday));
  console::write_line(get_boxed_info("A string"));
  console::write_line(get_boxed_info(U"A u32 string"));
  console::write_line(get_boxed_info(date_time::now()));
  console::write_line(get_boxed_info(foo(42)));
}

// This code produces the following output :
//
// [type = int, boxed type = xtd::box_integer<int>, value = 42]
// [type = double, boxed type = xtd::box_floating_point<double>, value = 42.84]
// [type = bool, boxed type = xtd::box<bool>, value = true]
// [type = xtd::day_of_week, boxed type = xtd::enum_object<xtd::day_of_week>, value = saturday]
// [type = char [9], boxed type = xtd::string, value = A string]
// [type = char32_t [13], boxed type = xtd::string, value = A u32 string]
// [type = xtd::date_time, boxed type = xtd::date_time, value = Thu Dec  1 20:00:57 2022]
// [type = foo, boxed type = xtd::box<foo>, value = 42]

