#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class appkit_gui_project : public base_project {
  public:
    explicit appkit_gui_project(const xtd::string& path) : base_project(path) {}
    
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
        xtd::string::format("project({} VERSION 1.0.0)", name),
        "",
        "# Projects",
        xtd::string::format("add_subdirectory({})", name),
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::string::format("project({} LANGUAGES Swift)", name),
        "set(SOURCES",
        "  src/main.swift",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -framework AppKit\")",
        "set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})",
        xtd::string::format("set(MACOSX_BUNDLE_COPYRIGHT \"Copyright © {:yyyy}\")", xtd::date_time::now()),
        xtd::string::format("set(MACOSX_BUNDLE_INFO_STRING \"{} application\")", name),
        xtd::string::format("set(MACOSX_BUNDLE_GUI_IDENTIFIER \"org.Company.{}\")", name),
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "import AppKit",
        "",
        "/// Represents the main window.",
        "class Window1: NSWindow, NSWindowDelegate {",
        "  init() {",
        "    super.init(",
        "      contentRect: NSRect(x: 100, y: 500, width: 800, height: 450),",
        "      styleMask: [.titled, .closable, .miniaturizable, .resizable],",
        "      backing: .buffered,",
        "      defer: false",
        "    )",
        "    self.title = \"Window1\"",
        "    self.delegate = self",
        "    self.makeKeyAndOrderFront(nil)",
        "  }",
        "  ",
        "  func windowShouldClose(_ sender: NSWindow) -> Bool {",
        "    NSApp.terminate(sender)",
        "    return false",
        "  }",
        "}",
        "",
        "/// The main entry point for the application.",
        "let app = NSApplication.shared",
        "let window = Window1()",
        "window.makeMain()",
        "app.run()",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "main.swift"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.add("cmake_minimum_required(VERSION 3.20)");
      lines.add("");
      lines.add("# Project");
      lines.add(xtd::string::format("project({} VERSION 1.0.0)", name));
      lines.add("set(SOURCES");
      auto sources = get_swift_sources(path, path);
      for (const auto& file : sources)
        lines.add(xtd::string::format("  {}", file));
      lines.add(")");
      lines.add("source_group(src FILES ${SOURCES})");
      lines.add("");
      lines.add("# Options");
      lines.add("set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -framework AppKit\")");
      lines.add("set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})");
      lines.add(xtd::string::format("set(MACOSX_BUNDLE_COPYRIGHT \"Copyright © {:yyyy}\")", xtd::date_time::now()));
      lines.add(xtd::string::format("set(MACOSX_BUNDLE_INFO_STRING \"{} application\")", name));
      lines.add(xtd::string::format("set(MACOSX_BUNDLE_GUI_IDENTIFIER \"org.Company.{}\")", name));
      lines.add("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.add("");
      lines.add("# Application properties");
      lines.add("add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
