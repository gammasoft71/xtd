#include "../../include/xtd/system_report.h"
#include <xtd/environment.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/system_fonts.h>
#include <xtd/io/path.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

namespace {
  static constexpr int32_t default_size_indent = 3;
  
  string indent_string(int32_t indent, int32_t size_indent) {
    return std::string(indent * size_indent, ' ');
  }
  
  string indent_string(int32_t indent) {
    return indent_string(indent, default_size_indent);
  }
    
  string generate_stack_trace_string_report(int32_t indent) {
    std::string report = strings::format("{}Stack trace{}", indent_string(indent), environment::new_line());
    auto stack_trace = system_report::stack_trace();
    for (auto frame : stack_trace.frames())
      report += strings::format("{}{}{}", indent_string(indent +1), frame, environment::new_line());
    return report + environment::new_line();
  }

  string generate_libraries_string_report(int32_t indent) {
    std::string report = strings::format("{}xtd libraries{}", indent_string(indent), environment::new_line());
    for (auto library : system_report::xtd_libraries()) {
      report += strings::format("{}{}{}", indent_string(indent + 1), library.name(), environment::new_line());
      report += strings::format("{}Version: {}{}", indent_string(indent + 2), library.version(), environment::new_line());
      report += strings::format("{}include path: {}{}", indent_string(indent + 2), library.include_path(), environment::new_line());
      report += strings::format("{}library path: {}{}", indent_string(indent + 2), library.library_path(), environment::new_line());
      report += strings::format("{}resources path: {}{}", indent_string(indent + 2), library.resources_path(), environment::new_line());
    }
    return report + environment::new_line();
  }
  
