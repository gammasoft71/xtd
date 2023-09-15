#pragma once
#include <xtd/io/path>
#include <xtd/environment>
#include <xtd/ustring>

namespace xtdc_command {
  class project_base static_ {
  protected:
    static xtd::ustring get_full_path() noexcept {return xtd::environment::get_folder_path(xtd::environment::special_folder::xtd_resources);}
    
    static xtd::ustring get_project_full_path_from_path(const xtd::ustring& path) noexcept {
      if (path.empty() || path == ".") return xtd::environment::current_directory();
      else if (path == "..") {
        auto directories = xtd::environment::current_directory().split({xtd::io::path::directory_separator_char()});
        if (directories.size() < 2) return "";
        directories.erase(directories.begin() + directories.size() - 2);
        return xtd::io::path::combine(directories);
      }
      return xtd::io::path::get_full_path(path);
    }
    
    static xtd::ustring get_project_name_from_path(const xtd::ustring& path) noexcept {
      auto directories = get_project_full_path_from_path(path).split({xtd::io::path::directory_separator_char()});
      if (directories.size() == 0) return "";
      return directories[directories.size() - 1];
    }
  };
}
