/// @file
/// @brief Contains xtd::forms::layout::sorter_none class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/object.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::layout namespace contains classes for implementing layout behaviors in your form or control.
    namespace layout {
      /// @brief Represents a sorter none of objects.
      /// @par Namespace
      /// xtd::forms::layout
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      class sorter_none : public object {
      public:
        template<typename type_t>
        void operator()(type_t first, type_t last) {}
      };
    }
  }
}
