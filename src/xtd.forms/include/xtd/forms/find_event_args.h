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
      find_event_args(const xtd::ustring& find_string, bool match_case, xtd::forms::search_direction search_direction, bool whole_word) {
        data_->find_string = find_string;
        data_->match_case = match_case;
        data_->search_direction = search_direction;
        data_->whole_word = whole_word;
      }
      /// @}
      
      /// @cond
      find_event_args(const find_event_args&) = default;
      find_event_args& operator =(const find_event_args&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the string to find.
      /// @return The string to find.
      const xtd::ustring& find_string() const noexcept {return data_->find_string;}
      
      /// @brief Gets the match case value.
      /// @return true if match case option selected; otherwise false. The default is false.
      bool match_case() const noexcept {return data_->match_case;}
      
      /// @brief Gets the search direction value.
      /// @return One of xtd::forms::search_direction values; The default is xtd::forms::search_direction::down.
      xtd::forms::search_direction search_direction() const noexcept {return data_->search_direction;}
      
      /// @brief Gets the whole word value.
      /// @return true if whole word option selected; otherwise false. The default is false.
      bool whole_word() const noexcept {return data_->whole_word;}
      
      /// @}
      
    private:
      struct data {
        xtd::ustring find_string;
        bool match_case = false;
        xtd::forms::search_direction search_direction = xtd::forms::search_direction::down;
        bool whole_word = false;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
