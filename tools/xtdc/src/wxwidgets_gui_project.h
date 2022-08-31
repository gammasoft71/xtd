#pragma once
#include "base_project.h"

namespace xtdc_command {
  class wxwidgets_gui_project : public base_project {
  public:
    explicit wxwidgets_gui_project(const xtd::ustring& path) : base_project(path) {}

    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_wxwidgets_gui_solution_cmakelists_txt(name);
      create_wxwidgets_gui_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_wxwidgets_gui_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_wxwidgets_gui_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_wxwidgets_gui_main(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void create_wxwidgets_gui_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        xtd::ustring::format("add_subdirectory({})", name)
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_wxwidgets_gui_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::ustring::format("project({} VERSION 1.0.0)", name),
        "set(SOURCES",
        "  src/Frame1.h",
        "  src/Frame1.cpp",
        "  src/Program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(wxWidgets REQUIRED)",
        "include(${wxWidgets_USE_FILE})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
        "target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_wxwidgets_gui_include(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains Frame1 class.",
        "#pragma once",
        "#include <wx/frame.h>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Frame1 : public wxFrame {",
        "  public:",
        "    /// @brief Initializes a new instance of the Frame1 class.",
        "    Frame1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Frame1.h"), lines);
    }
    
    void create_wxwidgets_gui_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Frame1.h\"",
        "",
        xtd::ustring::format("using namespace {};", name),
        "",
        "Frame1::Frame1() : wxFrame(nullptr, wxID_ANY, \"Frame1\", wxDefaultPosition, {800, 450}) {",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Frame1.cpp"), lines);
    }
    
    void create_wxwidgets_gui_main(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#include \"Frame1.h\"",
        "#include <wx/app.h>",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  // Represent the application",
        "  class Application : public wxApp {",
        "    bool OnInit() override {",
        "      (new Frame1())->Show();",
        "      return true;",
        "    }",
        "  };",
        "}",
        "",
        "// The main entry point for the application.",
        xtd::ustring::format("wxIMPLEMENT_APP({}::Application);", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.cpp.cpp"), lines);
    }
  };
}
