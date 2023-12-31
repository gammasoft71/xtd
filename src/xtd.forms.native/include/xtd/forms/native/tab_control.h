/// @file
/// @brief Contains xtd::forms::native::tab_control API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.#pragma once
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <string>
#include "create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class tab_control;
    class tab_page;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains tab control native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ tab_control final static_ {
        friend xtd::forms::tab_control;
        friend xtd::forms::tab_page;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Deletes specified tab page index.
        /// @param control Tab control window handle.
        /// @param page The page handle to delete.
        /// @warning Internal use only
        static void delete_page(intptr control, intptr page);
        /// @brief Sets image list.
        /// @param control Tab control window handle.
        /// @param image_list The image list handle.
        /// @warning Internal use only
        static void image_list(intptr control, intptr image_list);
        /// @brief Inserts at specified tab page index a specified tab page handle.
        /// @param control Tab control window handle.
        /// @param index The tab page index to insert.
        /// @param page The tab page handle.
        /// @warning Internal use only
        static void insert_page(intptr control, size_t index, intptr page);
        /// @brief Gets selected tab page index.
        /// @param control Tab control window handle.
        /// @return The selected tab page index.
        /// @warning Internal use only
        static size_t selected_index(intptr control);
        /// @brief Sets selected tab page with specified index
        /// @param control Tab control window handle.
        /// @param index The selected tab page index.
        /// @warning Internal use only
        static void selected_index(intptr control, size_t index);
        /// @}
      };
    }
  }
}
