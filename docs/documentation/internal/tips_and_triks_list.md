# Tips & tricks list

🟢 Published | 🟡 Ready to publish | 🔴 Not started

| Sts | Number | Publish date       | Subject                                                        | Comparison with                             |
| --- | ------ | ------------------ |--------------------------------------------------------------- | ------------------------------------------- |
| 🔴  |        |                    | Localizing strings with xtd::environment::culture              | .NET / Qt QTranslator                       |
| 🔴  |        |                    | LINQ-like queries with xtd::linq::enumerable                   | .NET LINQ / C++20 std::ranges               |
| 🔴  |        |                    | Handling exceptions with xtd::diagnostics::stack_trace         | C++ modern                                  |
| 🔴  |        |                    | Measuring execution time with xtd::diagnostics::stopwatch      | std::chrono                                 |
| 🔴  |        |                    | Showing notifications (balloon tips / tray icons)              | Qt QSystemTrayIcon / Win32 Shell_NotifyIcon |
| 🔴  |        |                    | Easy environment variable access with xtd::environment         | Qt qEnvironmentVariable / C getenv          |
| 🔴  |        |                    | Getting and formatting date/time easily                        | std::chrono, Qt                             |
| 🔴  |        |                    | Writing to debug output and console at once                    | std::cout / OutputDebugString               |
| 🔴  |        |                    | Using self_ to simplify code instead of raw this               | C++ modern                                  |
| 🔴  |        |                    | Displaying an open/save file dialog in one line                | Qt QFileDialog / Win32 API                  |
| 🔴  |        |                    | Drawing text and shapes in a form with xtd::drawing::graphics  | Qt painting / GDI+                          |
| 🔴  |        |                    | Using timers (interval, elapsed event)                         | std::thread + sleep, Qt Timer               |
| 🔴  |        |                    | Formatting strings with xtd::string::format                    | C++20 std::format / Qt QString::arg         |
| 🔴  |        |                    | Unit testing in one line with xtd::tunit                       | Catch2 / gtest                              |
| 🔴  | #9     | October 27, 2025   | Adding color to console output (text + background)             | ANSI escape codes                           |
| 🟡  | #8     | October 13, 2025   | array_list a heterogeneous container supporting multiple types | C++ modern / Boost / Qt                     |
| 🟡  | #7     | September 29, 2025 | Creating a simple form with a button                           | Qt / WinForms                               |
| 🟡  | #6     | September 15, 2025 | Getting special folders (desktop, app_data, etc.)              | Win32 API / Qt                              |
| 🟡  | #5     | September 1, 2025  | Applying image effects                                         | NA                                          |
| 🟡  | #4     | August 18, 2025    | Why xtd simplifies your code compared to Qt or WxWidgets       | Qt / wxWidgets                              |
| 🟢  | #3     | August 6, 2025     | Showing a message box in one line                              | Qt / wxWidgets                              |
| 🟢  | #2     | July 31, 2025      | Very simple threads synchronisation                            | C++ modern                                  |
| 🟢  | #1     | July 8, 2025       | Retrieving command-line arguments                              | C++ modern                                  |

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
