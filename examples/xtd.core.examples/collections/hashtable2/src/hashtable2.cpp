#include <xtd/xtd>

auto main() -> int {
  auto items = collections::hashtable {{"string", "42"}, {"int", 42}, {"time_span"_s, 12_h + 24_m + 42_s}, {"double", .42}, {"42", "string"}, {42, "int"}, {12_h + 24_m + 42_s, "time_span"}, {.42, "double"}};
  
  for (auto [key, value] : items) {
    console::write("{,-9} -> ", key);
    if (is<string>(value)) console::write_line("{}", as<string>(value).quoted());
    else if (is<int>(value)) console::write_line("0x{:X4}", as<int>(value));
    else if (is<time_span>(value)) console::write_line("{} seconds", as<time_span>(value).seconds());
    else console::write_line("{}", value);
  }
  
  console::write_line();
  console::write_line("Update time_span to 20_h + 10_m + 5_s");
  items["time_span"] = 20_h + 10_m + 5_s;
  console::write_line("[time_span] = {}", items["time_span"]);
  console::write_line("add day_of_week enum with day_of_week::saturday value");
  items["day_of_week"] = day_of_week::saturday;
  console::write_line("[day_of_week] = {}", items["day_of_week"]);
}

// This code can produce the following output :
//
// 0.42      -> "double"
// 12:24:42  -> "time_span"
// 42        -> "int"
// int       -> 0x002A
// double    -> 0.42
// 42        -> "string"
// time_span -> 42 seconds
// string    -> "42"
//
// Update time_span to 20_h + 10_m + 5_s
// [time_span] = 20:10:05
// add day_of_week enum with day_of_week::saturday value
// [day_of_week] = saturday
