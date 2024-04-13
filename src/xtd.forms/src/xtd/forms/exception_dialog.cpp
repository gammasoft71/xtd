#include "../../../include/xtd/forms/exception_dialog.h"
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/button.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/panel.h"
#include "../../../include/xtd/forms/picture_box.h"
#include "../../../include/xtd/forms/text_box.h"
#include "../../../include/xtd/forms/toggle_button.h"
#include <xtd/drawing/system_icons>
#include <xtd/io/path>
#include <xtd/literals>
#include <xtd/system_exception>
#include <xtd/typeof>
#include <memory>

using namespace std;
using namespace xtd;
using namespace forms;

namespace {
  using link_label = label;
  class exception_dialog_standard : public form {
  public:
    exception_dialog_standard(const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) : exception_(exception) {
      panel_top_.location({0, 0});
      panel_top_.size({480, 150});
      panel_top_.controls().push_back_range({picture_box_error_, label_exception_, button_details_, button_continue_, button_quit_});
      
      panel_bottom_.location({0, 150});
      panel_bottom_.size({480, 200});
      panel_bottom_.hide();
      panel_bottom_.controls().push_back(text_box_details_);
      
      picture_box_error_.location({10, 10});
      picture_box_error_.size({64, 64});
      picture_box_error_.image(drawing::system_images::from_name("dialog-error", drawing::size(64, 64)));
      
      label_exception_.location({85, 10});
      label_exception_.size({385, 95});
      label_exception_.text_align(content_alignment::top_left);
      label_exception_.text(ustring::format("Unhandled exception occurred in your application. If you click Continue, the application will ignore this error and attempt to continue. If you click Quit, the application will close immediately.{0}{0}{1}"_t, environment::new_line(), exception_ ? exception_->what() : "(Unknown exception)"_t));
      
      button_details_.location({10, 115});
      button_details_.width(100);
      button_details_.text("Details"_t);
      button_details_.click += [&] {
        panel_bottom_.visible(!panel_bottom_.visible());
      };
      
      //button_continue_.enabled(false);
      button_continue_.location({environment::os_version().is_macos_platform() ? 370 : 260, 115});
      button_continue_.width(100);
      button_continue_.text("Continue"_t);
      button_continue_.dialog_result(forms::dialog_result::ok);
      
      button_quit_.location({environment::os_version().is_macos_platform() ? 260 : 370, 115});
      button_quit_.width(100);
      button_quit_.text("Quit"_t);
      button_quit_.dialog_result(forms::dialog_result::cancel);
      
      text_box_details_.location({10, 5});
      text_box_details_.size({460, 185});
      text_box_details_.multiline(true);
      text_box_details_.read_only(true);
      text_box_details_.word_wrap(false);
      text_box_details_.text(generate_report());

      auto_size(true);
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      accept_button(button_continue_);
      cancel_button(button_quit_);
      controls().push_back_range({panel_top_, panel_bottom_});
      maximize_box(false);
      minimize_box(false);
      show_icon(false);
      top_most(true);
      form_border_style(forms::form_border_style::fixed_dialog);
      start_position(form_start_position::center_screen);
      this->text(text);
      form_closed += [&, on_dialog_closed] {
        on_dialog_closed->invoke(dialog_closed_event_args(dialog_result()));
        delete on_dialog_closed;
      };
    }
    
    using form::show_dialog;
    static forms::dialog_result show_dialog(const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) {
      auto dialog = exception_dialog_standard {exception, text, on_dialog_closed};
      return dialog.form::show_dialog();
    }
    
    static forms::dialog_result show_dialog(const iwin32_window& owner, const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) {
      auto dialog = exception_dialog_standard {exception, text, on_dialog_closed};
      return dialog.form::show_dialog(owner);
    }
    
    using form::show_sheet;
    static void show_sheet(const iwin32_window& owner, const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) {
      auto dialog = exception_dialog_standard {exception, text, on_dialog_closed};
      dialog.form::show_sheet_dialog(owner);
    }
    
    using form::show_sheet_dialog;
    static forms::dialog_result show_sheet_dialog(const iwin32_window& owner, const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) {
      auto dialog = exception_dialog_standard {exception, text, on_dialog_closed};
      return dialog.form::show_sheet_dialog(owner);
    }
    
  private:
    ustring generate_report() const {
      auto report = ustring::format("Use try and catch to handle std::exception or xtd::system_exception instead{0}of this dialog box. For more information, see the xtd documentation.{0}{0}"_t, environment::new_line());
      report += generate_exception_report();
      report += generate_libraries_report();
      report += generate_operating_system_report();
      report += generate_compiler_report();
      report += generate_language_report();
      return report;
    }
    
    ustring generate_exception_report() const {
      auto report = ustring::format("{0} Exception text {0}{1}"_t, ustring(14, '*'), environment::new_line());
      if (exception_ && dynamic_cast<const system_exception*>(exception_))
        report += ustring::format("{}{}", static_cast<const system_exception*>(exception_)->to_string(), environment::new_line());
      else if (exception_ && dynamic_cast<const std::exception*>(exception_))
        report += ustring::format("{0}: {1}{2}", typeof_(*exception_), static_cast<const std::exception*>(exception_)->what(), environment::new_line());
      else
        report += ustring::format("(Unknown exception){0}"_t, environment::new_line());
      report += environment::new_line();
      return report;
    }
    
