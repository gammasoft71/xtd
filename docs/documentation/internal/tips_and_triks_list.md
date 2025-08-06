# Tips & triks ist

| Subject                                            | Comparison with               | Published     |
|--------------------------------------------------- | ----------------------------- | ------------- |
| Retrieving command-line arguments                  | C++ standard                  | July 8, 2025  |
| Very simple threads synchronisation                | C++ standard                  | July 31, 2025 |
| Showing a message box in one line                  | Qt / wxWidgets                |               |
| Getting special folders (desktop, app_data, etc.)  | Win32 API / Qt                |               |
| Getting and formatting date/time easily            | std::chrono, Qt               |               |
| Creating a simple form with a button               | Qt / WinForms                 |               |
| Writing to debug output and console at once        | std::cout / OutputDebugString |               |
| Adding color to console output (text + background) | ANSI escape codes             |               |
| Using timers (interval, elapsed event)             | std::thread + sleep, Qt Timer |               |
| Localizing strings with xtd::environment::culture  | .NET / Qt QTranslator         |               |


# Showing a message box in one line

```cpp
#include <xtd/xtd>

auto main() -> int {
  message_box::show("Hello, world!", "my_app");
}
```

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
