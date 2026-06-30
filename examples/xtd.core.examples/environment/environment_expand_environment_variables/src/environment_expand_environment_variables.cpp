#include <xtd/xtd>

auto main() -> int {
  auto str = string::empty_string;
  auto nl = environment::new_line();
  
  console::write_line();
  //  <-- Keep this information secure! -->
  auto query = environment::os_version().is_windows_platform() ? R"("My user name is "%USERNAME%" and the temp path is "%TEMP%")" : R"(My user name is "%USER%" and the temp path is "%TMPDIR%")";
  str = environment::expand_environment_variables(query);
  console::write_line("expand_environment_variables: {0}  {1}", nl, str);
}

// This code produces the following output :
//
//
// expand_environment_variables:
//   My user name is "gammasoft71" and the temp path is "/var/folders/xg/4utgf5o735j2lqi2mhtoxps00000ba/T/"
