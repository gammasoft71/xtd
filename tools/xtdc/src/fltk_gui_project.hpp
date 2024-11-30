#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class fltk_gui_project : public base_project {
  public:
    explicit fltk_gui_project(const xtd::string& path) : base_project(path) {}
    
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
        "  src/Window1.hpp",
        "  src/Window1.cpp",
        "  src/Program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(FLTK REQUIRED)",
        "",
        "# Options",
        "if (MSVC)",
        "  set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup\")",
        "endif ()",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
        "target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})",
        "if (APPLE)",
        "  # Workaround: fltk.framework does not exist, so we have to replace it by libfltk.dylib",
        "  string(REPLACE \"libfltk_images\" \"libfltk\" FLTK_LIBRARY_NAME \"${FLTK_IMAGES_LIBRARY_RELEASE}\")",
        "  string(REPLACE \"/usr/local/fltk.framework\" \"${FLTK_LIBRARY_NAME}\" FLTK_LIBRARIES \"${FLTK_LIBRARIES}\")",
        "  endif()",
        "target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_include(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#pragma once",
        "#include <FL/Fl_Window.H>",
        "",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Window1 : public Fl_Window {",
        "  public:",
        "    /// @brief Initializes a new instance of the Window1 class.",
        "    Window1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.hpp"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#include \"Window1.hpp\"",
        "",
        xtd::string::format("using namespace {};", name),
        "",
        "Window1::Window1() : Fl_Window(100, 100, 800, 450, \"Window1\") {",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.cpp"), lines);
    }
    
    void create_main(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#include \"Window1.hpp\"",
        "#include <FL/Fl.H>",
        "",
        xtd::string::format("using namespace {};", name),
        "",
        "// The main entry point for the application.",
        "auto main(int argc, char* argv[]) -> int {",
        "  Window1 window;",
        "  window.show(argc, argv);",
        "  return Fl::run();",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::string::format("project({} VERSION 1.0.0)", name));
      lines.push_back("set(SOURCES");
      auto [headers, sources] = get_cpp_sources(path, path);
      for (auto file : headers)
        lines.push_back(xtd::string::format("  {}", file));
      for (auto file : sources)
        lines.push_back(xtd::string::format("  {}", file));
      lines.push_back(")");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back("find_package(FLTK REQUIRED)");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set(CMAKE_CXX_STANDARD 17)");
      lines.push_back("set(CMAKE_CXX_STANDARD_REQUIRED ON)");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})");
      lines.push_back("target_include_directories(${PROJECT_NAME} PRIVATE ${FLTK_INCLUDE_DIR})");
      lines.push_back("if (APPLE)");
      lines.push_back("  # Workaround: fltk.framework does not exist, so we have to replace it by libfltk.dylib");
      lines.push_back("  string(REPLACE \"libfltk_images\" \"libfltk\" FLTK_LIBRARY_NAME \"${FLTK_IMAGES_LIBRARY_RELEASE}\")");
      lines.push_back("  string(REPLACE \"/usr/local/fltk.framework\" \"${FLTK_LIBRARY_NAME}\" FLTK_LIBRARIES \"${FLTK_LIBRARIES}\")");
      lines.push_back("  endif()");
      lines.push_back("target_link_libraries(${PROJECT_NAME} ${FLTK_LIBRARIES})");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
