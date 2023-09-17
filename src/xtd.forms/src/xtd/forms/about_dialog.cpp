#include <memory>
#include <vector>
#include <xtd/chrono>
#include <xtd/literals.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/about_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/diagnostics/process.h>
#include <xtd/reflection/assembly.h>
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
using namespace xtd::reflection;

namespace {
  class credits_item_panel : public horizontal_layout_panel {
  public:
    credits_item_panel() {
      padding(forms::padding {5});
      controls().push_back_range({title_label_, names_label_});
      title_label_.text_align(content_alignment::top_right);
      title_label_.font({title_label_.font(), font_style::bold});
      names_label_.text_align(content_alignment::top_left);
      names_label_.auto_size(true);
      auto_size(true);
    }
    
    const string title() const {return title_;}
    credits_item_panel& title(const xtd::ustring& title) {
      if (title_ == title) return *this;
      title_ = title;
      title_label_.text(title);
      return *this;
    }
    
    const vector<ustring>& names() const {return names_;}
    credits_item_panel& names(const vector<ustring>& names) {
      if (names_ == names) return *this;
      names_ = names;
      names_label_.text(names_.size() ? names_[0] : "");
      for (auto index  = 1_sz; index < names_.size(); ++index)
        names_label_.text(ustring::format("{}{}{}", names_label_.text(), environment::new_line(), names_[index]));
      height(names_label_.height());
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
    vector<ustring> names_;
    string title_;
  };
  
  class about_dialog_standard : public form {
  public:
    about_dialog_standard() {
      maximize_box(false);
      minimize_box(false);
      show_icon(false);
      show_in_taskbar(false);
      client_size({476, 300});
      form_border_style(forms::form_border_style::fixed_dialog);
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
      text_box_license_.word_wrap(true);
      text_box_license_.dock(dock_style::fill);
    }
    
    using form::show;
    static form* show(const iwin32_window* owner, const xtd::drawing::image& icon, const xtd::ustring& name, const xtd::ustring& description, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const std::vector<ustring>& authors, const std::vector<ustring>& artists, const std::vector<ustring>& documenters, const std::vector<ustring>& translators, const xtd::ustring& license) {
      if (about_dialog_ && about_dialog_->visible()) {
        about_dialog_->activate();
        return about_dialog_.get();
      }
      about_dialog_ = std::make_unique<about_dialog_standard>();
      /// @todo Activate the following commment if about dialog must be modal on Windows.
      // if (about_dialog_->show_modal_) about_dialog_->start_position(form_start_position::center_parent);
      auto has_credit = !(authors.empty() && documenters.empty() && translators.empty() && artists.empty());
      auto has_license = !license.empty();
      if (icon != xtd::drawing::bitmap::empty)
        about_dialog_->picture_box_icon_.image(xtd::drawing::bitmap(icon, {64, 64}));
      else
        about_dialog_->picture_box_icon_.image(xtd::drawing::system_images::from_name("xtd-forms", xtd::drawing::size(64, 64)));
      about_dialog_->label_name_.height(static_cast<int32>(30 * name.split({'\n'}).size()));
      about_dialog_->label_name_.text(name);
      if (has_credit || has_license) {
        about_dialog_->controls().push_back_range({about_dialog_->tab_control_about_, about_dialog_->label_name_, about_dialog_->picture_box_icon_});
        about_dialog_->tab_control_about_.tab_pages().push_back(about_dialog_->tab_page_about_);
        about_dialog_->tab_page_about_.controls().push_back(about_dialog_->panel_about_);
      } else {
        about_dialog_->maximum_size({0, 0});
        about_dialog_->minimum_size({0, 0});
        about_dialog_->client_size({476, 250});
        about_dialog_->maximum_size(about_dialog_->size());
        about_dialog_->minimum_size(about_dialog_->size());
        about_dialog_->controls().push_back_range({about_dialog_->panel_about_, about_dialog_->label_name_, about_dialog_->picture_box_icon_});
      }
      
      if (!version.empty() && !long_version.empty())
        about_dialog_->label_version_.text(xtd::ustring::format("{} ({})", long_version, version));
      else if (!long_version.empty())
        about_dialog_->label_version_.text(xtd::ustring::format("{}", long_version));
      else if (!version.empty())
        about_dialog_->label_version_.text(xtd::ustring::format("({})", version));
        
      about_dialog_->label_description_.height(static_cast<int32>(23 * description.split({'\n'}).size()));
      about_dialog_->label_description_.text(xtd::ustring::format("{}", description));
      
      about_dialog_->link_label_website_.height(static_cast<int32>(23 * (!website_label.empty() ? website_label : website).split({'\n'}).size()));
      about_dialog_->link_label_website_.text(!website_label.empty() ? website_label : website);
      about_dialog_->link_label_website_.link_clicked += [website](object & sender, link_label_clicked_event_args & e) {
        e.visited(true);
        diagnostics::process::start(website);
      };
      
      about_dialog_->label_copyright_.height(static_cast<int32>(23 * copyright.split({'\n'}).size()));
      about_dialog_->label_copyright_.text(xtd::ustring::format("{}", ustring(copyright).replace(u8"(c)"_s, u8"\u00A9"_s)));
      
      if (has_credit) {
        about_dialog_->tab_control_about_.tab_pages().push_back(about_dialog_->tab_page_credits_);
        about_dialog_->tab_page_credits_.auto_scroll(true);
        
        if (!artists.empty()) {
          about_dialog_->artists_.parent(about_dialog_->tab_page_credits_);
          about_dialog_->artists_.dock(dock_style::top);
          about_dialog_->artists_.title("Artwork by");
          about_dialog_->artists_.names(artists);
        }
        
        if (!translators.empty()) {
          about_dialog_->translators_.parent(about_dialog_->tab_page_credits_);
          about_dialog_->translators_.dock(dock_style::top);
          about_dialog_->translators_.title("Translated by");
          about_dialog_->translators_.names(translators);
        }
        
        if (!documenters.empty()) {
          about_dialog_->documenters_.parent(about_dialog_->tab_page_credits_);
          about_dialog_->documenters_.dock(dock_style::top);
          about_dialog_->documenters_.title("Documented by");
          about_dialog_->documenters_.names(documenters);
        }
        
        if (!authors.empty()) {
          about_dialog_->authors_.parent(about_dialog_->tab_page_credits_);
          about_dialog_->authors_.dock(dock_style::top);
          about_dialog_->authors_.title("Created by");
          about_dialog_->authors_.names(authors);
        }
      }
      
      if (has_license) {
        about_dialog_->tab_control_about_.tab_pages().push_back(about_dialog_->tab_page_license_);
        about_dialog_->text_box_license_.text(license);
      }
      
      /** @todo Activate the following commment if about dialog must be modal on Windows.
      if (show_modal_) {
        auto o = owner;
        if (!o && application::open_forms().size()) o = &application::open_forms()[0].get();
        if (o) about_dialog_->show_dialog(*o);
        else  about_dialog_->show_dialog();
      } else*/ about_dialog_->visible(true);
      return about_dialog_.get();
    }
    
