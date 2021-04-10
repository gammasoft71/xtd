/// @file
/// @brief Contains xtd::forms::native::choice API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
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
      /// @brief Contains choice native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ choice final static_ {
      public:
        static void begin_update(intptr_t control);
        static void delete_item(intptr_t control, size_t index);
        static void end_update(intptr_t control);
        static void insert_item(intptr_t control, size_t index, const std::string& value);
        static size_t selected_index(intptr_t control);
        static void selected_index(intptr_t control, size_t index);
        static void update_item(intptr_t control, size_t pos, const std::string& value);
      };
    }
  }
}
