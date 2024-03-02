#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/drawing/color_converter>
#include <xtd/drawing/system_colors>
#include <xtd/forms/application>
#include <xtd/forms/check_box>
#include <xtd/forms/combo_box>
#include <xtd/forms/group_box>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::text;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

class strings_form : public form {
public:
  static auto main() {
    application::run(strings_form());
  }
  
  strings_form() {
    text("Strings tests");
    padding(5);
    client_size({1000, 800});
    
    tab_control.parent(*this);
    tab_control.dock(dock_style::fill);
    
    color_tab_page.parent(tab_control);
    color_tab_page.text("Color");
    color_tab_page.paint += {*this, &strings_form::draw_strings_with_color};
    
    linear_gradient_tab_page.parent(tab_control);
    linear_gradient_tab_page.text("Linear gradient");
    linear_gradient_tab_page.paint += {*this, &strings_form::draw_strings_with_linear_gradient};
    
    multilines_tab_page.parent(tab_control);
    multilines_tab_page.text("Multiline");
    multilines_tab_page.paint += {*this, &strings_form::draw_strings_multilines};
    
    hotkey_prefix_tab_page.parent(tab_control);
    hotkey_prefix_tab_page.text("Prefix");
    hotkey_prefix_tab_page.paint += {*this, &strings_form::draw_strings_hotkey_prefix};
    
    trim_tab_page.parent(tab_control);
    trim_tab_page.text("Trimming");
    trim_tab_page.paint += {*this, &strings_form::draw_strings_trim};
    
    string_format_tab_page.parent(tab_control);
    string_format_tab_page.text("String format");
    string_format_tab_page.paint += {*this, &strings_form::draw_strings_with_string_format};
    
    string_format_tab_page.controls().push_back_range({alignmentLabel, alignmentComboBox, lineAlignmentLabel, lineAlignmentComboBox, trimmingLabel, trimmingComboBox, hotKeyPrefixLabel, hotKeyPrefixComboBox, formatFlagsGroupBox});
    
    alignmentLabel.auto_size(true);
    alignmentLabel.location({10, 12});
    alignmentLabel.text("Alignment");
    
    alignmentComboBox.drop_down_style(combo_box_style::drop_down_list);
    alignmentComboBox.items().push_back_range({{"near", string_alignment::near}, {"center", string_alignment::center}, {"far", string_alignment::far}});
    alignmentComboBox.location({120, 10});
    alignmentComboBox.selected_index(0);
    alignmentComboBox.selected_index_changed += [&] {string_format_tab_page.invalidate(false);};
    
    lineAlignmentLabel.auto_size(true);
    lineAlignmentLabel.location({280, 12});
    lineAlignmentLabel.text("Line alignment");
    
    lineAlignmentComboBox.drop_down_style(combo_box_style::drop_down_list);
    lineAlignmentComboBox.items().push_back_range({{"near", string_alignment::near}, {"center", string_alignment::center}, {"far", string_alignment::far}});
    lineAlignmentComboBox.location({390, 10});
    lineAlignmentComboBox.selected_index(0);
    lineAlignmentComboBox.selected_index_changed += [&] {string_format_tab_page.invalidate(false);};
    
    trimmingLabel.auto_size(true);
    trimmingLabel.location({10, 52});
    trimmingLabel.text("Trimming");
    
    trimmingComboBox.drop_down_style(combo_box_style::drop_down_list);
    trimmingComboBox.items().push_back_range({{"none", string_trimming::none}, {"character", string_trimming::character}, {"word", string_trimming::word}, {"ellipsis_character", string_trimming::ellipsis_character}, {"ellipsis_word", string_trimming::ellipsis_word}, {"ellipsis_path", string_trimming::ellipsis_path}});
    trimmingComboBox.location({120, 50});
    trimmingComboBox.selected_index(0);
    trimmingComboBox.selected_index_changed += [&] {string_format_tab_page.invalidate(false);};
    
    hotKeyPrefixLabel.auto_size(true);
    hotKeyPrefixLabel.location({280, 52});
    hotKeyPrefixLabel.text("Hotkey prefix");
    
    hotKeyPrefixComboBox.drop_down_style(combo_box_style::drop_down_list);
    hotKeyPrefixComboBox.items().push_back_range({{"none", hotkey_prefix::none}, {"show", hotkey_prefix::show}, {"hide", hotkey_prefix::hide}});
    hotKeyPrefixComboBox.location({390, 50});
    hotKeyPrefixComboBox.selected_index(0);
    hotKeyPrefixComboBox.selected_index_changed += [&] {string_format_tab_page.invalidate(false);};
    
    formatFlagsGroupBox.controls().push_back_range({directionRightToLeftCheckBox, directionVerticalCheckBox, FitBlackBoxCheckBox, DisplayFormatControlCheckBox, NoFontFallbackCheckBox, MeasureTrailingSpacesCheckBox, NoWrapCheckBox, LineLimitCheckBox, NoClipCheckBox});
    formatFlagsGroupBox.location({10, 90});
    formatFlagsGroupBox.size({500, 185});
    formatFlagsGroupBox.text("Fromat flags");
    
    directionRightToLeftCheckBox.auto_size(true);
    directionRightToLeftCheckBox.location({10, 10});
    directionRightToLeftCheckBox.text("Direction right to left");
    directionRightToLeftCheckBox.checked_changed += [&] {string_format_tab_page.invalidate(false);};
    
    directionVerticalCheckBox.auto_size(true);
    directionVerticalCheckBox.location({270, 10});
    directionVerticalCheckBox.text("Direction vertical");
    directionVerticalCheckBox.checked_changed += [&] {string_format_tab_page.invalidate(false);};
    
    FitBlackBoxCheckBox.auto_size(true);
    FitBlackBoxCheckBox.location({10, 40});
    FitBlackBoxCheckBox.text("Fit back box");
    FitBlackBoxCheckBox.checked_changed += [&] {string_format_tab_page.invalidate(false);};
    
    DisplayFormatControlCheckBox.auto_size(true);
    DisplayFormatControlCheckBox.location({270, 40});
    DisplayFormatControlCheckBox.text("Display format control");
    DisplayFormatControlCheckBox.checked_changed += [&] {string_format_tab_page.invalidate(false);};
    
    NoFontFallbackCheckBox.auto_size(true);
    NoFontFallbackCheckBox.location({10, 70});
    NoFontFallbackCheckBox.text("No font failback");
    NoFontFallbackCheckBox.checked_changed += [&] {string_format_tab_page.invalidate(false);};
    
    MeasureTrailingSpacesCheckBox.auto_size(true);
    MeasureTrailingSpacesCheckBox.location({270, 70});
    MeasureTrailingSpacesCheckBox.text("Measure trailing spaces");
    MeasureTrailingSpacesCheckBox.checked_changed += [&] {string_format_tab_page.invalidate(false);};
    
    NoWrapCheckBox.auto_size(true);
    NoWrapCheckBox.location({10, 100});
    NoWrapCheckBox.text("No wrap");
    NoWrapCheckBox.checked_changed += [&] {string_format_tab_page.invalidate(false);};
    
    LineLimitCheckBox.auto_size(true);
    LineLimitCheckBox.location({270, 100});
    LineLimitCheckBox.text("Line limit");
    LineLimitCheckBox.checked_changed += [&] {string_format_tab_page.invalidate(false);};
    
    NoClipCheckBox.auto_size(true);
    NoClipCheckBox.location({10, 130});
    NoClipCheckBox.text("No clip");
    NoClipCheckBox.checked_changed += [&] {string_format_tab_page.invalidate(false);};
  }
  
private:
  forms::tab_control tab_control;
  forms::tab_page color_tab_page;
  forms::tab_page linear_gradient_tab_page;
  forms::tab_page multilines_tab_page;
  forms::tab_page hotkey_prefix_tab_page;
  forms::tab_page trim_tab_page;
  forms::tab_page string_format_tab_page;
  
