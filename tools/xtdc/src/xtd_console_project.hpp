#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class xtd_console_project : public base_project {
  public:
    explicit xtd_console_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "properties") : xtd::io::path::combine(current_path(), "properties"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_cmakelists_txt(name);
      create_xtd_console_application_properties(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_assembly_info(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_console_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_console_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_xtd_console_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::string& name) const {
      generate_xtd_console_cmakelists_txt(name, current_path());
    }
    
  private:
    void create_cmakelists_txt(const xtd::string& name) const {
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
    
    void create_xtd_console_application_properties(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        xtd::string::format("target_default_namespace(\"{}\")", name),
        xtd::string::format("target_name(\"{}\")", name),
        xtd::string::format("target_startup(\"{}::program::main\" src/program.hpp)", name),
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
        "assembly_product(\"\")",
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
    
    void create_xtd_console_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::string::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/program.hpp",
        "  src/program.cpp",
        ")",
        "target_type(CONSOLE_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_xtd_console_include(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "/// @file",
        xtd::string::format("/// @brief Contains {}::program class.", name),
        xtd::string::format("/// @copyright Copyright (c) {} YourCompanyName. All rights reserved.", xtd::date_time::now().year()),
        "#pragma once",
        "#include <xtd/xtd>",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represents the main class.",
        xtd::string::format("  /// @remarks Contains the {}::program::main entry point method;", name),
        "  class program {",
        "  public:",
        "    /// @brief The main entry point for the application.",
        "    /// @param args The collection of arguments for the main entry point.",
        "    static auto main(const argument_collection& args) -> void;",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "program.hpp"), lines);
    }
    
    void create_xtd_console_source(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "#include \"program.hpp\"",
        "",
        xtd::string::format("using namespace {};", name),
        "",
        "auto program::main(const argument_collection& args) -> void {",
        "  println(\"Hello, World!\");",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "program.cpp"), lines);
    }
    
    void generate_xtd_console_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::string::format("project({})", name));
      lines.push_back("find_package(xtd REQUIRED)");
      lines.push_back("add_sources(");
      auto [headers, sources] = get_cpp_sources(path, path);
      for (auto file : headers)
        lines.push_back(xtd::string::format("  {}", file));
      for (auto file : sources)
        lines.push_back(xtd::string::format("  {}", file));
      lines.push_back(")");
      lines.push_back("target_type(CONSOLE_APPLICATION)");
      lines.push_back("");
      lines.push_back("# Install");
      lines.push_back("install_component()");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
