/// @file
/// @brief Contains doygen main page.

/// @mainpage xtd.console - Reference Guide Documentation
///
/// @section FeaturesSection Features
///   * Console I/O charecters and wide charercters Streams.
///   * Full utf-8 support.
///   * Writes the text representation of the specified list of arguments to the standard output stream using the specified format information.
///   * Get or set the size of the console window.
///   * Get or set the position of the console window relative to the screen buffer.
///   * Get or set the size of the screen buffer.
///   * Get or set the position of the cursor.
///   * Get or set the size of the cursor.
///   * Play the sound of a beep through the console speaker.
///   * Get or set the foreground and background colors.
///   * Intercept and send callback to the user when the Control modifier key (Ctrl) and either the C console key (C) or the Break key are pressed simultaneously (Ctrl+C or Ctrl+Break).
///   * ...
///
/// For more information see <a href=https://github.com/gammasoft71/xtd.console/blob/master/README.md>Documentation.md</a> file.
///
/// @section ExamplesSection Examples
/// The following examples "Hello, world!" show how to change the color of the text in three different ways.
///
/// <b>Using xtd::console::WriteLine</b>
///
/// hello_world_console.cpp:
/// @code
/// #include <console/console>
///
/// using namespace xtd;
///
/// // The main entry point for the application.
/// int main() {
///   console::foreground_color(console_color::blue);
///   console::write_line("Hello, World!");
///   console::reset_color();
/// }
/// @endcode
///
/// <b>Using xtd::console::out character ostream</b>
///
/// hello_world_console_out.cpp:
/// @code
/// #include <console/console>
///
/// using namespace std;
/// using namespace xtd;
///
/// // The main entry point for the application.
/// int main() {
///   console::out << foreground_color(console_color::blue) << "Hello, World!" << reset_color() << endl;
/// }
/// @endcode
///
/// <b>Using std::cout character ostream</b>
///
/// hello_world_cout.cpp:
/// @code
/// #include <console/console>
///
/// using namespace std;
/// using namespace xtd;
///
/// // The main entry point for the application.
/// int main() {
///   cout << foreground_color(console_color::blue) << "Hello, World!" << reset_color() << endl;
/// }
/// @endcode
///
/// For more examples see <a href="hhttps://github.com/gammasoft71/xtd.console/tree/master/examples/">Examples</a>.
///
/// @section DownloadSection Download and install
/// Before running examples you must download and install xtd.console. To download and install it read <a href="https://github.com/gammasoft71/xtd.console/blob/master/docs/Downloads.md">Downloads.md</a> file.
