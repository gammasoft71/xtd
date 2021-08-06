#include <memory>
#include <xtd/literals.h>
#include <xtd/system_exception.h>
#include <xtd/drawing/system_icons.h>
#include <xtd/io/path.h>
#include "../../../include/xtd/forms/exception_dialog.h"
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/button.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/panel.h"
#include "../../../include/xtd/forms/picture_box.h"
#include "../../../include/xtd/forms/text_box.h"
#include "../../../include/xtd/forms/toggle_button.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace {
  using link_label = label;
  class exception_dialog_standard : public form {
  public:
    exception_dialog_standard(const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) : exception_(exception) {
      auto_size(true);
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      accept_button(button_continue_);
      cancel_button(button_quit_);
      controls().push_back_range({panel_top_, panel_bottom_});
      maximize_box(false);
      minimize_box(false);
      //form_border_style(forms::form_border_style::fixed_dialog);
      start_position(form_start_position::center_screen);
      this->text(text);
      form_closed += [&, on_dialog_closed]{
        on_dialog_closed->invoke(dialog_closed_event_args(dialog_result()));
        delete on_dialog_closed;
      };

      panel_top_.location({0, 0});
      panel_top_.size({550, 150});
      panel_top_.controls().push_back_range({picture_box_error_, label_exception_, button_details_, button_continue_, button_quit_});

      panel_bottom_.location({0, 150});
      panel_bottom_.size({550, 200});
      panel_bottom_.hide();
      panel_bottom_.controls().push_back(text_box_details_);

      picture_box_error_.location({10, 10});
      picture_box_error_.size({64, 64});
      picture_box_error_.image(xtd::drawing::system_images::from_name("dialog-error", xtd::drawing::size(64, 64)));
      
      label_exception_.location({85, 10});
      label_exception_.size({455, 95});
      label_exception_.text_align(content_alignment::top_left);
      auto text_m = ustring::format("Unhandled exception occured in your application. If you click\nContinue, the application will ignore this error and attempt to\ncontinue. If you click Quit, the application will close immediately.\n\n{}"_t, exception_ ? exception_->what() : "(Unknown exception)"_t);
      label_exception_.text(text_m);

      button_details_.location({10, 115});
      button_details_.width(100);
      button_details_.text("Details"_t);
      button_details_.click += [&] {
        panel_bottom_.visible(!panel_bottom_.visible());
      };

      //button_continue_.enabled(false);
      button_continue_.location({environment::os_version().is_macos_platform() ? 440 : 330, 115});
      button_continue_.width(100);
      button_continue_.text("Continue"_t);
      button_continue_.dialog_result(forms::dialog_result::ok);
      
      button_quit_.location({environment::os_version().is_macos_platform() ? 330 : 440, 115});
      button_quit_.width(100);
      button_quit_.text("Quit"_t);
      button_quit_.dialog_result(forms::dialog_result::cancel);
      
      text_box_details_.location({10, 5});
      text_box_details_.size({530, 185});
      text_box_details_.multiline(true);
      text_box_details_.read_only(true);
      text_box_details_.word_wrap(false);
      text_box_details_.text(generate_report());
    }
    
    static xtd::forms::dialog_result show_dialog(const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) {
      exception_dialog_standard dialog(exception, text, on_dialog_closed);
      return dialog.form::show_dialog();
    }
    
    static xtd::forms::dialog_result show_dialog(const iwin32_window& owner, const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) {
      exception_dialog_standard dialog(exception, text, on_dialog_closed);
      return dialog.form::show_dialog(owner);
    }
    
    static void show_sheet(const iwin32_window& owner, const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) {
      exception_dialog_standard dialog(exception, text, on_dialog_closed);
      dialog.form::show_sheet_dialog(owner);
    }
    
    static xtd::forms::dialog_result show_sheet_dialog(const iwin32_window& owner, const std::exception* exception, const string& text, delegate<void(const dialog_closed_event_args& e)>* on_dialog_closed) {
      exception_dialog_standard dialog(exception, text, on_dialog_closed);
      return dialog.form::show_sheet_dialog(owner);
    }

  private:
    xtd::ustring generate_report() const {
      xtd::ustring report = ustring::format("Use try and catch to handle std::exception or xtd::system_exception instead{0}of this dialog box. For more information, see the xtd documentation.{0}{0}"_t, environment::new_line());
      report += generate_exception_report();
      report += generate_libraries_report();
      report += generate_operating_system_report();
      report += generate_compiler_report();
      report += generate_language_report();
      return report;
    }

    xtd::ustring generate_exception_report() const {
      xtd::ustring report = ustring::format("{0} Exception text {0}{1}"_t, xtd::ustring(14, '*'), environment::new_line());
      if (exception_ && dynamic_cast<const xtd::system_exception*>(exception_))
        report += ustring::format("{}{}", static_cast<const xtd::system_exception*>(exception_)->to_string(), environment::new_line());
      else if (exception_ && dynamic_cast<const std::exception*>(exception_))
        report += ustring::format("{0}: {1}{2}", xtd::ustring::full_class_name(*exception_), static_cast<const std::exception*>(exception_)->what(), environment::new_line());
      else
        report += ustring::format("(Unknown exception){0}"_t, environment::new_line());
      report += environment::new_line();
      return report;
    }
    
    xtd::ustring generate_libraries_report() const {
      bool first = true;
      xtd::ustring report = ustring::format("{0} Libraries {0}{1}"_t, xtd::ustring(14, '*'), environment::new_line());
      for (auto library : {"xtd.core", "xtd.drawing", "xtd.forms"}) {
        if (!first) report += ustring::format("{}{}", xtd::ustring(40, '-'), environment::new_line());
        report += ustring::format("{}{}", library, environment::new_line());
        report += ustring::format("    Name: {}.{}{}"_t, library, environment::os_version().is_windows_platform() ? "lib" : "a", environment::new_line());
        report += ustring::format("    Version: {}{}"_t, environment::version(), environment::new_line());
        report += ustring::format("    include path: {}{}"_t, xtd::io::path::combine(__XTD_INSTALL_PATH__, "include"), environment::new_line());
        report += ustring::format("    library path: {}{}"_t, xtd::io::path::combine(__XTD_INSTALL_PATH__, "lib"), environment::new_line());
        report += ustring::format("    resources path: {}{}"_t, xtd::io::path::combine(__XTD_RESOURCES_PATH__, "resources", "xtd"), environment::new_line());
        first = false;
      }
      report += environment::new_line();
      return report;
    }
    
    xtd::ustring generate_operating_system_report() const {
      xtd::ustring report = ustring::format("{0} Operating System {0}{1}"_t, xtd::ustring(14, '*'), environment::new_line());
      report += ustring::format("{}{}", environment::os_version().name(), environment::new_line());
      report += ustring::format("    Version : {}{}"_t, environment::os_version().version(), environment::new_line());
      report += ustring::format("    Desktop environment : {}{}"_t, environment::os_version().desktop_environment(), environment::new_line());
      report += ustring::format("    OS Version : {}{}"_t, environment::os_version(), environment::new_line());
      report += ustring::format("    64 bits : {}{}"_t, environment::is_64_bit_operating_system(), environment::new_line());
      report += environment::new_line();
      return report;
    }
    
    xtd::ustring generate_language_report() const {
      xtd::ustring report = ustring::format("{0} Language {0}{1}"_t, xtd::ustring(14, '*'), environment::new_line());
      report += ustring::format("{}{}", environment::cpp_version().name(), environment::new_line());
      report += ustring::format("    Version : {}{}"_t, environment::cpp_version().version(), environment::new_line());
      report += ustring::format("    Experimental : {}{}"_t, environment::cpp_version().is_experimental_language(), environment::new_line());
      report += ustring::format("    Supported : {}{}"_t, environment::cpp_version().is_supported(), environment::new_line());
      report += environment::new_line();
      return report;
    }
    
    xtd::ustring generate_compiler_report() const {
      xtd::ustring report = ustring::format("{0} Compiler {0}{1}"_t, xtd::ustring(14, '*'), environment::new_line());
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

void exception_dialog::reset() {
  dialog_style_ = xtd::forms::dialog_style::standard;
  exception_ = nullptr;
  text_ = "";
}

xtd::forms::dialog_result exception_dialog::show_dialog() {
  return exception_dialog_standard::show_dialog(exception_, text_, new delegate<void(const dialog_closed_event_args& e)>(*this, &exception_dialog::on_dialog_closed));
}

xtd::forms::dialog_result exception_dialog::show_dialog(const iwin32_window& owner) {
  return exception_dialog_standard::show_dialog(owner, exception_, text_, new delegate<void(const dialog_closed_event_args& e)>(*this, &exception_dialog::on_dialog_closed));
}

void exception_dialog::show_sheet(const iwin32_window& owner) {
  dialog_result_ = xtd::forms::dialog_result::none;
  exception_dialog_standard::show_sheet(owner, exception_, text_, new delegate<void(const dialog_closed_event_args& e)>(*this, &exception_dialog::on_dialog_closed));
}

xtd::forms::dialog_result exception_dialog::show_sheet_dialog(const iwin32_window& owner) {
  return exception_dialog_standard::show_sheet_dialog(owner, exception_, text_, new delegate<void(const dialog_closed_event_args& e)>(*this, &exception_dialog::on_dialog_closed));
}
