/// @file
/// @brief Contains xtd::forms::check_boxes factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "check_box.h"
#include "system_texts.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of check_box objects for use by a Windows Forms application.
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
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box abort(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::abort(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent abort check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box abort(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::abort(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent about check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box about(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::about(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent about check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box about(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::about(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent actual size check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box actual_size(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::actual_size(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent actual size check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box actual_size(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::actual_size(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent add check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box add(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::add(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent add check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box add(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::add(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent alignment check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box alignment(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::alignment(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent alignment check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box alignment(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::alignment(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent align left check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box align_left(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::align_left(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent align left check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box align_left(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::align_left(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent align right check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box align_right(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::align_right(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent align right check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box align_right(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::align_right(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent apply check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box apply(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::apply(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent apply check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box apply(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::apply(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ascending check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box ascending(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::ascending(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ascending check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box ascending(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::ascending(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent back check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box back(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::back(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent back check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box back(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::back(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent bold check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box bold(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::bold(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent bold check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box bold(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::bold(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent bottom check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box bottom(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::bottom(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent bottom check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box bottom(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::bottom(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent cancel check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box cancel(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::cancel(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent cancel check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box cancel(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::cancel(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent CD-Rom check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box cdrom(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::cdrom(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent CD-Rom check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box cdrom(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::cdrom(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent centered check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box centered(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::centered(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent centered check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box centered(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::centered(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent clear check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box clear(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::clear(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent clear check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box clear(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::clear(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent close check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box close(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::close(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent close check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box close(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::close(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent color check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box color(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::color(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent color check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box color(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::color(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent contents check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box contents(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::contents(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent contents check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box contents(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::contents(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent convert check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box convert(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::convert(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent convert check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box convert(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::convert(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent copy check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box copy(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::copy(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent copy check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box copy(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::copy(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent customize check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box customize(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::customize(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent customize check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box customize(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::customize(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent cut check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box cut(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::cut(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent cut check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box cut(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::cut(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent delete check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box del(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::del(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent delete check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box del(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::del(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent descending check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box descending(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::descending(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent descending check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box descending(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::descending(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent down check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box down(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::down(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent down check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box down(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::down(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent edit check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box edit(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::edit(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent edit check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box edit(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::edit(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent execute check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box execute(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::execute(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent execute check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box execute(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::execute(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent file check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box file(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::file(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent file check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box file(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::file(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent find check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box find(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::find(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent find check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box find(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::find(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent first check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box first(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::first(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent first check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box first(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::first(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent floppy check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box floppy(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::floppy(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent floppy check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box floppy(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::floppy(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent font check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box font(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::font(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent font check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box font(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::font(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent forward check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box forward(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::forward(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent forward check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box forward(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::forward(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent hard disk check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box harddisk(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::harddisk(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent hard disk check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box harddisk(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::harddisk(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent help check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box help(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::help(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent help check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box help(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::help(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent home check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box home(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::home(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent home check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box home(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::home(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ignore check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box ignore(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::ignore(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ignore check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box ignore(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::ignore(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent indent check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box indent(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::indent(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent indent check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box indent(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::indent(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent index check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box index(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::index(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent index check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box index(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::index(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent info check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box info(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::info(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent info check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box info(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::info(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent italic check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box italic(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::italic(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent italic check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box italic(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::italic(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent justified check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box justified(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::justified(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent justified check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box justified(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::justified(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent jump_to check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box jump_to(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::jump_to(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent jump to check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box jump_to(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::jump_to(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent last check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box last(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::last(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent last check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box last(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::last(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent network check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box network(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::network(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent network check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box network(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::network(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent new check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box new_(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::new_(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent new check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box new_(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::new_(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent no check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box no(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::no(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent no check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box no(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::no(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ok check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box ok(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::ok(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent ok check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box ok(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::ok(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent open check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box open(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::open(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent open check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box open(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::open(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent options check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box options(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::options(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent options check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box options(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::options(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent paste check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box paste(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::paste(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent paste check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box paste(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::paste(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent preferences check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box preferences(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::preferences(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent preferences check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box preferences(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::preferences(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent print check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box print(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::print(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent print check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box print(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::print(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent print preview check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box print_preview(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::print_preview(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent print preview check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box print_preview(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::print_preview(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent properties check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box properties(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::properties(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent properties check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box properties(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::properties(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent quit check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box quit(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::quit(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent quit check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box quit(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::quit(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent redo check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box redo(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::redo(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent redo check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box redo(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::redo(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent refresh check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box refresh(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::refresh(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent refresh check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box refresh(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::refresh(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent remove check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box remove(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::remove(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent remove check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box remove(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::remove(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent replace check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box replace(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::replace(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent replace check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box replace(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::replace(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent retry check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box retry(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::retry(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent retry check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box retry(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::retry(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent revert to saved check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box revert_to_saved(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::revert_to_saved(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent revert to saved check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box revert_to_saved(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::revert_to_saved(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent save check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box save(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::save(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent save check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box save(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::save(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent save as check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box save_as(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::save_as(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent save as check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box save_as(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::save_as(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent search check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box search(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::search(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent search check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box search(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::search(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent select all check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box select_all(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::select_all(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent select all check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box select_all(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::select_all(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent spell check check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box spell_check(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::spell_check(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent spell check check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box spell_check(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::spell_check(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent stop check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box stop(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::stop(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent stop check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box stop(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::stop(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent strikeout check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box strikeout(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::strikeout(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent strikeout check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box strikeout(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::strikeout(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent tools check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box tools(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::tools(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent tools check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box tools(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::tools(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent top check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box top(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::top(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent top check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box top(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::top(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent undelete check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box undelete(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::undelete(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent undelete check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box undelete(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::undelete(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent underline check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box underline(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::underline(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent underline check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box underline(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::underline(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent undo check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box undo(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::undo(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent undo check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box undo(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::undo(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represents an unindented check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box unindent(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::unindent(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represents an unindented check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box unindent(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::unindent(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent up check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box up(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::up(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent up check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box up(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::up(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent view check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box view(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::view(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent view check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box view(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::view(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent yes check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box yes(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::yes(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent yes check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box yes(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::yes(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom in check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box zoom_in(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::zoom_in(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom in check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box zoom_in(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::zoom_in(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom out check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box zoom_out(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::zoom_out(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom out check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box zoom_out(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::zoom_out(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom to fit check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box zoom_to_fit(xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(system_texts::zoom_to_fit(), state, location, size, name);}
      /// @brief Create a system-defined check_box that represent zoom to fit check_box.
      /// @param parent The control that contains the check_box.
      /// @param location The check_box location in pixels.
      /// @param size The check_box size in pixels.
      /// @param back_color The check_box background color.
      /// @param fore_core The check_box foreground color.
      /// @return The created check_box.
      static check_box zoom_to_fit(const control& parent, xtd::forms::check_state state = xtd::forms::check_state::unchecked, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return check_box::create(parent, system_texts::zoom_to_fit(), state, location, size, name);}
      /// @}
    };
  }
}
