#include "../../../include/xtd/forms/about_dialog.hpp"
#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/form.hpp"
#include "../../../include/xtd/forms/horizontal_layout_panel.hpp"
#include "../../../include/xtd/forms/label.hpp"
#include "../../../include/xtd/forms/link_label.hpp"
#include "../../../include/xtd/forms/panel.hpp"
#include "../../../include/xtd/forms/picture_box.hpp"
#include "../../../include/xtd/forms/tab_control.hpp"
#include "../../../include/xtd/forms/tab_page.hpp"
#include "../../../include/xtd/forms/text_box.hpp"
#include <xtd/diagnostics/process>
#include <xtd/drawing/system_icons>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/about_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/chrono>
#include <xtd/globalization/translator>
#include <memory>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::helpers;
using namespace xtd::reflection;

namespace {
  class credits_item_panel : public horizontal_layout_panel {
  public:
    credits_item_panel() {
      padding(forms::padding {5});
      controls().add_range({title_label_, names_label_});
      title_label_.text_align(content_alignment::top_right);
      title_label_.font({title_label_.font(), font_style::bold});
      names_label_.text_align(content_alignment::top_left);
      names_label_.auto_size(true);
      auto_size(true);
    }
    
    const string title() const {return title_;}
    credits_item_panel& title(const string& title) {
      if (title_ == title) return *this;
      title_ = title;
      title_label_.text(title);
      return *this;
    }
    
    const list<string>& names() const {return names_;}
    credits_item_panel& names(const list<string>& names) {
      if (names_ == names) return *this;
      names_ = names;
      names_label_.text(names_.count() ? names_[0] : "");
      for (auto index = 1_z; index < names_.count(); ++index)
        names_label_.text(string::format("{}{}{}", names_label_.text(), environment::new_line(), names_[index]));
      height(names_label_.height());
      return *this;
    }
    
