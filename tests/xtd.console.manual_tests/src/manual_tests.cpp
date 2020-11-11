#include <xtd/xtd.console>

using namespace xtd;

void update_cmakefile(std::filesystem::path path) {
  for (auto item : std::filesystem::directory_iterator(path)) {
    if (item.is_directory()) update_cmakefile(item.path());
    else if (item.is_regular_file() && item.path().filename() == "CMakeLists.txt") {
      io::file::write_all_text(item.path(), strings::replace(io::file::read_all_text(item.path()), "target_type(CONSOLE_APPLICATION)", "target_type(TEST_APPLICATION)"));
    }
  }
}

// The main entry point for the application.
int main() {
  //console::write_line("Hello, World!");
  update_cmakefile(std::filesystem::path("/Users/yves/Projects/xtd/examples/xtd.tunit"));
}
