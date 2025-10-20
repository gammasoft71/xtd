#include "new_project.hpp"
//#include "project_management.hpp"
#include <xtd/collections/generic/dictionary>
#include <xtd/collections/generic/list>
#include <xtd/diagnostics/stopwatch>
#include <xtd/char_object>
#include <xtd/delegate>
#include <xtd/random>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

namespace xtdc_command {
  class xtdc final : public project_base {
  public:
    static auto main() {
      console::output_code_page(65001);
      
      if (environment::get_command_line_args().size() == 0) {
        write_line_error("No parameters.");
        console::write_line(string::join("\n", get_help()));
        return EXIT_FAILURE;
      }
      
      auto show_floppy = false;
      auto show_help = false;
      auto show_info = false;
      auto show_version = false;
      auto invalid_option = string::empty_string;
      list<string> command_args;
      if (process_xtdc_arguments(show_floppy, show_help, show_info, show_version, command_args, invalid_option) == false) {
        if (!xtd::string::is_empty(invalid_option)) write_line_error(string::format("Unknown option: {0}", invalid_option));
        else write_line_error("Invalid parameters.");
        console::write_line(string::join("\n", get_help()));
        return EXIT_FAILURE;
      }
      
      return run_commands(command_args, show_floppy, show_help, show_info, show_version, invalid_option);
    }
    
  private:
    static list<string> get_floppy() noexcept {
      static auto floppy_quotes = array {
        "Floppy aims to make c++ fun again.",
        "C++ is difficult! Not with Floppy let's see.",
        "Do you want a little help?",
        "I like it when everything runs like clockwork.",
        "I don't think it's time to go to sleep.",
        "Well, are you starting this project?",
        "Haa I see that you already don't know how to do without me anymore...",
        "Floppy aims to make c++ fun again.",
        "I was around long before std::format, and I'll be around again when it's deprecated.",
        "Floppy: keeping it retro since the dawn of computing.",
        "If it ain’t broken, it’s probably because Floppy’s been here.",
        "Saving data one spin at a time.",
        "Floppy doesn’t just store bits, it stores memories.",
        "Old school cool with a modern soul.",
        "When in doubt, trust Floppy to hold your legacy.",
        "Less flashy, more classy — that’s Floppy.",
        "Floppy spins the tales of code long forgotten.",
        "Not just a disk, a legacy in every byte.",
        "Floppy: because some classics never go out of style.",
        "Where others see slow, Floppy sees steady.",
        "Old tech, new tricks — that’s Floppy’s motto.",
        "Floppy doesn’t crash, it just takes a coffee break.",
        "Your data’s first home, still standing strong.",
        "Floppy knows your secrets — and keeps them safe.",
        "Keeping C++ vintage, one bit at a time.",
        "Floppy: proof that patience is a virtue in coding.",
        "If it’s worth saving, Floppy’s got it covered.",
        "Spinning disks, spinning stories, spinning code.",
        "Floppy: the original backup plan.",
        "Slow to start, fast to impress — Floppy style.",
        "In a world of SSDs, be a Floppy — unique and reliable.",
        "Floppy: spinning memories since the dawn of code.",
        "No flashy gimmicks, just pure floppy charm.",
        "Floppy: the original multitasker, one track at a time.",
        "More than storage — it’s a journey through time.",
        "Floppy’s not outdated, it’s vintage perfection.",
        "If code is art, Floppy is the canvas.",
        "Floppy: because every byte deserves a second chance.",
        "Trust Floppy to keep your bugs safe and sound.",
        "Floppy’s rhythm never quits — just like your code.",
        "C++ without Floppy? That’s just not the same.",
        "Floppy: where every spin tells a story.",
        "Reliable, retro, and ready to roll.",
        "Old-school tech with a heart of gold.",
        "Floppy: the original proof that good things last.",
        "Even in a digital age, Floppy’s got soul.",
      };
      
      return {
        u8"████████████████████████████████████████████████████████████",
        u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████",
        u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████",
        u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░██████████",
        u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████",
        u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████",
        u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████",
        u8"███████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░█████████████",
        u8"██████████████████████████████████████████████████████████████████████",
        u8"██████████████████████████████████████████████████████████████████████",
        u8"██████████████████████████▀▄▄▄▄▀███████▀▄▄▄▄▀█████████████████████████",
        u8"███████████████████████████▀▀▀▀███████▀▀▀▀▀███████████████████████████",
        u8"██████████████████████████      ▀████       ▀█████████████████████████",
        u8"███████████             ▐         ▀▀         ▐              ██████████",
        u8"█████████               ▐   ███   ▌▐   ███   ▐               █████████",
        u8"█████████               ▐   █▄▄▌  ▌▐  ▐▄▄█   ▐               █████████",
        u8"█████████                ▐▄  ▀▀ ▄▀  ▀▄ ▀▀  ▄▀                █████████",
        u8"█████████                  ▀▀▄▄▀      ▀▀▄▄▀                  █████████",
        u8"█████████                                                    █████████",
        u8"█████████                 █▄                ▌                █████████",
        u8"█████████                  ▌▀▀▄          ▄██                 █████████",
        u8"█████████                  ▐   ▀▀▄▄▄▄▄▄█▀ █▌                 █████████",
        u8"█████████                   ▐            ▄█                  █████████",
        u8"█████████                    █          ▄█                   █████████",
        u8"█████████                     ▀▄       █▀                    █████████",
        u8"█████████                       ▀▄▄▄▄██▀                     █████████",
        u8"█████████                                                    █████████",
        u8"█████████                                                    █████████",
        u8"█████████                                                    █████████",
        u8"█████████                                                    █████████",
        u8"█████████                                                    █████████",
        u8"██████████████████████████████████████████████████████████████████",
        u8"",
        string::format(u8"[💾 Floppy] - {}", floppy_quotes[xtd::random {}.next(floppy_quotes.length())]),
      };
    }
    
