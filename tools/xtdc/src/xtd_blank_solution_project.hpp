#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class xtd_blank_solution_project : public base_project {
  public:
    explicit xtd_blank_solution_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      create_solution_cmakelists_txt(name);
    }
    
    void generate(const xtd::string& name) const {
      create_solution_cmakelists_txt(name);
    }
    
  private:
    void create_solution_cmakelists_txt(const xtd::string& name) const {
      std::vector<xtd::string> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::string::format("project({})", name),
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
