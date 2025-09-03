#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class xtd_c_unit_test_application_project : public base_project {
  public:
    explicit xtd_c_unit_test_application_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      create_cmakelists_txt(name, current_path());
    }
    
    void generate(const xtd::string& name) const {
      generate_cmakelists_txt(name, current_path());
    }
    
  private:
    void create_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
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
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.add("cmake_minimum_required(VERSION 3.20)");
      lines.add("");
      lines.add("# Project");
      lines.add(xtd::string::format("project({})", name));
      lines.add("find_package(xtd REQUIRED)");
      lines.add("add_sources(");
      auto [headers, sources] = get_c_sources(path, path);
      for (auto file : headers)
        lines.add(xtd::string::format("  {}", file));
      for (auto file : sources)
        lines.add(xtd::string::format("  {}", file));
      lines.add(")");
      lines.add("target_type(TEST_APPLICATION)");
      lines.add("");
      lines.add("# Install");
      lines.add("install_package()");
      lines.add("");
      lines.add("# Projects");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
  };
}
