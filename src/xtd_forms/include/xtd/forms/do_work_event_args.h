#pragma once
#include <any>
#include <cstdint>
#include <xtd/event_args.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the do_work event handler.
    class do_work_event_args : public event_args {
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
      std::any argument() const {return this->argument_;}
      
      bool cancel() const {return cancel_;}
      void cancel(bool value) {cancel_ = value;}

      std::any result() const {return this->result_;}
      void result(std::any value) {this->result_ = value;}

    private:
      std::any argument_;
      bool cancel_ = false;
      std::any result_;
    };
  }
}
