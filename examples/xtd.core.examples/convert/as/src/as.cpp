#include <xtd/as>
#include <xtd/console>
#include <xtd/convert>
#include <xtd/random>

using namespace xtd;

auto main() -> int {
  double d = 41.6;
  int i1 = convert::to_int32(d);
  int i2 = as<int>(d);
  console::write_line("d = {0}, convert::to_int32(d) = {1}, as<int>(d) = {2}", d, i1, i2);
  
  int i = 42;
  string s1 = convert::to_string(i);
  string s2 = as<string>(i);
  console::write_line("i = {0}, convert::to_string(i) = {1}, as<string>(i) = {2}", i, s1, s2);
  
  std::any a = "string";
  s1 = convert::to_string(a);
  s2 = as<string>(a);
  console::write_line("a = {0}, convert::to_string(a) = {1}, as<string>(a) = {2}", a, s1, s2);
  
  ptr<object> value = new_ptr<string>("a");
  ptr<string> value2 = as<string>(value);
  console::write_line("value = {0}, as<string>(value) = {1}", *value, *value2);
  
  xtd::random rand;
  try {
    console::write_line("as<string>(rand) = {0}", as<string>(rand));
  } catch (const invalid_cast_exception& e) {
    console::write_line("Bad cast : {0} !", e.message());
  }
  
  ptr<object> ver = new_ptr<version>(1, 1, 5);
  ptr<string> str = as<string>(ver);
  if (str == nullptr)
    console::write_line("Bad cast!");
}

// This code produces the following output :
//
// d = 41.6, convert::to_int32(d) = 42, as<int>(d) = 42
// i = 42, convert::to_string(i) = 42, as<string>(i) = 42
// a = string, convert::to_string(a) = string, as<string>(a) = string
// value = a, as<string>(value) = a
// Bad cast : std::bad_cast !
// Bad cast!
