/// @file
/// @brief Contains xtd::forms::style_sheets::style_sheet class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include <vector>
#include <xtd/event_handler.h>
#include <xtd/iequatable.h>
#include <xtd/object.h>
#include <xtd/uri.h>
#include <xtd/web/css/css_reader.h>
#include "../../forms_export.h"
#include "button.h"
#include "form.h"
#include "label.h"
#include "pseudo_state.h"
#include "system_colors.h"
#include "theme.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::style_sheet allows you to specify an xtd style sheet.
      /// @code
      /// class forms_export_ style_sheet final : public xtd::iequatable<style_sheet>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::style_sheet
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::ibox_model.
      class forms_export_ style_sheet final : public xtd::iequatable<style_sheet>, public xtd::object {
      public:
        /// @name Alias
 
        /// @{
        /// @brief Represents a buttons collection.
        using buttons_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::button>;
        /// @brief Represents a controls collection.
        using controls_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::control>;
        /// @brief Represents a forms collection.
        using forms_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::form>;
        /// @brief Represents a labels collection.
        using labels_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::label>;
        /// @brief Represents a style_sheets collection.
        using style_sheets_t = std::map<xtd::ustring, style_sheet>;
        /// @}
        
        /// @name Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::style_sheet object.
        static const style_sheet empty;
        /// @}

        /// @name Constructors
        
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance.
        style_sheet() = default;
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance from specified css forrmated text.
        explicit style_sheet(const xtd::ustring& text);

        /// @cond
        style_sheet(const style_sheet&) = default;
        style_sheet(style_sheet&&) = default;
        style_sheet& operator=(const style_sheet&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        const xtd::forms::style_sheets::button& button() const noexcept;
        const xtd::forms::style_sheets::button& button(xtd::forms::style_sheets::pseudo_state state) const noexcept;

        const xtd::forms::style_sheets::control& control() const noexcept;
        const xtd::forms::style_sheets::control& control(xtd::forms::style_sheets::pseudo_state state) const noexcept;

        static const style_sheet& current_style_sheet() noexcept;
        static void current_style_sheet(const style_sheet& value);

        const xtd::forms::style_sheets::form& form() const noexcept;
        const xtd::forms::style_sheets::form& form(xtd::forms::style_sheets::pseudo_state state) const noexcept;

        const xtd::forms::style_sheets::label& label() const noexcept;
        const xtd::forms::style_sheets::label& label(xtd::forms::style_sheets::pseudo_state state) const noexcept;

        static const style_sheets_t& style_sheets() noexcept;

        const xtd::forms::style_sheets::system_colors& system_colors()const noexcept;
        
        static const style_sheet& system_style_sheet() noexcept;
        
        const xtd::forms::style_sheets::theme& theme() const noexcept;
        /// @}

        /// @name Methods

        bool equals(const object& other) const noexcept override;
        bool equals(const style_sheet& other) const noexcept override;

        border_color border_color_from_css(const xtd::ustring& css_text, const border_color& result) const noexcept;
        border_style border_style_from_css(const ustring& text, const border_style& default_value) const noexcept;
        xtd::drawing::color color_from_css(const xtd::ustring& css_text, const xtd::drawing::color& default_value) const noexcept;
        background_image background_image_from_css(const xtd::ustring& css_text, const background_image& default_value) const noexcept;
        length length_from_css(const xtd::ustring& css_text, const length& default_value) const noexcept;
        xtd::ustring string_from_css(const xtd::ustring& css_text, const xtd::ustring& default_value) const noexcept;
        xtd::uri uri_from_css(const xtd::ustring& css_text, const xtd::uri& default_value) const noexcept;
        /// @}
        
        /// @name Events
        
        /// @{
        /// @brief Occurs when the value of the xtd::forms::style_sheets::style_sheet::current_style_sheet property changes.
        /// @ingroup events
        /// @remarks This event is raised if the xtd::forms::style_sheets::style_sheet::current_style_sheet property is changed by either a programmatic modification or user interaction.
        /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
        static event<style_sheet, event_handler> current_style_sheet_changed;
        /// @}
        
      private:
        static void initilize();
        static void on_current_style_sheet_changed(const xtd::event_args& e);
        std::vector<xtd::ustring> split_colors_from_text(const xtd::ustring& text) const noexcept;
        void system_color_reader(xtd::web::css::selector_map::const_iterator& selectors_iterator, xtd::forms::style_sheets::system_colors& colors) const noexcept;
        static style_sheet system_style_sheet_gnome_dark() noexcept;
        static style_sheet system_style_sheet_gnome_light() noexcept;
        static style_sheet system_style_sheet_kde_dark() noexcept;
        static style_sheet system_style_sheet_kde_light() noexcept;
        static style_sheet system_style_sheet_macos_dark() noexcept;
        static style_sheet system_style_sheet_macos_light() noexcept;
        static style_sheet system_style_sheet_unknown_dark() noexcept;
        static style_sheet system_style_sheet_unknown_light() noexcept;
        static style_sheet system_style_sheet_windows_dark() noexcept;
        static style_sheet system_style_sheet_windows_light() noexcept;
        void theme_reader(xtd::web::css::selector_map::const_iterator& selectors_iterator, xtd::forms::style_sheets::theme& theme) const noexcept;
        bool try_parse_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hex_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_linear_gradient(const xtd::ustring& text, background_image& result) const noexcept;
        bool try_parse_named_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_rgb_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_rgba_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_argb_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsv_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsva_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_ahsv_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsl_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsla_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_ahsl_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_system_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_uri(const xtd::ustring& text, xtd::uri& result) const noexcept;

        buttons_t buttons_;
        controls_t controls_;
        forms_t forms_;
        labels_t labels_;
        static style_sheet current_style_sheets_;
        static style_sheets_t style_sheets_;
        xtd::forms::style_sheets::system_colors system_colors_;
        xtd::forms::style_sheets::theme theme_;
      };
    }
  }
}
