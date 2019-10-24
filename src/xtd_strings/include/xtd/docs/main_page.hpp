/// @file
/// @brief Contains doygen main page.

/// @mainpage xtd.strings - Reference Guide Documentation
///
/// @section FeaturesSection Features
///   * New istring, iu16string, iu32string, iwstring immutable string types and immutable_string_base immutable string class.
///   * Immutable string litteral operators _is.
///   * String format helper.
///   * String concat helper.
///   * String padding helper.
///   * Join strings helper.
///   * Split strings helper.
///   * and more...
///
/// For more information see <a href="https://gammasoft71.wixsite.com/xtd-strings">xtd.strings website</a> (or <a href="https://github.com/gammasoft71/xtd.strings/blob/master/docs/home.md">markdown documentations</a>) and <a href="https://codedocs.xyz/gammasoft71/xtd.strings/">Reference Guide</a>).
///
/// @section ExamplesSection Examples
/// The classic first application 'Hello World'.
///
/// src/strings_hello_world.cpp:
/// @code
/// #include <xtd/xtd.strings>
/// #include <iostream>
///
/// using namespace std;
/// using namespace string_literals;
/// using namespace xtd;
///
/// // The main entry point for the application.
/// int main() {
///   cout << strings::format("{}, {}!", "Hello", "World"s) << endl;
/// }
/// @endcode
///
/// For more examples see <a href="https://github.com/gammasoft71/xtd.strings/tree/master/examples/">examples</a>.
///
/// @section DownloadSection Download and install
/// Before running examples you must download and install xtd.strings. To download and install it read <a href="https://github.com/gammasoft71/xtd.strings/blob/master/docs/downloads.md">Downloads.md</a> file.
