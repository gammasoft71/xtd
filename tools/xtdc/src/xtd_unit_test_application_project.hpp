#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class xtd_unit_test_application_project : public base_project {
  public:
    explicit xtd_unit_test_application_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "properties") : xtd::io::path::combine(current_path(), "properties"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_application_properties(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_assembly_info(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::string& name) const {
      generate_cmakelists_txt(name, current_path());
    }
    
  private:
    void create_solution_cmakelists_txt(const xtd::string& name) const {
      auto lines = xtd::array<xtd::string> {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::string::format("project({} VERSION 1.0.0)", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::string::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_application_properties(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        xtd::string::format("target_default_namespace(\"{}\")", name),
        xtd::string::format("target_name(\"{}\")", name),
        xtd::string::format("target_startup(tunit_main_)", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "target_properties.cmake"), lines);
    }
    
    void create_assembly_info(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "# Information about this assembly is defined by the following attributes.",
        "# Change them to the values specific to your project.",
        "",
        xtd::string::format("assembly_title(\"{}\")", name),
        "assembly_description(\"\")",
        "assembly_company(\"\")",
        xtd::string::format("assembly_product(\"{}\")", name),
        xtd::string::format("assembly_copyright(\"Copyright © YourCompanyName {}\")", xtd::date_time::now().year()),
        "assembly_trademark(\"\")",
        "",
        "# The following GUID is for the ID of the typelib if this project is exposed to COM",
        "",
        xtd::string::format("assembly_guid(\"{}\")", xtd::guid::new_guid()),
        "",
        "# The assembly version has the format \"{Major}.{Minor}.{Build}.{Revision}\".",
        "# In not specify or empty or \"*\" the cmake project version is used.",
        "",
        "assembly_version(\"*\")",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "assembly_info.cmake"), lines);
    }
    
    void create_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::string::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/unit_test1.cpp",
        ")",
        "target_type(TEST_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "#include <xtd/tunit/assert>",
        "#include <xtd/tunit/test_class_attribute>",
        "#include <xtd/tunit/test_method_attribute>",
        "",
        "using namespace xtd::tunit;",
        "",
        xtd::string::format("namespace {} {{", name),
        "  class test_class_(unit_test1) {",
        "  public:",
        "    auto test_method_(test_method1) {",
        "      assert::ignore(\"Hello, World!\");",
        "    }",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "unit_test1.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.add("cmake_minimum_required(VERSION 3.20)");
      lines.add("");
      lines.add("# Project");
      lines.add(xtd::string::format("project({})", name));
      lines.add("find_package(xtd REQUIRED)");
      lines.add("add_sources(");
      auto [headers, sources] = get_cpp_sources(path, path);
      for (auto file : headers)
        lines.add(xtd::string::format("  {}", file));
      for (auto file : sources)
        lines.add(xtd::string::format("  {}", file));
      lines.add(")");
      lines.add("target_type(TEST_APPLICATION)");
      lines.add("");
      lines.add("# Install");
      lines.add("install_component()");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