  protected:
    xtd::uptr<xtd::object> clone() const override {
      auto result = xtd::new_uptr<credits_item_panel>(*this);
      if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).chars().c_str());
      return result;
    }
    
    void on_create_control() override {
      horizontal_layout_panel::on_create_control();
      control_layout_style(title_label_, {.50f, size_type::percent});
      control_layout_style(names_label_, {.50f, size_type::percent});
    }
    
  private:
    label title_label_;
    label names_label_;
    list<string> names_;
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
      label_name_.font({label_name_.font(), label_name_.font().size() + 4, font_style::bold});
      label_name_.padding(5);
      label_name_.dock(dock_style::top);
      
      tab_page_about_.text("About"_t);
      
      tab_page_credits_.text("Credits"_t);
      tab_page_credits_.auto_scroll(true);
      
      tab_page_license_.text("License"_t);
      tab_page_license_.controls().add(text_box_license_);
      
      tab_control_about_.padding(5);
      tab_control_about_.dock(dock_style::fill);
      
      panel_about_.padding(5);
      panel_about_.controls().add_range({label_copyright_, link_label_website_, label_description_, label_version_});
      panel_about_.dock(dock_style::fill);
      
      label_version_.text_align(content_alignment::middle_center);
      label_version_.padding(5);
      label_version_.dock(dock_style::top);
      
      label_description_.text_align(content_alignment::middle_center);
      label_description_.font({label_description_.font(), label_description_.font().size() + 2, font_style::bold});
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
    void show(const iwin32_window* owner, const image& icon, const string& name, const string& description, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const array<string>& authors, const array<string>& artists, const array<string>& documenters, const array<string>& translators, const string& license, const about_dialog::user_tab_page_collection& user_pages) {
      if (visible()) {
        activate();
        return;
      }
      /// @todo Activate the following commment if about dialog must be modal on Windows.
      // if (show_modal_) start_position(form_start_position::center_parent);
      auto has_credit = !(authors.empty() && documenters.empty() && translators.empty() && artists.empty());
      auto has_license = !xtd::string::is_empty(license);
      if (icon != bitmap::empty)
        picture_box_icon_.image(bitmap {icon, {64, 64}});
      else
        picture_box_icon_.image(system_images::from_name("xtd-forms", drawing::size {64, 64}));
      label_name_.height(static_cast<int32>(30 * name.split('\n').size()));
      label_name_.text(name);
      if (has_credit || has_license || user_pages.count()) {
        controls().add_range({tab_control_about_, label_name_, picture_box_icon_});
        tab_control_about_.tab_pages().add(tab_page_about_);
        tab_page_about_.controls().add(panel_about_);
      } else {
        maximum_size({0, 0});
        minimum_size({0, 0});
        client_size({476, 250});
        maximum_size(size());
        minimum_size(size());
        controls().add_range({panel_about_, label_name_, picture_box_icon_});
      }
      
      if (!xtd::string::is_empty(version) && !xtd::string::is_empty(long_version))
        label_version_.text(string::format("{} ({})", long_version, version));
      else if (!xtd::string::is_empty(long_version))
        label_version_.text(string::format("{}", long_version));
      else if (!xtd::string::is_empty(version))
        label_version_.text(string::format("({})", version));
        
      label_description_.height(static_cast<int32>(23 * description.split('\n').size()));
      label_description_.text(string::format("{}", description));
      
      link_label_website_.height(static_cast<int32>(23 * (!xtd::string::is_empty(website_label) ? website_label : website).split('\n').size()));
      link_label_website_.text(!xtd::string::is_empty(website_label) ? website_label : website);
      link_label_website_.link_clicked += [website](object & sender, link_label_clicked_event_args & e) {
        e.visited(true);
        diagnostics::process::start(diagnostics::process_start_info {website}.use_shell_execute(true));
      };
      
      label_copyright_.height(static_cast<int32>(23 * copyright.split('\n').size()));
      label_copyright_.text(string::format("{}", string(copyright).replace(u8"(c)"_s, u8"\u00A9"_s)));
      
      if (has_credit) {
        tab_control_about_.tab_pages().add(tab_page_credits_);
        tab_page_credits_.auto_scroll(true);
        
        if (!artists.empty()) {
          artists_.parent(tab_page_credits_);
          artists_.dock(dock_style::top);
          artists_.title("Artwork by");
          artists_.names(artists);
        }
        
        if (!translators.empty()) {
          translators_.parent(tab_page_credits_);
          translators_.dock(dock_style::top);
          translators_.title("Translated by");
          translators_.names(translators);
        }
        
        if (!documenters.empty()) {
          documenters_.parent(tab_page_credits_);
          documenters_.dock(dock_style::top);
          documenters_.title("Documented by");
          documenters_.names(documenters);
        }
        
        if (!authors.empty()) {
          authors_.parent(tab_page_credits_);
          authors_.dock(dock_style::top);
          authors_.title("Created by");
          authors_.names(authors);
        }
      }
      
      if (has_license) {
        tab_control_about_.tab_pages().add(tab_page_license_);
        text_box_license_.text(license);
      }
      
      for (const auto& user_page : user_pages)
        tab_control_about_.tab_pages().add(user_page);
        
      /** @todo Activate the following commment if about dialog must be modal on Windows.
      if (show_modal_) {
        auto o = owner;
        if (!o && application::main_or_first_form().has_value()) o = &application::main_or_first_form().value().get();
        if (o) show_dialog(*o);
        else  show_dialog();
      } else*/ visible(true);
    }
    
  private:
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
  xtd::sptr<about_dialog_standard> dialog;
  forms::dialog_appearance dialog_appearance = forms::dialog_appearance::standard;
  intptr handle = 0;
  image icon;
  string name;
  string version;
  string long_version;
  string description;
  string copyright;
  string website;
  string website_label;
  author_collection authors;
  documenter_collection documenters;
  user_tab_page_collection user_tab_pages;
  translator_collection translators;
  artist_collection artists;
  string license;
};

about_dialog::about_dialog() : data_(xtd::new_sptr<data>()) {
  data_->dialog_appearance = application::system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
}

