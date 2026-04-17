/// @file
/// @brief Contains xtd::forms::items_added_event_args event args.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/array>
#include <xtd/event_args>
#include <xtd//usize>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::layout namespace contains classes for implementing layout behaviors in your form or control.
    namespace layout {
      template<typename item_t>
      class items_added_event_args : public xtd::event_args {
      public:
        /// @name Public Consturctors
        
        /// @{
        items_added_event_args(xtd::usize index, const xtd::array<item_t>& items) : index_ {index}, items_ {items} {}
        /// @}
        
        /// @name Public Properties
        
        /// @{
        xtd::usize index() const noexcept {return index_;}
        const xtd::array<item_t>& items() const noexcept {return items_;}
        /// @}
        
      private:
        xtd::usize index_;
        xtd::array<item_t> items_;
      };
    }
  }
}
