/// @file
/// @brief Contains doygen main page.

/// @mainpage xtd. - Reference Guide Documentation
///
/// @section FeaturesSection Features
///   * <a href="https://github.com/gammasoft71/xtd.console">xtd.console</a> Modern c++17 library to manage console application on Windows, macOS and Linux.
///   * <a href="https://github.com/gammasoft71/xtd.delegates">xtd.delegates</a> Modern c ++17 library  containing delegate which is a data structure that refers to a static method or to a class instance and an instance method of that class.
///   * <a href="https://github.com/gammasoft71/xtd.io">xtd.io</a> Modern c++17 library, that allow reading and writing to files and data streams, and that provide basic file and directory support, for Windows, macOS, Linux, iOS and android.
///   * <a href="https://github.com/gammasoft71/xtd.properties">xtd.properties</a> another c#-like property accessor for C++11 and above.
///   * <a href="https://github.com/gammasoft71/xtd.strings">xtd.strings</a> Modern c++17 library to add string utilities on Windows, macOS and Linux.
///   * <a href="https://github.com/gammasoft71/xtd.tunit">xtd.tunit</a> Modern c++17 unit testing framework on Windows, macOS, Linux, iOS and android.
///
/// For more information see <a href="https://gammasoft71.wixsite.com/gammasoft">Gammasoft website</a> (or <a href="https://github.com/gammasoft71/xtd/blob/master/docs/home.md">markdown documentations</a>) and <a href="https://codedocs.xyz/gammasoft71/xtd/">Reference Guide</a>).
///
/// @section ExamplesSection Examples
/// The classic first application 'Hello World'.
///
/// src/tunit_hello_world_console.cpp:
/// @code
/// #include <xtd/xtd>
/// #include <string>
///
/// using namespace std;
/// using namespace xtd;
///
/// // The main entry point for the application.
/// int main() {
///   const char* s1 = "Hello,";
///   string s2 = "World!";
///
///   cout << foreground_color(console_color::green);
///   cout << format("%s%7s", s1, s2);
///   cout << reset_color() << endl;
///
///   console::background_color(console_color::blue);
///   console::foreground_color(console_color::white);
///   console::write_line("%s%7s", s1, s2);
///   console::reset_color();
/// }
/// @endcode
///
/// src/hello_worlds_forms.cpp:
/// @code
/// #include <xtd/xtd>
///
/// using namespace xtd;
/// using namespace xtd::drawing;
/// using namespace xtd::forms;
///
/// // The main entry point for the application.
/// int main() {
///   application::enable_visual_styles();
///
///   button button1;
///   button1.text("Click me");
///   button1.location(point(10, 10));
///   button1.click += [&] {
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
/// src/hello_worlds_tunit.cpp:
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
///       assert::are_equal("Hello, World!", s);
///     }
///   };
/// }
///
/// // The main entry point for the application.
/// int main(int argc, char* argv[]) {
///   return console_unit_test(argv, argc).run();
/// }
/// @endcode
///
/// For more examples see <a href="https://github.com/gammasoft71/xtd/tree/master/examples/">examples</a>.
///
/// @section DownloadSection Download and install
/// Before running examples you must download and install xtd. To download and install it read <a href="https://github.com/gammasoft71/xtd/blob/master/docs/downloads.md">Downloads.md</a> file.
