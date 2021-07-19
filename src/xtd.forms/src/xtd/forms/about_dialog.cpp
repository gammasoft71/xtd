#include <chrono>
#include <memory>
#include <thread>
#include <vector>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/about_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/diagnostics/process.h>
#include <xtd/drawing/system_icons.h>
#include "../../../include/xtd/forms/about_dialog.h"
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/horizontal_layout_panel.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/link_label.h"
#include "../../../include/xtd/forms/panel.h"
#include "../../../include/xtd/forms/picture_box.h"
#include "../../../include/xtd/forms/tab_control.h"
#include "../../../include/xtd/forms/tab_page.h"
#include "../../../include/xtd/forms/text_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  class credits_item_panel : public horizontal_layout_panel {
  public:
    credits_item_panel() {
      padding(5);
      controls().push_back_range({title_label_, names_label_});
      title_label_.text_align(content_alignment::top_right);
      title_label_.font({title_label_.font(), font_style::bold});
      names_label_.text_align(content_alignment::top_left);
      names_label_.auto_size(true);
      auto_size(true);
    }
    
    const string title() const {return title_;}
    credits_item_panel& title(const std::string& title) {
      if (title_ != title) {
        title_ = title;
        title_label_.text(title);
      }
      return *this;
    }
    
    const vector<string>& names() const {return names_;}
    credits_item_panel& names(const vector<string>& names) {
      if (names_ != names) {
        bool first = true;
        names_ = names;
        names_label_.text("");
        for (auto name : names_) {
          names_label_.text(strings::format("{}{}{}", names_label_.text(), first ? "" :"\n", name));
          first = false;
        }
      }
      return *this;
    }
    
  protected:
    void on_create_control() override {
      horizontal_layout_panel::on_create_control();
      control_layout_style(title_label_, {.50f, size_type::percent});
      control_layout_style(names_label_, {.50f, size_type::percent});
    }
    
  private:
    label title_label_;
    label names_label_;
    vector<string> names_;
    string title_;
  };
  
  class about_dialog_standard : public form {
  public:
    about_dialog_standard() {
      maximize_box(false);
      minimize_box(false);
      client_size({476, 300});
      maximum_size(size());
      minimum_size(size());
      //form_border_style(forms::form_border_style::fixed_dialog);
      start_position(form_start_position::center_screen);

      picture_box_icon_.height(74);
      picture_box_icon_.size_mode(picture_box_size_mode::center_image);
      picture_box_icon_.padding(5);
      picture_box_icon_.dock(dock_style::top);
      
      label_name_.text_align(content_alignment::middle_center);
      label_name_.font({label_name_.font(), label_name_.font().size() + 4, xtd::drawing::font_style::bold});
      label_name_.padding(5);
      label_name_.dock(dock_style::top);

      tab_page_about_.text("About"_t);
      
      tab_page_credits_.text("Credits"_t);
      tab_page_credits_.auto_scroll(true);

      tab_page_license_.text("License"_t);
      tab_page_license_.controls().push_back(text_box_license_);

      tab_control_about_.padding(5);
      tab_control_about_.dock(dock_style::fill);

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
      link_label_website_.padding(5);
      link_label_website_.dock(dock_style::top);

      label_copyright_.text_align(content_alignment::middle_center);
      label_copyright_.padding(5);
      label_copyright_.dock(dock_style::top);

      text_box_license_.multiline(true);
      text_box_license_.read_only(true);
      text_box_license_.word_wrap(false);
      text_box_license_.dock(dock_style::fill);
    }
    
    static void show(intptr_t hwnd, const xtd::drawing::image& icon, const std::string& name, const std::string& description, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const std::vector<std::string>& authors, const std::vector<std::string>& artists, const std::vector<std::string>& documenters, const std::vector<std::string>& translators, const std::string& license) {
      static std::unique_ptr<about_dialog_standard> about_dialog_standard;
      if (about_dialog_standard != nullptr) {
        about_dialog_standard->activate();
        return;
      }
      about_dialog_standard = std::make_unique<::about_dialog_standard>();
      auto has_credit = !(authors.empty() && documenters.empty() && translators.empty() && artists.empty());
      auto has_license = !license.empty();
      if (icon != xtd::drawing::bitmap::empty)
        about_dialog_standard->picture_box_icon_.image(xtd::drawing::bitmap(icon, {64, 64}));
      else {
        about_dialog_standard->picture_box_icon_.image(xtd::drawing::system_images::from_name("xtd-forms", xtd::drawing::size(64, 64)));
      }
      about_dialog_standard->label_name_.height(static_cast<int32_t>(30 * xtd::strings::split(name, {'\n'}).size()));
      about_dialog_standard->label_name_.text(name);
      if (has_credit || has_license) {
        about_dialog_standard->controls().push_back_range({about_dialog_standard->tab_control_about_, about_dialog_standard->label_name_, about_dialog_standard->picture_box_icon_});
        about_dialog_standard->tab_control_about_.tab_pages().push_back(about_dialog_standard->tab_page_about_);
        about_dialog_standard->tab_page_about_.controls().push_back(about_dialog_standard->panel_about_);
      } else {
        about_dialog_standard->maximum_size({0, 0});
        about_dialog_standard->minimum_size({0, 0});
        about_dialog_standard->client_size({476, 250});
        about_dialog_standard->maximum_size(about_dialog_standard->size());
        about_dialog_standard->minimum_size(about_dialog_standard->size());
        about_dialog_standard->controls().push_back_range({about_dialog_standard->panel_about_, about_dialog_standard->label_name_, about_dialog_standard->picture_box_icon_});
      }

      if (!version.empty() && !long_version.empty())
        about_dialog_standard->label_version_.text(xtd::strings::format("{} ({})", long_version, version));
      else if (!long_version.empty())
        about_dialog_standard->label_version_.text(xtd::strings::format("{}", long_version));
      else if (!version.empty())
        about_dialog_standard->label_version_.text(xtd::strings::format("({})", version));

      about_dialog_standard->label_description_.height(static_cast<int32_t>(23 * xtd::strings::split(description, {'\n'}).size()));
      about_dialog_standard->label_description_.text(xtd::strings::format("{}", description));

      about_dialog_standard->link_label_website_.height(static_cast<int32_t>(23 * xtd::strings::split(!website_label.empty() ? website_label : website, {'\n'}).size()));
      about_dialog_standard->link_label_website_.text(!website_label.empty() ? website_label : website);
      about_dialog_standard->link_label_website_.link_clicked += [&](object& sender, link_label_clicked_event_args& e) {
        e.visited(true);
        diagnostics::process::start(website);
      };

      about_dialog_standard->label_copyright_.height(static_cast<int32_t>(23 * xtd::strings::split(copyright, {'\n'}).size()));
      about_dialog_standard->label_copyright_.text(xtd::strings::format("{}", xtd::strings::replace(copyright, u8"(c)"_s, u8"\u00A9"_s)));
      
      if (has_credit) {
        about_dialog_standard->tab_control_about_.tab_pages().push_back(about_dialog_standard->tab_page_credits_);
        about_dialog_standard->tab_page_credits_.auto_scroll(true);

        if (!artists.empty()) {
          about_dialog_standard->artists_.parent(about_dialog_standard->tab_page_credits_);
          about_dialog_standard->artists_.dock(dock_style::top);
          about_dialog_standard->artists_.title("Artwork by");
          about_dialog_standard->artists_.names(artists);
        }
        
        if (!translators.empty()) {
          about_dialog_standard->translators_.parent(about_dialog_standard->tab_page_credits_);
          about_dialog_standard->translators_.dock(dock_style::top);
          about_dialog_standard->translators_.title("Translated by");
          about_dialog_standard->translators_.names(translators);
        }
        
        if (!documenters.empty()) {
          about_dialog_standard->documenters_.parent(about_dialog_standard->tab_page_credits_);
          about_dialog_standard->documenters_.dock(dock_style::top);
          about_dialog_standard->documenters_.title("Documented by");
          about_dialog_standard->documenters_.names(documenters);
        }
        
        if (!authors.empty()) {
          about_dialog_standard->authors_.parent(about_dialog_standard->tab_page_credits_);
          about_dialog_standard->authors_.dock(dock_style::top);
          about_dialog_standard->authors_.title("Created by");
          about_dialog_standard->authors_.names(authors);
        }
      }
      
      if (has_license) {
        about_dialog_standard->tab_control_about_.tab_pages().push_back(about_dialog_standard->tab_page_license_);
        about_dialog_standard->text_box_license_.text(license);
      }
      
      about_dialog_standard->visible(true);
      while (about_dialog_standard->visible()) {
        application::do_events();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
      about_dialog_standard.reset();
    }
    
  private:
    picture_box picture_box_icon_;
    label label_name_;
    tab_control tab_control_about_;
    tab_page tab_page_about_;
    panel panel_about_;
    label label_version_;
    label label_description_;
    label label_copyright_;
    link_label link_label_website_;
    tab_page tab_page_credits_;
    credits_item_panel authors_;
    credits_item_panel documenters_;
    credits_item_panel translators_;
    credits_item_panel artists_;
    tab_page tab_page_license_;
    text_box text_box_license_;
  };
}

