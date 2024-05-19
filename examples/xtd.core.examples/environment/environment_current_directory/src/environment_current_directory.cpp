#include <xtd/io/path>
#include <xtd/console>
#include <xtd/environment>

using namespace xtd;
using namespace xtd::io;

auto main() -> int {
  environment::current_directory(environment::get_folder_path(environment::special_folder::desktop));
  console::write_line("Directory entry:   " + path::get_full_path("."));
}

// This code produces the following output :
//
// Directory entry:   /!---OMITTED---!/Desktop
