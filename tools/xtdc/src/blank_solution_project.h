#pragma once
#include "base_project.h"

namespace xtdc_command {
  class blank_solution_project : public base_project {
  public:
    explicit blank_solution_project(const xtd::string& path) : base_project(path) {}
    
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
