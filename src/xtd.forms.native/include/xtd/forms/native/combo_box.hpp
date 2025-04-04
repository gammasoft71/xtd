/// @file
/// @brief Contains xtd::forms::native::combo_box API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.hpp"
#include <vector>
#include <xtd/static>
#include <xtd/string>
#include <xtd/forms_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class combo_box;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains combo box native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ combo_box final static_ {
        friend xtd::forms::combo_box;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Maintains performance while items are added to the combo_box one at a time by preventing the control from drawing until the end_update() method is called.
        /// @param control Combo box window handle.
        /// @warning Internal use only
        static void begin_update(intptr control);
        /// @brief Deletes specified item index.
        /// @param control Combo box window handle.
        /// @param index The item index to delete.
        /// @warning Internal use only
        static void delete_item(intptr control, size_t index);
        /// @brief Sets a value indicating whether the combo box is displaying its drop-down portion.
        /// @param control Combo box window handle.
        /// @param value `true` if the drop-down portion is displayed; otherwise, `false`.
        /// @warning Internal use only
        static void dropped_down(intptr control, bool value);
        /// @brief Resumes painting the combo_box control after painting is suspended by the begin_update method.
        /// @param control Combo box window handle.
        /// @warning Internal use only
        static void end_update(intptr control);
        /// @brief Inserts at specified item index a specified value.
        /// @param control Combo box window handle.
        /// @param index The item index to insert.
        /// @param value The text value.
        /// @warning Internal use only
        static void insert_item(intptr control, size_t index, const xtd::string& value);
        /// @brief Gets selected item index.
        /// @param control Combo box window handle.
        /// @return The selected item index.
        /// @warning Internal use only
        static size_t selected_index(intptr control);
        /// @brief Sets selected item with specified index
        /// @param control Combo box window handle.
        /// @param index The selected item index.
        /// @warning Internal use only
        static void selected_index(intptr control, size_t index);
        /// @brief Updates a specified item index with specified value.
        /// @param control Combo box window handle.
        /// @param index The item index to update.
        /// @param value The text value.
        /// @warning Internal use only
        static void update_item(intptr control, size_t index, const xtd::string& value);
        /// @}
      };
    }
  }
}
