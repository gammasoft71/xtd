#include <xtd/xtd>

using namespace std::filesystem;
using namespace xtd;

int main() {
  environment::current_directory(environment::get_folder_path(environment::special_folder::desktop));
  directory_entry info(".");
  
  console::write_line("Directory entry:   " + absolute(info.path()).string());
}

// This code produces the following output :
//
// Directory entry:   /!---OMITTED---!/Desktop/.
