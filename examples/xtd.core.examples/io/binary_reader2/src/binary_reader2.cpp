#include <xtd/xtd>

class program {
  inline static const string file_name = "app_settings.dat";
public:
  static auto main() {
    write_default_values();
    display_values();
  }
  
  static void write_default_values() {
    block_scope_(auto fs = file::open(file_name, std::ios::out | std::ios::binary | std::ios::trunc)) {
      auto writer = binary_writer {fs};
      writer << 1.250F;
      writer << R"(c:\Temp)";
      writer << 10;
      writer << true;
    }
  }
  
  static void display_values() {
    auto aspect_ratio = .0f;
    auto temp_directory = string::empty_string;
    auto auto_save_time = 0;
    auto show_status_bar = false;

    if (file::exists(file_name)) {
      block_scope_(auto fs = file::open(file_name, std::ios::in | std::ios::binary)) {
        auto reader = binary_reader {fs};
        reader >> aspect_ratio;
        reader >> temp_directory;
        reader >> auto_save_time;
        reader >> show_status_bar;
      }
      
      console::write_line("Aspect ratio set to: {}", aspect_ratio);
      console::write_line("Temp directory is: {}", temp_directory);
      console::write_line("Auto save time set to: {}", auto_save_time);
      console::write_line("Show status bar: {}", show_status_bar);
    }
  }
};

startup_(program::main);

// This code produces the following output :
//
// Aspect ratio set to: 1.25
// Temp directory is: c:\Temp
// Auto save time set to: 10
// Show status bar: true

