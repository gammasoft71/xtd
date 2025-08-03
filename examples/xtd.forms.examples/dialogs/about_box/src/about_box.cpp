#include "../resources/gammasoft_64x64.xpm"
#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("About box example");
    controls().push_back(button1);
    
    button1.location({10, 10});
    button1.text("About...");
    button1.click += delegate_ {
      about_box::show("About box description.", "About box", xtd::drawing::image::from_xpm_data(gammasoft_64x64_xpm), "1.0", "1.0.0", "Copyright (c) 2024 Gammasoft.\nAll rights reserved.", "https://gammasoft71.wixsite.com/gammasoft", "Gammasoft");
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  application::run(form1 {});
}
