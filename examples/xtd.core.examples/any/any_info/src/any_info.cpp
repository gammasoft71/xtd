#include <xtd/any_object>
#include <xtd/console>
#include <xtd/date_time>

using namespace xtd;

struct foo1 : public object, public icomparable<foo1>, public iequatable<foo1> {
  explicit foo1(int v) : value(v) {}
  int value = 0;
  
  string to_string() const noexcept override {return string::format("{}", value);}
  bool equals(const object& o) const noexcept override {return is<foo1>(o) && equals(static_cast<const foo1&>(o));}
  bool equals(const foo1& f) const noexcept override {return value == f.value;}
  int32 compare_to(const foo1& f) const noexcept override {return value < f.value ? -1 : value > f.value ? 1 : 0;}
};

struct foo2 {
  int value = 0;
  
  bool operator ==(const foo2& f) const noexcept {return value == f.value;}
  bool operator <(const foo2& f) const noexcept {return value < f.value;}
  bool operator >(const foo2& f) const noexcept {return value > f.value;}
};

template<>
std::string xtd::to_string(const foo2& value, const std::string& fmt, const std::locale& loc) {return xtd::int32_object {value.value}.to_string(fmt, loc);}

template<>
struct std::hash<foo2> {
  xtd::size operator()(const foo2& value) const noexcept {return xtd::hash_code::combine(value.value);}
};

template<typename type_t>
string get_any_info(const type_t& value) {
  auto any_value = any_object (value);
  return string::format("[value = {} ({}), any = {} ({})]", value, typeof_(value), any_value.value(), typeof_(any_value.value()));
}

auto main() -> int {
  console::write_line(get_any_info("one"));
  console::write_line(get_any_info(date_time {1971, 1, 5}));
  console::write_line(get_any_info(42));
  console::write_line(get_any_info(.42));
  console::write_line(get_any_info(foo1 {42}));
  console::write_line(get_any_info(foo2 {42}));
  console::write_line(get_any_info(day_of_week::wednesday));
}

// This code produces the following output :
//
// [value = one (char [4]), any = one (xtd::string)]
// [value = Tue Jan  5 00:00:00 1971 (xtd::date_time), any = Tue Jan  5 00:00:00 1971 (xtd::date_time)]
// [value = 42 (int), any = 42 (xtd::box_integer<int>)]
// [value = 0.42 (double), any = 0.42 (xtd::box_floating_point<double>)]
// [value = 42 (foo1), any = 42 (foo1)]
// [value = 42 (foo2), any = 42 (xtd::box<foo2>)]
// [value = wednesday (xtd::day_of_week), any = wednesday (xtd::enum_object<xtd::day_of_week>)]
