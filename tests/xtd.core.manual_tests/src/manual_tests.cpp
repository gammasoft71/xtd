#include <xtd/io/directory>
#include <xtd/io/file>
#include <xtd/io/path>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::io;

class core_manual_test {
public:
  static auto entry_point() {
    for (auto file_name : directory::get_files("/Users/yves/Projects/xtd/src/xtd.drawing.native/include/xtd/drawing/native", "*.h"))
      file::write_all_lines(path::change_extension(file_name, ""), {"#pragma once"_s, ustring::format("#include \"{}\"", path::get_file_name(file_name))});
  }
};

auto main()->int {
  startup::safe_run(core_manual_test::entry_point);
}