  label alignmentLabel;
  combo_box alignmentComboBox;
  label lineAlignmentLabel;
  combo_box lineAlignmentComboBox;
  label trimmingLabel;
  combo_box trimmingComboBox;
  label hotKeyPrefixLabel;
  combo_box hotKeyPrefixComboBox;
  group_box formatFlagsGroupBox;
  check_box directionRightToLeftCheckBox;
  check_box directionVerticalCheckBox;
  check_box FitBlackBoxCheckBox;
  check_box DisplayFormatControlCheckBox;
  check_box NoFontFallbackCheckBox;
  check_box MeasureTrailingSpacesCheckBox;
  check_box NoWrapCheckBox;
  check_box LineLimitCheckBox;
  check_box NoClipCheckBox;
  
  const ustring regular_str = u8"Regular text - 普通文本";
  const ustring italic_str = u8"Italic text - 斜体文字";
  const ustring bold_str = u8"Bold text - 黑体字";
  
  const xtd::drawing::font regular_font = xtd::drawing::font(system_fonts::default_font(), 32, font_style::regular);
  const xtd::drawing::font italic_font = xtd::drawing::font(system_fonts::default_font(), 32, font_style::italic);
  const xtd::drawing::font bold_font = xtd::drawing::font(system_fonts::default_font(), 32, font_style::bold);
  
