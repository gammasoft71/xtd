#pragma once
#include "base_project.h"

namespace xtdc_command {
  class win32_gui_project : public base_project {
  public:
    explicit win32_gui_project(const xtd::ustring& path) : base_project(path) {}
    
    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::ustring& name) const {
      generate_cmakelists_txt(name, current_path());
    }
    
  private:
    void create_cmakelists_txt(const xtd::ustring& name) const {
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
        "set(SOURCES",
        "  src/Program.c",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} /ENTRY:wmainCRTStartup\")",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "add_definitions(-DUNICODE)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "#pragma comment(linker,\"\\\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")",
        "",
        "#include <Windows>",
        "",
        "struct window {",
        "  HWND handle = NULL;",
        "  WNDPROC defWndProc = NULL;",
        "};",
        "typedef struct window window;",
        "",
        "window window1;",
        "",
        "LRESULT CALLBACK Window1WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {",
        "  switch (message) {",
        "    case WM_CLOSE: PostQuitMessage(0); break;",
        "    default: break;",
        "  }",
        "  return CallWindowProc(window1.defWndProc, hwnd, message, wParam, lParam);",
        "}",
        "",
        "int wmain(int argc, wchar* argv[]) {",
        "  window1.handle = CreateWindowEx(0, WC_DIALOG, L\"Window1\", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 450, NULL, NULL, NULL, NULL);",
        "  window1.defWndProc = (WNDPROC)SetWindowLongPtr(window1.handle, GWLP_WNDPROC, (LONG_PTR)Window1WndProc);",
        "",
        "  ShowWindow(window1.handle, SW_SHOW);",
        "",
        "  MSG message;",
        "  while (GetMessage(&message, NULL, 0, 0))",
        "    DispatchMessage(&message);",
        "  return (int)message.wParam;",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.c"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::ustring::format("project({} VERSION 1.0.0)", name));
      lines.push_back("set(SOURCES");
      auto [headers, sources] = get_c_sources(path, path);
      for (auto file : headers)
        lines.push_back(xtd::ustring::format("  {}", file));
      for (auto file : sources)
        lines.push_back(xtd::ustring::format("  {}", file));
      lines.push_back(")");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set(CMAKE_C_STANDARD 11)");
      lines.push_back("set(CMAKE_C_STANDARD_REQUIRED ON)");
      lines.push_back("set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} /ENTRY:wmainCRTStartup\")");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("add_definitions(-DUNICODE)");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_executable(${PROJECT_NAME} WIN32 ${SOURCES})");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
