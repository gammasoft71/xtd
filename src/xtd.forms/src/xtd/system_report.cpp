#include "../../include/xtd/system_report.hpp"
#include <xtd/box_char>
#include <xtd/environment>
#include <xtd/drawing/system_colors>
#include <xtd/drawing/system_fonts>
#include <xtd/io/path>

using namespace xtd;
using namespace xtd::drawing;

namespace {
  static constexpr int32 default_size_indent = 3;
  
  string indent_string(int32 indent, int32 size_indent) {
    return string(' ', indent * size_indent);
  }
  
  string indent_string(int32 indent) {
    return indent_string(indent, default_size_indent);
  }
  
  string generate_stack_trace_string_report(int32 indent) {
    string report = string::format("{}Stack trace{}", indent_string(indent), environment::new_line());
    auto stack_trace = system_report::stack_trace();
    for (auto frame : stack_trace.get_frames())
      report += string::format("{}{}", indent_string(indent + 1), frame);
    return report + environment::new_line();
  }
  
  string generate_libraries_string_report(int32 indent) {
    string report = string::format("{}xtd libraries{}", indent_string(indent), environment::new_line());
    for (auto library : system_report::xtd_libraries()) {
      report += string::format("{}{}{}", indent_string(indent + 1), library.name(), environment::new_line());
      report += string::format("{}Version: {}{}", indent_string(indent + 2), library.version(), environment::new_line());
      report += string::format("{}include path: {}{}", indent_string(indent + 2), library.include_path(), environment::new_line());
      report += string::format("{}library path: {}{}", indent_string(indent + 2), library.library_path(), environment::new_line());
      report += string::format("{}resources path: {}{}", indent_string(indent + 2), library.resources_path(), environment::new_line());
    }
    return report + environment::new_line();
  }
  
