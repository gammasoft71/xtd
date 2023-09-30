/// @file
/// @brief Contains xtd::forms::toggle_buttons factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "system_texts.h"
#include "toggle_button.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of toggle_button objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/toggle_buttons> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of toggle_buttons factory.
    /// @include toggle_buttons.cpp
    class forms_export_ toggle_buttons final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Create a system-defined toggle_button that represent abort toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button abort(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::abort(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent abort toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button abort(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::abort(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent about toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button about(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::about(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent about toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button about(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::about(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent actual size toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button actual_size(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::actual_size(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent actual size toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button actual_size(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::actual_size(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent add toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button add(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::add(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent add toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button add(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::add(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent alignment toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button alignment(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::alignment(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent alignment toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button alignment(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::alignment(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent align left toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button align_left(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::align_left(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent align left toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button align_left(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::align_left(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent align right toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button align_right(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::align_right(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent align right toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button align_right(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::align_right(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent apply toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button apply(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::apply(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent apply toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button apply(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::apply(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent ascending toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button ascending(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::ascending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent ascending toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button ascending(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::ascending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent back toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button back(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::back(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent back toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button back(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::back(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent bold toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button bold(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::bold(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent bold toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button bold(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::bold(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent bottom toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button bottom(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::bottom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent bottom toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button bottom(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::bottom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent cancel toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button cancel(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::cancel(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent cancel toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button cancel(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::cancel(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent CD-Rom toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button cdrom(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::cdrom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent CD-Rom toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button cdrom(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::cdrom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent centered toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button centered(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::centered(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent centered toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button centered(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::centered(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent clear toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button clear(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::clear(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent clear toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button clear(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::clear(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent close toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button close(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::close(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent close toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button close(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::close(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent color toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button color(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::color(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent color toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button color(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::color(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent contents toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button contents(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::contents(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent contents toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button contents(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::contents(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent convert toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button convert(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::convert(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent convert toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button convert(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::convert(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent copy toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button copy(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::copy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent copy toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button copy(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::copy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent customize toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button customize(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::customize(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent customize toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button customize(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::customize(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent cut toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button cut(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::cut(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent cut toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button cut(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::cut(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent delete toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button del(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::del(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent delete toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button del(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::del(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent descending toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button descending(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::descending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent descending toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button descending(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::descending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent down toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button down(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::down(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent down toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button down(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::down(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent edit toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button edit(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::edit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent edit toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button edit(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::edit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent execute toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button execute(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::execute(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent execute toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button execute(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::execute(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent file toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button file(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::file(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent file toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button file(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::file(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent find toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button find(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::find(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent find toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button find(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::find(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent first toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button first(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::first(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent first toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button first(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::first(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent floppy toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button floppy(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::floppy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent floppy toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button floppy(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::floppy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent font toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button font(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::font(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent font toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button font(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::font(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent forward toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button forward(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::forward(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent forward toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button forward(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::forward(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent harddisk toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button harddisk(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::harddisk(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent harddisk toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button harddisk(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::harddisk(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent help toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button help(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::help(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent help toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button help(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::help(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent home toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button home(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::home(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent home toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button home(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::home(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent ignore toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button ignore(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::ignore(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent ignore toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button ignore(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::ignore(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent indent toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button indent(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::indent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent indent toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button indent(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::indent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent index toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button index(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::index(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent index toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button index(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::index(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent info toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button info(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::info(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent info toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button info(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::info(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent italic toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button italic(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::italic(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent italic toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button italic(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::italic(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent justified toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button justified(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::justified(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent justified toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button justified(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::justified(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent jump_to toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button jump_to(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::jump_to(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent jump to toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button jump_to(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::jump_to(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent last toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button last(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::last(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent last toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button last(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::last(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent network toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button network(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::network(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent network toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button network(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::network(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent new toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button new_(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::new_(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent new toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button new_(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::new_(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent no toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button no(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::no(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent no toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button no(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::no(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent ok toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button ok(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::ok(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent ok toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button ok(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::ok(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent open toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button open(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::open(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent open toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button open(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::open(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent options toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button options(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::options(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent options toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button options(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::options(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent paste toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button paste(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::paste(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent paste toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button paste(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::paste(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent preferences toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button preferences(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::preferences(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent preferences toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button preferences(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::preferences(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent print toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button print(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::print(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent print toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button print(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::print(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent print preview toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button print_preview(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::print_preview(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent print preview toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button print_preview(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::print_preview(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent properties toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button properties(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::properties(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent properties toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button properties(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::properties(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent quit toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button quit(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::quit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent quit toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button quit(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::quit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent redo toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button redo(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::redo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent redo toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button redo(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::redo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent refresh toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button refresh(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::refresh(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent refresh toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button refresh(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::refresh(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent remove toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button remove(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::remove(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent remove toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button remove(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::remove(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent replace toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button replace(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::replace(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent replace toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button replace(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::replace(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent retry toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button retry(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::retry(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent retry toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button retry(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::retry(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent revert to saved toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button revert_to_saved(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::revert_to_saved(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent revert to saved toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button revert_to_saved(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::revert_to_saved(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent save toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button save(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::save(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent save toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button save(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::save(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent save as toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button save_as(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::save_as(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent save as toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button save_as(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::save_as(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent search toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button search(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::search(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent search toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button search(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::search(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent select all toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button select_all(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::select_all(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent select all toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button select_all(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::select_all(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent spell check toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button spell_check(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::spell_check(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent spell check toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button spell_check(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::spell_check(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent stop toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button stop(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::stop(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent stop toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button stop(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::stop(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent strikeout toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button strikeout(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::strikeout(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent strikeout toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button strikeout(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::strikeout(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent tools toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button tools(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::tools(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent tools toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button tools(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::tools(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent top toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button top(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::top(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent top toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button top(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::top(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent undelete toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button undelete(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::undelete(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent undelete toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button undelete(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::undelete(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent underline toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button underline(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::underline(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent underline toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button underline(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::underline(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent undo toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button undo(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::undo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent undo toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button undo(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::undo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represents an unindented toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button unindent(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::unindent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represents an unindented toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button unindent(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::unindent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent up toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button up(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::up(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent up toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button up(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::up(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent view toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button view(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::view(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent view toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button view(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::view(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent yes toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button yes(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::yes(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent yes toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button yes(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::yes(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent zoom in toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button zoom_in(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::zoom_in(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent zoom in toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button zoom_in(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::zoom_in(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent zoom out toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button zoom_out(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::zoom_out(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent zoom out toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button zoom_out(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::zoom_out(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent zoom to fit toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button zoom_to_fit(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(system_texts::zoom_to_fit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined toggle_button that represent zoom to fit toggle_button.
      /// @param parent The control that contains the toggle_button.
      /// @param three_state true if the toggle_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The toggle_button location in pixels.
      /// @param size The toggle_button size in pixels.
      /// @param name The name of the toggle_button.
      /// @return The created toggle_button.
      static toggle_button zoom_to_fit(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return toggle_button::create(parent, system_texts::zoom_to_fit(), three_state, check_state, location, size, name);}
      /// @}
    };
  }
}
