#pragma once
#include "base_project.h"

namespace xtdc_command {
  class qt6_gui_project : public base_project {
  public:
    explicit qt6_gui_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) {
        create_solution_cmakelists_txt(name);
        create_solution_qmake_pro(name);
      }
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_qmake_pro(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_main(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::string& name) const {
      generate_cmakelists_txt(name, current_path());
      generate_qmake_pro(name, current_path());
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
    
    void create_solution_qmake_pro(const xtd::string& name) const {
      std::vector<xtd::string> lines {
        "TEMPLATE = subdirs",
        xtd::string::format("SUBDIRS = {}", name),
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), xtd::string::format("{}.pro", name)), lines);
    }
    
    void create_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::string::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Window1.h",
        "  src/Window1.cpp",
        "  src/Program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(Qt6 COMPONENTS Widgets REQUIRED)",
        "",
        "# Options",
        "set(CMAKE_AUTOMOC ON)",
        "set(CMAKE_AUTORCC ON)",
        "set(CMAKE_AUTOUIC ON)",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
        "target_link_libraries(${PROJECT_NAME} Qt6::Widgets)",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_qmake_pro(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "CONFIG += c++17",
        "QT = widgets",
        "HEADERS = src/Window1.h",
        "SOURCES = src/Window1.cpp src/Program.cpp",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", xtd::string::format("{}.pro", name)), lines);
    }
    
    void create_include(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#pragma once",
        "#include <QMainWindow>",
        "",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Window1 : public QMainWindow {",
        "    Q_OBJECT",
        "  public:",
        "    /// @brief Initializes a new instance of the Window1 class.",
        "    Window1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.h"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#include \"Window1.h\"",
        "",
        xtd::string::format("using namespace {};", name),
        "",
        "Window1::Window1() {",
        "  setWindowTitle(\"Window1\");",
        "  move(100, 100);",
        "  resize(800, 450);",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.cpp"), lines);
    }
    
    void create_main(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#include \"Window1.h\"",
        "#include <QApplication>",
        "",
        xtd::string::format("using namespace {};", name),
        "",
        "// The main entry point for the application.",
        "auto main(int argc, char* argv[]) -> int {",
        "  QApplication application(argc, argv);",
        "  Window1 window1;",
        "  window1.show();",
        "  return application.exec();",
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
      lines.push_back("find_package(Qt6 COMPONENTS Widgets REQUIRED)");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set(CMAKE_AUTOMOC ON)");
      lines.push_back("set(CMAKE_AUTORCC ON)");
      lines.push_back("set(CMAKE_AUTOUIC ON)");
      lines.push_back("set(CMAKE_CXX_STANDARD 17)");
      lines.push_back("set(CMAKE_CXX_STANDARD_REQUIRED ON)");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})");
      lines.push_back("target_link_libraries(${PROJECT_NAME} Qt6::Widgets)");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void generate_qmake_pro(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines;
      lines.push_back("CONFIG += c++17");
      lines.push_back("QT = widgets");
      auto [headers, sources] = get_cpp_sources(path, path);
      lines.push_back(xtd::string::format("HEADERS = {}", xtd::string::join(" ", headers)));
      lines.push_back(xtd::string::format("SOURCES = {}", xtd::string::join(" ", sources)));
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", xtd::string::format("{}.pro", name)), lines);
    }
  };
}
