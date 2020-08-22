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
      
      picture_box_logo_.image(xtd::drawing::system_images::from_name("xtd-forms", xtd::drawing::size(64, 64)));
      picture_box_logo_.height(74);
      picture_box_logo_.size_mode(picture_box_size_mode::center_image);
      picture_box_logo_.padding(5);
      picture_box_logo_.dock(dock_style::top);
      
      label_name_.text_align(content_alignment::middle_center);
      label_name_.font({label_name_.font(), label_name_.font().size() + 4, xtd::drawing::font_style::bold});
      label_name_.padding(5);
      label_name_.dock(dock_style::top);

      tab_page_about_.text("About");
      
      tab_page_credit_.text("Credit");
      tab_page_credit_.auto_scroll(true);

      tab_page_license_.text("License");
      tab_page_license_.controls().push_back(text_box_license_);

      tab_control_about_.location({5, 75});
      tab_control_about_.padding(5);
      tab_control_about_.dock(dock_style::fill);

      panel_about_.location({0, 75});
      panel_about_.padding(5);
      panel_about_.controls().push_back_range({label_copyright_, link_label_website_, label_description_, label_version_});
      panel_about_.dock(dock_style::fill);
      
      label_version_.text_align(content_alignment::middle_center);
      label_version_.padding(5);
      label_version_.dock(dock_style::top);
      
      label_description_.text_align(content_alignment::middle_center);
      label_description_.font({label_description_.font(), label_description_.font().size() + 2, xtd::drawing::font_style::bold});
      label_description_.padding(5);
      label_description_.dock(dock_style::top);

      link_label_website_.text_align(content_alignment::middle_center);
      link_label_website_.fore_color(xtd::drawing::color::blue);
      link_label_website_.font({link_label_website_.font(), xtd::drawing::font_style::underline});
      link_label_website_.cursor(forms::cursors::hand());
      link_label_website_.padding(5);
      link_label_website_.dock(dock_style::top);

      label_copyright_.location({0, 109});
      label_copyright_.text_align(content_alignment::middle_center);
      label_copyright_.padding(5);
      label_copyright_.dock(dock_style::top);

      text_box_license_.parent(tab_page_license_);
      text_box_license_.multiline(true);
      text_box_license_.read_only(true);
      text_box_license_.dock(dock_style::fill);
    }
    
    bool run_dialog(intptr_t hwnd, const std::string& name, const std::string& description, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const std::vector<std::string>& creators, const std::vector<std::string>& designers, const std::vector<std::string>& doc_writers, const std::vector<std::string>& translators, const std::string& license) {
      auto has_credit = !(creators.empty() && doc_writers.empty() && translators.empty() && designers.empty());
      auto has_license = !license.empty();
      label_name_.height(23 * xtd::strings::split(name, {'\n'}).size());
      label_name_.text(name);
      if (has_credit || has_license) {
        tab_control_about_.pages().push_back(tab_page_about_);
        tab_page_about_.controls().push_back(panel_about_);
        controls().push_back_range({tab_control_about_, label_name_, picture_box_logo_});
      } else {
        controls().push_back_range({panel_about_, label_name_, picture_box_logo_});
      }


      if (!version.empty() && !long_version.empty())
        label_version_.text(xtd::strings::format("{} ({})", version, long_version));
      else if (!version.empty())
        label_version_.text(xtd::strings::format("{}", version));
      else if (!long_version.empty())
        label_version_.text(xtd::strings::format("({})", long_version));

      label_description_.height(23 * xtd::strings::split(description, {'\n'}).size());
      label_description_.text(xtd::strings::format("{}", description));

      link_label_website_.height(23 * xtd::strings::split(!website_label.empty() ? website_label : website, {'\n'}).size());
      link_label_website_.text(!website_label.empty() ? website_label : website);
      
      label_copyright_.height(23 * xtd::strings::split(copyright, {'\n'}).size());
      label_copyright_.text(xtd::strings::format("{}", xtd::strings::replace(copyright, u8"(c)", u8"\u00A9")));
      
      if (has_credit) {
        tab_control_about_.pages().push_back(tab_page_credit_);
      }
      
      if (has_license) {
        tab_control_about_.pages().push_back(tab_page_license_);
        text_box_license_.text(license);
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
