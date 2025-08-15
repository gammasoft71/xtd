# Tips & tricks list

🟢 Published | 🟡 Ready for review | 🔴 Not started

| Sts | Number | Publish date       | Subject                                                        | Comparison with               |
| --- | ------ | ------------------ |--------------------------------------------------------------- | ----------------------------- |
| 🔴  |        |                    | Localizing strings with xtd::environment::culture              | .NET / Qt QTranslator         |
| 🔴  |        |                    | Using timers (interval, elapsed event)                         | std::thread + sleep, Qt Timer |
| 🔴  |        |                    | Writing to debug output and console at once                    | std::cout / OutputDebugString |
| 🔴  |        |                    | Getting and formatting date/time easily                        | std::chrono, Qt               |
| 🔴  | #9     | October 27, 2025   | Adding color to console output (text + background)             | ANSI escape codes             |
| 🟡  | #8     | October 13, 2025   | array_list a heterogeneous container supporting multiple types | C++ standard / Boost / Qt     |
| 🔴  | #7     | September 29, 2025 | Creating a simple form with a button                           | Qt / WinForms                 |
| 🟡  | #6     | September 15, 2025 | Getting special folders (desktop, app_data, etc.)              | Win32 API / Qt                |
| 🔴  | #5     | September 1, 2025  | Image effect                                                   | .NET / Qt QTranslator         |
| 🟡  | #4     | August 18, 2025    | Why xtd simplifies your code compared to Qt or WxWidgets       | Qt / wxWidgets                |
| 🟢  | #3     | August 6, 2025     | Showing a message box in one line                              | Qt / wxWidgets                |
| 🟢  | #2     | July 31, 2025      | Very simple threads synchronisation                            | C++ standard                  |
| 🟢  | #1     | July 8, 2025       | Retrieving command-line arguments                              | C++ standard                  |

# Getting special folders (desktop, app_data, etc.)

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto my_file = path::combine(environment::get_folder_path(environment::special_folder::desktop), "my_file.txt");
  
  file::write_all_text(my_file, "Content:\n\nA simple text file\n");
  console::write_line(file::read_all_text(my_file));
  file::remove(my_file);
}
```

# Getting and formatting date/time easily

```cpp
#include <xtd/xtd>

auto main() -> int {
  console::write_line(date_time::now().to_long_date_string());
  console::write_line(date_time::now().to_long_time_string());
  console::write_line(date_time::now().to_string("u"));
}
```

# Creating a simple form with a button

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto main_form = form::create("Hello xtd", drawing::size {300, 200});
  auto click_me = button::create(main_form, "Click me", {100, 70});
  click_me.click += [] {message_box::show("You clicked me!");};
  application::run(main_form);
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
