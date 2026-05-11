#include <xtd/xtd>

struct foo {
  int value;
  
  friend auto operator <<(std::ostream& os, const foo& f) -> std::ostream& {return os << f.value;}
  friend auto operator ==(const foo& f1, const foo& f2) -> bool {return f1.value == f2.value;}
};

auto main() -> int {
  list<std::variant<bool, date_time, double, foo, int32, string>> {42, .21, "value", true, foo {84}, date_time {1971, 1, 5, 23, 32, 44}}
    .for_each([](const auto& item) {
      if (is<bool>(item)) println("bool -> {}", as<bool>(item));
      else if (is<date_time>(item)) println("date_time -> {:dd/MM/yyyy HH:mm:ss}", as<date_time>(item));
      else if (is<double>(item)) println("double -> {:P}", as<double>(item));
      else if (is<foo>(item)) println("foo -> {}", as<foo>(item));
      else if (is<int>(item)) println("int -> 0x{:X}", as<int>(item));
      else if (is<string>(item)) println("string -> {}", as<string>(item).quoted());
      else println("other -> ({})", item);
    });
  
  println();
  collections::array_list {42, .21, "value", true, foo {84}, date_time {1971, 1, 5, 23, 32, 44}}
    .for_each([](const auto& item) {
      if (is<bool>(item)) println("bool -> {}", as<bool>(item));
      else if (is<date_time>(item)) println("date_time -> {:dd/MM/yyyy HH:mm:ss}", as<date_time>(item));
      else if (is<double>(item)) println("double -> {:P}", as<double>(item));
      else if (is<foo>(item)) println("foo -> {}", as<foo>(item));
      else if (is<int>(item)) println("int -> 0x{:X}", as<int>(item));
      else if (is<string>(item)) println("string -> {}", as<string>(item).quoted());
      else println("other -> ({})", item);
    });
}

// This code produces the following output :
//
// int -> 0x2A
// double -> 21.00 %
// string -> "value"
// bool -> true
// foo -> 84
// date_time -> 05/01/1971 23:32:44
//
// int -> 0x2A
// double -> 21.00 %
// string -> "value"
// bool -> true
// foo -> 84
// date_time -> 05/01/1971 23:32:44