about_dialog::~about_dialog() {
  //if (data_->dialog) data_->dialog->destroy_control();
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

string about_dialog::copyright() const noexcept {
  return data_->copyright;
}

about_dialog& about_dialog::copyright(const string& copyright) {
  data_->copyright = copyright;
  return *this;
}

string about_dialog::description() const noexcept {
  return data_->description;
}

about_dialog& about_dialog::description(const string& description) {
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

forms::dialog_appearance about_dialog::dialog_appearance() const noexcept {
  return data_->dialog_appearance;
}

about_dialog& about_dialog::dialog_appearance(forms::dialog_appearance dialog_appearance) {
  data_->dialog_appearance = dialog_appearance;
  return *this;
}

drawing::icon about_dialog::icon() const noexcept {
  return drawing::icon::from_bitmap(bitmap {data_->icon});
}

about_dialog& about_dialog::icon(const drawing::icon& icon) {
  data_->icon = icon.to_bitmap();
  return *this;
}

about_dialog& about_dialog::icon(const drawing::image& image) {
  data_->icon = image;
  return *this;
}

about_dialog& about_dialog::icon(const bitmap& bitmap) {
  data_->icon = bitmap;
  return *this;
}

string about_dialog::license() const noexcept {
  return data_->license;
}

about_dialog& about_dialog::license(const string& license) {
  data_->license = license;
  return *this;
}

string about_dialog::long_version() const noexcept {
  return data_->long_version;
}

about_dialog& about_dialog::long_version(const string& long_version) {
  data_->long_version = long_version;
  return *this;
}

string about_dialog::name() const noexcept {
  return data_->name;
}

about_dialog& about_dialog::name(const string& name) {
  data_->name = name;
  return *this;
}

about_dialog::user_tab_page_collection& about_dialog::user_tab_pages() noexcept {
  return data_->user_tab_pages;
}

const about_dialog::user_tab_page_collection& about_dialog::user_tab_pages() const noexcept {
  return data_->user_tab_pages;
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

string about_dialog::version() const noexcept {
  return data_->version;
}

about_dialog& about_dialog::version(const string& version) {
  data_->version = version;
  return *this;
}

string about_dialog::website() const noexcept {
  return data_->website;
}

about_dialog& about_dialog::website(const string& website) {
  data_->website = website;
  return *this;
}

string about_dialog::website_label() const noexcept {
  return data_->website_label;
}

about_dialog& about_dialog::website_label(const string& website_label) {
  data_->website_label = website_label;
  return *this;
}

about_dialog about_dialog::from_assembly(const assembly& assembly) {
  auto result = about_dialog {};
  result.copyright(assembly.copyright());
  result.description(assembly.description());
  result.long_version(assembly.version());
  result.name(xtd::string::is_empty(assembly.title()) ? assembly.name() : assembly.title());
  return result;
}

about_dialog about_dialog::from_executing_assembly_informations() {
  return from_assembly(assembly::get_executing_assembly());
}

void about_dialog::reset() noexcept {
  data_->dialog_appearance = application::system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
  data_->icon = image::empty;
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
  if (data_->dialog_appearance == dialog_appearance::system) native::about_dialog::show(0, icon::from_bitmap(bitmap {data_->icon}), data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
  else {
    if (!data_->dialog) data_->dialog = xtd::new_sptr<about_dialog_standard>();
    data_->dialog->show(nullptr, data_->icon, data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license, data_->user_tab_pages);
  }
}

void about_dialog::show(const iwin32_window& owner) {
  if (data_->dialog_appearance == dialog_appearance::system) native::about_dialog::show(owner.handle(), icon::from_bitmap(bitmap {data_->icon}), data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license);
  else {
    if (!data_->dialog) data_->dialog = xtd::new_sptr<about_dialog_standard>();
    data_->dialog->show(&owner, data_->icon, data_->name, data_->description, data_->version, data_->long_version, data_->copyright, data_->website, data_->website_label, data_->authors.to_array(), data_->artists.to_array(), data_->documenters.to_array(), data_->translators.to_array(), data_->license, data_->user_tab_pages);
  }
}