  void draw_grid(const rectangle& rect, drawing::graphics& graphics, const drawing::size& grid_size = drawing::size(5, 5)) {
    auto color1 = back_color().is_dark() ? color_converter::light(back_color()) : color_converter::dark(back_color());
    auto color2 = fore_color().is_dark() ? color_converter::light(fore_color()) : color_converter::dark(fore_color());
    for (auto x = rect.left(); x < rect.right(); x += grid_size.width())
      graphics.draw_line(pen(color1, 1), point(x, rect.top()), point(x, rect.bottom()));
    for (auto y = rect.top(); y < rect.bottom(); y += grid_size.height())
      graphics.draw_line(pen(color1, 1), point(rect.left(), y), point(rect.right(), y));
    for (auto x = rect.left(); x < rect.right(); x += grid_size.width() * 10)
      graphics.draw_line(pen(color2, 1), point(x, rect.top()), point(x, rect.bottom()));
    for (auto y = rect.top(); y < rect.bottom(); y += grid_size.height() * 10)
      graphics.draw_line(pen(color2, 1), point(rect.left(), y), point(rect.right(), y));
  }
  
  void draw_strings_with_color(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_string(regular_str, regular_font, solid_brush(color::red), point(50, 50));
    e.graphics().draw_string(italic_str, italic_font, solid_brush(color::green), point(50, 100));
    e.graphics().draw_string(bold_str, bold_font, solid_brush(color::blue), point(50, 150));
    
    e.graphics().draw_rotated_string(regular_str, regular_font, solid_brush(color::red), point(100, 250), 90);
    e.graphics().draw_rotated_string(italic_str, italic_font, solid_brush(color::green), point(150, 250), 90);
    e.graphics().draw_rotated_string(bold_str, bold_font, solid_brush(color::blue), point(200, 250), 90);
    
    e.graphics().draw_rotated_string(regular_str, regular_font, solid_brush(color::red), point(300, 250), 45);
    e.graphics().draw_rotated_string(italic_str, italic_font, solid_brush(color::green), point(350, 250), 45);
    e.graphics().draw_rotated_string(bold_str, bold_font, solid_brush(color::blue), point(400, 250), 45);
  }
  
