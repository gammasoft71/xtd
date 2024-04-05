/// @file
/// @brief Contains xtd::forms::splitter_panel container.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class split_container;
    /// @endcond
    
    /// @brief Creates a panel that is associated with a split_container.
    /// @par Header
    /// @code #include <xtd/forms/splitter_panel> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @remarks The constructor for this object is not public, so you cannot explicitly create a splitter_panel object.
    /// @remarks The splitter_panel is a member of its associated split_container rather than being a member of the underlying form. At design time, the splitter_panel is accessible through the panel1 or panel2 properties of split_container.
    class forms_export_ splitter_panel : public panel {
      friend class split_container;
    protected:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of splitter_panel.
      splitter_panel() = default;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::splitter_panel.
      /// @return New xtd::forms::splitter_panel created.
      static splitter_panel create();
      /// @brief A factory to create an xtd::forms::splitter_panel with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter_panel.
      /// @return New xtd::forms::splitter_panel created.
      static splitter_panel create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::splitter_panel with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::splitter_panel.
      /// @return New xtd::forms::splitter_panel created.
      static splitter_panel create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::splitter_panel with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::splitter_panel.
      /// @param name The name of the xtd::forms::splitter_panel.
      /// @return New xtd::forms::splitter_panel created.
      static splitter_panel create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::splitter_panel with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::splitter_panel.
      /// @return New xtd::forms::splitter_panel created.
      static splitter_panel create(const control& parent);
      /// @brief A factory to create an xtd::forms::splitter_panel with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::splitter_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter_panel.
      /// @return New xtd::forms::splitter_panel created.
      static splitter_panel create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::splitter_panel with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::splitter_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::splitter_panel.
      /// @return New xtd::forms::splitter_panel created.
      static splitter_panel create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::splitter_panel with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::splitter_panel.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::splitter_panel.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::splitter_panel.
      /// @param name The name of the xtd::forms::splitter_panel.
      /// @return New xtd::forms::splitter_panel created.
      static splitter_panel create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}

    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      std::unique_ptr<xtd::object> clone() const override;
      /// @}
    };
  }
}