void about_dialog::reset() {
  dialog_style_ = xtd::forms::dialog_style::standard;
  icon_ = xtd::drawing::image::empty;
  artists_.clear();
  authors_.clear();
  copyright_ = "";
  description_ = "";
  documenters_.clear();
  license_ = "";
  long_version_ = "";
  name_ = "";
  translators_.clear();
  version_ = "";
  website_ = "";
  website_label_ = "";
}

void about_dialog::show() {
  if (dialog_style_ == xtd::forms::dialog_style::system) native::about_dialog::show(0, xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)), name_, description_, version_, long_version_, copyright_, website_, website_label_, authors_.to_array(), artists_.to_array(), documenters_.to_array(), translators_.to_array(), license_);
  else about_dialog_standard::show(0, icon_, name_, description_, version_, long_version_, copyright_, website_, website_label_, authors_.to_array(), artists_.to_array(), documenters_.to_array(), translators_.to_array(), license_);
}

void about_dialog::show(const iwin32_window& owner) {
  if (dialog_style_ == xtd::forms::dialog_style::system) native::about_dialog::show(owner.handle(), xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)), name_, description_, version_, long_version_, copyright_, website_, website_label_, authors_.to_array(), artists_.to_array(), documenters_.to_array(), translators_.to_array(), license_);
  else about_dialog_standard::show(owner.handle(), icon_, name_, description_, version_, long_version_, copyright_, website_, website_label_, authors_.to_array(), artists_.to_array(), documenters_.to_array(), translators_.to_array(), license_);
}
