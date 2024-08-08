#include <xtd/configuration/file_settings>
#include <xtd/console>

using namespace xtd;
using namespace xtd::configuration;

auto write_file_settings() {
  auto file = file_settings {"example.ini"};
  file.top_file_comment("Settings file used by file_settings example.\nCopyright (c) 2024 Gammasoft. All rights reserved.");
  file.write("auto_close", true);
  file.write("caption", "file_settings example");
  file.write("Thread \"Process\"", "timeout", 100_ms);
  file.save();
}

auto reset_file_settings() {
  auto file = file_settings {"example.ini"};
  file.reset();
}

auto read_file_settings() {
  auto file = file_settings {"example.ini"};
  console::write_line("----------------------------------------");
  console::write_line("\"exemple.ini\" file content :");
  console::write_line(file.to_string());
  console::write_line("----------------------------------------");
  console::write_line("read keys :");
  console::write_line("auto_close = {}", file.read("auto_close", false));
  console::write_line("caption = {}", file.read("caption", "example"));
  console::write_line("Thread \"Process\"", "time_out = {}", file.read("timeout", 50_ms));
  console::write_line("----------------------------------------");
}

auto main() -> int {
  write_file_settings();
  // Uncomment the following line to see what happens if the "example.ini" file doesn't exist.
  //reset_file_settings();
  read_file_settings();
}

// This code produces the following output :
//
// ----------------------------------------
// "exemple.ini" file content :
// # Settings file used by file_settings example.
// # Copyright (c) 2024 Gammasoft. All rights reserved.
//
// auto_close = true
// caption = file_settings example
//
// [Thread "Process"]
// timeout = 00:00:00.1000000
//
// ----------------------------------------
// read keys :
// auto_close = true
// caption = file_settings example
// Thread "Process"
// ----------------------------------------
