/// @file
/// @brief Contains xtd::forms::native::tab_control API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.#pragma once
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <string>
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains tab control native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ tab_control final static_ {
      public:
        /// @brief Maintains performance while items are added to the tab_control one at a tab_page by preventing the control from drawing until the end_update() method is called.
        /// @param control Tab control window handle.
        /// @warning Internal use only
        static void begin_update(intptr_t control);
        /// @brief Deletes specified tab page index.
        /// @param control Tab control window handle.
        /// @param index The item index to delete.
        /// @warning Internal use only
        static void delete_item(intptr_t control, size_t index);
        /// @brief Resumes painting the tab_control control after painting is suspended by the begin_update method.
        /// @param control Tab control window handle.
        /// @warning Internal use only
        static void end_update(intptr_t control);
        /// @brief Sets image list.
        /// @param control Tab control window handle.
        /// @param image_list The image list handle.
        /// @warning Internal use only
        static void image_list(intptr_t control, intptr_t image_list);
        /// @brief Inserts at specified tab page index a specified tab page handle.
        /// @param control Tab control window handle.
        /// @param index The tab page index to insert.
        /// @param page The tab page handle.
        /// @warning Internal use only
        static void insert_item(intptr_t control, size_t index, intptr_t page);
        /// @brief Gets selected tab page index.
        /// @param control Tab control window handle.
        /// @return The selected tab page index.
        /// @warning Internal use only
        static size_t selected_index(intptr_t control);
        /// @brief Sets selected tab page with specified index
        /// @param control Tab control window handle.
        /// @param index The selected tab page index.
        /// @warning Internal use only
        static void selected_index(intptr_t control, size_t index);
        /// @brief Updates a specified tab page index with specified tab page handle.
        /// @param control Tab control window handle.
        /// @param index The tab page index to update.
        /// @param page The tab page handle.
        /// @warning Internal use only
        static void update_item(intptr_t control, size_t index, intptr_t page);
      };
    }
  }
}
