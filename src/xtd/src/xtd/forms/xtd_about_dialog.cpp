#include "../../../include/xtd/system_report.h"
#include "../../../include/xtd/forms/xtd_about_dialog.h"
#include <xtd/forms/properties/resources>
#include <xtd/forms/about_dialog>
#include <xtd/forms/tab_page>
#include <xtd/forms/text_box>
#include <xtd/environment>

using namespace xtd;
using namespace xtd::forms;

struct xtd_about_dialog::data {
  about_dialog dialog;
  tab_page informations_tag_page;
  text_box text_reports_text_box;
};

xtd_about_dialog::xtd_about_dialog() : data_(std::make_shared<data>()) {
  data_->informations_tag_page.text("Informations");

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
  data_->dialog.user_tab_pages().push_back(data_->informations_tag_page);
  
  data_->text_reports_text_box.dock(dock_style::fill);
  data_->text_reports_text_box.font({drawing::font_family::generic_monospace(), data_->text_reports_text_box.font().size()});
  data_->text_reports_text_box.multiline(true);
  data_->text_reports_text_box.parent(data_->informations_tag_page);
  data_->text_reports_text_box.read_only(true);
  data_->text_reports_text_box.text(system_report::to_string(system_report::reports::libraries|system_report::reports::processor|system_report::reports::operating_system|system_report::reports::compiler|system_report::reports::language|system_report::reports::locale|system_report::reports::toolkit|system_report::reports::screens));
  data_->text_reports_text_box.word_wrap(false);

}

void xtd_about_dialog::show() {
  data_->dialog.show();
}

void xtd_about_dialog::show(const iwin32_window& owner) {
  data_->dialog.show(owner);
}
