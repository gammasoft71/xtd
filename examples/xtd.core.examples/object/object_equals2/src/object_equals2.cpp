#include <xtd/console>

using namespace xtd;

auto main() -> int {
  ustring s1 = "Tom";
  ustring s2 = "Carol";
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
