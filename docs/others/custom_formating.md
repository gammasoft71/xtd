# Custom formating 

## xtd

```cpp
#include <xtd/xtd>

struct foo1 {
  string name;
  int number;
};

struct foo2 {
  string name;
  int number;
  
  friend auto operator << (std::ostream& os, const foo2& value) -> std::ostream& {return os << string::format("{{name = {}, number = {}}}", value.name, value.number);}
};

struct foo3 {
  string name;
  int number;
};

template<>
auto xtd::to_string(const foo3& value, const string& format, const std::locale& loc) -> string {return string::format("{{name = {}, number = {}}}", value.name, value.number);}

struct foo4 : public istringable {
  foo4(string name, int number) : name {name}, number {number} {}
  
  string name;
  int number;
  
  auto to_string() const noexcept -> string override {return string::format("{{name = {}, number = {}}}", name, number);}
};

struct foo5 : public object {
  foo5(string name, int number) : name {name}, number {number} {}
  
  string name;
  int number;
  
  auto to_string() const noexcept -> string override {return string::format("{{name = {}, number = {}}}", name, number);}
};

struct foo6 {
  string name;
  int number;
};

template<>
auto xtd::to_string(const foo6& value, const string& format, const std::locale& loc) -> string {
  auto fmt = !format.length() ? "g" : format;
  if (fmt.length() != 1) throw format_exception {};
  switch(fmt[0]) {
    case 'd' : return string::format(loc, "{}", value.number);
    case 'g' : return string::format(loc, "{{name = {}, number = {}}}", value.name, value.number);
    case 'n' : return string::format(loc, "{}", value.name);
  }
  throw format_exception {};
}

struct foo7 : public iformatable {
  foo7(string name, int number) : name {name}, number {number} {}
  
  string name;
  int number;
  
  auto to_string(const string& format, const globalization::culture_info& loc) const -> string override {
    auto fmt = !format.length() ? "g" : format;
    if (fmt.length() != 1) throw format_exception {};
    switch(fmt[0]) {
      case 'd' : return string::format(loc, "{}", number);
      case 'g' : return string::format(loc, "{{name = {}, number = {}}}", name, number);
      case 'n' : return string::format(loc, "{}", name);
    }
    throw format_exception {};
  }
};

struct foo8 : public object, public iformatable {
  foo8(string name, int number) : name {name}, number {number} {}
  
  string name;
  int number;
  
  auto to_string() const noexcept -> string override {return to_string("", globalization::culture_info::current_culture());}
  auto to_string(const string& format, const globalization::culture_info& loc) const -> string override {
    auto fmt = !format.length() ? "g" : format;
    if (fmt.length() != 1) throw format_exception {};
    switch(fmt[0]) {
      case 'd' : return string::format(loc, "{}", number);
      case 'g' : return string::format(loc, "{{name = {}, number = {}}}", name, number);
      case 'n' : return string::format(loc, "{}", name);
    }
    throw format_exception {};
  }
  
  friend auto operator << (std::ostream& os, const foo8& value) noexcept -> std::ostream& {return os << value.to_string();}
};

auto main() -> int {
  console::out << "foo1 = " << foo1 {.name = "foo1", .number = 10} << environment::new_line;
  println("foo1 = {}", foo1 {.name = "foo1", .number = 10});
  console::out << "foo2 = " << foo2 {.name = "foo2", .number = 20} << environment::new_line;
  println("foo2 = {}", foo2 {.name = "foo2", .number = 20});
  console::out << "foo3 = " << foo3 {.name = "foo3", .number = 30} << environment::new_line;
  println("foo3 = {}", foo3 {.name = "foo3", .number = 30});
  console::out << "foo4 = " << foo4 {"foo4", 40} << environment::new_line;
  println("foo4 = {}", foo4 {"foo4", 40});
  console::out << "foo5 = " << foo5 {"foo5", 50} << environment::new_line;
  println("foo5 = {}", foo5 {"foo5", 50});
  console::out << "foo6 = " << foo6 {"foo6", 60} << environment::new_line;
  println("foo6 = {}", foo6 {.name = "foo6", .number = 60});
  println("foo6 = {:g}", foo6 {.name = "foo6", .number = 60});
  println("foo6 = {:n}", foo6 {.name = "foo6", .number = 60});
  println("foo6 = {:d}", foo6 {.name = "foo6", .number = 60});
  console::out << "foo7 = " << foo7 {"foo7", 70} << environment::new_line;
  println("foo7 = {}", foo7 {"foo7", 70});
  println("foo7 = {:g}", foo7 {"foo7", 70});
  println("foo7 = {:n}", foo7 {"foo7", 70});
  println("foo7 = {:d}", foo7 {"foo7", 70});
  console::out << "foo8 = " << foo8 {"foo8", 80} << environment::new_line;
  println("foo8 = {}", foo7 {"foo8", 80});
  println("foo8 = {:g}", foo7 {"foo8", 80});
  println("foo8 = {:n}", foo7 {"foo8", 80});
  println("foo8 = {:d}", foo7 {"foo8", 80});
}

// This code produces the following output :
//
// foo1 = (unregistered)
// foo1 = (unregistered)
// foo2 = {name = foo2, number = 20}
// foo2 = {name = foo2, number = 20}
// foo3 = (unregistered)
// foo3 = {name = foo3, number = 30}
// foo4 = {name = foo4, number = 40}
// foo4 = {name = foo4, number = 40}
// foo5 = {name = foo5, number = 50}
// foo5 = {name = foo5, number = 50}
// foo6 = (unregistered)
// foo6 = {name = foo6, number = 60}
// foo6 = {name = foo6, number = 60}
// foo6 = foo6
// foo6 = 60
// foo7 = {name = foo7, number = 70}
// foo7 = {name = foo7, number = 70}
// foo7 = {name = foo7, number = 70}
// foo7 = foo7
// foo7 = 70
// foo8 = {name = foo8, number = 80}
// foo8 = {name = foo8, number = 80}
// foo8 = {name = foo8, number = 80}
// foo8 = foo8
// foo8 = 80
```

