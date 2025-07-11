#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class win32_gui_project : public base_project {
  public:
    explicit win32_gui_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::string& name) const {
      generate_cmakelists_txt(name, current_path());
    }
    
  private:
    void create_cmakelists_txt(const xtd::string& name) const {
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
        "  src/Program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "add_definitions(-DNOMINMAX)",
        "add_definitions(-DUNICODE)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "#pragma comment(linker,\"\\\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")",
        "",
        "#include <Windows.h>",
        "",
        "struct window {",
        "  HWND hwnd;",
        "  WNDPROC defWndProc;",
        "};",
        "",
        "auto window1 = window {nullptr, nullptr};",
        "",
        "auto CALLBACK Window1WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) -> LRESULT {",
        "  switch (message) {",
        "    case WM_CLOSE: PostQuitMessage(0); break;",
        "    default: return CallWindowProc(window1.defWndProc, hwnd, message, wParam, lParam);",
        "  }",
        "  return 0;",
        "}",
        "",
        "auto WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) -> int {",
        "  window1.hwnd = CreateWindowEx(0, WC_DIALOG, L\"Window1\", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 450, nullptr, nullptr, hInstance, nullptr);",
        "  window1.defWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(window1.hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(Window1WndProc)));",
        "",
        "  auto message = MSG {};",
        "  while (GetMessage(&message, nullptr, 0, 0))",
        "    DispatchMessage(&message);",
        "  return static_cast<int>(message.wParam);",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Program.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.add("cmake_minimum_required(VERSION 3.20)");
      lines.add("");
      lines.add("# Project");
      lines.add(xtd::string::format("project({} VERSION 1.0.0)", name));
      lines.add("set(SOURCES");
      auto [headers, sources] = get_cpp_sources(path, path);
      for (auto file : headers)
        lines.add(xtd::string::format("  {}", file));
      for (auto file : sources)
        lines.add(xtd::string::format("  {}", file));
      lines.add(")");
      lines.add("source_group(src FILES ${SOURCES})");
      lines.add("");
      lines.add("# Options");
      lines.add("set(CMAKE_CXX_STANDARD 17)");
      lines.add("set(CMAKE_CXX_STANDARD_REQUIRED ON)");
      lines.add("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.add("add_definitions(-DNOMINMAX)");
      lines.add("add_definitions(-DUNICODE)");
      lines.add("");
      lines.add("# Application properties");
      lines.add("add_executable(${PROJECT_NAME} WIN32 ${SOURCES})");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