  string generate_processor_string_report(int32 indent) {
    string report = string::format("{}Processor{}", indent_string(indent), environment::new_line());
    auto processor = system_report::processor();
    report += string::format("{}Name: {}{}", indent_string(indent + 1), processor.name(), environment::new_line());
    report += string::format("{}Architecture: {}{}", indent_string(indent + 1), processor.architecture_string(), environment::new_line());
    report += string::format("{}Core count: {}{}", indent_string(indent + 1), processor.core_count(), environment::new_line());
    report += string::format("{}64 bit: {}{}", indent_string(indent + 1), processor.is_64_bit(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_operating_system_string_report(int32 indent) {
    auto to_time_since_boot_string = [](auto time_since_boot) {
      auto days = std::chrono::duration_cast<std::chrono::days>(time_since_boot);
      auto hours = std::chrono::duration_cast<std::chrono::hours>(time_since_boot);
      auto minutes = std::chrono::duration_cast<std::chrono::minutes>(time_since_boot);
      return string::format("{}{}{}", days.count() ? string::format("{} days, ", days.count()) : string::empty_string, days.count() || hours.count()  % 24 ? string::format("{} hours, ", hours.count() % 24) : string::empty_string, string::format("{} minutes", minutes.count() % 60));
    };
    string report = string::format("{}Operating System{}", indent_string(indent), environment::new_line());
    auto operating_system = system_report::operating_system();
    report += string::format("{}Name: {}{}", indent_string(indent + 1), operating_system.name(), environment::new_line());
    report += string::format("{}Version: {}{}", indent_string(indent + 1), operating_system.version(), environment::new_line());
    report += string::format("{}Service pack: {}{}", indent_string(indent + 1), operating_system.service_pack(), environment::new_line());
    report += string::format("{}Desktop environment: {}{}", indent_string(indent + 1), operating_system.desktop_environment(), environment::new_line());
    report += string::format("{}64 bit: {}{}", indent_string(indent + 1), operating_system.is_64_bit(), environment::new_line());
    report += string::format("{}Time since boot: {}{}", indent_string(indent + 1), to_time_since_boot_string(environment::tick_count()), environment::new_line());
    report += string::format("{}Distribution: {}", indent_string(indent + 1), environment::new_line());
    report += string::format("{}Name: {}{}", indent_string(indent + 2), operating_system.distribution().name(), environment::new_line());
    report += string::format("{}Version: {}{}", indent_string(indent + 2), operating_system.distribution().version_string(), environment::new_line());
    report += string::format("{}Id: {}{}", indent_string(indent + 2), operating_system.distribution().id(), environment::new_line());
    report += string::format("{}Home: {}{}", indent_string(indent + 2), operating_system.distribution().home(), environment::new_line());
    report += string::format("{}Bug repport: {}{}", indent_string(indent + 2), operating_system.distribution().bug_repport(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_compiler_string_report(int32 indent) {
    string report = string::format("{}Compiler{}", indent_string(indent), environment::new_line());
    auto compiler = system_report::compiler();
    report += string::format("{}Name: {}{}", indent_string(indent + 1), compiler.name(), environment::new_line());
    report += string::format("{}Version: {}{}", indent_string(indent + 1), compiler.version(), environment::new_line());
    report += string::format("{}Mode: {}{}", indent_string(indent + 1), compiler.is_build_type_debug() ? "Debug" : "Release", environment::new_line());
    report += string::format("{}64 bit: {}{}", indent_string(indent + 1), compiler.is_64_bit(), environment::new_line());
    if (!string::is_empty(compiler.additional_information())) report += string::format("{}Additional information: {}{}", indent_string(indent + 1), compiler.additional_information(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_language_string_report(int32 indent) {
    string report = string::format("{}Language{}", indent_string(indent), environment::new_line());
    auto language = system_report::language();
    report += string::format("{}Name: {}{}", indent_string(indent + 1), language.name(), environment::new_line());
    report += string::format("{}Version: {}{}", indent_string(indent + 1), language.version(), environment::new_line());
    report += string::format("{}Experimental: {}{}", indent_string(indent + 1), language.is_experimental_language(), environment::new_line());
    report += string::format("{}Supported: {}{}", indent_string(indent + 1), language.is_supported(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_locale_string_report(int32 indent) {
    string report = string::format("{}Locale{}", indent_string(indent), environment::new_line());
    auto locale = system_report::locale();
    report += string::format("{}Name: {}{}", indent_string(indent + 1), locale.name(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_toolkit_string_report(int32 indent) {
    string report = string::format("{}Toolkit{}", indent_string(indent), environment::new_line());
    auto toolkit = system_report::toolkit();
    report += string::format("{}Name: {}{}", indent_string(indent + 1), toolkit.name(), environment::new_line());
    report += string::format("{}Version: {}{}", indent_string(indent + 1), toolkit.version(), environment::new_line());
    report += string::format("{}Description: {}{}", indent_string(indent + 1), toolkit.description(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_environment_variables_string_report(int32 indent) {
    string report = string::format("{}Environment variables{}", indent_string(indent), environment::new_line());
    for (auto environment_variable : system_report::environment_variables())
      report += string::format("{}{}={}{}", indent_string(indent + 1), environment_variable.first, environment_variable.second, environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_special_folders_string_report(int32 indent) {
    string report = string::format("{}Special folders{}", indent_string(indent), environment::new_line());
    for (auto special_folder : system_report::special_folders())
      report += string::format("{}{}: {}{}", indent_string(indent + 1), special_folder.first, special_folder.second, environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_system_colors_string_report(int32 indent) {
    string report = string::format("{}System colors{}", indent_string(indent), environment::new_line());
    for (auto system_color : system_report::system_colors())
      report += string::format("{}{}: {}{}", indent_string(indent + 1), system_color.first, system_color.second, environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_generic_font_families_string_report(int32 indent) {
    string report = string::format("{}Generic font families{}", indent_string(indent), environment::new_line());
    for (auto font_family : system_report::generic_font_families())
      report += string::format("{}{}: {}{}", indent_string(indent + 1), font_family.first, font_family.second, environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_system_fonts_string_report(int32 indent) {
    string report = string::format("{}System fonts{}", indent_string(indent), environment::new_line());
    for (auto system_font : system_report::system_fonts())
      report += string::format("{}{}: {}{}", indent_string(indent + 1), system_font.first, system_font.second, environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_screens_report(int32 indent) {
    string report = string::format("{}Screens{}", indent_string(indent), environment::new_line());
    for (auto screen : system_report::screens()) {
      report += string::format("{}{}{}", indent_string(indent + 1), screen.device_name(), environment::new_line());
      report += string::format("{}Bounds: {}{}", indent_string(indent + 2), screen.bounds(), environment::new_line());
      report += string::format("{}Working area: {}{}", indent_string(indent + 2), screen.working_area(), environment::new_line());
      report += string::format("{}Bits per pixel: {}{}", indent_string(indent + 2), screen.bits_per_pixel(), environment::new_line());
      report += string::format("{}Primary screen: {}{}", indent_string(indent + 2), screen.primary(), environment::new_line());
    }
    return report + environment::new_line();
  }
  
  string generate_system_informations_string_report(int32 indent) {
    string report = string::format("{}System informations{}", indent_string(indent), environment::new_line());
    for (auto system_information : system_report::system_informations())
      report += string::format("{}{}: {}{}", indent_string(indent + 1), system_information.first, system_information.second, environment::new_line());
    return report + environment::new_line();
  }
}

xtd::compiler system_report::compiler() noexcept {
  return xtd::environment::compiler_version();
}

system_report::environment_variable_collection system_report::environment_variables() noexcept {
  environment_variable_collection environment_variables;
  auto envs = xtd::environment::get_environment_variables();
  std::for_each(envs.begin(), envs.end(), [&](auto environment_variable) {environment_variables.add({environment_variable});});
  return environment_variables;
}

const system_report::system_font_family_collection& system_report::generic_font_families() noexcept {
  static system_font_family_collection families {{"Monospace", font_family::generic_monospace()}, {"Sans Serif", font_family::generic_sans_serif()}, {"Serif", font_family::generic_serif()},};
  return families;
}

xtd::cpp_language system_report::language() noexcept {
  return xtd::environment::cpp_version();
}

std::locale system_report::locale() noexcept {
  return environment::locale();
}

xtd::operating_system system_report::operating_system() noexcept {
  return xtd::environment::os_version();
}

xtd::processor system_report::processor() noexcept {
  return xtd::environment::processor_information();
}

array<xtd::forms::screen> system_report::screens() noexcept {
  return xtd::forms::screen::all_screens();
}

const system_report::special_folder_collection& system_report::special_folders() noexcept {
  static auto special_folders = enum_object<>::get_values<environment::special_folder>();
  static special_folder_collection folders;
  if (folders.count() != 0) return folders;
  std::for_each(special_folders.begin(), special_folders.end(), [&](auto value) {folders.add({enum_object<environment::special_folder>(value).to_string().replace("_", " ").to_title_case(), environment::get_folder_path(value)});});
  return folders;
}

xtd::diagnostics::stack_trace system_report::stack_trace() noexcept {
  return stack_trace(0);
}

xtd::diagnostics::stack_trace system_report::stack_trace(size_t skip_frames) noexcept {
  return xtd::diagnostics::stack_trace(skip_frames, true);
}

const system_report::system_color_collection& system_report::system_colors() noexcept {
  static system_color_collection colors;
  if (colors.count() != 0) return colors;
  std::for_each(system_colors::get_colors().begin(), system_colors::get_colors().end(), [&](auto color) {colors.add({color.name().replace("_", " ").to_title_case(), drawing::color::from_argb(color.to_argb())});});
  return colors;
}

const system_report::system_font_collection& system_report::system_fonts() noexcept {
  static system_font_collection fonts {{"Caption", drawing::system_fonts::caption_font()}, {"Default", drawing::system_fonts::default_font()}, {"Dialog", drawing::system_fonts::dialog_font()}, {"Icon title", drawing::system_fonts::icon_title_font()}, {"Menu", drawing::system_fonts::menu_font()}, {"Message box", drawing::system_fonts::message_box_font()}, {"Small caption", drawing::system_fonts::small_caption_font()}, {"Status", drawing::system_fonts::status_font()}, {"Tool", drawing::system_fonts::tool_font()},};
  return fonts;
}

system_report::system_information_collection system_report::system_informations() noexcept {
  return {
    {"Active window tracking delay", string::format("{}", forms::system_information::active_window_tracking_delay())},
    {"Active", string::format("{}", forms::system_information::active_window_tracking_delay())},
    {"Arrange direction", string::format("{}", forms::system_information::arrange_direction())},
    {"Arrange starting position", string::format("{}", forms::system_information::arrange_starting_position())},
    {"Boot mode", string::format("{}", forms::system_information::boot_mode())},
    {"Border 3d size", string::format("{}", forms::system_information::border_3d_size())},
    {"Border multiplier factor", string::format("{}", forms::system_information::border_multiplier_factor())},
    {"Border size", string::format("{}", forms::system_information::border_size())},
    {"Caption button size", string::format("{}", forms::system_information::caption_button_size())},
    {"Caption height", string::format("{}", forms::system_information::caption_height())},
    {"Caret blink time", string::format("{}", forms::system_information::caret_blink_time())},
    {"Caret width", string::format("{}", forms::system_information::caret_width())},
    {"Computer name", string::format("{}", forms::system_information::computer_name())},
    {"Cursor size", string::format("{}", forms::system_information::cursor_size())},
    {"DBCS enabled", string::format("{}", forms::system_information::dbcs_enabled())},
    {"Debug os", string::format("{}", forms::system_information::debug_os())},
    {"Double click size", string::format("{}", forms::system_information::double_click_size())},
    {"Double_click time", string::format("{}", forms::system_information::double_click_time())},
    {"Drag full windows", string::format("{}", forms::system_information::drag_full_windows())},
    {"Drag size", string::format("{}", forms::system_information::drag_size())},
    {"Fixed frame border size", string::format("{}", forms::system_information::fixed_frame_border_size())},
    {"Font smoothing contrast", string::format("{}", forms::system_information::font_smoothing_contrast())},
    {"Font smoothing type", string::format("{}", forms::system_information::font_smoothing_type())},
    //{"Frame border size", string::format("{}", forms::system_information::frame_border_size())},
    //{"High contrast", string::format("{}", forms::system_information::high_contrast())},
    //{"Horizontal focus thickness", string::format("{}", forms::system_information::horizontal_focus_thickness())},
    //{"Horizontal resize border thickness", string::format("{}", forms::system_information::horizontal_resize_border_thickness())},
    //{"Horizontal scroll bar arrow width", string::format("{}", forms::system_information::horizontal_scroll_bar_arrow_width())},
    {"Horizontal scroll bar height", string::format("{}", forms::system_information::horizontal_scroll_bar_height())},
    //{"Horizontal scroll bar bhumb width", string::format("{}", forms::system_information::horizontal_scroll_bar_bhumb_width())},
    //{"icon_horizontal_spacing", string::format("{}", forms::system_information::icon_horizontal_spacing())},
    //{"Active", string::format("{}", forms::system_information::active_window_tracking_delay())},
  };
}

xtd::toolkit system_report::toolkit() noexcept {
  return xtd::environment::toolkit_version();
}

const xtd::environment::xtd_library_collection& system_report::xtd_libraries() noexcept {
  return environment::xtd_libraries();
}

string system_report::to_json() noexcept {
  return to_json(reports::all);
}

string system_report::to_json(reports reports) noexcept {
  return "(The JSON report is not yet implemented)";
}

string system_report::to_string() noexcept {
  return to_string(reports::all);
}

string system_report::to_string(reports reports) noexcept {
  int32 indent = 0;
  string report;
  if ((reports & system_report::reports::stack_trace) == system_report::reports::stack_trace) report += generate_stack_trace_string_report(indent);
  if ((reports & system_report::reports::libraries) == system_report::reports::libraries) report += generate_libraries_string_report(indent);
  if ((reports & system_report::reports::processor) == system_report::reports::processor) report += generate_processor_string_report(indent);
  if ((reports & system_report::reports::operating_system) == system_report::reports::operating_system) report += generate_operating_system_string_report(indent);
  if ((reports & system_report::reports::compiler) == system_report::reports::compiler) report += generate_compiler_string_report(indent);
  if ((reports & system_report::reports::language) == system_report::reports::language) report += generate_language_string_report(indent);
  if ((reports & system_report::reports::locale) == system_report::reports::locale) report += generate_locale_string_report(indent);
  if ((reports & system_report::reports::toolkit) == system_report::reports::toolkit) report += generate_toolkit_string_report(indent);
  if ((reports & system_report::reports::environment_variables) == system_report::reports::environment_variables) report += generate_environment_variables_string_report(indent);
  if ((reports & system_report::reports::special_folders) == system_report::reports::special_folders) report += generate_special_folders_string_report(indent);
  if ((reports & system_report::reports::system_colors) == system_report::reports::system_colors) report += generate_system_colors_string_report(indent);
  if ((reports & system_report::reports::generic_font_families) == system_report::reports::generic_font_families) report += generate_generic_font_families_string_report(indent);
  if ((reports & system_report::reports::system_fonts) == system_report::reports::system_fonts) report += generate_system_fonts_string_report(indent);
  if ((reports & system_report::reports::screens) == system_report::reports::screens) report += generate_screens_report(indent);
  if ((reports & system_report::reports::system_informations) == system_report::reports::system_informations) report += generate_system_informations_string_report(indent);
  return report;
}

string system_report::to_xml() noexcept {
  return to_xml(reports::all);
}

string system_report::to_xml(reports reports) noexcept {
  return "(The XML report is not yet implemented)";
}
