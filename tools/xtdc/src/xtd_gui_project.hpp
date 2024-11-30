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
      create_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::string& name) const {
      generate_cmakelists_txt(name, current_path());
    }
    
  private:
    static xtd::string get_base_path() noexcept {return xtd::environment::get_folder_path(xtd::environment::special_folder::xtd_resources);}
    
    void create_solution_cmakelists_txt(const xtd::string& name) const {
      std::vector<xtd::string> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Solution",
        xtd::string::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::string::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_application_properties(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines{
        xtd::string::format("target_default_namespace(\"{}\")", name),
        xtd::string::format("target_icon(resources/{})", name),
        xtd::string::format("target_name(\"{}\")", name),
        xtd::string::format("target_startup(\"{}::form1::main\" src/form1.h)", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "target_properties.cmake"), lines);
    }
    
    void create_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::string::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        "  src/form1.hpp",
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
      std::vector<xtd::string> lines{
        xtd::string::format("assembly_title(\"{}\")", name),
        "assembly_description(\"\")",
        "assembly_company(\"\")",
        "assembly_product(\"\")",
        xtd::string::format("assembly_copyright(\"Copyright © YourCompanyName {}\")", xtd::date_time::now().year()),
        "assembly_trademark(\"\")",
        "assembly_version(\"1.0.0\")",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "assembly_info.cmake"), lines);
    }

    void create_include(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "/// @file",
        xtd::string::format("/// @brief Contains {}::form1 class.", name),
        xtd::string::format("/// @copyright Copyright (c) {} YourCompanyName. All rights reserved.", xtd::date_time::now().year()),
        "#pragma once",
        "#include <xtd/forms/form>",
        "",
        "/// @brief Represents the namespace that contains application objects.",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represents the main form.",
        xtd::string::format("  /// @remarks Contains the {}::form1::main entry point method;", name),
        "  class form1 : public xtd::forms::form {",
        "  public:",
        xtd::string::format("    /// @brief Initializes a new instance of the {}::form1 class.", name),
        "    form1();",
        "",
        "    /// @brief The main entry point for the application.",
        "    static auto main() -> void;",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "form1.hpp"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#include \"form1.hpp\"",
        "#include <xtd/forms/application>",
        "",
        xtd::string::format("using namespace {};", name),
        "using namespace xtd::forms;",
        "",
        "form1::form1() {",
        "  text(\"form1\");",
        "  client_size({800, 450});",
        "}",
        "",
        "auto form1::main() -> void {",
        "  application::run(form1 {});",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "form1.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::string::format("project({})", name));
      lines.push_back("find_package(xtd REQUIRED)");
      lines.push_back("add_sources(");
      auto [headers, sources] = get_cpp_sources(path, path);
      for (auto file : headers)
        lines.push_back(xtd::string::format("  {}", file));
      for (auto file : sources)
        lines.push_back(xtd::string::format("  {}", file));
      lines.push_back(")");
      lines.push_back("target_type(GUI_APPLICATION)");
      lines.push_back("");
      lines.push_back("# Install");
      lines.push_back("install_component()");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
