#include <xtd/console>
#include <xtd/environment>

using namespace xtd;

auto main() -> int {
  auto str = ustring::empty_string;
  auto nl = environment::new_line();
  
  console::write_line();
  //  <-- Keep this information secure! -->
  auto query = "My system drive is %SystemDrive% and my system root is %SystemRoot%";
  str = environment::expand_environment_variables(query);
  console::write_line("expand_environment_variables: {0}  {1}", nl, str);
}

// This code produces the following output :
//
// expand_environment_variables:
//   My system drive is C: and my system root is C:\windows
