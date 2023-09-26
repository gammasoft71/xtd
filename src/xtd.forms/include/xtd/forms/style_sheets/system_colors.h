/// @file
/// @brief Contains xtd::forms::style_sheets::system_colors class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export"
#include <xtd/drawing/color>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <memory>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The theme data allows you to specify the theme informations.
      /// @code
      /// class forms_export_ system_colors : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::system_colors
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/system_colors> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ system_colors : public xtd::iequatable<system_colors>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::system_colors class.
        system_colors() = default;
        /// @}
        
        /// @cond
        system_colors(const system_colors&) = default;
        system_colors(system_colors&&) = default;
        system_colors& operator =(const system_colors&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the accent system color;
        /// @return The accent system color.
        const xtd::drawing::color& accent() const noexcept;
        /// @brief Sets the accent system color;
        /// @param value The accent system color.
        void accent(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the accent text system color;
        /// @return The accent text system color.
        const xtd::drawing::color& accent_text() const noexcept;
        /// @brief Sets the accent text system color;
        /// @param value The accent text system color.
        void accent_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the active border system color;
        /// @return The active border system color.
        const xtd::drawing::color& active_border() const noexcept;
        /// @brief Sets the active border system color;
        /// @param value The active border system color.
        void active_border(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the active caption system color;
        /// @return The active caption system color.
        const xtd::drawing::color& active_caption() const noexcept;
        /// @brief Sets the active caption system color;
        /// @param value The active caption system color.
        void active_caption(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the active caption text system color;
        /// @return The active caption text system color.
        const xtd::drawing::color& active_caption_text() const noexcept;
        /// @brief Sets the active caption text system color;
        /// @param value The active caption text system color.
        void active_caption_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the text color of an html link text when mouse down.
        /// @return The text color of an html link text when mouse down.
        const xtd::drawing::color& active_text() const noexcept;
        /// @brief Sets the text color of an html link text when mouse down.
        /// @param value The text color of an html link text when mouse down.
        void active_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the app workspace system color;
        /// @return The app workspace system color.
        const xtd::drawing::color& app_workspace() const noexcept;
        /// @brief Sets the app workspace system color;
        /// @param value The app workspace system color.
        void app_workspace(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the button face system color;
        /// @return The button face system color.
        const xtd::drawing::color& button_face() const noexcept;
        /// @brief Sets the button face system color;
        /// @param value The button face system color.
        void button_face(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the button highlight system color;
        /// @return The button highlight system color.
        const xtd::drawing::color& button_highlight() const noexcept;
        /// @brief Sets the button highlight system color;
        /// @param value The button highlight system color.
        void button_highlight(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the button shadow system color;
        /// @return The button shadow system color.
        const xtd::drawing::color& button_shadow() const noexcept;
        /// @brief Sets the button shadow system color;
        /// @param value The button shadow system color.
        void button_shadow(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the control system color;
        /// @return The control system color.
        const xtd::drawing::color& control() const noexcept;
        /// @brief Sets the control system color;
        /// @param value The control system color.
        void control(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the control dark system color;
        /// @return The control dark system color.
        const xtd::drawing::color& control_dark() const noexcept;
        /// @brief Sets the control dark system color;
        /// @param value The control dark system color.
        void control_dark(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the control dark dark system color;
        /// @return The control dark dark system color.
        const xtd::drawing::color& control_dark_dark() const noexcept;
        /// @brief Sets the control dark dark system color;
        /// @param value The control dark dark system color.
        void control_dark_dark(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the control light system color;
        /// @return The control light system color.
        const xtd::drawing::color& control_light() const noexcept;
        /// @brief Sets the control light system color;
        /// @param value The control light system color.
        void control_light(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the control light light system color;
        /// @return The control light light system color.
        const xtd::drawing::color& control_light_light() const noexcept;
        /// @brief Sets the control light light system color;
        /// @param value The control light light system color.
        void control_light_light(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the control text system color;
        /// @return The control text system color.
        const xtd::drawing::color& control_text() const noexcept;
        /// @brief Sets the control text system color;
        /// @param value The control text system color.
        void control_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the desktop system color;
        /// @return The desktop system color.
        const xtd::drawing::color& desktop() const noexcept;
        /// @brief Sets the desktop system color;
        /// @param value The desktop system color.
        void desktop(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the gradient active caption system color;
        /// @return The gradient active caption system color.
        const xtd::drawing::color& gradient_active_caption() const noexcept;
        /// @brief Sets the gradient active caption system color;
        /// @param value The gradient active caption system color.
        void gradient_active_caption(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the gradient inactive caption system color;
        /// @return The gradient inactive caption system color.
        const xtd::drawing::color& gradient_inactive_caption() const noexcept;
        /// @brief Sets the gradient inactive caption system color;
        /// @param value The gradient inactive caption system color.
        void gradient_inactive_caption(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the gray text system color;
        /// @return The gray text system color.
        const xtd::drawing::color& gray_text() const noexcept;
        /// @brief Sets the gray text system color;
        /// @param value The gray text system color.
        void gray_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the highlight system color;
        /// @return The highlight system color.
        const xtd::drawing::color& highlight() const noexcept;
        /// @brief Sets the highlight system color;
        /// @param value The highlight system color.
        void highlight(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the highlight text system color;
        /// @return The highlight text system color.
        const xtd::drawing::color& highlight_text() const noexcept;
        /// @brief Sets the highlight text system color;
        /// @param value The highlight text system color.
        void highlight_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the hot track system color;
        /// @return The hot track system color.
        const xtd::drawing::color& hot_track() const noexcept;
        /// @brief Sets the hot track system color;
        /// @param value The hot track system color.
        void hot_track(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the inactive border system color;
        /// @return The inactive border system color.
        const xtd::drawing::color& inactive_border() const noexcept;
        /// @brief Sets the inactive border system color;
        /// @param value The inactive border system color.
        void inactive_border(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the inactive caption system color;
        /// @return The inactive caption system color.
        const xtd::drawing::color& inactive_caption() const noexcept;
        /// @brief Sets the inactive caption system color;
        /// @param value The inactive caption system color.
        void inactive_caption(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the inactive caption text system color;
        /// @return The inactive caption text system color.
        const xtd::drawing::color& inactive_caption_text() const noexcept;
        /// @brief Sets the inactive caption text system color;
        /// @param value The inactive caption text system color.
        void inactive_caption_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the info system color;
        /// @return The info system color.
        const xtd::drawing::color& info() const noexcept;
        /// @brief Sets the info system color;
        /// @param value The info system color.
        void info(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the info text system color;
        /// @return The info text system color.
        const xtd::drawing::color& info_text() const noexcept;
        /// @brief Sets the info text system color;
        /// @param value The info text system color.
        void info_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the text color of an html link text.
        /// @return The text color of an html link text.
        const xtd::drawing::color& link_text() const noexcept;
        /// @brief Sets the text color of an html link text.
        /// @param value The text color of an html link text.
        void link_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the menu system color;
        /// @return The menu system color.
        const xtd::drawing::color& menu() const noexcept;
        /// @brief Sets the menu system color;
        /// @param value The menu system color.
        void menu(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the menu bar system color;
        /// @return The menu bar system color.
        const xtd::drawing::color& menu_bar() const noexcept;
        /// @brief Sets the menu bar system color;
        /// @param value The menu bar system color.
        void menu_bar(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the menu highlight system color;
        /// @return The menu highlight system color.
        const xtd::drawing::color& menu_highlight() const noexcept;
        /// @brief Sets the menu highlight system color;
        /// @param value The menu highlight system color.
        void menu_highlight(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the menu text system color;
        /// @return The menu text system color.
        const xtd::drawing::color& menu_text() const noexcept;
        /// @brief Sets the menu text system color;
        /// @param value The menu text system color.
        void menu_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the scroll bar system color;
        /// @return The scroll bar system color.
        const xtd::drawing::color& scroll_bar() const noexcept;
        /// @brief Sets the scroll bar system color;
        /// @param value The scroll bar system color.
        void scroll_bar(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the shadow text system color;
        /// @return The shadow text system color.
        const xtd::drawing::color& shadow_text() const noexcept;
        /// @brief Sets the shadow text system color;
        /// @param value The shadow text system color.
        void shadow_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the text box system color;
        /// @return The text box system color.
        const xtd::drawing::color& text_box() const noexcept;
        /// @brief Sets the text box system color;
        /// @param value The text box system color.
        void text_box(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the text box text system color;
        /// @return The text box text system color.
        const xtd::drawing::color& text_box_text() const noexcept;
        /// @brief Sets the text box text system color;
        /// @param value The text box text system color.
        void text_box_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the text color of an html visited link text.
        /// @return The text color of an html visited link text.
        const xtd::drawing::color& visited_text() const noexcept;
        /// @brief Sets the text color of an html visited link text.
        /// @param value The text color of an html visited link text.
        void visited_text(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the window system color;
        /// @return The window system color.
        const xtd::drawing::color& window() const noexcept;
        /// @brief Sets the window system color;
        /// @param value The window system color.
        void window(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the window frame system color;
        /// @return The window frame system color.
        const xtd::drawing::color& window_frame() const noexcept;
        /// @brief Sets the window frame system color;
        /// @param value The window frame system color.
        void window_frame(const xtd::drawing::color& value) noexcept;
        
        /// @brief Gets the window text system color;
        /// @return The window text system color.
        const xtd::drawing::color& window_text() const noexcept;
        /// @brief Sets the window text system color;
        /// @param value The window text system color.
        void window_text(const xtd::drawing::color& value) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const system_colors& other) const noexcept override;
        /// @}
        
      private:
        xtd::drawing::color accent_;
        xtd::drawing::color accent_text_;
        xtd::drawing::color active_border_;
        xtd::drawing::color active_caption_;
        xtd::drawing::color active_caption_text_;
        xtd::drawing::color active_text_;
        xtd::drawing::color app_workspace_;
        xtd::drawing::color button_face_;
        xtd::drawing::color button_highlight_;
        xtd::drawing::color button_shadow_;
        xtd::drawing::color control_;
        xtd::drawing::color control_dark_;
        xtd::drawing::color control_dark_dark_;
        xtd::drawing::color control_light_;
        xtd::drawing::color control_light_light_;
        xtd::drawing::color control_text_;
        xtd::drawing::color desktop_;
        xtd::drawing::color gradient_active_caption_;
        xtd::drawing::color gradient_inactive_caption_;
        xtd::drawing::color gray_text_;
        xtd::drawing::color highlight_;
        xtd::drawing::color highlight_text_;
        xtd::drawing::color hot_track_;
        xtd::drawing::color inactive_border_;
        xtd::drawing::color inactive_caption_;
        xtd::drawing::color inactive_caption_text_;
        xtd::drawing::color info_;
        xtd::drawing::color info_text_;
        xtd::drawing::color link_text_;
        xtd::drawing::color menu_;
        xtd::drawing::color menu_bar_;
        xtd::drawing::color menu_highlight_;
        xtd::drawing::color menu_text_;
        xtd::drawing::color scroll_bar_;
        xtd::drawing::color shadow_text_;
        xtd::drawing::color text_box_;
        xtd::drawing::color text_box_text_;
        xtd::drawing::color visited_text_;
        xtd::drawing::color window_;
        xtd::drawing::color window_frame_;
        xtd::drawing::color window_text_;
      };
    }
  }
}
