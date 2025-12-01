#pragma once
#include <xtd/io/path>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

namespace xtdc_command {
  class project_base static_ {
  protected:
    static xtd::string get_full_path() noexcept {return xtd::environment::get_folder_path(xtd::environment::special_folder::xtd_resources);}
    
    static xtd::string get_project_full_path_from_path(const xtd::string& path) noexcept {
      if (xtd::string::is_empty(path) || path == ".") return xtd::environment::current_directory();
      else if (path == "..") {
        auto directories = xtd::collections::generic::list<xtd::string> {xtd::environment::current_directory().split(xtd::io::path::directory_separator_char())};
        if (directories.count() < 2) return "";
        directories.remove_at(directories.count() - 2);
        return xtd::io::path::combine(directories);
      }
      return xtd::io::path::get_full_path(path);
    }
    
    static xtd::string get_project_name_from_path(const xtd::string& path) noexcept {
      auto directories = get_project_full_path_from_path(path).split(xtd::io::path::directory_separator_char());
      if (directories.length() == 0) return "";
      return directories[directories.length() - 1];
    }
    
    static void write_error(const string& message) {
      xtd::console::foreground_color(xtd::console_color::red);
      xtd::console::write(message);
      xtd::console::reset_color();
    }
    
    static void write_line_error(const string& message) {
      xtd::console::foreground_color(xtd::console_color::red);
      xtd::console::write_line(message);
      xtd::console::reset_color();
    }
  };
}
