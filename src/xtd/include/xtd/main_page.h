/// @file
/// @brief Contains doygen main page.

/// @mainpage xtd - Reference Guide Documentation
///
/// <b>Modern c++17/20 framework to create console, GUI and unit test applications on Windows, macOS, Linux, iOS and android.</b>
///
/// @image html xtd_header.png
///
/// @section FeaturesSection Features
///   * a collection of native C++ classes libraries, to complete std;
///   * written in efficient, modern C++17 / C++20;
///   * and highly portable and available on many different platforms (Windows, macOS, Linux, iOS and android);
///
/// @subsection MoreInformationSubsection For more information see:
///  * <a href="https://gammasoft71.wixsite.com/xtdpro">website</a>
///  * <a href="https://github.com/gammasoft71/xtd/tree/master/docs/home.md">markdown documentations</a>
///  * <a href="https://github.com/gammasoft71/xtd">sources</a>
///  * <a href="https://codedocs.xyz/gammasoft71/xtd/">Reference Guide</a>
///
/// @section ExamplesSection Examples
/// The classic first application 'Hello World'.
///
/// @subsection ExamplesConsoleSubsection Console
/// hello_world_console.cpp:
/// @code
/// #include <xtd/xtd>
///
/// using namespace xtd;
///
/// int main() {
///   console::background_color(console_color::blue);
///   console::foreground_color(console_color::white);
///   console::write_line("Hello, World!");
/// }
/// @endcode
///
/// CMakeLists.txt:
/// @code
/// cmake_minimum_required(VERSION 3.3)
///
/// project(hello_world_console)
/// find_package(xtd REQUIRED)
/// add_sources(hello_world_console.cpp)
/// target_type(CONSOLE_APPLICATION)
/// @endcode
///
/// @subsubsection ExamplesConsoleBuildAndRunSubsubsection Build and run
/// Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:
/// @code
/// xtdc run
/// @endcode
///
/// @subsubsection ExamplesConsoleOutputSubsubsection Output
/// @code
/// Hello, World!
/// @endcode
///
/// @subsection ExamplesGUISubsection GUI
/// hello_world_forms.cpp:
/// @code
/// #include <xtd/xtd>
///
/// using namespace xtd::forms;
///
/// int main() {
///   button button1;
///   button1.text("Click me");
///   button1.location({10, 10});
///   button1.click += [] {
///     messageBox::show("Hello, World!");
///   };
///
///   form form1;
///   form1.text("Hello world (message_box)");
///   form.controls().push_back(button1);
///
///   application::run(form1);
/// }
/// @endcode
///
/// CMakeLists.txt:
/// @code
/// cmake_minimum_required(VERSION 3.3)
///
/// project(hello_world_forms)
/// find_package(xtd REQUIRED)
/// add_sources(hello_world_forms.cpp)
/// target_type(GUI_APPLICATION)
/// @endcode
///
/// @subsubsection ExamplesGUIBuildAndRunSubsubsection Build and run
/// Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:
/// @code
/// xtdc run
/// @endcode
///
/// @subsubsection ExamplesGUIOutputSubsubsection Output
///
/// Windows:
///  @image html hello_world_message_box_w.png
/// <br>
///  @image html hello_world_message_box_wd.png
///
/// macOS:
///  @image html hello_world_message_box_m.png
/// <br>
///  @image html hello_world_message_box_md.png
///
/// Linux Gnome:
///  @image html hello_world_message_box_g.png
/// <br>
///  @image html hello_world_message_box_gd.png
///
/// @subsection ExamplesUnitTestSubsection Unit tests
/// hello_world_test.cpp:
/// @code
/// #include <xtd/xtd>
/// #include <string>
///
/// using namespace std;
/// using namespace xtd::tunit;
///
/// namespace unit_tests {
///   class test_class_(hello_world_test) {
///   public:
///     void test_method_(create_string_from_literal) {
///       string s = "Hello, World!";
///       assert::are_equal("Hello, World!", s);
///     }
///
///     void test_method_(create_string_from_chars) {
///       string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
///       valid::are_equal(13, s.size());
///       string_assert::starts_with("Hello,", s);
///       string_assert::ends_with(" World!", s);
///     }
///   };
/// }
///
/// int main() {
///   return console_unit_test(argv, argc).run();
/// }
/// @endcode
///
/// CMakeLists.txt:
/// @code
/// cmake_minimum_required(VERSION 3.3)
///
/// project(hello_world_test)
/// find_package(xtd REQUIRED)
/// add_sources(hello_world_test.cpp)
/// target_type(TEST_APPLICATION)
/// @endcode
///
/// @subsubsection ExamplesUnitTestBuildAndRunSubsubsection Build and run
/// Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:
/// @code
/// xtdc run
/// @endcode
///
/// @subsubsection ExamplesUnitTestOutputSubsubsection Output
/// @code
/// Start 2 tests from 1 test case
/// Run tests:
///   SUCCEED hello_world_test.create_string_from_literal (0 ms total)
///   SUCCEED hello_world_test.create_string_from_chars (0 ms total)
///
/// Test results:
///   SUCCEED 2 tests.
/// End 2 tests from 1 test case ran. (0 ms total)
/// @endcode
///
/// @section GettingStartedSection Getting Started
///
///  * <a href="https://gammasoft71.wixsite.com/xtdpro/download">Installation</a> provides download and install documentation.
///  * <a href="https://gammasoft71.wixsite.com/xtdpro/portability">Portability</a> provides information about C++, libraries dependency, Operating System suported, Compilators and Devepment Environment tools..
///  * <a href="https://gammasoft71.wixsite.com/xtdpro/examples">Examples</a> provides some examples.
