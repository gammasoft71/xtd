/// @file
/// @brief Contains xtd::forms::do_work_event event args.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <cstdint>
#include "cancel_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the do_work event handler.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class do_work_event_args : public cancel_event_args {
    public:
      /// @cond
      do_work_event_args(const do_work_event_args& do_work_event_args) = default;
      do_work_event_args& operator=(const do_work_event_args& do_work_event_args) = default;
      /// @endcond
      
      /// @brief Initializes a new instance of the DoWorkEventArgs class.
      /// @param argument Specifies an argument for an asynchronous operation.
      do_work_event_args(const std::any& argument) : argument_(argument) {}
      
      /// @brief Gets a value that represents the argument of an asynchronous operation.
      /// @return An object representing the argument of an asynchronous operation.
      std::any argument() const {return argument_;}
      
      /// @brief Gets a value that represents the result of an asynchronous operation.
      /// @return A std::any representing the result of an asynchronous operation.
      std::any result() const {return result_;}
      /// @brief Sets a value that represents the result of an asynchronous operation.
      /// @param value A std::any representing the result of an asynchronous operation.
      void result(std::any value) {result_ = value;}

    private:
      std::any argument_;
      std::any result_;
    };
  }
}
