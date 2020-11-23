#include <xtd/xtd.core>
#include <filesystem>

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::io;

void update_md_files(const filesystem::path& path) {
  for (auto item : directory_iterator(path))
    if (item.is_directory()) update_md_files(item.path());
    else if (item.path().extension() == ".md") {
      auto file_name= item.path().string();
      file::write_all_text(file_name, strings::replace(file::read_all_text(file_name), "(../../..", "(../../../.."));
    }
}

int main() {
  //console::write_line("Hello, World!");
  //system_exception::enable_stack_trace(false);
  update_md_files({"/Users/yves/Projects/xtd/examples/xtd.forms.examples"});
}
