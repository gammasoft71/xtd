#include <memory>
#include <xtd/system_exception.h>
#include <xtd/drawing/system_icons.h>
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
    exception_dialog_standard(const std::exception* exception) : exception_(exception) {
      auto_size(true);
      auto_size_mode(forms::auto_size_mode::grow_and_shrink);
      accept_button(button_continue_);
      cancel_button(button_quit_);
      controls().push_back_range({panel_top_, panel_bottom_});
      maximize_box(false);
      minimize_box(false);
      //form_border_style(forms::form_border_style::fixed_dialog);
      start_position(form_start_position::center_screen);
      if (application::open_forms().size() > 0)
        text(application::open_forms()[0].get().text());
      else
        text(exception_ ? strings::format("Exception {} occured", strings::class_name(*exception_)) : "Unknown exception occured");

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
      label_exception_.flat_style(xtd::forms::flat_style::system);
      label_exception_.size({455, 95});
      label_exception_.text_align(content_alignment::top_left);
      auto text_m = strings::format("Unhandled exception occured in your application. If you click\nContinue, the application will ignore this error and attempt to continue.\nIf you click Quit, the application will close immediately.\n\n{}", exception_ ? exception_->what() : "(Unknown exception)");
      label_exception_.text(text_m);

      button_details_.location({10, 115});
      button_details_.width(100);
      button_details_.text("Details");
      button_details_.click += [&] {
        panel_bottom_.visible(!panel_bottom_.visible());
      };

      //button_continue_.enabled(false);
      button_continue_.location({environment::os_version().is_macos_platform() ? 440 : 330, 115});
      button_continue_.width(100);
      button_continue_.text("Continue");
      button_continue_.dialog_result(forms::dialog_result::ok);
      
      button_quit_.location({environment::os_version().is_macos_platform() ? 330 : 440, 115});
      button_quit_.width(100);
      button_quit_.text("Quit");
      button_quit_.dialog_result(forms::dialog_result::cancel);
      
      text_box_details_.location({10, 5});
      text_box_details_.size({530, 185});
      text_box_details_.multiline(true);
      text_box_details_.read_only(true);
      text_box_details_.text(generate_report());
    }
    
    static xtd::forms::dialog_result show_dialog(const std::exception* exception) {
      exception_dialog_standard dialog(exception);
      if (application::open_forms().size() > 0) return dialog.form::show_sheet_dialog(application::open_forms()[0].get());
      return dialog.form::show_dialog();
    }
    
  private:
    std::string generate_report() const {
      std::string report = strings::format("Use try and catch to handle std::exception or xtd::system_exception instead{0}of this dialog box. For more information, see the xtd documentation.{0}{0}", environment::new_line());
      report += generate_exception_report();
      report += generate_libraries_report();
      report += generate_operating_system_report();
      report += generate_standard_cpp_report();
      report += generate_compiler_report();
      return report;
    }

    std::string generate_exception_report() const {
      std::string report = strings::format("{0} Exception text {0}{1}", std::string(14, '*'), environment::new_line());
      if (exception_ && dynamic_cast<const xtd::system_exception*>(exception_))
        report += strings::format("{}{}", static_cast<const xtd::system_exception*>(exception_)->to_string(), environment::new_line());
      else if (exception_ && dynamic_cast<const std::exception*>(exception_))
        report += strings::format("{0}: {1}{2}{3}{2}", xtd::strings::full_class_name(*exception_), static_cast<const std::exception*>(exception_)->what(), environment::new_line(), xtd::diagnostics::stack_trace(5, true));
      else
        report += strings::format("(Unknown exception){0}{1}{0}", environment::new_line(), xtd::diagnostics::stack_trace(5, true));
      report += environment::new_line();
      return report;
    }
    
    std::string generate_libraries_report() const {
      bool first = true;
      std::string report = strings::format("{0} Libraries {0}{1}", std::string(14, '*'), environment::new_line());
      for (auto library : {"xtd.core", "xtd.drawing", "xtd.forms"}) {
        if (!first) report += strings::format("{}{}", std::string(40, '-'), environment::new_line());
        report += strings::format("{}{}", library, environment::new_line());
        report += strings::format("    Name: {}.{}{}", library, environment::os_version().is_windows_platform() ? "lib" : "a", environment::new_line());
        report += strings::format("    Version: {}{}", environment::version(), environment::new_line());
        first = false;
      }
      report += environment::new_line();
      return report;
    }
    
    std::string generate_operating_system_report() const {
      static map<platform_id, string> operating_system_names {{platform_id::win32s, "Microsoft Win32S"}, {platform_id::win32_windows, "Microsoft Windows 98"}, {platform_id::win32_nt, "Microsoft Windows NT"}, {platform_id::win_ce, "Microsoft Windows CE"}, {platform_id::unix, "Unix"}, {platform_id::xbox, "Xbox"}, {platform_id::macos, "macOS"}, {platform_id::ios, "iOS"}, {platform_id::android, "Android"}, {platform_id::unknown, "<Unknown>"}};
      std::string report = strings::format("{0} Operating System {0}{1}", std::string(14, '*'), environment::new_line());
      report += strings::format("{}{}", operating_system_names[environment::os_version().platform()], environment::new_line());
      report += strings::format("    Version : {}{}", environment::os_version().version(), environment::new_line());
      report += strings::format("    Platform : {}{}", environment::os_version().platform(), environment::new_line());
      report += strings::format("    OS Version : {}{}", environment::os_version(), environment::new_line());
      report += strings::format("    Is 64 bits : {}{}", environment::is_64_bit_operating_system(), environment::new_line());
      report += environment::new_line();
      return report;
    }
    
    std::string generate_standard_cpp_report() const {
      enum class libcpp_id {unknown = -1, cpp_pre98 = 0, cpp98, cpp11, cpp14, cpp17, cpp20};
      
      class libcpp_info final static_ {
      public:
        static string name() {
          static map<libcpp_id, string> names {{libcpp_id::cpp_pre98, "Standard C++ Pre 98"}, {libcpp_id::cpp98, "Standard C++ 98"}, {libcpp_id::cpp11, "Standard C++ 11"}, {libcpp_id::cpp14, "Standard C++ 14"}, {libcpp_id::cpp17, "Standard C++ 17"}, {libcpp_id::cpp20, "Standard C++ 20"}, {libcpp_id::unknown, "<unknown>"}};
          return names[id()];
        }
        
        static const xtd::version& version() {
          static xtd::version ver(__cplusplus/100, __cplusplus%100);
          return ver;
        }
        
        static libcpp_id id() {
          uint32_t cpp = __cplusplus;
          if (cpp >= 202002L) return libcpp_id::cpp20;
          if (cpp >= 201703L) return libcpp_id::cpp17;
          if (cpp >= 201402L) return libcpp_id::cpp14;
          if (cpp >= 201103L) return libcpp_id::cpp11;
          if (cpp >= 199711L) return libcpp_id::cpp98;
          if (cpp == 1L) return libcpp_id::cpp_pre98;
          return libcpp_id::unknown;
        }
        
        static bool is_supported() {return __cplusplus >= 201703L;}
        static int32_t year() {return __cplusplus / 100;}
        static int32_t month() {return __cplusplus % 100;}
      };
      
      std::string report = strings::format("{0} Standard C++ {0}{1}", std::string(14, '*'), environment::new_line());
      report += strings::format("{}{}", libcpp_info::name(), environment::new_line());
      report += strings::format("    Version : {}{}", libcpp_info::version(), environment::new_line());
      report += strings::format("    Value : {}{}", static_cast<uint32_t>(__cplusplus), environment::new_line());
      report += strings::format("    Is supported : {}{}", libcpp_info::is_supported(), environment::new_line());
      report += environment::new_line();
      return report;
    }
    
    std::string generate_compiler_report() const {
      enum class compilator_id {unknown = -1, microsoft_visual_studio = 0, gcc = 1, clang = 2};
      enum class compilator_mode {release = 0, debug = 1};
      class compilator_info final static_ {
      public:
        static string name() {
          switch (id()) {
            case compilator_id::microsoft_visual_studio: return "Microsoft Visual Studio";
            case compilator_id::gcc: return "gcc";
            case compilator_id::clang: return "clang";
            case compilator_id::unknown: return "<Unknown>";
            default: return "<Unknown>";
          }
        }
        
#if __clang__
        static xtd::version version() {return xtd::version(__clang_major__ , __clang_minor__, __clang_patchlevel__);}
#elif __GNUC__
        static xtd::version version() {return xtd::version(__GNUC__ , __GNUC_MINOR__, __GNUC_PATCHLEVEL__);}
#elif _MSC_VER
        static xtd::version version() {return xtd::version(_MSC_VER/100, _MSC_VER%100, 0);}
#else
        static xtd::version version() {return xtd::version(0, 0, 0);}
#endif
#if __clang__
        static compilator_id id() {return compilator_id::clang;}
#elif __GNUC__
        static compilator_id id() {return compilator_id::gcc;}
#elif _MSC_VER
        static compilator_id id() {return compilator_id::microsoft_visual_studio;}
#else
        static compilator_id id() {return compilator_id::unknown;}
#endif
        
#if NDEBUG
        static compilator_mode mode() {return compilator_mode::release;}
#else
        static compilator_mode mode() {return compilator_mode::debug;}
#endif
        static bool is_debug_mode() { return mode() == compilator_mode::debug; }
      };

      std::string report = strings::format("{0} Compiler {0}{1}", std::string(14, '*'), environment::new_line());
      report += strings::format("{0}{1}", compilator_info::name(), environment::new_line());
      report += strings::format("    Version : {0}{1}", compilator_info::version(), environment::new_line());
      report += strings::format("    ID : {0}{1}", static_cast<int32_t>(compilator_info::id()), environment::new_line());
      report += strings::format("    Mode : {0}{1}", compilator_info::is_debug_mode() ? "Debug" : "Release", environment::new_line());
      report += strings::format("    Is 64 bits : {0}{1}", environment::is_64_bit_process(), environment::new_line());
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
}

xtd::forms::dialog_result exception_dialog::show_dialog() {
  return exception_dialog_standard::show_dialog(exception_);
}
