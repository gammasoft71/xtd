#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("About dialog with user pages example");
    
    user_tab_page1.back_color(color::from_name(user_tab_page1.text()));
    user_tab_page2.back_color(color::from_name(user_tab_page2.text()));
    
    user_label1.text_align(content_alignment::middle_center).font({user_label1.font(), 32}).dock(dock_style::fill).fore_color(color::black);
    user_label2.text_align(content_alignment::middle_center).font({user_label2.font(), 32}).dock(dock_style::fill).fore_color(color::black);

    dialog.icon(system_images::from_name("symbolic", "contact-new", xtd::drawing::size {64, 64}));
    dialog.name("User about dialog");
    dialog.version("1.0");
    dialog.long_version("1.0.0");
    dialog.description("About dialog with user pages.");
    dialog.copyright("Copyright (c) 2024 Gammasoft.\nAll rights reserved.");
    dialog.website("https://gammasoft71.github.io");
    dialog.website_label("gammasoft website");
    dialog.user_tab_pages().add_range({user_tab_page1, user_tab_page2});

    button1.click += delegate_ {
      dialog.show(*this);
    };
  }
  
private:
  about_dialog dialog;
  tab_page user_tab_page1 = tab_page::create("Dodger Blue");
  tab_page user_tab_page2 = tab_page::create("Spring Green");
  label user_label1 = label::create(user_tab_page1, color_translator::to_rgb(color::from_name(user_tab_page1.text())));
  label user_label2 = label::create(user_tab_page2, color_translator::to_rgb(color::from_name(user_tab_page2.text())));
  button button1 = button::create(*this, "About...", {10, 10});
};

auto main() -> int {
  application::run(form1 {});
}
