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
      writer.write(1.250F);
      writer.write(R"(c:\Temp)");
      writer.write(10);
      writer.write(true);
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
        aspect_ratio = reader.read_single();
        temp_directory = reader.read_string();
        auto_save_time = reader.read_int32();
        show_status_bar = reader.read_boolean();
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

