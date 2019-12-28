#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class progress_dialog : public form {
public:
  progress_dialog() {
    client_size({350, 50});
    start_position(form_start_position::center_parent);
    minimize_box(false);
    maximize_box(false);
    control_box(false);
    progress_bar_.parent(*this);
    button_cancel_.parent(*this);
    button_cancel_.text("Cancel");
    button_cancel_.dialog_result(forms::dialog_result::cancel);
    do_layout();
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

  /// @brief Gets the current position of the progress bar.
  /// @return The position within the range of the progress bar. The default is 0.
  /// @remarks If the value specified is greater than the value of the maximum property, the value property is set to maximum.
  /// @remarks If the value specified is less than the value of the minimum property, the value property is set to minimum.
  /// @remarks The minimum and maximum values of the value property are specified by the minimum and maximum properties. This property enables you to increment or decrement the value of the progress bar directly. To perform consistent increases in the value of the progress_bar control you can use the step property with the perform_step method. To increase the progress bar value by varying amounts, use the increment method.
  virtual int32_t value() {return progress_bar_.value();}
  /// @brief Sets the current position of the progress bar.
  /// @param value The position within the range of the progress bar. The default is 0.
  /// @remarks If the value specified is greater than the value of the maximum property, the value property is set to maximum.
  /// @remarks If the value specified is less than the value of the minimum property, the value property is set to minimum.
  /// @remarks The minimum and maximum values of the value property are specified by the minimum and maximum properties. This property enables you to increment or decrement the value of the progress bar directly. To perform consistent increases in the value of the progress_bar control you can use the step property with the perform_step method. To increase the progress bar value by varying amounts, use the increment method.
  virtual progress_dialog& value(int32_t value) {progress_bar_.value(value); return *this;}

  /// @brief Gets the manner in which progress should be indicated on the progress bar.
  /// @return One of the progress_bar_style values. The default is blocks
  /// @remarks You can use the marquee style when you need to indicate progress is being made, without indicating the quantity of progress. The marquee style is honored only when visual styles are enabled. The continuous style is honored when visual styles are not enabled.
  virtual progress_bar_style style() const {return progress_bar_.style();}
  /// @brief Sets the manner in which progress should be indicated on the progress bar.
  /// @param style One of the progress_bar_style values. The default is blocks
  /// @remarks You can use the marquee style when you need to indicate progress is being made, without indicating the quantity of progress. The marquee style is honored only when visual styles are enabled. The continuous style is honored when visual styles are not enabled.
  virtual progress_dialog& style(progress_bar_style style) {progress_bar_.style(style); return *this;}

  virtual bool cancel_button() const {return cancel_button_;}
  virtual progress_dialog& cancel_button(bool value) {
    if (cancel_button_ != value) {
      cancel_button_ = value;
      do_layout();
    }
    return *this;
  }
  
protected:
  void on_resize(const event_args& e) override {
    do_layout();
    form::on_resize(e);
  }
  
  virtual void do_layout() {
    form_border_style(text_.empty() ? forms::form_border_style::none : forms::form_border_style::fixed_dialog);
    progress_bar_.location({10, (client_size_.height() - progress_bar_.height()) / 2});
    progress_bar_.width(cancel_button_ ? client_size_.width() - 30 - button_cancel_.width()  : client_size_.width() - 20);
    
    close_box(cancel_button_);
    button_cancel_.visible(cancel_button_);
    button_cancel_.location({client_size_.width() - button_cancel_.width() - 10, (client_size_.height() - button_cancel_.height()) / 2});
  }
  
  progress_bar progress_bar_;
  button button_cancel_;
  bool cancel_button_ = false;
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
  
   button btn;
   btn.parent(form_main);
   btn.text("Click me");
   btn.click += [&] {
     progress_dialog progress;
     progress.cancel_button(true);
     progress.style(progress_bar_style::marquee);
     progress.text("Progress");
     progress.maximize_box(true);
     progress.minimize_box(true);
     progress.form_border_style(forms::form_border_style::sizable);
     progress.show_dialog();
  };
  
  application::run(form_main);
}
