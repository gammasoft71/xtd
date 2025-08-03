#include <xtd/xtd>

using namespace diagnostics;

bool is_cppcheck_present() {
  try {
    return process::start(process_start_info {"cppcheck", "--version"}.redirect_standard_output(true).create_no_window(true)).wait_for_exit().exit_code() == 0;
  } catch (...) {
    return false;
  }
}

auto main() -> int {
  if (!is_cppcheck_present()) {
    console::write_line("`cppcheck` command not found, please install `cppcheck` or add `cppcheck` in your path.");
    environment::exit(exit_status::failure);
  }
  
  auto cppcheck_process = process::start(process_start_info {"cppcheck", "--help"}.redirect_standard_output(true));
  auto& standard_output = cppcheck_process.standard_output();
  auto process_output_reader = stream_reader {standard_output};
  while (!process_output_reader.end_of_stream())
    console::write_line(process_output_reader.read_line());
  cppcheck_process.wait_for_exit();
  console::write_line(cppcheck_process.exit_code());
  
  /*
  auto source_file = "/Users/yves/Projects/xtd/build/cppcheck_results.txt";
  auto cppcheck_path = path::combine(path::get_directory_name(source_file), "cppcheck");
  
  directory::create_directory(cppcheck_path);
  auto source_sr = stream_reader {source_file};
  auto error_sw = stream_writer(path::combine(cppcheck_path, "error.txt"));
  auto information_sw = stream_writer(path::combine(cppcheck_path, "information.txt"));
  auto noise_sw = stream_writer(path::combine(cppcheck_path, "noise.txt"));
  auto other_sw = stream_writer(path::combine(cppcheck_path, "other.txt"));
  auto performance_sw = stream_writer(path::combine(cppcheck_path, "performance.txt"));
  auto portability_sw = stream_writer(path::combine(cppcheck_path, "portability.txt"));
  auto style_sw = stream_writer(path::combine(cppcheck_path, "style.txt"));
  auto warning_sw = stream_writer(path::combine(cppcheck_path, "warning.txt"));
  
  while (!source_sr.end_of_stream()) {
    auto line = source_sr.read_line();
    if (line.contains("]: ( error )")) error_sw.write_line(line);
    else if (line.contains("]: ( information )")) information_sw.write_line(line);
    else if (line.contains("]: ( performance )")) performance_sw.write_line(line);
    else if (line.contains("]: ( portability )")) portability_sw.write_line(line);
    else if (line.contains("]: ( style )")) style_sw.write_line(line);
    else if (line.contains("]: ( warning )")) warning_sw.write_line(line);
    else if (line.contains("]: (")) other_sw.write_line(line);
    else noise_sw.write_line(line);
  }
   */
}

// This code produces the following output:
//
// Hello, World!
