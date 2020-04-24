/// @file
/// @brief Contains doygen main page.

/// @mainpage xtd.forms - Reference Guide Documentation
///
/// @section NotesSection Notes
/// xtd.forms is under development.
///
/// @section FeaturesSection Features
///   * Contains common controls, containers, menu, toolbar, components, various dialogs, ...
///   * Easy catch control events by using event and delegates classes.
///   * All controls are natives (win32 on windows, cocoa on macOS, gtk+3 on linux).
///   * ...
///
/// For more information see <a href="https://gammasoft71.wixsite.com/gammasoft">xtd.foms website</a> (or <a href="https://github.com/gammasoft71/xtd.forms/tree/master/docs/home.md">markdown documentations</a>) and <a href="https://codedocs.xyz/gammasoft71/xtd.forms/">Reference Guide</a>).
///
/// @section ExamplesSection Examples
/// The following examples "Hello, world!" show how use form and button control, catch event click and show a message box.
///
/// forms_hello_world.cpp:
/// @code
/// #include <xtd/xtd.forms>
///
/// using namespace xtd::forms;
///
/// int main() {
///   button button1;
///   button1.text("Click me");
///   button1.location({10, 10});
///   button1.click += [] {
///     message_box::show("Hello, World!");
///   };
///
///   form form1;
///   form1.text("Hello world (message_box))");
///   form1.controls().push_back(button1);
///
///   application::run(form1);
/// }
/// @endcode
///
/// For more examples see <a href="https://github.com/gammasoft71/xtd.forms/tree/master/examples/">examples</a>.
///
/// @section DownloadSection Download and install
/// Before running examples you must download and install xtd.forms. To download and install it read <a href="https://github.com/gammasoft71/xtd.forms/tree/master/docs/downloads.md">Downloads.md</a> file.
