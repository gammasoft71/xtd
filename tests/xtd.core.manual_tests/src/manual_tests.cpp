#include <xtd/xtd>

auto main() -> int {
  // from({"/Users/yves/Projects/xtd/src/xtd.core/include"_s, "/Users/yves/Projects/xtd/src/xtd.core.native/include"_s, "/Users/yves/Projects/xtd/src/xtd.drawing/include"_s, "/Users/yves/Projects/xtd/src/xtd.drawing.native/include"_s, "/Users/yves/Projects/xtd/src/xtd.forms/include"_s, "/Users/yves/Projects/xtd/src/xtd.forms.native/include"_s, "/Users/yves/Projects/xtd/src/xtd.tunit/include"_s}).to_list().for_each(delegate_(auto p) {directory::get_files(p, "*", search_option::all_directories).order_by(delegate_(auto file) {return file;}).where(delegate_(auto file) {return path::get_extension(file) == "";}).to_list().for_each(delegate_(auto f) {file::write_all_lines(f, file::read_all_lines(f).select(delegate_(auto l) {return (!l.starts_with("#include \"") || !l.ends_with(".hpp\"")) ? l : "#include <" + path::get_directory_name(f).replace(p + "/", "") + "/" + path::get_file_name(l.substring(10, l.size() - 11)) + ">";})), console::write_line("Fixed: {}", f);});});

  from({"/Users/yves/Projects/xtd/src/xtd.core/include"_s, "/Users/yves/Projects/xtd/src/xtd.core.native/include"_s, "/Users/yves/Projects/xtd/src/xtd.drawing/include"_s, "/Users/yves/Projects/xtd/src/xtd.drawing.native/include"_s, "/Users/yves/Projects/xtd/src/xtd.forms/include"_s, "/Users/yves/Projects/xtd/src/xtd.forms.native/include"_s, "/Users/yves/Projects/xtd/src/xtd.tunit/include"_s})
    .to_list()
    .for_each(delegate_(auto path) {
      directory::get_files(path, "*", search_option::all_directories)
        .order_by(delegate_(auto file) { return file; })
        .where(delegate_(auto file) { return io::path::get_extension(file) == ""; })
        .to_list()
        .for_each(delegate_(auto file) {
          io::file::write_all_lines(file, io::file::read_all_lines(file).select(delegate_(auto line) {
            return !line.starts_with("#include \"") || !line.ends_with(".hpp\"") ? line : "#include <" + io::path::get_directory_name(file).replace(path + "/", "") + "/" + io::path::get_file_name(line.substring(10, line.size() - 11)) + ">";
          }));
          console::write_line("Fixed: {}", file);
        });
    });
}

// This code produces the following outputs :
//
