#include <xtd/char32_object>
#include <xtd/console>
#include <xtd/startup>

using namespace std;
using namespace xtd;

namespace console_clear_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main(const vector<ustring>& args) {
      // Save colors so they can be restored when use finishes input.
      auto dft_fore_color = console::foreground_color();
      auto dft_back_color = console::background_color();
      auto continue_flag = true;
      console::clear();
      
      do {
        auto new_fore_color = console_color::white;
        auto new_back_color = console_color::black;
        
        auto fore_color_selection = get_key_press("Select Text Color (B for Blue, R for Red, Y for Yellow): ", vector<char32_t> { 'B', 'R', 'Y' });
        switch (fore_color_selection) {
          case 'B':
          case 'b': new_fore_color = console_color::dark_blue; break;
          case 'R':
          case 'r': new_fore_color = console_color::dark_red; break;
          case 'Y':
          case 'y': new_fore_color = console_color::dark_yellow; break;
        }
        
        auto back_color_selection = get_key_press("Select Background Color (W for White, G for Green, M for Magenta): ", vector<char32_t> { 'W', 'G', 'M' });
        switch (back_color_selection) {
          case 'W':
          case 'w': new_back_color = console_color::white; break;
          case 'G':
          case 'g': new_back_color = console_color::green; break;
          case 'M':
          case 'm': new_back_color = console_color::magenta; break;
        }
        
        console::write_line();
        console::write("Enter a message to display: ");
        ustring text_to_display = console::read_line();
        console::write_line();
        console::foreground_color(new_fore_color);
        console::background_color(new_back_color);
        console::write_line(text_to_display);
        console::write_line();
        if (char32_object::to_upper(get_key_press("Display another message (Y/N): ", vector<char32_t> { 'Y', 'N' })) == 'N')
          continue_flag = false;
          
        // Restore the default settings and clear the screen.
        console::foreground_color(dft_fore_color);
        console::background_color(dft_back_color);
        console::clear();
      } while (continue_flag);
    }
    
  private:
    static char32_t get_key_press(const ustring& msg, const vector<char32_t>& valid_chars) {
      auto key_pressed = console_key_info {};
      auto valid = false;
      
      console::write_line();
      do {
        console::write(msg);
        key_pressed = console::read_key();
        console::write_line();
        if (find(valid_chars.begin(), valid_chars.end(), char32_object::to_upper(key_pressed.key_char())) != valid_chars.end())
          valid = true;
          
      } while (!valid);
      return key_pressed.key_char();
    }
  };
}

startup_(console_clear_example::program::main);
