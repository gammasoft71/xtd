/// @file
/// @brief Contains xtd::forms::light_buttons factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "light_button"
#include "system_texts"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of light_button objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/light_buttons> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of light_buttons control factory.
    /// @include light_buttons.cpp
    class light_buttons final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Create a system-defined light_button that represent abort light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button abort(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::abort(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent abort light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button abort(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::abort(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent about light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button about(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::about(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent about light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button about(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::about(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent actual size light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button actual_size(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::actual_size(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent actual size light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button actual_size(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::actual_size(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent add light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button add(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::add(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent add light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button add(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::add(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent alignment light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button alignment(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::alignment(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent alignment light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button alignment(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::alignment(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent align left light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button align_left(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::align_left(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent align left light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button align_left(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::align_left(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent align right light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button align_right(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::align_right(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent align right light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button align_right(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::align_right(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent apply light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button apply(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::apply(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent apply light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button apply(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::apply(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent ascending light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button ascending(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::ascending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent ascending light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button ascending(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::ascending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent back light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button back(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::back(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent back light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button back(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::back(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent bold light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button bold(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::bold(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent bold light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button bold(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::bold(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent bottom light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button bottom(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::bottom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent bottom light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button bottom(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::bottom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent cancel light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button cancel(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::cancel(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent cancel light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button cancel(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::cancel(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent CD-Rom light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button cdrom(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::cdrom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent CD-Rom light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button cdrom(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::cdrom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent centered light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button centered(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::centered(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent centered light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button centered(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::centered(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent clear light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button clear(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::clear(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent clear light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button clear(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::clear(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent close light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button close(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::close(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent close light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button close(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::close(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent color light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button color(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::color(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent color light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button color(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::color(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent contents light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button contents(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::contents(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent contents light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button contents(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::contents(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent convert light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button convert(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::convert(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent convert light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button convert(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::convert(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent copy light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button copy(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::copy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent copy light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button copy(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::copy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent customize light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button customize(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::customize(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent customize light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button customize(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::customize(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent cut light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button cut(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::cut(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent cut light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button cut(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::cut(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent delete light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button del(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::del(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent delete light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button del(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::del(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent descending light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button descending(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::descending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent descending light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button descending(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::descending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent down light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button down(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::down(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent down light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button down(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::down(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent edit light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button edit(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::edit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent edit light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button edit(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::edit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent execute light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button execute(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::execute(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent execute light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button execute(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::execute(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent file light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button file(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::file(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent file light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button file(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::file(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent find light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button find(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::find(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent find light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button find(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::find(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent first light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button first(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::first(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent first light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button first(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::first(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent floppy light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button floppy(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::floppy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent floppy light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button floppy(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::floppy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent font light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button font(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::font(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent font light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button font(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::font(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent forward light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button forward(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::forward(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent forward light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button forward(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::forward(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent hard disk light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button harddisk(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::harddisk(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent hard disk light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button harddisk(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::harddisk(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent help light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button help(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::help(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent help light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button help(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::help(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent home light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button home(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::home(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent home light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button home(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::home(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent ignore light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button ignore(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::ignore(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent ignore light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button ignore(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::ignore(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent indent light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button indent(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::indent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent indent light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button indent(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::indent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent index light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button index(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::index(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent index light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button index(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::index(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent info light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button info(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::info(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent info light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button info(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::info(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent italic light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button italic(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::italic(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent italic light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button italic(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::italic(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent justified light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button justified(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::justified(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent justified light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button justified(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::justified(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent jump_to light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button jump_to(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::jump_to(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent jump to light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button jump_to(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::jump_to(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent last light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button last(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::last(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent last light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button last(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::last(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent network light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button network(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::network(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent network light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button network(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::network(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent new light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button new_(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::new_(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent new light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button new_(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::new_(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent no light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button no(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::no(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent no light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button no(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::no(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent ok light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button ok(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::ok(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent ok light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button ok(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::ok(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent open light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button open(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::open(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent open light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button open(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::open(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent options light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button options(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::options(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent options light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button options(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::options(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent paste light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button paste(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::paste(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent paste light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button paste(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::paste(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent preferences light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button preferences(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::preferences(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent preferences light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button preferences(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::preferences(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent print light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button print(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::print(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent print light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button print(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::print(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent print preview light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button print_preview(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::print_preview(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent print preview light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button print_preview(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::print_preview(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent properties light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button properties(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::properties(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent properties light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button properties(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::properties(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent quit light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button quit(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::quit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent quit light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button quit(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::quit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent redo light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button redo(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::redo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent redo light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button redo(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::redo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent refresh light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button refresh(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::refresh(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent refresh light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button refresh(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::refresh(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent remove light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button remove(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::remove(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent remove light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button remove(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::remove(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent replace light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button replace(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::replace(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent replace light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button replace(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::replace(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent retry light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button retry(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::retry(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent retry light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button retry(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::retry(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent revert to saved light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button revert_to_saved(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::revert_to_saved(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent revert to saved light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button revert_to_saved(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::revert_to_saved(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent save light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button save(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::save(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent save light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button save(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::save(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent save as light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button save_as(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::save_as(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent save as light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button save_as(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::save_as(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent search light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button search(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::search(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent search light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button search(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::search(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent select all light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button select_all(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::select_all(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent select all light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button select_all(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::select_all(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent spell check light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button spell_check(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::spell_check(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent spell check light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button spell_check(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::spell_check(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent stop light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button stop(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::stop(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent stop light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button stop(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::stop(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent strikeout light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button strikeout(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::strikeout(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent strikeout light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button strikeout(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::strikeout(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent tools light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button tools(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::tools(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent tools light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button tools(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::tools(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent top light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button top(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::top(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent top light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button top(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::top(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent undelete light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button undelete(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::undelete(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent undelete light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button undelete(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::undelete(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent underline light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button underline(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::underline(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent underline light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button underline(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::underline(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent undo light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button undo(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::undo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent undo light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button undo(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::undo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represents an unindented light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button unindent(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::unindent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represents an unindented light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button unindent(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::unindent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent up light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button up(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::up(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent up light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button up(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::up(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent view light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button view(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::view(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent view light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button view(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::view(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent yes light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button yes(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::yes(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent yes light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button yes(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::yes(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent zoom in light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button zoom_in(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::zoom_in(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent zoom in light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button zoom_in(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::zoom_in(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent zoom out light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button zoom_out(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::zoom_out(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent zoom out light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button zoom_out(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::zoom_out(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent zoom to fit light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button zoom_to_fit(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(system_texts::zoom_to_fit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined light_button that represent zoom to fit light_button.
      /// @param parent The control that contains the light_button.
      /// @param three_state true if the light_button is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The light_button location in pixels.
      /// @param size The light_button size in pixels.
      /// @param name The name of the light_button.
      /// @return The created light_button.
      static light_button zoom_to_fit(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return light_button::create(parent, system_texts::zoom_to_fit(), three_state, check_state, location, size, name);}
      /// @}
    };
  }
}
