/// @file
/// @brief Contains xtd::forms::progress_dialog dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>
#include <xtd/forms/progress_dialog_flags.h>
#include "component.h"
#include "dialog_style.h"
#include "iwin32_window.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays progress box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of progress_dialog dialog.
    /// @include progress_dialog.cpp
    class forms_export_ progress_dialog  final : public component {
    public:
      /// @brief Initializes a new instance of the progress_dialog class.
      progress_dialog() = default;
      ~progress_dialog() {hide();}
      
      /// @brief Gets whether user has clicked on cancel butttoon.
      /// @return true if user has clicked on cancel button; otherwise false.
      bool cancelled() const;

      /// @brief Gets whether user has clicked on skip butttoon.
      /// @return true if user has clicked on skip button; otherwise false.
      bool skipped() const;
      
      /// @brief Gets the dialog style.
      /// @return One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      xtd::forms::dialog_style dialog_style() const {return dialog_style_;}
      /// @brief Sets the dialog style.
      /// @param dialog_style One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      /// @return Current progress dialog.
      progress_dialog& dialog_style(xtd::forms::dialog_style dialog_style) {
        if (dialog_style_ != dialog_style) {
          dialog_style_ = dialog_style;
          recreate_dialog();
        }
        return *this;
      }
      
      /// @brief Gets the information texts.
      /// @return The information texts.
      const std::vector<xtd::ustring>& informations() const {return informations_;}
      /// @brief Sets the information texts.
      /// @param informations The information texts.
      /// @return Current progress_dialog instance.
      progress_dialog& informations(const std::vector<xtd::ustring>& informations);

      /// @brief Gets a value that Indicates progress by continuously scrolling a block across a progress_bar in a marquee fashion.
      /// @return truee is marquee; otherwise false. The default is false.
      bool marquee() const {return get_option(PROGDLG_MARQUEEPROGRESS);}
      /// @brief Gets a value that Indicates progress by continuously scrolling a block across a progress_bar in a marquee fashion.
      /// @param marquee truee is marquee; otherwise false. The default is false.
      /// @return Current progress_dialog instance.
      progress_dialog& marquee(bool marquee);
      
      /// @brief Gets he time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @return The time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @remarks A marquee-style progress indicator does not display progress; instead it indicates that an operation is occurring by moving the progress block across the progress bar.
      /// @remarks Since the marquee animation speed is a time period, setting the value to a higher number results in a slower speed and a lower number results in a faster speed.
      size_t marquee_animation_speed() {return marquee_animation_speed_;}
      /// @brief Sets the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param marquee_animation_speed The time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @remarks A marquee-style progress indicator does not display progress; instead it indicates that an operation is occurring by moving the progress block across the progress bar.
      /// @remarks Since the marquee animation speed is a time period, setting the value to a higher number results in a slower speed and a lower number results in a faster speed.
      progress_dialog& marquee_animation_speed(size_t marquee_animation_speed);

      /// @brief Gets the maximum value of the range of the control.
      /// @return The maximum value of the range. The default is 100.
      /// @remarks This property specifies the upper limit of the value property. When the value of the maximum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the maximum property, the progress bar is completely filled.
      /// @remarks You can use this property to specify a value to which the value property must be set (by setting the value property or using the increment or perform_step methods) to indicate that an operation is complete. For example, you can set the value of the maximum property to the total number of files in a file copy operation. Each time a file is copied, the value property can be increased by 1 until the total number of files is copied. At that point, the progress bar would be completely filled.
      int32_t maximum() {return maximum_;}
      /// @brief Sets the maximum value of the range of the control.
      /// @param maximum The maximum value of the range. The default is 100.
      /// @remarks This property specifies the upper limit of the value property. When the value of the maximum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the maximum property, the progress bar is completely filled.
      /// @remarks You can use this property to specify a value to which the value property must be set (by setting the value property or using the increment or perform_step methods) to indicate that an operation is complete. For example, you can set the value of the maximum property to the total number of files in a file copy operation. Each time a file is copied, the value property can be increased by 1 until the total number of files is copied. At that point, the progress bar would be completely filled.
      progress_dialog& maximum(int32_t maximum);
      
      /// @brief Gets the message text.
      /// @return The message text.
      const xtd::ustring& message() const {return message_;}
      /// @brief Sets the message text.
      /// @param description The message text.
      /// @return Current progress_dialog instance.
      progress_dialog& message(const xtd::ustring& message);
      
      /// @brief Gets the minimum value of the range of the control.
      /// @return The minimum value of the range. The default is 0.
      /// @remarks This property specifies the lower limit of the value property. When the value of the minimum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the minimum property, the progress bar is empty. To change the value of the progress bar, use the step property with the perform_step method, use the increment method, or set the value of the value property directly.
      int32_t minimum() {return minimum_;}
      /// @brief Sets the minimum value of the range of the control.
      /// @param minimum The minimum value of the range. The default is 0.
      /// @return Current progress_dialog instance.
      /// @remarks This property specifies the lower limit of the value property. When the value of the minimum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the minimum property, the progress bar is empty. To change the value of the progress bar, use the step property with the perform_step method, use the increment method, or set the value of the value property directly.
      progress_dialog& minimum(int32_t minimum);

      /// @brief Resume progress dialog box after Abort button clicked.
      void resume();

      /// @brief Gets a value that indicates whether cancel button is shown.
      /// @return true if cancel button shown; otherwise false. By default false.
      bool show_cancel_button() const {return !get_option(PROGDLG_NOCANCEL);}
      /// @brief Sets a value that indicates whether cancel button is shown.
      /// @param show_cancel_button true if cancel button is shown; otherwise false. By default false.
      /// @return Current progress_dialog instance.
      progress_dialog& show_cancel_button(bool show_cancel_button);
      
      /// @brief Gets a value that indicates whether ealapsed time is shown.
      /// @return true if elapsed time is shown; otherwise false. By default false.
      bool show_elapsed_time() const {return !get_option(PROGDLG_ELAPSEDTIME);}
      /// @brief Sets a value that indicates whether elapsed time is shown.
      /// @param show_elapsed_time true if elapsed time is shown; otherwise false. By default false.
      /// @return Current progress_dialog instance.
      progress_dialog& show_elapsed_time(bool show_elapsed_time);
      
      /// @brief Gets a value that indicates whether estimated time is shown.
      /// @return true if estimated time is shown; otherwise false. By default false.
      bool show_estimated_time() const {return !get_option(PROGDLG_ESTIMATEDTIME);}
      /// @brief Sets a value that indicates whether estimated time is shown.
      /// @param show_estimated_time true if estimated time is shown; otherwise false. By default false.
      /// @return Current progress_dialog instance.
      progress_dialog& show_estimated_time(bool show_estimated_time);

      /// @brief Gets a value that indicates whether remaining time is shown.
      /// @return true if remaining time is shown; otherwise false. By default false.
      bool show_remaining_time() const {return !get_option(PROGDLG_AUTOTIME);}
      /// @brief Sets a value that indicates whether remaining time is shown.
      /// @param show_remaining_time true if remaining time is shown; otherwise false. By default false.
      /// @return Current progress_dialog instance.
      progress_dialog& show_remaining_time(bool show_remaining_time);

      /// @brief Gets a value that indicates whether skip button is shown.
      /// @return true if skipv button shown; otherwise false. By default false.
      bool show_skip_button() const {return !get_option(PROGDLG_NOSKIP);}
      /// @brief Sets a value that indicates whether skip button is shown.
      /// @param show_skip_button true if skip button is shown; otherwise false. By default false.
      /// @return Current progress_dialog instance.
      progress_dialog& show_skip_button(bool show_skip_button);

      /// @brief Gets the amount by which a call to the PerformStep() method increases the current position of the progress bar.
      /// @return The amount by which to increment the progress bar with each call to the perform_step() method. The default is 10.
      /// @remarks You can use the step property to specify the amount that each completed task in an operation changes the value of the progress bar. For example, if you are copying a group of files, you might want to set the value of the step property to 1 and the value of the maximum property to the total number of files to copy. When each file is copied, you can call the perform_step method to increment the progress bar by the value of the step property. If you want to have more flexible control of the value of the progress bar, you can use the increment method or set the value of the value property directly.
      virtual int32_t step() {return step_;}
      /// @brief Sets the amount by which a call to the PerformStep() method increases the current position of the progress bar.
      /// @param step The amount by which to increment the progress bar with each call to the perform_step() method. The default is 10.
      /// @remarks You can use the step property to specify the amount that each completed task in an operation changes the value of the progress bar. For example, if you are copying a group of files, you might want to set the value of the step property to 1 and the value of the maximum property to the total number of files to copy. When each file is copied, you can call the perform_step method to increment the progress bar by the value of the step property. If you want to have more flexible control of the value of the progress bar, you can use the increment method or set the value of the value property directly.
      virtual progress_dialog& step(int32_t step);

      /// @brief Gets the dialog title.
      /// @return The dialog title.
      const xtd::ustring& text() const {return text_;}
      /// @brief Sets the dialog title.
      /// @param copyright The dialog title.
      /// @return Current progress_dialog instance.
      progress_dialog& text(const xtd::ustring& text) {
        if (text_ != text) {
          text_ = text;
          recreate_dialog();
        }
        return *this;
      }

      /// @brief Gets the current position of the progress bar.
      /// @return The position within the range of the progress bar. The default is 0.
      /// @remarks If the value specified is greater than the value of the maximum property, the value property is set to maximum.
      /// @remarks If the value specified is less than the value of the minimum property, the value property is set to minimum.
      /// @remarks The minimum and maximum values of the value property are specified by the minimum and maximum properties. This property enables you to increment or decrement the value of the progress bar directly. To perform consistent increases in the value of the progress_bar control you can use the step property with the perform_step method. To increase the progress bar value by varying amounts, use the increment method.
      int32_t value() {return value_;}
      /// @brief Sets the current position of the progress bar.
      /// @param value The position within the range of the progress bar. The default is 0.
      /// @remarks If the value specified is greater than the value of the maximum property, the value property is set to maximum.
      /// @remarks If the value specified is less than the value of the minimum property, the value property is set to minimum.
      /// @remarks The minimum and maximum values of the value property are specified by the minimum and maximum properties. This property enables you to increment or decrement the value of the progress bar directly. To perform consistent increases in the value of the progress_bar control you can use the step property with the perform_step method. To increase the progress bar value by varying amounts, use the increment method.
      progress_dialog& value(int32_t value);

      /// @brief Hides progress dialog box.
      void hide();

      /// @brief Advances the current position of the progress bar by the specified amount.
      /// @param increment The amount by which to increment the progress bar's current position.
      /// @remarks The increment method enables you to increment the value of the progress bar by a specific amount. This method of incrementing the progress bar is similar to using the step property with the perform_step method. The value property specifies the current position of the progress_bar. If, after calling the increment method, the value property is greater than the value of the maximum property, the value property remains at the value of the maximum property. If, after calling the increment method with a negative value specified in the value parameter, the Value property is less than the value of the minimum property, the value property remains at the value of the minimum property.
      /// @remarks Because a progress_bar object whose style is set to marquee displays a continuously scrolling bar instead of its value, calling increment is unnecessary and will do nothing.
      void increment(int32_t increment) {value(value_ + increment);}
      
      /// @brief Advances the current position of the progress bar by the amount of the Step property.
      /// @remarks The perform_step method increments the value of the progress bar by the amount specified by the step property. You can use the Step property to specify the amount that each completed task in an operation changes the value of the progress bar. For example, if you are copying a group of files, you might want to set the value of the step property to 1 and the value of the maximum property to the total number of files to copy. When each file is copied, you can call the perform_step method to increment the progress bar by the value of the step property. If you want to have more flexible control of the value of the progress bar, you can use the increment method or set the value of the value property directly.
      void perform_step() {increment(step());}

      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs progress dialog box.
      void show();
      /// @brief Runs progress dialog box.
      void show(const iwin32_window& owner);
      
      /// @brief Runs progress dialog box as sheet.
      void show_sheet(const iwin32_window& owner);
      
      /// @brief Runs progress dialog box.
      void show_dialog();
      /// @brief Runs progress dialog box.
      void show_dialog(const iwin32_window& owner);
      /// @brief Runs progress dialog box.
      void show_sheet_dialog(const iwin32_window& owner);

    private:
      bool get_option(size_t flag) const {return (options_ & flag) == flag;}
      void set_option(size_t flag, bool value) {options_ = value ? options_ | flag : options_ & ~flag;}
      void recreate_dialog();
      
      xtd::forms::dialog_style dialog_style_ = xtd::forms::dialog_style::system;
      intptr_t handle_ = 0;
      std::vector<xtd::ustring> informations_;
      size_t marquee_animation_speed_ = 100;
      int32_t maximum_ = 100;
      xtd::ustring message_;
      int32_t minimum_ = 0;
      bool native_ = false;
      size_t options_ = PROGDLG_NORMAL|PROGDLG_NOCANCEL|PROGDLG_NOSKIP;
      const iwin32_window* owner_ = nullptr;
      int32_t step_ = 10;
      xtd::ustring text_;
      int32_t value_ = 0;
    };
  }
}
