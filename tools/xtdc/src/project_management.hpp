#pragma once
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <map>
#include <string>
#include <vector>
#include <xtd/environment.hpp>
#include <xtd/action.hpp>
#include <xtd/file.hpp>
#include <xtd/path.hpp>
#include <xtd/strings.hpp>

#include "project_language.hpp"
#include "project_sdk.hpp"
#include "project_type.hpp"

namespace xtdc_command {
  class project_management {
    struct change_current_directory {
      change_current_directory(const std::string& current_directory) {xtd::environment::current_directory(current_directory);}
      ~change_current_directory() {xtd::environment::current_directory(previous_current_directoy_);}
    private:
      std::string previous_current_directoy_ = xtd::environment::current_directory();
    };
    
  public:
    project_management() {}
    //explicit project_management(const std::string& name) : name_(name) {}
    //project_management(const std::string& name, project_type type) : name_(name), type_(type) {}
    project_management(const std::string& name, const std::filesystem::path& output) : name_(name), output_(output) {}
    project_management(const std::string& name, project_type type, project_sdk sdk, project_language language, const std::filesystem::path& output) : name_(name), type_(type), sdk_(sdk), language_(language), output_(output) {
      auto sdks = get_valid_sdks(type);
      if (std::find(sdks.begin(), sdks.end(), sdk) == sdks.end()) throw std::invalid_argument("sdk not valid with type");
      auto languages = get_valid_languages(sdk);
      if (std::find(languages.begin(), languages.end(), language) == languages.end()) throw std::invalid_argument("language not valid with sdk");
    }

    static std::vector<project_sdk> get_valid_sdks(project_type type) {
      switch (type) {
        case project_type::blank_solution: return {project_sdk::xtd};
        case project_type::console: return {project_sdk::none, project_sdk::xtd};
        case project_type::gui: return {project_sdk::xtd, project_sdk::win32, project_sdk::gtk, project_sdk::cocoa, project_sdk::gtkmm, project_sdk::wxwidgets, project_sdk::qt5};
        case project_type::shared_library: return {project_sdk::none, project_sdk::xtd};
        case project_type::static_library: return {project_sdk::none, project_sdk::xtd};
        case project_type::unit_test_application: return {project_sdk::xtd, project_sdk::gtest, project_sdk::catch2};
      }
      throw std::invalid_argument("type is not project_type valid value");
    }
    
    static std::vector<project_language> get_valid_languages(project_sdk sdk) {
      switch (sdk) {
        case project_sdk::none: return {project_language::cpp, project_language::c, project_language::objectivec};
        case project_sdk::xtd: return {project_language::cpp};
        case project_sdk::win32: return {project_language::c, project_language::cpp};
        case project_sdk::gtk: return {project_language::c, project_language::cpp};
        case project_sdk::cocoa: return {project_language::objectivec};
        case project_sdk::gtkmm: return {project_language::cpp};
        case project_sdk::wxwidgets: return {project_language::cpp};
        case project_sdk::qt5: return {project_language::cpp};
        case project_sdk::gtest: return {project_language::c, project_language::cpp};
        case project_sdk::catch2: return {project_language::c, project_language::cpp};
      }
      throw std::invalid_argument("sdk is not project_sdk valid value");
    }
    
    std::string create() {
      if (is_path_already_exist_and_not_empty(output_)) return xtd::strings::format("Path \"{0}\" already exists and not empty! CreateNewProject aborted.", output_);
      std::filesystem::create_directories(std::filesystem::path {output_}/"build");
      std::map<project_type, xtd::action<>> {{project_type::blank_solution, {*this, &project_management::create_blank_solution}}, {project_type::console, {*this, &project_management::create_console}}, {project_type::gui, {*this, &project_management::create_gui}}, {project_type::shared_library, {*this, &project_management::create_shared_library}}, {project_type::static_library, {*this, &project_management::create_static_library}}, {project_type::unit_test_application, {*this, &project_management::create_unit_test_application}}}[type_]();
      generate();
      return xtd::strings::format("Project {}{} created", name_, xtd::environment::os_version().is_windows_platform() ? ".sln" : xtd::environment::os_version().is_osx_platform() ? ".xcodeproj" : " makefile");
    }

