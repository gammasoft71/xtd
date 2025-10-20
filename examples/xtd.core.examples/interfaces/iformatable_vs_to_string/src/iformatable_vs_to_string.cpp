#include <xtd/xtd>

using namespace xtd::globalization;

// The following simple class throws an `xtd::format_exception`exception with the `xtd::console::write_line` method,
// and generates the invalid result "(unregistered)" with output stream.
// Remarks: You needs to write to_strings methods.
class foo1 {
public:
  explicit foo1(int value) : value_ {value} {}
  string to_string() const noexcept {return string::format("{}", value_);}
  string to_string(const string& format, const std::locale& loc) const {return string::format(string::format("{{:{}}}", format), value_);}

private:
  int value_ = 0;
};

// The following simple class works correctly with the `xtd::console::write_line` method,
// and generates the invalid result "(unregistered)" with output stream.
// Remarks: You needs to write to_strings methods.
class foo2 {
public:
  explicit foo2(int value) : value_ {value} {}
  
  string to_string() const noexcept {return string::format("{}", value_);}
  string to_string(const string& format, const std::locale& loc) const {return string::format(string::format("{{:{}}}", format), value_);}

private:
  int value_ = 0;
};

// xtd::to_string specialisation for foo2 class.
template<>
std::string xtd::to_string(const foo2& value, const std::string& format, const std::locale& loc) {return value.to_string(format, loc);}

// The following class which inherits from `xtd::iformatable` works correctly with the `xtd::console::write_line` method,
// and generates the invalid result "(unregistered)" with output stream.
// Remarks: You needs to write to_string method without param and to verride to_string method with params.
class foo3 : public iformatable {
public:
  explicit foo3(int value) : value_ {value} {}
  
  string to_string() const noexcept {return string::format("{}", value_);}
  string to_string(const string& format, const std::locale& loc) const override {return string::format(string::format("{{:{}}}", format), value_);}
  
private:
  int value_ = 0;
};

// The following class which inherits from `xtd::object` deos not work correctly with the `xtd::console::write_line` method,
// and work correctly with output stream.
// Remarks: You needs to override to_string method without param and to write to_string method with params.
class foo4 : public object {
public:
  explicit foo4(int value) : value_ {value} {}
  string to_string() const noexcept override {return string::format("{}", value_);}
  string to_string(const string& format, const std::locale& loc) const {return string::format(string::format("{{:{}}}", format), value_);}

private:
  int value_ = 0;
};

// The following class which inherits from `xtd::object` works correctly with the `xtd::console::write_line` method 
// and works correctly with output stream thanks to the << operator.
// Remarks: You needs to write to_string method without param and to verride to_string method with params and << operator.
class foo5 : public iformatable {
public:
  explicit foo5(int value) : value_ {value} {}

  string to_string() const noexcept {return string::format("{}", value_);}
  string to_string(const string& format, const std::locale& loc) const override {return string::format(string::format("{{:{}}}", format), value_);}

  friend std::ostream& operator <<(std::ostream& stream, const foo5& value) {return stream << value.to_string("", culture_info::current_culture());}
  
private:
  int value_ = 0;
};

// The following class which inherits from `xtd::object` works correctly with the `xtd::console::write_line` method
// and works correctly with output stream thanks to the << operator.
// Remarks: You needs to write to_string methods and the << operator.
class foo6 {
public:
  explicit foo6(int value) : value_ {value} {}
  
  string to_string() const noexcept {return to_string("", culture_info::current_culture());}
  string to_string(const string& format, const std::locale& loc) const {return string::format(string::format("{{:{}}}", format), value_);}
  
  friend std::ostream& operator <<(std::ostream& stream, const foo6& value) {return stream << value.to_string();}
  
private:
  int value_ = 0;
};

// xtd::to_string specialisation for foo6 class.
template<>
std::string xtd::to_string(const foo6& value, const std::string& format, const std::locale& loc) {return value.to_string(format, loc);}

// The following class which inherits from `xtd::object` and `xtd::iformatable` works correctly with the `xtd::console::write_line` method
// and with output stream.
// Remarks: All you have to do is override the method parameterised to_string.
class foo7 : public object, public iformatable {
public:
  explicit foo7(int value) : value_ {value} {}
  
  using object::to_string;
  string to_string(const string& format, const std::locale& loc) const override {return string::format(string::format("{{:{}}}", format), value_);}
  
private:
  int value_ = 0;
};

