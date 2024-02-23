/// @file
/// @brief Contains xtd::forms::radio_buttons factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "radio_button.h"
#include <xtd/drawing/texts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of radio_button objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/radio_buttons> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of radio_button control factory.
    /// @include radio_buttons.cpp
    class forms_export_ radio_buttons final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Create a system-defined radio_button that represent abort radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button abort(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::abort(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent abort radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button abort(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::abort(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent about radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button about(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::about(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent about radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button about(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::about(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent actual size radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button actual_size(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::actual_size(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent actual size radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button actual_size(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::actual_size(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent add radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button add(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::add(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent add radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button add(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::add(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent alignment radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button alignment(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::alignment(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent alignment radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button alignment(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::alignment(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent align left radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_left(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::align_left(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent align left radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_left(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::align_left(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent align right radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_right(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::align_right(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent align right radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_right(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::align_right(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent apply radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button apply(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::apply(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent apply radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button apply(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::apply(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent ascending radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ascending(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::ascending(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent ascending radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ascending(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::ascending(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent back radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button back(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::back(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent back radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button back(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::back(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent bold radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bold(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::bold(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent bold radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bold(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::bold(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent bottom radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bottom(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::bottom(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent bottom radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bottom(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::bottom(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent cancel radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cancel(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::cancel(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent cancel radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cancel(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::cancel(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent CD-Rom radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cdrom(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::cdrom(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent CD-Rom radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cdrom(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::cdrom(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent centered radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button centered(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::centered(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent centered radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button centered(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::centered(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent clear radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button clear(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::clear(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent clear radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button clear(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::clear(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent close radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button close(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::close(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent close radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button close(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::close(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent color radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button color(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::color(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent color radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button color(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::color(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent contents radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button contents(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::contents(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent contents radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button contents(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::contents(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent convert radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button convert(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::convert(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent convert radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button convert(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::convert(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent copy radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button copy(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::copy(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent copy radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button copy(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::copy(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent customize radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button customize(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::customize(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent customize radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button customize(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::customize(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent cut radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cut(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::cut(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent cut radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cut(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::cut(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent delete radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button del(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::del(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent delete radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button del(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::del(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent descending radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button descending(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::descending(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent descending radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button descending(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::descending(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent down radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button down(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::down(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent down radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button down(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::down(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent edit radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button edit(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::edit(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent edit radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button edit(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::edit(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent execute radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button execute(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::execute(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent execute radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button execute(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::execute(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent file radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button file(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::file(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent file radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button file(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::file(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent find radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button find(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::find(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent find radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button find(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::find(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent first radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button first(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::first(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent first radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button first(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::first(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent floppy radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button floppy(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::floppy(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent floppy radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button floppy(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::floppy(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent font radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button font(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::font(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent font radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button font(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::font(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent forward radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button forward(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::forward(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent forward radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button forward(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::forward(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent hard disk radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button harddisk(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::harddisk(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent hard disk radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button harddisk(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::harddisk(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent help radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button help(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::help(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent help radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button help(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::help(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent home radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button home(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::home(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent home radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button home(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::home(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent ignore radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ignore(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::ignore(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent ignore radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ignore(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::ignore(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent indent radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button indent(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::indent(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent indent radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button indent(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::indent(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent index radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button index(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::index(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent index radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button index(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::index(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent info radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button info(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::info(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent info radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button info(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::info(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent italic radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button italic(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::italic(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent italic radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button italic(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::italic(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent justified radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button justified(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::justified(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent justified radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button justified(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::justified(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent jump_to radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button jump_to(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::jump_to(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent jump to radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button jump_to(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::jump_to(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent last radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button last(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::last(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent last radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button last(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::last(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent network radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button network(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::network(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent network radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button network(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::network(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent new radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button new_(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::new_(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent new radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button new_(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::new_(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent no radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button no(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::no(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent no radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button no(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::no(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent ok radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ok(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::ok(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent ok radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ok(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::ok(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent open radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button open(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::open(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent open radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button open(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::open(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent options radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button options(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::options(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent options radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button options(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::options(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent paste radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button paste(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::paste(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent paste radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button paste(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::paste(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent preferences radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button preferences(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::preferences(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent preferences radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button preferences(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::preferences(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent print radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::print(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent print radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::print(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent print preview radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print_preview(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::print_preview(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent print preview radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print_preview(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::print_preview(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent properties radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button properties(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::properties(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent properties radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button properties(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::properties(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent quit radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button quit(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::quit(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent quit radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button quit(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::quit(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent redo radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button redo(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::redo(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent redo radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button redo(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::redo(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent refresh radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button refresh(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::refresh(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent refresh radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button refresh(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::refresh(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent remove radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button remove(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::remove(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent remove radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button remove(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::remove(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent replace radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button replace(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::replace(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent replace radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button replace(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::replace(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent retry radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button retry(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::retry(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent retry radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button retry(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::retry(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent revert to saved radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button revert_to_saved(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::revert_to_saved(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent revert to saved radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::revert_to_saved(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent save radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::save(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent save radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::save(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent save as radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save_as(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::save_as(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent save as radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save_as(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::save_as(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent search radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button search(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::search(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent search radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button search(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::search(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent select all radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button select_all(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::select_all(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent select all radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button select_all(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::select_all(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent spell check radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button spell_check(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::spell_check(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent spell check radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button spell_check(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::spell_check(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent stop radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button stop(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::stop(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent stop radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button stop(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::stop(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent strikeout radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button strikeout(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::strikeout(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent strikeout radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button strikeout(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::strikeout(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent tools radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button tools(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::tools(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent tools radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button tools(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::tools(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent top radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button top(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::top(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent top radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button top(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::top(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent undelete radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undelete(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::undelete(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent undelete radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undelete(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::undelete(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent underline radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button underline(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::underline(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent underline radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button underline(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::underline(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent undo radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undo(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::undo(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent undo radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undo(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::undo(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represents an unindented radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button unindent(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::unindent(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represents an unindented radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button unindent(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::unindent(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent up radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button up(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::up(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent up radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button up(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::up(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent view radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button view(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::view(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent view radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button view(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::view(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent yes radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button yes(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::yes(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent yes radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button yes(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::yes(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent zoom in radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_in(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::zoom_in(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent zoom in radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_in(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::zoom_in(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent zoom out radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_out(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::zoom_out(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent zoom out radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_out(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::zoom_out(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent zoom to fit radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(xtd::drawing::texts::zoom_to_fit(), checked, location, size, name);}
      /// @brief Create a system-defined radio_button that represent zoom to fit radio_button.
      /// @param parent The control that contains the radio_button.
      /// @param checked true if the check box is checked; otherwise, false.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const control& parent, bool checked = false, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return radio_button::create(parent, xtd::drawing::texts::zoom_to_fit(), checked, location, size, name);}
      /// @}
    };
  }
}
