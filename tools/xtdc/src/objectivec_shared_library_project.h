#pragma once
#include "base_project.h"

namespace xtdc_command {
  class objectivec_shared_library_project : public base_project {
  public:
    explicit objectivec_shared_library_project(const xtd::ustring& path) : base_project(path) {}

    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "include") : xtd::io::path::combine(current_path(), "include"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_objectivec_shared_library_solution_cmakelists_txt(name);
      create_objectivec_shared_library_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_objectivec_shared_library_header(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_objectivec_shared_library_export(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_objectivec_shared_library_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
  private:
    void create_objectivec_shared_library_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_objectivec_shared_library_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(HEADERS",
        "  include/Class1.h",
        "  include/Export.h",
        ")",
        "set(SOURCES",
        "  src/Class1.m",
        ")",
        "source_group(include FILES ${HEADERS})",
        "source_group(src FILES ${SOURCES})",
        xtd::ustring::format("add_definitions(-D{0}_EXPORT)", name.to_upper()),
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DESTINATION include/{})", name),
        xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name),
        "  \"include(CMakeFindDependencyMacro)\\n\"",
        "  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"",
        "  \"\\n\"",
        xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()),
        xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()),
        "  \"\\n\"",
        xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name),
        xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()),
        ")",
        xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name),
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_objectivec_shared_library_export(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#pragma once",
        xtd::ustring::format("#if defined({0}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#  define {0}_export_ __attribute__((visibility (\"default\")))", name.to_lower()),
        "#else",
        xtd::ustring::format("#  define {0}_export_", name.to_lower()),
        "#endif",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "Export.h"), lines);
    }
    
    void create_objectivec_shared_library_header(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#import \"Export.h\"",
        "#import <Foundation/Foundation.h>",
        "",
        xtd::ustring::format("{0}_export_ @interface Class1 : NSObject", name.to_lower()),
        "",
        "@end",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "Class1.h"), lines);
    }
    
    void create_objectivec_shared_library_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#import \"../include/Class1.h\"",
        "",
        "@implementation Class1",
        "",
        "@end"
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Class1.m"), lines);
    }
  };
}
