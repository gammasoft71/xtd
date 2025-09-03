#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class csharp_console_project : public base_project {
  public:
    explicit csharp_console_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
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
        xtd::string::format("project({})", name),
        xtd::string::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::string::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name),
        "include(CSharpUtilities)",
        "set(SOURCES",
        "  src/Program.cs",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "/// @file",
        "/// @brief Contains Program class.",
        "using System;",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represents the main class.",
        "  class Program {",
        "    /// @brief The main entry point for the application.",
        "    static void Main(string[] args) {",
        "      Console.WriteLine(\"Hello, World!\");",
        "    }",
        "  }",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.cs"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.add("cmake_minimum_required(VERSION 3.20)");
      lines.add("");
      lines.add("# Project");
      lines.add(xtd::string::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name));
      lines.add("include(CSharpUtilities)");
      lines.add("set(SOURCES");
      auto [sources, configs, xamls] = get_csharp_sources(path, path);
      for (auto file : sources)
        lines.add(xtd::string::format("  {}", file));
      for (auto file : configs)
        lines.add(xtd::string::format("  {}", file));
      for (auto file : xamls)
        lines.add(xtd::string::format("  {}", file));
      lines.add(")");
      lines.add("source_group(src FILES ${SOURCES})");
      lines.add("");
      lines.add("# Options");
      lines.add("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.add("");
      lines.add("# Application properties");
      lines.add("add_executable(${PROJECT_NAME} ${SOURCES})");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
