#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class c_console_project : public base_project {
  public:
    explicit c_console_project(const xtd::string& path) : base_project(path) {}
    
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
        xtd::string::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/program.c",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})",
        "",
        "# Install",
        xtd::string::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::string::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::string::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::string::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::string::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::string::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::string::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION bin CONFIGURATIONS Debug OPTIONAL)",
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION bin CONFIGURATIONS Release OPTIONAL)",
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION bin)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "#include <stdio.h>",
        "",
        "/* The main entry point for the application. */",
        "int main(int argc, char* argv[]) {",
        "  printf(\"Hello, World!\\n\");",
        "  return 0;",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "program.c"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::string::format("project({} VERSION 1.0.0)", name));
      lines.push_back("set(SOURCES");
      auto [headers, sources] = get_c_sources(path, path);
      for (auto file : headers)
        lines.push_back(xtd::string::format("  {}", file));
      for (auto file : sources)
        lines.push_back(xtd::string::format("  {}", file));
      lines.push_back(")");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set(CMAKE_C_STANDARD 11)");
      lines.push_back("set(CMAKE_C_STANDARD_REQUIRED ON)");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_executable(${PROJECT_NAME} ${SOURCES})");
      lines.push_back("");
      lines.push_back("# Install");
      lines.push_back(xtd::string::format("install(DIRECTORY include/. DESTINATION include/{})", name));
      lines.push_back(xtd::string::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name));
      lines.push_back("  \"include(CMakeFindDependencyMacro)\\n\"");
      lines.push_back("  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"");
      lines.push_back("  \"\\n\"");
      lines.push_back(xtd::string::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()));
      lines.push_back(xtd::string::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()));
      lines.push_back("  \"\\n\"");
      lines.push_back(xtd::string::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name));
      lines.push_back(xtd::string::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()));
      lines.push_back(")");
      lines.push_back(xtd::string::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name));
      lines.push_back("install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION bin CONFIGURATIONS Debug OPTIONAL)");
      lines.push_back("install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION bin CONFIGURATIONS Release OPTIONAL)");
      lines.push_back("install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION bin)");
      lines.push_back("install(EXPORT ${PROJECT_NAME} DESTINATION cmake)");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
