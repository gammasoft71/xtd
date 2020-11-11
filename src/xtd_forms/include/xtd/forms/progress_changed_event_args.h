#pragma once
#include <any>
#include <cstdint>
#include <xtd/event_args.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the do_work event handler.
    class progress_changed_event_args : public event_args {
    public:
      /// @cond
      progress_changed_event_args(const progress_changed_event_args&) = default;
      progress_changed_event_args& operator=(const progress_changed_event_args&) = default;
      /// @endcond
      
      /// @brief Initializes a new instance of the DoWorkEventArgs class.
      /// @param argument Specifies an argument for an asynchronous operation.
      progress_changed_event_args(int32_t progress_percentage, const std::any& user_state) : progress_percentage_(progress_percentage), user_state_(user_state) {}
      
      int32_t progress_percentage() const {return progress_percentage_;}

      /// @brief Gets a value that represents the argument of an asynchronous operation.
      /// @return An object representing the argument of an asynchronous operation.
      std::any user_state() const {return user_state_;}
      
    private:
      int32_t progress_percentage_ = 0;
      std::any user_state_;
    };
  }
}
