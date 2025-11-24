# Tips & tricks list

🟢 Published | 🟡 Ready to publish | 🔴 Not started

| Sts | Number | Publish date       | Subject                                                                 | Comparison with                             |
| --- | ------ | ------------------ |------------------------------------------------------------------------ | ------------------------------------------- |
| 🔴  |        |                    | Localizing strings with xtd::environment::culture                       | .NET / Qt QTranslator                       |
| 🔴  |        |                    | Showing notifications (balloon tips / tray icons)                       | Qt QSystemTrayIcon / Win32 Shell_NotifyIcon |
| 🔴  |        |                    | How to use xtd::forms::clipboard to copy/paste text and images          | Qt / wxWidgets                              |
|     |        |                    |                                                                         |                                             |
| 🔴  | #39    | December 21, 2026  | Handling unknown exceptions with xtd::application::thread_exception     | Qt / wxWidgets                              |
| 🔴  | #38    | December 7, 2026   | Simplifying file I/O with xtd::io::file::read_all_text / write_all_text | std::fstream                                |
| 🔴  | #37    | November 23, 2026  | Exploring xtd::diagnostics::debug and trace for logging                 | std::cerr                                   |
| 🔴  | #36    | November 9, 2026   | Using xtd::guid for unique identifiers                                  | Boost::uuid                                 |
| 🔴  | #35    | October 26, 2026   | Managing time with xtd::datetime and xtd::timespan                      | std::chrono                                 |
| 🔴  | #34    | October 12, 2026   | Asynchronous operations with xtd::threading::thread                     | std::thread                                 |
| 🔴  | #33    | September 28, 2026 | Using xtd::random to generate random numbers                            | std::random                                 |
| 🔴  | #32    | September 14, 2026 | How to create a system report                                           | NA                                          |
| 🔴  | #31    | August 31, 2026    | Using loading indicator                                                 | wxWidets / Qt                               |
| 🔴  | #30    | August 17, 2026    | Creating a simple animation with xtd::forms::animation                  | NA                                          |
| 🔴  | #29    | August 3, 2026     | Resource management with xtd::resources                                 | Qt                                          |
| 🔴  | #28    | July 20, 2026      | Using a asynchonous delegates                                           | NA                                          |
| 🔴  | #27    | July 6, 2026       | Using settings                                                          | wxWidgets / Qt                              |
| 🔴  | #26    | June 22, 2026      | Creating a client server in high, medium and low levels                 | NA                                          |
| 🔴  | #25    | June 8, 2026       | Creating xtd::forms::button with style sheet                            | Qt                                          |
| 🔴  | #24    | May 25, 2026       | Getting and formatting date/time easily                                 | std::chrono, Qt                             |
| 🔴  | #23    | May 11, 2026       | Writing to debug output and console at once                             | std::cout / OutputDebugString               |
| 🔴  | #22    | April 27, 2026     | Creating owner control                                                  | Qt                                          |
| 🔴  | #21    | April 13, 2026     | LINQ-like queries with xtd::linq::enumerable                            | .NET LINQ / C++20 std::ranges               |
| 🔴  | #20    | March 30, 2026     | Handling exceptions with xtd::diagnostics::stack_trace                  | C++ modern                                  |
| 🔴  | #19    | March 16, 2026     | Using xtd::forms::lcd_label                                             | Qt                                          |
| 🔴  | #18    | March 2, 2026      | Measuring execution time with xtd::diagnostics::stopwatch               | std::chrono                                 |
| 🔴  | #17    | February 16, 2026  | Easy environment variable access with xtd::environment                  | Qt qEnvironmentVariable / C getenv          |
| 🔴  | #16    | February 2, 2026   | Creating a spheric xtd::forms::form without caption                     | wxWidgets / Qt                              |
| 🔴  | #15    | January 19, 2026   | Using self_ to simplify code instead of raw this                        | C++ modern                                  |
| 🔴  | #14    | January 5, 2026    | Displaying an open/save file dialog in one line                         | Qt QFileDialog / Win32 API                  |
| 🔴  | #13    | December 22, 2025  | Drawing text and shapes in a form with xtd::drawing::graphics           | Qt painting / GDI+                          |
| 🔴  | #12    | December 8, 2025   | Formatting strings with xtd::string::format                             | C++20 std::format / Qt QString::arg         |
| 🟢  | #11    | November 24, 2025  | Using timers (interval, elapsed event)                                  | std::thread + sleep, Qt Timer               |
| 🟢  | #10    | November 10, 2025  | Unit testing with xtd::tunit                                            | Catch2 / gtest                              |
| 🟢  | #9     | October 27, 2025   | Adding color to console output (text + background)                      | ANSI escape codes                           |
| 🟢  | #8     | October 13, 2025   | array_list a heterogeneous container supporting multiple types          | C++ modern / Boost / Qt                     |
| 🟢  | #7     | September 29, 2025 | Creating a simple form with a button                                    | Qt / WinForms                               |
| 🟢  | #6     | September 15, 2025 | Getting special folders                                                 | Win32 API / Qt                              |
| 🟢  | #5     | September 1, 2025  | Applying image effects                                                  | NA                                          |
| 🟢  | #4     | August 18, 2025    | Why xtd simplifies your code compared to Qt or wxWidgets                | Qt / wxWidgets                              |
| 🟢  | #3     | August 6, 2025     | Showing a message box in one line                                       | Qt / wxWidgets                              |
| 🟢  | #2     | July 31, 2025      | Very simple threads synchronisation                                     | C++ modern                                  |
| 🟢  | #1     | July 8, 2025       | Retrieving command-line arguments                                       | C++ modern                                  |

# Getting and formatting date/time easily

```cpp
#include <xtd/xtd>

auto main() -> int {
  console::write_line(date_time::now().to_long_date_string());
  console::write_line(date_time::now().to_long_time_string());
  console::write_line(date_time::now().to_string("u"));
}
```

# Writing to debug output and console at once

```cpp
#include <xtd/xtd>

auto main() -> int {
  debug::write_line("This goes to console and debug output!");
}
```

Write on console, debug_form, syslog, ... and any listener that you want.
