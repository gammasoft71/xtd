#include <xtd/forms/native/about_dialog.h>
#include <xtd/drawing/system_images.h>
#include "../../../include/xtd/forms/about_dialog.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/panel.h"
#include "../../../include/xtd/forms/picture_box.h"
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/tab_page.h"
#include "../../../include/xtd/forms/text_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace {
  using link_label = label;
  class about_dialog_geeneric : public form {
  public:
    about_dialog_geeneric() {
      maximize_box(false);
      minimize_box(false);
      form_border_style(forms::form_border_style::fixed_dialog);
      client_size({476, 300});
      start_position(form_start_position::center_screen);
      
      picture_box_logo_.parent(*this);
      picture_box_logo_.image(xtd::drawing::system_images::from_name("xtd-forms", xtd::drawing::size(32, 32)));
      picture_box_logo_.location({222, 10});
      
      label_name_.parent(*this);
      label_name_.location({0, 52});
      label_name_.text_align(content_alignment::middle_center);
      label_name_.width(client_size().width());
      
      tab_page_about_.text("About");
      
      tab_page_credit_.text("Credit");
      tab_page_credit_.auto_scroll(true);

      tab_page_license_.text("License");

      tab_control_about_.location({0, 85});
      tab_control_about_.size({client_size().width(), 215});

      panel_about_.location({0, 85});
      panel_about_.size({client_size().width(), 215});
      
      label_version_.parent(panel_about_);
      label_version_.location({0, 0});
      label_version_.text_align(content_alignment::middle_center);
      
      label_description_.parent(panel_about_);
      label_description_.location({0, 33});
      label_description_.text_align(content_alignment::middle_center);
      
      label_copyright_.parent(panel_about_);
      label_copyright_.location({0, 66});
      label_copyright_.text_align(content_alignment::middle_center);
      
      text_box_license_.parent(tab_page_license_);
      text_box_license_.multiline(true);
      text_box_license_.read_only(true);
    }
    
    bool run_dialog(intptr_t hwnd, const std::string& name, const std::string& description, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const std::vector<std::string>& creators, const std::vector<std::string>& designers, const std::vector<std::string>& doc_writers, const std::vector<std::string>& translators, const std::string& license) {
      auto has_credit = !(creators.empty() && doc_writers.empty() && translators.empty() && designers.empty());
      auto has_license = !license.empty();
      label_name_.text(name);
      if (has_credit || has_license) {
        tab_control_about_.parent(*this);
        tab_control_about_.pages().push_back(tab_page_about_);
        panel_about_.parent(tab_page_about_);
        panel_about_.location({0, 0});
        panel_about_.size(tab_page_about_.size());
      } else
        panel_about_.parent(*this);

      label_version_.width(panel_about_.client_size().width());
      if (!version.empty() && !long_version.empty())
        label_version_.text(xtd::strings::format("{} ({})", version, long_version));
      else if (!version.empty())
        label_version_.text(xtd::strings::format("{}", version));
      else if (!long_version.empty())
        label_version_.text(xtd::strings::format("({})", long_version));

      label_description_.width(panel_about_.client_size().width());
      label_description_.text(xtd::strings::format("{}", description));

      label_copyright_.height(23 * xtd::strings::split(copyright, {'\n'}).size());
      label_copyright_.width(panel_about_.size().width());
      label_copyright_.text(xtd::strings::format("{}", xtd::strings::replace(copyright, u8"(c)", u8"\u00A9")));

      if (has_credit) {
        tab_control_about_.pages().push_back(tab_page_credit_);
      }
      
      if (has_license) {
        tab_control_about_.pages().push_back(tab_page_license_);
        text_box_license_.text(license);
        text_box_license_.size(tab_page_license_.size());
      }
      
      show_dialog();
      return true;
    }
    
  private:
    picture_box picture_box_logo_;
    label label_name_;
    tab_control tab_control_about_;
    tab_page tab_page_about_;
    panel panel_about_;
    label label_version_;
    label label_description_;
    label label_copyright_;
    link_label link_label_website_;
    tab_page tab_page_credit_;
    tab_page tab_page_license_;
    text_box text_box_license_;
  };
}

void about_dialog::reset() {
  about_dialog_style_ = xtd::forms::about_dialog_style::system;
  name_ = "";
  description_ = "";
  version_ = "";
  long_version_ = "";
  copyright_ = "";
  website_ = "";
  website_label_ = "";
  creators_.clear();
  designers_.clear();
  doc_writers_.clear();
  translators_.clear();
  license_ = "";
}

bool about_dialog::run_dialog(intptr_t owner) {
  if (about_dialog_style_ == xtd::forms::about_dialog_style::system)
    return native::about_dialog::run_dialog(owner, name_, description_, version_, long_version_, copyright_, website_, website_label_, creators_.to_array(), designers_.to_array(), doc_writers_.to_array(), translators_.to_array(), license_);
  return about_dialog_geeneric().run_dialog(owner, name_, description_, version_, long_version_, copyright_, website_, website_label_, creators_.to_array(), designers_.to_array(), doc_writers_.to_array(), translators_.to_array(), license_);
}
