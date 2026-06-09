/// @file
/// @brief Contains xtd::forms::progress_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "component.hpp"
#include "dialog_appearance.hpp"
#include "iwin32_window.hpp"
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays progress dialog.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/progress_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                     | macOS                                       | Gnome                                       |
    /// | ----- | ------------------------------------------- | ------------------------------------------- | ------------------------------------------- |
    /// | Light |  @image html dialog_progress_dialog_w.png   |  @image html dialog_progress_dialog_m.png   |  @image html dialog_progress_dialog_g.png   |
    /// | Dark  |  @image html dialog_progress_dialog_wd.png  |  @image html dialog_progress_dialog_md.png  |  @image html dialog_progress_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of progress_dialog dialog.
    /// @include progress_dialog.cpp
    class forms_export_ progress_dialog  final : public xtd::forms::component {
      struct data;
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the progress_dialog class.
      progress_dialog();
      /// @}
      
      /// @cond
      ~progress_dialog();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets whether user has clicked on cancel button.
      /// @return `true` if user has clicked on cancel button; otherwise `false`.
      [[nodiscard]] auto cancelled() const -> bool;
      
      /// @brief Gets the dialog appearance.
      /// @return One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      [[nodiscard]] auto dialog_appearance() const noexcept -> xtd::forms::dialog_appearance;
      /// @brief Sets the dialog appearance.
      /// @param value One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      /// @return Current progress dialog.
      auto dialog_appearance(xtd::forms::dialog_appearance value) -> progress_dialog&;
      
      /// @brief Gets the information texts.
      /// @return The information texts.
      [[nodiscard]] auto informations() const noexcept -> const xtd::array<xtd::string>&;
      /// @brief Sets the information texts.
      /// @param value The information texts.
      /// @return Current progress_dialog instance.
      auto informations(const xtd::array<xtd::string>& value) -> progress_dialog&;
      
      /// @brief Gets a value that Indicates progress by continuously scrolling a block across a progress_bar in a marquee fashion.
      /// @return tree is marquee; otherwise `false`. The default is `false`.
      [[nodiscard]] auto marquee() const noexcept -> bool;
      /// @brief Gets a value that Indicates progress by continuously scrolling a block across a progress_bar in a marquee fashion.
      /// @param value tree is marquee; otherwise `false`. The default is `false`.
      /// @return Current progress_dialog instance.
      auto marquee(bool value) -> progress_dialog&;
      
      /// @brief Gets he time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @return The time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @remarks A marquee-style progress indicator does not display progress; instead it indicates that an operation is occurring by moving the progress block across the progress bar.
      /// @remarks Since the marquee animation speed is a time period, setting the value to a higher number results in a slower speed and a lower number results in a faster speed.
      [[nodiscard]] auto marquee_animation_speed() const noexcept -> xtd::usize;
      /// @brief Sets the time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @param value The time period, in milliseconds, that it takes the progress block to scroll across the progress bar.
      /// @remarks A marquee-style progress indicator does not display progress; instead it indicates that an operation is occurring by moving the progress block across the progress bar.
      /// @remarks Since the marquee animation speed is a time period, setting the value to a higher number results in a slower speed and a lower number results in a faster speed.
      auto marquee_animation_speed(xtd::usize value) -> progress_dialog&;
      
      /// @brief Gets the maximum value of the range of the control.
      /// @return The maximum value of the range. The default is 100.
      /// @remarks This property specifies the upper limit of the value property. When the value of the maximum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the maximum property, the progress bar is completely filled.
      /// @remarks You can use this property to specify a value to which the value property must be set (by setting the value property or using the increment or perform_step methods) to indicate that an operation is complete. For example, you can set the value of the maximum property to the total number of files in a file copy operation. Each time a file is copied, the value property can be increased by 1 until the total number of files is copied. At that point, the progress bar would be completely filled.
      [[nodiscard]] auto maximum() const noexcept -> xtd::int32;
      /// @brief Sets the maximum value of the range of the control.
      /// @param value The maximum value of the range. The default is 100.
      /// @remarks This property specifies the upper limit of the value property. When the value of the maximum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the maximum property, the progress bar is completely filled.
      /// @remarks You can use this property to specify a value to which the value property must be set (by setting the value property or using the increment or perform_step methods) to indicate that an operation is complete. For example, you can set the value of the maximum property to the total number of files in a file copy operation. Each time a file is copied, the value property can be increased by 1 until the total number of files is copied. At that point, the progress bar would be completely filled.
      auto maximum(xtd::int32 value) -> progress_dialog&;
      
      /// @brief Gets the message text.
      /// @return The message text.
      [[nodiscard]] auto message() const noexcept -> const xtd::string&;
      /// @brief Sets the message text.
      /// @param value The message text.
      /// @return Current progress_dialog instance.
      auto message(const xtd::string& value) -> progress_dialog&;
      
      /// @brief Gets the minimum value of the range of the control.
      /// @return The minimum value of the range. The default is 0.
      /// @remarks This property specifies the lower limit of the value property. When the value of the minimum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the minimum property, the progress bar is empty. To change the value of the progress bar, use the step property with the perform_step method, use the increment method, or set the value of the value property directly.
      [[nodiscard]] auto minimum() const noexcept -> xtd::int32;
      /// @brief Sets the minimum value of the range of the control.
      /// @param value The minimum value of the range. The default is 0.
      /// @return Current progress_dialog instance.
      /// @remarks This property specifies the lower limit of the value property. When the value of the minimum property is changed, the progress_bar control is redrawn to reflect the new range of the control. When the value of the value property is equal to the value of the minimum property, the progress bar is empty. To change the value of the progress bar, use the step property with the perform_step method, use the increment method, or set the value of the value property directly.
      auto minimum(xtd::int32 value) -> progress_dialog&;
      
      /// @brief Gets a value that indicates whether cancel button is shown.
      /// @return `true` if cancel button shown; otherwise `false`. By default `false`.
      [[nodiscard]] auto show_cancel_button() const noexcept -> bool;
      /// @brief Sets a value that indicates whether cancel button is shown.
      /// @param value `true` if cancel button is shown; otherwise `false`. By default `false`.
      /// @return Current progress_dialog instance.
      auto show_cancel_button(bool value) -> progress_dialog&;
      
      /// @brief Gets a value that indicates whether elapsed time is shown.
      /// @return `true` if elapsed time is shown; otherwise `false`. By default `false`.
      [[nodiscard]] auto show_elapsed_time() const noexcept -> bool;
      /// @brief Sets a value that indicates whether elapsed time is shown.
      /// @param value `true` if elapsed time is shown; otherwise `false`. By default `false`.
      /// @return Current progress_dialog instance.
      auto show_elapsed_time(bool value) -> progress_dialog&;
      
      /// @brief Gets a value that indicates whether estimated time is shown.
      /// @return `true` if estimated time is shown; otherwise `false`. By default `false`.
      [[nodiscard]] auto show_estimated_time() const noexcept -> bool;
      /// @brief Sets a value that indicates whether estimated time is shown.
      /// @param value `true` if estimated time is shown; otherwise `false`. By default `false`.
      /// @return Current progress_dialog instance.
      auto show_estimated_time(bool value) -> progress_dialog&;
      
      /// @brief Gets a value that indicates whether remaining time is shown.
      /// @return `true` if remaining time is shown; otherwise `false`. By default `false`.
      [[nodiscard]] auto show_remaining_time() const noexcept -> bool;
      /// @brief Sets a value that indicates whether remaining time is shown.
      /// @param value `true` if remaining time is shown; otherwise `false`. By default `false`.
      /// @return Current progress_dialog instance.
      auto show_remaining_time(bool value) -> progress_dialog&;
      
      /// @brief Gets a value that indicates whether skip button is shown.
      /// @return `true` if skip button shown; otherwise `false`. By default `false`.
      [[nodiscard]] auto show_skip_button() const noexcept -> bool;
      /// @brief Sets a value that indicates whether skip button is shown.
      /// @param value `true` if skip button is shown; otherwise `false`. By default `false`.
      /// @return Current progress_dialog instance.
      auto show_skip_button(bool value) -> progress_dialog&;
      
      /// @brief Gets whether user has clicked on skip button.
      /// @return `true` if user has clicked on skip button; otherwise `false`.
      [[nodiscard]] auto skipped() const -> bool;
      
      /// @brief Gets the amount by which a call to the PerformStep() method increases the current position of the progress bar.
      /// @return The amount by which to increment the progress bar with each call to the perform_step() method. The default is 10.
      /// @remarks You can use the step property to specify the amount that each completed task in an operation changes the value of the progress bar. For example, if you are copying a group of files, you might want to set the value of the step property to 1 and the value of the maximum property to the total number of files to copy. When each file is copied, you can call the perform_step method to increment the progress bar by the value of the step property. If you want to have more flexible control of the value of the progress bar, you can use the increment method or set the value of the value property directly.
      [[nodiscard]] auto step() const noexcept -> xtd::int32;
      /// @brief Sets the amount by which a call to the PerformStep() method increases the current position of the progress bar.
      /// @param value The amount by which to increment the progress bar with each call to the perform_step() method. The default is 10.
      /// @remarks You can use the step property to specify the amount that each completed task in an operation changes the value of the progress bar. For example, if you are copying a group of files, you might want to set the value of the step property to 1 and the value of the maximum property to the total number of files to copy. When each file is copied, you can call the perform_step method to increment the progress bar by the value of the step property. If you want to have more flexible control of the value of the progress bar, you can use the increment method or set the value of the value property directly.
      auto step(xtd::int32 value) -> progress_dialog&;
      
      /// @brief Gets the dialog title.
      /// @return The dialog title.
      [[nodiscard]] auto text() const noexcept -> const xtd::string&;
      /// @brief Sets the dialog title.
      /// @param value The dialog title.
      /// @return Current progress_dialog instance.
      auto text(const xtd::string& value) -> progress_dialog&;
      
      /// @brief Gets the current position of the progress bar.
      /// @return The position within the range of the progress bar. The default is 0.
      /// @remarks If the value specified is greater than the value of the maximum property, the value property is set to maximum.
      /// @remarks If the value specified is less than the value of the minimum property, the value property is set to minimum.
      /// @remarks The minimum and maximum values of the value property are specified by the minimum and maximum properties. This property enables you to increment or decrement the value of the progress bar directly. To perform consistent increases in the value of the progress_bar control you can use the step property with the perform_step method. To increase the progress bar value by varying amounts, use the increment method.
      [[nodiscard]] auto value() const noexcept -> xtd::int32;
      /// @brief Sets the current position of the progress bar.
      /// @param value The position within the range of the progress bar. The default is 0.
      /// @remarks If the value specified is greater than the value of the maximum property, the value property is set to maximum.
      /// @remarks If the value specified is less than the value of the minimum property, the value property is set to minimum.
      /// @remarks The minimum and maximum values of the value property are specified by the minimum and maximum properties. This property enables you to increment or decrement the value of the progress bar directly. To perform consistent increases in the value of the progress_bar control you can use the step property with the perform_step method. To increase the progress bar value by varying amounts, use the increment method.
      auto value(xtd::int32 value) -> progress_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Hides progress dialog box.
      auto hide() -> void;
      
      /// @brief Advances the current position of the progress bar by the specified amount.
      /// @param increment The amount by which to increment the progress bar's current position.
      /// @remarks The increment method enables you to increment the value of the progress bar by a specific amount. This method of incrementing the progress bar is similar to using the step property with the perform_step method. The value property specifies the current position of the progress_bar. If, after calling the increment method, the value property is greater than the value of the maximum property, the value property remains at the value of the maximum property. If, after calling the increment method with a negative value specified in the value parameter, the Value property is less than the value of the minimum property, the value property remains at the value of the minimum property.
      /// @remarks Because a progress_bar object whose style is set to marquee displays a continuously scrolling bar instead of its value, calling increment is unnecessary and will do nothing.
      auto increment(xtd::int32 increment) -> void;
      
      /// @brief Advances the current position of the progress bar by the amount of the Step property.
      /// @remarks The perform_step method increments the value of the progress bar by the amount specified by the step property. You can use the Step property to specify the amount that each completed task in an operation changes the value of the progress bar. For example, if you are copying a group of files, you might want to set the value of the step property to 1 and the value of the maximum property to the total number of files to copy. When each file is copied, you can call the perform_step method to increment the progress bar by the value of the step property. If you want to have more flexible control of the value of the progress bar, you can use the increment method or set the value of the value property directly.
      auto perform_step() -> void;
      
      /// @brief Resets all properties to empty string.
      auto reset() noexcept -> void;
      
      /// @brief Resume progress dialog box after Abort button clicked.
      auto resume() -> void;
      
      /// @brief Runs progress dialog box.
      auto show() -> void;
      /// @brief Runs progress dialog box with specified owner.
      /// @param owner The progress dialog owner.
      auto show(const xtd::forms::iwin32_window& owner) -> void;
      
      /// @brief Runs progress dialog box as sheet with specified owner.
      /// @param owner The progress dialog owner.
      auto show_sheet(const xtd::forms::iwin32_window& owner) -> void;
      
      /// @brief Runs progress dialog box.
      auto show_dialog() -> void;
      /// @brief Runs progress dialog box with specified owner.
      /// @param owner The progress dialog owner.
      auto show_dialog(const xtd::forms::iwin32_window& owner) -> void;
      /// @brief Runs progress dialog box with specified owner.
      /// @param owner The progress dialog owner.
      auto show_sheet_dialog(const xtd::forms::iwin32_window& owner) -> void;
      /// @}
      
    private:
      auto get_option(xtd::usize flag) const noexcept -> bool;
      auto set_option(xtd::usize flag, bool value) -> void;
      auto recreate_dialog() -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
