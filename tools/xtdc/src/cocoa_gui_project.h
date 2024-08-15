#pragma once
#include "base_project.h"

namespace xtdc_command {
  class cocoa_gui_project : public base_project {
  public:
    explicit cocoa_gui_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_main(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
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
        xtd::string::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Window1.h",
        "  src/Window1.m",
        "  src/Program.m",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa\")",
        "set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})",
        xtd::string::format("set(MACOSX_BUNDLE_COPYRIGHT \"Copyright © {:L}\")", xtd::date_time::now()),
        xtd::string::format("set(MACOSX_BUNDLE_INFO_STRING \"{} application\")", name),
        xtd::string::format("set(MACOSX_BUNDLE_GUI_IDENTIFIER \"org.Company.{}\")", name),
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_include(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#import <Cocoa/Cocoa>",
        "",
        "/// @brief Represents the main NSWindow",
        "@interface Window1 : NSWindow {",
        "}",
        " /// @brief Initializes a new instance of the Window1 class.",
        "- (instancetype)init;",
        "- (BOOL)windowShouldClose:(id)sender;",
        "@end",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.h"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#import \"Window1.h\"",
        "",
        "@implementation Window1",
        "- (instancetype)init {",
        "  [super initWithContentRect:NSMakeRect(100, 500, 800, 450) styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable backing:NSBackingStoreBuffered defer:NO];",
        "  [self setTitle:@\"Window1\"];",
        "  [self setIsVisible:YES];",
        "  return self;",
        "}",
        "",
        "- (BOOL)windowShouldClose:(id)sender {",
        "   [NSApp terminate:sender];",
        "   return NO;",
        "}",
        "@end",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.m"), lines);
    }
    
    void create_main(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#import \"Window1.h\"",
        "",
        "// The main entry point for the application.",
        "auto main(int argc, char* argv[]) -> int {",
        "  [NSApplication sharedApplication];",
        "  [[[[Window1 alloc] init] autorelease] makeMainWindow];",
        "  [NSApp run];",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.m"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::string::format("project({} VERSION 1.0.0)", name));
      lines.push_back("set(SOURCES");
      auto [headers, sources] = get_objectivec_sources(path, path);
      for (auto file : headers)
        lines.push_back(xtd::string::format("  {}", file));
      for (auto file : sources)
        lines.push_back(xtd::string::format("  {}", file));
      lines.push_back(")");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa\")");
      lines.push_back("set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})");
      lines.push_back(xtd::string::format("set(MACOSX_BUNDLE_COPYRIGHT \"Copyright © {:L}\")", xtd::date_time::now()));
      lines.push_back(xtd::string::format("set(MACOSX_BUNDLE_INFO_STRING \"{} application\")", name));
      lines.push_back(xtd::string::format("set(MACOSX_BUNDLE_GUI_IDENTIFIER \"org.Company.{}\")", name));
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
