#include "../properties/settings.hpp"
#include <xtd/xtd>

using namespace settings_with_cmake::properties;

namespace settings_with_cmake {
  class program {
  public:
    static auto main() {
      console::output_code_page(65001);
      console::cursor_visible(false);
      console::clear();
      reload();
      while (true) {
        switch (auto key_char = char32_object::to_upper(console::read_key(true).key_char())) {
          case 'B': write_status(change_background()); break;
          case 'F': write_status(change_foreground()); break;
          case 'L': write_status(reload()); break;
          case 'R': write_status(reset()); break;
          case 'S': write_status(save()); break;
          case 'U': write_status(update_screen()); break;
          case 'Q': quit();
          default: write_status(string::format("The key '{}`, is not a valid key...", key_char)); break;
        }
      }
    }

  private:
    static auto change_background() -> string {
      console::background_color(color_selector(console::background_color(), console::foreground_color()));
      write_screen();
      return string::format("Color background is set to {}", console::background_color());
    }
    
    static auto change_foreground() -> string {
      console::foreground_color(color_selector(console::foreground_color(), console::background_color()));
      write_screen();
      return string::format("Color foreground is set to {}", console::foreground_color());
    }

    static auto color_selector(console_color current, console_color invalid) -> console_color {
      static auto colors = array {console_color::black, console_color::dark_blue, console_color::dark_green, console_color::dark_cyan, console_color::dark_red, console_color::dark_magenta, console_color::dark_yellow, console_color::gray, console_color::dark_gray, console_color::blue, console_color::green, console_color::cyan, console_color::red, console_color::magenta, console_color::yellow, console_color::white};
      auto index = colors.index_of(current) + 1;
      if (index < colors.length() && colors[index] == invalid) index += 1;
      if (index >= colors.length() && colors[0] == invalid) index = 1;
      if (index >= colors.length()) index = 0;
      current = colors[index];
      return current;
    }
    
    [[noreturn]] static auto quit() -> void {
      console::clear();
      console::cursor_visible(true);
      console::reset_color();
      environment::exit();
    }
    
    static auto reload() -> string {
      console::background_color(settings::default_settings().back_color());
      console::foreground_color(settings::default_settings().fore_color());
      console::window_width(settings::default_settings().window_width());
      console::window_height(settings::default_settings().window_height());
      console::title(settings::default_settings().text());
      write_screen();
      return "Settings is reload";
    }
    
    static auto reset() -> string {
      settings::default_settings().reset();
      reload();
      return "Settings is reset";
    }

    static auto save() -> string {
      settings::default_settings().back_color(console::background_color());
      settings::default_settings().fore_color(console::foreground_color());
      settings::default_settings().window_width(console::window_width());
      settings::default_settings().window_height(console::window_height());
      settings::default_settings().save();
      write_screen();
      return "Settings is save";
    }
    
    static auto update_screen() -> string {
      write_screen();
      return "Screen updated";
    }
    
    static auto write_at(int32 x, int32 y, const string& text) -> void {
      console::set_cursor_position(x, y);
      console::write(text);
    }

    static auto write_status(const string& text) -> void {
      auto bkg_color = console::background_color();
      auto fwd_color = console::foreground_color();
      console::background_color(console_color::gray);
      console::foreground_color(console_color::black);
      write_at(0, console::window_height() - 1, string(' ', console::window_width()));
      write_at(1, console::window_height() - 1, string::format("Select key | {}", text));
      console::background_color(bkg_color);
      console::foreground_color(fwd_color);
    }
    
    static auto write_screen() -> void {
      for (auto index = 0; index < console::window_height() - 1; ++index)
        write_at(0, index, string(' ', console::window_width()));
      auto y = 2;
      write_at(2, y++, "Select follwing keys :");
      write_at(4, y++, "• B : Change background color");
      write_at(4, y++, "• F : Change foreground color");
      write_at(4, y++, "• L : Reload settings");
      write_at(4, y++, "• R : Reset settings");
      write_at(4, y++, "• S : Save settings");
      write_at(4, y++, "• U : Update screen");
      write_at(4, y++, "• Q : Quit");
      write_status("");
    }
  };
}

startup_(settings_with_cmake::program::main);

// This code produces the following output :
//
//
//
//   Select follwing keys :
//     • B : Change background color
//     • F : Change foreground color
//     • L : Reload settings
//     • R : Reset settings
//     • S : Save settings
//     • U : Update screen
//     • Q : Quit
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// Select key |
