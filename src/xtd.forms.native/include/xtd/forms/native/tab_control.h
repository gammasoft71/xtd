/// @file
/// @brief Contains xtd::forms::native::tab_control API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.#pragma once
#pragma once
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
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ tab_control final static_ {
      public:
        static void delete_item(intptr_t control, size_t index);
        static void delete_item(intptr_t control, intptr_t page);
        static void image_list(intptr_t control, intptr_t image_list);
        static void insert_item(intptr_t control, size_t index, intptr_t page);
        static void page_image_index(intptr_t control, size_t index, size_t image_index);
        static void page_text(intptr_t control, size_t index, const std::string& text);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
        static void update_item(intptr_t control, size_t index, intptr_t page);
      };
    }
  }
}
