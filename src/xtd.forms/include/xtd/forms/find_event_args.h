/// @file
/// @brief Contains xtd::forms::find_event_args event args.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <xtd/event_args.h>
#include "message.h"
#include "search_direction.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::fnd_dialog::find_next event.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class find_event_args : public event_args {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::find_event_args class.
      find_event_args() = default;
      /// @brief Initializes a new instance of the xtd::forms::find_event_args class.
      /// @param find_string The string to find.
      /// @param match_case true if match case option selected; otherwise false.
      /// @param search_direction true if match case option selected; otherwise false.
      /// @param whole_word One of xtd::forms::search_direction values.
      find_event_args(const xtd::ustring& find_string, bool match_case, xtd::forms::search_direction search_direction, bool whole_word) : find_string_(find_string), match_case_(match_case), search_direction_(search_direction), whole_word_(whole_word) {}
      /// @}
      
      /// @cond
      find_event_args(const find_event_args&) = default;
      find_event_args& operator =(const find_event_args&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the string to find.
      /// @return The string to find.
      const xtd::ustring& find_string() const {return find_string_;}
      
      /// @brief Gets the match case value.
      /// @return true if match case option selected; otherwise false. The default is false.
      bool match_case() const {return match_case_;}
      
      /// @brief Gets the search direction value.
      /// @return One of xtd::forms::search_direction values; The default is xtd::forms::search_direction::down.
      xtd::forms::search_direction search_direction() const {return search_direction_;}
      
      /// @brief Gets the whole word value.
      /// @return true if whole word option selected; otherwise false. The default is false.
      bool whole_word() const {return whole_word_;}
      
      /// @}
      
    private:
      xtd::ustring find_string_;
      bool match_case_ = false;
      xtd::forms::search_direction search_direction_ = xtd::forms::search_direction::down;
      bool whole_word_ = false;
    };
  }
}