    std::string build(bool release) {
      generate();
      if (xtd::environment::os_version().is_windows_platform() || xtd::environment::os_version().is_osx_platform())
        system(xtd::strings::format("cmake --build {} --config {}", build_path(), release ? "Release" : "Debug").c_str());
      else
        system(xtd::strings::format("cmake --build {}", build_path()/(release ? "Release" : "Debug")).c_str());
      builded_ = true;
      return xtd::strings::format("Project {0} builded", name_);
    }

    std::string clean(bool release) {
      if (xtd::environment::os_version().is_windows_platform() || xtd::environment::os_version().is_osx_platform())
        std::filesystem::remove_all( build_path());
      else
        std::filesystem::remove_all( build_path()/(release ? "Release" : "Debug"));
      generate();
      return xtd::strings::format("Project {0} cleaned", name_);
    }

    std::string open(bool release) {
      generate();
      if (xtd::environment::os_version().is_windows_platform())
        system(xtd::strings::format("explorer {}.sln", build_path()/name_).c_str());
      if (xtd::environment::os_version().is_osx_platform())
        system(xtd::strings::format("open {}.xcodeproj", build_path()/name_).c_str());
      else
        system(xtd::strings::format("xdg-open {}.cbp", build_path()/(release ? "Release" : "Debug")/name_).c_str());
      opened_ = true;
      return xtd::strings::format("Project {0} opened", name_);
    }

    std::string to_string() const {return xtd::strings::format("{{name=\"{}\", type={}, sdk={}, language={}, output=\"{}\"}}", name_, to_string(type_), to_string(sdk_), to_string(language_), output_);}

  private:
    std::filesystem::path build_path() const {return output_ / "build";}
    void create_blank_solution() {
      //std::cout << "(create_blank_solution) Generate " << to_string() << std::endl << std::endl;
      create_doxygen_txt();
      create_blank_solution_cmakelists_txt();
    }
    
    void create_console() {
      std::cout << "(create_console) Generate " << to_string() << std::endl << std::endl;
      create_doxygen_txt();
    }
    
    void create_gui() {
      std::cout << "(create_gui) Generate " << to_string() << std::endl << std::endl;
      create_doxygen_txt();
    }
    
    void create_shared_library() {
      std::cout << "(create_shared_library) Generate " << to_string() << std::endl << std::endl;
      create_doxygen_txt();
    }
    
    void create_static_library() {
      std::cout << "(create_static_library) Generate " << to_string() << std::endl << std::endl;
      create_doxygen_txt();
    }
    
    void create_unit_test_application() {
      std::cout << "(create_unit_test_application) Generate " << to_string() << std::endl << std::endl;
      create_doxygen_txt();
    }
    
