#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Font box example");
    client_size({ 200, 160 });
    controls().push_back_range({ button_font, button_font_and_color });

    button_font.parent(*this)
      .location({ 10, 10 })
      .text("Select a font")
      .size({ 180, 45 })
      .click += [this] {
       drawing::font font = xtd::drawing::system_fonts::default_font();
        auto res = font_box::show(font, *this);
        if (res == dialog_result::ok) {
          message_box::show(ustring::format("Selected font is: {}", font));
        } 
      };

    button_font_and_color.parent(*this)
      .location({ 10, 60 })
      .text("Select a font and a font color")
      .size({ 180, 45 })
      .click += [] {
        drawing::font font("Arial", 16); 
        drawing::color color;
        auto res = font_box::show(font, color, font_box_options::show_color);
        if (res == dialog_result::ok) {
          message_box::show(ustring::format("Selected font is: {}\ncolor: {}", font, color));
        }
      };
  }
  
private:
  button button_font;
  button button_font_and_color;
};

int main() {
  application::run(form1());
}
