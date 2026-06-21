#include <xtd/xtd>

namespace console_clear_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      // Save colors so they can be restored when use finishes input.
      auto dft_fore_color = console::foreground_color();
      auto dft_back_color = console::background_color();
      
      do {
        auto new_fore_color = console_color::white;
        auto new_back_color = console_color::black;
        console::clear();

        switch (get_key_press("Select Text Color (B for Blue, R for Red, Y for Yellow): ", { 'B', 'R', 'Y' })) {
          case 'B': new_fore_color = console_color::dark_blue; break;
          case 'R': new_fore_color = console_color::dark_red; break;
          case 'Y': new_fore_color = console_color::dark_yellow; break;
        }
        
        switch (get_key_press("Select Background Color (W for White, G for Green, M for Magenta): ", { 'W', 'G', 'M' })) {
          case 'W': new_back_color = console_color::white; break;
          case 'G': new_back_color = console_color::green; break;
          case 'M': new_back_color = console_color::magenta; break;
        }
        
        console::write_line();
        console::write("Enter a message to display: ");
        string text_to_display = console::read_line();
        console::write_line();
        console::foreground_color(new_fore_color);
        console::background_color(new_back_color);
        console::write_line(text_to_display);

        // Restore the default settings and clear the screen.
        console::foreground_color(dft_fore_color);
        console::background_color(dft_back_color);
        console::write_line();
      } while (get_key_press("Display another message (Y/N): ", {'Y', 'N'}) == 'Y');
      
      console::clear();
    }
    
  private:
    [[nodiscard]] static constexpr auto get_key_press(const string& msg, const array<char32>& valid_chars) noexcept -> char32 {
      auto key = char32 {};
      console::write_line();
      do {
        console::write(msg);
        key = char32_object::to_upper(console::read_key().key_char());
        console::write_line();
      } while (!valid_chars.contains(key));
      return key;
    }
  };
}

startup_(console_clear_example::program::main);
