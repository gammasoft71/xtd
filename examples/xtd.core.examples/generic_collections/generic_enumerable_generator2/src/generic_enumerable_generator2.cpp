#include <xtd/xtd>

auto fill_large_log_file(const string& file) -> void {
  if (file::exists(file)) return; // file::remove(file);
  println("Write file {}...", file);
  auto noise_strings = array<string> {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz", "012345678901234467890123456789"};
  using_(auto sw = stream_writer {file})
  for (auto index = 0; index < 10'000'000; ++index)
    sw.write_line(string::format("{}", index / 2 % 1'000'000 ? noise_strings[index % 3] : string::format("ERROR {}", index / 2)));
  println("Done!\n");
}

auto read_all_lines_generator(const string& file) -> enumerable_generator<string> {
  using_(auto sr = stream_reader {file})
  while (!sr.end_of_stream())
    co_yield sr.read_line();
}

auto main() -> int {
  auto file = path::combine(path::get_temp_path(), "bulky_log.txt");
  fill_large_log_file(file);
  
  auto lines = read_all_lines_generator(file)
    .where([](auto line) {return line.contains("ERROR");})
    .select([](auto line) {return string::format("0x{:X8}", as<int32>(line.replace("ERROR ", "")));})
    .distinct();
  
  println("Read file {}...", file);
  for (auto line : lines)
    println("  {}", line);
  println("Done!");
}

// This code can produce the following output :
//
// Read file /var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T/bulky_log.txt...
//   0x00000000
//   0x000F4240
//   0x001E8480
//   0x002DC6C0
//   0x003D0900
// Done!
