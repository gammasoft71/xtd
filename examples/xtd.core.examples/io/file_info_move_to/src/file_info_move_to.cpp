#include <xtd/io/file_info>
#include <xtd/io/directory_info>
#include <xtd/io/path>
#include <xtd/console>
#include <xtd/startup>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
private:
  inline static ustring source_path = path::combine(environment::get_folder_path(environment::special_folder::my_documents), "file_info_test_directory", "move_from", "from_file.xml");
  inline static ustring dest_path = path::combine(environment::get_folder_path(environment::special_folder::my_documents), "file_info_test_directory", "dest_filexml");
  
public:
  //
  // The main entry point for the application.
  //
  static auto main() {
    // Change Console properties to make it obvious that
    // the application is starting.
    console::clear();
    // Move it to the upper left corner of the screen.
    console::set_window_position(0, 0);
    // Make it very large.
    console::set_window_size(console::largest_window_width() - 24, console::largest_window_height() - 16);
    console::write_line("Welcome.");
    console::write_line("This application demonstrates the file_info::move_to method.");
    console::write_line("Press any key to start.");
    console::read_key();
    console::write("    Checking whether ");
    console::write(source_path);
    console::write_line(" exists.");
    auto f_info = file_info {source_path};
    ensure_source_file_exists();
    display_file_properties(f_info);
    console::write_line("Preparing to move the file to ");
    console::write(dest_path);
    console::write_line(".");
    move_file(f_info);
    display_file_properties(f_info);
    console::write_line("Preparing to delete directories.");
    delete_files();
    console::write_line("Press the ENTER key to close this application.");
    console::read_key();
  }
  
private:
  //
  // Moves the supplied file_info instance to dest_path.
  //
  static void move_file(file_info& f_info) {
    try {
      f_info.move_to(dest_path);
      console::write_line("File moved to ");
      console::write_line(dest_path);
    } catch (const system_exception& ex) {
      display_exception(ex);
    }
  }
  
  //
  // Ensures that the test directories
  // and the file FromFile.xml all exist.
  //
  static void ensure_source_file_exists() {
    auto f_info = file_info {source_path};
    auto dir_path = f_info.directory().full_name();
    if (!directory::exists(dir_path))
      directory::create_directory(dir_path);
    if (file::exists(dest_path))
      file::remove(dest_path);
    console::write("Creating file ");
    console::write(f_info.full_name());
    console::write_line(".");
    try {
      if (!f_info.exists()) {
        console::write_line("Adding data to the file.");
        write_file_content(10);
        console::write_line("Successfully created the file.");
      }
    } catch (const system_exception& ex) {
      display_exception(ex);
    }
  }
  
  //
  // Creates and saves an Xml file to source_path.
  //
  static void write_file_content(int total_element) {
    auto lines = vector<ustring> {};
    lines.push_back("<?xml version=\"1.0\" standalone=\"yes\"?>");
    for (auto index  = 0; index < total_element; ++index)
      lines.push_back(ustring::format("<MyElement Index=\"{0}\">\nMyElement at position {0}.", index));
    file::write_all_lines(source_path, lines);
  }
  
  //
  // Displays FullName, CreationTime, and LastWriteTime of the supplied
  // file_info instance, then displays the text of the file.
  //
  static void display_file_properties(const file_info& f_info) {
    console::write_line("The file_info instance shows these property values.");
    try {
      console::write("Full_name: ");
      console::write_line(f_info.full_name());
      console::write("creation_time: ");
      console::write_line(f_info.creation_time());
      console::write("last_write_time: ");
      console::write_line(f_info.last_write_time());
      console::write_line();
      console::write_line("file contents:");
      console::write_line();
      stream_reader reader(f_info.full_name());
      while (!reader.end_of_stream())
        console::write_line(reader.read_line());
      console::write_line();
    } catch (const system_exception& ex) {
      display_exception(ex);
    }
  }
  
  //
  // Deletes the test directory and all its files and subdirectories.
  //
  static void delete_files() {
    try {
      auto d_info = directory_info {path::combine(environment::get_folder_path(environment::special_folder::my_documents), "file_infoTestDirectory")};
      if (d_info.exists()) {
        d_info.remove(true);
        console::write_line("Successfully deleted directories and files.");
      }
    } catch (const system_exception& ex) {
      display_exception(ex);
    }
  }
  
  //
  // Displays information about the supplied Exception. This
  // code is not suitable for production applications.
  //
  static void display_exception(const system_exception& ex) {
    auto s = ustring::empty_string;
    s += "An exception of type \"";
    s += typeof_(ex).full_name();
    s += "\" has occurred.\r\n";
    s += ex.message();
    s += "\r\nStack trace information:\r\n";
    s += ex.stack_trace();
    console::write_line(s);
  }
};

startup_(program);

// This code produces the following output :
// results may vary based on the computer/file structure/etc.:
//
// Welcome.
// This application demonstrates the file_info.move_to method.
// Press any key to start.
//
//     Checking whether C:\Documents and Settings\MyComputer\My Documents\file_infoTestDirectory\MoveFrom\FromFile.xml exists.
// Creating file C:\Documents and Settings\MyComputer\My Documents\file_infoTestDirectory\MoveFrom\FromFile.xml.
// Adding data to the file.
// Successfully created the file.
// The file_info instance shows these property values.
// FullName: C:\Documents and Settings\MyComputer\My Documents\file_infoTestDirectory\MoveFrom\FromFile.xml
// CreationTime: 4/18/2006 1:24:19 PM
// LastWriteTime: 4/18/2006 1:24:19 PM
//
// File contents:
//
// <?xml version="1.0" standalone="yes"?>
// <MyElement Index="0">
// MyElement at position 0.
// <MyElement Index="1">
// MyElement at position 1.
// <MyElement Index="2">
// MyElement at position 2.
// <MyElement Index="3">
// MyElement at position 3.
// <MyElement Index="4">
// MyElement at position 4.
// <MyElement Index="5">
// MyElement at position 5.
// <MyElement Index="6">
// MyElement at position 6.
// <MyElement Index="7">
// MyElement at position 7.
// <MyElement Index="8">
// MyElement at position 8.
// <MyElement Index="9">
// MyElement at position 9.

// Preparing to move the file to
// C:\Documents and Settings\MYComputer\My Documents\file_infoTestDirectory\DestFile.xml.
// File moved to
// C:\Documents and Settings\MYComputer\My Documents\file_infoTestDirectory\DestFile.xml
// The file_info instance shows these property values.
// FullName: C:\Documents and Settings\MYComputer\My Documents\file_infoTestDirectory\DestFile.xml
// CreationTime: 4/18/2006 1:24:19 PM
// LastWriteTime: 4/18/2006 1:24:19 PM
//
// File contents:
//
// <?xml version="1.0" standalone="yes"?>
// <MyElement Index="0">
// MyElement at position 0.
// <MyElement Index="1">
// MyElement at position 1.
// <MyElement Index="2">
// MyElement at position 2.
// <MyElement Index="3">
// MyElement at position 3.
// <MyElement Index="4">
// MyElement at position 4.
// <MyElement Index="5">
// MyElement at position 5.
// <MyElement Index="6">
// MyElement at position 6.
// <MyElement Index="7">
// MyElement at position 7.
// <MyElement Index="8">
// MyElement at position 8.
// <MyElement Index="9">
// MyElement at position 9.
//
// Preparing to delete directories.
// Successfully deleted directories and files.
// Press the ENTER key to close this application.
