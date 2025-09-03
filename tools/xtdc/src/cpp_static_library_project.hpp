#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class cpp_static_library_project : public base_project {
  public:
    explicit cpp_static_library_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "include") : xtd::io::path::combine(current_path(), "include"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
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
        "set(INCLUDES",
        "  include/class1.hpp",
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
        "",
        "# Application properties",
        "add_library(${PROJECT_NAME} STATIC ${INCLUDES} ${SOURCES})",
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
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)",
        "install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)",
        "install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)",
        "install(EXPORT ${PROJECT_NAME} DESTINATION cmake)",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_include(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "/// @file",
        "/// @brief Contains class1 class.",
        "#pragma once",
        "",
        "/// @brief Represents the namespace that contains library objects.",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represents the class1 class.",
        "  class class1 {",
        "  public:",
        "    /// @brief Initializes a new instance of the class1 class.",
        "    class1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "class1.hpp"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "#include \"../include/class1.hpp\"",
        "",
        xtd::string::format("using namespace {};", name),
        "",
        "class1::class1() {",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "class1.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.add("cmake_minimum_required(VERSION 3.20)");
      lines.add("");
      lines.add("# Project");
      lines.add(xtd::string::format("project({} VERSION 1.0.0)", name));
      auto [headers, sources] = get_cpp_sources(path, path);
      lines.add("set(INCLUDES");
      for (auto file : headers)
        lines.add(xtd::string::format("  {}", file));
      lines.add(")");
      lines.add("set(SOURCES");
      for (auto file : sources)
        lines.add(xtd::string::format("  {}", file));
      lines.add(")");
      lines.add("source_group(include FILES ${INCLUDES})");
      lines.add("source_group(src FILES ${SOURCES})");
      lines.add("");
      lines.add("# Options");
      lines.add("set(CMAKE_CXX_STANDARD 17)");
      lines.add("set(CMAKE_CXX_STANDARD_REQUIRED ON)");
      lines.add("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.add("");
      lines.add("# Application properties");
      lines.add("add_library(${PROJECT_NAME} STATIC ${INCLUDES} ${SOURCES})");
      lines.add("target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)");
      lines.add("");
      lines.add("# Install");
      lines.add(xtd::string::format("install(DIRECTORY include/. DESTINATION include/{})", name));
      lines.add(xtd::string::format("file(WRITE ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake", name));
      lines.add("  \"include(CMakeFindDependencyMacro)\\n\"");
      lines.add("  \"include(\\\"\\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\\\")\\n\"");
      lines.add("  \"\\n\"");
      lines.add(xtd::string::format("  \"get_filename_component({}_INCLUDE_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../include\\\" ABSOLUTE)\\n\"", name.to_upper()));
      lines.add(xtd::string::format("  \"get_filename_component({}_LIBRARIES_DIRS \\\"\\${{CMAKE_CURRENT_LIST_DIR}}/../lib\\\" ABSOLUTE)\\n\"", name.to_upper()));
      lines.add("  \"\\n\"");
      lines.add(xtd::string::format("  \"set({}_LIBRARIES {})\\n\"", name.to_upper(), name));
      lines.add(xtd::string::format("  \"set({}_FOUND TRUE)\\n\"", name.to_upper()));
      lines.add(")");
      lines.add(xtd::string::format("install(FILES ${{CMAKE_CURRENT_BINARY_DIR}}/{}Config.cmake DESTINATION cmake)", name));
      lines.add("install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)");
      lines.add("install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)");
      lines.add("install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)");
      lines.add("install(EXPORT ${PROJECT_NAME} DESTINATION cmake)");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
