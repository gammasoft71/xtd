#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class winforms_gui_project : public base_project {
  public:
    explicit winforms_gui_project(const xtd::string& path) : base_project(path) {}
    
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
      std::vector<xtd::string> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::string::format("project({})", name),
        xtd::string::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
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
        "add_executable(${PROJECT_NAME} WIN32 ${SOURCES})",
        "set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES",
        "  Microsoft.CSharp",
        "  System",
        "  System.Drawing",
        "  System.Windows.Forms",
        ")",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "/// @file",
        "/// @brief Contains Form1 class.",
        "using System;",
        "using System.Drawing;",
        "using System.Windows.Forms;",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represents the Form1 class.",
        "  class Form1 : Form {",
        "    /// @brief Initializes a new instance of the Form1 class.",
        "    public Form1() {",
        "      Text = \"Form1\";",
        "      ClientSize = new Size(800, 450);",
        "    }",
        "",
        "    /// @brief The main entry point for the application.",
        "    [STAThread]",
        "    static void Main(string[] args) {",
        "      Application.EnableVisualStyles();",
        "      Application.Run(new Form1());",
        "    }",
        "  }",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.cs"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::string::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name));
      lines.push_back("include(CSharpUtilities)");
      lines.push_back("set(SOURCES");
      auto [sources, configs, xamls] = get_csharp_sources(path, path);
      for (auto file : sources)
        lines.push_back(xtd::string::format("  {}", file));
      for (auto file : configs)
        lines.push_back(xtd::string::format("  {}", file));
      for (auto file : xamls)
        lines.push_back(xtd::string::format("  {}", file));
      lines.push_back(")");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_executable(${PROJECT_NAME} WIN32 ${SOURCES})");
      lines.push_back("set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES");
      lines.push_back("  Microsoft.CSharp");
      lines.push_back("  System");
      lines.push_back("  System.Drawing");
      lines.push_back("  System.Windows.Forms");
      lines.push_back(")");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
