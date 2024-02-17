#pragma once
#include "base_project.h"

namespace xtdc_command {
  class wpf_gui_project : public base_project {
  public:
    explicit wpf_gui_project(const xtd::ustring& path) : base_project(path) {}
    
    void create(const xtd::ustring& name, bool create_solution) const {
      xtd::io::directory::create_directory(create_solution ? xtd::io::path::combine(current_path(), name, "src") : xtd::io::path::combine(current_path(), "src"));
      if (create_solution) create_solution_cmakelists_txt(name);
      create_cmakelists_txt(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_window1_xaml(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_application_config(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_application_source(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
      create_application_xaml(name, create_solution ? xtd::io::path::combine(current_path(), name) : current_path());
    }
    
    void generate(const xtd::ustring& name) const {
      generate_cmakelists_txt(name, current_path());
    }
    
  private:
    void create_solution_cmakelists_txt(const xtd::ustring& name) const {
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
        xtd::ustring::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name),
        "include(CSharpUtilities)",
        "set(SOURCES",
        "  src/App.config",
        "  src/App.xaml",
        "  src/App.xaml.cs",
        "  src/Window1.xaml",
        "  src/Window1.xaml.cs",
        ")",
        "csharp_set_xaml_cs_properties(",
        "  src/App.xaml",
        "  src/App.xaml.cs",
        "  src/Window1.xaml",
        "  src/Window1.xaml.cs",
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "set_property(SOURCE src/App.xaml PROPERTY VS_XAML_TYPE \"ApplicationDefinition\")",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 ${SOURCES})",
        "set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES",
        "  Microsoft.CSharp",
        "  PresentationCore",
        "  PresentationFramework",
        "  System",
        "  System.Xaml",
        "  System.Xml",
        "  System.Xml.Linq",
        "  WindowsBase",
        ")",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
    
    void create_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "using System.Windows;",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  public partial class Window1 : Window {",
        "    public Window1() {",
        "      InitializeComponent();",
        "    }",
        "  }",
        "}",
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.xaml.cs"), lines);
    }
    
    void create_window1_xaml(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        xtd::ustring::format("<Window x:Class=\"{}.Window1\"", name),
        "        xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\"",
        "        xmlns:x=\"http://schemas.microsoft.com/winfx/2006/xaml\"",
        "        xmlns:d=\"http://schemas.microsoft.com/expression/blend/2008\"",
        "        xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\"",
        xtd::ustring::format("        xmlns:local=\"clr-namespace:{}\"", name),
        "        mc:Ignorable=\"d\"",
        "        Title=\"Window1\" Height=\"450\" Width=\"800\">",
        "    <Grid>",
        "",
        "    </Grid>",
        "</Window>",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "Window1.xaml"), lines);
    }
    
    void create_application_config(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "<?xml version=\"1.0\" encoding=\"utf-8\" ?>",
        "<configuration>",
        "    <startup> ",
        "        <supportedRuntime version=\"v4.0\" sku=\".NETFramework,Version=v4.7.2\" />",
        "    </startup>",
        "</configuration>",
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "App.config"), lines);
    }
    
    void create_application_source(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        "using System.Windows;",
        "",
        xtd::ustring::format("namespace {} {{", name),
        "  public partial class App : Application {",
        "  }",
        "}",
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "App.xaml.cs"), lines);
    }
    
    void create_application_xaml(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines {
        xtd::ustring::format("<Application x:Class=\"{}.App\"", name),
        "        xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\"",
        "        xmlns:x=\"http://schemas.microsoft.com/winfx/2006/xaml\"",
        xtd::ustring::format("    xmlns:local=\"clr-namespace:{}\"", name),
        "        StartupUri=\"src\\Window1.xaml\">",
        "    <Application.Resources>",
        "",
        "    </Application.Resources>",
        "</Application>",
      };
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "src", "App.xaml"), lines);
    }
    
    void generate_cmakelists_txt(const xtd::ustring& name, const xtd::ustring& path) const {
      std::vector<xtd::ustring> lines;
      lines.push_back("cmake_minimum_required(VERSION 3.20)");
      lines.push_back("");
      lines.push_back("# Project");
      lines.push_back(xtd::ustring::format("project({} VERSION 1.0.0 LANGUAGES CSharp)", name));
      lines.push_back("include(CSharpUtilities)");
      lines.push_back("set(SOURCES");
      lines.push_back("  src/App.config");
      lines.push_back("  src/App.xaml");
      lines.push_back("  src/App.xaml.cs");
      lines.push_back("  src/Window1.xaml");
      lines.push_back("  src/Window1.xaml.cs");
      lines.push_back(")");
      lines.push_back("csharp_set_xaml_cs_properties(");
      lines.push_back("  src/App.xaml");
      lines.push_back("  src/App.xaml.cs");
      lines.push_back("  src/Window1.xaml");
      lines.push_back("  src/Window1.xaml.cs");
      lines.push_back(")");
      lines.push_back("source_group(src FILES ${SOURCES})");
      lines.push_back("");
      lines.push_back("# Options");
      lines.push_back("set_property(GLOBAL PROPERTY USE_FOLDERS ON)");
      lines.push_back("set_property(SOURCE src/App.xaml PROPERTY VS_XAML_TYPE \"ApplicationDefinition\")");
      lines.push_back("");
      lines.push_back("# Application properties");
      lines.push_back("add_executable(${PROJECT_NAME} WIN32 ${SOURCES})");
      lines.push_back("set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES");
      lines.push_back("  Microsoft.CSharp");
      lines.push_back("  PresentationCore");
      lines.push_back("  PresentationFramework");
      lines.push_back("  System");
      lines.push_back("  System.Xaml");
      lines.push_back("  System.Xml");
      lines.push_back("  System.Xml.Linq");
      lines.push_back("  WindowsBase");
      lines.push_back(")");
      
      xtd::io::file::write_all_lines(xtd::io::path::combine(path, "CMakeLists.txt"), lines);
    }
  };
}
