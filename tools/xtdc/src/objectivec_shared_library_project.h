#pragma once
#include "base_project.h"

namespace xtdc_command {
  class objectivec_shared_library_project : public base_project {
  public:
    explicit objectivec_shared_library_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "include") : xtd::io::path::combine(current_path(), "include"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_header(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_export(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
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
        xtd::string::format("project({} VERSION 1.0.0)", name),
        "set(INCLUDES",
        "  include/Class1.h",
        "  include/export.hpp",
        ")",
        "set(SOURCES",
        "  src/Class1.m",
        ")",
        "source_group(include FILES ${INCLUDES})",
        "source_group(src FILES ${SOURCES})",
        xtd::string::format("add_definitions(-D{0}_EXPORT)", name.to_upper()),
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} SHARED ${INCLUDES} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
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
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_export(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#pragma once",
        xtd::string::format("#if defined({0}_EXPORT)", name.to_upper()),
        xtd::string::format("#  define {0}_export_ __attribute__((visibility (\"default\")))", name.to_lower()),
        "#else",
        xtd::string::format("#  define {0}_export_", name.to_lower()),
        "#endif",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "export.hpp"), lines);
    }
    
    void create_header(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#import \"Export.h\"",
        "#import <Foundation/Foundation>",
        "",
        xtd::string::format("{0}_export_ @interface Class1 : NSObject", name.to_lower()),
        "",
        "@end",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "Class1.h"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#import \"../include/Class1.h\"",
        "",
        "@implementation Class1",
        "",
        "@end"
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Class1.m"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::string::format("project({} VERSION 1.0.0)", name));
      auto [headers, sources] = get_objectivec_sources(path, path);
      lines.push_back("set(INCLUDES");
      for (auto file : headers)
        lines.push_back(xtd::string::format("  {}", file));
      lines.push_back(")");
      lines.push_back("set(SOURCES");
      for (auto file : sources)
        lines.push_back(xtd::string::format("  {}", file));
      lines.push_back(")");
      lines.push_back("source_group(include FILES ${INCLUDES})");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back(xtd::string::format("add_definitions(-D{0}_EXPORT)", name.to_upper()));
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_library(${PROJECT_NAME} SHARED ${INCLUDES} ${SOURCES})");
      lines.push_back("target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)");
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
      lines.push_back("install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)");
      lines.push_back("install(EXPORT ${PROJECT_NAME} DESTINATION cmake)");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