    void create_doxygen_txt() {
      std::vector<std::string> lines {
        "#---------------------------------------------------------------------------\n",
        "# Project related configuration options\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        xtd::strings::format("PROJECT_NAME           = \"{} - Reference Guide\"\n", name_),
        "PROJECT_NUMBER         = 0.1.0\n",
        "PROJECT_BRIEF          = \n",
        "PROJECT_LOGO           = \n",
        "OUTPUT_DIRECTORY       = \n",
        "ALWAYS_DETAILED_SEC    = YES\n",
        "INLINE_INHERITED_MEMB  = NO\n",
        "FULL_PATH_NAMES        = NO\n",
        "STRIP_FROM_PATH        = \n",
        "STRIP_FROM_INC_PATH    = \n",
        "TAB_SIZE               = 2\n",
        "TOC_INCLUDE_HEADINGS   = 0\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Build related configuration options\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "SORT_BRIEF_DOCS        = YES\n",
        "SORT_MEMBERS_CTORS_1ST = YES\n",
        "SORT_GROUP_NAMES       = YES\n",
        "SORT_BY_SCOPE_NAME     = YES\n",
        "#MAX_INITIALIZER_LINES  = 0\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to warning and progress messages\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "WARN_LOGFILE           = doxygen_warnings.txt\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the input files\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "INPUT                  = src\n",
        "RECURSIVE              = YES\n",
        "EXCLUDE_PATTERNS       = \n",
        "EXAMPLE_PATH           = \n",
        "EXAMPLE_PATTERNS       = *\n",
        "EXAMPLE_RECURSIVE      = YES\n",
        "IMAGE_PATH             = \n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to source browsing\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the alphabetical class index\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "COLS_IN_ALPHA_INDEX    = 1\n",
        "IGNORE_PREFIX          = \n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the HTML output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "HTML_OUTPUT            = ReferenceGuide\n",
        "HTML_HEADER            = \n",
        "HTML_FOOTER            = \n",
        "HTML_STYLESHEET        = \n",
        "HTML_EXTRA_STYLESHEET  = \n",
        "HTML_EXTRA_FILES       = \n",
        "HTML_COLORSTYLE_HUE    = 220\n",
        "HTML_COLORSTYLE_SAT    = 100\n",
        "HTML_COLORSTYLE_GAMMA  = 80\n",
        "HTML_TIMESTAMP         = YES\n",
        "HTML_DYNAMIC_SECTIONS  = NO\n",
        "HTML_INDEX_NUM_ENTRIES = 100\n",
        "GENERATE_DOCSET        = NO\n",
        "GENERATE_HTMLHELP      = NO\n",
        "GENERATE_QHP           = NO\n",
        "QCH_FILE               = \n",
        "GENERATE_ECLIPSEHELP   = NO\n",
        "DISABLE_INDEX          = NO\n",
        "GENERATE_TREEVIEW      = YES\n",
        "ENUM_VALUES_PER_LINE   = 1\n",
        "TREEVIEW_WIDTH         = 250\n",
        "EXT_LINKS_IN_WINDOW    = NO\n",
        "FORMULA_FONTSIZE       = 10\n",
        "FORMULA_TRANSPARENT    = YES\n",
        "USE_MATHJAX            = NO\n",
        "SEARCHENGINE           = YES\n",
        "SERVER_BASED_SEARCH    = NO\n",
        "EXTERNAL_SEARCH        = NO\n",
        "SEARCHENGINE_URL       = \n",
        "SEARCHDATA_FILE        = searchdata.xml\n",
        "EXTERNAL_SEARCH_ID     = \n",
        "EXTRA_SEARCH_MAPPINGS  = \n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the LaTeX output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "GENERATE_LATEX         = NO\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the RTF output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the man page output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the XML output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the DOCBOOK output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options for the AutoGen Definitions output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the Perl module output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the preprocessor\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "MACRO_EXPANSION        = YES\n",
        "EXPAND_ONLY_PREDEF     = YES\n",
        "SEARCH_INCLUDES        = YES\n",
        "INCLUDE_PATH           = \n",
        "INCLUDE_FILE_PATTERNS  = \n",
        "PREDEFINED             = \"static_=final : public xtd::static\"\n",
        "EXPAND_AS_DEFINED      = \n",
        "SKIP_FUNCTION_MACROS   = YES\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to external references\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the dot tool\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "CLASS_DIAGRAMS         = YES\n",
        "MSCGEN_PATH            = \n",
        "DIA_PATH               = \n",
        "HIDE_UNDOC_RELATIONS   = YES\n",
        "HAVE_DOT               = NO\n",
        "DOT_NUM_THREADS        = 0\n",
        "DOT_FONTNAME           = Helvetica\n",
        "DOT_FONTSIZE           = 10\n",
        "DOT_FONTPATH           = \n",
        "CLASS_GRAPH            = YES\n",
        "COLLABORATION_GRAPH    = YES\n",
        "GROUP_GRAPHS           = YES\n",
        "UML_LOOK               = NO\n",
        "UML_LIMIT_NUM_FIELDS   = 10\n",
        "TEMPLATE_RELATIONS     = NO\n",
        "INCLUDE_GRAPH          = YES\n",
        "INCLUDED_BY_GRAPH      = YES\n",
        "CALL_GRAPH             = NO\n",
        "CALLER_GRAPH           = NO\n",
        "GRAPHICAL_HIERARCHY    = YES\n",
        "DIRECTORY_GRAPH        = YES\n",
        "DOT_IMAGE_FORMAT       = png\n",
        "INTERACTIVE_SVG        = NO\n",
        "DOT_PATH               = \n",
        "DOTFILE_DIRS           = \n",
        "MSCFILE_DIRS           = \n",
        "DIAFILE_DIRS           = \n",
        "PLANTUML_JAR_PATH      = \n",
        "PLANTUML_CFG_FILE      = \n",
        "PLANTUML_INCLUDE_PATH  = \n",
        "DOT_GRAPH_MAX_NODES    = 50\n",
        "MAX_DOT_GRAPH_DEPTH    = 0\n",
        "DOT_TRANSPARENT        = NO\n",
        "DOT_MULTI_TARGETS      = NO\n",
        "GENERATE_LEGEND        = YES\n",
        "DOT_CLEANUP            = YES\n",
      };
      xtd::io::file::write_all_lines(output_/".doxygen.txt", lines);
   }
    
