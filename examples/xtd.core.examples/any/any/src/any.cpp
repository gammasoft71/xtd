#include <xtd/xtd>

struct foo1 {
  int value = 0;
};

auto operator <<(std::ostream& os, const foo1& f) noexcept -> std::ostream& {return os << f.value;}

struct foo2 {
  int value = 0;
};

template<>
auto xtd::to_string(const foo2& value, const string& fmt, const std::locale& loc) -> string {return int32_object {value.value}.to_string(fmt, loc);}

struct foo3 : public istringable<foo3> {
  explicit foo3(int v) : value {v} {}
  auto to_string() const noexcept -> string override {return string::format("{}", value);}
  int value = 0;
};

auto main() -> int {
  auto a = any_object {};
  a = "gammasoft";
  if (is<string>(a)) console::write_line("a = {} => {} ({})", a, as<string>(a).to_title_case(), type_of(as<string>(a)));
  a = date_time {1971, 1, 5};
  if (is<date_time>(a)) console::write_line("a = {} => {} ({})", a, as<date_time>(a).to_short_date_string(), type_of(as<date_time>(a)));
  a = 42;
  if (is<int32>(a)) console::write_line("a = {} => {} ({})", a, as<int32>(a), type_of(as<int32>(a)));
  a = .42;
  if (is<double>(a)) console::write_line("a = {} => {} ({})", a, as<double>(a), type_of(as<double>(a)));
  a = foo1 {42};
  if (is<foo1>(a)) console::write_line("a = {} => {} ({})", a, as<foo1>(a), type_of(as<foo1>(a)));
  a = foo2 {42};
  if (is<foo2>(a)) console::write_line("a = {} => {} ({})", a, as<foo2>(a), type_of(as<foo2>(a)));
  a = foo3 {42};
  if (is<foo3>(a)) console::write_line("a = {} => {} ({})", a, as<foo3>(a), type_of(as<foo3>(a)));
  a = day_of_week::wednesday;
  if (is<day_of_week>(a)) console::write_line("a = {} => {} ({})", a, as<day_of_week>(a), type_of(as<day_of_week>(a)));
}

// This code produces the following output :
//
// a = gammasoft => Gammasoft (xtd::string)
// a = 1/5/1971 0:00:00 AM => 1/5/1971 (xtd::date_time)
// a = 42 => 42 (int)
// a = 0.42 => 0.42 (double)
// a = 42 => 42 (foo1)
// a = 42 => 42 (foo2)
// a = 42 => 42 (foo3)
// a = wednesday => wednesday (xtd::day_of_week)
