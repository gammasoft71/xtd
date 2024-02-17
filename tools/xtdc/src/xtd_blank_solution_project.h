#pragma once
#include "base_project.h"

namespace xtdc_command {
  class xtd_blank_solution_project : public base_project {
  public:
    explicit xtd_blank_solution_project(const xtd::ustring& path) : base_project(path) {}
    
    void create(const xtd::ustring& name, bool create_solution) const {
      create_solution_cmakelists_txt(name);
    }
    
    void generate(const xtd::ustring& name) const {
      create_solution_cmakelists_txt(name);
    }
    
  private:
    void create_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "",
        "# Install",
        "install_package()",
        "",
        "# Projects"
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
  };
}
