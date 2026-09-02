#include <xtd/xtd>

struct foo {
  int value;
  
  auto operator +(const foo& v) -> foo {return foo {value + v.value};}
};

auto main() -> int {
  //auto add = [](auto&& _1, auto&& _2) {return _1 + _2;}
  auto add = _1 + _2;

  println(R"(add(40, 20)) => {})", add(40, 20));
  println(R"(add("Barry "_s, "Allen"_s) => {})", add("Barry "_s, "Allen"_s));
  println(R"(add(date_time {2026, 4, 20, 21, 12, 36}, 7_min + 24_s) => {})", add(date_time {2026, 4, 20, 21, 12, 36}, 7_min + 24_s));
  println(R"(add(foo {{50}}, foo {{30}}) => {})", add(foo {50}, foo {30}).value);
  println();
}

// This code produces the following output :
//
// add(40, 20)) => 60
// add("Barry "_s, "Allen"_s) => Barry Allen
// add(date_time , 7_min + 24_s) => 4/20/2026 9:20:00 PM
// add(foo {50}, foo {30}) => 80
