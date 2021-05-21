/// @file
/// @brief Contains xtd::forms::native::checked_list_box API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <vector>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains checked list box native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ checked_list_box final static_ {
      public:
        /// @brief Maintains performance while items are added to the checked_list_box one at a time by preventing the control from drawing until the end_update() method is called.
        /// @param control Checked list box window handle.
        /// @warning Internal use only
        static void begin_update(intptr_t control);
        /// @brief Sets check state to specified item index.
        /// @param control Checked list box window handle.
        /// @param index The item index to set the check state for.
        /// @param check_state The check state value : BST_UNCHECKED or BST_CHECKED or BST_INDETERMINATE.
        /// @warning Internal use only
        static void check_state(intptr_t control, size_t index, int32_t check_state);
        /// @brief Gets check state from specified item index.
        /// @param control Checked list box window handle.
        /// @param index The item index to set the check state for.
        /// @return The check state value : BST_UNCHECKED or BST_CHECKED or BST_INDETERMINATE.
        /// @warning Internal use only
        static int32_t check_state(intptr_t control, size_t index);
        /// @brief Deletes specified item index.
        /// @param control Checked list box window handle.
        /// @param index The item index to delete.
        /// @warning Internal use only
        static void delete_item(intptr_t control, size_t index);
        /// @brief Resumes painting the checked_list_box control after painting is suspended by the begin_update method.
        /// @param control Checked list box window handle.
        /// @warning Internal use only
        static void end_update(intptr_t control);
        /// @brief Inserts at specified item index a specified value and check state.
        /// @param control Checked list box window handle.
        /// @param index The item index to insert.
        /// @param value The text value.
        /// @param check_state The check state value : BST_UNCHECKED or BST_CHECKED or BST_INDETERMINATE.
        /// @warning Internal use only
        static void insert_item(intptr_t control, size_t index, const std::string& value, int32_t check_state);
        /// @brief Gets selected item index.
        /// @param control Checked list box window handle.
        /// @return The selected item index.
        /// @warning Internal use only
        static size_t selected_index(intptr_t control);
        /// @brief Sets selected item with specified index
        /// @param control Checked list box window handle.
        /// @param index The selected item index.
        /// @warning Internal use only
        static void selected_index(intptr_t control, size_t index);
        /// @brief Gets a size_t array of selected indices.
        /// @param control Checked list box window handle.
        /// @return A size_t array of selected indices.
        /// @warning Internal use only
        static std::vector<size_t> selected_indices(intptr_t control);
        /// @brief Updates a specified item index with specified value and check state.
        /// @param control Checked list box window handle.
        /// @param index The item index to update.
        /// @param value The text value.
        /// @param check_state The check state value : BST_UNCHECKED or BST_CHECKED or BST_INDETERMINATE.
        /// @warning Internal use only
        static void update_item(intptr_t control, size_t index, const std::string& value, int32_t check_state);
      };
    }
  }
}
