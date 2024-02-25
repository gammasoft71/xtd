/// @file
/// @brief Contains xtd::forms::h_scroll_bar control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "scroll_bar.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows horizontal scroll bar.
    /// @par Header
    /// @code #include <xtd/forms/h_scroll_bar> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html control_h_scroll_bar_w.png   |  @image html control_h_scroll_bar_m.png   |  @image html control_h_scroll_bar_g.png   |
    /// | Dark  |  @image html control_h_scroll_bar_wd.png  |  @image html control_h_scroll_bar_md.png  |  @image html control_h_scroll_bar_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of h_scroll_bar control.
    /// @include h_scroll_bar.cpp
    class forms_export_ h_scroll_bar : public scroll_bar {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of h_scroll_bar class.
      h_scroll_bar();
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create();
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, and maximum.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, int32 maximum);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, minimum, maximum, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, int32 maximum, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, maximum, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, maximum, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, minimum, and maximum.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, int32 minimum, int32 maximum);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, minimum, maximum, and location.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, int32 minimum, int32 maximum, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, minimum, maximum, location, and size.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified value, minimum, maximum, location, size, and name.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, and value.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, and location.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, and maximum.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, int32 maximum);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, maximum, and location.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, int32 maximum, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, maximum, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, maximum, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, minimum, and maximum.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, int32 minimum, int32 maximum);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, minimum, maximum, and location.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, minimum, maximum, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::h_scroll_bar with specified parent, value, minimum, maximum, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::h_scroll_bar.
      /// @param value A numeric value that is within the minimum and maximum range. The default value is 0.
      /// @param minimum The lower limit of values of the scrollable range.
      /// @param maximum The upper limit of values of the scrollable range.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::h_scroll_bar.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::h_scroll_bar.
      /// @param name The name of the xtd::forms::h_scroll_bar.
      /// @return New xtd::forms::h_scroll_bar created.
      static h_scroll_bar create(const control& parent, int32 value, int32 minimum, int32 maximum, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      xtd::forms::create_params create_params() const noexcept override;
      xtd::drawing::size default_size() const noexcept override;
      /// @}
    };
  }
}