    static list<string> get_help() noexcept {
      return {
        "",
        "Usage: xtdc [<options> | command [<command-argument>] [<command-options>]]",
        "",
        "options:",
        "  -i, --info       Display information.",
        "  -v, --version    Display version in use.",
        "  -h, --help       Display help.",
        
        "",
        "command:",
        "  new              Initializes project.",
        "  generate         Generate project from existing source files.",
        "  add              Adds new project to project.",
        "  update           Regenerates a project.",
        "  run              Compiles and immediately executes a project.",
        "  build            Builds a project.",
        "  install          Install a project.",
        "  clean            Clean build output(s).",
        "  open             Open a project in default ide.",
        "  targets          List project targets.",
        "  test             Runs unit tests using the test runner specified in the project.",
        "  uninstall        Uninstall a project.",
        "  documentation    Open xtd documentation.",
        "  examples         Open xtd examples.",
        "  guide            Open xtd reference guide.",
        "  web              Open xtd website.",
        "  help             Show help.",
        "",
        "Run 'xtdc command --help' for more information on a command.",
        "",
      };
    }
    
    static list<string> get_add_help() noexcept {
      return {
        "Add new project to project.",
        "Usage: add [template-short-name] [path] [<options>]",
        "",
        "template-short-name:",
        "  A template short name of the following table. If no short name specified, gui is used.",
        "  Templates               Short Name     SDK/Language                         ",
        "  ----------------------------------------------------------------------------",
        "  Console Application     console        [xtd], xtd_c, c++, c, c#, objective-c",
        "  GUI Application         gui            [xtd], xtd_c, cocoa, fltk, gtk+2,",
        "                                         gtk+3, gtk+4, gtkmm, wxwidgets, qt5,",
        "                                         qt6, win32, winforms, wpf",
        "  Shared library          sharedlib      [xtd], xtd_c, c++, c, c#, objective-c",
        "  Static library          staticlib      [xtd], xtd_c, c++, c, c#, objective-c",
        "  Unit Test Project       test           [xtd], xtd_c, gtest, catch2",
        "  Solution File           sln            [xtd], xtd_c",
        "",
        "path:",
        "  Location to place the generated output. If no path is specified, the current path is used.",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -n, --name          The name for the project. If no name is specified, the name of the specified path or of the current directory is used.",
        "  --type              Filters templates based on available types. Predefined values are \"project\", \"item\" or \"other\".",
        "  -s , --sdk          Filters templates based on SDK/language and specifies the SDK/language of the template to create.",
        "",
        "",
        "Exemples:",
        "    xtdc add console",
        "    xtdc add gui my_app",
        "    xtdc add --help",
      };
    }
    
    static list<string> get_build_help() noexcept {
      return {
        "Builds a project.",
        "Usage: build [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         build debug config.",
        "  -r, --release       build release config.",
        "  -t, --target        build a specified target project.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc build",
        "    xtdc build my_apps",
        "    xtdc build my_apps -t my_app1",
        "    xtdc build --help"
      };
    }
    