## std C++23

```cpp
#include <format>
#include <iostream>
#include <print>
#include <sstream>
#include <string>

struct foo1 {
  std::string name;
  int number;
};

struct foo2 {
  std::string name;
  int number;
  
  friend auto operator << (std::ostream& os, const foo2& value) -> std::ostream& {return os << std::format("{{name = {}, number = {}}}", value.name, value.number);}
};

struct foo3 {
  std::string name;
  int number;
};

template <>
struct std::formatter<foo3, char> {
  bool show_name = true;
  bool show_number = true;
  
  template<class parse_context_t>
  constexpr auto parse(parse_context_t& context) -> parse_context_t::iterator {
    auto iterator = context.begin();
    if (iterator == context.end() || *iterator == '}') return iterator;
    if (*iterator == 'd') show_name = false;
    else if (*iterator == 'n') show_number = false;
    else if (*iterator != 'g') throw std::format_error("invalid format");
    ++iterator;
    return iterator;
  }
  
  template<class format_context_t>
  auto format(const foo3& value, format_context_t& context) const -> format_context_t::iterator {
    if (!show_name) return std::format_to(context.out(), "{}", value.number);
    if (!show_number) return std::format_to(context.out(), "{}", value.name);
    return std::format_to(context.out(), "{{name = {}, number = {}}}", value.name, value.number);
  }
};

struct foo4 {
  std::string name;
  int number;
  
  friend auto operator << (std::ostream& os, const foo4& value) -> std::ostream& {return os << std::format("{{name = {}, number = {}}}", value.name, value.number);}
};

template <>
struct std::formatter<foo4, char> {
  bool show_name = true;
  bool show_number = true;
  
  template<class parse_context_t>
  constexpr auto parse(parse_context_t& context) -> parse_context_t::iterator {
    auto iterator = context.begin();
    if (iterator == context.end() || *iterator == '}') return iterator;
    if (*iterator == 'd') show_name = false;
    else if (*iterator == 'n') show_number = false;
    else if (*iterator != 'g') throw std::format_error("invalid format");
    ++iterator;
    return iterator;
  }
  
  template<class format_context_t>
  auto format(const foo4& value, format_context_t& context) const -> format_context_t::iterator {
    if (!show_name) return std::format_to(context.out(), "{}", value.number);
    if (!show_number) return std::format_to(context.out(), "{}", value.name);
    auto out = std::ostringstream {};
    out << value;
    return std::ranges::copy(std::move(out).str(), context.out()).out;
  }
};

auto main() -> int {
  //std::cout << foo1 {.name = "foo1", .number = 10} << std::endl; // Does not build, because not stream operator << !
  //std::println("foo1 = {}", foo1 {.name = "foo1", .number = 10}); // Does not build, because not std::formatter !
  std::cout << foo2 {.name = "foo2", .number = 20} << std::endl;
  //std::println("foo2 = {}", foo2 {.name = "foo2", .number = 20}); // Does not build, because not std::formatter !
  //std::cout << foo3 {.name = "foo3", .number = 30} << std::endl; // Does not build, because not stream operator << !
  std::println("foo3 = {}", foo3 {.name = "foo3", .number = 30});
  std::println("foo3 = {:g}", foo3 {.name = "foo3", .number = 30});
  std::println("foo3 = {:n}", foo3 {.name = "foo3", .number = 30});
  std::println("foo3 = {:d}", foo3 {.name = "foo3", .number = 30});
  std::cout << foo4 {.name = "foo4", .number = 40} << std::endl;
  std::println("foo4 = {}", foo4 {.name = "foo4", .number = 40});
  std::println("foo4 = {:g}", foo4 {.name = "foo4", .number = 40});
  std::println("foo4 = {:n}", foo4 {.name = "foo4", .number = 40});
  std::println("foo4 = {:d}", foo4 {.name = "foo4", .number = 40});
}

// This code produces the following output :
//
// {name = foo2, number = 20}
// foo3 = {name = foo3, number = 30}
// foo3 = {name = foo3, number = 30}
// foo3 = foo3
// foo3 = 30
// foo4 = {name = foo4, number = 40}
// foo4 = {name = foo4, number = 40}
// foo4 = foo4
// foo4 = 40
```
