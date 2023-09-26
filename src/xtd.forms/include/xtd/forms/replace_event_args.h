/// @file
/// @brief Contains xtd::forms::replace_event_args event args.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "message"
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::replace_dialog::replace and xtd::forms::replace_dialog::replace_all events.
    /// @par Header
    /// @code #include <xtd/forms/replace_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class replace_event_args : public event_args {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::replace_event_args class.
      replace_event_args() = default;
      /// @brief Initializes a new instance of the xtd::forms::replace_event_args class.
      /// @param find_string The string to find.
      /// @param replace_string A string that specifies the replaced text.
      /// @param match_case true if match case option selected; otherwise false.
      /// @param whole_word One of xtd::forms::search_direction values.
      replace_event_args(const xtd::ustring& find_string, const xtd::ustring& replace_string, bool match_case, bool whole_word) : find_string_(find_string), replace_string_(replace_string), match_case_(match_case), whole_word_(whole_word) {}
      /// @}
      
      /// @cond
      replace_event_args(const replace_event_args&) = default;
      replace_event_args& operator =(const replace_event_args&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the string to find.
      /// @return The string to find.
      const xtd::ustring& find_string() const noexcept {return find_string_;}
      
      /// @brief Gets the replaced string.
      /// @return The replaced string.
      const xtd::ustring& replace_string() const noexcept {return replace_string_;}
      
      /// @brief Gets the match case value.
      /// @return true if match case option selected; otherwise false. The default is false.
      bool match_case() const noexcept {return match_case_;}
      
      /// @brief Gets the whole word value.
      /// @return true if whole word option selected; otherwise false. The default is false.
      bool whole_word() const noexcept {return whole_word_;}
      
      /// @}
      
    private:
      xtd::ustring find_string_;
      xtd::ustring replace_string_;
      bool match_case_ = false;
      bool whole_word_ = false;
    };
  }
}