  private:
    inline static std::unique_ptr<about_dialog_standard> about_dialog_;
    /// @todo Activate the following commment if about dialog must be modal on Windows.
    //inline static bool show_modal_ = environment::os_version().is_windows();
    picture_box picture_box_icon_;
    label label_name_;
    panel panel_about_;
    label label_version_;
    label label_description_;
    label label_copyright_;
    link_label link_label_website_;
    credits_item_panel authors_;
    credits_item_panel documenters_;
    credits_item_panel translators_;
    credits_item_panel artists_;
    tab_page tab_page_about_;
    tab_page tab_page_credits_;
    tab_page tab_page_license_;
    text_box text_box_license_;
    tab_control tab_control_about_;
  };
}

struct about_dialog::data {
  xtd::forms::dialog_appearance dialog_appearance = xtd::forms::dialog_appearance::standard;
  xtd::drawing::image icon;
  xtd::ustring name;
  xtd::ustring version;
  xtd::ustring long_version;
  xtd::ustring description;
  xtd::ustring copyright;
  xtd::ustring website;
  xtd::ustring website_label;
  author_collection authors;
  documenter_collection documenters;
  translator_collection translators;
  artist_collection artists;
  xtd::ustring license;
  xtd::forms::form* dialog = nullptr;
};

about_dialog::about_dialog() : data_(std::make_shared<data>()) {
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
}

about_dialog::~about_dialog() {
  if (data_->dialog) data_->dialog->destroy_control();
}

const about_dialog::artist_collection& about_dialog::artists() const noexcept {
  return data_->artists;
}

about_dialog::artist_collection& about_dialog::artists() noexcept {
  return data_->artists;
}

about_dialog& about_dialog::artists(const artist_collection& artists) {
  data_->artists = artists;
  return *this;
}

const about_dialog::author_collection& about_dialog::authors() const noexcept {
  return data_->authors;
}

about_dialog::author_collection& about_dialog::authors() noexcept {
  return data_->authors;
}

about_dialog& about_dialog::authors(const author_collection& authors) {
  data_->authors = authors;
  return *this;
}

xtd::ustring about_dialog::copyright() const noexcept {
  return data_->copyright;
}

about_dialog& about_dialog::copyright(const xtd::ustring& copyright) {
  data_->copyright = copyright;
  return *this;
}

xtd::ustring about_dialog::description() const noexcept {
  return data_->description;
}

about_dialog& about_dialog::description(const xtd::ustring& description) {
  data_->description = description;
  return *this;
}

const about_dialog::documenter_collection& about_dialog::documenters() const noexcept {
  return data_->documenters;
}

about_dialog::documenter_collection& about_dialog::documenters() noexcept {
  return data_->documenters;
}

about_dialog& about_dialog::documenters(const documenter_collection& documenters) {
  data_->documenters = documenters;
  return *this;
}

xtd::forms::dialog_appearance about_dialog::dialog_appearance() const noexcept {
  return data_->dialog_appearance;
}

about_dialog& about_dialog::dialog_appearance(xtd::forms::dialog_appearance dialog_appearance) {
  data_->dialog_appearance = dialog_appearance;
  return *this;
}

xtd::drawing::icon about_dialog::icon() const noexcept {
  return xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon));
}