auto main() -> int {
  auto f1 = foo1 {42};
  console::out << "foo1 standard output :" << environment::new_line;
  console::out << "  " << f1 << environment::new_line;
  console::out << "  " << f1.to_string() << environment::new_line;
  try {
    console::out << string::format("  {}", f1) << environment::new_line;
  } catch(const format_exception& e) {
    console::out << "  " << foreground_color(console_color::red) << "exception : " << e.message() << foreground_color(console_color::default_color) << environment::new_line;
  }
  try {
    console::out << string::format("  0b{:b8}", f1) << environment::new_line;
  } catch(const format_exception& e) {
    console::out << "  " << foreground_color(console_color::red) << "exception : " << e.message() << foreground_color(console_color::default_color) << environment::new_line;
  }
  console::out << "  0b" << f1.to_string("b8", culture_info::current_culture()) << environment::new_line;
  console::write_line();
  console::write_line("foo1 write_line :");
  console::write("  ");
  try {
    console::write_line(f1);
  } catch(const format_exception& e) {
    console::out << foreground_color(console_color::red) << "exception : " << e.message() << foreground_color(console_color::default_color) << environment::new_line;
  }
  console::write("  ");
  console::write_line(f1.to_string());
  try {
    console::write_line("  {}", f1);
  } catch(const format_exception& e) {
    console::out << "  " << foreground_color(console_color::red) << "exception : " << e.message() << foreground_color(console_color::default_color) << environment::new_line;
  }
  try {
    console::write_line("  0b{:b8}", f1);
  } catch(const format_exception& e) {
    console::out << "  " << foreground_color(console_color::red) << "exception : " << e.message() << foreground_color(console_color::default_color) << environment::new_line;
  }
  console::write("  0b");
  console::write_line(f1.to_string("b8", culture_info::current_culture()));
  console::write_line();

  auto f2 = foo2 {42};
  console::out << "foo2 standard output :" << environment::new_line;
  console::out << "  " << f2 << environment::new_line;
  console::out << "  " << f2.to_string() << environment::new_line;
  console::out << string::format("  {}", f2) << environment::new_line;
  console::out << string::format("  0b{:b8}", f2) << environment::new_line;
  console::out << "  0b" << f2.to_string("b8", culture_info::current_culture()) << environment::new_line;
  console::write_line();
  console::write_line("foo2 write_line :");
  console::write("  ");
  console::write_line(f2);
  console::write("  ");
  console::write_line(f2.to_string());
  console::write_line("  {}", f2);
  console::write_line("  0b{:b8}", f2);
  console::write("  0b");
  console::write_line(f2.to_string("b8", culture_info::current_culture()));
  console::write_line();

  auto f3 = foo3 {42};
  console::out << "foo3 standard output :" << environment::new_line;
  console::out << "  " << f3 << environment::new_line;
  console::out << "  " << f3.to_string() << environment::new_line;
  console::out << string::format("  {}", f3) << environment::new_line;
  console::out << string::format("  0b{:b8}", f3) << environment::new_line;
  console::out << "  0b" << f3.to_string("b8", culture_info::current_culture()) << environment::new_line;
  console::write_line();
  console::write_line("foo3 write_line :");
  console::write("  ");
  console::write_line(f3);
  console::write("  ");
  console::write_line(f3.to_string());
  console::write_line("  {}", f3);
  console::write_line("  0b{:b8}", f3);
  console::write("  0b");
  console::write_line(f3.to_string("b8", culture_info::current_culture()));
  console::write_line();

  auto f4 = foo4 {42};
  console::out << "foo4 standard output :" << environment::new_line;
  console::out << "  " << f4 << environment::new_line;
  console::out << "  " << f4.to_string() << environment::new_line;
  console::out << string::format("  {}", f4) << environment::new_line;
  console::out << string::format("  0b{:b8}", f4) << environment::new_line;
  console::out << "  0b" << f4.to_string("b8", culture_info::current_culture()) << environment::new_line;
  console::write_line();
  console::write_line("foo4 write_line :");
  console::write("  ");
  console::write_line(f4);
  console::write("  ");
  console::write_line(f4.to_string());
  console::write_line("  {}", f4);
  console::write_line("  0b{:b8}", f4);
  console::write("  0b");
  console::write_line(f4.to_string("b8", culture_info::current_culture()));
  console::write_line();

  auto f5 = foo5 {42};
  console::out << "foo5 standard output :" << environment::new_line;
  console::out << "  " << f5 << environment::new_line;
  console::out << "  " << f5.to_string() << environment::new_line;
  console::out << string::format("  {}", f5) << environment::new_line;
  console::out << string::format("  0b{:b8}", f5) << environment::new_line;
  console::out << "  0b" << f5.to_string("b8", culture_info::current_culture()) << environment::new_line;
  console::write_line();
  console::write_line("foo5 write_line :");
  console::write("  ");
  console::write_line(f5);
  console::write("  ");
  console::write_line(f5.to_string());
  console::write_line("  {}", f5);
  console::write_line("  0b{:b8}", f5);
  console::write("  0b");
  console::write_line(f5.to_string("b8", culture_info::current_culture()));
  console::write_line();

  auto f6 = foo6 {42};
  console::out << "foo6 standard output :" << environment::new_line;
  console::out << "  " << f6 << environment::new_line;
  console::out << "  " << f6.to_string() << environment::new_line;
  console::out << string::format("  {}", f6) << environment::new_line;
  console::out << string::format("  0b{:b8}", f6) << environment::new_line;
  console::out << "  0b" << f6.to_string("b8", culture_info::current_culture()) << environment::new_line;
  console::write_line();
  console::write_line("foo6 write_line :");
  console::write("  ");
  console::write_line(f6);
  console::write("  ");
  console::write_line(f6.to_string());
  console::write_line("  {}", f6);
  console::write_line("  0b{:b8}", f6);
  console::write("  0b");
  console::write_line(f6.to_string("b8", culture_info::current_culture()));
  console::write_line();

  auto f7 = foo7 {42};
  console::out << "foo7 standard output :" << environment::new_line;
  console::out << "  " << f7 << environment::new_line;
  console::out << "  " << f7.to_string() << environment::new_line;
  console::out << string::format("  {}", f7) << environment::new_line;
  console::out << string::format("  0b{:b8}", f7) << environment::new_line;
  console::out << "  0b" << f7.to_string("b8", culture_info::current_culture()) << environment::new_line;
  console::write_line();
  console::write_line("foo7 write_line :");
  console::write("  ");
  console::write_line(f7);
  console::write("  ");
  console::write_line(f7.to_string());
  console::write_line("  {}", f7);
  console::write_line("  0b{:b8}", f7);
  console::write("  0b");
  console::write_line(f7.to_string("b8", culture_info::current_culture()));
  console::write_line();
}

