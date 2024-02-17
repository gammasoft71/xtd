#pragma once
#include "base_project.h"

namespace xtdc_command {
  class cpp_shared_library_project : public base_project {
  public:
    explicit cpp_shared_library_project(const xtd::ustring& path) : base_project(path) {}
    
    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "include") : xtd::io::path::combine(current_path(), "include"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_export(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::ustring& name) const {
      generate_cmakelists_txt(name, current_path());
    }
    
  private:
    void create_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(INCLUDES",
        "  include/class1.h",
        "  include/export.h",
        ")",
        "set(SOURCES",
        "  src/class1.cpp",
        ")",
        "source_group(include FILES ${INCLUDES})",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        xtd::ustring::format("add_definitions(-D{0}_EXPORT)", name.to_upper()),
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} SHARED ${INCLUDES} ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)",
        "",
        "# Install",
        xtd::ustring::format("install(DIRECTORY include/. DEStiffTINATION include/{})", name),
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
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)",
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)",
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_include(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains class1 class.",
        "#pragma once",
        "#include \"export.h\"",
        "",
        "/// @brief Represents the namespace that contains library objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the class1 class.",
        xtd::ustring::format("  class {}_export_ class1 {{", name.to_lower()),
        "  public:",
        "    /// @brief Initializes a new instance of the class1 class.",
        "    class1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "class1.h"), lines);
    }
    
    void create_export(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains export.",
        "#pragma once",
        "",
        "/// @cond",
        "#if defined(_WIN32)",
        xtd::ustring::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#    define {}_export_ __declspec(dllexport)", name.to_lower()),
        "#  else",
        xtd::ustring::format("#    define {}_export_ __declspec(dllimport)", name.to_lower()),
        "#  endif",
        "#else",
        xtd::ustring::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::ustring::format("#    define {}_export_ __attribute__((visibility (\"default\")))", name.to_lower()),
        "#  else",
        xtd::ustring::format("#    define {}_export_", name.to_lower()),
        "#  endif",
        "#endif",
        "/// @endcond",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "export.h"), lines);
    }
    
    void create_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"../include/class1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "class1::class1() {",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "class1.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::ustring::format("project({} VERSION 1.0.0)", name));
      auto [headers, sources] = get_cpp_sources(path, path);
      lines.push_back("set(INCLUDES");
      for (auto file : headers)
        lines.push_back(xtd::ustring::format("  {}", file));
      lines.push_back(")");
      lines.push_back("set(SOURCES");
      for (auto file : sources)
        lines.push_back(xtd::ustring::format("  {}", file));
      lines.push_back(")");
      lines.push_back("source_group(include FILES ${INCLUDES})");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set(CMAKE_CXX_STANDARD 17)");
      lines.push_back("set(CMAKE_CXX_STANDARD_REQUIRED ON)");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back(xtd::ustring::format("add_definitions(-D{0}_EXPORT)", name.to_upper()));
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_library(${PROJECT_NAME} SHARED ${INCLUDES} ${SOURCES})");
      lines.push_back("target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)");
      lines.push_back("");
      lines.push_back("# Install");
      lines.push_back(xtd::ustring::format("install(DIRECTORY include/. DEStiffTINATION include/{})", name));
      lines.push_back(xtd::ustring::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name));
      lines.push_back("  \"include(CMakeFindDependencyMacro)\\n\"");
      lines.push_back("  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"");
      lines.push_back("  \"\\n\"");
      lines.push_back(xtd::ustring::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()));
      lines.push_back(xtd::ustring::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()));
      lines.push_back("  \"\\n\"");
      lines.push_back(xtd::ustring::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name));
      lines.push_back(xtd::ustring::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()));
      lines.push_back(")");
      lines.push_back(xtd::ustring::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name));
      lines.push_back("install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)");
      lines.push_back("install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)");
      lines.push_back("install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)");
      lines.push_back("install(EXPORT ${PROJECT_NAME} DESTINATION cmake)");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