    static list<string> get_clean_help() noexcept {
      return {
        "Clean build output(s).",
        "Usage: clean [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         clean debug config.",
        "  -r, --release       clean release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc clean",
        "    xtdc clean my_app",
        "    xtdc clean --help",
      };
    }
    
    static list<string> get_generate_help() noexcept {
      return {
        "Generate project.",
        "Usage: generate [template-short-name] [path] [<options>]",
        "",
        "template-short-name:",
        "  A template short name of the following table. If no short name specified, gui is used.",
        "  Templates               Short Name     SDK/Language                         ",
        "  ----------------------------------------------------------------------------",
        "  Console Application     console        [xtd], xtd_c, c++, c, c#, objective-c",
        "  GUI Application         gui            [xtd], xtd_c, cocoa, fltk, gtk+2,",
        "                                         gtk+3, gtk+4, gtkmm, wxwidgets, qt5,",
        "                                         qt6, win32, winforms, wpf",
        "  Shared library          sharedlib      [xtd], xtd_c, c++, c, c#, objective-c",
        "  Static library          staticlib      [xtd], xtd_c, c++, c, c#, objective-c",
        "  Unit Test Project       test           [xtd], xtd_c, gtest, catch2",
        "  Solution File           sln            [xtd], xtd_c",
        "",
        "path:",
        "  Location to place the generated output. If no path is specified, the current path is used.",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -n, --name          The name for the project. If no name is specified, the name of the specified path or of the current directory is used.",
        "  --type              Filters templates based on available types. Predefined values are \"project\", \"item\" or \"other\".",
        "  -s , --sdk          Filters templates based on SDK/language and specifies the SDK/language of the template to create.",
        "",
        "",
        "Exemples:",
        "    xtdc generate console",
        "    xtdc generate gui my_app",
        "    xtdc generate --help",
      };
    }
    
    static list<string> get_install_help() noexcept {
      return {
        "Install a project.",
        "Usage: install [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         install debug config.",
        "  -r, --release       install release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc install",
        "    xtdc install my_app",
        "    xtdc install --help",
      };
    }
    
    static list<string> get_open_help() noexcept {
      return {
        "Open a project in default ide.",
        "Usage: open [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         open debug config.",
        "  -r, --release       open release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc open",
        "    xtdc open my_app",
        "    xtdc open --help",
      };
    }
    
    
    static list<string> get_update_help() noexcept {
      return {
        "Regenrates a project.",
        "Usage: update [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -t, --target        update a specified target project.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc update",
        "    xtdc update my_apps",
        "    xtdc update my_apps -t my_app1",
        "    xtdc update --help",
      };
    }
    
    static list<string> get_run_help() noexcept {
      return {
        "Compiles and immediately executes a project.",
        "Usage: run [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         run debug config.",
        "  -r, --release       run release config.",
        "  -t, --target        run a specified target project.",
        "  -w, --wait          wait until the execution is finished.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc run",
        "    xtdc run my_apps",
        "    xtdc run my_apps -t my_app1",
        "    xtdc run --help",
      };
    }
    
    static list<string> get_targets_help() noexcept {
      return {
        "List project targets.",
        "Usage: targets [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc list",
        "    xtdc list my_app",
        "    xtdc list --help",
      };
    }
    
    static list<string> get_test_help() noexcept {
      return {
        "Runs unit tests using the test runner specified in the project.",
        "Usage: test [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         test debug config.",
        "  -r, --release       test release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc test",
        "    xtdc test my_app",
        "    xtdc test --help",
      };
    }
    
    static list<string> get_uninstall_help() noexcept {
      return {
        "Uninstall a project.",
        "Usage: uninstall [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         uninstall debug config.",
        "  -r, --release       uninstall release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc uninstall",
        "    xtdc uninstall my_app",
        "    xtdc uninstall --help",
      };
    }
    
    static list<string> get_info() noexcept {
      return {
        "",
        get_xtd_version(),
        //"",
        "Operating System:",
        string::format("  Name: {}", environment::os_version().name()),
        string::format("  Version: {}", environment::os_version().version()),
        string::format("  Service pack: {}", environment::os_version().service_pack()),
        string::format("  Desktop environment: {}", environment::os_version().desktop_environment()),
        string::format("  64 bit: {}", environment::os_version().is_64_bit()),
        "",
        "Compiler:",
        string::format("  Name: {}", environment::compiler_version().name()),
        string::format("  Version: {}", environment::compiler_version().version()),
        string::format("  Mode: {}", environment::compiler_version().is_build_type_debug() ? "Debug" : "Release"),
        string::format("  64 bit: {}", environment::compiler_version().is_64_bit()),
        "",
        "Language:",
        string::format("  Name: {}", environment::cpp_version().name()),
        string::format("  Version: {}", environment::cpp_version().version()),
        string::format("  Experimental: {}", environment::cpp_version().is_experimental_language()),
        string::format("  Supported: {}", environment::cpp_version().is_supported()),
        "",
      };
    }
    