// This code produces the following output :
//
// foo1 standard output :
//   (unregistered)
//   42
//   exception : The `foo1` type does not inherit from `xtd::iformat` or the specialisation for the `foo1` type in the `xtd::to_string` specialisation method does not exist.
//   exception : The `foo1` type does not inherit from `xtd::iformat` or the specialisation for the `foo1` type in the `xtd::to_string` specialisation method does not exist.
//   0b00101010
//
// foo1 write_line :
//   exception : The `foo1` type does not inherit from `xtd::iformat` or the specialisation for the `foo1` type in the `xtd::to_string` specialisation method does not exist.
//   42
//   exception : The `foo1` type does not inherit from `xtd::iformat` or the specialisation for the `foo1` type in the `xtd::to_string` specialisation method does not exist.
//   exception : The `foo1` type does not inherit from `xtd::iformat` or the specialisation for the `foo1` type in the `xtd::to_string` specialisation method does not exist.
//   0b00101010
//
// foo2 standard output :
//   (unregistered)
//   42
//   42
//   0b00101010
//   0b00101010
//
// foo2 write_line :
//   42
//   42
//   42
//   0b00101010
//   0b00101010
//
// foo3 standard output :
//   (unregistered)
//   42
//   42
//   0b00101010
//   0b00101010
//
// foo3 write_line :
//   42
//   42
//   42
//   0b00101010
//   0b00101010
//
// foo4 standard output :
//   42
//   42
//   42
//   0b42
//   0b00101010
//
// foo4 write_line :
//   42
//   42
//   42
//   0b42
//   0b00101010
//
// foo5 standard output :
//   42
//   42
//   42
//   0b00101010
//   0b00101010
//
// foo5 write_line :
//   42
//   42
//   42
//   0b00101010
//   0b00101010
//
// foo6 standard output :
//   42
//   42
//   42
//   0b00101010
//   0b00101010
//
// foo6 write_line :
//   42
//   42
//   42
//   0b00101010
//   0b00101010
//
// foo7 standard output :
//   42
//   42
//   42
//   0b00101010
//   0b00101010
//
// foo7 write_line :
//   42
//   42
//   42
//   0b00101010
//   0b00101010
