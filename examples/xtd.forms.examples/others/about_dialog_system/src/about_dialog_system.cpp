#include <xtd/forms/about_dialog>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include "../resources/gammasoft_64x64.xpm"

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("About dialog system example");
    controls().push_back(button1);
    
    button1.location({10, 10});
    button1.text("About...");
    button1.click += [&] {
      static about_dialog dialog;
      dialog.dialog_appearance(dialog_appearance::system);
      dialog.icon(xtd::drawing::image::from_xpm_data(gammasoft_64x64_xpm));
      dialog.name("About dialog system");
      dialog.version("1.0");
      dialog.long_version("1.0.0");
      dialog.description("About dialog description.");
      dialog.copyright("Copyright (c) 2024 Gammasoft.\nAll rights reserved.");
      dialog.website("https://gammasoft71.wixsite.com/gammasoft");
      dialog.website_label("gammasoft website");
      dialog.authors({"Gammasoft", "Contributors"});
      dialog.documenters({"Gammasoft"});
      dialog.translators({"Gammasoft", "Contributors"});
      dialog.artists({"Gammasoft"});
      dialog.license("MIT License\n"
        "\n"
        "Copyright (c) 2024 Gammasoft.\n"
        "\n"
        "Permission is hereby granted, free of charge, to any person obtaining\n"
        "a copy of this software and associated documentation files (the\n"
        "\"Software\"), to deal in the Software without restriction, including\n"
        "without limitation the rights to use, copy, modify, merge, publish,\n"
        "distribute, sublicense, and/or sell copies of the Software, and to\n"
        "permit persons to whom the Software is furnished to do so, subject\n"
        "to the following conditions:\n"
        "\n"
        "The above copyright notice and this permission notice shall be\n"
        "included in all copies or substantial portions of the Software.\n"
        "\n"
        "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF\n"
        "ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO\n"
        "THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A\n"
        "PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT\n"
        "SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR\n"
        "ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN\n"
        "ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
        "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE\n"
        "OR OTHER DEALINGS IN THE SOFTWARE.\n");
      dialog.show(*this);
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  application::run(form1 {});
}