    void create_blank_solution_cmakelists_txt() {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name_),
        "find_package(xtd REQUIRED)",
        "",
        "# Install",
        "install_package()"
      };
      xtd::io::file::write_all_lines(output_/"CMakeLists.txt", lines);
    }
        
    void generate() {
      std::filesystem::create_directories(build_path());
      if (xtd::environment::os_version().is_windows_platform() && !std::filesystem::exists(build_path()/xtd::strings::format("{}.sln", name_)))
        system(xtd::strings::format("cmake -S {} -B {}", output_, build_path()).c_str());
      else if (xtd::environment::os_version().is_osx_platform() && !std::filesystem::exists(build_path()/xtd::strings::format("{}.xcodeproj", name_)))
        system(xtd::strings::format("cmake -S {} -B {} -G \"Xcode\"", output_, build_path()).c_str());
      else if (xtd::environment::os_version().is_linux_platform() && (!std::filesystem::exists(build_path()/"Debug"/xtd::strings::format("{}.cbp", name_)) || !std::filesystem::exists(build_path()/"Release"/xtd::strings::format("{}.cbp", name_)))) {
        std::filesystem::create_directories(build_path()/"Debug");
        std::filesystem::create_directories(build_path()/"Release");
        system(xtd::strings::format("cmake -S {} -B {} -G \"CodeBlocks - Unix Makefiles\"", output_, build_path()/"Debug").c_str());
        system(xtd::strings::format("cmake -S {} -B {} -G \"CodeBlocks - Unix Makefiles\"", output_, build_path()/"Release").c_str());
      }
      generated_ = true;
    }

    bool is_path_already_exist_and_not_empty(const std::string& path) {
      if (!std::filesystem::exists({output_})) return false;
      if (std::filesystem::is_empty({output_})) return false;
      if (xtd::environment::os_version().is_osx_platform() && std::count_if(std::filesystem::directory_iterator({output_}), std::filesystem::directory_iterator(), [](auto item) {return item.path().filename().string() != ".DS_Store";}) == 0) return false;
      return true;
    }
    
    static std::string to_string(project_type type) {return std::map<xtdc_command::project_type, std::string> {{xtdc_command::project_type::blank_solution, "blank_solution"}, {xtdc_command::project_type::gui, "gui"}, {xtdc_command::project_type::console, "console"}, {xtdc_command::project_type::shared_library, "shared_library"}, {xtdc_command::project_type::static_library, "static_library"}, {xtdc_command::project_type::unit_test_application, "unit_test_application"}}[type];}
    static std::string to_string(project_sdk sdk) {return std::map<xtdc_command::project_sdk, std::string> {{xtdc_command::project_sdk::none, "none"}, {xtdc_command::project_sdk::xtd, "xtd"}, {xtdc_command::project_sdk::win32, "win32"}, {xtdc_command::project_sdk::gtk, "gtk"}, {xtdc_command::project_sdk::cocoa, "cocoa"}, {xtdc_command::project_sdk::gtkmm, "gtkmm"}, {xtdc_command::project_sdk::wxwidgets, "wxwidgets"}, {xtdc_command::project_sdk::qt5, "qt5"}, {xtdc_command::project_sdk::gtest, "gtest"}, {xtdc_command::project_sdk::catch2, "catch2"}}[sdk];}
    static std::string to_string(project_language language) {return std::map<xtdc_command::project_language, std::string> {{xtdc_command::project_language::cpp, "cpp"}, {xtdc_command::project_language::c, "c"}, {xtdc_command::project_language::objectivec, "objectivec"}}[language];}
    std::string name_ {std::filesystem::path(xtd::environment::current_directory()).stem().string()};
    project_type type_ {project_type::gui};
    project_sdk sdk_ {project_sdk::xtd};
    project_language language_ {project_language::cpp};
    std::filesystem::path output_ {xtd::environment::current_directory()};
    bool generated_ = false;
    bool builded_ = false;
    bool opened_ = false;
  };
}
