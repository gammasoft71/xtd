#include "../../../include/xtd/forms/about_dialog.h"
#include "../../../include/xtd/forms/xtd_about_dialog.h"
#include "../../../include/xtd/forms/properties/resources.h"
#include <xtd/environment>

using namespace xtd;
using namespace xtd::forms;

struct xtd_about_dialog::data {
  xtd::forms::about_dialog dialog;
};

xtd_about_dialog::xtd_about_dialog() : data_(std::make_shared<data>()) {
  data_->dialog.icon(properties::resources::xtd());
  data_->dialog.name("About xtd");
  data_->dialog.version(environment::version().to_string(2));
  data_->dialog.long_version(environment::version().to_string(3));
  data_->dialog.description("xtd is a framework to create console, GUI and unit tests.");
  data_->dialog.website("https://gammasoft71.github.io/xtd/");
  data_->dialog.website_label("xtd website");
  data_->dialog.copyright("Copyright (c) 2024 Gammasoft.\nAll rights reserved.");
  data_->dialog.authors({"Gammasoft", "Contributors"});
  data_->dialog.documenters({"Gammasoft"});
  data_->dialog.translators({"Gammasoft", "Contributors"});
  data_->dialog.artists({"Gammasoft"});
  data_->dialog.license("MIT License\n"
                        "\n"
                        "Copyright (c) 2024 Gammasoft.\n"
                        "\n"
                        "Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n"
                        "\n"
                        "The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n"
                        "\n"
                        "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n");
}

void xtd_about_dialog::show() {
  data_->dialog.show();
}

void xtd_about_dialog::show(const iwin32_window& owner) {
  data_->dialog.show(owner);
}
