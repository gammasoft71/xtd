/// @file
/// @brief Contains xtd::forms::check_boxes factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "check_box"
#include "system_texts"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of check_box objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/check_boxes> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of check_boxes control factory.
    /// @include check_boxes.cpp
    class check_boxes final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Create a system-defined check_box that represent abort check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box abort(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::abort(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent abort check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box abort(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::abort(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent about check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box about(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::about(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent about check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box about(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::about(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent actual size check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box actual_size(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::actual_size(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent actual size check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box actual_size(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::actual_size(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent add check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box add(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::add(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent add check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box add(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::add(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent alignment check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box alignment(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::alignment(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent alignment check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box alignment(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::alignment(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent align left check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box align_left(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::align_left(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent align left check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box align_left(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::align_left(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent align right check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box align_right(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::align_right(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent align right check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box align_right(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::align_right(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent apply check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box apply(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::apply(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent apply check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box apply(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::apply(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ascending check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box ascending(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::ascending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ascending check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box ascending(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::ascending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent back check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box back(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::back(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent back check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box back(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::back(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent bold check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box bold(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::bold(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent bold check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box bold(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::bold(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent bottom check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box bottom(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::bottom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent bottom check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box bottom(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::bottom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent cancel check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box cancel(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::cancel(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent cancel check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box cancel(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::cancel(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent CD-Rom check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box cdrom(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::cdrom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent CD-Rom check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box cdrom(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::cdrom(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent centered check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box centered(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::centered(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent centered check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box centered(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::centered(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent clear check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box clear(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::clear(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent clear check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box clear(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::clear(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent close check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box close(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::close(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent close check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box close(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::close(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent color check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box color(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::color(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent color check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box color(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::color(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent contents check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box contents(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::contents(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent contents check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box contents(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::contents(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent convert check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box convert(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::convert(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent convert check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box convert(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::convert(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent copy check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box copy(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::copy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent copy check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box copy(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::copy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent customize check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box customize(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::customize(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent customize check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box customize(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::customize(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent cut check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box cut(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::cut(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent cut check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box cut(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::cut(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent delete check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box del(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::del(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent delete check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box del(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::del(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent descending check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box descending(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::descending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent descending check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box descending(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::descending(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent down check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box down(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::down(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent down check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box down(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::down(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent edit check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box edit(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::edit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent edit check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box edit(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::edit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent execute check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box execute(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::execute(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent execute check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box execute(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::execute(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent file check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box file(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::file(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent file check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box file(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::file(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent find check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box find(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::find(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent find check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box find(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::find(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent first check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box first(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::first(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent first check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box first(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::first(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent floppy check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box floppy(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::floppy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent floppy check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box floppy(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::floppy(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent font check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box font(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::font(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent font check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box font(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::font(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent forward check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box forward(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::forward(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent forward check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box forward(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::forward(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent hard disk check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box harddisk(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::harddisk(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent hard disk check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box harddisk(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::harddisk(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent help check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box help(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::help(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent help check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box help(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::help(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent home check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box home(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::home(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent home check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box home(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::home(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ignore check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box ignore(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::ignore(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ignore check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box ignore(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::ignore(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent indent check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box indent(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::indent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent indent check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box indent(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::indent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent index check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box index(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::index(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent index check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box index(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::index(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent info check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box info(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::info(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent info check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box info(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::info(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent italic check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box italic(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::italic(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent italic check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box italic(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::italic(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent justified check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box justified(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::justified(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent justified check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box justified(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::justified(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent jump_to check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box jump_to(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::jump_to(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent jump to check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box jump_to(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::jump_to(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent last check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box last(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::last(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent last check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box last(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::last(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent network check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box network(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::network(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent network check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box network(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::network(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent new check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box new_(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::new_(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent new check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box new_(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::new_(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent no check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box no(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::no(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent no check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box no(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::no(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ok check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box ok(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::ok(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ok check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box ok(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::ok(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent open check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box open(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::open(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent open check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box open(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::open(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent options check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box options(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::options(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent options check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box options(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::options(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent paste check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box paste(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::paste(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent paste check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box paste(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::paste(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent preferences check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box preferences(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::preferences(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent preferences check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box preferences(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::preferences(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent print check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box print(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::print(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent print check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box print(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::print(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent print preview check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box print_preview(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::print_preview(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent print preview check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box print_preview(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::print_preview(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent properties check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box properties(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::properties(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent properties check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box properties(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::properties(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent quit check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box quit(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::quit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent quit check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box quit(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::quit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent redo check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box redo(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::redo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent redo check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box redo(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::redo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent refresh check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box refresh(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::refresh(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent refresh check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box refresh(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::refresh(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent remove check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box remove(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::remove(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent remove check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box remove(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::remove(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent replace check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box replace(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::replace(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent replace check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box replace(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::replace(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent retry check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box retry(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::retry(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent retry check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box retry(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::retry(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent revert to saved check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box revert_to_saved(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::revert_to_saved(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent revert to saved check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box revert_to_saved(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::revert_to_saved(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent save check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box save(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::save(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent save check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box save(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::save(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent save as check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box save_as(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::save_as(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent save as check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box save_as(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::save_as(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent search check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box search(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::search(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent search check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box search(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::search(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent select all check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box select_all(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::select_all(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent select all check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box select_all(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::select_all(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent spell check check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box spell_check(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::spell_check(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent spell check check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box spell_check(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::spell_check(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent stop check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box stop(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::stop(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent stop check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box stop(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::stop(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent strikeout check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box strikeout(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::strikeout(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent strikeout check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box strikeout(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::strikeout(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent tools check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box tools(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::tools(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent tools check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box tools(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::tools(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent top check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box top(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::top(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent top check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box top(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::top(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent undelete check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box undelete(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::undelete(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent undelete check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box undelete(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::undelete(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent underline check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box underline(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::underline(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent underline check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box underline(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::underline(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent undo check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box undo(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::undo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent undo check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box undo(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::undo(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represents an unindented check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box unindent(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::unindent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represents an unindented check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box unindent(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::unindent(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent up check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box up(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::up(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent up check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box up(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::up(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent view check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box view(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::view(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent view check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box view(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::view(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent yes check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box yes(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::yes(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent yes check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box yes(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::yes(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom in check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box zoom_in(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::zoom_in(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom in check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box zoom_in(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::zoom_in(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom out check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box zoom_out(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::zoom_out(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom out check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box zoom_out(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::zoom_out(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom to fit check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box zoom_to_fit(bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::zoom_to_fit(), three_state, check_state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom to fit check_box.
      /// @param parent The control that contains the check_box.
      /// @param three_state true if the check_box is able to display three check states; otherwise, false.
      /// @param check_state One of the check_state enumeration values.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param name The name of the check_box.
      /// @return The created check_box.
      static check_box zoom_to_fit(const control& parent, bool three_state = false, xtd::forms::check_state check_state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::zoom_to_fit(), three_state, check_state, location, size, name);}
      /// @}
    };
  }
}
