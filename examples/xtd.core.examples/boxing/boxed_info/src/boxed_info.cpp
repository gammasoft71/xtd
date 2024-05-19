#include <xtd/boxing>
#include <xtd/console>
#include <xtd/date_time>
#include <xtd/day_of_week>
#include <xtd/typeof>

using namespace xtd;

class foo {
public:
  foo() = default;
  foo(int value) : value_(value) {}
  
  int value() const noexcept {return value_;}
  
  // For boxing a struct, it must implements oprtat = and operator <.
  // Or the struct must xtd::inherites from icomparable and xtd::iequatble interfaces.
  bool operator ==(const foo& v) const noexcept {return value_ == v.value_;}
  bool operator <(const foo& v) const noexcept {return value_ < v.value_;}
  
private:
  int value_ = 0;
};

template<typename type_t>
ustring get_boxed_info(const type_t& value) {
  auto boxed_value = boxing(value);
  return ustring::format("[type = {}, boxed type = {}, value = {}]", typeof_(value), typeof_(boxed_value), boxed_value.to_string());
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

// This code can produces the following output:
//
// [type = int, boxed type = xtd::box_integer<int>, value = 42]
// [type = double, boxed type = xtd::box_floating_point<double>, value = 42.84]
// [type = bool, boxed type = xtd::box<bool>, value = true]
// [type = xtd::day_of_week, boxed type = xtd::enum_object<xtd::day_of_week>, value = saturday]
// [type = char [9], boxed type = xtd::ustring, value = A string]
// [type = char32_t [13], boxed type = xtd::ustring, value = A u32 string]
// [type = xtd::date_time, boxed type = xtd::date_time, value = Thu Dec  1 20:00:57 2022]
// [type = foo, boxed type = xtd::box<foo>, value = (unregistered)]

