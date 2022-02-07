#include <xtd/xtd.forms.h>
#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/forms/button_renderer.h>
#include <xtd/forms/text_renderer.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms;

class owner_button : public button {
protected:
  void on_paint(xtd::forms::paint_event_args& e) override {
    button_renderer::draw_button(e.graphics(), e.clip_rectangle(), flat_style(), state(), default_button(), back_color() != default_back_color() ? std::optional<color> {back_color()} : std::nullopt, text(), std::nullopt, fore_color() != default_fore_color() ? std::optional<color> {fore_color()} : std::nullopt, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt);
    control::on_paint(e);
  }
};

class form1 : public xtd::forms::form {
public:
  form1();
  
private:
  button button1;
  button button2;
  button button3;
  button button4;
  button button5;
  button button6;
  button button7;
  button button8;
  button button9;
  button button10;
  button button11;
  button button12;
};

form1::form1() {
  text("form1 - system");
  client_size({800, 450});
  //back_color(color::dark_blue);
  //back_color(color::light_blue);
  //fore_color(color::black);
  //back_color(color::pink);
  //fore_color(color::blue);

  accept_button(button1);
  
  button1.parent(*this);
  button1.location({10, 10});
  button1.text("Button 1");
  button1.flat_style(flat_style::system);
  button1.click += [&] {
    accept_button(button1);
  };
  
  button2.parent(*this);
  button2.location({90, 10});
  button2.text("Button 2");
  button2.flat_style(flat_style::system);

  button3.parent(*this);
  button3.location({170, 10});
  button3.text("Button 3");
  button3.flat_style(flat_style::system);
  button3.enabled(false);
  
  button4.parent(*this);
  button4.location({250, 10});
  button4.text("Button 4");
  button4.click += [&] {
    accept_button(button4);
  };

  button5.parent(*this);
  button5.location({330, 10});
  button5.text("Button 5");
  button5.image(button_images::from_name("media-playback-start"));
  button5.image_align(content_alignment::middle_left);
  button5.text_align(content_alignment::middle_right);

  button6.parent(*this);
  button6.location({410, 10});
  button6.text("Button 6");
  button6.image(button_images::from_name("media-playback-start"));
  button6.image_align(content_alignment::middle_left);
  button6.text_align(content_alignment::middle_right);
  button6.enabled(false);

  button7.parent(*this);
  button7.location({10, 50});
  button7.text("Button 7");
  button7.flat_style(flat_style::flat);
  button7.click += [&] {
    accept_button(button7);
  };
  
  button8.parent(*this);
  button8.location({90, 50});
  button8.text("Button 8");
  button8.flat_style(flat_style::flat);
  
  button9.parent(*this);
  button9.location({170, 50});
  button9.text("Button 9");
  button9.flat_style(flat_style::flat);
  button9.enabled(false);
  
  button10.parent(*this);
  button10.location({250, 50});
  button10.text("Button 10");
  button10.flat_style(flat_style::popup);
  button10.click += [&] {
    accept_button(button10);
  };
  
  button11.parent(*this);
  button11.location({330, 50});
  button11.text("Button 11");
  button11.flat_style(flat_style::popup);

  button12.parent(*this);
  button12.location({410, 50});
  button12.text("Button 12");
  button12.flat_style(flat_style::popup);
  button12.enabled(false);
  
  click += [&] {
    //static auto names = application::style_sheet_names();
    static std::vector names = {"GNOME (dark)", "GNOME (light)", "KDE (dark)", "KDE (light)", "macOS (dark)", "macOS (light)", "Windows (dark)", "Windows (light)", "default"};
    static auto current = 0U;
    application::style_sheet(application::get_style_sheet_from_name(names[current]));
    text(ustring::format("form1 - {}", names[current]));
    if (++current >= names.size()) current = 0;
  };
}

int main() {
  //application::style_sheet(application::get_style_sheet_from_name("Windows (light)"));
  application::run(form1());
}