    static string get_xtd_version() noexcept {
      auto result = string::format("xtd Framework:{}", environment::new_line());
      for (auto library : environment::xtd_libraries()) {
        result += string::format("  {}", library.name(), environment::new_line());
        result += string::format("    Version: {}{}", library.version(), environment::new_line());
        result += string::format("    include path: {}{}", library.include_path(), environment::new_line());
        result += string::format("    library path: {}{}", library.library_path(), environment::new_line());
        result += string::format("    resources path: {}{}", library.resources_path(), environment::new_line());
      }
      return result;
    }
    
    static string get_version() noexcept {
      return string::format("xtdc version {}, (c) {} by Gammasoft", get_version_number(), xtd::date_time::now().year());
    }
    
    static string get_version_number() noexcept {
      return environment::version().to_string();
    }
    
    static int add(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto type = string::empty_string;
      auto sdk = string::empty_string;
      auto name = string::empty_string;
      auto path = string::empty_string;
      if (!process_add_arguments(args, show_help, type, name, path, sdk, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option)) write_line_error(string::format("Unknown option: {0}", invalid_option));
        else write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_add_help()));
        return EXIT_FAILURE;
      }
      
      if (show_help) {
        console::write_line(string::join("\n", get_add_help()));
        return EXIT_SUCCESS;
      }
      
      if (xtd::string::is_empty(type)) type = "gui";
      if (xtd::string::is_empty(sdk)) sdk = "xtd";
      if (xtd::string::is_empty(name)) name = get_project_name_from_path(path);
      
      if (xtd::string::is_empty(name)) {
        write_line_error("The name is empty.");
        return EXIT_FAILURE;
      }
      if (name.first_or_default([](auto c) {return !(char_object::is_letter_or_digit(c) || c == '_');}) != 0) {
        write_line_error(string::format("The name : \"{}\" contains invalid charaters.", name));
        return EXIT_FAILURE;
      }
      if (name.length() > 128) {
        write_line_error("The size of the name is invalid, the size must be less than or equal to 128.");
        return EXIT_FAILURE;
      }
      
      auto project_type = dictionary<string, xtdc_command::project_type> {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}} [type];
      auto project_sdk = dictionary<string, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"catch2", xtdc_command::project_sdk::catch2}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"fltk", xtdc_command::project_sdk::fltk}, {"gtest", xtdc_command::project_sdk::gtest}, {"gtk+2", xtdc_command::project_sdk::gtk2}, {"gtk+3", xtdc_command::project_sdk::gtk3}, {"gtk+4", xtdc_command::project_sdk::gtk4}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"qt5", xtdc_command::project_sdk::qt5}, {"qt6", xtdc_command::project_sdk::qt6}, {"win32", xtdc_command::project_sdk::win32}, {"winforms", xtdc_command::project_sdk::winforms}, {"wpf", xtdc_command::project_sdk::wpf}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"xtd", xtdc_command::project_sdk::xtd}, {"xtd_c", xtdc_command::project_sdk::xtd_c}} [sdk];
      auto project_language = dictionary<string, xtdc_command::project_language> {{"cocoa", xtdc_command::project_language::objectivec}, {"fltk", xtdc_command::project_language::cpp}, {"gtk+2", xtdc_command::project_language::cpp}, {"gtk+3", xtdc_command::project_language::cpp}, {"gtk+4", xtdc_command::project_language::cpp}, {"gtkmm", xtdc_command::project_language::cpp}, {"qt5", xtdc_command::project_language::cpp}, {"qt6", xtdc_command::project_language::cpp}, {"win32", xtdc_command::project_language::cpp}, {"winforms", xtdc_command::project_language::csharp}, {"wpf", xtdc_command::project_language::csharp}, {"wxwidgets", xtdc_command::project_language::cpp}, {"xtd", xtdc_command::project_language::cpp}, {"xtd_c", xtdc_command::project_language::c}, {"c++", xtdc_command::project_language::cpp}, {"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"c#", xtdc_command::project_language::csharp}, {"csharp", xtdc_command::project_language::csharp}, {"objective-c", xtdc_command::project_language::objectivec}, {"objectivec", xtdc_command::project_language::objectivec}} [sdk];
      auto status = project_management(get_project_full_path_from_path(path)).add(name, project_type, project_sdk, project_language);
      switch (status) {
        case operation_status::success: console::write_line("\n** ADD SUCCEEDED **\n\n"); break;
        case operation_status::already_exist: write_line_error(xtd::string::format("Path {} already exists and not empty! Add project aborted.", path)); break;
        case operation_status::cmake_prefix_path_not_set: write_line_error("Set your CMAKE_PREFIX_PATH environment variable to the Qt installation prefix! Add project aborted."); break;
        case operation_status::invalid_language: write_line_error("The language param not valid with sdk param! Add project aborted."); break;
        case operation_status::invalid_sdk: write_line_error("The sdk param not valid with type param! Add project aborted."); break;
        //case operation_status::invalid_sdk_with_current_project: write_line_error("The sdk param not valid with current project sdk! Add project aborted."); break;
        case operation_status::unknown_project: write_line_error(xtd::string::format("Parent directory \"{}\", is not a known project! Add project aborted.", xtd::io::directory::get_parent(path).full_name())); break;
        default: write_line_error("\n** ADD FAILED **\n\n"); break;
      }
      return status == operation_status::success ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    
    static int build(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto clean_first = false;
      auto release = false;
      auto target = string::empty_string;
      auto path = string::empty_string;
      if (!process_build_arguments(args, show_help, clean_first, release, target, path, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option)) write_line_error(string::format("Unknown option: {0}", invalid_option));
        else write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_build_help()));
        return EXIT_FAILURE;
      }
      if (show_help) {
        console::write_line(string::join("\n", get_build_help()));
        return EXIT_SUCCESS;
      }
      
      auto chrono = stopwatch::start_new();
      auto status = project_management(get_project_full_path_from_path(path)).build(target, clean_first, release);
      switch (status) {
        case operation_status::success: console::write(xtd::environment::os_version().is_macos_platform() ? "" : "\n** BUILD SUCCEEDED **\n\n"); break;
        case operation_status::clean_error: write_error("\n** CLEAN FAILED **\n\n"); break;
        case operation_status::not_exist: write_error(xtd::string::format("Path {} does not exists or is empty! Build project aborted.\n\n", path)); break;
        default: write_error(xtd::environment::os_version().is_macos_platform() ? "" : "\n** BUILD FAILED **\n\n"); break;
      }
      chrono.stop();
      console::write_line("Time Elapsed {0}{1:H}:{1:M}:{1:S}.{1:L}", chrono.elapsed().days() ? string::format("{d}.", chrono.elapsed().days()) : "", chrono.elapsed());
      return status == operation_status::success ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    
    static int clean(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto release = false;
      auto path = string::empty_string;
      if (!process_clean_arguments(args, show_help, release, path, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option)) write_line_error(string::format("Unknown option: {0}", invalid_option));
        else write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_clean_help()));
        return EXIT_FAILURE;
      }
      if (show_help) {
        console::write_line(string::join("\n", get_clean_help()));
        return EXIT_SUCCESS;
      }
      
      auto status = project_management(get_project_full_path_from_path(path)).clean(release);
      switch (status) {
        case operation_status::success: break;
        case operation_status::not_exist: write_error(xtd::string::format("Path {} does not exists or is empty! Build project aborted.\n", path)); break;
        default: write_line_error("\n** CLEAN FAILED **\n"); break;
      }
      return status == operation_status::success ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    
    static int generate(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto type = string::empty_string;
      auto sdk = string::empty_string;
      auto name = string::empty_string;
      auto path = string::empty_string;
      if (!process_generate_arguments(args, show_help, type, name, path, sdk, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option)) write_line_error(string::format("Unknown option: {0}", invalid_option));
        else write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_generate_help()));
        return EXIT_FAILURE;
      }
      if (show_help) {
        console::write_line(string::join("\n", get_generate_help()));
        return EXIT_SUCCESS;
      }
      if (xtd::string::is_empty(type)) type = "gui";
      if (xtd::string::is_empty(sdk)) sdk = "xtd";
      if (xtd::string::is_empty(name)) name = get_project_name_from_path(path);
      
      if (xtd::string::is_empty(name)) {
        console::write_line("The name is empty.");
        return EXIT_FAILURE;
      }
      if (name.first_or_default([](auto c) {return !(char_object::is_letter_or_digit(c) || c == '_');}) != 0) {
        console::write_line("The name : \"{}\" contains invalid charaters.", name);
        return EXIT_FAILURE;
      }
      if (name.length() > 128) {
        console::write_line("The size of the name is invalid, the size must be less than or equal to 128.");
        return EXIT_FAILURE;
      }
      
      auto project_type = dictionary<string, xtdc_command::project_type> {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}} [type];
      auto project_sdk = dictionary<string, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"catch2", xtdc_command::project_sdk::catch2}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"fltk", xtdc_command::project_sdk::fltk}, {"gtest", xtdc_command::project_sdk::gtest}, {"gtk+2", xtdc_command::project_sdk::gtk2}, {"gtk+3", xtdc_command::project_sdk::gtk3}, {"gtk+4", xtdc_command::project_sdk::gtk4}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"qt5", xtdc_command::project_sdk::qt5}, {"qt6", xtdc_command::project_sdk::qt6}, {"win32", xtdc_command::project_sdk::win32}, {"winforms", xtdc_command::project_sdk::winforms}, {"wpf", xtdc_command::project_sdk::wpf}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"xtd", xtdc_command::project_sdk::xtd}, {"xtd_c", xtdc_command::project_sdk::xtd_c}} [sdk];
      auto project_language = dictionary<string, xtdc_command::project_language> {{"cocoa", xtdc_command::project_language::objectivec}, {"fltk", xtdc_command::project_language::cpp}, {"gtk+2", xtdc_command::project_language::cpp}, {"gtk+3", xtdc_command::project_language::cpp}, {"gtk+4", xtdc_command::project_language::cpp}, {"gtkmm", xtdc_command::project_language::cpp}, {"qt5", xtdc_command::project_language::cpp}, {"qt6", xtdc_command::project_language::cpp}, {"win32", xtdc_command::project_language::cpp}, {"winforms", xtdc_command::project_language::csharp}, {"wpf", xtdc_command::project_language::csharp}, {"wxwidgets", xtdc_command::project_language::cpp}, {"xtd", xtdc_command::project_language::cpp}, {"xtd_c", xtdc_command::project_language::c}, {"c++", xtdc_command::project_language::cpp}, {"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"c#", xtdc_command::project_language::csharp}, {"csharp", xtdc_command::project_language::csharp}, {"objective-c", xtdc_command::project_language::objectivec}, {"objectivec", xtdc_command::project_language::objectivec}} [sdk];
      auto status = project_management(get_project_full_path_from_path(path)).generate(name, project_type, project_sdk, project_language);
      switch (status) {
        case operation_status::success: console::write_line("\n** GENERATE SUCCEEDED **\n"); break;
        case operation_status::already_exist: write_line_error(xtd::string::format("Path {} does not exists or is empty! Genertae project aborted.", path)); break;
        case operation_status::cmake_prefix_path_not_set: write_line_error("Set your CMAKE_PREFIX_PATH environment variable to the Qt installation prefix! Genertae project aborted."); break;
        case operation_status::invalid_language: write_line_error("The language param not valid with sdk param! Genertae project aborted."); break;
        case operation_status::invalid_sdk: write_line_error("The sdk param not valid with type param! Generate project aborted."); break;
        case operation_status::invalid_sdk_with_current_project: write_line_error("The sdk param not valid with current project sdk! Add project aborted."); break;
        case operation_status::unknown_project: write_line_error(xtd::string::format("Parent directory \"{}\", is not a known project! Add project aborted.", xtd::io::directory::get_parent(path).full_name())); break;
        default: write_line_error("\n** GENERATE FAILED **\n"); break;
      }
      return status == operation_status::success ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    
    static int help(const list<string>& args) {
      console::write_line(string::join("\n", get_help()));
      return EXIT_SUCCESS;
    }
    
    static int install(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto release = false;
      auto path = string::empty_string;
      if (!process_install_arguments(args, show_help, release, path, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option)) write_line_error(string::format("Unknown option: {0}", invalid_option));
        else write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_install_help()));
        return EXIT_FAILURE;
      }
      if (show_help) {
        console::write_line(string::join("\n", get_install_help()));
        return EXIT_SUCCESS;
      }
      auto status = project_management(get_project_full_path_from_path(path)).install(release);
      switch (status) {
        case operation_status::success: console::write_line("\n** INSTALL SUCCEEDED **\n"); break;
        case operation_status::not_exist: write_error(xtd::string::format("Path {} does not exists or is empty! Install project aborted.\n", path)); break;
        default: write_line_error("\n** INSTALL FAILED **\n"); break;
      }
      return status == operation_status::success ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    
    static int open(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto release = false;
      auto path = string::empty_string;
      if (!process_open_arguments(args, show_help, release, path, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option))
          console::write_line("Unknown option: {0}", invalid_option);
        else
          write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_open_help()));
        return EXIT_FAILURE;
      }
      if (show_help)
        console::write_line(string::join("\n", get_open_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).open(release));
      return EXIT_SUCCESS;
    }
    
    static int update(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto target = string::empty_string;
      auto path = string::empty_string;
      if (!process_update_arguments(args, show_help, target, path, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option))
          console::write_line("Unknown option: {0}", invalid_option);
        else
          write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_update_help()));
        return EXIT_FAILURE;
      }
      if (show_help)
        console::write_line(string::join("\n", get_update_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).update(target));
      return EXIT_SUCCESS;
    }
    
    static int run(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto release = false;
      auto no_wait = false;
      auto target = string::empty_string;
      auto path = string::empty_string;
      if (!process_run_arguments(args, show_help, release, no_wait, target, path, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option))
          console::write_line("Unknown option: {0}", invalid_option);
        else
          write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_run_help()));
        return EXIT_FAILURE;
      }
      if (show_help)
        console::write_line(string::join("\n", get_run_help()));
      else {
        auto result = project_management(get_project_full_path_from_path(path)).run(target, release, !no_wait);
        if (!xtd::string::is_empty(result)) console::write_line(result);
      }
      return EXIT_SUCCESS;
    }
    
    static int targets(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto path = string::empty_string;
      if (!process_targets_arguments(args, show_help, path, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option))
          console::write_line("Unknown option: {0}", invalid_option);
        else
          write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_targets_help()));
        return EXIT_FAILURE;
      }
      if (show_help)
        console::write_line(string::join("\n", get_targets_help()));
      else {
        auto targets = xtd::string::join(", ", project_management(get_project_full_path_from_path(path)).targets());
        if (xtd::string::is_empty(targets)) targets = get_project_name_from_path(path);
        console::write_line(targets);
      }
      return EXIT_SUCCESS;
    }
    
    static int test(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto release = false;
      auto path = string::empty_string;
      if (!process_test_arguments(args, show_help, release, path, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option))
          console::write_line("Unknown option: {0}", invalid_option);
        else
          write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_test_help()));
        return EXIT_FAILURE;
      }
      if (show_help)
        console::write_line(string::join("\n", get_test_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).test(release));
      return EXIT_SUCCESS;
    }
    
    static int uninstall(const list<string>& args) {
      auto show_help = false;
      auto invalid_option = string::empty_string;
      auto release = false;
      auto path = string::empty_string;
      if (!process_uninstall_arguments(args, show_help, release, path, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option))
          console::write_line("Unknown option: {0}", invalid_option);
        else
          write_line_error("Invalid parameters");
        console::write_line(string::join("\n", get_uninstall_help()));
        return EXIT_FAILURE;
      }
      if (show_help)
        console::write_line(string::join("\n", get_uninstall_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).uninstall(release));
      return EXIT_SUCCESS;
    }
    
    static int documentation(const list<string>& args) {
      process::start(process_start_info {"https://gammasoft71.github.io/xtd/docs/documentation"}.use_shell_execute(true));
      return EXIT_SUCCESS;
    }
    
    static int examples(const list<string>& args) {
      process::start(process_start_info {"https://github.com/gammasoft71/xtd/blob/master/examples/README.md"}.use_shell_execute(true));
      return EXIT_SUCCESS;
    }
    
    static int guide(const list<string>& args) {
      process::start(process_start_info {"https://gammasoft71.github.io/xtd/reference_guides/latest/index.html"}.use_shell_execute(true));
      return EXIT_SUCCESS;
    }
    
    static int web(const list<string>& args) {
      process::start(process_start_info {"https://gammasoft71.github.io/xtd"}.use_shell_execute(true));
      return EXIT_SUCCESS;
    }
    
    static bool process_xtdc_arguments(bool& show_floppy, bool& show_help, bool& show_info, bool& show_version, list<string>& command_args, string& invalid_option) {
      auto args = environment::get_command_line_args();
      for (auto i = 1_z; i < args.size(); i += 1) {
        if (args[i] == "-f" || args[i] == "--floppy")
          show_floppy = true;
        else if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-i" || args[i] == "--info")
          show_info = true;
        else if (args[i] == "-v" || args[i] == "--version")
          show_version = true;
        else if (!args[i].starts_with('-')) {
          command_args = {args.begin() + i, args.end()};
          i = args.size();
        } else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_add_arguments(const list<string>& args, bool& show_help, string& type, string& name, string& path, string& sdk, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-n" || args[i] == "--name") {
          if (i + 1 >= args.count()) return false;
          name = args[++i];
        } else if (args[i] == "-s" || args[i] == "--sdk") {
          if (i + 1 >= args.count()) return false;
          sdk = args[++i];
        } else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        } else if (xtd::string::is_empty(type))
          type = args[i];
        else if (xtd::string::is_empty(name))
          path = args[i];
        else
          return false;
      }
      return true;
    }
    
    static bool process_build_arguments(const list<string>& args, bool& show_help, bool& clean_first, bool& release, string& target, string& path, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-c" || args[i] == "--clean-first")
          clean_first = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (xtd::string::is_empty(path))
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_clean_arguments(const list<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (xtd::string::is_empty(path))
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_generate_arguments(const list<string>& args, bool& show_help, string& type, string& name, string& path, string& sdk, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-n" || args[i] == "--name") {
          if (i + 1 >= args.count()) return false;
          name = args[++i];
        } else if (args[i] == "-s" || args[i] == "--sdk") {
          if (i + 1 >= args.count()) return false;
          sdk = args[++i];
        } else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        } else if (xtd::string::is_empty(type))
          type = args[i];
        else if (xtd::string::is_empty(path))
          path = args[i];
        else
          return false;
      }
      return true;
    }
    
    static bool process_install_arguments(const list<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (xtd::string::is_empty(path))
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_open_arguments(const list<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (xtd::string::is_empty(path))
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_update_arguments(const list<string>& args, bool& show_help, string& target, string& path, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (xtd::string::is_empty(path))
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_run_arguments(const list<string>& args, bool& show_help, bool& release, bool& no_wait, string& target, string& path, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (args[i] == "-nw" || args[i] == "--no_wait")
          no_wait = true;
        else if (xtd::string::is_empty(path))
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_targets_arguments(const list<string>& args, bool& show_help, string& path, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (xtd::string::is_empty(path))
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_test_arguments(const list<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (xtd::string::is_empty(path))
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_uninstall_arguments(const list<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (auto i = 1_z; i < args.count(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (xtd::string::is_empty(path))
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static int invalid_command(const list<string>& command_args) {
      console::write_line("Invalid command");
      console::write_line(string::join("\n", get_help()));
      return EXIT_FAILURE;
    }
    
    static int run_commands(const list<string>& command_args, bool show_floppy, bool show_help, bool show_info, bool show_version, string invalid_option) {
      if (show_floppy || show_version || show_info || show_help) {
        console::write_line(get_version());
        if (show_version) console::write("");
        else if (show_floppy) console::write_line(string::join("\n", get_floppy()));
        else if (show_info) console::write_line(string::join("\n", get_info()));
        else if (show_help) console::write_line(string::join("\n", get_help()));
        return EXIT_SUCCESS;
      }
      static auto commands = dictionary<string, delegate<int(const list<string>&) >> {{"add", {add}}, {"build", {build}}, {"clean", {clean}}, {"documentation", {documentation}}, {"examples", {examples}}, {"generate", {generate}}, {"guide", {guide}}, {"help", {help}}, {"install", {install}}, {"new", {new_project::execute}}, {"open", {open}}, {"update", {update}}, {"run", {run}}, {"targets", {targets}}, {"test", {test}}, {"uninstall", {uninstall}}, {"web", {web}}};
      if (command_args.empty() || !commands.contains_key(command_args[0])) return invalid_command(command_args);
      return commands[command_args[0]](command_args);
      //auto iterator = commands.find(command_args[0]);
      //if (iterator == commands.end()) return invalid_command(command_args);
      //return iterator->second(command_args);
    }
    
    static void write_error(const string& message) {
      console::foreground_color(console_color::red);
      console::write(message);
      console::reset_color();
    }
    
    static void write_line_error(const string& message) {
      console::foreground_color(console_color::red);
      console::write_line(message);
      console::reset_color();
    }
  };
}

startup_(xtdc_command::xtdc::main);
