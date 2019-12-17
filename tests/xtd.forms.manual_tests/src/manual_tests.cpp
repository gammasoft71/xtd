#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class progress_dialog : public form {
public:
  progress_dialog() {
    client_size({300, 50});
    progress_bar_.dock(dock_style::fill);
  }
  
  /// @brief Gets the maximum value of the range of the control.
  /// @return The maximum value of the range. The default is 100.
  /// @remarks This property specifies the upper limit of the value property. When the value of the maximum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the maximum property, the progress bar is completely filled.
  /// @remarks You can use this property to specify a value to which the value property must be set (by setting the value property or using the increment or perform_step methods) to indicate that an operation is complete. For example, you can set the value of the maximum property to the total number of files in a file copy operation. Each time a file is copied, the value property can be increased by 1 until the total number of files is copied. At that point, the progress bar would be completely filled.
  virtual int32_t maximum() {return progress_bar_.maximum();}
  /// @brief Sets the maximum value of the range of the control.
  /// @param maximum The maximum value of the range. The default is 100.
  /// @remarks This property specifies the upper limit of the value property. When the value of the maximum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the maximum property, the progress bar is completely filled.
  /// @remarks You can use this property to specify a value to which the value property must be set (by setting the value property or using the increment or perform_step methods) to indicate that an operation is complete. For example, you can set the value of the maximum property to the total number of files in a file copy operation. Each time a file is copied, the value property can be increased by 1 until the total number of files is copied. At that point, the progress bar would be completely filled.
  virtual progress_dialog& maximum(int32_t maximum) {progress_bar_.maximum(maximum); return *this;}
  
  /// @brief Gets the minimum value of the range of the control.
  /// @return The minimum value of the range. The default is 0.
  /// @remarks This property specifies the lower limit of the value property. When the value of the minimum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the minimum property, the progress bar is empty. To change the value of the progress bar, use the step property with the perform_step method, use the increment method, or set the value of the value property directly.
  virtual int32_t minimum() {return progress_bar_.minimum();}
  /// @brief Sets the minimum value of the range of the control.
  /// @param minimum The minimum value of the range. The default is 0.
  /// @remarks This property specifies the lower limit of the value property. When the value of the minimum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the minimum property, the progress bar is empty. To change the value of the progress bar, use the step property with the perform_step method, use the increment method, or set the value of the value property directly.
  virtual progress_dialog& minimum(int32_t minimum) {progress_bar_.minimum(minimum); return *this;}

protected:
  progress_bar progress_bar_;
};

class my_panel : public panel {
public:
  my_panel() {
    size({280, 280});
    
    panel_internal.parent(*this);
    panel_internal.back_color(drawing::color::light_blue);
    panel_internal.size({180, 180});
    panel_internal.location({50, 50});
    panel_internal.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
  }
  
  panel panel_internal;
};

int main() {
  main_menu menu;
  
  menu.menu_items().push_back("File");
  menu.menu_items().push_back("Edit");
  menu.menu_items().push_back("View");
  
  form form_main;
  form_main.text("Manual tests");
  //form_main.client_size({300, 300});
  //form_main.menu(menu);

  /*
  panel panel_fill;
  panel_fill.back_color(drawing::color::light_green);
  panel_fill.parent(form_main);
  panel_fill.location({10, 10});
  panel_fill.size({280, 280});
  //panel_fill.dock(dock_style::fill);
  panel_fill.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);

  //panel panel_left;
  //panel_left.parent(form_main);
  //panel_left.dock(dock_style::left);
  //panel_left.back_color(drawing::color::light_pink);
  //panel_left.width(100);
  
  panel panel1;
  panel1.location({50, 50});
  panel1.parent(panel_fill);
  panel1.size({180, 180});
  panel1.back_color(drawing::color::light_blue);
  panel1.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
   */

  /*
  form_main.suspend_layout();
  my_panel panel_fill;
  panel_fill.back_color(drawing::color::light_green);
  panel_fill.parent(form_main);
  panel_fill.location({10, 10});
  panel_fill.size({280, 280});
  panel_fill.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
  form_main.resume_layout();
   */

  /*
  button btn;
  btn.parent(form_main);
  btn.click += [&] {
    progress_dialog progress;
    progress.form_border_style(forms::form_border_style::none);
    progress.parent(form_main);
    progress.close_box(false);
    progress.minimize_box(false);
    progress.maximize_box(false);

    progress.show_dialog();
  };
   */

  /*
  lcd_label label;
  label.parent(form_main);
  label.auto_size(true);
  label.text(lcd_label::valid_characters());

  form_main.close_box(false);
  form_main.form_border_style(forms::form_border_style::none);
  form_main.control_box(false);
  form_main.minimize_box(false);
  form_main.maximize_box(false);
  form_main.auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  form_main.auto_size(true);
  form_main.start_position(form_start_position::center_screen);
   */
  
  seven_segment_display ssd;
  ssd.parent(form_main);
  ssd.location({10, 10});
  ssd.dock(dock_style::fill);
  ssd.segment_style(forms::segment_style::modern);
  ssd.value(segments::a|segments::b|segments::c|segments::d|segments::e|segments::f|segments::g);
  ssd.fore_color(drawing::color::red);

  application::run(form_main);
}
