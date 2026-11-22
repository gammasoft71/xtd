#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class gtk_gui_project : public base_project {
  public:
    explicit gtk_gui_project(const xtd::string& path) : base_project(path) {}
    
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
        "",
        "# Projects",
        xtd::string::format("add_subdirectory({})", name),
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
        "  src/program.cpp",
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(PkgConfig)",
        "pkg_check_modules(GTK gtk4)",
        "include_directories(${GTK_INCLUDE_DIRS})",
        "link_directories(${GTK_LIBRARY_DIRS})",
        "link_libraries(${GTK_LIBRARIES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 20)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "#include <gtk/gtk.h>",
        "",
        "auto on_app_activate(GtkApplication* app, gpointer user_data) -> void {",
        "  auto* window1 = gtk_application_window_new(app);",
        "  gtk_window_set_title(GTK_WINDOW(window1), \"Window1\");",
        "  gtk_window_set_default_size(GTK_WINDOW(window1), 800, 450);",
        "  gtk_window_present(GTK_WINDOW(window1));",
        "}",
        "",
        "// The main entry point for the application.",
        "auto main(int argc, char* argv[]) -> int {",
        xtd::string::format("  auto* app = gtk_application_new(\"org.gtk.{}\", G_APPLICATION_DEFAULT_FLAGS);", name),
        "  g_signal_connect(app, \"activate\", G_CALLBACK(on_app_activate), nullptr);",
        "  auto status = g_application_run(G_APPLICATION(app), argc, argv);",
        "  g_object_unref(app);",
        "  return status;",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "program.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.add("cmake_minimum_required(VERSION 3.20)");
      lines.add("");
      lines.add("# Project");
      lines.add(xtd::string::format("project({} VERSION 1.0.0)", name));
      lines.add("set(SOURCES");
      auto [headers, sources] = get_c_sources(path, path);
      for (const auto& file : headers)
        lines.add(xtd::string::format("  {}", file));
      for (const auto& file : sources)
        lines.add(xtd::string::format("  {}", file));
      lines.add(")");
      lines.add("source_group(src FILES ${SOURCES})");
      lines.add("find_package(PkgConfig)");
      lines.add("pkg_check_modules(GTK gtk4)");
      lines.add("include_directories(${GTK_INCLUDE_DIRS})");
      lines.add("link_directories(${GTK_LIBRARY_DIRS})");
      lines.add("link_libraries(${GTK_LIBRARIES})");
      lines.add("");
      lines.add("# Options");
      lines.add("set(CMAKE_CXX_STANDARD 20)");
      lines.add("set(CMAKE_CXX_STANDARD_REQUIRED ON)");
      lines.add("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.add("");
      lines.add("# Application properties");
      lines.add("add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
