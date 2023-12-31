/// @file
/// @brief Contains xtd::forms::find_event_args event args.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include "message.h"
#include "search_direction.h"
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::find_dialog::find_next and xtd::forms::replace_dialog::find_next events.
    /// @par Header
    /// @code #include <xtd/forms/find_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class forms_export_ find_event_args : public event_args {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::find_event_args class.
      find_event_args();
      /// @brief Initializes a new instance of the xtd::forms::find_event_args class.
      /// @param find_string The string to find.
      /// @param match_case true if match case option selected; otherwise false.
      /// @param search_direction true if match case option selected; otherwise false.
      /// @param whole_word One of xtd::forms::search_direction values.
      find_event_args(const xtd::ustring& find_string, bool match_case, xtd::forms::search_direction search_direction, bool whole_word);
      /// @}
      
      /// @cond
      find_event_args(const find_event_args& other);
      find_event_args& operator =(const find_event_args& other);
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the string to find.
      /// @return The string to find.
      const xtd::ustring& find_string() const noexcept;
      
      /// @brief Gets the match case value.
      /// @return true if match case option selected; otherwise false. The default is false.
      bool match_case() const noexcept;
      
      /// @brief Gets the search direction value.
      /// @return One of xtd::forms::search_direction values; The default is xtd::forms::search_direction::down.
      xtd::forms::search_direction search_direction() const noexcept;
      
      /// @brief Gets the whole word value.
      /// @return true if whole word option selected; otherwise false. The default is false.
      bool whole_word() const noexcept;
      
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
