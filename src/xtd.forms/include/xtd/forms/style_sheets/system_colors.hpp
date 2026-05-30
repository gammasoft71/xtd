/// @file
/// @brief Contains xtd::forms::style_sheets::system_colors class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.hpp"
#include <xtd/drawing/color>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>
#include <memory>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The theme data allows you to specify the theme informations.
      /// ```cpp
      /// class forms_export_ system_colors : public xtd::object
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::system_colors
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/style_sheets/system_colors>
      /// ```
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ system_colors : public xtd::iequatable<system_colors>, public xtd::object {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::system_colors class.
        system_colors() = default;
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the accent system color;
        /// @return The accent system color.
        [[nodiscard]] auto accent() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the accent system color;
        /// @param value The accent system color.
        auto accent(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the accent text system color;
        /// @return The accent text system color.
        [[nodiscard]] auto accent_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the accent text system color;
        /// @param value The accent text system color.
        auto accent_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the active border system color;
        /// @return The active border system color.
        [[nodiscard]] auto active_border() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the active border system color;
        /// @param value The active border system color.
        auto active_border(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the active caption system color;
        /// @return The active caption system color.
        [[nodiscard]] auto active_caption() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the active caption system color;
        /// @param value The active caption system color.
        auto active_caption(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the active caption text system color;
        /// @return The active caption text system color.
        [[nodiscard]] auto active_caption_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the active caption text system color;
        /// @param value The active caption text system color.
        auto active_caption_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the text color of an html link text when mouse down.
        /// @return The text color of an html link text when mouse down.
        [[nodiscard]] auto active_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the text color of an html link text when mouse down.
        /// @param value The text color of an html link text when mouse down.
        auto active_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the app workspace system color;
        /// @return The app workspace system color.
        [[nodiscard]] auto app_workspace() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the app workspace system color;
        /// @param value The app workspace system color.
        auto app_workspace(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the button face system color;
        /// @return The button face system color.
        [[nodiscard]] auto button_face() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the button face system color;
        /// @param value The button face system color.
        auto button_face(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the button highlight system color;
        /// @return The button highlight system color.
        [[nodiscard]] auto button_highlight() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the button highlight system color;
        /// @param value The button highlight system color.
        auto button_highlight(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the button shadow system color;
        /// @return The button shadow system color.
        [[nodiscard]] auto button_shadow() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the button shadow system color;
        /// @param value The button shadow system color.
        auto button_shadow(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the control system color;
        /// @return The control system color.
        [[nodiscard]] auto control() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the control system color;
        /// @param value The control system color.
        auto control(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the control dark system color;
        /// @return The control dark system color.
        [[nodiscard]] auto control_dark() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the control dark system color;
        /// @param value The control dark system color.
        auto control_dark(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the control dark dark system color;
        /// @return The control dark dark system color.
        [[nodiscard]] auto control_dark_dark() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the control dark dark system color;
        /// @param value The control dark dark system color.
        auto control_dark_dark(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the control light system color;
        /// @return The control light system color.
        [[nodiscard]] auto control_light() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the control light system color;
        /// @param value The control light system color.
        auto control_light(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the control light light system color;
        /// @return The control light light system color.
        [[nodiscard]] auto control_light_light() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the control light light system color;
        /// @param value The control light light system color.
        auto control_light_light(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the control text system color;
        /// @return The control text system color.
        [[nodiscard]] auto control_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the control text system color;
        /// @param value The control text system color.
        auto control_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the desktop system color;
        /// @return The desktop system color.
        [[nodiscard]] auto desktop() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the desktop system color;
        /// @param value The desktop system color.
        auto desktop(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the gradient active caption system color;
        /// @return The gradient active caption system color.
        [[nodiscard]] auto gradient_active_caption() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the gradient active caption system color;
        /// @param value The gradient active caption system color.
        auto gradient_active_caption(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the gradient inactive caption system color;
        /// @return The gradient inactive caption system color.
        [[nodiscard]] auto gradient_inactive_caption() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the gradient inactive caption system color;
        /// @param value The gradient inactive caption system color.
        auto gradient_inactive_caption(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the gray text system color;
        /// @return The gray text system color.
        [[nodiscard]] auto gray_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the gray text system color;
        /// @param value The gray text system color.
        auto gray_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the highlight system color;
        /// @return The highlight system color.
        [[nodiscard]] auto highlight() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the highlight system color;
        /// @param value The highlight system color.
        auto highlight(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the highlight text system color;
        /// @return The highlight text system color.
        [[nodiscard]] auto highlight_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the highlight text system color;
        /// @param value The highlight text system color.
        auto highlight_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the hot track system color;
        /// @return The hot track system color.
        [[nodiscard]] auto hot_track() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the hot track system color;
        /// @param value The hot track system color.
        auto hot_track(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the inactive border system color;
        /// @return The inactive border system color.
        [[nodiscard]] auto inactive_border() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the inactive border system color;
        /// @param value The inactive border system color.
        auto inactive_border(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the inactive caption system color;
        /// @return The inactive caption system color.
        [[nodiscard]] auto inactive_caption() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the inactive caption system color;
        /// @param value The inactive caption system color.
        auto inactive_caption(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the inactive caption text system color;
        /// @return The inactive caption text system color.
        [[nodiscard]] auto inactive_caption_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the inactive caption text system color;
        /// @param value The inactive caption text system color.
        auto inactive_caption_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the info system color;
        /// @return The info system color.
        [[nodiscard]] auto info() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the info system color;
        /// @param value The info system color.
        auto info(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the info text system color;
        /// @return The info text system color.
        [[nodiscard]] auto info_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the info text system color;
        /// @param value The info text system color.
        auto info_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the text color of an html link text.
        /// @return The text color of an html link text.
        [[nodiscard]] auto link_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the text color of an html link text.
        /// @param value The text color of an html link text.
        auto link_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the menu system color;
        /// @return The menu system color.
        [[nodiscard]] auto menu() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the menu system color;
        /// @param value The menu system color.
        auto menu(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the menu bar system color;
        /// @return The menu bar system color.
        [[nodiscard]] auto menu_bar() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the menu bar system color;
        /// @param value The menu bar system color.
        auto menu_bar(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the menu highlight system color;
        /// @return The menu highlight system color.
        [[nodiscard]] auto menu_highlight() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the menu highlight system color;
        /// @param value The menu highlight system color.
        auto menu_highlight(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the menu text system color;
        /// @return The menu text system color.
        [[nodiscard]] auto menu_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the menu text system color;
        /// @param value The menu text system color.
        auto menu_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the scroll bar system color;
        /// @return The scroll bar system color.
        [[nodiscard]] auto scroll_bar() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the scroll bar system color;
        /// @param value The scroll bar system color.
        auto scroll_bar(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the shadow text system color;
        /// @return The shadow text system color.
        [[nodiscard]] auto shadow_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the shadow text system color;
        /// @param value The shadow text system color.
        auto shadow_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the text box system color;
        /// @return The text box system color.
        [[nodiscard]] auto text_box() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the text box system color;
        /// @param value The text box system color.
        auto text_box(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the text box text system color;
        /// @return The text box text system color.
        [[nodiscard]] auto text_box_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the text box text system color;
        /// @param value The text box text system color.
        auto text_box_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the text color of an html visited link text.
        /// @return The text color of an html visited link text.
        [[nodiscard]] auto visited_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the text color of an html visited link text.
        /// @param value The text color of an html visited link text.
        auto visited_text(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the window system color;
        /// @return The window system color.
        [[nodiscard]] auto window() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the window system color;
        /// @param value The window system color.
        auto window(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the window frame system color;
        /// @return The window frame system color.
        [[nodiscard]] auto window_frame() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the window frame system color;
        /// @param value The window frame system color.
        auto window_frame(const xtd::drawing::color& value) noexcept -> void;
        
        /// @brief Gets the window text system color;
        /// @return The window text system color.
        [[nodiscard]] auto window_text() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the window text system color;
        /// @param value The window text system color.
        auto window_text(const xtd::drawing::color& value) noexcept -> void;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const system_colors& other) const noexcept -> bool override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
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
