#pragma once
#include "base_project.h"

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
      std::vector<xtd::string> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::string::format("project({})", name),
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
      std::vector<xtd::string> lines{
        xtd::string::format("target_default_namespace(\"{}\")", name),
        xtd::string::format("target_name(\"{}\")", name),
        xtd::string::format("target_startup(\"{}::program::main\" src/program.h)", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "target_properties.cmake"), lines);
    }
    
    void create_assembly_info(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines{
        xtd::string::format("assembly_title(\"{}\")", name),
        "assembly_description(\"\")",
        "assembly_company(\"\")",
        "assembly_product(\"\")",
        xtd::string::format("assembly_copyright(\"Copyright © YourCompanyName {}\")", xtd::date_time::now().year()),
        "assembly_trademark(\"\")",
        "assembly_version(\"1.0.0\")",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "assembly_info.cmake"), lines);
    }

    void create_xtd_console_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::string::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/program.h",
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
      std::vector<xtd::string> lines {
        "/// @file",
        "/// @brief Contains program class.",
        "#pragma once",
        "#include <xtd/collections/generic/list>",
        "#include <xtd/string>",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represents the main class.",
        "  class program {",
        "  public:",
        "    /// @brief The main entry point for the application.",
        "    static auto main(const xtd::collections::generic::list<xtd::string>& args) -> void;",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "program.h"), lines);
    }
    
    void create_xtd_console_source(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#include \"program.h\"",
        "#include <xtd/console>",
        "",
        xtd::string::format("using namespace {};", name),
        "using namespace xtd;",
        "using namespace xtd::collections::generic;",
        "",
        "auto program::main(const list<string>& args) -> void {",
        "  console::write_line(\"Hello, World!\");",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "program.cpp"), lines);
    }
    
    void generate_xtd_console_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines;
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
