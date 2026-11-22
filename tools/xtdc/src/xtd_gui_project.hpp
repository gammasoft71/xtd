#pragma once
#include "base_project.hpp"

namespace xtdc_command {
  class xtd_gui_project : public base_project {
  public:
    explicit xtd_gui_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "properties") : xtd::io::path::combine(current_path(), "properties"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "resources") : xtd::io::path::combine(current_path(), "resources"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      xtd::io::file::copy(xtd::io::path::combine(get_base_path(), "icons", "xtd_forms.icns"), xtd::io::path::combine(current_path(), (create_solution ? name : ""), "resources", xtd::string::format("{}.icns", name)));
      xtd::io::file::copy(xtd::io::path::combine(get_base_path(), "icons", "xtd_forms.ico"), xtd::io::path::combine(current_path(), (create_solution ? name : ""), "resources", xtd::string::format("{}.ico", name)));
      xtd::io::file::copy(xtd::io::path::combine(get_base_path(), "icons", "xtd_forms.png"), xtd::io::path::combine(current_path(), (create_solution ? name : ""), "resources", xtd::string::format("{}.png", name)));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_application_properties(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_assembly_info(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::string& name) const {
      generate_cmakelists_txt(name, current_path());
    }
    
  private:
    static xtd::string get_base_path() noexcept {return xtd::environment::get_folder_path(xtd::environment::special_folder::xtd_resources);}
    
    void create_solution_cmakelists_txt(const xtd::string& name) const {
      auto lines = xtd::array<xtd::string> {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::string::format("project({} VERSION 1.0.0)", name),
        "find_package(xtd REQUIRED)",
        "",
        "# Install",
        "install_package()",
        "",
        "# Projects",
        xtd::string::format("add_projects({})", name),
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_application_properties(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        xtd::string::format("target_default_namespace(\"{}\")", name),
        xtd::string::format("target_icon(resources/{})", name),
        xtd::string::format("target_name(\"{}\")", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "target_properties.cmake"), lines);
    }
    
    void create_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::string::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/form1.cpp",
        ")",
        "target_type(GUI_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_assembly_info(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "# Information about this assembly is defined by the following attributes.",
        "# Change them to the values specific to your project.",
        "",
        xtd::string::format("assembly_title(\"{}\")", name),
        "assembly_description(\"\")",
        "assembly_company(\"\")",
        xtd::string::format("assembly_product(\"{}\")", name),
        xtd::string::format("assembly_copyright(\"Copyright © YourCompanyName {}\")", xtd::date_time::now().year()),
        "assembly_trademark(\"\")",
        "",
        "# The following GUID is for the ID of the typelib if this project is exposed to COM",
        "",
        xtd::string::format("assembly_guid(\"{}\")", xtd::guid::new_guid()),
        "",
        "# The assembly version has the format \"{Major}.{Minor}.{Build}.{Revision}\".",
        "# In not specify or empty or \"*\" the cmake project version is used.",
        "",
        "assembly_version(\"*\")",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "assembly_info.cmake"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::array<xtd::string> {
        "#include <xtd/forms/application>",
        "#include <xtd/forms/form>",
        "#include <xtd/startup>",
        "",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represents the main form.",
        "  class form1 : public form {",
        "  public:",
        "    form1() {",
        "      client_size({800, 450});",
        "      text(\"form1\");",
        "    }",
        "",
        "    /// @brief The main entry point for the application.",
        "    static auto main() {",
        "      application::run(form1 {});",
        "    }",
        "  };",
        "}",
        "",
        "auto main() -> int {",
        xtd::string::format("  return startup::run({}::form1::main);", name),
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "form1.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      auto lines = xtd::collections::generic::list<xtd::string> {};
      lines.add("cmake_minimum_required(VERSION 3.20)");
      lines.add("");
      lines.add("# Project");
      lines.add(xtd::string::format("project({})", name));
      lines.add("find_package(xtd REQUIRED)");
      lines.add("add_sources(");
      auto [headers, sources] = get_cpp_sources(path, path);
      for (const auto& file : headers)
        lines.add(xtd::string::format("  {}", file));
      for (const auto& file : sources)
        lines.add(xtd::string::format("  {}", file));
      lines.add(")");
      lines.add("target_type(GUI_APPLICATION)");
      lines.add("");
      lines.add("# Install");
      lines.add("install_component()");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
