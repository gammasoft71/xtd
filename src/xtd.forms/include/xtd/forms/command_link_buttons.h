/// @file
/// @brief Contains xtd::forms::command_link_buttons factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "command_link_button"
#include "system_texts"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of command_link_button objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/command_link_buttons> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of command_link_buttons control factory.
    /// @include command_link_buttons.cpp
    class command_link_buttons final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Create a system-defined command_link_button that represent abort command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button abort(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::abort(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent abort command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button abort(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::abort(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent about command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button about(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::about(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent about command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button about(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::about(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent actual size command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button actual_size(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::actual_size(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent actual size command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button actual_size(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::actual_size(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent add command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button add(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::add(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent add command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button add(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::add(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button alignment(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::alignment(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button alignment(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::alignment(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent align left command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button align_left(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::align_left(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent align left command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button align_left(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::align_left(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent align right command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button align_right(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::align_right(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent align right command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button align_right(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::align_right(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent apply command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button apply(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::apply(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent apply command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button apply(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::apply(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button ascending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::ascending(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button ascending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::ascending(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent back command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button back(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::back(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent back command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button back(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::back(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent bold command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button bold(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::bold(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent bold command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button bold(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::bold(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button bottom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::bottom(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button bottom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::bottom(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button cancel(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::cancel(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button cancel(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::cancel(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent CD-Rom command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button cdrom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::cdrom(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent CD-Rom command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button cdrom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::cdrom(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent centered command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button centered(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::centered(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent centered command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button centered(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::centered(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent clear command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button clear(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::clear(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent clear command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button clear(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::clear(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent close command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button close(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::close(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent close command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button close(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::close(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent color command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button color(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::color(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent color command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button color(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::color(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent contents command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button contents(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::contents(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent contents command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button contents(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::contents(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent convert command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button convert(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::convert(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent convert command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button convert(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::convert(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent copy command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button copy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::copy(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent copy command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button copy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::copy(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent customize command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button customize(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::customize(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent customize command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button customize(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::customize(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent cut command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button cut(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::cut(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent cut command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button cut(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::cut(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent delete command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button del(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::del(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent delete command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button del(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::del(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent descending command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button descending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::descending(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent descending command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button descending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::descending(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent down command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button down(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::down(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent down command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button down(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::down(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent edit command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button edit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::edit(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent edit command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button edit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::edit(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent execute command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button execute(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::execute(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent execute command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button execute(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::execute(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent file command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button file(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::file(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent file command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button file(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::file(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent find command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button find(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::find(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent find command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button find(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::find(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent first command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button first(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::first(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent first command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button first(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::first(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button floppy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::floppy(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button floppy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::floppy(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent font command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button font(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::font(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent font command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button font(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::font(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent forward command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button forward(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::forward(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent forward command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button forward(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::forward(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent hard disk command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button harddisk(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::harddisk(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent hard disk command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button harddisk(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::harddisk(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent help command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button help(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::help(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent help command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button help(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::help(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent home command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button home(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::home(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent home command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button home(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::home(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button ignore(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::ignore(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button ignore(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::ignore(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent indent command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button indent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::indent(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent indent command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button indent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::indent(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent index command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button index(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::index(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent index command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button index(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::index(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent info command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button info(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::info(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent info command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button info(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::info(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent italic command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button italic(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::italic(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent italic command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button italic(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::italic(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent justified command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button justified(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::justified(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent justified command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button justified(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::justified(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent jump_to command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button jump_to(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::jump_to(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent jump to command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button jump_to(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::jump_to(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent last command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button last(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::last(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent last command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button last(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::last(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent network command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button network(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::network(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent network command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button network(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::network(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent new command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button new_(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::new_(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent new command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button new_(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::new_(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent no command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button no(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::no(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent no command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button no(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::no(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent ok command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button ok(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::ok(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent ok command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button ok(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::ok(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent open command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button open(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::open(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent open command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button open(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::open(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent options command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button options(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::options(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent options command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button options(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::options(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent paste command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button paste(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::paste(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent paste command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button paste(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::paste(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button preferences(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::preferences(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button preferences(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::preferences(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent print command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button print(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::print(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent print command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button print(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::print(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent print preview command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button print_preview(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::print_preview(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent print preview command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button print_preview(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::print_preview(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent properties command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button properties(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::properties(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent properties command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button properties(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::properties(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent quit command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button quit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::quit(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent quit command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button quit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::quit(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent redo command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button redo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::redo(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent redo command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button redo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::redo(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button refresh(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::refresh(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button refresh(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::refresh(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent remove command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button remove(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::remove(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent remove command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button remove(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::remove(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent replace command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button replace(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::replace(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent replace command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button replace(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::replace(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent retry command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button retry(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::retry(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent retry command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button retry(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::retry(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent revert to saved command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button revert_to_saved(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::revert_to_saved(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent revert to saved command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button revert_to_saved(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::revert_to_saved(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent save command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button save(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::save(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent save command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button save(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::save(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent save as command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button save_as(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::save_as(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent save as command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button save_as(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::save_as(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent search command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button search(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::search(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent search command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button search(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::search(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent select all command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button select_all(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::select_all(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent select all command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button select_all(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::select_all(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent spell check command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button spell_check(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::spell_check(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent spell check command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button spell_check(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::spell_check(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent stop command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button stop(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::stop(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent stop command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button stop(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::stop(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button strikeout(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::strikeout(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button strikeout(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::strikeout(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent tools command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button tools(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::tools(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent tools command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button tools(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::tools(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent top command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button top(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::top(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent top command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button top(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::top(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button undelete(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::undelete(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button undelete(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::undelete(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent underline command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button underline(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::underline(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent underline command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button underline(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::underline(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent undo command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button undo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::undo(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent undo command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button undo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::undo(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represents an unindented command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button unindent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::unindent(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represents an unindented command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button unindent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::unindent(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent up command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button up(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::up(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent up command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button up(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::up(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent view command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button view(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::view(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent view command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button view(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::view(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent yes command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button yes(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::yes(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent yes command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button yes(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::yes(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent zoom in command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button zoom_in(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::zoom_in(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent zoom in command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button zoom_in(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::zoom_in(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent zoom out command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button zoom_out(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::zoom_out(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent zoom out command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button zoom_out(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::zoom_out(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent zoom to fit command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button zoom_to_fit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(system_texts::zoom_to_fit(), location, size, name);}
      /// @brief Create a system-defined command_link_button that represent zoom to fit command_link_button.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      command_link_button zoom_to_fit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return command_link_button::create(parent, system_texts::zoom_to_fit(), location, size, name);}
      /// @}
    };
  }
}
