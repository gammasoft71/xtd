/// @file
/// @brief Contains doygen main page.

/// @mainpage xtd.tunit - Reference Guide Documentation
///
/// @section FeaturesSection Features
///   * An <a href="https://en.wikipedia.org/wiki/XUnit">xUnit</a> test framework.
///   * Auto registration of class and method based tests.
///   * Rich set of assertions.
///   * ...
///
/// For more information see <a href="https://gammasoft71.wixsite.com/xtd-tunit">xtd.tunit website</a> (or <a href="https://github.com/gammasoft71/xtd.tunit/blob/master/docs/home.md">markdown documentations</a>) and <a href="https://codedocs.xyz/gammasoft71/xtd.tunit/">Reference Guide</a>).
///
/// @section ExamplesSection Examples
/// The classic first application 'Hello World'.
///
/// src/tunit_hello_world.cpp:
/// @code
/// #include <xtd/xtd.tunit>
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
///       valid::are_equal(13, s.size());
///       assert::are_equal_("Hello, World!", s);
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
/// // The main entry point for the application.
/// int main() {
///   return console_unit_test().run();
/// }
/// @endcode
///
/// For more examples see <a href="https://github.com/gammasoft71/xtd.tunit/tree/master/examples/">examples</a>.
///
/// @section DownloadSection Download and install
/// Before running examples you must download and install xtd.tunit. To download and install it read <a href="https://github.com/gammasoft71/xtd.tunit/blob/master/docs/downloads.md">Downloads.md</a> file.
