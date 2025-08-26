#include <xtd/xtd>

auto main() -> int {
  string s1 = "Tom";
  string s2 = "Carol";
  console::write_line("object::equals(\"{0}\", \"{1}\") => {2}", s1, s2, object::equals(s1, s2));
  
  s1 = "Tom";
  s2 = "Tom";
  console::write_line("object::equals(\"{0}\", \"{1}\") => {2}", s1, s2, object::equals(s1, s2));
  
  s1 = "";
  s2 = "Tom";
  console::write_line("object::equals(\"{0}\", \"{1}\") => {2}", s1, s2, object::equals(s1, s2));
  
  s1 = "Carol";
  s2 = "";
  console::write_line("object::equals(\"{0}\", \"{1}\") => {2}", s1, s2, object::equals(s1, s2));
  
  s1 = "";
  s2 = "";
  console::write_line("object::equals(\"{0}\", \"{1}\") => {2}", s1, s2, object::equals(s1, s2));
}

// This code produces the following output :
//
// object::equals("Tom", "Carol") => false
// object::equals("Tom", "Tom") => true
// object::equals("", "Tom") => false
// object::equals("Carol", "") => false
// object::equals("", "") => true
