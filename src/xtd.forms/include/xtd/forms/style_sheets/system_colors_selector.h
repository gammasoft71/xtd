/// @file
/// @brief Contains xtd::forms::style_sheets::system_colors_selector class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include <xtd/iequatable.h>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../../forms_export.h"
#include "color_property.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The theme data allows you to specify the theme informations.
      /// @code
      /// class forms_export_ system_colors_selector : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::system_colors_selector
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ system_colors_selector : public xtd::iequatable<system_colors_selector>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::system_colors_selector class.
        system_colors_selector() = default;
        /// @}

        /// @cond
        system_colors_selector(const system_colors_selector&) = default;
        system_colors_selector(system_colors_selector&&) = default;
        system_colors_selector& operator=(const system_colors_selector&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the accent system color;
        /// @return The accent system color.
        const color_property& accent() const noexcept;
        /// @brief Sets the accent system color;
        /// @param value The accent system color.
        void accent(const color_property& value) noexcept;

        /// @brief Gets the accent text system color;
        /// @return The accent text system color.
        const color_property& accent_text() const noexcept;
        /// @brief Sets the accent text system color;
        /// @param value The accent text system color.
        void accent_text(const color_property& value) noexcept;

        /// @brief Gets the active border system color;
        /// @return The active border system color.
        const color_property& active_border() const noexcept;
        /// @brief Sets the active border system color;
        /// @param value The active border system color.
        void active_border(const color_property& value) noexcept;

        /// @brief Gets the active caption system color;
        /// @return The active caption system color.
        const color_property& active_caption() const noexcept;
        /// @brief Sets the active caption system color;
        /// @param value The active caption system color.
        void active_caption(const color_property& value) noexcept;

        /// @brief Gets the active caption text system color;
        /// @return The active caption text system color.
        const color_property& active_caption_text() const noexcept;
        /// @brief Sets the active caption text system color;
        /// @param value The active caption text system color.
        void active_caption_text(const color_property& value) noexcept;

        /// @brief Gets the app workspace system color;
        /// @return The app workspace system color.
        const color_property& app_workspace() const noexcept;
        /// @brief Sets the app workspace system color;
        /// @param value The app workspace system color.
        void app_workspace(const color_property& value) noexcept;

        /// @brief Gets the button face system color;
        /// @return The button face system color.
        const color_property& button_face() const noexcept;
        /// @brief Sets the button face system color;
        /// @param value The button face system color.
        void button_face(const color_property& value) noexcept;

        /// @brief Gets the button highlight system color;
        /// @return The button highlight system color.
        const color_property& button_highlight() const noexcept;
        /// @brief Sets the button highlight system color;
        /// @param value The button highlight system color.
        void button_highlight(const color_property& value) noexcept;

        /// @brief Gets the button shadow system color;
        /// @return The button shadow system color.
        const color_property& button_shadow() const noexcept;
        /// @brief Sets the button shadow system color;
        /// @param value The button shadow system color.
        void button_shadow(const color_property& value) noexcept;

        /// @brief Gets the control system color;
        /// @return The control system color.
        const color_property& control() const noexcept;
        /// @brief Sets the control system color;
        /// @param value The control system color.
        void control(const color_property& value) noexcept;

        /// @brief Gets the control dark system color;
        /// @return The control dark system color.
        const color_property& control_dark() const noexcept;
        /// @brief Sets the control dark system color;
        /// @param value The control dark system color.
        void control_dark(const color_property& value) noexcept;

        /// @brief Gets the control dark dark system color;
        /// @return The control dark dark system color.
        const color_property& control_dark_dark() const noexcept;
        /// @brief Sets the control dark dark system color;
        /// @param value The control dark dark system color.
        void control_dark_dark(const color_property& value) noexcept;

        /// @brief Gets the control light system color;
        /// @return The control light system color.
        const color_property& control_light() const noexcept;
        /// @brief Sets the control light system color;
        /// @param value The control light system color.
        void control_light(const color_property& value) noexcept;

        /// @brief Gets the control light light system color;
        /// @return The control light light system color.
        const color_property& control_light_light() const noexcept;
        /// @brief Sets the control light light system color;
        /// @param value The control light light system color.
        void control_light_light(const color_property& value) noexcept;

        /// @brief Gets the control text system color;
        /// @return The control text system color.
        const color_property& control_text() const noexcept;
        /// @brief Sets the control text system color;
        /// @param value The control text system color.
        void control_text(const color_property& value) noexcept;

        /// @brief Gets the desktop system color;
        /// @return The desktop system color.
        const color_property& desktop() const noexcept;
        /// @brief Sets the desktop system color;
        /// @param value The desktop system color.
        void desktop(const color_property& value) noexcept;

        /// @brief Gets the gradient active caption system color;
        /// @return The gradient active caption system color.
        const color_property& gradient_active_caption() const noexcept;
        /// @brief Sets the gradient active caption system color;
        /// @param value The gradient active caption system color.
        void gradient_active_caption(const color_property& value) noexcept;

        /// @brief Gets the gradient inactive caption system color;
        /// @return The gradient inactive caption system color.
        const color_property& gradient_inactive_caption() const noexcept;
        /// @brief Sets the gradient inactive caption system color;
        /// @param value The gradient inactive caption system color.
        void gradient_inactive_caption(const color_property& value) noexcept;

        /// @brief Gets the gray text system color;
        /// @return The gray text system color.
        const color_property& gray_text() const noexcept;
        /// @brief Sets the gray text system color;
        /// @param value The gray text system color.
        void gray_text(const color_property& value) noexcept;

        /// @brief Gets the highlight system color;
        /// @return The highlight system color.
        const color_property& highlight() const noexcept;
        /// @brief Sets the highlight system color;
        /// @param value The highlight system color.
        void highlight(const color_property& value) noexcept;

        /// @brief Gets the highlight text system color;
        /// @return The highlight text system color.
        const color_property& highlight_text() const noexcept;
        /// @brief Sets the highlight text system color;
        /// @param value The highlight text system color.
        void highlight_text(const color_property& value) noexcept;

        /// @brief Gets the hot track system color;
        /// @return The hot track system color.
        const color_property& hot_track() const noexcept;
        /// @brief Sets the hot track system color;
        /// @param value The hot track system color.
        void hot_track(const color_property& value) noexcept;

        /// @brief Gets the inactive border system color;
        /// @return The inactive border system color.
        const color_property& inactive_border() const noexcept;
        /// @brief Sets the inactive border system color;
        /// @param value The inactive border system color.
        void inactive_border(const color_property& value) noexcept;

        /// @brief Gets the inactive caption system color;
        /// @return The inactive caption system color.
        const color_property& inactive_caption() const noexcept;
        /// @brief Sets the inactive caption system color;
        /// @param value The inactive caption system color.
        void inactive_caption(const color_property& value) noexcept;

        /// @brief Gets the inactive caption text system color;
        /// @return The inactive caption text system color.
        const color_property& inactive_caption_text() const noexcept;
        /// @brief Sets the inactive caption text system color;
        /// @param value The inactive caption text system color.
        void inactive_caption_text(const color_property& value) noexcept;

        /// @brief Gets the info system color;
        /// @return The info system color.
        const color_property& info() const noexcept;
        /// @brief Sets the info system color;
        /// @param value The info system color.
        void info(const color_property& value) noexcept;

        /// @brief Gets the info text system color;
        /// @return The info text system color.
        const color_property& info_text() const noexcept;
        /// @brief Sets the info text system color;
        /// @param value The info text system color.
        void info_text(const color_property& value) noexcept;

        /// @brief Gets the menu system color;
        /// @return The menu system color.
        const color_property& menu() const noexcept;
        /// @brief Sets the menu system color;
        /// @param value The menu system color.
        void menu(const color_property& value) noexcept;

        /// @brief Gets the menu bar system color;
        /// @return The menu bar system color.
        const color_property& menu_bar() const noexcept;
        /// @brief Sets the menu bar system color;
        /// @param value The menu bar system color.
        void menu_bar(const color_property& value) noexcept;

        /// @brief Gets the menu highlight system color;
        /// @return The menu highlight system color.
        const color_property& menu_highlight() const noexcept;
        /// @brief Sets the menu highlight system color;
        /// @param value The menu highlight system color.
        void menu_highlight(const color_property& value) noexcept;

        /// @brief Gets the menu text system color;
        /// @return The menu text system color.
        const color_property& menu_text() const noexcept;
        /// @brief Sets the menu text system color;
        /// @param value The menu text system color.
        void menu_text(const color_property& value) noexcept;

        /// @brief Gets the scroll bar system color;
        /// @return The scroll bar system color.
        const color_property& scroll_bar() const noexcept;
        /// @brief Sets the scroll bar system color;
        /// @param value The scroll bar system color.
        void scroll_bar(const color_property& value) noexcept;

        /// @brief Gets the text box system color;
        /// @return The text box system color.
        const color_property& text_box() const noexcept;
        /// @brief Sets the text box system color;
        /// @param value The text box system color.
        void text_box(const color_property& value) noexcept;

        /// @brief Gets the text box text system color;
        /// @return The text box text system color.
        const color_property& text_box_text() const noexcept;
        /// @brief Sets the text box text system color;
        /// @param value The text box text system color.
        void text_box_text(const color_property& value) noexcept;

        /// @brief Gets the window system color;
        /// @return The window system color.
        const color_property& window() const noexcept;
        /// @brief Sets the window system color;
        /// @param value The window system color.
        void window(const color_property& value) noexcept;

        /// @brief Gets the window frame system color;
        /// @return The window frame system color.
        const color_property& window_frame() const noexcept;
        /// @brief Sets the window frame system color;
        /// @param value The window frame system color.
        void window_frame(const color_property& value) noexcept;

        /// @brief Gets the window text system color;
        /// @return The window text system color.
        const color_property& window_text() const noexcept;
        /// @brief Sets the window text system color;
        /// @param value The window text system color.
        void window_text(const color_property& value) noexcept;
        /// @}

        /// @name Methods
        
        /// @{
        bool equals(const object& other) const noexcept override;
        bool equals(const system_colors_selector& other) const noexcept override;
        /// @}

      private:
        color_property accent_;
        color_property accent_text_;
        color_property active_border_;
        color_property active_caption_;
        color_property active_caption_text_;
        color_property app_workspace_;
        color_property button_face_;
        color_property button_highlight_;
        color_property button_shadow_;
        color_property control_;
        color_property control_dark_;
        color_property control_dark_dark_;
        color_property control_light_;
        color_property control_light_light_;
        color_property control_text_;
        color_property desktop_;
        color_property gradient_active_caption_;
        color_property gradient_inactive_caption_;
        color_property gray_text_;
        color_property highlight_;
        color_property highlight_text_;
        color_property hot_track_;
        color_property inactive_border_;
        color_property inactive_caption_;
        color_property inactive_caption_text_;
        color_property info_;
        color_property info_text_;
        color_property menu_;
        color_property menu_bar_;
        color_property menu_highlight_;
        color_property menu_text_;
        color_property scroll_bar_;
        color_property text_box_;
        color_property text_box_text_;
        color_property window_;
        color_property window_frame_;
        color_property window_text_;
      };
    }
  }
}
