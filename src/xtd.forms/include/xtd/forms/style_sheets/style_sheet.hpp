/// @file
/// @brief Contains xtd::forms::style_sheets::style_sheet class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.hpp"
#include "../border_style.hpp"
#include "button.hpp"
#include "control.hpp"
#include "form.hpp"
#include "label.hpp"
#include "link_label.hpp"
#include "panel.hpp"
#include "pseudo_state.hpp"
#include "status_bar.hpp"
#include "status_bar_panel.hpp"
#include "system_colors.hpp"
#include "theme.hpp"
#include "user_control.hpp"
#include "toggle_button.hpp"
#include "tool_bar.hpp"
#include "tool_bar_button.hpp"
#include <xtd/collections/generic/list>
#include <xtd/web/css/css_reader>
#include <xtd/event_handler>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/uri>
#include <map>

/// @cond
class __test_style_sheet__; // Necessary for the test unit to access the private member functions
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    class form;
    /// @endcond
    
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::style_sheet allows you to specify an xtd style sheet.
      /// ```cpp
      /// class forms_export_ style_sheet final : public xtd::iequatable<style_sheet>, public xtd::object
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::style_sheet
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/style_sheets/style_sheet>
      /// ```
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::ibox_model.
      /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
      class forms_export_ style_sheet final : public xtd::iequatable<style_sheet>, public xtd::object {
        struct data;
        
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents a style sheet buttons collection.
        using buttons_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::button>;
        /// @brief Represents a style sheet controls collection.
        using controls_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::control>;
        /// @brief Represents a style sheet forms collection.
        using forms_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::form>;
        /// @brief Represents a style sheet labels collection.
        using labels_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::label>;
        /// @brief Represents a style sheet link_label collection.
        using link_labels_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::link_label>;
        /// @brief Represents a style sheet panels collection.
        using panels_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::panel>;
        /// @brief Represents a style_sheets collection.
        using style_sheets_t = std::map<xtd::string, style_sheet>;
        /// @brief Represents a style_sheet names collection.
        using style_sheet_names_t = xtd::collections::generic::list<xtd::string>;
        /// @brief Represents a style sheet tool_bars collection.
        using status_bars_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::status_bar>;
        /// @brief Represents a style sheet buttons collection.
        using status_bar_panels_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::status_bar_panel>;
        /// @brief Represents a style sheet toggle buttons collection.
        using toggle_buttons_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::toggle_button>;
        /// @brief Represents a style sheet tool_bars collection.
        using tool_bars_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::tool_bar>;
        /// @brief Represents a style sheet buttons collection.
        using tool_bar_buttons_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::tool_bar_button>;
        /// @brief Represents a style sheet user_controls collection.
        using user_controls_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::user_control>;
        /// @}
        
        /// @name Public Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::style_sheet object.
        static const style_sheet empty;
        /// @}
        
        /// @name Public Constructors
        
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance.
        style_sheet();
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance from specified css forrmated text.
        /// @param css_text The css forrmated text that contains the style sheet definition.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        explicit style_sheet(const xtd::string& css_text);
        
        /// @cond
        style_sheet(const style_sheet&);
        style_sheet(style_sheet&&) = default;
        style_sheet& operator =(const style_sheet&);
        style_sheet& operator =(style_sheet&&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the style sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto button() const noexcept -> xtd::forms::style_sheets::button;
        /// @brief Gets the style sheet button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto button(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::button;
        /// @brief Gets the style sheet buttons collection of this instance.
        /// @return The style sheet buttons collection.
        [[nodiscard]] auto buttons() const noexcept -> const buttons_t&;
        
        /// @brief Gets the style sheet control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto control() const noexcept -> xtd::forms::style_sheets::control;
        /// @brief Gets the style sheet control for specified pseudo state.
        /// @return A style_sheet control.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto control(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::control;
        /// @brief Gets the style sheet controls collection of this instance.
        /// @return The style sheet controls collection.
        [[nodiscard]] auto controls() const noexcept -> const controls_t&;
        
        /// @brief Gets the style sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto flat_button() const noexcept -> xtd::forms::style_sheets::button;
        /// @brief Gets the style sheet button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto flat_button(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::button;
        /// @brief Gets the style sheet buttons collection of this instance.
        /// @return The style sheet buttons collection.
        [[nodiscard]] auto flat_buttons() const noexcept -> const buttons_t&;
        
        /// @brief Gets the style sheet toggle_button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto flat_toggle_button() const noexcept -> xtd::forms::style_sheets::toggle_button;
        /// @brief Gets the style sheet toggle_button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto flat_toggle_button(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::toggle_button;
        /// @brief Gets the style sheet toggle_buttons collection of this instance.
        /// @return The style sheet buttons collection.
        [[nodiscard]] auto flat_toggle_buttons() const noexcept -> const toggle_buttons_t&;
        
        /// @brief Gets the style sheet form for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet form for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto form() const noexcept -> xtd::forms::style_sheets::form;
        /// @brief Gets the style sheet form for specified pseudo state.
        /// @return A style_sheet form.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto form(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::form;
        /// @brief Gets the style sheet forms collection of this instance.
        /// @return The style sheet forms collection.
        [[nodiscard]] auto forms() const noexcept -> const forms_t&;
        
        /// @brief Gets a value indicate if this instance is system style sheet.
        /// @return `true` if the current instance is system style sheet; otherwise `false`.
        /// @remarks This method return `true` only if the current instance is equal to xtd::forms::style_sheets::style_sheet::system_style_sheet.
        [[nodiscard]] auto is_system_style_sheet() const noexcept -> bool;
        
        /// @brief Gets the style sheet label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto label() const noexcept -> xtd::forms::style_sheets::label;
        /// @brief Gets the style sheet label for specified pseudo state.
        /// @return A style_sheet label.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto label(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::label;
        /// @brief Gets the style sheet labels collection of this instance.
        /// @return The style sheet labels collection.
        [[nodiscard]] auto labels() const noexcept -> const labels_t&;
        
        /// @brief Gets the style sheet link_label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet link_label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto link_label() const noexcept -> xtd::forms::style_sheets::link_label;
        /// @brief Gets the style sheet link_label for specified pseudo state.
        /// @return A style_sheet link_label.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto link_label(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::link_label;
        /// @brief Gets the style sheet link_label collection of this instance.
        /// @return The style sheet link_label collection.
        [[nodiscard]] auto link_labels() const noexcept -> const link_labels_t&;
        
        /// @brief Gets the style sheet panel for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet panel for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto panel() const noexcept -> xtd::forms::style_sheets::panel;
        /// @brief Gets the style sheet panel for specified pseudo state.
        /// @return A style_sheet panel.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto panel(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::panel;
        /// @brief Gets the style sheet panels collection of this instance.
        /// @return The style sheet panels collection.
        [[nodiscard]] auto panels() const noexcept -> const panels_t&;
        
        /// @brief Gets the style sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto popup_button() const noexcept -> xtd::forms::style_sheets::button;
        /// @brief Gets the style sheet button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto popup_button(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::button;
        /// @brief Gets the style sheet buttons collection of this instance.
        /// @return The style sheet buttons collection.
        [[nodiscard]] auto popup_buttons() const noexcept -> const buttons_t&;
        
        /// @brief Gets the style sheet toggle_button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto popup_toggle_button() const noexcept -> xtd::forms::style_sheets::toggle_button;
        /// @brief Gets the style sheet toggle_button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto popup_toggle_button(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::toggle_button;
        /// @brief Gets the style sheet toggle_buttons collection of this instance.
        /// @return The style sheet buttons collection.
        [[nodiscard]] auto popup_toggle_buttons() const noexcept -> const toggle_buttons_t&;
        
        /// @brief Gets the style sheet status_bar for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet status_bar for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto status_bar() const noexcept -> xtd::forms::style_sheets::status_bar;
        /// @brief Gets the style sheet status_bar for specified pseudo state.
        /// @return A style_sheet status_bar.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto status_bar(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::status_bar;
        /// @brief Gets the style sheet status_bar collection of this instance.
        /// @return The style sheet status_bar collection.
        [[nodiscard]] auto status_bars() const noexcept -> const status_bars_t&;
        
        /// @brief Gets the style sheet status bar panel for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet status bar panel for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto status_bar_panel() const noexcept -> xtd::forms::style_sheets::status_bar_panel;
        /// @brief Gets the style sheet status bar panel for specified pseudo state.
        /// @return A style_sheet status bar panel.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto status_bar_panel(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::status_bar_panel;
        /// @brief Gets the style sheet status bar panels collection of this instance.
        /// @return The style sheet status bar panels collection.
        [[nodiscard]] auto status_bar_panels() const noexcept -> const status_bar_panels_t&;
        
        /// @brief Gets The style sheet system colors of this instance.
        /// @return The style sheet systel colors collection.
        [[nodiscard]] auto system_colors() const noexcept -> const xtd::forms::style_sheets::system_colors&;
        
        /// @brief Gets The style sheet theme of this instance.
        /// @return The style sheet theme collection.
        [[nodiscard]] auto theme() const noexcept -> const xtd::forms::style_sheets::theme&;
        
        /// @brief Gets the style sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto toggle_button() const noexcept -> xtd::forms::style_sheets::toggle_button;
        /// @brief Gets the style sheet button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto toggle_button(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::toggle_button;
        /// @brief Gets the style sheet buttons collection of this instance.
        /// @return The style sheet buttons collection.
        [[nodiscard]] auto toggle_buttons() const noexcept -> const toggle_buttons_t&;
        
        /// @brief Gets the style sheet tool_bar for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet tool_bar for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto tool_bar() const noexcept -> xtd::forms::style_sheets::tool_bar;
        /// @brief Gets the style sheet tool_bar for specified pseudo state.
        /// @return A style_sheet tool_bar.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto tool_bar(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::tool_bar;
        /// @brief Gets the style sheet tool_bars collection of this instance.
        /// @return The style sheet tool_bars collection.
        [[nodiscard]] auto tool_bars() const noexcept -> const tool_bars_t&;
        
        /// @brief Gets the style sheet tool bar button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet tool bar button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto tool_bar_button() const noexcept -> xtd::forms::style_sheets::tool_bar_button;
        /// @brief Gets the style sheet tool bar button for specified pseudo state.
        /// @return A style_sheet tool bar button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto tool_bar_button(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::tool_bar_button;
        /// @brief Gets the style sheet tool bar buttons collection of this instance.
        /// @return The style sheet tool bar buttons collection.
        [[nodiscard]] auto tool_bar_buttons() const noexcept -> const tool_bar_buttons_t&;
        
        /// @brief Gets the style sheet user_control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        [[nodiscard]] auto user_control() const noexcept -> xtd::forms::style_sheets::user_control;
        /// @brief Gets the style sheet user_control for specified pseudo state.
        /// @return A style_sheet user_control.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        [[nodiscard]] auto user_control(xtd::forms::style_sheets::pseudo_state state) const noexcept -> xtd::forms::style_sheets::user_control;
        /// @brief Gets the style sheet user_control collection of this instance.
        /// @return The style sheet controls collection.
        [[nodiscard]] auto user_controls() const noexcept -> const user_controls_t&;
        /// @}
        
        /// @name Public Static Properties
        
        /// @{
        /// @brief Gets current xtd::forms::style_sheets::style_sheet style sheet.
        /// @return The current xtd::forms::style_sheets::style_sheet style sheet.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto current_style_sheet() noexcept -> const style_sheet&;
        /// @brief Sets current xtd::forms::style_sheets::style_sheet style sheet.
        /// @param value The current xtd::forms::style_sheets::style_sheet style sheet.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        static auto current_style_sheet(const style_sheet& value) -> void;
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheets.
        /// @return The installed xtd::forms::style_sheets::style_sheet style sheets.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto style_sheets() noexcept -> const style_sheets_t&;
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheet names.
        /// @return The installed xtd::forms::style_sheets::style_sheet names.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto style_sheet_names() noexcept -> const style_sheet_names_t&;
        
        /// @brief Gets system xtd::forms::style_sheets::style_sheet style sheet.
        /// @return The system xtd::forms::style_sheets::style_sheet style sheet.
        /// @remarks The system style sheet is the style sheet corresponding to the current Operating System and the current Desktop Environment.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto system_style_sheet() noexcept -> const style_sheet&;
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
        [[nodiscard]] auto equals(const style_sheet& other) const noexcept -> bool override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        /// @brief Gets the style sheet buttons collection from specified css string.
        /// @param css_text The css string that contains button definition.
        /// @return The style sheet buttons collection.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto button_from_css(const xtd::string& css_text) -> buttons_t;
        
        /// @brief Gets the style sheet controls collection from specified css string.
        /// @param css_text The css string that contains control definition.
        /// @return The style sheet controls collection.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto control_from_css(const xtd::string& css_text) -> controls_t;
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheet from specified name.
        /// @return The xtd::forms::style_sheets::style_sheet style sheet from name.
        /// @exception xtd::argument_exception The style sheet name not tvalid.
        /// @remarks Use xtd::forms::style_sheets::style_sheet::style_sheet_names to retreive valid style sheet names.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto get_style_sheet_from_name(const xtd::string& name) -> style_sheet;
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheet from specified name.
        /// @return The xtd::forms::style_sheets::style_sheet style sheet from name.
        /// @exception xtd::argument_exception The style sheet name not tvalid.
        /// @remarks Use xtd::forms::style_sheets::style_sheet::style_sheet_names to retreive valid style sheet names.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto get_style_sheet_from_file(const xtd::string& file_name) -> style_sheet;
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheet from specified name.
        /// @return The xtd::forms::style_sheets::style_sheet style sheet from name.
        /// @exception xtd::argument_exception The style sheet name not tvalid.
        /// @remarks Use xtd::forms::style_sheets::style_sheet::style_sheet_names to retreive valid style sheet names.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto get_style_sheet_from_path(const xtd::string& path_name) -> style_sheet;
        
        /// @brief Gets the style sheet forms collection from specified css string.
        /// @param css_text The css string that contains forms definition.
        /// @return The style sheet forms collection.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto form_from_css(const  xtd::string& css_text) -> forms_t;
        
        /// @brief Gets the style sheet system colors from specified css string.
        /// @param css_text The css string that contains system colors definition.
        /// @return The style sheet system colors.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto system_colors_from_css(const xtd::string& css_text) -> xtd::forms::style_sheets::system_colors;
        
        /// @brief Gets the style sheet theme from specified css string.
        /// @param css_text The css string that contains theme definition.
        /// @return The style sheet theme.
        /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.forms/Style%20sheets/style_sheets_overview).
        [[nodiscard]] static auto theme_from_css(const xtd::string& css_text) -> xtd::forms::style_sheets::theme;
        
        /// @brief Converts xtd::forms::border_style in std::tuple<xtd::forms::style_sheets::border_type, int32, int32>.
        /// @param border The ::forms::border_style to convert.
        /// @return A std::tuple<xtd::forms::style_sheets::border_type, int32, int32> class that containe, border type, border width and border radius.
        [[nodiscard]] static auto to_border_type(xtd::forms::border_style border) -> std::tuple<xtd::forms::style_sheets::border_type, int32, int32>;
        /// @}
        
        /// @name Public Static Events
        
        /// @{
        /// @brief Occurs when the value of the xtd::forms::style_sheets::style_sheet::current_style_sheet property changes.
        /// @remarks This event is raised if the xtd::forms::style_sheets::style_sheet::current_style_sheet property is changed by either a programmatic modification or user interaction.
        /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
        static event<style_sheet, event_handler> style_sheet_changed;
        /// @}
        
      private:
        friend class ::__test_style_sheet__; // Necessary for the test unit to access the private member functions
        friend class xtd::forms::control;
        friend class xtd::forms::form;
        style_sheet(const xtd::string& css_text, bool init_system);
        
        [[nodiscard]] auto background_color_from_css(const xtd::string& css_text, const xtd::drawing::color& default_value) const noexcept -> xtd::drawing::color;
        [[nodiscard]] auto background_image_from_css(const xtd::string& css_text, const background_image& default_value) const noexcept -> background_image;
        [[nodiscard]] auto border_color_from_css(const xtd::string& css_text, const border_color& default_value) const noexcept -> border_color;
        [[nodiscard]] auto border_style_from_css(const string& text, const border_style& default_value) const noexcept -> border_style;
        [[nodiscard]] auto border_radius_from_css(const xtd::string& css_text, const border_radius& default_value) const noexcept -> border_radius;
        [[nodiscard]] auto border_width_from_css(const xtd::string& css_text, const border_width& default_value) const noexcept -> border_width;
        [[nodiscard]] auto color_from_css(const xtd::string& css_text, const xtd::drawing::color& default_value) const noexcept -> xtd::drawing::color;
        [[nodiscard]] auto length_from_css(const xtd::string& css_text, const length& default_value) const noexcept -> length;
        [[nodiscard]] auto margin_from_css(const xtd::string& css_text, const margin& default_value) const noexcept -> margin;
        [[nodiscard]] auto margin_bottom_from_css(const xtd::string& css_text, const margin& default_value) const noexcept -> margin;
        [[nodiscard]] auto margin_left_from_css(const xtd::string& css_text, const margin& default_value) const noexcept -> margin;
        [[nodiscard]] auto margin_right_from_css(const xtd::string& css_text, const margin& default_value) const noexcept -> margin;
        [[nodiscard]] auto margin_top_from_css(const xtd::string& css_text, const margin& default_value) const noexcept -> margin;
        [[nodiscard]] auto padding_from_css(const xtd::string& css_text, const padding& default_value) const noexcept -> padding;
        [[nodiscard]] auto padding_bottom_from_css(const xtd::string& css_text, const padding& default_value) const noexcept -> padding;
        [[nodiscard]] auto padding_left_from_css(const xtd::string& css_text, const padding& default_value) const noexcept -> padding;
        [[nodiscard]] auto padding_right_from_css(const xtd::string& css_text, const padding& default_value) const noexcept -> padding;
        [[nodiscard]] auto padding_top_from_css(const xtd::string& css_text, const padding& default_value) const noexcept -> padding;
        [[nodiscard]] auto string_from_css(const xtd::string& css_text, const xtd::string& default_value) const noexcept -> xtd::string;
        [[nodiscard]] auto text_align_from_css(const xtd::string& css_text, const xtd::forms::content_alignment& default_value) const noexcept -> xtd::forms::content_alignment;
        [[nodiscard]] auto text_decoration_from_css(const xtd::string& css_text, const xtd::forms::style_sheets::text_decoration& default_value) const noexcept -> xtd::forms::style_sheets::text_decoration;
        [[nodiscard]] auto text_transformation_from_css(const xtd::string& css_text, const xtd::forms::style_sheets::text_transformation& default_value) const noexcept -> xtd::forms::style_sheets::text_transformation;
        [[nodiscard]] auto uri_from_css(const xtd::string& css_text, const xtd::uri& default_value) const noexcept -> xtd::uri;
        [[nodiscard]] auto white_space_from_css(const xtd::string& css_text, const xtd::forms::style_sheets::white_space& default_value) const noexcept -> xtd::forms::style_sheets::white_space;
        
        template<typename type_t, typename collection_t>
        [[nodiscard]] auto get_state_control(const collection_t& collection, pseudo_state state) const noexcept -> type_t {
          auto result = type_t();
          auto it = collection.find(pseudo_state::standard);
          if (it != collection.end()) result = it->second;
          it = collection.find(state);
          if (it != collection.end()) result = it->second;
          return result;
        }
        
        static auto on_style_sheet_changed(const xtd::event_args& e) -> void;
        static auto on_system_colors_changed(const event_args& e) -> void;
        [[nodiscard]] auto split_values_from_text(const xtd::string& text) const noexcept -> xtd::array<xtd::string>;
        
        auto button_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto control_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto fill_control(const xtd::web::css::selector_dictionary::const_iterator& selectors_iterator, xtd::forms::style_sheets::control& control) noexcept -> void;
        auto flat_button_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto flat_toggle_button_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto form_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto label_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto link_label_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto panel_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto popup_button_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto popup_toggle_button_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto status_bar_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto status_bar_panel_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto system_colors_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto theme_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto toggle_button_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto tool_bar_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto tool_bar_button_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        auto user_control_reader(xtd::web::css::css_reader& reader) noexcept -> void;
        
        //s[[nodiscard]] tatic auto system_style_sheet_gnome_dark() noexcept -> style_sheet; // Declared in system_style_sheet_gnome_dark.cpp
        //[[nodiscard]] static auto system_style_sheet_gnome_light() noexcept -> style_sheet; // Declared in system_style_sheet_gnome_light.cpp
        //[[nodiscard]] static auto system_style_sheet_kde_dark() noexcept -> style_sheet; // Declared in system_style_sheet_kde_dark.cpp
        //[[nodiscard]] static auto system_style_sheet_kde_light() noexcept -> style_sheet; // Declared in system_style_sheet_kde_light.cpp
        //[[nodiscard]] static auto system_style_sheet_macos_dark() noexcept -> style_sheet; // Declared in system_style_sheet_macos_dark.cpp
        //[[nodiscard]] static auto system_style_sheet_macos_light() noexcept -> style_sheet; // Declared in system_style_sheet_macos_light.cpp
        [[nodiscard]] static auto system_style_sheet_unknown_dark() noexcept -> style_sheet; // Declared in system_style_sheet_unknown_dark.cpp
        [[nodiscard]] static auto system_style_sheet_unknown_light() noexcept -> style_sheet; // Declared in system_style_sheet_unknown_light.cpp
        //[[nodiscard]] static auto system_style_sheet_windows_dark() noexcept -> style_sheet; // Declared in system_style_sheet_windows_dark.cpp
        //[[nodiscard]] static auto system_style_sheet_windows_light() noexcept -> style_sheet; // Declared in system_style_sheet_windows_light.cpp
        
        auto try_parse_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_conic_gradient(const xtd::string& text, background_image& result) const noexcept -> bool;
        auto try_parse_hex_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_linear_gradient(const xtd::string& text, background_image& result) const noexcept -> bool;
        auto try_parse_named_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_radial_gradient(const xtd::string& text, background_image& result) const noexcept -> bool;
        auto try_parse_rgb_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_rgba_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_hsv_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_hsva_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_hsl_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_hsla_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_system_color(const xtd::string& text, xtd::drawing::color& result) const noexcept -> bool;
        auto try_parse_uri(const xtd::string& text, xtd::uri& result) const noexcept -> bool;
        
        auto system_colors_(const xtd::forms::style_sheets::system_colors& system_colors) -> void;
        auto theme_(const xtd::forms::style_sheets::theme& theme) -> void;
        auto theme_name_(const xtd::string& name) -> void;
        
        static style_sheet current_style_sheet_;
        static style_sheets_t style_sheets_;
        static style_sheet_names_t style_sheet_names_;
        static style_sheet system_style_sheet_;
        
        xtd::sptr<data> data_;
      };
    }
  }
}