    ustring generate_libraries_report() const {
      auto first = true;
      auto report = ustring::format("{0} Libraries {0}{1}"_t, ustring(14, '*'), environment::new_line());
      for (auto library : {"xtd.core", "xtd.drawing", "xtd.forms"}) {
        if (!first) report += ustring::format("{}{}", ustring(40, '-'), environment::new_line());
        report += ustring::format("{}{}", library, environment::new_line());
        report += ustring::format("    Name: {}.{}{}"_t, library, environment::os_version().is_windows_platform() ? "lib" : "a", environment::new_line());
        report += ustring::format("    Version: {}{}"_t, environment::version(), environment::new_line());
        report += ustring::format("    include path: {}{}"_t, io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "include"), environment::new_line());
        report += ustring::format("    library path: {}{}"_t, io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "lib"), environment::new_line());
        report += ustring::format("    resources path: {}{}"_t, environment::get_folder_path(environment::special_folder::xtd_resources), environment::new_line());
        first = false;
      }
      report += environment::new_line();
      return report;
    }
    
    ustring generate_operating_system_report() const {
      auto report = ustring::format("{0} Operating System {0}{1}"_t, ustring(14, '*'), environment::new_line());
      report += ustring::format("{}{}", environment::os_version().name(), environment::new_line());
      report += ustring::format("    Version : {}{}"_t, environment::os_version().version(), environment::new_line());
      report += ustring::format("    Desktop environment : {}{}"_t, environment::os_version().desktop_environment(), environment::new_line());
      report += ustring::format("    OS Version : {}{}"_t, environment::os_version(), environment::new_line());
      report += ustring::format("    64 bits : {}{}"_t, environment::is_64_bit_operating_system(), environment::new_line());
      report += environment::new_line();
      return report;
    }
    
    ustring generate_language_report() const {
      auto report = ustring::format("{0} Language {0}{1}"_t, ustring(14, '*'), environment::new_line());
      report += ustring::format("{}{}", environment::cpp_version().name(), environment::new_line());
      report += ustring::format("    Version : {}{}"_t, environment::cpp_version().version(), environment::new_line());
      report += ustring::format("    Experimental : {}{}"_t, environment::cpp_version().is_experimental_language(), environment::new_line());
      report += ustring::format("    Supported : {}{}"_t, environment::cpp_version().is_supported(), environment::new_line());
      report += environment::new_line();
      return report;
    }
    
    ustring generate_compiler_report() const {
      auto report = ustring::format("{0} Compiler {0}{1}"_t, ustring(14, '*'), environment::new_line());
      report += ustring::format("{0}{1}", environment::compiler_version().name(), environment::new_line());
      report += ustring::format("    Version : {0}{1}", environment::compiler_version().version(), environment::new_line());
      report += ustring::format("    ID : {0}{1}", environment::compiler_version().compiler_id(), environment::new_line());
      report += ustring::format("    Mode : {0}{1}", environment::compiler_version().is_build_type_debug() ? "Debug"_t : "Release"_t, environment::new_line());
      report += ustring::format("    64 bits : {0}{1}", environment::compiler_version().is_64_bit(), environment::new_line());
      report += environment::new_line();
      return report;
    }
    
    const std::exception* exception_ = nullptr;
    panel panel_top_;
    panel panel_bottom_;
    picture_box picture_box_error_;
    label label_exception_;
    toggle_button button_details_;
    button button_continue_;
    button button_quit_;
    text_box text_box_details_;
  };
}

struct exception_dialog::data {
  forms::dialog_result dialog_result = forms::dialog_result::none;
  forms::dialog_appearance dialog_appearance = forms::dialog_appearance::standard;
  const std::exception* exception = nullptr;
  ustring text;
};

exception_dialog::exception_dialog() : data_(std::make_shared<data>()) {
  data_->dialog_appearance = application::system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
}

forms::dialog_result exception_dialog::dialog_result() const noexcept {
  return data_->dialog_result;
}

forms::dialog_appearance exception_dialog::dialog_appearance() const noexcept {
  return data_->dialog_appearance;
}

exception_dialog& exception_dialog::dialog_appearance(forms::dialog_appearance dialog_appearance) {
  data_->dialog_appearance = dialog_appearance;
  return *this;
}

std::reference_wrapper<const std::exception> exception_dialog::exception() const noexcept {
  return std::reference_wrapper<const std::exception>(*data_->exception);
}

exception_dialog& exception_dialog::exception(const std::exception& exception) {
  data_->exception = &exception;
  return *this;
}

ustring exception_dialog::text() const noexcept {
  return data_->text;
}

exception_dialog& exception_dialog::text(const ustring& text) {
  data_->text = text;
  return *this;
}


void exception_dialog::reset() noexcept {
  data_->dialog_appearance = application::system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
  data_->exception = nullptr;
  data_->text = "";
}

forms::dialog_result exception_dialog::show_dialog() {
  return exception_dialog_standard::show_dialog(data_->exception, data_->text, new delegate<void(const dialog_closed_event_args& e)>(*this, &exception_dialog::on_dialog_closed));
}

forms::dialog_result exception_dialog::show_dialog(const iwin32_window& owner) {
  return exception_dialog_standard::show_dialog(owner, data_->exception, data_->text, new delegate<void(const dialog_closed_event_args& e)>(*this, &exception_dialog::on_dialog_closed));
}

void exception_dialog::show_sheet(const iwin32_window& owner) {
  data_->dialog_result = forms::dialog_result::none;
  exception_dialog_standard::show_sheet(owner, data_->exception, data_->text, new delegate<void(const dialog_closed_event_args& e)>(*this, &exception_dialog::on_dialog_closed));
}

forms::dialog_result exception_dialog::show_sheet_dialog(const iwin32_window& owner) {
  return exception_dialog_standard::show_sheet_dialog(owner, data_->exception, data_->text, new delegate<void(const dialog_closed_event_args& e)>(*this, &exception_dialog::on_dialog_closed));
}

void exception_dialog::on_dialog_closed(const dialog_closed_event_args& e) {
  data_->dialog_result = e.dialog_result();
  dialog_closed(*this, e);
}
