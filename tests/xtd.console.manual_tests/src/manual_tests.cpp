#include <xtd/xtd.console>

using namespace xtd;

void update_cmakefile(std::filesystem::path path) {
  for (auto item : std::filesystem::directory_iterator(path)) {
    if (item.is_directory()) update_cmakefile(item.path());
    else if (item.is_regular_file() && item.path().filename() == "CMakeLists.txt") {
      io::file::write_all_text(item.path(), strings::replace(io::file::read_all_text(item.path()), "find_package(xtd.forms REQUIRED)", "find_package(xtd REQUIRED)"));
      io::file::write_all_text(item.path(), strings::replace(io::file::read_all_text(item.path()), "add_executable(${PROJECT_NAME} ", "add_sources("));
      io::file::write_all_text(item.path(), strings::replace(io::file::read_all_text(item.path()), "target_link_libraries(${PROJECT_NAME} xtd.tunit)\nset_target_properties(${PROJECT_NAME} PROPERTIES FOLDER \"xtd.tunit\")", "target_type(CONSOLE_APPLICATION)"));
    }
  }
}

// The main entry point for the application.
int main() {
  //console::write_line("Hello, World!");
  update_cmakefile(std::filesystem::path("/Users/yves/Projects/xtd/examples/xtd.forms"));
}
