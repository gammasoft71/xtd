#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
  inline static const ustring file_name = "app_settings.dat";
public:
  static auto main() {
    write_default_values();
    display_values();
  }
  
  static void write_default_values() {
    using_(fstream fs = file::open(file_name, ios::out | ios::binary | ios::trunc)) {
      binary_writer writer(fs);
      writer.write(1.250F);
      writer.write(R"(c:\Temp)");
      writer.write(10);
      writer.write(true);
    }
  }
  
  static void display_values() {
    float aspect_ratio;
    ustring temp_directory;
    int auto_save_time;
    bool show_status_bar;
    
    if (file::exists(file_name)) {
      using_(fstream fs = file::open(file_name, ios::in | ios::binary)) {
        binary_reader reader(fs);
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

startup_(program);

// This code produces the following output :
//
// Aspect ratio set to: 1.25
// Temp directory is: c:\Temp
// Auto save time set to: 10
// Show status bar: true

