#include <filesystem>
#include <xtd/xtd.console>

using namespace xtd;

void replace_hpp_by_h(const std::filesystem::path& path) {
  for (auto item : std::filesystem::directory_iterator(path)) {
    if (item.is_directory()) replace_hpp_by_h(item.path());
    else if (item.path().extension() == ".hpp") io::file::move(item.path().string(), strings::replace(item.path().string(), ".hpp", ".h"));
  }
}

// The main entry point for the application.
int main() {
  console::write_line("Hello, World!");
  replace_hpp_by_h(std::filesystem::path("/Users/yves/Projects/xtd/src"));
}
