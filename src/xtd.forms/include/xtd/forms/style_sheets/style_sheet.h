/// @file
/// @brief Contains xtd::forms::style_sheets::style_sheet class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.h"
#include "../border_style.h"
#include "button.h"
#include "control.h"
#include "form.h"
#include "label.h"
#include "link_label.h"
#include "panel.h"
#include "pseudo_state.h"
#include "status_bar.h"
#include "status_bar_panel.h"
#include "system_colors.h"
#include "theme.h"
#include "user_control.h"
#include "toggle_button.h"
#include "tool_bar.h"
#include "tool_bar_button.h"
#include <xtd/web/css/css_reader>
#include <xtd/event_handler>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/uri>
#include <map>
#include <vector>

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
      /// @code
      /// class forms_export_ style_sheet final : public xtd::iequatable<style_sheet>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::style_sheet
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/style_sheet> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks This class is used by xtd::forms::style_sheets::ibox_model.
      /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
      class forms_export_ style_sheet final : public xtd::iequatable<style_sheet>, public xtd::object {
        struct data;
        
      public:
        /// @name Alias
        
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
        using style_sheets_t = std::map<xtd::ustring, style_sheet>;
        /// @brief Represents a style_sheet names collection.
        using style_sheet_names_t = std::vector<xtd::ustring>;
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
        
        /// @name Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::style_sheet object.
        static const style_sheet empty;
        /// @}
        
        /// @name Constructors
        
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance.
        style_sheet();
        /// @brief Initialize a new xtd::forms::style_sheets::style_sheet instance from specified css forrmated text.
        /// @param css_text The css forrmated text that contains the style sheet definition.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        explicit style_sheet(const xtd::ustring& css_text);
        
        /// @cond
        style_sheet(const style_sheet&);
        style_sheet(style_sheet&&) = default;
        style_sheet& operator =(const style_sheet&);
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the style sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::button button() const noexcept;
        /// @brief Gets the style sheet button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::button button(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet buttons collection of this instance.
        /// @return The style sheet buttons collection.
        const buttons_t& buttons() const noexcept;
        
        /// @brief Gets the style sheet control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::control control() const noexcept;
        /// @brief Gets the style sheet control for specified pseudo state.
        /// @return A style_sheet control.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::control control(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet controls collection of this instance.
        /// @return The style sheet controls collection.
        const controls_t& controls() const noexcept;
        
        /// @brief Gets current xtd::forms::style_sheets::style_sheet style sheet.
        /// @return The current xtd::forms::style_sheets::style_sheet style sheet.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static const style_sheet& current_style_sheet() noexcept;
        /// @brief Sets current xtd::forms::style_sheets::style_sheet style sheet.
        /// @param value The current xtd::forms::style_sheets::style_sheet style sheet.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static void current_style_sheet(const style_sheet& value);
        
        /// @brief Gets the style sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::button flat_button() const noexcept;
        /// @brief Gets the style sheet button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::button flat_button(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet buttons collection of this instance.
        /// @return The style sheet buttons collection.
        const buttons_t& flat_buttons() const noexcept;
        
        /// @brief Gets the style sheet toggle_button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::toggle_button flat_toggle_button() const noexcept;
        /// @brief Gets the style sheet toggle_button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::toggle_button flat_toggle_button(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet toggle_buttons collection of this instance.
        /// @return The style sheet buttons collection.
        const toggle_buttons_t& flat_toggle_buttons() const noexcept;
        
        /// @brief Gets the style sheet form for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet form for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::form form() const noexcept;
        /// @brief Gets the style sheet form for specified pseudo state.
        /// @return A style_sheet form.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::form form(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet forms collection of this instance.
        /// @return The style sheet forms collection.
        const forms_t& forms() const noexcept;
        
        /// @brief Gets a value indicate if this instance is system style sheet.
        /// @return true if the current instance is system style sheet; otherwise false.
        /// @remarks This method return true only if the current instance is equal to xtd::forms::style_sheets::style_sheet::system_style_sheet.
        bool is_system_style_sheet() const noexcept;
        
        /// @brief Gets the style sheet label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::label label() const noexcept;
        /// @brief Gets the style sheet label for specified pseudo state.
        /// @return A style_sheet label.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::label label(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet labels collection of this instance.
        /// @return The style sheet labels collection.
        const labels_t& labels() const noexcept;
        
        /// @brief Gets the style sheet link_label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet link_label for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::link_label link_label() const noexcept;
        /// @brief Gets the style sheet link_label for specified pseudo state.
        /// @return A style_sheet link_label.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::link_label link_label(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet link_label collection of this instance.
        /// @return The style sheet link_label collection.
        const link_labels_t& link_labels() const noexcept;
        
        /// @brief Gets the style sheet panel for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet panel for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::panel panel() const noexcept;
        /// @brief Gets the style sheet panel for specified pseudo state.
        /// @return A style_sheet panel.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::panel panel(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet panels collection of this instance.
        /// @return The style sheet panels collection.
        const panels_t& panels() const noexcept;
        
        /// @brief Gets the style sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::button popup_button() const noexcept;
        /// @brief Gets the style sheet button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::button popup_button(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet buttons collection of this instance.
        /// @return The style sheet buttons collection.
        const buttons_t& popup_buttons() const noexcept;
        
        /// @brief Gets the style sheet toggle_button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::toggle_button popup_toggle_button() const noexcept;
        /// @brief Gets the style sheet toggle_button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::toggle_button popup_toggle_button(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet toggle_buttons collection of this instance.
        /// @return The style sheet buttons collection.
        const toggle_buttons_t& popup_toggle_buttons() const noexcept;
        
        /// @brief Gets the style sheet status_bar for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet status_bar for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::status_bar status_bar() const noexcept;
        /// @brief Gets the style sheet status_bar for specified pseudo state.
        /// @return A style_sheet status_bar.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::status_bar status_bar(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet status_bar collection of this instance.
        /// @return The style sheet status_bar collection.
        const status_bars_t& status_bars() const noexcept;
        
        /// @brief Gets the style sheet status bar panel for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet status bar panel for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::status_bar_panel status_bar_panel() const noexcept;
        /// @brief Gets the style sheet status bar panel for specified pseudo state.
        /// @return A style_sheet status bar panel.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::status_bar_panel status_bar_panel(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet status bar panels collection of this instance.
        /// @return The style sheet status bar panels collection.
        const status_bar_panels_t& status_bar_panels() const noexcept;
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheets.
        /// @return The installed xtd::forms::style_sheets::style_sheet style sheets.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static const style_sheets_t& style_sheets() noexcept;
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheet names.
        /// @return The installed xtd::forms::style_sheets::style_sheet names.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static const style_sheet_names_t& style_sheet_names() noexcept;
        
        /// @brief Gets The style sheet system colors of this instance.
        /// @return The style sheet systel colors collection.
        const xtd::forms::style_sheets::system_colors& system_colors() const noexcept;
        
        /// @brief Gets system xtd::forms::style_sheets::style_sheet style sheet.
        /// @return The system xtd::forms::style_sheets::style_sheet style sheet.
        /// @remarks The system style sheet is the style sheet corresponding to the current Operating System and the current Desktop Environment.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static const style_sheet& system_style_sheet() noexcept;
        
        /// @brief Gets The style sheet theme of this instance.
        /// @return The style sheet theme collection.
        const xtd::forms::style_sheets::theme& theme() const noexcept;
        
        /// @brief Gets the style sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::toggle_button toggle_button() const noexcept;
        /// @brief Gets the style sheet button for specified pseudo state.
        /// @return A style_sheet button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::toggle_button toggle_button(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet buttons collection of this instance.
        /// @return The style sheet buttons collection.
        const toggle_buttons_t& toggle_buttons() const noexcept;
        
        /// @brief Gets the style sheet tool_bar for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet tool_bar for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::tool_bar tool_bar() const noexcept;
        /// @brief Gets the style sheet tool_bar for specified pseudo state.
        /// @return A style_sheet tool_bar.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::tool_bar tool_bar(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet tool_bars collection of this instance.
        /// @return The style sheet tool_bars collection.
        const tool_bars_t& tool_bars() const noexcept;
        
        /// @brief Gets the style sheet tool bar button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet tool bar button for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::tool_bar_button tool_bar_button() const noexcept;
        /// @brief Gets the style sheet tool bar button for specified pseudo state.
        /// @return A style_sheet tool bar button.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::tool_bar_button tool_bar_button(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet tool bar buttons collection of this instance.
        /// @return The style sheet tool bar buttons collection.
        const tool_bar_buttons_t& tool_bar_buttons() const noexcept;
        
        /// @brief Gets the style sheet user_control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        /// @return A style_sheet control for the xtd::forms::style_sheets::pseudo_state::standard pseudo state.
        xtd::forms::style_sheets::user_control user_control() const noexcept;
        /// @brief Gets the style sheet user_control for specified pseudo state.
        /// @return A style_sheet user_control.
        /// @remarks if the pseudo state does not exists, the value for xtd::forms::style_sheets::pseudo_state::standard pseudo state is getted.
        xtd::forms::style_sheets::user_control user_control(xtd::forms::style_sheets::pseudo_state state) const noexcept;
        /// @brief Gets the style sheet user_control collection of this instance.
        /// @return The style sheet controls collection.
        const user_controls_t& user_controls() const noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const style_sheet& other) const noexcept override;
        
        /// @brief Gets the style sheet buttons collection from specified css string.
        /// @param css_text The css string that contains button definition.
        /// @return The style sheet buttons collection.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static buttons_t button_from_css(const  xtd::ustring& css_text);
        
        /// @brief Gets the style sheet controls collection from specified css string.
        /// @param css_text The css string that contains control definition.
        /// @return The style sheet controls collection.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static controls_t control_from_css(const  xtd::ustring& css_text);
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheet from specified name.
        /// @return The xtd::forms::style_sheets::style_sheet style sheet from name.
        /// @exception xtd::argument_exception The style sheet name not tvalid.
        /// @remarks Use xtd::forms::style_sheets::style_sheet::style_sheet_names to retreive valid style sheet names.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static style_sheet get_style_sheet_from_name(const xtd::ustring& name);
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheet from specified name.
        /// @return The xtd::forms::style_sheets::style_sheet style sheet from name.
        /// @exception xtd::argument_exception The style sheet name not tvalid.
        /// @remarks Use xtd::forms::style_sheets::style_sheet::style_sheet_names to retreive valid style sheet names.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static style_sheet get_style_sheet_from_file(const xtd::ustring& file_name);
        
        /// @brief Gets the installed xtd::forms::style_sheets::style_sheet style sheet from specified name.
        /// @return The xtd::forms::style_sheets::style_sheet style sheet from name.
        /// @exception xtd::argument_exception The style sheet name not tvalid.
        /// @remarks Use xtd::forms::style_sheets::style_sheet::style_sheet_names to retreive valid style sheet names.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static style_sheet get_style_sheet_from_path(const xtd::ustring& path_name);
        
        /// @brief Gets the style sheet forms collection from specified css string.
        /// @param css_text The css string that contains forms definition.
        /// @return The style sheet forms collection.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static forms_t form_from_css(const  xtd::ustring& css_text);
        
        /// @brief Gets the style sheet system colors from specified css string.
        /// @param css_text The css string that contains system colors definition.
        /// @return The style sheet system colors.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static xtd::forms::style_sheets::system_colors system_colors_from_css(const xtd::ustring& css_text);
        
        /// @brief Gets the style sheet theme from specified css string.
        /// @param css_text The css string that contains theme definition.
        /// @return The style sheet theme.
        /// @remarks For more information, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview">Style sheets overview</a>.
        static xtd::forms::style_sheets::theme theme_from_css(const xtd::ustring& css_text);
        
        /// @brief Converts xtd::forms::border_style in std::tuple<xtd::forms::style_sheets::border_type, int32, int32>.
        /// @param border The ::forms::border_style to convert.
        /// @return A std::tuple<xtd::forms::style_sheets::border_type, int32, int32> class that containe, border type, border width and border radius.
        static std::tuple<xtd::forms::style_sheets::border_type, int32, int32> to_border_type(xtd::forms::border_style border);
        /// @}
        
        /// @name Events
        
        /// @{
        /// @brief Occurs when the value of the xtd::forms::style_sheets::style_sheet::current_style_sheet property changes.
        /// @remarks This event is raised if the xtd::forms::style_sheets::style_sheet::current_style_sheet property is changed by either a programmatic modification or user interaction.
        /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
        static event<style_sheet, event_handler> style_sheet_changed;
        /// @}
        
      private:
        friend class ::__test_style_sheet__; // Necessary for the test unit to access the private member functions
        friend class xtd::forms::control;
        friend class xtd::forms::form;
        style_sheet(const xtd::ustring& css_text, bool init_system);
        
        xtd::drawing::color background_color_from_css(const xtd::ustring& css_text, const xtd::drawing::color& default_value) const noexcept;
        background_image background_image_from_css(const xtd::ustring& css_text, const background_image& default_value) const noexcept;
        border_color border_color_from_css(const xtd::ustring& css_text, const border_color& default_value) const noexcept;
        border_style border_style_from_css(const ustring& text, const border_style& default_value) const noexcept;
        border_radius border_radius_from_css(const xtd::ustring& css_text, const border_radius& default_value) const noexcept;
        border_width border_width_from_css(const xtd::ustring& css_text, const border_width& default_value) const noexcept;
        xtd::drawing::color color_from_css(const xtd::ustring& css_text, const xtd::drawing::color& default_value) const noexcept;
        length length_from_css(const xtd::ustring& css_text, const length& default_value) const noexcept;
        margin margin_from_css(const xtd::ustring& css_text, const margin& default_value) const noexcept;
        margin margin_bottom_from_css(const xtd::ustring& css_text, const margin& default_value) const noexcept;
        margin margin_left_from_css(const xtd::ustring& css_text, const margin& default_value) const noexcept;
        margin margin_right_from_css(const xtd::ustring& css_text, const margin& default_value) const noexcept;
        margin margin_top_from_css(const xtd::ustring& css_text, const margin& default_value) const noexcept;
        padding padding_from_css(const xtd::ustring& css_text, const padding& default_value) const noexcept;
        padding padding_bottom_from_css(const xtd::ustring& css_text, const padding& default_value) const noexcept;
        padding padding_left_from_css(const xtd::ustring& css_text, const padding& default_value) const noexcept;
        padding padding_right_from_css(const xtd::ustring& css_text, const padding& default_value) const noexcept;
        padding padding_top_from_css(const xtd::ustring& css_text, const padding& default_value) const noexcept;
        ustring string_from_css(const xtd::ustring& css_text, const xtd::ustring& default_value) const noexcept;
        xtd::forms::content_alignment text_align_from_css(const xtd::ustring& css_text, const xtd::forms::content_alignment& default_value) const noexcept;
        xtd::forms::style_sheets::text_decoration text_decoration_from_css(const xtd::ustring& css_text, const xtd::forms::style_sheets::text_decoration& default_value) const noexcept;
        xtd::forms::style_sheets::text_transformation text_transformation_from_css(const xtd::ustring& css_text, const xtd::forms::style_sheets::text_transformation& default_value) const noexcept;
        xtd::uri uri_from_css(const xtd::ustring& css_text, const xtd::uri& default_value) const noexcept;
        xtd::forms::style_sheets::white_space white_space_from_css(const xtd::ustring& css_text, const xtd::forms::style_sheets::white_space& default_value) const noexcept;
        
        template<typename type_t, typename collection_t>
        type_t get_state_control(const collection_t& collection, pseudo_state state) const noexcept {
          auto result = type_t();
          auto it = collection.find(pseudo_state::standard);
          if (it != collection.end()) result = it->second;
          it = collection.find(state);
          if (it != collection.end()) result = it->second;
          return result;
        }
        
        static void on_style_sheet_changed(const xtd::event_args& e);
        static void on_system_colors_changed(const event_args& e);
        std::vector<xtd::ustring> split_values_from_text(const xtd::ustring& text) const noexcept;
        
        void button_reader(xtd::web::css::css_reader& reader) noexcept;
        void control_reader(xtd::web::css::css_reader& reader) noexcept;
        void fill_control(const xtd::web::css::selector_map::const_iterator& selectors_iterator, xtd::forms::style_sheets::control& control) noexcept;
        void flat_button_reader(xtd::web::css::css_reader& reader) noexcept;
        void flat_toggle_button_reader(xtd::web::css::css_reader& reader) noexcept;
        void form_reader(xtd::web::css::css_reader& reader) noexcept;
        void label_reader(xtd::web::css::css_reader& reader) noexcept;
        void link_label_reader(xtd::web::css::css_reader& reader) noexcept;
        void panel_reader(xtd::web::css::css_reader& reader) noexcept;
        void popup_button_reader(xtd::web::css::css_reader& reader) noexcept;
        void popup_toggle_button_reader(xtd::web::css::css_reader& reader) noexcept;
        void status_bar_reader(xtd::web::css::css_reader& reader) noexcept;
        void status_bar_panel_reader(xtd::web::css::css_reader& reader) noexcept;
        void system_colors_reader(xtd::web::css::css_reader& reader) noexcept;
        void theme_reader(xtd::web::css::css_reader& reader) noexcept;
        void toggle_button_reader(xtd::web::css::css_reader& reader) noexcept;
        void tool_bar_reader(xtd::web::css::css_reader& reader) noexcept;
        void tool_bar_button_reader(xtd::web::css::css_reader& reader) noexcept;
        void user_control_reader(xtd::web::css::css_reader& reader) noexcept;
        
        //static style_sheet system_style_sheet_gnome_dark() noexcept; // Declared in system_style_sheet_gnome_dark.cpp
        //static style_sheet system_style_sheet_gnome_light() noexcept; // Declared in system_style_sheet_gnome_light.cpp
        //static style_sheet system_style_sheet_kde_dark() noexcept; // Declared in system_style_sheet_kde_dark.cpp
        //static style_sheet system_style_sheet_kde_light() noexcept; // Declared in system_style_sheet_kde_light.cpp
        //static style_sheet system_style_sheet_macos_dark() noexcept; // Declared in system_style_sheet_macos_dark.cpp
        //static style_sheet system_style_sheet_macos_light() noexcept; // Declared in system_style_sheet_macos_light.cpp
        static style_sheet system_style_sheet_unknown_dark() noexcept; // Declared in system_style_sheet_unknown_dark.cpp
        static style_sheet system_style_sheet_unknown_light() noexcept; // Declared in system_style_sheet_unknown_light.cpp
        //static style_sheet system_style_sheet_windows_dark() noexcept; // Declared in system_style_sheet_windows_dark.cpp
        //static style_sheet system_style_sheet_windows_light() noexcept; // Declared in system_style_sheet_windows_light.cpp
        
        bool try_parse_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hex_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_linear_gradient(const xtd::ustring& text, background_image& result) const noexcept;
        bool try_parse_named_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_rgb_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_rgba_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsv_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsva_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsl_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_hsla_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_system_color(const xtd::ustring& text, xtd::drawing::color& result) const noexcept;
        bool try_parse_uri(const xtd::ustring& text, xtd::uri& result) const noexcept;
        
        void system_colors_(const xtd::forms::style_sheets::system_colors& system_colors);
        void theme_(const xtd::forms::style_sheets::theme& theme);
        void theme_name_(const xtd::ustring& name);
        
        static style_sheet current_style_sheet_;
        static style_sheets_t style_sheets_;
        static style_sheet_names_t style_sheet_names_;
        static style_sheet system_style_sheet_;
        
        std::shared_ptr<data> data_;
      };
    }
  }
}