  string generate_processor_string_report(int32_t indent) {
    std::string report = strings::format("{}Processor{}", indent_string(indent), environment::new_line());
    auto processor = system_report::processor();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), processor.name(), environment::new_line());
    report += strings::format("{}Architecture: {}{}", indent_string(indent + 1), processor.architecture_string(), environment::new_line());
    report += strings::format("{}Core count: {}{}", indent_string(indent + 1), processor.core_count(), environment::new_line());
    report += strings::format("{}64 bit: {}{}", indent_string(indent + 1), processor.is_64_bit(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_operating_system_string_report(int32_t indent) {
    std::string report = strings::format("{}Operating System{}", indent_string(indent), environment::new_line());
    auto operating_system = system_report::operating_system();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), operating_system.name(), environment::new_line());
    report += strings::format("{}Version: {}{}", indent_string(indent + 1), operating_system.version(), environment::new_line());
    report += strings::format("{}Service pack: {}{}", indent_string(indent + 1), operating_system.service_pack(), environment::new_line());
    report += strings::format("{}Desktop environment: {}{}", indent_string(indent + 1), operating_system.desktop_environment(), environment::new_line());
    report += strings::format("{}64 bit: {}{}", indent_string(indent + 1), operating_system.is_64_bit(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_compiler_string_report(int32_t indent) {
    std::string report = strings::format("{}Compiler{}", indent_string(indent), environment::new_line());
    auto compiler = system_report::compiler();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), compiler.name(), environment::new_line());
    report += strings::format("{}Version: {}{}", indent_string(indent + 1), compiler.version(), environment::new_line());
    report += strings::format("{}Mode: {}{}", indent_string(indent + 1), compiler.is_build_type_debug() ? "Debug" : "Release", environment::new_line());
    report += strings::format("{}64 bit: {}{}", indent_string(indent + 1), compiler.is_64_bit(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_language_string_report(int32_t indent) {
    std::string report = strings::format("{}Language{}", indent_string(indent), environment::new_line());
    auto language = system_report::language();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), language.name(), environment::new_line());
    report += strings::format("{}Version: {}{}", indent_string(indent + 1), language.version(), environment::new_line());
    report += strings::format("{}Experimental: {}{}", indent_string(indent + 1), language.is_experimental_language(), environment::new_line());
    report += strings::format("{}Supported: {}{}", indent_string(indent + 1), language.is_supported(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_locale_string_report(int32_t indent) {
    std::string report = strings::format("{}Locale{}", indent_string(indent), environment::new_line());
    auto locale = system_report::locale();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), locale.name(), environment::new_line());
    return report + environment::new_line();
  }

  string generate_environment_variables_string_report(int32_t indent) {
    std::string report = strings::format("{}Environment variables{}", indent_string(indent), environment::new_line());
    for (auto environment_variable : system_report::environment_variables())
      report += strings::format("{}{}={}{}", indent_string(indent + 1), environment_variable.first, environment_variable.second, environment::new_line());
    return report + environment::new_line();
  }

  string generate_special_folders_string_report(int32_t indent) {
    std::string report = strings::format("{}Special folders{}", indent_string(indent), environment::new_line());
    for (auto special_folder : system_report::special_folders())
      report += strings::format("{}{}: {}{}", indent_string(indent + 1), special_folder.first, special_folder.second, environment::new_line());
    return report + environment::new_line();
  }

  string generate_system_colors_string_report(int32_t indent) {
    std::string report = strings::format("{}System colors{}", indent_string(indent), environment::new_line());
    for (auto system_color : system_report::system_colors())
      report += strings::format("{}{}: {}{}", indent_string(indent + 1), system_color.first, system_color.second, environment::new_line());
    return report + environment::new_line();
  }

  string generate_generic_font_families_string_report(int32_t indent) {
    std::string report = strings::format("{}Generic font families{}", indent_string(indent), environment::new_line());
    for (auto font_family : system_report::generic_font_families())
      report += strings::format("{}{}: {}{}", indent_string(indent + 1), font_family.first, font_family.second, environment::new_line());
    return report + environment::new_line();
  }

  string generate_system_fonts_string_report(int32_t indent) {
    std::string report = strings::format("{}System fonts{}", indent_string(indent), environment::new_line());
    for (auto system_font : system_report::system_fonts())
      report += strings::format("{}{}: {}{}", indent_string(indent + 1), system_font.first, system_font.second, environment::new_line());
    return report + environment::new_line();
  }

  string generate_screens_report(int32_t indent) {
    std::string report = strings::format("{}Screens{}", indent_string(indent), environment::new_line());
    for (auto screen : system_report::screens()) {
      report += strings::format("{}{}{}", indent_string(indent + 1), screen.device_name(), environment::new_line());
      report += strings::format("{}Bounds: {}{}", indent_string(indent + 2), screen.bounds(), environment::new_line());
      report += strings::format("{}Working area: {}{}", indent_string(indent + 2), screen.working_area(), environment::new_line());
      report += strings::format("{}Bits per pixel: {}{}", indent_string(indent + 2), screen.bits_per_pixel(), environment::new_line());
      report += strings::format("{}Primary screen: {}{}", indent_string(indent + 2), screen.primary(), environment::new_line());
    }
    return report + environment::new_line();
  }

  string generate_system_informations_string_report(int32_t indent) {
    std::string report = strings::format("{}System informations{}", indent_string(indent), environment::new_line());
    for (auto system_information : system_report::system_informations())
      report += strings::format("{}{}: {}{}", indent_string(indent + 1), system_information.first, system_information.second, environment::new_line());
    return report + environment::new_line();
  }
}

xtd::system_report::xtd_library_collection system_report::xtd_libraries() noexcept {
  return {{"xtd.core", environment::version(), xtd::io::path::combine(__XTD_INSTALL_PATH__, "include"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "lib"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "share", "xtd", "resources")}, {"xtd.drawing", environment::version(), xtd::io::path::combine(__XTD_INSTALL_PATH__, "include"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "lib"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "share", "xtd", "resources")}, {"xtd.forms", environment::version(), xtd::io::path::combine(__XTD_INSTALL_PATH__, "include"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "lib"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "share", "xtd", "resources")}, {"xtd.tunit", environment::version(), xtd::io::path::combine(__XTD_INSTALL_PATH__, "include"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "lib"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "share", "xtd", "resources")},};
}

system_report::environment_variable_collection system_report::environment_variables() noexcept {
  environment_variable_collection environment_variables;
  for (auto environment_variable : xtd::environment::get_environment_variables())
    environment_variables.push_back(environment_variable);
  return environment_variables;
}

system_report::special_folder_collection system_report::special_folders() noexcept {
  return {{"Desktop", environment::get_folder_path(environment::special_folder::desktop)}, {"Programs", environment::get_folder_path(environment::special_folder::programs)}, {"My documents", environment::get_folder_path(environment::special_folder::my_documents)}, {"Personal", environment::get_folder_path(environment::special_folder::personal)}, {"Favorites", environment::get_folder_path(environment::special_folder::favorites)}, {"Startup", environment::get_folder_path(environment::special_folder::startup)}, {"Recent", environment::get_folder_path(environment::special_folder::recent)}, {"Send to", environment::get_folder_path(environment::special_folder::send_to)}, {"Start menu", environment::get_folder_path(environment::special_folder::start_menu)}, {"My music", environment::get_folder_path(environment::special_folder::my_music)}, {"My videos", environment::get_folder_path(environment::special_folder::my_videos)}, {"Desktop directory", environment::get_folder_path(environment::special_folder::desktop_directory)}, {"My computer", environment::get_folder_path(environment::special_folder::my_computer)}, {"Network shortcuts", environment::get_folder_path(environment::special_folder::network_shortcuts)}, {"Fonts", environment::get_folder_path(environment::special_folder::fonts)}, {"Templates", environment::get_folder_path(environment::special_folder::templates)}, {"Common start menu", environment::get_folder_path(environment::special_folder::common_start_menu)}, {"Common programs", environment::get_folder_path(environment::special_folder::common_programs)}, {"Common startup", environment::get_folder_path(environment::special_folder::common_startup)}, {"Common desktop directory", environment::get_folder_path(environment::special_folder::common_desktop_directory)}, {"Application data", environment::get_folder_path(environment::special_folder::application_data)}, {"Printer shortcuts", environment::get_folder_path(environment::special_folder::printer_shortcuts)}, {"Local application data", environment::get_folder_path(environment::special_folder::local_application_data)}, {"Internet cache", environment::get_folder_path(environment::special_folder::internet_cache)}, {"Cookies", environment::get_folder_path(environment::special_folder::cookies)}, {"History", environment::get_folder_path(environment::special_folder::history)}, {"Common application data", environment::get_folder_path(environment::special_folder::common_application_data)}, {"Windows", environment::get_folder_path(environment::special_folder::windows)}, {"System", environment::get_folder_path(environment::special_folder::system)}, {"Program files", environment::get_folder_path(environment::special_folder::program_files)}, {"My pictures", environment::get_folder_path(environment::special_folder::my_pictures)}, {"User profile", environment::get_folder_path(environment::special_folder::user_profile)}, {"System x86", environment::get_folder_path(environment::special_folder::system_x86)}, {"Program files x86", environment::get_folder_path(environment::special_folder::program_files_x86)}, {"Common program files", environment::get_folder_path(environment::special_folder::common_program_files)}, {"Common program files x86", environment::get_folder_path(environment::special_folder::common_program_files_x86)}, {"Common templates", environment::get_folder_path(environment::special_folder::common_templates)}, {"Common documents", environment::get_folder_path(environment::special_folder::common_documents)}, {"Common admin tools", environment::get_folder_path(environment::special_folder::common_admin_tools)}, {"Admin tools", environment::get_folder_path(environment::special_folder::admin_tools)}, {"Common music", environment::get_folder_path(environment::special_folder::common_music)}, {"Common pictures", environment::get_folder_path(environment::special_folder::common_pictures)}, {"Common videos", environment::get_folder_path(environment::special_folder::common_videos)}, {"Resources", environment::get_folder_path(environment::special_folder::resources)}, {"Localized resources", environment::get_folder_path(environment::special_folder::localized_resources)}, {"common oem links", environment::get_folder_path(environment::special_folder::common_oem_links)}, {"Cd burning", environment::get_folder_path(environment::special_folder::cd_burning)}, {"Home", environment::get_folder_path(environment::special_folder::home)},};
}

system_report::system_color_collection system_report::system_colors() noexcept {
  return {{"Active border", color::from_argb(drawing::system_colors::active_border().to_argb())}, {"Active caption", color::from_argb(drawing::system_colors::active_caption().to_argb())}, {"Active caption text", color::from_argb(drawing::system_colors::active_caption_text().to_argb())}, {"App workspace", color::from_argb(drawing::system_colors::app_workspace().to_argb())}, {"Control", color::from_argb(drawing::system_colors::control().to_argb())}, {"Control dark", color::from_argb(drawing::system_colors::control_dark().to_argb())}, {"Control dark dark", color::from_argb(drawing::system_colors::control_dark_dark().to_argb())}, {"Control light", color::from_argb(drawing::system_colors::control_light().to_argb())}, {"ontrol light ligCht", color::from_argb(drawing::system_colors::control_light_light().to_argb())}, {"Control text", color::from_argb(drawing::system_colors::control_text().to_argb())}, {"Gray text", color::from_argb(drawing::system_colors::gray_text().to_argb())}, {"Highlight", color::from_argb(drawing::system_colors::highlight().to_argb())}, {"Highlight text", color::from_argb(drawing::system_colors::highlight_text().to_argb())}, {"Hot track", color::from_argb(drawing::system_colors::hot_track().to_argb())}, {"Inactive_border", color::from_argb(drawing::system_colors::inactive_border().to_argb())}, {"Inactive caption", color::from_argb(drawing::system_colors::inactive_caption().to_argb())}, {"Inactive caption text", color::from_argb(drawing::system_colors::inactive_caption_text().to_argb())}, {"Info", color::from_argb(drawing::system_colors::info().to_argb())}, {"Info text", color::from_argb(drawing::system_colors::info_text().to_argb())}, {"Menu", color::from_argb(drawing::system_colors::menu().to_argb())}, {"Menu text", color::from_argb(drawing::system_colors::menu_text().to_argb())}, {"Scroll bar", color::from_argb(drawing::system_colors::scroll_bar().to_argb())}, {"Window", color::from_argb(drawing::system_colors::window().to_argb())}, {"Window frame", color::from_argb(drawing::system_colors::window_frame().to_argb())}, {"Window text", color::from_argb(drawing::system_colors::window_text().to_argb())}, {"Button face", color::from_argb(drawing::system_colors::button_face().to_argb())}, {"Button highlight", color::from_argb(drawing::system_colors::button_highlight().to_argb())}, {"Button shadow", color::from_argb(drawing::system_colors::button_shadow().to_argb())}, {"Gradient active caption", color::from_argb(drawing::system_colors::gradient_active_caption().to_argb())}, {"Gradient inactive caption", color::from_argb(drawing::system_colors::gradient_inactive_caption().to_argb())}, {"Menu bar", color::from_argb(drawing::system_colors::menu_bar().to_argb())}, {"Menu highlight", color::from_argb(drawing::system_colors::menu_highlight().to_argb())}, {"Accent", color::from_argb(drawing::system_colors::accent().to_argb())}, {"Accent text", color::from_argb(drawing::system_colors::accent_text().to_argb())}, {"Text box", color::from_argb(drawing::system_colors::text_box().to_argb())}, {"Text box text", color::from_argb(drawing::system_colors::text_box_text().to_argb())},};
}

system_report::system_font_family_collection system_report::generic_font_families() noexcept {
  return {{"Monospace", font_family::generic_monospace()}, {"Sans serif", font_family::generic_sans_serif()}, {"Serif", font_family::generic_serif()},};
}

system_report::system_font_collection system_report::system_fonts() noexcept {
  return {{"Caption", drawing::system_fonts::caption_font()}, {"Default", drawing::system_fonts::default_font()}, {"Dialog", drawing::system_fonts::dialog_font()}, {"Icon title", drawing::system_fonts::icon_title_font()}, {"Menu", drawing::system_fonts::menu_font()}, {"Message box", drawing::system_fonts::message_box_font()}, {"Small caption", drawing::system_fonts::small_caption_font()}, {"Status", drawing::system_fonts::status_font()},};
}

system_report::system_information_collection system_report::system_informations() noexcept {
  return {
    {"Active window tracking delay", strings::format("{}", forms::system_information::active_window_tracking_delay())},
    {"Active", strings::format("{}", forms::system_information::active_window_tracking_delay())},
    {"Arrange direction", strings::format("{}", forms::system_information::arrange_direction())},
    {"Arrange starting position", strings::format("{}", forms::system_information::arrange_starting_position())},
    {"Boot mode", strings::format("{}", forms::system_information::boot_mode())},
    {"Border 3d size", strings::format("{}", forms::system_information::border_3d_size())},
    {"Border multiplier factor", strings::format("{}", forms::system_information::border_multiplier_factor())},
    {"Border size", strings::format("{}", forms::system_information::border_size())},
    {"Caption button size", strings::format("{}", forms::system_information::caption_button_size())},
    {"Caption height", strings::format("{}", forms::system_information::caption_height())},
    {"Caret blink time", strings::format("{}", forms::system_information::caret_blink_time())},
    {"Caret width", strings::format("{}", forms::system_information::caret_width())},
    {"Computer name", strings::format("{}", forms::system_information::computer_name())},
    {"Cursor size", strings::format("{}", forms::system_information::cursor_size())},
    {"DBCS enabled", strings::format("{}", forms::system_information::dbcs_enabled())},
    {"Debug os", strings::format("{}", forms::system_information::debug_os())},
    {"Double click size", strings::format("{}", forms::system_information::double_click_size())},
    {"Double_click time", strings::format("{}", forms::system_information::double_click_time())},
    {"Drag full windows", strings::format("{}", forms::system_information::drag_full_windows())},
    {"Drag size", strings::format("{}", forms::system_information::drag_size())},
    {"Fixed frame border size", strings::format("{}", forms::system_information::fixed_frame_border_size())},
    {"Font smoothing contrast", strings::format("{}", forms::system_information::font_smoothing_contrast())},
    {"Font smoothing type", strings::format("{}", forms::system_information::font_smoothing_type())},
    //{"Frame border size", strings::format("{}", forms::system_information::frame_border_size())},
    //{"High contrast", strings::format("{}", forms::system_information::high_contrast())},
    //{"Horizontal focus thickness", strings::format("{}", forms::system_information::horizontal_focus_thickness())},
    //{"Horizontal resize border thickness", strings::format("{}", forms::system_information::horizontal_resize_border_thickness())},
    //{"Horizontal scroll bar arrow width", strings::format("{}", forms::system_information::horizontal_scroll_bar_arrow_width())},
    {"Horizontal scroll bar height", strings::format("{}", forms::system_information::horizontal_scroll_bar_height())},
    //{"Horizontal scroll bar bhumb width", strings::format("{}", forms::system_information::horizontal_scroll_bar_bhumb_width())},
    //{"icon_horizontal_spacing", strings::format("{}", forms::system_information::icon_horizontal_spacing())},
    //{"Active", strings::format("{}", forms::system_information::active_window_tracking_delay())},
  };
}

string system_report::to_string() noexcept {
  int32_t indent = 0;
  string report;
  report += generate_stack_trace_string_report(indent);
  report += generate_libraries_string_report(indent);
  report += generate_processor_string_report(indent);
  report += generate_operating_system_string_report(indent);
  report += generate_compiler_string_report(indent);
  report += generate_language_string_report(indent);
  report += generate_locale_string_report(indent);
  report += generate_environment_variables_string_report(indent);
  report += generate_special_folders_string_report(indent);
  report += generate_system_colors_string_report(indent);
  report += generate_generic_font_families_string_report(indent);
  report += generate_system_fonts_string_report(indent);
  report += generate_screens_report(indent);
  report += generate_system_informations_string_report(indent);
  return report;
}

string system_report::to_xml() noexcept {
  return "(Not yet implemented)";
}
