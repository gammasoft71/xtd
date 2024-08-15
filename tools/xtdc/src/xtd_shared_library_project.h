#pragma once
#include "base_project.h"

namespace xtdc_command {
  class xtd_shared_library_project : public base_project {
  public:
    explicit xtd_shared_library_project(const xtd::string& path) : base_project(path) {}
    
    void create(const xtd::string& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "include") : xtd::io::path::combine(current_path(), "include"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "properties") : xtd::io::path::combine(current_path(), "properties"));
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_application_properties(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_assembly_info(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_include(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_export(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
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
        xtd::string::format("target_name(\"{}\")", name),
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "properties", "target_properties.cmake"), lines);
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

    void create_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "cmake_minimum_required(VERSION 3.20)",
        "",
        "# Project",
        xtd::string::format("project({})", name),
        "find_package(xtd REQUIRED)",
        "add_include_directories(include)",
        "add_sources(",
        "  include/class1.h",
        "  include/export.h",
        "  src/class1.cpp",
        ")",
        "target_type(SHARED_LIBRARY)",
        "",
        "# Install",
        "add_install_include_directories(include)",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_include(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "/// @file",
        "/// @brief Contains class1 class.",
        "#pragma once",
        "#include \"export.h\"",
        "",
        "/// @brief Represents the namespace that contains library objects.",
        xtd::string::format("namespace {} {{", name),
        "  /// @brief Represents the class1 class.",
        xtd::string::format("  class {}_export_ class1 {{", name.to_lower()),
        "  public:",
        "    /// @brief Initializes a new instance of the class1 class.",
        "    class1();",
        "  };",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "class1.h"), lines);
    }
    
    void create_export(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "/// @file",
        "/// @brief Contains export.",
        "#pragma once",
        "",
        "/// @cond",
        "#if defined(_WIN32)",
        xtd::string::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::string::format("#    define {}_export_ __declspec(dllexport)", name.to_lower()),
        "#  else",
        xtd::string::format("#    define {}_export_ __declspec(dllimport)", name.to_lower()),
        "#  endif",
        "#else",
        xtd::string::format("#  if defined({}_EXPORT)", name.to_upper()),
        xtd::string::format("#    define {}_export_ __attribute__((visibility (\"default\")))", name.to_lower()),
        "#  else",
        xtd::string::format("#    define {}_export_", name.to_lower()),
        "#  endif",
        "#endif",
        "/// @endcond",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "include", "export.h"), lines);
    }
    
    void create_source(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines {
        "#include \"../include/class1.h\"",
        "",
        xtd::string::format("using namespace {};", name),
        "",
        "class1::class1() {",
        "}",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "class1.cpp"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::string& name, const xtd::string& path) const {
      std::vector<xtd::string> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::string::format("project({})", name));
      lines.push_back("find_package(xtd REQUIRED)");
      lines.push_back("add_include_directories(include)");
      lines.push_back("add_sources(");
      auto [headers, sources] = get_cpp_sources(path, path);
      for (auto file : headers)
        lines.push_back(xtd::string::format("  {}", file));
      for (auto file : sources)
        lines.push_back(xtd::string::format("  {}", file));
      lines.push_back(")");
      lines.push_back("target_type(SHARED_LIBRARY)");
      lines.push_back("");
      lines.push_back("# Install");
      lines.push_back("add_install_include_directories(include)");
      lines.push_back("install_component()");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
