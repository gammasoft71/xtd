/// @file
/// @brief Contains xtd::forms::buttons factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "button.h"
#include "system_texts.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of button objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/buttons> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of buttons control factory.
    /// @include buttons.cpp
    class buttons final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Create a system-defined button that represent abort button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button abort(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::abort(), location, size, name);}
      /// @brief Create a system-defined button that represent abort button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button abort(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::abort(), location, size, name);}
      /// @brief Create a system-defined button that represent about button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button about(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::about(), location, size, name);}
      /// @brief Create a system-defined button that represent about button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button about(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::about(), location, size, name);}
      /// @brief Create a system-defined button that represent actual size button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button actual_size(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::actual_size(), location, size, name);}
      /// @brief Create a system-defined button that represent actual size button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button actual_size(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::actual_size(), location, size, name);}
      /// @brief Create a system-defined button that represent add button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      button add(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::add(), location, size, name);}
      /// @brief Create a system-defined button that represent add button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button add(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::add(), location, size, name);}
      /// @brief Create a system-defined button that represent alignment button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button alignment(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::alignment(), location, size, name);}
      /// @brief Create a system-defined button that represent alignment button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button alignment(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::alignment(), location, size, name);}
      /// @brief Create a system-defined button that represent align left button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button align_left(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::align_left(), location, size, name);}
      /// @brief Create a system-defined button that represent align left button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button align_left(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::align_left(), location, size, name);}
      /// @brief Create a system-defined button that represent align right button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button align_right(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::align_right(), location, size, name);}
      /// @brief Create a system-defined button that represent align right button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button align_right(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::align_right(), location, size, name);}
      /// @brief Create a system-defined button that represent apply button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button apply(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::apply(), location, size, name);}
      /// @brief Create a system-defined button that represent apply button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button apply(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::apply(), location, size, name);}
      /// @brief Create a system-defined button that represent ascending button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ascending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::ascending(), location, size, name);}
      /// @brief Create a system-defined button that represent ascending button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ascending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::ascending(), location, size, name);}
      /// @brief Create a system-defined button that represent back button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button back(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::back(), location, size, name);}
      /// @brief Create a system-defined button that represent back button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button back(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::back(), location, size, name);}
      /// @brief Create a system-defined button that represent bold button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button bold(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::bold(), location, size, name);}
      /// @brief Create a system-defined button that represent bold button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button bold(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::bold(), location, size, name);}
      /// @brief Create a system-defined button that represent bottom button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button bottom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::bottom(), location, size, name);}
      /// @brief Create a system-defined button that represent bottom button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button bottom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::bottom(), location, size, name);}
      /// @brief Create a system-defined button that represent cancel button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cancel(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::cancel(), location, size, name);}
      /// @brief Create a system-defined button that represent cancel button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cancel(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::cancel(), location, size, name);}
      /// @brief Create a system-defined button that represent CD-Rom button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cdrom(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::cdrom(), location, size, name);}
      /// @brief Create a system-defined button that represent CD-Rom button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cdrom(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::cdrom(), location, size, name);}
      /// @brief Create a system-defined button that represent centered button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button centered(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::centered(), location, size, name);}
      /// @brief Create a system-defined button that represent centered button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button centered(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::centered(), location, size, name);}
      /// @brief Create a system-defined button that represent clear button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button clear(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::clear(), location, size, name);}
      /// @brief Create a system-defined button that represent clear button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button clear(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::clear(), location, size, name);}
      /// @brief Create a system-defined button that represent close button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button close(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::close(), location, size, name);}
      /// @brief Create a system-defined button that represent close button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button close(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::close(), location, size, name);}
      /// @brief Create a system-defined button that represent color button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button color(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::color(), location, size, name);}
      /// @brief Create a system-defined button that represent color button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button color(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::color(), location, size, name);}
      /// @brief Create a system-defined button that represent contents button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button contents(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::contents(), location, size, name);}
      /// @brief Create a system-defined button that represent contents button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button contents(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::contents(), location, size, name);}
      /// @brief Create a system-defined button that represent convert button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button convert(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::convert(), location, size, name);}
      /// @brief Create a system-defined button that represent convert button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button convert(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::convert(), location, size, name);}
      /// @brief Create a system-defined button that represent copy button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button copy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::copy(), location, size, name);}
      /// @brief Create a system-defined button that represent copy button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button copy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::copy(), location, size, name);}
      /// @brief Create a system-defined button that represent customize button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button customize(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::customize(), location, size, name);}
      /// @brief Create a system-defined button that represent customize button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button customize(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::customize(), location, size, name);}
      /// @brief Create a system-defined button that represent cut button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cut(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::cut(), location, size, name);}
      /// @brief Create a system-defined button that represent cut button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cut(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::cut(), location, size, name);}
      /// @brief Create a system-defined button that represent delete button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button del(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::del(), location, size, name);}
      /// @brief Create a system-defined button that represent delete button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button del(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::del(), location, size, name);}
      /// @brief Create a system-defined button that represent descending button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button descending(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::descending(), location, size, name);}
      /// @brief Create a system-defined button that represent descending button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button descending(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::descending(), location, size, name);}
      /// @brief Create a system-defined button that represent down button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button down(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::down(), location, size, name);}
      /// @brief Create a system-defined button that represent down button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button down(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::down(), location, size, name);}
      /// @brief Create a system-defined button that represent edit button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button edit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::edit(), location, size, name);}
      /// @brief Create a system-defined button that represent edit button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button edit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::edit(), location, size, name);}
      /// @brief Create a system-defined button that represent execute button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button execute(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::execute(), location, size, name);}
      /// @brief Create a system-defined button that represent execute button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button execute(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::execute(), location, size, name);}
      /// @brief Create a system-defined button that represent file button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button file(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::file(), location, size, name);}
      /// @brief Create a system-defined button that represent file button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button file(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::file(), location, size, name);}
      /// @brief Create a system-defined button that represent find button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button find(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::find(), location, size, name);}
      /// @brief Create a system-defined button that represent find button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button find(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::find(), location, size, name);}
      /// @brief Create a system-defined button that represent first button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button first(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::first(), location, size, name);}
      /// @brief Create a system-defined button that represent first button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button first(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::first(), location, size, name);}
      /// @brief Create a system-defined button that represent floppy button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button floppy(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::floppy(), location, size, name);}
      /// @brief Create a system-defined button that represent floppy button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button floppy(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::floppy(), location, size, name);}
      /// @brief Create a system-defined button that represent font button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button font(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::font(), location, size, name);}
      /// @brief Create a system-defined button that represent font button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button font(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::font(), location, size, name);}
      /// @brief Create a system-defined button that represent forward button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button forward(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::forward(), location, size, name);}
      /// @brief Create a system-defined button that represent forward button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button forward(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::forward(), location, size, name);}
      /// @brief Create a system-defined button that represent hard disk button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button harddisk(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::harddisk(), location, size, name);}
      /// @brief Create a system-defined button that represent hard disk button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button harddisk(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::harddisk(), location, size, name);}
      /// @brief Create a system-defined button that represent help button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button help(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::help(), location, size, name);}
      /// @brief Create a system-defined button that represent help button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button help(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::help(), location, size, name);}
      /// @brief Create a system-defined button that represent home button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button home(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::home(), location, size, name);}
      /// @brief Create a system-defined button that represent home button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button home(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::home(), location, size, name);}
      /// @brief Create a system-defined button that represent ignore button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ignore(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::ignore(), location, size, name);}
      /// @brief Create a system-defined button that represent ignore button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ignore(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::ignore(), location, size, name);}
      /// @brief Create a system-defined button that represent indent button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button indent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::indent(), location, size, name);}
      /// @brief Create a system-defined button that represent indent button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button indent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::indent(), location, size, name);}
      /// @brief Create a system-defined button that represent index button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button index(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::index(), location, size, name);}
      /// @brief Create a system-defined button that represent index button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button index(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::index(), location, size, name);}
      /// @brief Create a system-defined button that represent info button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button info(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::info(), location, size, name);}
      /// @brief Create a system-defined button that represent info button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button info(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::info(), location, size, name);}
      /// @brief Create a system-defined button that represent italic button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button italic(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::italic(), location, size, name);}
      /// @brief Create a system-defined button that represent italic button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button italic(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::italic(), location, size, name);}
      /// @brief Create a system-defined button that represent justified button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button justified(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::justified(), location, size, name);}
      /// @brief Create a system-defined button that represent justified button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button justified(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::justified(), location, size, name);}
      /// @brief Create a system-defined button that represent jump_to button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button jump_to(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::jump_to(), location, size, name);}
      /// @brief Create a system-defined button that represent jump to button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button jump_to(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::jump_to(), location, size, name);}
      /// @brief Create a system-defined button that represent last button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button last(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::last(), location, size, name);}
      /// @brief Create a system-defined button that represent last button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button last(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::last(), location, size, name);}
      /// @brief Create a system-defined button that represent network button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button network(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::network(), location, size, name);}
      /// @brief Create a system-defined button that represent network button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button network(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::network(), location, size, name);}
      /// @brief Create a system-defined button that represent new button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button new_(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::new_(), location, size, name);}
      /// @brief Create a system-defined button that represent new button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button new_(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::new_(), location, size, name);}
      /// @brief Create a system-defined button that represent no button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button no(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::no(), location, size, name);}
      /// @brief Create a system-defined button that represent no button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button no(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::no(), location, size, name);}
      /// @brief Create a system-defined button that represent ok button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ok(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::ok(), location, size, name);}
      /// @brief Create a system-defined button that represent ok button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ok(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::ok(), location, size, name);}
      /// @brief Create a system-defined button that represent open button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button open(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::open(), location, size, name);}
      /// @brief Create a system-defined button that represent open button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button open(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::open(), location, size, name);}
      /// @brief Create a system-defined button that represent options button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button options(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::options(), location, size, name);}
      /// @brief Create a system-defined button that represent options button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button options(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::options(), location, size, name);}
      /// @brief Create a system-defined button that represent paste button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button paste(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::paste(), location, size, name);}
      /// @brief Create a system-defined button that represent paste button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button paste(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::paste(), location, size, name);}
      /// @brief Create a system-defined button that represent preferences button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button preferences(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::preferences(), location, size, name);}
      /// @brief Create a system-defined button that represent preferences button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button preferences(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::preferences(), location, size, name);}
      /// @brief Create a system-defined button that represent print button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button print(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::print(), location, size, name);}
      /// @brief Create a system-defined button that represent print button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button print(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::print(), location, size, name);}
      /// @brief Create a system-defined button that represent print preview button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button print_preview(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::print_preview(), location, size, name);}
      /// @brief Create a system-defined button that represent print preview button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button print_preview(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::print_preview(), location, size, name);}
      /// @brief Create a system-defined button that represent properties button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button properties(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::properties(), location, size, name);}
      /// @brief Create a system-defined button that represent properties button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button properties(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::properties(), location, size, name);}
      /// @brief Create a system-defined button that represent quit button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button quit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::quit(), location, size, name);}
      /// @brief Create a system-defined button that represent quit button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button quit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::quit(), location, size, name);}
      /// @brief Create a system-defined button that represent redo button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button redo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::redo(), location, size, name);}
      /// @brief Create a system-defined button that represent redo button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button redo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::redo(), location, size, name);}
      /// @brief Create a system-defined button that represent refresh button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button refresh(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::refresh(), location, size, name);}
      /// @brief Create a system-defined button that represent refresh button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button refresh(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::refresh(), location, size, name);}
      /// @brief Create a system-defined button that represent remove button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button remove(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::remove(), location, size, name);}
      /// @brief Create a system-defined button that represent remove button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button remove(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::remove(), location, size, name);}
      /// @brief Create a system-defined button that represent replace button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button replace(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::replace(), location, size, name);}
      /// @brief Create a system-defined button that represent replace button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button replace(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::replace(), location, size, name);}
      /// @brief Create a system-defined button that represent retry button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button retry(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::retry(), location, size, name);}
      /// @brief Create a system-defined button that represent retry button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button retry(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::retry(), location, size, name);}
      /// @brief Create a system-defined button that represent revert to saved button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button revert_to_saved(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::revert_to_saved(), location, size, name);}
      /// @brief Create a system-defined button that represent revert to saved button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button revert_to_saved(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::revert_to_saved(), location, size, name);}
      /// @brief Create a system-defined button that represent save button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button save(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::save(), location, size, name);}
      /// @brief Create a system-defined button that represent save button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button save(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::save(), location, size, name);}
      /// @brief Create a system-defined button that represent save as button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button save_as(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::save_as(), location, size, name);}
      /// @brief Create a system-defined button that represent save as button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button save_as(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::save_as(), location, size, name);}
      /// @brief Create a system-defined button that represent search button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button search(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::search(), location, size, name);}
      /// @brief Create a system-defined button that represent search button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button search(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::search(), location, size, name);}
      /// @brief Create a system-defined button that represent select all button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button select_all(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::select_all(), location, size, name);}
      /// @brief Create a system-defined button that represent select all button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button select_all(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::select_all(), location, size, name);}
      /// @brief Create a system-defined button that represent spell check button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button spell_check(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::spell_check(), location, size, name);}
      /// @brief Create a system-defined button that represent spell check button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button spell_check(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::spell_check(), location, size, name);}
      /// @brief Create a system-defined button that represent stop button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button stop(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::stop(), location, size, name);}
      /// @brief Create a system-defined button that represent stop button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button stop(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::stop(), location, size, name);}
      /// @brief Create a system-defined button that represent strikeout button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button strikeout(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::strikeout(), location, size, name);}
      /// @brief Create a system-defined button that represent strikeout button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button strikeout(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::strikeout(), location, size, name);}
      /// @brief Create a system-defined button that represent tools button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button tools(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::tools(), location, size, name);}
      /// @brief Create a system-defined button that represent tools button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button tools(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::tools(), location, size, name);}
      /// @brief Create a system-defined button that represent top button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button top(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::top(), location, size, name);}
      /// @brief Create a system-defined button that represent top button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button top(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::top(), location, size, name);}
      /// @brief Create a system-defined button that represent undelete button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button undelete(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::undelete(), location, size, name);}
      /// @brief Create a system-defined button that represent undelete button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button undelete(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::undelete(), location, size, name);}
      /// @brief Create a system-defined button that represent underline button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button underline(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::underline(), location, size, name);}
      /// @brief Create a system-defined button that represent underline button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button underline(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::underline(), location, size, name);}
      /// @brief Create a system-defined button that represent undo button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button undo(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::undo(), location, size, name);}
      /// @brief Create a system-defined button that represent undo button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button undo(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::undo(), location, size, name);}
      /// @brief Create a system-defined button that represents an unindented button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button unindent(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::unindent(), location, size, name);}
      /// @brief Create a system-defined button that represents an unindented button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button unindent(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::unindent(), location, size, name);}
      /// @brief Create a system-defined button that represent up button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button up(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::up(), location, size, name);}
      /// @brief Create a system-defined button that represent up button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button up(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::up(), location, size, name);}
      /// @brief Create a system-defined button that represent view button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button view(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::view(), location, size, name);}
      /// @brief Create a system-defined button that represent view button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button view(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::view(), location, size, name);}
      /// @brief Create a system-defined button that represent yes button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button yes(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::yes(), location, size, name);}
      /// @brief Create a system-defined button that represent yes button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button yes(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::yes(), location, size, name);}
      /// @brief Create a system-defined button that represent zoom in button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_in(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::zoom_in(), location, size, name);}
      /// @brief Create a system-defined button that represent zoom in button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_in(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::zoom_in(), location, size, name);}
      /// @brief Create a system-defined button that represent zoom out button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_out(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::zoom_out(), location, size, name);}
      /// @brief Create a system-defined button that represent zoom out button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_out(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::zoom_out(), location, size, name);}
      /// @brief Create a system-defined button that represent zoom to fit button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_to_fit(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(system_texts::zoom_to_fit(), location, size, name);}
      /// @brief Create a system-defined button that represent zoom to fit button.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_to_fit(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {return xtd::forms::button::create(parent, system_texts::zoom_to_fit(), location, size, name);}
      /// @}
    };
  }
}