  void draw_strings_with_linear_gradient(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_string(regular_str, regular_font, linear_gradient_brush(point_f(50, 50), point_f(e.graphics().measure_string(regular_str, regular_font)), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}), point(50, 50));
    e.graphics().draw_string(italic_str, italic_font, linear_gradient_brush(point_f(50, 50), point_f(e.graphics().measure_string(italic_str, italic_font)), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}), point(50, 100));
    e.graphics().draw_string(bold_str, bold_font, linear_gradient_brush(point_f(50, 50), point_f(e.graphics().measure_string(bold_str, bold_font)), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}), point(50, 150));
    
    auto text_size = e.graphics().measure_string(regular_str, regular_font);
    e.graphics().draw_rotated_string(regular_str, regular_font, linear_gradient_brush(rectangle_f(point_f(100, 250), size_f(text_size.height(), text_size.width())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 90.0f), point(100, 250), 90);
    text_size = e.graphics().measure_string(italic_str, italic_font);
    e.graphics().draw_rotated_string(italic_str, italic_font, linear_gradient_brush(rectangle_f(point_f(150, 250), size_f(text_size.height(), text_size.width())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 90.0f), point(150, 250), 90);
    text_size = e.graphics().measure_string(bold_str, bold_font);
    e.graphics().draw_rotated_string(bold_str, bold_font, linear_gradient_brush(rectangle_f(point_f(200, 250), size_f(text_size.height(), text_size.width())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 90.0f), point(200, 250), 90);
    
    text_size = size_f(300.0f, 300.0f);
    e.graphics().draw_rotated_string(regular_str, regular_font, linear_gradient_brush(rectangle_f(point_f(300, 250), size_f(text_size.width(), text_size.height())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 45.0f), point(300, 250), 45);
    text_size = size_f(260.0f, 260.0f);
    e.graphics().draw_rotated_string(italic_str, italic_font, linear_gradient_brush(rectangle_f(point_f(350, 250), size_f(text_size.width(), text_size.height())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 45.0f), point(350, 250), 45);
    text_size = size_f(240.0f, 240.0f);
    e.graphics().draw_rotated_string(bold_str, bold_font, linear_gradient_brush(rectangle_f(point_f(400, 250), size_f(text_size.width(), text_size.height())), {color::red, color::orange, color::yellow, color::green, color::cyan, color::blue, color::dark_magenta, color::magenta}, 45.0f), point(400, 250), 45);
  }
  
  void draw_strings_hotkey_prefix(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    e.graphics().draw_string("&No hotkey prefix", regular_font, solid_brush(system_colors::control_text()), point(50, 50), string_format().hotkey_prefix(xtd::drawing::text::hotkey_prefix::none));
    e.graphics().draw_string("&Show hotkey prefix", regular_font, solid_brush(system_colors::control_text()), point(50, 150), string_format().hotkey_prefix(xtd::drawing::text::hotkey_prefix::show));
    e.graphics().draw_string("&Hide hotkey prefix", regular_font, solid_brush(system_colors::control_text()), point(50, 250), string_format().hotkey_prefix(xtd::drawing::text::hotkey_prefix::hide));
  }
  
  void draw_strings_trim(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    auto text = "Lorem ipsum dolor sitas amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec,"_s;
    auto text_size = e.graphics().measure_string(text, regular_font);
    
    e.graphics().draw_string(text, regular_font, solid_brush(system_colors::control_text()), rectangle_f(50.0f, 50.0f, 850.0f, as<float>(text_size.height())), string_format(string_format_flags::no_wrap).trimming(xtd::drawing::string_trimming::none));
    e.graphics().draw_string(text, regular_font, solid_brush(system_colors::control_text()), rectangle_f(50.0f, 150.0f, 850.0f, as<float>(text_size.height())), string_format(string_format_flags::no_wrap).trimming(xtd::drawing::string_trimming::character));
    e.graphics().draw_string(text, regular_font, solid_brush(system_colors::control_text()), rectangle_f(50.0f, 250.0f, 850.0f, as<float>(text_size.height())), string_format(string_format_flags::no_wrap).trimming(xtd::drawing::string_trimming::word));
    e.graphics().draw_string(text, regular_font, solid_brush(system_colors::control_text()), rectangle_f(50.0f, 350.0f, 850.0f, as<float>(text_size.height())), string_format(string_format_flags::no_wrap).trimming(xtd::drawing::string_trimming::ellipsis_character));
    e.graphics().draw_string(text, regular_font, solid_brush(system_colors::control_text()), rectangle_f(50.0f, 450.0f, 850.0f, as<float>(text_size.height())), string_format(string_format_flags::no_wrap).trimming(xtd::drawing::string_trimming::ellipsis_word));
    e.graphics().draw_string(ustring::format("{0}directory1{0}directory2{0}directory3{0}directory4{0}directory5{0}directory6{0}file.txt", xtd::io::path::directory_separator_char()), regular_font, solid_brush(system_colors::control_text()), rectangle_f(50.0f, 550.0f, 850.0f, as<float>(text_size.height())), string_format(string_format_flags::no_wrap).trimming(xtd::drawing::string_trimming::ellipsis_path));
  }
  
  void draw_strings_with_string_format(object& sender, paint_event_args& e) {
  
    auto rect = rectangle(100, 340, e.clip_rectangle().width() - 200, e.clip_rectangle().height() - 487);
    draw_grid(rect, e.graphics());
    
    e.graphics().draw_rectangle(pen(system_colors::control_text()), rect);
    
    auto text = "&Lorem &ipsum &&dolor sit amet, consectetur adipiscing elit.                                     \nSed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.\n\nUt velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar. Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula. Pellentesque rhoncus nunc et augue. Integer id felis. Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Morbi vel erat non mauris convallis vehicula. Nulla et sapien. Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat. Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n\nAliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus. Fusce vulputate sem at sapien. Vivamus leo. Aliquam euismod libero eu enim. Nulla nec felis sed leo placerat imperdiet. Aenean suscipit nulla in justo. Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus. Curabitur eu amet.\n"_s;
    
    string_format format;
    
    format.alignment(std::any_cast<string_alignment>(alignmentComboBox.selected_item().tag()));
    
    format.line_alignment(std::any_cast<string_alignment>(lineAlignmentComboBox.selected_item().tag()));
    
    format.trimming(std::any_cast<string_trimming>(trimmingComboBox.selected_item().tag()));
    
    format.hotkey_prefix(std::any_cast<hotkey_prefix>(hotKeyPrefixComboBox.selected_item().tag()));
    
    if (directionRightToLeftCheckBox.checked()) format.format_flags(format.format_flags() | string_format_flags::direction_right_to_left);
    if (directionVerticalCheckBox.checked()) format.format_flags(format.format_flags() | string_format_flags::direction_vertical);
    if (FitBlackBoxCheckBox.checked()) format.format_flags(format.format_flags() | string_format_flags::fit_black_box);
    if (DisplayFormatControlCheckBox.checked()) format.format_flags(format.format_flags() | string_format_flags::display_format_control);
    if (NoFontFallbackCheckBox.checked()) format.format_flags(format.format_flags() | string_format_flags::no_font_fallback);
    if (MeasureTrailingSpacesCheckBox.checked()) format.format_flags(format.format_flags() | string_format_flags::measure_trailing_spaces);
    if (NoWrapCheckBox.checked()) format.format_flags(format.format_flags() | string_format_flags::no_wrap);
    if (LineLimitCheckBox.checked()) format.format_flags(format.format_flags() | string_format_flags::line_limit);
    if (NoClipCheckBox.checked()) format.format_flags(format.format_flags() | string_format_flags::no_clip);
    
    auto font = xtd::drawing::font(system_fonts::default_font(), 16, font_style::regular);
    e.graphics().draw_string(text, font, solid_brush(system_colors::control_text()), rect, format);
  }
  
  void draw_strings_multilines(object& sender, paint_event_args& e) {
    draw_grid(e.clip_rectangle(), e.graphics());
    
    const xtd::drawing::font font = xtd::drawing::font(system_fonts::default_font(), 16, font_style::regular);
    auto text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nSed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec,\nultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a,\nsemper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie,\nenim est eleifend mi, non fermentum diam nisl sit amet erat."_s;
    e.graphics().draw_string(text, font, solid_brush(system_colors::control_text()), point(50, 50));
    e.graphics().draw_string(text, font, solid_brush(system_colors::control_text()), point(50, 250), string_format().alignment(xtd::drawing::string_alignment::center));
    e.graphics().draw_string(text, font, solid_brush(system_colors::control_text()), point(50, 450), string_format().alignment(xtd::drawing::string_alignment::far));
  }
};

startup_(strings_form::main);
