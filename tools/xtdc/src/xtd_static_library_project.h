#pragma once
#include "base_project.h"

namespace xtdc_command {
  class xtd_static_library_project : public base_project {
  public:
    explicit xtd_static_library_project(const xtd::ustring& path) : base_project(path) {}
    
    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "include") : xtd::io::path::combine(current_path(), "include"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "properties") : xtd::io::path::combine(current_path(), "properties"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_application_properties(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_assembly_info(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::ustring& name) const {
      generate_cmakelists_txt(name, current_path());
    }
    
  private:
    void create_solution_cmakelists_txt(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.5)",
        "",
        "# Solution",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::ustring::format("  {}", name),
        ")",
        "",
        "# Install",
        "install_package()",
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(current_path(), "CMakeLists.txt"), lines);
    }
    
    void create_application_properties(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("target_default_namespace(\"{}\")", name),
        xtd::ustring::format("target_name(\"{}\")", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "target_properties.cmake"), lines);
    }
    
    void create_assembly_info(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines{
        xtd::ustring::format("assembly_title(\"{}\")", name),
        "assembly_description(\"\")",
        "assembly_company(\"\")",
        "assembly_product(\"\")",
        xtd::ustring::format("assembly_copyright(\"Copyright © YourCompanyName {}\")", xtd::date_time::now().year()),
        "assembly_trademark(\"\")",
        "assembly_version(\"1.0.0\")",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "assembly_info.cmake"), lines);
    }

    void create_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "cmake_minimum_required(VERSION 3.5)",
        "",
        "# Project",
        xtd::ustring::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_include_directories(include)",
        "add_sources(",
        "  include/class1.h",
        "  src/class1.cpp",
        ")",
        "target_type(STATIC_LIBRARY)",
        "",
        "# Install",
        "add_install_include_directories(include)",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_include(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "/// @file",
        "/// @brief Contains class1 class.",
        "#pragma once",
        "",
        "/// @brief Represents the namespace that contains library objects.",
        xtd::ustring::format("namespace {} {{", name),
        "  /// @brief Represents the class1 class.",
        "  class class1 {",
        "  public:",
        "    /// @brief Initializes a new instance of the class1 class.",
        "    class1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "class1.h"), lines);
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
      lines.push_back("cmake_minimum_required(VERSION 3.5)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::ustring::format("project({})", name));
      lines.push_back("find_package(xtd REQUIRED)");
      lines.push_back("add_include_directories(include)");
      lines.push_back("add_sources(");
      auto [headers, sources] = get_cpp_sources(path, path);
      for (auto file : headers)
        lines.push_back(xtd::ustring::format("  {}", file));
      for (auto file : sources)
        lines.push_back(xtd::ustring::format("  {}", file));
      lines.push_back(")");
      lines.push_back("target_type(STATIC_LIBRARY)");
      lines.push_back("");
      lines.push_back("# Install");
      lines.push_back("add_install_include_directories(include)");
      lines.push_back("install_component()");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
