#include <filesystem>
#include <xtd/xtd.core>

using namespace std;
using namespace std::filesystem;
using namespace xtd;

void updte_cmakelists_files(const path& path) {
  for (auto item : directory_iterator(path)) {
    if (item.is_directory()) updte_cmakelists_files(item.path());
    else if (item.path().filename() == "CMakeLists.txt") io::file::write_all_text(item.path(), strings::replace(io::file::read_all_text(item.path()), "cmake_minimum_required(VERSION 3.13)", "cmake_minimum_required(VERSION 3.3)"));
  }
}

int main() {
  console::write_line("Hello, World!");
  double value = 123.456;
  //updte_cmakelists_files({"/Users/yves/Projects/xtd/src"});
  console::write_line("locale = {}, value = {:C}", locale().name(), value);
  std::locale::global(std::locale());
  console::write_line("locale = {}, value = {:C}", locale().name(), value);
  std::locale::global(std::locale("C"));
  console::write_line("locale = {}, value = {:C}", locale().name(), value);
  std::locale::global(std::locale(""));
  console::write_line("locale = {}, value = {:C}", locale().name(), value);
  std::locale::global(std::locale("en_US.utf-8"));
  console::write_line("locale = {}, value = {:C}", locale().name(), value);
  std::locale::global(std::locale("fr_FR.utf-8"));
  console::write_line("locale = {}, value = {:C}", locale().name(), value);
  std::locale::global(std::locale("ja_JP.utf-8"));
  console::write_line("locale = {}, value = {:C}", locale().name(), value);
  std::locale::global(std::locale("de_CH.utf-8"));
  console::write_line("locale = {}, value = {:C}", locale().name(), value);
  
  console::write_line("locale = {}", locale().name());
}
