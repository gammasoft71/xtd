/// @file
/// @brief Contains doygen main page.

/// @mainpage xtd.tunit - Reference Guide Documentation
///
/// @section FeaturesSection Features
///   * An [xUnit](https://en.wikipedia.org/wiki/XUnit) test framework.
///   * Modern c++17.
///   *  Auto registration of class and method based tests.
///   *  Rich set of assertions.
///   *  std::ostream output event listener.
///   *  You can create your own event listener (see [create_your_own_event_listener example](examples/create_your_own_event_listener)).
///   *  Gets duration for each test, and for each class test.
///   *  Multi-platform (Windows, macOS, linux, ...).
///   *  CMake build script.
///   *  Very easy to use.
///   * ...
///
/// For more information see <a href=https://github.com/gammasoft71/xtd.tunit/blob/master/README.md>Documentation.md</a> file.
///
/// @section ExamplesSection Examples
/// The classic first application 'Hello World'.
///
/// src/tunit_hello_world.cpp:
/// @code
/// #include <xtd/tunit>
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
///       assert::are_equal_("Hello, World!", s);
///     }
///
///     void test_method_(create_string_from_chars) {
///       string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
///       assert::are_equal_("Hello, World!", s);
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
/// For more examples see <a href="hhttps://github.com/gammasoft71/xtd.tunit/tree/master/examples/">Examples</a>.
///
/// @section DownloadSection Download and install
/// Before running examples you must download and install xtd.tunit. To download and install it read <a href="https://github.com/gammasoft71/xtd.tunit/blob/master/docs/Downloads.md">Downloads.md</a> file.
