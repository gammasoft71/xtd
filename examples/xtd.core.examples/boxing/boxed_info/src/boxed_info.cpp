#include <xtd/xtd>

// To box a structure or class, it must inherit the xtd::icomparable, and xtd::iequatable interfaces, or implements `<`, `>` and `==` operators.

struct foo1 : icomparable<foo1>, iequatable<foo1>, istringable {
  foo1() = default;
  explicit foo1(int value) : value {value} {}
  
  int value = 0;
  
  auto compare_to(const foo1& other) const noexcept -> int32 override {return value - other.value;}
  auto equals(const foo1& other) const noexcept -> bool override {return value == other.value;}
  auto to_string() const noexcept -> string override {return string::format("{}", value);}
};

struct foo2 {
  int value = 0;
  
  auto operator <(const foo2& other) const noexcept -> bool {return value < other.value;}
  auto operator >(const foo2& other) const noexcept -> bool {return value > other.value;}
  auto operator ==(const foo2& other) const noexcept -> bool {return value == other.value;}
  friend auto operator <<(std::ostream& os, const foo2& value) -> std::ostream& {return os << string::format("{}", value.value);}
};

template<typename type_t>
auto get_boxed_info(const type_t& value) -> string {
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
  console::write_line(get_boxed_info(foo1 {42}));
  console::write_line(get_boxed_info(foo2 {.value = 42}));
}

// This code produces the following output :
//
// [type = int, boxed type = xtd::box_integer<int>, value = 42]
// [type = double, boxed type = xtd::box_floating_point<double>, value = 42.84]
// [type = bool, boxed type = xtd::box<bool>, value = true]
// [type = xtd::day_of_week, boxed type = xtd::enum_object<xtd::day_of_week>, value = saturday]
// [type = char [9], boxed type = xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>, value = A string]
// [type = char32_t [13], boxed type = xtd::basic_string<char, std::char_traits<char>, std::allocator<char>>, value = A u32 string]
// [type = xtd::date_time, boxed type = xtd::date_time, value = Thu Dec  1 20:00:57 2022]
// [type = foo1, boxed type = xtd::box<foo1>, value = 42]
// [type = foo2, boxed type = xtd::box<foo2>, value = 42]
