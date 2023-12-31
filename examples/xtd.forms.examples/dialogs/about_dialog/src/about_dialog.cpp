#include <xtd/forms/about_dialog>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include "../resources/gammasoft_64x64.xpm"

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("About dialog example");
    controls().push_back(button1);
    
    button1.location({10, 10});
    button1.text("About...");
    button1.click += [&] {
      static auto dialog = about_dialog {};
      dialog.icon(xtd::drawing::bitmap {gammasoft_64x64_xpm});
      dialog.name("About dialog");
      dialog.version("1.0");
      dialog.long_version("1.0.0");
      dialog.description("About dialog description.");
      dialog.website("https://gammasoft71.wixsite.com/gammasoft");
      dialog.website_label("gammasoft website");
      dialog.copyright("Copyright (c) 2024 Gammasoft.\nAll rights reserved.");
      dialog.authors({"Gammasoft", "Contributors"});
      dialog.documenters({"Gammasoft"});
      dialog.translators({"Gammasoft", "Contributors"});
      dialog.artists({"Gammasoft"});
      dialog.license("MIT License\n"
        "\n"
        "Copyright (c) 2024 Gammasoft.\n"
        "\n"
        "Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n"
        "\n"
        "The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n"
        "\n"
        "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n");
      dialog.show();
    };
  }
  
private:
  button button1;
};

auto main()->int {
  application::run(form1 {});
}