about_dialog& about_dialog::icon(const xtd::drawing::icon& icon) {
  data_->icon = icon.to_bitmap();
  return *this;
}

about_dialog& about_dialog::icon(const xtd::drawing::image& image) {
  data_->icon = image;
  return *this;
}

about_dialog& about_dialog::icon(const xtd::drawing::bitmap& bitmap) {
  data_->icon = bitmap;
  return *this;
}

xtd::ustring about_dialog::license() const noexcept {
  return data_->license;
}

about_dialog& about_dialog::license(const xtd::ustring& license) {
  data_->license = license;
  return *this;
}

xtd::ustring about_dialog::long_version() const noexcept {
  return data_->long_version;
}

about_dialog& about_dialog::long_version(const xtd::ustring& long_version) {
  data_->long_version = long_version;
  return *this;
}

xtd::ustring about_dialog::name() const noexcept {
  return data_->name;
}

about_dialog& about_dialog::name(const xtd::ustring& name) {
  data_->name = name;
  return *this;
}

const about_dialog::translator_collection& about_dialog::translators() const noexcept {
  return data_->translators;
}

about_dialog::translator_collection& about_dialog::translators() noexcept {
  return data_->translators;
}

about_dialog& about_dialog::translators(const translator_collection& translators) {
  data_->translators = translators;
  return *this;
}

xtd::ustring about_dialog::version() const noexcept {
  return data_->version;
}

about_dialog& about_dialog::version(const xtd::ustring& version) {
  data_->version = version;
  return *this;
}

xtd::ustring about_dialog::website() const noexcept {
  return data_->website;
}

about_dialog& about_dialog::website(const xtd::ustring& website) {
  data_->website = website;
  return *this;
}

xtd::ustring about_dialog::website_label() const noexcept {
  return data_->website_label;
}

about_dialog& about_dialog::website_label(const xtd::ustring& website_label) {
  data_->website_label = website_label;
  return *this;
}

about_dialog about_dialog::from_executing_assembly_informations() {
  about_dialog result;
  assembly assembly = xtd::reflection::assembly::get_executing_assembly();
  result.copyright(assembly.copyright());
  result.description(assembly.description());
  result.long_version(assembly.version());
  result.name(assembly.title().empty() ? assembly.name() : assembly.title());
  return result;
}

void about_dialog::reset() noexcept {
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
  data_->icon = xtd::drawing::image::empty;
  data_->artists.clear();
  data_->authors.clear();
  data_->copyright = "";
  data_->description = "";
  data_->documenters.clear();
  data_->license = "";
  data_->long_version = "";
  data_->name = "";
  data_->translators.clear();
  data_->version = "";
  data_->website = "";
  data_->website_label = "";
}

void about_dialog::show() {
  if (data_->dialog_appearance == xtd::forms::dialog_appearance::system) native::about_dialog::show(0, xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
  else data_->dialog = about_dialog_standard::show(nullptr, data_->icon, data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
}

void about_dialog::show(const iwin32_window& owner) {
  if (data_->dialog_appearance == xtd::forms::dialog_appearance::system) native::about_dialog::show(owner.handle(), xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
  else data_->dialog = about_dialog_standard::show(&owner, data_->icon, data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
}
